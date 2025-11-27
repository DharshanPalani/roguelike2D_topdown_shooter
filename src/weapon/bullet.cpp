#include "bullet.hpp"

void Bullet::_bind_methods() {

}

Bullet::Bullet() {
    speed = 500;
}

void Bullet::_process(double delta) {
    godot::Vector2 direction = godot::Vector2(-1, 0).rotated(get_global_rotation());
    set_global_position(get_global_position() + direction * delta * speed);
}

void Bullet::_draw() {
    draw_circle(godot::Vector2(0,0), 20, godot::Color(0,0,1));
}