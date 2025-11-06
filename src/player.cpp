#include <player.h>

#include <godot_cpp/classes/input.hpp>

using namespace godot;


void Player::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_speed", "speed"), &Player::set_speed);
    ClassDB::bind_method(D_METHOD("get_speed"), &Player::get_speed);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
}

Player::Player() {
    health = 100;
    speed = 200;

    playerSpriteData.spriteCenter = Vector2(50, 50);
    playerSpriteData.spriteColor = Color(1,1,0);
    playerSpriteData.spriteRadius = 50.0f;
}


void Player::_process(double delta) {
    Vector2 velocity = Vector2();

    Input *input = Input::get_singleton();

    if (input->is_action_pressed("ui_right")) velocity.x += 1;
    if (input->is_action_pressed("ui_left"))  velocity.x -= 1;
    if (input->is_action_pressed("ui_down"))  velocity.y += 1;
    if (input->is_action_pressed("ui_up"))    velocity.y -= 1;

    if (velocity.length() > 0) {
        velocity = velocity.normalized() * speed * delta;
        set_position(get_position() + velocity);
    }
}

Player::~Player() {}

double Player::get_health() const {
    return health;
}

double Player::get_speed() const {
    return speed;
}

void Player::set_speed(float speed) {
    this->speed = speed;
}

void Player::set_player_sprite_data(PlayerSpriteData data) {
    this->playerSpriteData = data;
}

PlayerSpriteData Player::get_player_sprite_data() const {
    return this->playerSpriteData;
}

void Player::_draw() {

    draw_circle(playerSpriteData.spriteCenter, playerSpriteData.spriteRadius, playerSpriteData.spriteColor);
}