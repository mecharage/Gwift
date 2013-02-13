#include "graphic/Draw.h"
#include "util/VecteurNorme.h"

#include <GL/glew.h>
#include <assert.h>

#define TWOPI 6.283185307179586476925286766559f

Color const
Color::white =		{0xFF,	0xFF,	0xFF,	0xFF},
Color::black =		{0x0,	0x0,	0x0,	0xFF},
Color::gray =		{0x80,	0x80,	0x80,	0xFF},
Color::red =		{0xFF,	0x0,	0x0,	0xFF},
Color::lime =		{0x0,	0xFF,	0x0,	0xFF},
Color::blue =		{0x0,	0x0,	0xFF,	0xFF},
Color::yellow =		{0xFF,	0xFF,	0x0,	0xFF},
Color::fuchsia =	{0xFF,	0x0,	0xFF,	0xFF},
Color::aqua =		{0x0,	0xFF,	0xFF,	0xFF},
Color::orange =		{0xFF,	0x80,	0x0,	0xFF},
Color::brown =		{0x80,	0x40,	0x0,	0xFF};

Color Draw::m_CurrentColor = Color::white;

Draw::Draw() { }

void Draw::begin(GLenum mode, int x, int y)
{
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x, y, .0);
	glBegin(mode);
}

void Draw::end()
{
	glEnd();
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
}

Color Draw::rgb(ubyte r, ubyte g, ubyte b)
{
	return rgba(r, g, b, 0xFF);
}

Color Draw::rgba(ubyte r, ubyte g, ubyte b, ubyte a)
{
	Color c = {r, g, b, a};
	return c;
}

void Draw::setColor(Color const& col)
{
	m_CurrentColor = col;
	glColor4ubv((ubyte*) & m_CurrentColor);
}

void Draw::resetColor()
{
	setColor(Color::white);
}

void Draw::setBlendFunction(BlendFunc function)
{
	glBlendEquation(function);
}

void Draw::setBlendMode(BlendMode src, BlendMode dest)
{
	glBlendFunc(src, dest);
}

void Draw::setBlendColor(Color col)
{
	glBlendColor(col.r / 255., col.g / 255., col.b / 255., col.a / 255.);
}

void Draw::resetBlending()
{
	glBlendEquation(GL_ADD);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBlendColor(1., 1., 1., 1.);
}

void Draw::setAlpha(ubyte a)
{
	m_CurrentColor.a = a;
	glColor4ubv((ubyte*) & m_CurrentColor);
}

void Draw::line(int x1, int y1, int x2, int y2)
{
	begin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	end();
}

void Draw::line(int x1, int y1, int x2, int y2, int width)
{
	Vecteur v(y1 - y2, x2 - x1);
	v.normer();
	v *= width / 2;

	begin(GL_QUADS);
	glVertex2i(x1 - v.x, y1 - v.y);
	glVertex2i(x1 + v.x, y1 + v.y);
	glVertex2i(x2 + v.x, y2 + v.y);
	glVertex2i(x2 - v.x, y2 - v.y);
	end();
}

void Draw::coloredLine(int x1, int y1, int x2, int y2, Color const& col1, Color const& col2)
{
	begin(GL_LINES);
	Color c = m_CurrentColor;

	setColor(col1);
	glVertex2i(x1, y1);
	setColor(col2);
	glVertex2i(x2, y2);

	setColor(c);
	end();
}

void Draw::coloredLine(int x1, int y1, int x2, int y2, Color const& col1, Color const& col2, int width)
{
	Vecteur v(y1 - y2, x2 - x1);
	v.normer();
	v *= width / 2;

	begin(GL_QUADS);
	Color c = m_CurrentColor;

	setColor(col1);
	glVertex2i(x1 - v.x, y1 - v.y);
	glVertex2i(x1 + v.x, y1 + v.y);
	setColor(col2);
	glVertex2i(x2 + v.x, y2 + v.y);
	glVertex2i(x2 - v.x, y2 - v.y);

	setColor(c);
	end();
}

void Draw::beam(int x1, int y1, int x2, int y2, Color const& middle, Color const& outside, int width)
{
	Vecteur v(y1 - y2, x2 - x1);
	v.normer();
	v *= width / 2;

	begin(GL_QUAD_STRIP);
	Color c = m_CurrentColor;

	setColor(outside);
	glVertex2i(x1 - v.x, y1 - v.y);
	glVertex2i(x2 - v.x, y2 - v.y);

	setColor(middle);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);

	setColor(outside);
	glVertex2i(x1 + v.x, y1 + v.y);
	glVertex2i(x2 + v.x, y2 + v.y);

	setColor(c);
	end();
}

void Draw::triangle(int x1, int y1, int x2, int y2, int x3, int y3, bool filled)
{
	begin(filled ? GL_TRIANGLES : GL_LINE_LOOP);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	end();
}

void Draw::coloredTriangle(int x1, int y1, int x2, int y2, int x3, int y3, Color const& col1, Color const& col2, Color const& col3, bool filled)
{
	begin(filled ? GL_TRIANGLES : GL_LINE_LOOP);
	Color c = m_CurrentColor;

	setColor(col1);
	glVertex2i(x1, y1);
	setColor(col2);
	glVertex2i(x2, y2);
	setColor(col3);
	glVertex2i(x3, y3);

	setColor(c);
	end();
}

void Draw::rect(int x1, int y1, int x2, int y2, bool filled)
{
	begin(filled ? GL_QUADS : GL_LINE_LOOP);
	glVertex2i(x1, y1);
	glVertex2i(x2, y1);
	glVertex2i(x2, y2);
	glVertex2i(x1, y2);
	end();
}

void Draw::coloredRect(int x1, int y1, int x2, int y2, Color const& col1, Color const& col2, Color const& col3, Color const& col4, bool filled)
{
	begin(filled ? GL_QUADS : GL_LINE_LOOP);
	Color c = m_CurrentColor;

	setColor(col1);
	glVertex2i(x1, y1);
	setColor(col2);
	glVertex2i(x2, y1);
	setColor(col3);
	glVertex2i(x2, y2);
	setColor(col4);
	glVertex2i(x1, y2);

	setColor(c);
	end();
}

void Draw::circle(int x, int y, int r, bool filled, int p)
{
	assert(p > 0);
	VecteurNorme rv(TWOPI / p);
	Vecteur v(r, 0);

	begin(filled ? GL_TRIANGLE_FAN : GL_LINE_LOOP, x, y);
	if(filled)
	{
		glVertex2i(0, 0);
		p++;
	}

	while(p)
	{
		glVertex2i(v.x, v.y);
		v = v.rotation(rv);
		p--;
	}

	end();
}

void Draw::coloredCircle(int x, int y, int r, Color const& center, Color const& outside, int p)
{
	assert(p > 0);
	VecteurNorme rv(TWOPI / p);
	Vecteur v(r, 0);

	begin(GL_TRIANGLE_FAN, x, y);
	Color c = m_CurrentColor;

	setColor(center);
	glVertex2i(0, 0);
	p++;

	setColor(outside);
	while(p)
	{
		glVertex2i(v.x, v.y);
		v = v.rotation(rv);
		p--;
	}

	setColor(c);
	end();
}