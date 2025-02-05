#ifndef STATEIDLE_H
#define STATEIDLE_H

#include "state.h"
#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {
//Class defining the 'idle' state, where the enemy is moving slowly left.
class StateIdle : public State {
	GDCLASS(StateIdle, State)

private:

protected:
	static void _bind_methods();

public:
    StateIdle();
    ~StateIdle();
    void _ready() override;
    void enter() override;
    Vector2 update(double time_passed) override;
    void exit() override;
};

}

#endif