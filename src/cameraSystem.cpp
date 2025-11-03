#include "cameraSystem.hpp"

#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/class_db.hpp>


void CameraSystem::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_target", "target"), &CameraSystem::set_target);
    godot::ClassDB::bind_method(godot::D_METHOD("get_target"), &CameraSystem::get_target);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::OBJECT, "target", godot::PROPERTY_HINT_NODE_TYPE, "Node2D"), "set_target", "get_target");

    godot::ClassDB::bind_method(godot::D_METHOD("set_smooth_factor", "smooth_factor"), &CameraSystem::set_smooth_factor);
    godot::ClassDB::bind_method(godot::D_METHOD("get_smooth_factor"), &CameraSystem::get_smooth_factor);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::FLOAT, "smooth_factor"), "set_smooth_factor", "get_smooth_factor");

}

CameraSystem::CameraSystem() {
    smooth_factor = 10.0f;
    set_process(true);
}

void CameraSystem::_process(double delta) {
    follow_target(delta);
}

void CameraSystem::set_target(Node2D* target) {
    this->target = target;
}

godot::Node2D *CameraSystem::get_target() const {
    return target;
}

void CameraSystem::set_smooth_factor(float smooth_factor) {
    this->smooth_factor = smooth_factor;
}

float CameraSystem::get_smooth_factor() const {
    return smooth_factor;
}

void CameraSystem::follow_target(const double &delta) {
    if(target != nullptr) {
        godot::Vector2 newPosition = get_position() + (target->get_position() - get_position()) * (smooth_factor * delta);
        set_position(newPosition);
    }
}