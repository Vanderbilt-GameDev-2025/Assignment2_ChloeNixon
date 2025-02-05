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

}

State::State() {

}

State::~State() {
}

//changes teh enemy coordinates based on speed and amplitude to oscilate, move left, and return the new coords
Vector2 State::update(double time_passed) {
    Vector2 x = Vector2(100, 100);
    return x;
}

//changes enemy movement to move towards the player's direction
Vector2 State::seekplayer(Vector2 player_pos, Vector2 current_pos) {
   Vector2 x = Vector2(100, 100);
   return x;
}

void State::enter() {
    return;
}

void State::exit() {
    return;
}

