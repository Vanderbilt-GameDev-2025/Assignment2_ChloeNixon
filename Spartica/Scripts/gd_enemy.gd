#passes area signals to parent node, so that they can be reached within the main script

extends GDExample
signal hit_gd
signal killed_gd(points)

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass 

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass

func _on_enemy_area_hit_gd() -> void:
	hit_gd.emit()

func _on_enemy_area_killed_gd(points: Variant) -> void:
	killed_gd.emit(points)
