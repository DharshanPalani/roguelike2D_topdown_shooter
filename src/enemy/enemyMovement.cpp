#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/classes/object.hpp>


#include "enemyMovement.hpp"

void EnemyMovement::_bind_methods() {

    godot::ClassDB::bind_method(godot::D_METHOD("set_entity", "entity"), &EnemyMovement::set_entity);
    godot::ClassDB::bind_method(godot::D_METHOD("get_entity"), &EnemyMovement::get_entity);
    
    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::OBJECT, "entity", godot::PROPERTY_HINT_NODE_TYPE, "Node2D"), "set_entity", "get_entity");

    godot::ClassDB::bind_method(godot::D_METHOD("set_speed", "speed"), &EnemyMovement::set_speed);
    godot::ClassDB::bind_method(godot::D_METHOD("get_speed"), &EnemyMovement::get_speed);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::INT, "speed"), "set_speed", "get_speed");
}


Entity* EnemyMovement::find_target() {
    godot::SceneTree *tree = get_tree();
    if (!tree) return nullptr;

    godot::Array targets = tree->get_nodes_in_group("player");
    if (targets.size() == 0) return nullptr;

    return godot::Object::cast_to<Entity>(targets[0]);
}


void EnemyMovement::_process() {

    if(target == nullptr || !target) return;
    
    godot::Vector2 entity_pos = entity->get_position();
    godot::Vector2 target_pos = target->get_position();

    godot::Vector2 direction = target_pos - entity_pos;

    if(direction.length() > 0.1) {
        direction = direction.normalized();

        entity->set_position(entity_pos + direction * speed);
    }
}


void EnemyMovement::_ready() {
    target = find_target();
    if(target != nullptr) {
        godot::print_line("There is a target to follow.");
    } else {
        godot::print_line("There isn't a target to follow.");
    }
}

int EnemyMovement::get_speed() const {
    return this->speed;
}

void EnemyMovement::set_speed(int speed) {
    this->speed = speed;
}

Entity *EnemyMovement::get_entity() const {
    return entity;
}

void EnemyMovement::set_entity(Entity* entity) {
    this->entity = entity;
}