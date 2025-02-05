extends Node2D

#possible enemy scenes that can spawn
@export var enemy_scene_gd: Array[PackedScene] = []
# parallax scroll speeds
var scroll_speeds = [35, 150]
		
@onready var player = $player
@onready var player_spawn_pos = $playerSpawnPosition
@onready var player_position = player_spawn_pos
#parent node of all bullets on screen
@onready var bullet_container = $bulletContainer
#timer before an enemy is spawned in
@onready var spawn_timer = $enemySpawnTimer
#parent node of all enemies on screen
@onready var enemy_container = $enemyContainer
#scoreboard scene
@onready var scorehud = $UILayer/HUD
@onready var gameoverhud = $UILayer/gameOverHUD
@onready var background = $ParallaxBackground
@onready var foreground = $ParallaxForeground

@onready var sound_bullet = $SFX/bullet_shot
@onready var sound_hit = $SFX/enemy_hit
@onready var sound_killed = $SFX/enemy_killed

signal player_coordinates(coordinates)
@onready var player_pos = player_spawn_pos

#sets score to value after enemy is killed, set into scoreboard
var score := 0:
	set(value):
		score = value
		scorehud.score = score

## Called when the node enters the scene tree for the first time.
func _ready() -> void:
	score = 0
	
	player.global_position = player_spawn_pos.global_position
	player.bullet_shot.connect(_on_player_bullet_shot)
	player.player_killed.connect(_on_player_killed)

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	if Input.is_action_just_pressed("quit"):
		get_tree().quit()
	elif Input.is_action_just_pressed("reset"):
		get_tree().reload_current_scene()
	
	#decrements spawn timer at a constant rate, capping it at .4 seconds per spawn
	if spawn_timer.wait_time >= .2:
		spawn_timer.wait_time -= delta * 0.015
	
	#scrolls background and foreground at different speeds
	background.scroll_offset.x -= delta * scroll_speeds[0]
	if background.scroll_offset.x >= 1820:
		background.scroll_offset.x = 0
	foreground.scroll_offset.x -= delta * scroll_speeds[1]
	if foreground.scroll_offset.x >= 1820:
		foreground.scroll_offset.x = 0
	if player and is_instance_valid(player):
		player_coordinates.emit(player.global_position)
		player_pos = player.global_position
		

# when bullet is shot, adds a bullet to the scene going right
func _on_player_bullet_shot(bullet_scene, location):
	var bullet = bullet_scene.instantiate()
	bullet.global_position = location
	bullet_container.add_child(bullet)
	sound_bullet.play()

# Spawns an enemy
func _on_enemy_spawn_timer_timeout() -> void:
	#Picks enemy from scene list at random
	var enemy_spawn_gd = enemy_scene_gd.pick_random().instantiate()
	# Positions enemy at start of screen at random y-coordinate
	enemy_spawn_gd.global_position = Vector2(1860, randf_range(30, 780))
	enemy_spawn_gd.hit_gd.connect(_on_enemy_hit)
	enemy_spawn_gd.killed_gd.connect(_on_enemy_killed)
	# Adds enemy to scene
	enemy_container.add_child(enemy_spawn_gd)

func _on_enemy_hit():
	sound_hit.play()

func _on_enemy_killed(points):
	score += points
	sound_killed.play()
	
func _on_player_killed():
	scorehud.visible = false
	gameoverhud.set_score(score)
	await get_tree().create_timer(.5).timeout
	gameoverhud.visible = true
	

	
	
	
