#include "unit.hpp"

void Unit::_register_methods()
{
    godot::register_method("_ready", &Unit::_ready);
    godot::register_method("_process", &Unit::_process);

    godot::register_property("speed", &Unit::speed, 400);
    godot::register_property("isSelected", &Unit::isSelected, false);
}

void Unit::_init()
{
}


// Initializes the area 2d and it gives access to its children nodes

void Unit::_ready()
{
    animatedSprite = get_node<godot::AnimatedSprite>("AnimatedSprite");
    collisionShape = get_node<godot::CollisionShape2D>("CollisionShape2D");
    userInput = godot::Input::get_singleton();
    screenSize = get_viewport_rect().size;
}


// is called each frame, check if its clicked

void Unit::_process(const double p_delta) 
{
    
}
