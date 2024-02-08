# Plants vs Zombies
## Introduction
Plants vs Zombies was developed as an educational project for OOP practice at Bauman Moscow State Technical University.

In this game plants try to defeat zombies, who want to go through the field. Before zombies start to attack, player has to put plants on the field. To do that he uses WASD keys to move on the field in 4 directions: up, down, left, right. Player press the space key to put plants on the field and enter to run the game. The number of zombies and plants differs depending on the level chosen by player. As zombies reach the other side of the field or plants defeat all zombies, the game ends with displaying the information about the winner.

Program interface is implemented in UNIX console. There are two types of graphics: color and symbol.

## Showcase

![Запись экрана от 30 01 2024 13 39 30](https://github.com/dalatea/Plants_vs_zombies/assets/148526614/faa34b0f-9185-4c35-a66e-e04b52e442ad)

![Запись экрана от 05 02 2024 18 22 49](https://github.com/dalatea/Plants_vs_zombies/assets/148526614/5523a085-9cb6-47c7-a4eb-45c0bf06e268)



## Installation
```bash
git clone https://github.com/dalatea/Plants_vs_zombies
mkdir -p Plants_vs_zombies/build
cd Plants_vs_zombies/build
cmake ..
make
```
## Features

1. Player can choose type of graphics and level in the menu
2. Player can move on the field and put plants on it using WASD keys
3. The game can be started by pressing the Enter button or using all of the plants available for current level
4. Levels differ with game difficulty, they can be changed in settings.txt file. Current settings:
* Level_1: field 1x6, number of plants 4
* Level_2: field 2x6, number of plants 8
* Level_3: field 3x6, number of plants 12
* Level_4: field 4x6, number of plants 16
* Level_5: field 5x6, number of plants 20
5. Every time zombie spawns in random place
6. The game can be stopped by pressing ^C or by waiting until the end
7. In the end player gets the message about the results of this round
## Requirements
* Unix
* Git
* C++11 or higher
* Cmake
