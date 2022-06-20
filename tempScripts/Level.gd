extends Node2D


var isDragging : bool = false;
var selected : Array = [];
var startDragging : Vector2 = Vector2.ZERO;
var selectRectangle = RectangleShape2D.new()


# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass

func _unhandled_input(event):

	if event is InputEventMouseButton and event.button_index == BUTTON_LEFT:
		if event.pressed:

			for unit in selected:
				unit.collider.setSelected(false);
			selected = [];
			isDragging = true;
			startDragging = event.position;
			print("start");

		elif isDragging:

			isDragging = false;
			var endDragging = event.position
			selectRectangle.extents = (endDragging - startDragging) / 2;
			var space = get_world_2d().direct_space_state;
			var query = Physics2DShapeQueryParameters.new();

			query.set_shape(selectRectangle);
			query.transform = Transform2D(0, (endDragging + startDragging) / 2);
			selected = space.intersect_shape(query);
			print("end");
			print(selected);
			for unit in selected:
				unit.collider.setSelected(true);

