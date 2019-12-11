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
| Space       	| Shoot Laser Beam                         	|
| Left Arrow  	| Adjust Laser Beam Direction to the Left  	|
| Right Arrow 	| Adjust Laser Beam Direction to the Right 	|

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

### Sze Yuk Yin

1. Scoreboard Design

2. AVL Scoreboard data structure

3. Enemy Design

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
