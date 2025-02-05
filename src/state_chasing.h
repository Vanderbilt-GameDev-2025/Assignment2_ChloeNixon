#ifndef STATECHASING_H
#define STATECHASING_H

#include "state.h"
#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {
//Class defining the 'chasing' state, where the enemy is supposed to move faster and towards the player.

class StateChasing : public State {
	GDCLASS(StateChasing, State)

private:
    

protected:
	static void _bind_methods();

public:
    StateChasing();
    ~StateChasing();
    void _ready() override;
    void enter() override;
    void exit() override;
    Vector2 update(double time_passed) override;
    Vector2 seekplayer(Vector2 player_pos, Vector2 current_pos) override;
};

}

#endif