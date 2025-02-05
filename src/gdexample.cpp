#include "gdexample.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void GDExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_amplitude"), &GDExample::get_amplitude);
	ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &GDExample::set_amplitude);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");

    ClassDB::bind_method(D_METHOD("get_speed"), &GDExample::get_speed);
	ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &GDExample::set_speed);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");

    ClassDB::bind_method(D_METHOD("get_hp"), &GDExample::get_hp);
	ClassDB::bind_method(D_METHOD("set_hp", "p_hp"), &GDExample::set_hp);
    	
	ADD_PROPERTY(PropertyInfo(Variant::INT, "hp", PROPERTY_HINT_RANGE, "0,6,1"), "set_hp", "get_hp");

        ClassDB::bind_method(D_METHOD("get_points"), &GDExample::get_points);
	ClassDB::bind_method(D_METHOD("set_points", "p_points"), &GDExample::set_points);
   
	ADD_PROPERTY(PropertyInfo(Variant::INT, "points", PROPERTY_HINT_RANGE, "100,1000,100"), "set_points", "get_points");
}

GDExample::GDExample() {
	// Initialized variables
	time_passed = 0.0;
    amplitude = 20.0;
    speed = 600;
    hp = 2;
    points = 300;
}

GDExample::~GDExample() {
}


void GDExample::_process(double delta) {
	time_passed += delta;

    // makes position vector oscillate in a curve over time
	// Vector2 new_position = Vector2(
	// 	amplitude + (amplitude * sin(time_passed * 2.0)) + 1700,
	// 	amplitude + (amplitude * cos(time_passed * 1.5)) + 500
	// );

	// set_position(new_position);
}

//function to move position left at a constant given speed, made to call within the script
Vector2 GDExample::move_left(const Vector2 p_position) {
    Vector2 new_position_left = p_position;
    new_position_left.x -= speed * time_passed;

    set_position(new_position_left);
	return new_position_left;
}

//function to oscillate position at given amplitude, made to call within the script
Vector2 GDExample::oscillate(const Vector2 p_position) {
    Vector2 new_position = Vector2(
		amplitude + (amplitude * sin(time_passed * 2.0)),
		amplitude + (amplitude * cos(time_passed * 1.5))
	);
    new_position.x -= speed * time_passed;
    set_position(new_position);
	return new_position;
}

void GDExample::set_amplitude(const double p_amplitude) {
	amplitude = p_amplitude;
}

double GDExample::get_amplitude() const {
	return amplitude;
}

void GDExample::set_speed(const double p_speed) {
	speed = p_speed;
}

double GDExample::get_speed() const {
	return speed;
}

void GDExample::set_hp(const int p_hp) {
	hp = p_hp;
}

int GDExample::get_hp() const {
	return hp;
}


void GDExample::set_points(const int p_points) {
	points = p_points;
}

int GDExample::get_points() const {
	return points;
}

