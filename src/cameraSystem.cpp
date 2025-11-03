#include "cameraSystem.hpp"

#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/class_db.hpp>


void CameraSystem::_bind_methods() {
    
    // the below 2 are binding for set_target and get_target, set_target receives a target to set in the private variable
    // get_target just returns the target node stored in the private, only reference ong.

    godot::ClassDB::bind_method(godot::D_METHOD("set_target", "target"), &CameraSystem::set_target);
    godot::ClassDB::bind_method(godot::D_METHOD("get_target"), &CameraSystem::get_target);

    // This adds a property field in the editor allowing drag and drop in the editor, it uses the previous 2 binding methods. 
    // set_target and get_target

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::OBJECT, "target", godot::PROPERTY_HINT_NODE_TYPE, "Node2D"), "set_target", "get_target");

    // Same bs as seen in the previous shi for the target bs.

    godot::ClassDB::bind_method(godot::D_METHOD("set_smooth_factor", "smooth_factor"), &CameraSystem::set_smooth_factor);
    godot::ClassDB::bind_method(godot::D_METHOD("get_smooth_factor"), &CameraSystem::get_smooth_factor);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::FLOAT, "smooth_factor"), "set_smooth_factor", "get_smooth_factor");

}

CameraSystem::CameraSystem() {
    smooth_factor = 10.0f;
    set_process(true);
}

void CameraSystem::_process(double delta) {
    // calls follow_target every frame or second idk.
    follow_target(delta);
}

// receives the pointer of the target and sets it in the private. Having reference of that target not as whole. Don't forget.
void CameraSystem::set_target(Node2D* target) {
    this->target = target;
}

// Returns the reference of the target, only reference not the whole bs.
godot::Node2D *CameraSystem::get_target() const {
    return target;
}
// Receives a floating value and sets it in the smooth_factor private variable.
void CameraSystem::set_smooth_factor(float smooth_factor) {
    this->smooth_factor = smooth_factor;
}

// Returns smooth_factor float value.
float CameraSystem::get_smooth_factor() const {
    return smooth_factor;
}
// function to make the camera follow the target. Receives delta as reference from the _process function.
void CameraSystem::follow_target(const double &delta) {
    // Checks if the target is null or nah, if null and runs the following shit it breaks the editor.
    if(target != nullptr) {
        // some formula bs to calculate new position for that smooth camera movement and sets it in the next line.
        godot::Vector2 newPosition = get_position() + (target->get_position() - get_position()) * (smooth_factor * delta);
        set_position(newPosition);
    }
}