#include "followPlayer.h"

#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/class_db.hpp>


void FollowPlayer::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_target", "target"), &FollowPlayer::set_target);
    godot::ClassDB::bind_method(godot::D_METHOD("get_target"), &FollowPlayer::get_target);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::OBJECT, "target", godot::PROPERTY_HINT_NODE_TYPE, "Node2D"), "set_target", "get_target");
}

FollowPlayer::FollowPlayer() {

}

void FollowPlayer::_process(double delta) {

    if(target != nullptr) {
        set_position(target->get_position());
    }
}

void FollowPlayer::set_target(Node2D* target) {
    this->target = target;
}

godot::Node2D *FollowPlayer::get_target() const {
    return target;
}