# Plants vs Zombies
## Introduction
Plants vs Zombies was developed as an educational project for OOP practice at Bauman Moscow State Technical University.

In this game plants try to defeat zombies, who want to go through the field. Before zombies start to attack, player has to put plants on the field. To do that he uses WASD keys to move on the field in 4 directions: up, down, left, right. Player press the space key to put plants on the field and enter to run the game. The number of zombies and plants differs depending on the level chosen by player. As zombies reach the other side of the field or plants defeat all zombies, the game ends with displaying the information about the winner.

Program interface is implemented in UNIX console. There are two types of graphics: color and symbol.

## Showcase
[Запись экрана от 30.01.2024 13:36:38.webm](https://github.com/dalatea/Plants_vs_zombies/assets/148526614/038f8ce6-d886-43ac-957d-c5195999239e)


## Installation

git clone https://github.com/dalatea/Plants_vs_zombies

cd Plants_vs_zombies/build

cmake ..

make

## Features

1. Storage of user data, choice of graphics
2. Table of defeated zombies and plants
3. Multiple game levels (set in settings.txt):
* Level_1: field 1x6, number of plants 4
* Level_2: field 2x6, number of plants 8
* Level_3: field 3x6, number of plants 12
* Level_4: field 4x6, number of plants 16
* Level_5: field 5x6, number of plants 20
4. Zombie randomizer (zombies spawn in different places)
5. Player can move on the field and put plants on it.
## Requirements
* Unix
* Git
* C++11 or higher
* Cmake
