// This code goes in `player.cpp`.
#include "unit.hpp"

void Unit::_ready()
{
    _animated_sprite = get_node<godot::AnimatedSprite>("AnimatedSprite");
    _collision_shape = get_node<godot::CollisionShape2D>("CollisionShape2D");
    _input = godot::Input::get_singleton();
    _screen_size = get_viewport_rect().size;
}

void Unit::_process(const double p_delta)
{
    godot::Vector2 velocity(0, 0);

    velocity.x = _input->get_action_strength("move_right") - _input->get_action_strength("move_left");
    velocity.y = _input->get_action_strength("move_down") - _input->get_action_strength("move_up");

    if (velocity.length() > 0) {
        velocity = velocity.normalized() * speed;
        _animated_sprite->play();
    } else {
        _animated_sprite->stop();
    }
}

void Unit::_register_methods() 
{
    godot::register_method("_ready", &Unit::_ready);
    godot::register_method("_process", &Unit::_process);
    godot::register_method("start", &Unit::start);
    godot::register_method("_on_Unit_body_entered", &Unit::_on_Unit);
    godot::register_property("speed", &Unit::speed, (real_t)400.0);
    // This below line is the signal.
    godot::register_signal<Unit>("hit", godot::Dictionary());
}
void Unit::start(const godot::Vector2 p_position)
{
    set_position(p_position);
    show();
    _collision_shape->set_disabled(false);
}


