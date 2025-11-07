#ifndef GUN_HPP
#define GUN_HPP

#include <godot_cpp/classes/node2d.hpp>

class Gun : public godot::Node2D {

    GDCLASS(Gun, godot::Node2D);

    private:
        double range;
        godot::Node2D* firePoint = nullptr;

        godot::Node2D* bulletContainer = nullptr;
    
    protected:
        static void _bind_methods();
    
    public:
        Gun();

        void _process(double delta) override;

        void _draw();

        double get_range() const;
        void set_range(double range);

        void set_firePoint(godot::Node2D* firePoint);

        godot::Node2D* get_firePoint() const;

        void set_bulletContainer(godot::Node2D* bulletContainer);

        godot::Node2D* get_bulletContainer() const;

};

#endif