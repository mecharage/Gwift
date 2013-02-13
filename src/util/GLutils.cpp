#include "util/GLutils.h"

#include <SDL.h>
#include <GL/glew.h>

GLuint sdlSurfToGlTex(SDL_Surface *surface)
{
	GLuint TextureID = 0;

	glGenTextures(1, &TextureID);
	glBindTexture(GL_TEXTURE_2D, TextureID);

	int Mode = (surface->format->BytesPerPixel == 4 ? GL_RGBA : GL_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, Mode, surface->w, surface->h, 0, Mode, GL_UNSIGNED_BYTE, surface->pixels);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	return TextureID;
}
