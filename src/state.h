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
    float dampener = .25;

	// State(const Callable& p_change_state, Node* p_persistent_state);
    State();
	virtual ~State();
	// void _ready() override;
	// void _process(double delta) override;
    // void handle_input(InputEvent _event);
    // void update(float _delta);
    // void physics_update(float _delta);
    // void enter(String previous_state_path, Dictionary data = {});
    virtual void enter();
    virtual Vector2 update(double time_passed);
    virtual Vector2 seekplayer(Vector2 player_pos, Vector2 current_pos);
    virtual void exit();
    virtual void move_left(const Vector2 p_position);
    virtual void oscillate(const Vector2 p_position);

    // void _physics_process(double delta) override;
    // void set_speed(const double p_speed);
	// double get_speed() const;
    // void set_amplitude(const double p_amplitude);
	// double get_amplitude() const;

    //void setup(const Callable& p_change_state, AnimatedSprite2D* p_animated_sprite, Node2D* p_persistent_state);
};

}

#endif