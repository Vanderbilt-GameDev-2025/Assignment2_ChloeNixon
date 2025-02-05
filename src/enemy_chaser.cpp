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
	detection_radius = 700;
	starting_pos["x"] = 1700;
    starting_pos["y"] = 500;
	enemy_pos = Vector2(starting_pos["x"], starting_pos["y"]);
	distance = 1500;

	//state machine manages state
	state_machine  = memnew(StateMachine);
	state_machine->change_state("Idle");
	current_state = state_machine->get_state();
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
	//if the distance between enemy & player is within detection, changes the state to "Chasing"
	if (distance < detection_radius && current_state == state_machine->states["Idle"]) {
		current_state = state_machine->change_state("Chasing");
		state_machine->change_state("Chasing");
	};
	enemy_pos = new_position;

	//Finds player coords relative to enemy, and moves enemy towards player in a chasing state
	Node *parent_node = get_parent();
	player_pos = parent_node->get("player_pos");
	if (current_state == state_machine->states["Chasing"]) {
		set_position(current_state->seekplayer(player_pos, enemy_pos));
		enemy_pos = get_position();
	};
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

