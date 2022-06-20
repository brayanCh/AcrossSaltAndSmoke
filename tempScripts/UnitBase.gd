extends Area2D

signal selectionToggled(selection);

export var exclusive = true;
export var selection_action = "leftClick";


var selected = false;


func setSelected(selection):
	if selection:
		_makeExclusive();
	selected = selection;
	emit_signal("sectionToggled", selected)

func _makeExclusive():
	if not selected:
		return;
	get_tree().call_group("selected", "setSelected", false);

func _input_event(viewport, event, shape_idx):
	if event.is_action_pressed(selection_action):
		setSelected(not selected);
