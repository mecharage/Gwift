#include "graphic/Tileset.h"

typedef std::vector<Tileset* >::iterator tvectIterator;

static std::vector<Tileset* > m_LoadedTilesets;

Tileset::Tileset() :
Image(),
m_w(0),
m_h(0),
m_pw(0),
m_ph(0),
m_xoffset(0),
m_yoffset(0) { }

Tileset::~Tileset() { }

void Tileset::slice(uint tileWidth, uint tileHeight, int xoffset, int yoffset, int hmargin, int vmargin)
{
	m_w = tileWidth;
	m_h = tileHeight;
	m_pw = tileWidth + hmargin;
	m_ph = tileHeight + vmargin;
	m_xoffset = xoffset;
	m_yoffset = yoffset;
}

void Tileset::drawTile(Tile tile, int x, int y)
{
	int xx = tile.tx * m_pw, yy = tile.ty * m_ph;
	drawPart(xx, yy, xx + m_w, yy + m_h, x, y);
}

void Tileset::drawTile(Tile tile, int x, int y, uint w, uint h)
{
	int xx = tile.tx * m_pw, yy = tile.ty * m_ph;
	drawPart(xx, yy, xx + m_w, yy + m_h, x, y, x + w, y + h);
}

Tileset* Tileset::newFromFile(std::string fname)
{
	return (Tileset*) Image::loadFromFile(fname);
}

int loadFromListFile(std::string fname)
{
	m_LoadedTilesets.clear();	// Libération gérée par Image.
	//TODO : lecture de fichier
	return 0;
}
