# Spartica: Galage-Style 2d Shooter Game
This game is a horizontally scrolling, 2d shooter game inspired by games such as galaga. 


For the sake of demo-ing the plugins made for assignment 2, the game loop and enemy spawn is temporarily disabled. The only thing that spawns is a fixed enemy that uses the plugin made. You can restart behavior using R.

## Controls
wasd or arrows to move, r to restart, and q to quit.

The game controls are also within 'game_controls.tscn'

## How to run
1. Clone this repository onto your computer
2. Open the Godot application, use the 'import' button to open the folder 'Spartica' within the repo.
3. Run the application. The default scene should be set to 'main_game.res', otherwise run 'main_game.res' directly. 
4. If there are issues importing the GD nodes, run 
 ```bash
 git submodule update --init
 scons platform=<platform>
```
within the home directory of the repository (not within spartica)

## Functionality
The assignment implemented a FSM that determines the movement of the enemy, changing and updating teh states based on player proximity. The plugin does this by making a base class, State, and two inherited classes, StateIdle and StateChasing. The state machine manages the changing, memory management, and updating of these states.

The enemy moves based off of what state the enemy is in. The enemy starts in 'Idle state', moving slowly left. if the player is within a close enough distance to the enemy, it changes to 'Chasing' state, both moving faster and moving towards the player. This encourages the player to shoot it before it gets too close.
