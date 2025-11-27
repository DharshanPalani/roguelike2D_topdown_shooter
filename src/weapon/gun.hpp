#pragma once

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/object.hpp>

class Gun : public godot::Node2D {
    GDCLASS(Gun, godot::Node2D)

private:
    godot::Node2D *firePoint = nullptr;

protected:
    static void _bind_methods();

public:
    Gun();
    ~Gun() override = default;

    void _draw() override;

    godot::Node2D *get_firePoint() const;
    void set_firePoint(godot::Object *p_firePoint);

    void fire();
};
