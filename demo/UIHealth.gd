extends Node2D

@export var entity: Node

@onready var health_slider: HSlider = $Control/ProgressBar

func _ready():
	entity.health_changed.connect(_on_health_changed)
	health_slider.value = entity.get_health()

func _on_health_changed(current):
	health_slider.value = current
