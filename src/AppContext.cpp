#include "AppContext.h"
#include "ObjectsManager.h"
#include "controls/ControlsManager.h"
#include "graphic/Screen.h"
#include "graphic/Text.h"
#include "graphic/Image.h"

#include <stdlib.h>
#include <SDL.h>

bool AppContext::m_KeepLooping;
ObjectsManager *AppContext::m_ObjectsManager;

bool AppContext::init()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
	Screen::init(800, 600);
	atexit(clean);

	ControlsManager::createControls();

	m_ObjectsManager = new ObjectsManager();

	return true;
}

void AppContext::clean() throw()
{
	Text::unloadAll();
	Image::unloadAll();
	SDL_Quit();
}

void AppContext::stopMainLoop()
{
	m_KeepLooping = false;
}

void AppContext::mainLoop()
{
	SDL_Event event;
	char caption[64];
	Uint32
	previousTime = SDL_GetTicks(),
	timeDelta,
	MPF = 16;
	float elapsedSeconds;

	m_KeepLooping = true;

	while(m_KeepLooping)
	{
		// Timer
		timeDelta = SDL_GetTicks() - previousTime;
		previousTime = SDL_GetTicks();
		elapsedSeconds = .001 * timeDelta;
		if(timeDelta < MPF)
			SDL_Delay(MPF - timeDelta);

		sprintf(caption, "MPF: %d", timeDelta);

		SDL_WM_SetCaption(caption, NULL);

		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_KEYDOWN:
					if(event.key.keysym.sym != SDLK_ESCAPE)
						break;
				case SDL_QUIT:
					stopMainLoop();
					break;

				case SDL_VIDEORESIZE:
					Screen::resize(event.resize.w, event.resize.h);
					break;

				default:
					break;
			}
		}

		Screen::clear();
		CurrentControls->update();
		m_ObjectsManager->performTick(elapsedSeconds);
		Screen::flip();
	}
}

void AppContext::setObjectsManager(ObjectsManager *objManager)
{
	m_ObjectsManager = objManager;
}

ObjectsManager* AppContext::getObjectsManager()
{
	return m_ObjectsManager;
}