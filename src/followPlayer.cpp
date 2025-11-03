#include "followPlayer.h"

#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/class_db.hpp>


void FollowPlayer::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_target", "target"), &FollowPlayer::set_target);
    godot::ClassDB::bind_method(godot::D_METHOD("get_target"), &FollowPlayer::get_target);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::OBJECT, "target", godot::PROPERTY_HINT_NODE_TYPE, "Node2D"), "set_target", "get_target");

    godot::ClassDB::bind_method(godot::D_METHOD("set_smooth_factor", "smooth_factor"), &FollowPlayer::set_smooth_factor);
    godot::ClassDB::bind_method(godot::D_METHOD("get_smooth_factor"), &FollowPlayer::get_smooth_factor);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::FLOAT, "smooth_factor"), "set_smooth_factor", "get_smooth_factor");

}

FollowPlayer::FollowPlayer() {
    smooth_factor = 10.0f;
    set_process(true);
}

void FollowPlayer::_process(double delta) {

    if(target != nullptr) {
        godot::Vector2 newPosition = get_position() + (target->get_position() - get_position()) * (smooth_factor * delta);
        set_position(newPosition);
    }
}

void FollowPlayer::set_target(Node2D* target) {
    this->target = target;
}

godot::Node2D *FollowPlayer::get_target() const {
    return target;
}

void FollowPlayer::set_smooth_factor(float smooth_factor) {
    this->smooth_factor = smooth_factor;
}

float FollowPlayer::get_smooth_factor() const {
    return smooth_factor;
}