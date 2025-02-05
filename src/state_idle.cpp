#include "state_idle.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/timer.hpp>

using namespace godot;

void StateIdle::_bind_methods() {
	// ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");
}

// StateIdle::StateIdle(const Callable& p_change_state, Node* p_persistent_state) {
// 	change_state = p_change_state;
//     persistent_state = p_persistent_state;
//     amplitude = 10.0;
// }

StateIdle::StateIdle() {
}

StateIdle::~StateIdle() {
}

void StateIdle::_ready() {

}

void StateIdle::enter() {
    return;
}
//updates coordinate to oscillate, and moves left
Vector2 StateIdle::update(double time_passed) {
    amplitude = 1.0;
    speed = 5;
    // UtilityFunctions::print("IDLE");
    Vector2 new_position = Vector2(
		(amplitude * sin(time_passed * 1.0)),
		(amplitude * cos(time_passed * 1.0))
	);

    new_position.x -= speed * dampener * time_passed;
	return new_position;
}

void StateIdle::exit() {
    return;
}


// //function to move position left at a constant given speed, made to call within the script
// void StateIdle::move_left(const Vector2 p_position) {
//     return;
// }

// //function to oscillate position at given amplitude, made to call within the script
// void StateIdle::oscillate(const Vector2 p_position) {

// }