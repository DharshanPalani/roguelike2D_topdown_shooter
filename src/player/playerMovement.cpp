#include "playerMovement.hpp"

#include <godot_cpp/classes/input.hpp>


PlayerMovement::PlayerMovement() {

}

void PlayerMovement::_process(double delta) {
    godot::Vector2 velocity;

    godot::Input *input = godot::Input::get_singleton();

    if (input->is_action_pressed("ui_right")) velocity.x += 1;
    if (input->is_action_pressed("ui_left"))  velocity.x -= 1;
    if (input->is_action_pressed("ui_down"))  velocity.y += 1;
    if (input->is_action_pressed("ui_up"))    velocity.y -= 1;

    if (velocity.length() > 0) {
        velocity = velocity.normalized() * 100 * delta;
        
        if(entity != nullptr) {
            entity->set_position(entity->get_position() + velocity);
        }
    }
}

void PlayerMovement::_bind_methods() {

    godot::ClassDB::bind_method(godot::D_METHOD("set_entity", "entity"), &PlayerMovement::set_entity);
    godot::ClassDB::bind_method(godot::D_METHOD("get_entity"), &PlayerMovement::get_entity);
    
    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::OBJECT, "entity", godot::PROPERTY_HINT_NODE_TYPE, "Node2D"), "set_entity", "get_entity");
}

Entity *PlayerMovement::get_entity() const {
    return entity;
}

void PlayerMovement::set_entity(Entity* entity) {
    this->entity = entity;
}