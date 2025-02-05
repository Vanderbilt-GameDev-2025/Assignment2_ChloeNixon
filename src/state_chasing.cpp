#include "state_chasing.h"

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

void StateChasing::_bind_methods() {

}


StateChasing::StateChasing() {
    amplitude = .5;
    speed = 10;
}

StateChasing::~StateChasing() {
}

void StateChasing::_ready() {
}

void StateChasing::enter() {
    return;
}

//oscilates, then moves left based on speed variable.
Vector2 StateChasing::update(double time_passed) {
    amplitude = .5;
    speed = 10;
    // UtilityFunctions::print("CHASING");
    Vector2 new_position = Vector2(
		amplitude + (amplitude * sin(time_passed * 2.0)),
		amplitude + (amplitude * cos(time_passed * 1.5))
	);
    new_position.x -= speed * dampener * time_passed;
	return new_position;
}

//finds direction of player based on enemy, and changes coords to move towards that direction
Vector2 StateChasing::seekplayer(Vector2 player_pos, Vector2 current_pos) {
    Vector2 direction = (player_pos - current_pos).normalized(); 
    return current_pos + direction * 10; 

}

void StateChasing::exit() {
    return;
}