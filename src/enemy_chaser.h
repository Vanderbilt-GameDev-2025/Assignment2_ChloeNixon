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
    //calculated distance between enemy and player
    float distance;
    //player node
    Node2D* player = nullptr;
    //current state enemy is in
    State* current_state = nullptr;
    //state machine that manages enemies states
    StateMachine* state_machine;
    //the distance from the player where the enemy will change states
    float detection_radius;
    //starting position of enemy
    Dictionary starting_pos;
    //calculated coordinates of the player
    Vector2 player_pos;
    //calculated coordinates of the player
    Vector2 enemy_pos;

protected:
	static void _bind_methods();

public:
	EnemyChaser();
	~EnemyChaser();
	void _ready() override;
	void _process(double delta) override;
    void _process_ai();
	void set_speed(const double p_speed);
	double get_speed() const;
};

}

#endif