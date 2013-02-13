#ifndef SCREEN_H
#define	SCREEN_H

#include "util/types.h"
#include <SDL.h>

#define DEFAULT_SCREEN_WIDTH 800
#define DEFAULT_SCREEN_HEIGHT 600

class Screen
{
public:
	static bool init() {return init(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);}
	static bool init(uint width, uint height, bool fullscreen = false);

	static uint width();
	static uint height();
	static bool fullscreen();

	static void resize(uint width, uint height);
	static void setFullscreen(bool fullscreen);

	static void clear();
	static void flip();

private:
	Screen();

	static uint m_Width, m_Height;
	static bool m_Fullscreen;
	static SDL_Surface *m_ScreenSurface;
};

#endif	/* SCREEN_H */

