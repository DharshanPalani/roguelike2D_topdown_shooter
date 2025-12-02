#include "entity.hpp"

Entity::Entity() {
    maxHealth = 100;
    health = maxHealth;
}

void Entity::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_health", "health"), &Entity::set_health);
    godot::ClassDB::bind_method(godot::D_METHOD("get_health"), &Entity::get_health);

    godot::ClassDB::bind_method(godot::D_METHOD("increment_health", "increment_value"), &Entity::increment_health);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::FLOAT, "health"), "set_health", "get_health");

    ADD_SIGNAL(godot::MethodInfo("health_changed", godot::PropertyInfo(godot::Variant::FLOAT, "current")));
}

int Entity::get_health() const {
    return health;
}

void Entity::set_health(int health) {
    this->health = health;
}

void Entity::increment_health(int increment_value) {
    this->health += increment_value;
    emit_signal("health_changed", health);
}

void Entity::_draw() {

    draw_circle(godot::Vector2(0,0), 20.0f, godot::Color(0,0,1));
}

void Entity::_ready() {
    emit_signal("health_changed", health);
}