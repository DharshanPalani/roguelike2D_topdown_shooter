#ifndef bullet_hpp
#define bullet_hpp


#include <godot_cpp/classes/node2d.hpp>

class Bullet : public godot::Node2D {
    GDCLASS(Bullet, godot::Node2D);

    private:
        float speed;
    
    protected:
        static void _bind_methods();

    public:
        Bullet();

        void _process(double delta) override;

        void _draw();

};

#endif