#include <Area2D.hpp>
#include <Input.hpp>
#include <CollisionShape2D.hpp>
#include <AnimatedSprite.hpp>
#include <Godot.hpp>

class Unit : public godot::Area2D {

    GODOT_CLASS(Unit, godot::Area2D);
    int speed = 400;

    godot::AnimatedSprite *animatedSprite;
    godot::CollisionShape2D *collisionShape;
    godot::Input *userInput;
    godot::Vector2 screenSize;

    bool isSelected = false;

public:

    static void _register_methods();
    void _init(); 
    void _ready();
    void _process(const double p_delta);
    void start(const godot::Vector2 p_position);
    void _on_Player_body_entered(godot::Node2D *body);
};
