# behavior of all enemies (currently not in use)
class_name Enemy extends Area2D

signal killed(points)
signal hit

@export var speed = 400
@export var hp = 1
@export var points = 100

@onready var sprite = $enemy_area/Sprite2D
@onready var sound_hit = $SFX/enemy_hit


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass 

# Called every frame. 'delta' is the elapsed time since the previous frame.
# Enemy moves left at a constant rate of the speed
func _process(delta: float) -> void:
	global_position.x -= speed * delta
	
# Deletes enemy when notifier exits the screen
func _on_visible_on_screen_notifier_2d_screen_exited():
	queue_free()

# When area is entered by another object, deletes both enemy and player
func _on_body_entered(body: Node2D) -> void:
	if body is Player:
		body.die()
		die()

# Decrements HP, kills enemy at 0
func damage():
	hp -= 1
	if hp <= 0:
		die()
	else:
		sprite.texture = load("res://assets/enemy_blue_damaged.png")
		hit.emit()

# Signals enemy death to main scene, deletes enemy
func die():
	killed.emit(points)
	queue_free()
