#include "graphic/TileMap.h"

#include "graphic/Tileset.h"

TileMap::TileMap(uint width, uint height, uint depth, uint tilewidth, uint tileheight) :
m_width(width),
m_height(height),
m_depth(depth),
m_tw(tilewidth),
m_th(tileheight),
m_layers(new Tile**[m_depth])
{
	for(int i = 0; i < m_width; i++)
	{
		m_layers[i] = new Tile*[m_width];
		for(int j = 0; j < m_width; j++)
			m_layers[i][j] = new Tile[m_height];
	}
}

TileMap::~TileMap()
{
	for(int i = 0; i < m_width; i++)
	{
		for(int j = 0; j < m_width; j++)
			delete[] m_layers[i][j];
		delete[] m_layers[i];
	}
	delete[] m_layers;
}

void TileMap::setTileSize(uint w, uint h)
{
	m_tw = w;
	m_th = h;
}