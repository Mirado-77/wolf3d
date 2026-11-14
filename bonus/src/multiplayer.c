/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** multiplayer
*/

#include "wolf.h"
#include "raycasting.h"
#include "network.h"
#include "input_handler.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

// buff qui stock les pkts reçus ( receive buff )
static char rxbuf[SNAPSHOT_SZ * 4];
// nombre de bytes valides dans rxbuf
static size_t used = 0;

// passe le fd en mode non-bloquant (recv / read return directement quand vide)
static int set_non_blocking(int fd)
{
    int flags = fcntl(fd, F_GETFL, 0);

    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

int close_err(int fd)
{
    if (fd >= 0)
        close(fd);
    return ERROR;
}

// init sockaddr (set ip and port), puis convertit la str de l'ip en binaire. return 0 si success
int init_sockaddr(struct sockaddr_in *addr, const char *ip, uint16_t port)
{
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    return inet_pton(AF_INET, ip, &addr->sin_addr) <= 0;
}

// créer socket TCP, connect au serv (duhhh), reçois player id
static int connect_to_server(wolf_t *wolf, const char *ip)
{
    struct sockaddr_in addr = {0};

    wolf->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (wolf->sock < 0)
        return ERROR;
    if (init_sockaddr(&addr, ip, PORT))
        return close_err(wolf->sock);
    if (connect(wolf->sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        return close_err(wolf->sock);
    if (recv(wolf->sock, &wolf->player_id, sizeof(int),
        MSG_WAITALL) != sizeof(int))
        return close_err(wolf->sock);
    set_non_blocking(wolf->sock);
    return SUCCESS;
}

// obvious
static void copy_from_player(net_player_t *dst, const player_t *src)
{
    dst->id = src->id;
    dst->x = src->x;
    dst->y = src->y;
    dst->dirX = src->dirX;
    dst->dirY = src->dirY;
    dst->planeX = src->planeX;
    dst->planeY = src->planeY;
    dst->health = src->health;
    dst->stamina = src->stamina;
    dst->mana = src->mana;
    dst->is_alive = src->is_alive;
    dst->kills = src->kills;
    dst->deaths = src->deaths;
}

// obvious
static void apply_to_player(player_t *dst, const net_player_t *src)
{
    dst->id = src->id;
    dst->x = src->x;
    dst->y = src->y;
    dst->dirX = src->dirX;
    dst->dirY = src->dirY;
    dst->planeX = src->planeX;
    dst->planeY = src->planeY;
    dst->health = src->health;
    dst->stamina = src->stamina;
    dst->mana = src->mana;
    dst->is_alive = src->is_alive;
    dst->kills = src->kills;
    dst->deaths = src->deaths;
}

// obvious
void multiplayer_init(wolf_t *wolf, const char *ip)
{
    if (connect_to_server(wolf, ip) == ERROR) {
        fprintf(stderr, "Failed connection to server %s:%d\n", ip, PORT);
        wolf->sock = -1;
    }
}

// send le pkt au socket
static void send_player_state(wolf_t *wolf)
{
    net_packet_t p;

    if (wolf->is_dead)
        return;
    p.type = PKT_STATE;
    copy_from_player(&p.state, &wolf->player);
    send(wolf->sock, &p, sizeof(p), MSG_NOSIGNAL);
}

static int pull_socket(int fd)
{
    ssize_t n = recv(fd, rxbuf + used,
        sizeof(rxbuf) - used, MSG_DONTWAIT);

    return (n > 0) ? (used += (size_t)n, 1) : 0;
}

// on ne garde que le snapshot le plus récent
static int pop_snapshot(net_game_state_t *dst)
{
    size_t extra;

    if (used >= SNAPSHOT_SZ) {
        extra = used - SNAPSHOT_SZ;
        memmove(rxbuf, rxbuf + extra, SNAPSHOT_SZ);
        used = SNAPSHOT_SZ;
    }
    if (used == SNAPSHOT_SZ) {
        memcpy(dst, rxbuf, SNAPSHOT_SZ);
        used = 0;
    }
    return 0;
}

/* Lit le socket, garde 1 seul snapshot, fusionne l'état dans wolf->players  */
static void receive_players_state(wolf_t *wolf)
{
    net_game_state_t snap = {0};
    int id;

    pull_socket(wolf->sock);
    if (used < SNAPSHOT_SZ)
        return;
    pop_snapshot(&snap);
    if (snap.player_count < 0 || snap.player_count > MAX_PLAYERS)
        return;
    wolf->player_count = snap.player_count;
    for (int i = 0; i < snap.player_count; ++i) {
        id = snap.players[i].id;
        if (id < 0 || id >= MAX_PLAYERS)
            continue;
        wolf->players[id] = snap.players[i];
        if (id == wolf->player_id) {
            bool resurrected = wolf->is_dead && snap.players[i].is_alive;
            if (resurrected || !wolf->local_player_initialized) {
                apply_to_player(&wolf->player, &snap.players[i]);
                wolf->local_player_initialized = 1;
            }
            wolf->is_dead = !snap.players[i].is_alive;
        }
    }
}

// obvious
static void update_other_players_state(wolf_t *wolf)
{
    for (int i = 0; i < wolf->player_count; ++i) {
        if (i == wolf->player_id)
            continue;
        apply_to_player((player_t *)&wolf->players[i], &wolf->players[i]);
    }
}

// obvious
void draw_other_players(wolf_t *wolf3d, ray_context_t *ctx)
{
    float2_t pos = {0};

    sprite_t ennemies = {0};
    ennemies.vilain_texture = sfTexture_createFromFile(PLAYER_SPRITE, NULL);
    for (int i = 0; i < wolf3d->player_count; ++i) {
        if (i == wolf3d->player_id || !wolf3d->players[i].is_alive)
            continue;
        pos.x = wolf3d->players[i].x;
        pos.y = wolf3d->players[i].y;
        cast_ennemies(ctx, pos, ennemies, 48);
    }
}

// main loop
void update_multiplayer_frame(wolf_t *wolf3d, ray_context_t *ctx)
{
    float dt;
    const texture_t hud[] = {BLOOD_LINE, MANA_LINE, STAMINA_LINE, END};

    if (wolf3d->sock < 0)
        return;
    dt = sfTime_asSeconds(sfClock_restart(wolf3d->clock));
    process_input(&wolf3d->player, dt, wolf3d, &wolf3d->weapons);
    send_player_state(wolf3d);
    receive_players_state(wolf3d);
    update_other_players_state(wolf3d);
    cast_rays(ctx);
    draw_other_players(wolf3d, ctx);
    weapon_update(&wolf3d->weapons, ctx, wolf3d);
    weapon_draw(&wolf3d->weapons, wolf3d->window, ctx->screenW, ctx->screenH);
    minimap_draw(&wolf3d->minimap, &wolf3d->map, &wolf3d->player);
    handle_player_hud(wolf3d, (texture_t *)hud, RECT_TEXTURE);
    draw_hud(wolf3d);
    update_stamina_mana(wolf3d);
}
