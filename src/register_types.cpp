#include "register_types.h"
#include "cameraSystem.hpp"
#include "bullet.hpp"
#include "entity/entity.hpp"
#include "player/playerMovement.hpp"


#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

#include <gun.hpp>

using namespace godot;

void initialize_types(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
    
    ClassDB::register_class<CameraSystem>();
    ClassDB::register_class<Gun>();
    ClassDB::register_class<Bullet>();
    ClassDB::register_class<Entity>();
    ClassDB::register_class<PlayerMovement>();
}

void uninitialize_types(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C" {
GDExtensionBool GDE_EXPORT gdcpp_library_init(
    GDExtensionInterfaceGetProcAddress p_get_proc_address,
    GDExtensionClassLibraryPtr p_library,
    GDExtensionInitialization *r_initialization) {

    GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

    init_obj.register_initializer(initialize_types);
    init_obj.register_terminator(uninitialize_types);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_obj.init();
}
}
