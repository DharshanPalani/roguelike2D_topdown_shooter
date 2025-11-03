#ifndef FOLLOWPLAYER_H
#define FOLLOWPLAYER_H

#include <godot_cpp/classes/camera2d.hpp>
#include <godot_cpp/classes/node2d.hpp>

class FollowPlayer : public godot::Camera2D {
    GDCLASS(FollowPlayer, Camera2D);

    private:
        Node2D *target = nullptr;

    protected:
        static void _bind_methods();

    public:

        FollowPlayer();

       	void _process(double delta) override;

        void set_target(Node2D* target);
        Node2D* get_target() const;
    
};

#endif