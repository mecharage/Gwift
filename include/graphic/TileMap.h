#ifndef TILEMAP_H
#define	TILEMAP_H

#include "Tileset.h"

class TileMap
{
public:
	TileMap(uint width, uint height, uint depth, uint tilewidth, uint tileheight);
	~TileMap();

	void setTileSize(uint w, uint h);

private:
	uint const m_width, m_height, m_depth;
	uint m_tw, m_th;
	Tile ***m_layers;
};

#endif	/* TILEMAP_H */
