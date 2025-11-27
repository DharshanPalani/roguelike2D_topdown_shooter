#include <gun.hpp>

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/tree.hpp>

#include <bullet.hpp>

void Gun::_bind_methods() {

    godot::ClassDB::bind_method(godot::D_METHOD("set_firePoint", "firePoint"), &Gun::set_firePoint);
    godot::ClassDB::bind_method(godot::D_METHOD("get_firePoint"), &Gun::get_firePoint);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::OBJECT, "firePoint", godot::PROPERTY_HINT_NODE_TYPE, "Node2D"), "set_firePoint", "get_firePoint");

    godot::ClassDB::bind_method(godot::D_METHOD("set_bulletContainer", "bulletContainer"), &Gun::set_bulletContainer);
    godot::ClassDB::bind_method(godot::D_METHOD("get_bulletContainer"), &Gun::get_bulletContainer);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::OBJECT, "bulletContainer", godot::PROPERTY_HINT_NODE_TYPE, "Node2D"), "set_bulletContainer", "get_bulletContainer");

}

Gun::Gun() {
    range = 20;
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

godot::Node2D* Gun::get_firePoint() const {
    return this->firePoint;
}

void Gun::set_firePoint(godot::Node2D* firePoint) {
    this->firePoint = firePoint;
}

godot::Node2D* Gun::get_bulletContainer() const {
    return this->bulletContainer;
}

void Gun::set_bulletContainer(godot::Node2D* bulletContainer) {
    this->bulletContainer = bulletContainer;
}

void Gun::fire() {

    if(firePoint == nullptr) return;

    Bullet* newBullet = memnew(Bullet);
    newBullet->set_rotation(firePoint->get_global_rotation());
    newBullet->set_position(firePoint->get_global_position());
    bulletContainer->add_child(newBullet);
}