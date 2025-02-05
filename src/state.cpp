#include "state.h"

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

void State::_bind_methods() {
	// ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");
	// ADD_SIGNAL(MethodInfo("position_changed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::VECTOR2, "new_pos")));

    // ClassDB::bind_method(D_METHOD("get_speed"), &State::get_speed);
	// ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &State::set_speed);

	// ClassDB::bind_method(D_METHOD("get_amplitude"), &State::get_amplitude);
	// ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &State::set_amplitude);

}

// State::State(const Callable& p_change_state, Node* p_persistent_state) {
// 	change_state = p_change_state;
//     persistent_state = p_persistent_state;
// }

State::State() {

}

State::~State() {
}

// void State::_ready() {
//     return;

// }

// void State::_process(double delta) {
// 	return;
// }
//updates enemy coordinates based on how the enemy should move in a given state

Vector2 State::update(double time_passed) {
    Vector2 x = Vector2(100, 100);
    return x;
}
//changes enemy movement to move towards the player

Vector2 State::seekplayer(Vector2 player_pos, Vector2 current_pos) {
   Vector2 x = Vector2(100, 100);
   return x;
}

//String previous_state_path, Dictionary data
void State::enter() {
    return;
}

void State::exit() {
    return;
}


//function to move position left at a constant given speed, made to call within the script
void State::move_left(const Vector2 p_position) {
    return;
}

//function to oscillate position at given amplitude, made to call within the script
void State::oscillate(const Vector2 p_position) {
	return;
}


// void State::_physics_process(double delta) {
//     if (persistent_state) {
//         CharacterBody2D* body = Object::cast_to<CharacterBody2D>(persistent_state);
//         if (body) {
//             body->move_and_slide();
//         }
//     }
// }

// void State::handle_input(InputEvent _event) {
//     return;
// }

// void godot::State::physics_update(float _delta) {
//     return;
// }


// void State::set_speed(const double p_speed) {
// 	speed = p_speed;
// }

// double State::get_speed() const {
// 	return speed;
// }

// void State::set_amplitude(const double p_amplitude) {
// 	amplitude = p_amplitude;
// }

// double State::get_amplitude() const {
// 	return amplitude;
// }

