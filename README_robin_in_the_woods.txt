# 🌲 Robin in the Woods

A terminal-based C adventure game where you — Robin — must outsmart enemies, survive deadly maps, and navigate your way through a series of increasingly dangerous stages. It's classic ASCII survival with movement, enemies, coins, and stage progression. All in glorious text-mode.

---

## 🎮 Gameplay Summary

You play as `Robin`, symbolized by `'P'`, navigating treacherous woods full of traps, enemies, and loot. Your goal is to reach the exit `'E'` while avoiding or surviving encounters with enemies `'Z'` and `'X'`.

- Collect coins (`'$'`)
- Dodge enemies or lose health (`*`)
- Survive all stages to win
- Die… and it’s over

---

## 🎯 Objective

- 🏃 Reach the exit (marked `'E'`)
- 💰 Collect money to increase your score
- 💔 Avoid enemies and hazards — you only have 5 hits!
- 🔁 Progress through all available stages

---

## 🕹 Controls

W / w / 8 → Move Up
A / a / 4 → Move Left
S / s / 2 → Move Down
D / d / 6 → Move Right
Q / q → Quit Game


---

## 📦 Features

- 3 unique hand-coded stages (more can be added!)(you can design ur own stages! :) )
- Enemy movement logic (Zombies and stronger X-types)
- Collectible coins and a money system
- Health meter represented with hearts
- Stage transitions and level resets
- Simple enemy AI using a move pattern

---

## 🧰 How to Run

You'll need a C compiler like GCC.

```bash
gcc main.c -o robin
./robin
