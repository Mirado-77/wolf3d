/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** server
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <time.h>
#include <sys/select.h>
#include "network.h"

#define RESPAWN_DELAY_MS 5000
static long respawn_at[MAX_PLAYERS] = {0};

static long wall_now_ms(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long)ts.tv_sec * 1000L + ts.tv_nsec / 1000000L;
}

static void set_nodelay(int fd)
{
    int flag = 1;

    setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &flag, sizeof(flag));
}

static void broadcast_state(client_info_t *client, const net_game_state_t *s)
{
    for (int i = 0; i < MAX_PLAYERS; ++i)
        if (client[i].fd > 0)
            send(client[i].fd, s, sizeof(*s), MSG_DONTWAIT | MSG_NOSIGNAL);
}

static int init_server(void)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    int yes = 1;
    struct sockaddr_in addr = {0};

    if (fd < 0)
    	return -1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    if (bind(fd, (void *)&addr, sizeof(addr)) < 0)
    	return -1;
    if (listen(fd, MAX_PLAYERS) < 0)
    	return -1;
    printf("[server] listening on port %d\n", PORT);
    return fd;
}

static void add_player(client_info_t *client, net_game_state_t *st,
    int fd, int id, const float sp[][2])
{
    client[id].fd = fd;
    client[id].id = id;
    st->players[id] = (net_player_t) {
        .id = id,
        .x = sp[id][0],
        .y = sp[id][1],
        .dirX = -1.f,
        .planeY = 0.66f,
        .health = 100.f,
        .stamina = 200.f,
        .mana = 500.f,
        .is_alive = 1,
        .kills = 0,
	    .deaths = 0
    };
    st->player_count++;
}

static void handle_new_conn(int srv, client_info_t *client,
    net_game_state_t *st, const float sp[][2])
{
    struct sockaddr_in addr = {0};
    socklen_t len = sizeof(addr);
    int fd = accept(srv, (void *)&addr, &len);
    int id = -1;
    int rej;

    if (fd < 0)
    	return;
    set_nodelay(fd);
    for (int i = 0; i < MAX_PLAYERS && id == -1; ++i)
        if (client[i].fd == 0)
        	id = i;
    if (id == -1) {
        rej = -1;
        send(fd, &rej, sizeof(int), 0);
        close(fd);
    } else {
        add_player(client, st, fd, id, sp);
        send(fd, &id, sizeof(int), 0);
        printf("[server] player %d connected\n", id);
        broadcast_state(client, st);
    }
}

static void merge_player_state(net_player_t *dst, const net_player_t *src)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->dirX = src->dirX;
    dst->dirY = src->dirY;
    dst->planeX = src->planeX;
    dst->planeY = src->planeY;
    dst->stamina = src->stamina;
    dst->mana = src->mana;
}

static void handle_recv(client_info_t *client, net_game_state_t *st, int i)
{
    const long now_ms = wall_now_ms();
    net_packet_t pkt;
    int t;
    ssize_t n = recv(client[i].fd, &pkt, sizeof(pkt), MSG_DONTWAIT);

    if (n <= 0) {
        printf("[server] player %d disconnected\n", i);
        close(client[i].fd);
        client[i].fd = 0;
        st->players[i].is_alive = 0;
        if (st->player_count)
        	st->player_count--;
    }
    if ((size_t)n != sizeof(pkt))
        return;
    if (pkt.type == PKT_STATE) {
        if (st->players[i].is_alive)
            merge_player_state(&st->players[i], &pkt.state);
    } else if (pkt.type == PKT_DAMAGE) {
        t = pkt.damage.target_id;
        if (!st->players[t].is_alive)
            return;
        st->players[t].health -= pkt.damage.dmg;
        if (st->players[t].health <= 0 && st->players[t].is_alive) {
            st->players[t].health = 0.f;
            st->players[t].is_alive = 0;
            st->players[t].deaths++;
            int a = pkt.damage.attacker_id;
            if (a >= 0 && a < MAX_PLAYERS)
                st->players[a].kills++;
            printf("[server] player %d is DEAD – respawn dans 5 s\n", t);
            respawn_at[t] = now_ms + RESPAWN_DELAY_MS;
        }
    }
}

static void try_respawn(net_game_state_t *st,
	const float sp[][2], long now_ms)
{
    for (int i = 0; i < MAX_PLAYERS; ++i) {
        if (!st->players[i].is_alive &&
            respawn_at[i] && now_ms >= respawn_at[i]) {
            st->players[i].x = sp[i][0];
            st->players[i].y = sp[i][1];
            st->players[i].health = 100.f;
            st->players[i].stamina = 200.f;
            st->players[i].mana = 500.f;
            st->players[i].is_alive= 1;
            respawn_at[i] = 0;
            printf("[server] player %d respawned\n", i);
        }
    }
}

int main(void)
{
    const float sp[MAX_PLAYERS][2] = {
        {5, 5}, {35, 35}, {10, 10}, {2, 15}, {2, 2}, {8, 8}, {12, 12}, {6, 6}
  	};
    client_info_t client[MAX_PLAYERS] = {0};
    net_game_state_t st = {0};
    fd_set rfds;
    struct timeval tv;
    int srv = init_server();

    if (srv < 0)
    	return 84;
    while (1) {
        int max = srv;
        FD_ZERO(&rfds);
        FD_SET(srv, &rfds);
        for (int i = 0; i < MAX_PLAYERS; ++i)
            if (client[i].fd > 0) {
            	FD_SET(client[i].fd, &rfds);
            	if(client[i].fd > max)
                	max = client[i].fd;
            }
        tv = (struct timeval){0, TICK_USEC};
        select(max + 1, &rfds, NULL, NULL, &tv);
        if (FD_ISSET(srv, &rfds))
            handle_new_conn(srv, client, &st, sp);
        for (int i = 0; i < MAX_PLAYERS; ++i)
            if (client[i].fd > 0 && FD_ISSET(client[i].fd, &rfds))
                handle_recv(client, &st, i);
        const long now_ms = wall_now_ms();
        try_respawn(&st, sp, now_ms);
        broadcast_state(client, &st);
    }
    return 0;
}
