#ifndef STATE_H
#define STATE_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

//Base class of a state, defining what funcitons and parameters each state will inherit.
class State : public Node {
	GDCLASS(State, Node)

private:
    //time passed in-game
	double time_passed;

    String next_state_path;
    Dictionary next_state_data;

    Callable change_state;
    Node* persistent_state = nullptr;
    Vector2 velocity = Vector2(0, 0);

protected:
	static void _bind_methods();

public:
    double amplitude;
    int speed;
    //fraction to multiply with speed, so speed can more easily be an integer value
    float dampener = .25;

    State();
	virtual ~State();
    virtual void enter();
    virtual Vector2 update(double time_passed);
    virtual Vector2 seekplayer(Vector2 player_pos, Vector2 current_pos);
    virtual void exit();

};

}

#endif