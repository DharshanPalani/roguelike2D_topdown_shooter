#ifndef GUN_HPP
#define GUN_HPP

#include <godot_cpp/classes/node2d.hpp>

class Gun : public godot::Node2D {

    GDCLASS(Gun, Node2D);

    private:
        double range;
    
    protected:
        static void _bind_methods();
    
    public:
        Gun();

        void _process(double delta) override;

        void _draw();

        double get_range() const;
        void set_range(double range);

};

#endif