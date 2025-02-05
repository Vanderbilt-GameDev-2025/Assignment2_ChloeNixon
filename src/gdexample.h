#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class GDExample : public Sprite2D {
	GDCLASS(GDExample, Sprite2D)

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

protected:
	static void _bind_methods();

public:
	GDExample();
	~GDExample();

	void _process(double delta) override;
    Vector2 move_left(const Vector2 p_position);
    Vector2 oscillate(const Vector2 p_position);
    void set_amplitude(const double p_amplitude);
	double get_amplitude() const;
	void set_speed(const double p_speed);
	double get_speed() const;
    void set_hp(const int p_hp);
	int get_hp() const;
    void set_points(const int p_points);
	int get_points() const;
};

}

#endif