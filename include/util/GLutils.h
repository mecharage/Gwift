#ifndef GLUTILS_H
#define GLUTILS_H

#include <SDL.h>
#include <GL/glew.h>

// Génère une texture OpenGL à partir de la surface SDL, et retourne son identifiant.
GLuint sdlSurfToGlTex(SDL_Surface *surface);

#endif // GLUTILS_H
