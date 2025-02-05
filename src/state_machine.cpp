#include "state_machine.h"
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void StateMachine::_bind_methods() {
    ClassDB::bind_method(D_METHOD("change_state", "new_state"), &StateMachine::change_state);
}


StateMachine::StateMachine() {
    current_state = nullptr;
    StateIdle* idle_state = memnew(StateIdle);
    states["Idle"] = idle_state; 
	StateChasing* chasing_state = memnew(StateChasing);
    states["Chasing"] = chasing_state; 
    change_state("Idle");
}


StateMachine::~StateMachine() {
    states.clear();
}


State* StateMachine::change_state(const String &new_state) {
    //checks for if parameter is a valid state
    if (states.has(new_state)) {
        if (current_state) {
            current_state->exit();
        }

        //creates pointer for new state
        State *new_state_ptr = Object::cast_to<State>(states[new_state].operator Object*());
        //checks if state successfully initialized
        if (new_state_ptr) {
            UtilityFunctions::print("State change to: " + new_state);
            current_state = new_state_ptr;
        } else {
            UtilityFunctions::print("State cast failed: " + new_state);
        }

    } else {
        UtilityFunctions::print("State not found: " + new_state);
    }
    return current_state;
}


State* StateMachine::get_state() {
    return current_state;
}
