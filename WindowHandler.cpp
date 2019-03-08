#include "pch.h"
#include "WindowHandler.h"

SDL_Surface *load_surface(char const *path)
{
	SDL_Surface *image_surface = SDL_LoadBMP(path);

	if (!image_surface)
		return 0;

	return image_surface;
}

WindowHandler::WindowHandler()
{	
	//Initialize fonts
	if (TTF_Init() < 0) {
		printf("Failed to initialize font, error: {0}", TTF_GetError());
		exit(100);
	}

	m_window = SDL_CreateWindow("WindowHandler",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800, 600, 0);

	if (!m_window)
	{
		std::cout << "Failed to create window\n";
		std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return;
	}

	m_window_surface = SDL_GetWindowSurface(m_window);
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);

	if (!m_window_surface)
	{
		std::cout << "Failed to get window's surface\n";
		std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return;
	}

	m_crosshair = new InputHandler();
	m_statusoverlay = new StatusOverlayText("Initializing");
}

void WindowHandler::beginLoop()
{
	bool exit = false;
	while (!exit)
	{
		while (SDL_PollEvent(&m_window_event) > 0)
		{
			m_crosshair->handle_events(m_window_event);
			switch (m_window_event.type)
			{
			case SDL_QUIT:
				exit = false;
				break;
			}
		}
		update(1.0 / 60.0);
		draw();
	}
}

void WindowHandler::update(double delta_time)
{
	m_crosshair->update(delta_time);
}

void WindowHandler::draw()
{
	SDL_FillRect(m_window_surface, nullptr, SDL_MapRGB(m_window_surface->format, 255, 255, 255));
	m_crosshair->draw(m_window_surface);
	Vector position = m_crosshair->getPosition();

	std::stringstream stream;
	stream << "Position x: " << position.x << " y:" << position.y;
	m_statusoverlay->setText(stream.str());
	m_statusoverlay->draw(m_window_surface,m_renderer);
	SDL_UpdateWindowSurface(m_window);
}
WindowHandler::~WindowHandler()
{
}
