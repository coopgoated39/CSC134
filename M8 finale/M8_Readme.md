Avengers Battle

Overview:

Avengers Battle is a text-and-graphics adventure game built with Python and Pygame. Players explore different rooms, collect items, battle villains, and try to defeat the final enemy in the Villain’s Lair. The game displays a scrolling log window using Pygame while the player types commands through the console.

Features:

Explore multiple connected rooms (HQ, New York, Wakanda, Villain’s Lair)

Turn-based combat with damage affected by inventory items

Collectable items including Mjolnir, Shield, Vibranium Suit, and the Infinity Stone

Healing items such as Medkits and Potions

Sound effects for attacking, getting hit, and healing

Win by defeating all villains; lose if your HP reaches zero

Controls:

All commands are typed into the console.

Movement:

north / n

east / e

south / s

west / w

Actions:

look — inspect items or surroundings

take — pick up the object or item in the room

attack — attack during battle

run — retreat from battle

use — use a healing item

quit / q — exit the game

Combat System

Combat begins automatically when entering a room with a villain. Damage is affected by your inventory:

Mjolnir: +10 attack damage

Infinity Stone: +20 attack damage

Shield: -5 incoming damage

Vibranium Suit: -10 incoming damage

The villain in the Villain’s Lair deals extra damage.

Requirements:

Python 3.8 or higher

Pygame
Install Pygame with:
pip install pygame

Required Sound Files

Place these files in the same folder as the game script:

attack.wav

hit.wav

heal.wav

How to Run:

Run the game with:
python your_script_name.py

A Pygame window will display the game log. Enter commands in the console.

File Structure Example

AvengersBattle/

avengers_battle.py

attack.wav

hit.wav

heal.wav

README.md

License:

You are free to modify or extend this project however you like.