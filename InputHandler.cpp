#include "pch.h"
#include "InputHandler.h"
#include <SDL.h>

InputHandler::InputHandler()
{
	m_image = SDL_LoadBMP("reticle.bmp");
	m_position.x = 0;
	m_position.y = 0;
	m_position.w = 60;
	m_position.h = 60;

	m_x = 290.0;
	m_y = 240.0;

	m_direction = Direction::NONE;
}

Vector InputHandler::getPosition()
{
	return Vector(m_position.x,m_position.y);
}

void InputHandler::handle_events(SDL_Event const &event)
{
	
	switch (event.type)
	{

	case SDL_KEYDOWN:
		Uint8 const *keys = SDL_GetKeyboardState(nullptr);

		if (keys[SDL_SCANCODE_UP] == 1)
			m_direction = Direction::UP;
		else if (keys[SDL_SCANCODE_DOWN] == 1)
			m_direction = Direction::DOWN;
		else if (keys[SDL_SCANCODE_LEFT] == 1)
			m_direction = Direction::LEFT;
		else if (keys[SDL_SCANCODE_RIGHT] == 1)
			m_direction = Direction::RIGHT;
		else if (keys[SDL_SCANCODE_SPACE] == 1)
			m_direction = Direction::NONE;
		else if (keys[SDL_SCANCODE_ESCAPE] == 1)
			exit(0);
		break;
	}
}

void InputHandler::update(double delta_time)
{
	switch (m_direction)
	{
	case Direction::NONE:
		m_x += 0.0;
		m_y += 0.0;
		break;
	case Direction::UP:
		m_y = m_y - 0.1;
		break;
	case Direction::DOWN:
		m_y = m_y + 0.1;
		break;
	case Direction::LEFT:
		m_x = m_x - 0.1;
		break;
	case Direction::RIGHT:
		m_x = m_x + 0.1;
		break;
	}
	// Update the position after input.
	m_position.x = m_x;
	m_position.y = m_y;
}

void InputHandler::draw(SDL_Surface *window_surface)
{
	SDL_BlitScaled(m_image, nullptr, window_surface, &m_position);
}
