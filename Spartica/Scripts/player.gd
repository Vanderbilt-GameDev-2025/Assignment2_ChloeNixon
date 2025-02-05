class_name Player extends CharacterBody2D

# coordinates where bullets are shot from
@onready var shooter = $shooter
@export var speed = 500
# time between bullet rounds
var bullet_cooldown = .2
var can_shoot := true
var bullet_scene = preload("res://Scenes/bullet.tscn")
var frame_counter := 0
var frame_buffer := 5

signal player_position(coordinates)
signal player_killed
signal bullet_shot(bullet_scene, location)

func _process(delta: float) -> void:
	if Input.is_action_pressed("shoot"):
		if can_shoot:
			# fires bullet, prevents firing for duration of bullet cooldown
			shoot()
			can_shoot = false
			await get_tree().create_timer(bullet_cooldown).timeout
			can_shoot = true
	player_position.emit(global_position)

func _physics_process(delta: float) -> void:
	#moves player direction based on input key coordinates
	var direction = Vector2(
		Input.get_axis("moveLeft", "moveRight"),
		Input.get_axis("moveUp", "moveDown")
		)
		
	velocity = direction * speed
	#if player is not going backwards, rotates towards where player is moving
	if not Input.is_action_pressed("moveLeft"):
		rotation = clamp(lerp_angle(rotation,velocity.angle(),0.05), -.6, .6)
	move_and_slide()
	
	#prevents player from leaving screen
	global_position = global_position.clamp(
		Vector2.ZERO, 
		get_viewport_rect().size
	)
	
func shoot():
	bullet_shot.emit(bullet_scene, shooter.global_position)
	
func die():
	player_killed.emit()
	queue_free()
