#include "graphic/Sprite.h"

Sprite::Sprite() :
m_sheet(NULL),
m_w(0),
m_h(0),
m_framenum(0),
m_sheetx(0),
m_sheety(0),
m_pw(0),
m_ph(0),
m_columns(0),
m_xorig(0),
m_yorig(0) { }

Sprite* Sprite::setSheet(Image *sheet)
{
	m_sheet = sheet;
	return this;
}

Sprite* Sprite::setSize(uint w, uint h)
{
	m_w = w;
	m_h = h;
	return this;
}

Sprite* Sprite::setOrigin(int xorig, int yorig)
{
	m_xorig = xorig;
	m_yorig = yorig;
	return this;
}

Sprite* Sprite::sliceSheet(uint w, uint h, uint framenum, uint columns, uint sheetx, uint sheety, uint hgap, uint vgap)
{
	m_w = w;
	m_h = h;
	m_sheetx = sheetx;
	m_sheety = sheety;
	m_pw = m_w + hgap;
	m_ph = m_h + vgap;
	m_framenum = framenum;
	m_columns = columns;
	return this;
}

bool Sprite::isValid() const
{
	return m_sheet->isValid() && m_w && m_h && m_framenum;
}

uint Sprite::getWidth() const
{
	return m_w;
}

uint Sprite::getHeight() const
{
	return m_h;
}

int Sprite::getXorig() const
{
	return m_xorig;
}

int Sprite::getYorig() const
{
	return m_yorig;
}

uint Sprite::getFrameNum() const
{
	return m_framenum;
}

void Sprite::drawAsGLQuad(uint frame) const
{
	frame %= m_framenum;
	uint framex, framey;
	if(m_columns)
	{
		framex = frame % m_columns;
		framey = frame / m_columns;
	}
	else
	{
		framex = frame;
		framey = 0;
	}
	framex = m_sheetx + framex * m_pw;
	framey = m_sheety + framey * m_ph;

	m_sheet->drawAsGLQuadi(
	m_w, m_h,
	framex, framey,
	framex + m_w, framey + m_h
	);
}

void Sprite::draw(int x, int y, uint frame) const
{
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x - m_xorig, y - m_yorig, 0);
	drawAsGLQuad(frame);
	glPopMatrix();
}

void Sprite::drawTransformed(int x, int y, uint frame, float xscale, float yscale, float rotation) const
{
	if(!isValid()) return;

	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x, y, 0);
	glScalef(xscale, yscale, 1);
	glRotatef(rotation, 0, 0, -1);
	glTranslatef(-m_xorig, -m_yorig, 0);
	drawAsGLQuad(frame);
	glPopMatrix();
}
