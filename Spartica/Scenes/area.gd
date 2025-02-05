# behavior of all enemies
extends Area2D

# signals for if enemy is kills and hit
var time = 0.0
signal killed_gd()
signal hit_gd

@onready var cpp_node = $".."


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
# Enemy moves left at a constant rate of the speed
func _process(delta: float) -> void:
	time += delta
	#global_position.y += cpp_node.amplitude + (cpp_node.amplitude * cos(delta * 1.5))
	
# Deletes enemy when notifier exits the screen
func _on_visible_on_screen_notifier_2d_screen_exited():
	queue_free()

# If player enters body, kills both objects
func _on_body_entered(body: Node2D) -> void:
	if body is Player:
		body.die()
		die()
		
# Decrements HP, kills enemy at 0
func damage():
	cpp_node.hp -= 1
	if cpp_node.hp <= 0:
		die()
	else:
		hit_gd.emit()

# Signals enemy death to main scene, deletes enemy
func die():
	killed_gd.emit()
	queue_free()
