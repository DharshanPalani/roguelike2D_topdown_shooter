#include "gun.hpp"

#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/color_rect.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/node.hpp>

#include "bullet.hpp"

void Gun::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_firePoint", "firePoint"), &Gun::set_firePoint);
    godot::ClassDB::bind_method(godot::D_METHOD("get_firePoint"), &Gun::get_firePoint);

    ADD_PROPERTY( godot::PropertyInfo(godot::Variant::OBJECT, "firePoint", godot::PROPERTY_HINT_NODE_TYPE, "Node2D"), "set_firePoint", "get_firePoint" );
}

Gun::Gun() {

}

void Gun::_draw() {
    float gun_length = 20.0f;
    float gun_width = 10.0f;

    godot::Vector2 start(0, 0);
    godot::Rect2 rect(start, godot::Vector2(gun_length, gun_width));

    draw_rect(rect, godot::Color(1, 1, 1), true);
}

godot::Node2D *Gun::get_firePoint() const {
    return firePoint;
}

void Gun::set_firePoint(godot::Object *p_firePoint) {
    firePoint = godot::Object::cast_to<godot::Node2D>(p_firePoint);
}

void Gun::fire() {
    if (!firePoint)
        return;

    Bullet *bullet = memnew(Bullet);

    bullet->set_global_position(firePoint->get_global_position());
    bullet->set_global_rotation(firePoint->get_global_rotation());

    godot::SceneTree *tree = get_tree();
    if (!tree)
        return;

    godot::Node *scene = tree->get_current_scene();
    if (!scene)
        return;

    scene->add_child(bullet);
}
