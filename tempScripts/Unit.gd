extends KinematicBody2D



var selected : bool = false;

func setSelected(arg : bool):
	selected = arg;
	$selectedBox.visible = arg;
