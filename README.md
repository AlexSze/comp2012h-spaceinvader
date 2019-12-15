# Space Invader++

## Contributors (in alphabetical order)

1. Lee Ho Wan Owen

2. Sze Yuk Yin

3. Tsang Cheuk Nam

## Game Description

Space Invader++ is a modern replica of a classic arcade game, Space Invader written in C++ with a QT frontend. 

## Game Controls

| Key         	| Description                              	|
|-------------	|------------------------------------------	|
| W           	| Move Player Upwards                      	|
| A           	| Move Player to the Left                  	|
| S           	| Move Player Downwards                    	|
| D           	| Move Player to the Right                 	|
| Space       	| Shoot Missiles                         	|
| Left Arrow  	| Adjust Missile Direction to the Left  	|
| Right Arrow 	| Adjust Missile Beam Direction to the Right 	|

## File Structure

`./README.md` is the documentation of the project

`./scoreboard.csv` is an example csv file for the scorring system

`./src` is a folder containing the QT project and all its assets. See `COMP2012H_Group_H20.pro` inside the folder for more detail on the files inside the subdirectory


## Data Structure

## Division of Labor

### Lee Ho Wan Owen

1. Project Report

2. Level Design

3. Boss Design

4. Game Flow Design

### Sze Yuk Yin

1. Game Flow Backend (gamescene, boss, health, score, life, tools)

2. Scoreboard Backend (AVl data structure)

3. Game UI design (win screen, defeat screen, main screen, avl scene)

4. Game Logic (Control, Scene settings)

### Tsang Cheuk Nam

1. Game Flow Backend

2. Player Implementation

3. Display Window Implementation

4. Debugging

5. File I/O

## What we have learned

### Collaboration across different time zones

During the project's creation, one of our teammates are in a vastly different timezone with little overlap of working hour. It has proven challenging to be unable to work and communicate simutaniously. As a result, early progress are made individually with little communication, making it difficult to integrate features as a whole. Later on, we learned to communicate with a shared list for what has been done and what needs to be done, as well as extensive comments on the shared code to avoid repeated reference reading work. At the end, we overcame the barrier of distance and have grown a rigid communication skill with precise word choices to have the project finished.

### Version control and importance of off-site backing up

At one stage of development, one of our teammates pushed known crashing code into the repository, overwriting previous work and rendered other progress untestable. It is especially problematic since the crash will effect the display session of the entire desktop so we cannot read the error code or debugging information effectively. Fortunately, we have periodically backup the project at every milestone. It is very valuable to be able to compare the problem code with known working versions and pinpoint where are the bugs. With this incident in mind, we think we will be able to make better use of branching and version control of git in the future as well as having backup on past and current projects.

## Potential for future work on the project

### Infinity Mode

The key feature in the next update would be the introduction of the Infinity Mode. Under Infinity Mode, a scene the same as level 1 will be established. As the current enemy squad nears elimination, a new wave with an increase in enemy rows and an increment of bosses will spawn, resulting in a never-ending game until the player is overwhelmed by the sheer number of enemy firepower. A new derived class GameSceneInfinity depicted in “gamesceneinfinity.h” inherits the GameScene class, yet during initial design of the base class functions, we had yet to conjure this idea. We were ultimately unable to fully implement Infinity Mode within our limited time span, and its prototypical design details are left as “Easter Eggs” for passionate gamers to explore.

### Memory Leak

In the process of debugging the project, there is a consistent set size of memory leak when we are testing it. The majority of which are found to be a bug in QT's Media Player for the audio aspect of the project, which we have yet to test every versions of. In the future, we can setup various QT versions to find out which would have the best memory leak prevention. However, since the leak is not in the scope of our code, memory leak at the scale of the size of media we uses is the best we can deliver.

As pointed out in the following [QT Forum discussion](https://forum.qt.io/topic/84048/memory-leak-on-empty-qt-widgets-application), memory leak at this scale are likely false positives especially when objects are allocated and deallocated frequently without increase in the indicated memory leak.

