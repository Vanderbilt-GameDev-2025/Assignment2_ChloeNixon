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
    Vector2 player_pos;
    Vector2 enemy_pos;

protected:
    static void _bind_methods();

public:
    StateMachine();
    ~StateMachine();

    //all states 
    Dictionary states;
    void initialize();
    void update_states(Vector2 new_player_pos, double delta);
    State* change_state(const String &new_state);
    State* get_state();
    Vector2 process_state(double time_passed);
};

}

#endif
