#ifndef ENEMYCHASER_H
#define ENEMYCHASER_H

#include "state_idle.h"
#include "state_chasing.h"
#include "state_machine.h"
#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class EnemyChaser : public Sprite2D {
	GDCLASS(EnemyChaser, Sprite2D)

private:
    //time passed in-game
	double time_passed;
    //level of amplitude of oscillations
    double amplitude;
    //speed that enemy moves left across the screen
    double speed;
    //amount of times enemy can be hit by bullet
    int hp;
    //amount of points awarded when enemy is killed
    int points;

    float distance;

    Node2D* player = nullptr;

    Dictionary states;
    State* current_state = nullptr;
    State* current_state_real = nullptr;
    StateMachine* state_machine;

    int distance_radius;
    Dictionary starting_pos;
    Vector2 player_pos;
    Vector2 enemy_pos;

protected:
	static void _bind_methods();

public:
	EnemyChaser();
	~EnemyChaser();
	void _ready() override;
	void _process(double delta) override;
    void _process_ai();
    Vector2 move_left(const Vector2 p_position);
    Vector2 oscillate(const Vector2 p_position);
	void set_speed(const double p_speed);
	double get_speed() const;
    void set_hp(const int p_hp);
	int get_hp() const;
    void set_points(const int p_points);
	int get_points() const;
    void set_amplitude(const double p_amplitude);
	double get_amplitude() const;
};

}

#endif