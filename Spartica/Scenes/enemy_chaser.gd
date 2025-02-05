#passes area signals to parent node, so that they can be reached within the main script
extends EnemyChaser

signal hit_gd
signal killed_gd(points)

func _on_area_hit_gd() -> void:
	hit_gd.emit()


func _on_area_killed_gd(points: Variant) -> void:
	killed_gd.emit(points)


func _on_killed_gd(points: Variant) -> void:
	queue_free()
