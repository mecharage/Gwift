#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <SDL.h>
#include <GL/glew.h>
#include <vector>
#include "util/types.h"

#define R_MASK 0xFF000000
#define G_MASK 0x00FF0000
#define B_MASK 0x0000FF00
#define A_MASK 0x000000FF

// Classe-enveloppe encapsulant une texture OpenGL.

class Image
{
public:
	Image();
	Image(SDL_Surface *surface);
	virtual ~Image();

	// Vrai si l'image enveloppe une texture OpenGL valide
	bool isValid() const;

	void draw(int x, int y) const;

	// Affiche la zone (x1,y1,x2,y2) de l'image à la position (x,y) de l'écran.
	void drawPart(int x1, int y1, int x2, int y2, int dx, int dy) const;

	void drawPart(int x1, int y1, int x2, int y2, int dx1, int dy1, int dx2, int dy2) const;

	// Fonction primitive. Affiche l'image sous forme d'un quad rectangulaire de taille (w,h)
	// texturé par la fraction [fx1,fy1,fx2,fy2] de l'image.
	void drawAsGLQuad(int w, int h, float fx1, float fy1, float fx2, float fy2) const;

	// Identique à drawAsGLQuad, mais avec des coordonnées en pixels.
	void drawAsGLQuadi(int w, int h, int x1, int y1, int x2, int y2) const;

	// Charge une image depuis un fichier image quelconque
	static Image* loadFromFile(std::string const& fname);

	// Libère toutes les images de la mémoire
	static void unloadAll();

protected:
	GLuint m_gltex; // La texture OpenGL enveloppée
	uint m_w, m_h; // Taille de l'image

	static std::vector<Image* > m_LoadedImages;
	static Image *m_DefaultImage;
};

#endif // IMAGE_H
