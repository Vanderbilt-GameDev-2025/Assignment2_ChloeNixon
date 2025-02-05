# Spartica: Galage-Style 2d Shooter Game
This game is a horizontally scrolling, 2d shooter game inspired by games such as galaga. The player's objective is to shoot as many enemies as possible before being hit by an enemy themselves.

## How to run
1. Clone this repository onto your computer
2. Open the Godot application, use the 'import' button to open the folder 'Spartica' within the repo.
3. Run the application. The default scene should be set to 'game_controls.tcsn', otherwise run 'main_game.tscn' directly.
4. If there are issues importing the GD nodes, run 
 ```bash
 git submodule update --init
 scons platform=<platform>
```
within the home directory of the repository (not within spartica)

## Functionality
- Sound effects for shooting, hitting, and killing enemies.
- All assets are made from scratch within illustrator, except for the background planets, body font, and sounds.
- Full gameplay loop with scoring, losing conditions, and restart conditions.
- Full interaction and collision with enemies and player.
- Difficulty that increases over time.
-  Randomly spawning enemies and particle effects.
![alt text](image-1.png)
![alt text](image.png)

## Controls
Controls are explained in the 'controls' scene when the game is first run. Movement is with WASD and arrows, shooting is with holding down or pressing E, and R restarts the game. Q also quits the game.