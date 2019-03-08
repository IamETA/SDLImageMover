#pragma once
#include <SDL.h>

class Vector {
public:
	float x;
	float y;
	Vector(float f1, float f2)
	{
		x = f1;
		y = f2;
	}
};

class InputHandler
{
public:
	enum class Direction
	{
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	InputHandler();
	~InputHandler() = default;
	Vector getPosition();
	void handle_events(SDL_Event const &event);
	void update(double delta_time);
	void draw(SDL_Surface *window_surface);
private:
	Direction    m_direction;

	SDL_Surface *m_image;
	SDL_Rect     m_position;
	double       m_x;
	double       m_y;
};
