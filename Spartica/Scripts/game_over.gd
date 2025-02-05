# Processes game over HUD
extends Control

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass 

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass

func _on_reset_button_pressed() -> void:
	get_tree().reload_current_scene()
	
# Displays player's final score
func set_score(value):
	$final_score.text = "Score: " + str(value)
	
