#include "playerShoot.hpp"

#include <godot_cpp/classes/input.hpp>



void PlayerShoot::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_gun", "gun"), &PlayerShoot::set_gun);
    godot::ClassDB::bind_method(godot::D_METHOD("get_gun"), &PlayerShoot::get_gun);
    
    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::OBJECT, "gun", godot::PROPERTY_HINT_NODE_TYPE, "Node2D"), "set_gun", "get_gun");
}


void PlayerShoot::_process(double delta) {
    godot::Input* input = godot::Input::get_singleton();

    if(input->is_action_just_pressed("fire")) {
        if(gun == nullptr) return;
        
        gun->fire();
    }
}

void PlayerShoot::set_gun(Gun* gun) {
    this->gun = gun;
}

Gun *PlayerShoot::get_gun() const {
    return this->gun;
}