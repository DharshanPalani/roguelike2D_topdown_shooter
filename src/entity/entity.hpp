#ifndef entity_hpp
#define entity_hpp

#include <godot_cpp/classes/node2d.hpp>

class Entity : public godot::Node2D {
    GDCLASS(Entity, godot::Node2D);

    private:
        int health;
        int maxHealth;

    protected:
        static void _bind_methods();
    
    public:

        Entity();

        int get_health() const;

        void _draw() override;

        void _ready() override;

        void set_health(int health);

        void increment_health(int increment_value);
};


#endif