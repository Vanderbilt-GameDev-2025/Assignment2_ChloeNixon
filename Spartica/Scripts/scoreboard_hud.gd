extends Control

# Displays player score at top of screen
@onready var score = $Panel/ScoreCount:
	set(value):
		score.text = str(value)
	
