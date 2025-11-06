#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/character_body2d.hpp>

using namespace godot;

struct PlayerSpriteData
{	
	Vector2 spriteCenter;
	float spriteRadius;
	Color spriteColor;
};

class Player : public CharacterBody2D {
	GDCLASS(Player, CharacterBody2D)

private:
	double health;
    double speed;

	PlayerSpriteData playerSpriteData;	

protected:
	static void _bind_methods();

public:
	Player();
	~Player();

	void _process(double delta) override;

	void _draw();

	double get_health() const;
	double get_speed() const;

	void set_player_sprite_data(PlayerSpriteData data);

	PlayerSpriteData get_player_sprite_data() const;

	void set_speed(float speed);
};

#endif