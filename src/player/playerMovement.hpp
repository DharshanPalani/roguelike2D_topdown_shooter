#ifndef playerMovement_hpp
#define playerMovement_hpp

#include <godot_cpp/classes/node2d.hpp>
#include "../entity/entity.hpp"

class PlayerMovement : public godot::Node2D {
    GDCLASS(PlayerMovement, godot::Node2D);

    private:
        int speed;
        Entity* entity = nullptr;
    
    protected:
        static void _bind_methods();

    public:

        PlayerMovement();

        void _process(double delta) override;
        
        Entity *get_entity() const;
        void set_entity(Entity* entity);

        int get_speed() const;
        void set_speed(int speed);

};


#endif