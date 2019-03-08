#include "pch.h"
#include "StatusOverlayText.h"


StatusOverlayText::StatusOverlayText(std::string text)
{
	m_text = text; 
	m_font = TTF_OpenFont("FreeSans.ttf", 24);
	if (!m_font) {
		printf("TTF_OpenFont Error: %s", TTF_GetError());
	}
	else {
		Black = { 0, 0, 0 };  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color
		//surfaceMessage = TTF_RenderText_Solid(m_font, m_text.c_str(), Black); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
		//Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance
	}
}

void StatusOverlayText::draw(SDL_Surface *window_surface, SDL_Renderer *renderer)
{
	/*
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture
	*/
	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 0;  //controls the rect's x coordinate 
	Message_rect.y = 0; // controls the rect's y coordinte
	Message_rect.w = 600; // controls the width of the rect
	Message_rect.h = 100; // controls the height of the rect

	SDL_Surface *text = TTF_RenderText_Solid(m_font, m_text.c_str(), Black);
	SDL_BlitSurface(text, &Message_rect, window_surface, &m_position);
	SDL_FreeSurface(text);
}

void StatusOverlayText::setText(std::string new_text) 
{
	m_text = new_text;
}