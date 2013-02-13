#include "graphic/Screen.h"
#include "graphic/Draw.h"

#include "util/types.h"

#include <GL/glew.h>
#include <SDL.h>

uint Screen::m_Width, Screen::m_Height;
bool Screen::m_Fullscreen;
SDL_Surface *Screen::m_ScreenSurface;

bool Screen::init(uint width, uint height, bool fullscreen)
{
	m_ScreenSurface = SDL_SetVideoMode(width, height, 32, SDL_OPENGL | /*SDL_RESIZABLE |*/ (fullscreen ? SDL_FULLSCREEN : 0));
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, width, height, 0);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glMatrixMode(GL_MODELVIEW);

	glewInit();

	m_Width = width;
	m_Height = height;
	m_Fullscreen = fullscreen;

	Draw::resetBlending();

	return m_ScreenSurface != NULL;
}

void Screen::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
}

void Screen::flip()
{
	glFlush();
	SDL_GL_SwapBuffers();
}

void Screen::resize(uint width, uint height)	// Ne fonctionne pas non plus...
{
/*	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluOrtho2D(0, width, height, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	m_Width = width;
	m_Height = height;*/
}

void Screen::setFullscreen(bool fullscreen)	// Ne fonctionne pas sous SDL 1.2
{
	/*
	if(fullscreen)
		m_ScreenSurface->flags |= SDL_FULLSCREEN;
	else
		m_ScreenSurface->flags &= ~SDL_FULLSCREEN;

	m_Fullscreen = fullscreen;
	 */
}

uint Screen::width()
{
	return m_Width;
}

uint Screen::height()
{
	return m_Height;
}

bool Screen::fullscreen()
{
	return m_Fullscreen;
}