# Main scene is loaded on button press or spacebar.
extends Control

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass 

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	if Input.is_action_just_pressed("start"):
		get_tree().change_scene_to_file("res://Scenes/main_game.res")	

func _on_start_button_pressed() -> void:
	get_tree().change_scene_to_file("res://Scenes/main_game.res")
