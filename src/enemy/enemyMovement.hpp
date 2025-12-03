#ifndef enemyMovement_hpp
#define enemyMovement_hpp

#include <godot_cpp/classes/node2d.hpp>
#include "../entity/entity.hpp"
class EnemyMovement : public godot::Node2D {

    GDCLASS(EnemyMovement, Node2D);
    private:
        int speed;
        Entity* target = nullptr;
        Entity* entity = nullptr;
    protected:
        static void _bind_methods();
    public:
        void _process();
        void _ready();

        Entity* find_target();

        Entity* get_entity() const;
        void set_entity(Entity* entity);

        int get_speed() const;
        void set_speed(int speed);
        
};


#endif