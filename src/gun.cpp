#include <gun.hpp>

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/sprite2d.hpp>

void Gun::_bind_methods() {
}

Gun::Gun() {
    range = 20;
}

void Gun::_process(double delta) {

    godot::Input* input = godot::Input::get_singleton();

    if(input->is_action_just_pressed("fire")) {
        Node2D* node = memnew(Node2D);
        add_child(node);
    }

}

void Gun::_draw() {
    float gun_length = 20.0f;
    float gun_width = 10.0f;

    godot::Vector2 start = godot::Vector2(0, 0);
    godot::Rect2 gun_rect(start, godot::Vector2(gun_length, gun_width));

    draw_rect(gun_rect, godot::Color(1,1,1), true);
}

double Gun::get_range() const {
    return this->range;
}

void Gun::set_range(double range) {
    this->range = range;
}