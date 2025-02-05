#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "state_idle.h"
#include "state_chasing.h"
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <map>

namespace godot {

//Class that manages the enemy state seperate from the main node class.
class StateMachine : public Node {
    GDCLASS(StateMachine, Node)

private:
    State* current_state;

protected:
    static void _bind_methods();

public:
    //all enemy states 
    Dictionary states;

    StateMachine();
    ~StateMachine();
    //changes state to the given string, then returns the new current state
    State* change_state(const String &new_state);
    //gets current state
    State* get_state();
};

}

#endif
