#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/sprite2d.hpp>

using namespace godot;

class Player : public Sprite2D {
	GDCLASS(Player, Sprite2D)

private:
	double health;
    double speed;

protected:
	static void _bind_methods();

public:
	Player();
	~Player();

	void _process(double delta) override;

	double get_health() const;
	double get_speed() const;

	void set_speed(float speed);
};

#endif