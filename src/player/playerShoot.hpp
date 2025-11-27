#ifndef playerShoot_hpp
#define playerShoot_hpp

#include "../gun.hpp"

#include <godot_cpp/classes/node2d.hpp>

class PlayerShoot : public godot::Node2D {

    GDCLASS(PlayerShoot, Node2D);

    private:
        Gun *gun = nullptr;

    protected:
        static void _bind_methods();

    public:
        
        void set_gun(Gun* gun);
        Gun *get_gun() const;

        void _process(double delta);

};


#endif