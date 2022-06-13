#include <Godot.hpp>
#include <Node2D.hpp>

class Unit : public godot::Node2D {
    GODOT_CLASS(Unit, godot::Node2D);


public:

    static void _register_methods();
    void _init(); 
};

