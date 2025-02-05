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

// void StateMachine::initialize() {
//     states["Idle"] = memnew(StateIdle);
//     states["Chasing"] = memnew(StateChasing);
//     change_state("Idle");
// }

State* StateMachine::change_state(const String &new_state) {
    if (states.has(new_state)) {
        if (current_state) {
            current_state->exit();
        }
        UtilityFunctions::print("chang to: " + new_state);
        // current_state = static_cast<State*>(states[new_state]);
        State *new_state_ptr = Object::cast_to<State>(states[new_state].operator Object*());
        if (new_state_ptr) {
            current_state = new_state_ptr;
        } else {
            UtilityFunctions::print("State cast failed: " + new_state);
        }
        // current_state = Object::cast_to<State>(states[new_state].operator Object*());
        if (current_state == states["Chasing"]) {
            UtilityFunctions::print("TEMP WORK");
        }
        return current_state;
    } else {
        UtilityFunctions::print("State not found: " + new_state);
        return current_state;
    }
}

State* StateMachine::get_state() {
    return current_state;
}
