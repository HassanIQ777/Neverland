# Neverland

> *"In a vast kingdom, there exists a nurturing Queen,*
> *So powerful yet caring, so easy yet keen.*
> *Ages will pass, then a warrior will arise,*
> *That warrior will bring this kingdom to its demise."*

A terminal RPG written in C++ — built years ago when the author thought putting 2,000 lines in a single `main.cpp` was peak software architecture. It was. Probably still is.

You wake up in a cave. You don't know why. You find a sword stuck in a rock (classic). You step into **Neverland** and start walking toward your destiny — or the nearest Goblin Brewer, whichever comes first.

---

## Features

- **A full narrative RPG** with an intro prophecy, NPCs, dialogue, and a final boss fight against the Queen herself
- **Turn-based combat** — Attack, Defend (with 65% block chance + healing), Run away like a coward (75% success), or chug a Healing Potion
- **Adrenaline system** — build it up in battle, unleash an Energy Burst for 2.5× damage
- **Character creation** — pick your name and race, which affects absolutely nothing but makes you feel special
- **Leveling & XP** — defeat enemies, grow stronger, unlock higher damage thresholds
- **Economy** — earn Zyniolax (yes, that's the currency), buy potions and charms at the Goblin Brewer's shop
- **Sword upgrades** — visit the Swordsmith at 35 Bosels for +15% damage per upgrade (3 upgrades max, by law of the Kingdom)
- **Zyniolax Charm** — makes enemies drop ~34% more money on death
- **A horse** — find it at 42 Bosels, tame it, travel faster, and respawn there instead of the very beginning
- **3-floor castle** — ascend staircases, discover hidden items (Crystalized Goop, Rancid Egg), fight escalating enemies
- **13 achievements** — from `pet_owner` and `sword_master` to `heavy_drinker` and `slayer_of_worlds`
- **A full cast of NPCs** — Goblin Brewer, Swordsmith, Old Man, Acid Watcher, Traitor, Shaman, Citizen, Acid Golem boss, and the Queen
- **Cross-platform build** — Linux, Windows, Android (Termux). Though the game *does* display a notice advising against playing on mobile. Charming.

---

## World

The game world is measured in **Bosels**. Key landmarks along the road:

| Distance | Event |
|---|---|
| 0 | Cave start, sword obtained |
| 18 | Goblin Brewer's hut (shop) |
| 20 | Meet the Old Man |
| 35 | Swordsmith (sword upgrades) |
| 42 | Encounter the horse |
| 60 | Meet the Acid Watcher |
| 61 | Meet the Traitor (free potion) |
| 65 | City Gate — boss battle with the City Guard |
| 72 | The Shaman |
| 80 | Citizen encounter |
| 95 | Acid Golem boss fight |
| 96+ | Enter the castle (distance shown as `???`) |
| 115 | Staircase → Floor 2 |
| 119 (F1) | Crystalized Goop (+20% max health) |
| 125 | Staircase → Floor 3 |
| 128 (F2) | Rancid Egg |
| 135+ (F3) | Queen's chambers — final boss |

---

## Enemies

**Zone 1 (0–19 Bosels):** Goblin, Centipede, Tryonix, Elf, Aspid Minion, Troll

**Zone 2 (20–64 Bosels):** Witch, Wizard, Aspid Minion, Primal Aspid, Chinchilasaur

**Zone 3 (65–95 Bosels):** Aspid Minion, Aspid Warrior, Primal Aspid, Acid Hermit, Acid Slime

**Zone 4 (96+ Bosels):** Aspid Guard, Queen Servant, Acidmold, Aspid Minion

Plus two named bosses: **Acid Golem** (guards the castle gate) and **The Queen** (final boss, floor 3).

---

## Building

Requires a C++20-capable compiler (`g++`) and `make`.

```bash
git clone https://github.com/HassanIQ777/Neverland
cd Neverland
make
```

The Makefile automatically detects and links `libutils` (bundled). The binary is placed in the project root as `neverland`.

```bash
# Release build (default, -O2 -march=native -flto)
make

# Debug build (ASan + UBSan, -Og)
make debug

# Build and run immediately
make run

# Install to /usr/local/bin (or custom PREFIX)
make install
make install PREFIX=~/.local

# Uninstall (gets yeeted into the void, per the Makefile's words)
make uninstall

# Clean build artifacts
make clean
```

---

## Running

```bash
./neverland
```

Or if installed:

```bash
neverland
```

On **Android (Termux)**, it compiles and runs. The game itself will remind you this is not ideal. The reminder is correct.

---

## Dependencies

- **libutils** — bundled in the `libutils/` directory, handles terminal clearing, centered printing, cross-platform sleep (`msleep`), and input utilities. No external packages needed.
- Standard C++20 library

---

## Project Structure

```
Neverland/
├── main.cpp        # ~2000 lines of pure narrative courage
├── Makefile
├── libutils/       # Utility library (bundled)
│   └── src/
│       └── funcs.hpp
└── LICENSE         # MIT
```

---

## License

MIT — do whatever you want, just don't blame the Queen.

---

*Made by [HassanIQ777](https://github.com/HassanIQ777)*