#pragma once

/* Include window library */
#include "InputHandler.h"
#include "StatusOverlayText.h"
#include <iostream>
#include <string>
#include <sstream>
#include <SDL.h>
#undef main

class WindowHandler
{
public:
	WindowHandler();
	~WindowHandler();

	void beginLoop();
	void update(double delta_time);
	void draw();
private:
	InputHandler *m_crosshair;
	StatusOverlayText *m_statusoverlay;

	SDL_Window  *m_window;
	SDL_Surface *m_window_surface;
	SDL_Renderer *m_renderer;
	SDL_Event    m_window_event;
};
