# Wolf3D — Le Palais du Crépuscule

A first-person raycasting game written in **C** with **CSFML**, built as a team project during my studies at **Epitech** (2025).
The setting draws on Japanese folklore: you play a revenant warrior-monk climbing a cursed palace overrun by yōkai to defeat the shogun who sold his soul for eternal life.

## Features

- **Raycasting engine** — textured walls, floor and ceiling, with GLSL fragment shaders for lighting (`shaders/`)
- **Custom ECS library** (`lib/`, built as `libecs.a`) managing enemies, items and the boss
- **Combat** — multiple spells/weapons, mana and stamina, sprinting, a crosshair
- **Enemies & boss fight** — animated sprite enemies with movement AI, a boss with its own attacks and health bar
- **Items & inventory** — health/mana potions, keys, doors, a torch
- **HUD** — health / mana / stamina bars, minimap, kill/death overlay
- **Menus** — main menu, settings (graphics, audio, controls), pause, lore, credits, game over and victory screens
- **Dialogue system**, music and sound effects
- **Gamepad support**
- **Online multiplayer (bonus)** — a TCP server (`bonus/`) players join by IP
- **Data-driven levels** — maps, enemies and objects loaded from text files in `configs/`

## Requirements

- Linux
- `gcc` and `make`
- [CSFML](https://www.sfml-dev.org/download/csfml/) (graphics, window, system, audio)

On Debian/Ubuntu:

```sh
sudo apt install build-essential libcsfml-dev
```

## Build

```sh
make            # builds lib/libecs.a and the ./wolf3D binary
make -C bonus   # builds the multiplayer ./bonus/server
```

Other targets: `make clean`, `make fclean`, `make re`, `make gdb` (debug build launched in gdb).

## Run

Solo:

```sh
./wolf3D
```

Multiplayer — start the server on the host machine (it listens on port **4242**), then have each player connect with the host's IP:

```sh
./bonus/server
./wolf3D -I 127.0.0.1
```

## Controls

The layout targets an AZERTY keyboard.

| Key | Action |
| --- | --- |
| Z / Q / S / D | Move forward / left / back / right |
| ← / → | Turn the camera |
| Left Shift | Sprint (uses stamina) |
| E / Left click | Attack / cast |
| A | Switch weapon |
| F | Open door |
| R | Toggle torch |
| L | Drink health potion |
| M | Drink mana potion |
| Tab | Show kill/death overlay |

Gamepads are supported: left stick to move, right stick to turn, face/shoulder buttons for attack, doors, torch, potions and weapon switching.

## Project structure

```
.
├── src/          game sources (raycasting, player, enemies, boss, menus, HUD, sound…)
├── include/      game headers
├── lib/          small entity-component-system library (libecs)
├── bonus/        multiplayer server and client networking
├── shaders/      GLSL shaders for walls and floor
├── configs/      maps, enemy and object placement files
└── assets/       textures, sprites, fonts, music and sounds
```

## Map format

Map files in `configs/` start with the map width and height, followed by a grid of integers: `0` is empty floor, `1` a wall, and other values are special tiles such as doors.

## Lore

<details>
<summary>Read the story (French)</summary>

Il est des lieux dont le nom s’efface des mémoires, enseveli sous les cendres du temps et le silence des morts. Mais là-haut, dans les replis solennels des montagnes sacrées, là où les pins murmurent à l’oreille du vent et où les brumes s’attardent comme des âmes sans repos, s’élève encore le spectre d’un empire oublié : le Palais du Crépuscule.

Autrefois, ses murs d’onyx et de jade reflétaient la lumière d’un âge d’or. Les carillons chantaient au rythme des saisons, les cerisiers pleuraient des fleurs au pied de lanternes de pierre, et le shogun régnait en paix, drapé dans le silence d’une éternité conquise.

Mais l’éternité a un prix, et les dieux n’offrent rien sans retour.

Aveuglé par la peur de mourir, le shogun scella un pacte sous le clair de lune, dans les entrailles d’un sanctuaire ancien. Il lia son âme à celle des yōkais, esprits anciens nés du chaos et du soupir des forêts, en échange d’une vie sans fin. Les saisons passèrent, mais la nature, trahie, réclama justice.

Les esprits, dénaturés par la folie d’un homme, se révoltèrent. Ils jaillirent des ombres et du vent, rampèrent entre les dalles, possédèrent les gardes, les moines, les servantes, et jusqu’aux murs eux-mêmes. Le palais devint un tombeau vivant, un labyrinthe de murmures, d’yeux dissimulés et de larmes figées.

Et puis le silence. Un silence plus cruel que mille batailles.


---

Des siècles plus tard, quand les étoiles elles-mêmes ont cessé de nommer ce lieu, une cloche oubliée sonne dans l’au-delà. Le sol tremble sous les pas d’un revenant.

Toi.

Un moine-guerrier, jadis. Tu t’es consumé dans la flamme d’une guerre perdue, mais ton âme, pure et liée à une divinité que le monde n’adore plus, refuse de s’éteindre. La déesse de l’Aube t’a choisi pour rompre la nuit.

Tu reviens d’entre les morts. Tu n’es ni vivant ni spectre. Tu es le fil du karma, l’écho d’un serment oublié, la main vengeresse d’un monde brisé.

Ton souffle soulève la poussière des siècles. Chaque marche que tu gravis est un souvenir, chaque ennemi une énigme. Le Palais du Crépuscule t’attend, infesté d’abominations qui furent autrefois des hommes, des prêtres, des protecteurs.

Mais dans l’obscurité, il y a encore des braises. Des âmes piégées t’observent, prêtes à t’offrir leurs secrets, leurs larmes, leurs forces. Et au cœur du palais, le shogun t’attend.

Purifie le sang, tranche la corruption, et que l’aube, enfin, transperce le crépuscule

</details>

## Credits

Made as part of the Epitech curriculum (Wolf3D project) by a team of students.
Inspired by *Sekiro* and Japanese folklore.
