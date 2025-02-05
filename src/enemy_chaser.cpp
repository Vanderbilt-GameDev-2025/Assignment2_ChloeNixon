#include "enemy_chaser.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/timer.hpp>
#include <cmath>

using namespace godot;

void EnemyChaser::_bind_methods() {

    ClassDB::bind_method(D_METHOD("get_speed"), &EnemyChaser::get_speed);
	ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &EnemyChaser::set_speed);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");

	ClassDB::bind_method(D_METHOD("get_amplitude"), &EnemyChaser::get_amplitude);
	ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &EnemyChaser::set_amplitude);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");

    ClassDB::bind_method(D_METHOD("get_hp"), &EnemyChaser::get_hp);
	ClassDB::bind_method(D_METHOD("set_hp", "p_hp"), &EnemyChaser::set_hp);
    	
	ADD_PROPERTY(PropertyInfo(Variant::INT, "hp", PROPERTY_HINT_RANGE, "0,6,1"), "set_hp", "get_hp");

    ClassDB::bind_method(D_METHOD("get_points"), &EnemyChaser::get_points);
	ClassDB::bind_method(D_METHOD("set_points", "p_points"), &EnemyChaser::set_points);
   
	ADD_PROPERTY(PropertyInfo(Variant::INT, "points", PROPERTY_HINT_RANGE, "100,1000,100"), "set_points", "get_points");
}

EnemyChaser::EnemyChaser() {
	// Initialized variables
	time_passed = 0.0;
	amplitude = 10.0;
    speed = 600;
    hp = 2;
    points = 300;
	starting_pos["x"] = 1700;
    starting_pos["y"] = 500;
	enemy_pos = Vector2(starting_pos["x"], starting_pos["y"]);
	distance = 1500;

//state machine manages state
	state_machine  = memnew(StateMachine);
	state_machine->change_state("Idle");
	current_state = state_machine->get_state();

	// StateIdle* idle_state = memnew(StateIdle);
    // states["Idle"] = idle_state; 
	// StateChasing* chasing_state = memnew(StateChasing);
    // states["Chasing"] = chasing_state; 

	// current_state = Object::cast_to<State>(states["Idle"].operator Object*());
}

EnemyChaser::~EnemyChaser() {
}

void EnemyChaser::_ready() {
    Node* parent_node = get_parent();
    String x = "Node is: " + parent_node->get_name();
    UtilityFunctions::print(x);
}

void EnemyChaser::_process(double delta) {
	time_passed += delta;

	// updates enemy position based on current state
	Vector2 new_position;
	if (current_state) {
		new_position = current_state->update(time_passed);
		new_position = new_position + enemy_pos;
		set_position(new_position);
	}
	distance = enemy_pos.distance_to(player_pos);
	if (distance < 500.0 && current_state == state_machine->states["Idle"]) {
		current_state = state_machine->change_state("Chasing");
		state_machine->change_state("Chasing");
	};
	enemy_pos = new_position;
	Node *parent_node = get_parent();
	player_pos = parent_node->get("player_pos");
	if (current_state == state_machine->states["Chasing"]) {
		set_position(current_state->seekplayer(player_pos, enemy_pos));
		enemy_pos = get_position();
	};

	if (current_state == state_machine->states["Chasing"]) {
		UtilityFunctions::print("state set to chasing");
	} else if (current_state == state_machine->states["Idle"]) {
		UtilityFunctions::print("state set to idle");
	} else {
		UtilityFunctions::print("womp womp");
	};
}

// void EnemyChaser::_process_ai() { 
// 	float distance = enemy_pos.distance_to(player_pos);
// 	UtilityFunctions::print(distance);
// 	if (distance < 100.0f) {
//         return;
//     };
// }


//function to move position left at a constant given speed, made to call within the script
Vector2 EnemyChaser::move_left(const Vector2 p_position) {
    Vector2 new_position_left = p_position;
    new_position_left.x -= speed * time_passed;

    set_position(new_position_left);
	return new_position_left;
}

//function to oscillate position at given amplitude, made to call within the script
Vector2 EnemyChaser::oscillate(const Vector2 p_position) {
	return p_position;
}

void EnemyChaser::set_speed(const double p_speed) {
	speed = p_speed;
}

double EnemyChaser::get_speed() const {
	return speed;
}

void EnemyChaser::set_hp(const int p_hp) {
	hp = p_hp;
}

int EnemyChaser::get_hp() const {
	return hp;
}


void EnemyChaser::set_points(const int p_points) {
	points = p_points;
}

int EnemyChaser::get_points() const {
	return points;
}

void EnemyChaser::set_amplitude(const double p_amplitude) {
	amplitude = p_amplitude;
}

double EnemyChaser::get_amplitude() const {
	return amplitude;
}

