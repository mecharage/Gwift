#include "graphic/Image.h"
#include "util/GLutils.h"

#include <GL/glew.h>
#include <SDL_image.h>

Image *Image::m_DefaultImage = new Image();
std::vector<Image* > Image::m_LoadedImages;

Image::Image() :
m_gltex(0),
m_w(0),
m_h(0) { }

Image::Image(SDL_Surface *surface) :
m_gltex(sdlSurfToGlTex(surface)),
m_w(surface->w),
m_h(surface->h) { }

Image::~Image()
{
	glDeleteTextures(1, &m_gltex);
}

bool Image::isValid() const
{
	return m_gltex != 0;
}

void Image::drawAsGLQuad(int w, int h, float fx1, float fy1, float fx2, float fy2) const
{
	glBindTexture(GL_TEXTURE_2D, m_gltex);
	glBegin(GL_QUADS);
	glTexCoord2f(fx1, fy1);
	glVertex2i(0, 0);
	glTexCoord2f(fx2, fy1);
	glVertex2i(w, 0);
	glTexCoord2f(fx2, fy2);
	glVertex2i(w, h);
	glTexCoord2f(fx1, fy2);
	glVertex2i(0, h);
	glEnd();
}

void Image::drawAsGLQuadi(int w, int h, int x1, int y1, int x2, int y2) const
{
	drawAsGLQuad(
	w, h,
	(float) x1 / m_w, (float) y1 / m_h,
	(float) x2 / m_w, (float) y2 / m_h
	);
}

void Image::draw(int x, int y) const
{
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x, y, 0);
	drawAsGLQuad(m_w, m_h, 0, 0, 1, 1);
	glPopMatrix();
}

void Image::drawPart(int x1, int y1, int x2, int y2 , int dx, int dy) const
{
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(dx, dy, 0);
	drawAsGLQuadi(x2 - x1, y2 - y1, x1, y1, x2, y2);
	glPopMatrix();
}

void Image::drawPart(int x1, int y1, int x2, int y2 , int dx, int dy, int dx2, int dy2) const
{
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(dx, dy, 0);
	drawAsGLQuadi(dx2 - dx, dy2 - dy, x1, y1, x2, y2);
	glPopMatrix();
}

Image* Image::loadFromFile(std::string const& fname)
{
	SDL_Surface *surface = IMG_Load(fname.c_str());

	if(!surface)
	{
		SDL_FreeSurface(surface);
		return m_DefaultImage;
	}

	Image *i = new Image(surface);
	m_LoadedImages.push_back(i);

	SDL_FreeSurface(surface);
	return i;
}

void Image::unloadAll()
{
	delete m_DefaultImage;
	for(Image *i : m_LoadedImages)
		delete i;

	m_LoadedImages.clear();
}