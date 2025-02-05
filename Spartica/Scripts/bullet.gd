#processes player's bullet movement & interactions
extends Area2D

#bullet speed and deacceleration
var bullet_speed = 2500
var deacceleration = 8
#player rotation
var 	direction = Vector2(cos(rotation), sin(rotation)).normalized() 

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass


# Called every frame. 'delta' is the elapsed time since the previous frame.
# Processes bullet movement
func _process(delta: float) -> void:
	bullet_speed = max(bullet_speed - deacceleration, 400)
	direction = Vector2(cos(rotation), sin(rotation)).normalized()
	global_position += direction * bullet_speed * delta

# When bullet notifier exits screen, deletes object
func _on_visible_on_screen_notifier_2d_screen_exited():
	queue_free()

# When bullet enters enemy's 2d area, damages enemy & deletes bullet
func _on_area_entered(area: Area2D) -> void:
	area.damage()
	queue_free()
	
