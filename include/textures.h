/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** textures
*/

#ifndef TEXTURE_MANAGER_H_
    #define TEXTURE_MANAGER_H_
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "positions.h"

typedef enum {
    END = -1,
    PLAY_BTN = 0,
    BACK_BTN = 1,
    SETTINGS_BTN = 2,
    LEAVE_BTN = 3,
    FADE1 = 4,
    FADE3 = 5,
    GAMEMODE_BTN = 6,
    VOLUME_SLIDER = 7,
    SLIDER_HANDLE = 8,
    BR_BTN = 9,
    MULTI_BTN = 10,
    ZOMBIE_BTN = 11,
    KEY_A = 12,
    KEY_D = 13,
    KEY_E = 14,
    KEY_Q = 15,
    KEY_S = 16,
    KEY_Z = 17,
    KEY_R = 18,
    KEY_F = 19,
    KEY_H = 20,
    KEY_M = 21,
    KEY_ARROW_L = 22,
    KEY_ARROW_R = 23,
    KEY_SHIFT = 24,
    PLAYER_HUD = 25,
    BLOOD_LINE = 26,
    MANA_LINE = 27,
    STAMINA_LINE = 28,
    DEVIDER1 = 29,
    CARD_GAME = 30,
    CLOSE_BTN = 31,
    HUD_MINIMAP = 32,
    SKELETON_HEAD = 33,
    AUDIO_BTN = 34,
    GRAPHICS_BTN = 35,
    CONTROLS_BTN = 36,
    WINDOW_MODE = 37,
    HOST_BTN = 38,
    JOIN_BTN = 39,
    CREDITS_BTN = 40,
    SAVE_BTN = 41,
    HUD_ITEMS = 42,
    BOSS_BAR = 43,
    BOSS_FILLER = 44,
    HEART = 45,
    BOSS_KEY = 46,
    INPUT = 47,
    HEALTH_BOTLE = 48,
    MANA_BOTLE = 49,
    PREVIEW_SP1 = 50,
    PREVIEW_SP2 = 51,
    PREVIEW_SP3 = 52,
    LORE_BTN = 53,
    MAIN_BG = 54,
    WIN_BG = 55,
    LOOSE_BG = 56,
    HUD_KD = 57,
    SELECTED = 58,
    SELECTED2 = 59,
    HUD_OBJ = 60,
    OBJ_IND = 61,
} texture_t;

static const char *TEXTURES_PATHS[] __attribute__((used)) = {
    "assets/MENU_UI_KIT/Buttons/Buttons_Selected.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Fade effects/Fade_1.png",
    "assets/MENU_UI_KIT/Fade effects/Fade_3.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Sliders/horizontal_Slider-bar.png",
    "assets/MENU_UI_KIT/Sliders/horizontal_Slider.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/textures/menu/settings/keys/key_a.png",
    "assets/textures/menu/settings/keys/key_d.png",
    "assets/textures/menu/settings/keys/key_e.png",
    "assets/textures/menu/settings/keys/key_q.png",
    "assets/textures/menu/settings/keys/key_s.png",
    "assets/textures/menu/settings/keys/key_z.png",
    "assets/textures/menu/settings/keys/key_r.png",
    "assets/textures/menu/settings/keys/key_f.png",
    "assets/textures/menu/settings/keys/key_l.png",
    "assets/textures/menu/settings/keys/key_h.png",
    "assets/textures/menu/settings/keys/key_arrow_left.png",
    "assets/textures/menu/settings/keys/key_arrow_right.png",
    "assets/textures/menu/settings/keys/key_shift.png",
    "assets/MENU_UI_KIT/Health Bar/Player_hud.png",
    "assets/MENU_UI_KIT/Health Bar/Blood_Filler.png",
    "assets/MENU_UI_KIT/Health Bar/Mana_Filler.png",
    "assets/MENU_UI_KIT/Health Bar/Stamina_Filler.png",
    "assets/MENU_UI_KIT/deviders/deviders1.png",
    "assets/MENU_UI_KIT/Scalable screen/Scalable_4.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Item holders/32px_2.png",
    "assets/MENU_UI_KIT/head/skeleton_head.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/MENU_UI_KIT/Item holders/Hud_Item_selector.png",
    "assets/MENU_UI_KIT/Boss-bars/Bossbar.png",
    "assets/MENU_UI_KIT/Boss-bars/Boss_Filler.png",
    "assets/textures/heart.png",
    "assets/Key_8.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_1.png",
    "assets/pots/health_pot.png",
    "assets/pots/mana_pot.png",
    "assets/spells/preview/spell_2_bullet.png",
    "assets/spells/preview/spell_3_bullet.png",
    "assets/spells/torch_player.png",
    "assets/MENU_UI_KIT/Buttons/Buttons_4.png",
    "assets/backgrounds/main_menu.png",
    "assets/backgrounds/win.jpg",
    "assets/backgrounds/game_over.jpg",
    "assets/MENU_UI_KIT/Scalable screen/Scalable_4.png",
    "assets/MENU_UI_KIT/Scalable screen/Selected_.png",
    "assets/MENU_UI_KIT/Scalable screen/bg_kd.png",
    "assets/MENU_UI_KIT/Scalable screen/Scalable_4.png",
    "assets/MENU_UI_KIT/Sliders/circle_filler.png",
};

static const sfIntRect RECT_TEXTURE[] = {
    {0, 0, 88, 13},
    {0, 0, 88, 13},
    {0, 0, 88, 13},
    {0, 0, 88, 13},
    {0, 0, 180, 32},
    {0, 0, 180, 48},
    {0, 0, 88, 13},
    {0, 0, 79, 13},
    {0, 0, 13, 9},
    {0, 0, 88, 13},
    {0, 0, 88, 13},
    {0, 0, 88, 13},
    {0, 0, 16, 16},
    {0, 0, 16, 16},
    {0, 0, 16, 16},
    {0, 0, 16, 16},
    {0, 0, 16, 16},
    {0, 0, 16, 16},
    {0, 0, 16, 16},
    {0, 0, 16, 16},
    {0, 0, 16, 16},
    {0, 0, 16, 16},
    {0, 0, 16, 16},
    {0, 0, 16, 16},
    {0, 0, 32, 16},
    {0, 0, 133, 36},
    {0, 0, 68, 3},
    {0, 0, 85, 3},
    {0, 0, 57, 3},
    {0, 0, 160, 20},
    {0, 0, 80, 64},
    {0, 0, 88, 13},
    {0, 0, 32, 32},
    {0, 0, 374, 372},
    {0, 0, 88, 13},
    {0, 0, 88, 13},
    {0, 0, 88, 13},
    {0, 0, 88, 13},
    {0, 0, 88, 13},
    {0, 0, 88, 13},
    {0, 0, 88, 13},
    {0, 0, 88, 13},
    {0, 0, 74, 56},
    {0, 0, 192, 18},
    {0, 0, 188, 9},
    {0, 0, 27, 27},
    {0, 0, 21, 47},
    {0, 0, 88, 13},
    {0, 0, 22, 37},
    {0, 0, 22, 37},
    {0, 0, 43, 46},
    {0, 0, 64, 56},
    {0, 0, 156, 104},
    {0, 0, 88, 13},
    {0, 0, 1920, 1104},
    {0, 0, 736, 414},
    {0, 0, 736, 414},
    {0, 0, 80, 64},
    {0, 0, 48, 44},
    {0, 0, 48, 44},
    {0, 0, 80, 64},
    {0, 0, 9, 9},
};

typedef struct texture_asset_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    bool is_loaded;
} texture_asset_t;

typedef struct {
    char *str;
    unsigned int size;
    sfVector2f pos;
    bool visible;
} text_entity_t;

typedef struct {
    sfVector2f *positions;
    sfVector2f *scales;
} texture_draw_params_t;

typedef struct texture_manager_s {
    texture_asset_t *assets;
    text_entity_t *texts;
    sfText **sf_texts;
    size_t count;
    bool initialized;
    sfFont *font;
} texture_manager_t;

typedef enum {
    TXT_PLAY = 0,
    TXT_SETTINGS = 1,
    TXT_GAMEMODE = 2,
    TXT_LEAVE = 3,
    TXT_VOLUME = 4,
    TXT_BACK = 5,
    TXT_TILE = 6,
    TXT_BR = 7,
    TXT_MU = 8,
    TXT_ZO = 9,
    TXT_CGAME = 10,
    TXT_CLOSE = 11,
    TXT_S_IN_S = 12,
    TXT_AUDIO = 13,
    TXT_GRAPHICS = 14,
    TXT_CONTROLS = 15,
    TXT_MODE = 16,
    TXT_SWITCH = 17,
    TXT_KEY_A = 18,
    TXT_KEY_D = 19,
    TXT_KEY_E = 20,
    TXT_KEY_Q = 21,
    TXT_KEY_S = 22,
    TXT_KEY_Z = 23,
    TXT_KEY_F = 24,
    TXT_KEY_ARROW_L = 25,
    TXT_KEY_ARROW_R = 26,
    TXT_KEY_SHIFT = 27,
    TXT_PRE_MULTI = 28,
    TXT_HOST = 29,
    TXT_JOIN = 30,
    TXT_GAME_OVER = 31,
    TXT_CREDITS = 32,
    TXT_LORE = 33,
    TXT_MIRA = 34,
    TXT_SANDES = 35,
    TXT_PHIL = 36,
    TXT_C_IN_C = 37,
    TXT_SAVE = 38,
    TXT_PAUSE = 39,
    TXT_KEY_R = 40,
    TXT_KEY_MANA = 41,
    TXT_KEY_HEALTH = 42,
    TXT_GAME_WIN = 43,
    TXT_BTN_LORE = 44,
    TXT_CREDIT_1 = 45,
    TXT_CREDIT_2 = 46,
    TXT_CREDIT_3 = 47,
    TITLE_CREDIT_SPRITE = 48,
    TXT_TEAM = 49,
    TXT_OBJ1 = 50,
    TXT_OBJ2 = 51,
    TXT_OBJ3 = 52,
    TXT_COUNT
} text_id_t;

static const text_entity_t TEXT_ENTITIES[TXT_COUNT] = {
    [TXT_PLAY] = { "Play", 34, {POFT(LEFT_PLACE, 165), 407}, false },
    [TXT_SETTINGS] = { "Settings", 34, {POFT(LEFT_PLACE, 120), 506}, false },
    [TXT_GAMEMODE] = { "Gamemode", 34, {POFT(LEFT_PLACE, 110), 606}, false },
    [TXT_LEAVE] = { "Leave", 34, {POFT(LEFT_PLACE, 150), 706}, false },
    [TXT_VOLUME] = { "Volume", 34, {POFT(LEFT_PLACE, 50), 500}
        , false },
    [TXT_BACK] = { "Back", 34, {POFT(50, 162), 55}, false },
    [TXT_TILE] = { "Le palais du crepuscule", 80,
        {NOFT((WIN_WIDTH / 2), 450), POFT(0, 85)}, false },
    [TXT_BR] = { "Back room", 34, {POFT(LEFT_PLACE, 120), 455}, false },
    [TXT_MU] = { "Multijoueur", 34, {POFT(MIDDLE_X, 20), 455}, false },
    [TXT_ZO] = { "Zombie", 34, {NOFT(WIN_WIDTH, 500), 455}, false },
    [TXT_CGAME] = { "Choose your gamemode", 60,
        {NOFT((WIN_WIDTH / 2), 330), POFT(0, 60) }, false },
    [TXT_CLOSE] = { "Close", 34, {POFT(50, 162), 55}, false },
    [TXT_S_IN_S] = { "Settings", 60,
        {NOFT((WIN_WIDTH / 2), 130), POFT(0, 190) }, false },
    [TXT_AUDIO] = { "Audio", 34, {NOFT(MIDDLE_X, 280), 315}, false },
    [TXT_GRAPHICS] = { "Graphics", 34, {POFT(MIDDLE_X, 30), 315}, false },
    [TXT_CONTROLS] = { "Controls", 34, {POFT(MIDDLE_X, 360), 315}, false },
    [TXT_MODE] = { "Window mode", 34, {POFT(LEFT_PLACE, 50), 500}, false },
    [TXT_SWITCH] = { "Change window mode", 34, {POFT(LEFT_PLACE, 300), 500},
        false },
    [TXT_KEY_A] = {"Change weapon", 25, {POFT(LEFT_PLACE, 300), 470}, false},
    [TXT_KEY_Z] = {"Go forward", 25, {POFT(LEFT_PLACE, 300), 520}, false},
    [TXT_KEY_E] = {"Shoot", 25, {POFT(LEFT_PLACE, 300), 570}, false},
    [TXT_KEY_S] = {"Go backward", 25, {POFT(LEFT_PLACE, 300), 620}, false},
    [TXT_KEY_Q] = {"Go left", 25, {POFT(LEFT_PLACE, 300), 670}, false},
    [TXT_KEY_D] = {"Go right", 25, {POFT(LEFT_PLACE, 300), 720}, false},
    [TXT_KEY_F] = {"Interact", 25, {POFT(MIDDLE_X, 300), 470}, false},
    [TXT_KEY_ARROW_L] = {"Look left", 25, {POFT(LEFT_PLACE, 300), 770}, false},
    [TXT_KEY_ARROW_R] = {"Look right", 25, {POFT(LEFT_PLACE, 300), 820},
        false},
    [TXT_KEY_SHIFT] = {"Sprint", 25, {POFT(LEFT_PLACE, 300), 870}, false},
    [TXT_PRE_MULTI] = { "Do you want", 80,
        {NOFT((WIN_WIDTH / 2), 230), POFT(0, 60) }, false},
    [TXT_HOST] = { "Hosting", 34, {POFT(LEFT_PLACE, 120), 455}, false},
    [TXT_JOIN] = { "Join a server", 34, {NOFT(WIN_WIDTH, 500), 455}, false},
    [TXT_GAME_OVER] = {"Silence ...", 80,
        {NOFT((WIN_WIDTH / 2), 150), POFT(0, 60) }, false},
    [TXT_CREDITS] = { "Credits", 34,
        {NOFT(WIN_WIDTH, 160), NOFT(WIN_HEIGHT, 150)}, false},
    [TXT_LORE] = {
        "Il est des lieux dont le nom s'efface des memoires, enseveli sous"
        " les cendres du temps et le silence des morts.\nMais la-haut,"
        " dans les replis solennels des montagnes sacrees, la ou les pins"
        " murmurent a l'oreille du vent et ou\nles brumes s'attardent comme"
        " des ames sans repos, s'eleve encore le spectre d'un empire "
        "oublie : le Palais du\nCrepuscule.\n\nAutrefois, ses murs d'onyx"
        " et de jade refletaient la lumiere d'un age d'or. Les carillons"
        " chantaient au rythme des\nsaisons, les cerisiers pleuraient des"
        " fleurs au pied de lanternes de pierre, et le shogun regnait en"
        " paix, drape dans le\nsilence d'une eternite conquise.\n\n"
        "Mais l'eternite a un prix, et les dieux n'offrent rien sans"
        " retour.\n\nAveugle par la peur de mourir, le shogun scella un"
        " pacte sous le clair de lune, dans les entrailles d'un"
        " sanctuaire\nancien. Il lia son ame a celle des yokais, esprits"
        " anciens nes du chaos et du soupir des forets, en echange d'une"
        " vie\nsans fin.\nLes saisons passerent, mais la nature, trahie,"
        " reclama justice.\n\nLes esprits, denatures par la folie d'un "
        "homme, se revolterent. Ils jaillirent des ombres et du vent, "
        "ramperent entre\nles dalles, possederent les gardes, les moines, "
        "les servantes, et jusqu'aux murs eux-memes. Le palais devint un\n"
        "tombeau vivant,\nun labyrinthe de murmures, d'yeux dissimules et"
        " de larmes figees.\n\nEt puis le silence. Un silence plus cruel "
        "que mille batailles.\n\nDes siecles plus tard, quand les etoiles"
        " elles-memes ont cesse de nommer ce lieu, une cloche oubliee"
        " sonne dans\nl'au-dela. Le sol tremble sous les pas d'un"
        "revenant.\nToi.\nUn moine-guerrier, jadis. Tu t'es consume"
        " dans la flamme d'une guerre perdue, mais ton ame, pure et liee"
        " a une\ndivinite que le monde n'adore plus, refuse de s'eteindre."
        " La deesse de l'Aube t'a choisi pour rompre la nuit.\n\nTu "
        "reviens d'entre les morts. Tu es ni vivant ni spectre. "
        "Tu es le fil du karma, l'echo d'un serment oublie, la main\n"
        " vengeresse d'un monde brise.\n\nTon souffle souleve la poussiere"
        " des siecles. Chaque marche que tu gravis est un souvenir,"
        " chaque ennemi une\nenigme. Le Palais du Crepuscule t'attend,"
        " infeste d'abominations qui furent autrefois des hommes,"
        " des pretres,\ndes protecteurs.\n\nMais dans l'obscurite, il y a "
        "encore des braises. Des ames piegees t'observent, pretes a "
        "t'offrir leurs\nsecrets, leurs larmes, leurs forces. Et au coeur "
        "du palais, le shogun t'attend.\n\nPurifie le sang, tranche la "
        "corruption, et que l'aube, enfin, transperce le crepuscule",
        21,
        {NOFT(MIDDLE_X, 110), 50},
        false
    },
    [TXT_MIRA] = { "Mirado", 34, {LEFT_PLACE, 315}, false },
    [TXT_SANDES] = { "Sandes", 34, {POFT(LEFT_PLACE, 620), 315}, false },
    [TXT_PHIL] = { "Philibert", 34, {NOFT(WIN_WIDTH, 440), 315}, false },
    [TXT_C_IN_C] = { "Credits", 80, {NOFT((WIN_WIDTH / 2), 150), POFT(0, 55)},
        false },
    [TXT_SAVE] = { "Save", 34, {POFT(LEFT_PLACE, 165), 407}, false},
    [TXT_PAUSE] = { "Pause", 80, {NOFT((WIN_WIDTH / 2), 120), POFT(0, 65)},
        false },
    [TXT_KEY_R] = {"Use torch", 25, {POFT(MIDDLE_X, 300), 520}, false},
    [TXT_KEY_MANA] = {"Use mana bottle", 25,
        {POFT(MIDDLE_X, 300), 570}, false},
    [TXT_KEY_HEALTH] = {"Use health bottle", 25,
        {POFT(MIDDLE_X, 300), 620}, false},
    [TXT_GAME_WIN] = { "L'aube transperce le crepuscule", 50,
        {NOFT((WIN_WIDTH / 2), 380), POFT(0, 60) }, false},
    [TXT_BTN_LORE] = { "Lore", 34, {POFT(LEFT_PLACE, 165), 806}, false },
    [TXT_CREDIT_1] = {"Menu & HUD : Finnmercury", 34, {LEFT_PLACE, 615},
        false},
    [TXT_CREDIT_2] = {"Background : Pinterest", 34, {LEFT_PLACE, 655}, false},
    [TXT_CREDIT_3] = {"Boss sprite : Mattz Art", 34, {LEFT_PLACE, 695}, false},
    [TITLE_CREDIT_SPRITE] = {"Pour les sprites", 40,
        {NOFT(LEFT_PLACE, 50), 545}, false},
    [TXT_TEAM] = {"Miaou Miaou !", 34,
        {NOFT(LEFT_PLACE, 50), 215}, false},
    [TXT_OBJ1] = {"Recuperer la clef", 25, {50, NOFT(MIDDLE_Y, 15)}, false},
    [TXT_OBJ2] = {"Tuer le boss", 25, {50, POFT(MIDDLE_Y, 25)}, false},
    [TXT_OBJ3] = {"Trouver la salle du boss", 25, {50, POFT(MIDDLE_Y, 65)}, false},
};

texture_manager_t *create_texture_manager(void);
bool init_texture_manager(texture_manager_t *manager);
sfSprite *get_sprite(texture_manager_t *manager, texture_t id);
sfTexture *get_texture(texture_manager_t *manager, texture_t id);
void destroy_texture_manager(texture_manager_t *manager);
void destroy_texts_entities(texture_manager_t *manager, const text_id_t *ids,
    size_t id_count);
#endif /* !TEXTURE_MANAGER_H_ */
