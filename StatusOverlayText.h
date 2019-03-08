#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
class StatusOverlayText
{
public:
	StatusOverlayText(std::string text);
	~StatusOverlayText() = default;
	void draw(SDL_Surface *window_surface, SDL_Renderer * renderer);
	void setText(std::string new_text);
private:
	SDL_Rect		m_position;
	std::string		m_text;
	TTF_Font*		m_font;
	SDL_Color		Black;
	SDL_Surface*	surfaceMessage;
	double			m_x;
	double			m_y;
};