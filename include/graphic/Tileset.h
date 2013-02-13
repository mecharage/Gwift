#ifndef TILESET_H
#define	TILESET_H

#include "graphic/Image.h"
#include "util/types.h"
#include <vector>

class Tileset;

struct Tile
{
	ubyte set;
	ubyte tx, ty;
};

// Représente une planche de tiles.

class Tileset : public Image
{
public:
	Tileset();
	virtual ~Tileset();

	// Détermine le découpage de la planche de tiles.
	void slice(uint tileWidth, uint tileHeight, int xoffset = 0, int yoffset = 0, int hmargin = 0, int vmargin = 0);
	// Affiche une unique tile à  la position (x, y).
	void drawTile(Tile tile, int x, int y);
	// Affiche une tile à  la position (x, y) aux dimensions w x h.
	void drawTile(Tile tile, int x, int y, uint w, uint h);

	// Vide la liste des tilesets et en charge une nouvelle depuis un fichier.
	static int loadFromListFile(std::string fname);
	// Charge le tileset depuis un fichier image.
	static Tileset* newFromFile(std::string fname);

private:
	uint m_w, m_h;

	int
	m_pw, m_ph,
	m_xoffset, m_yoffset;

	static std::vector<Tileset* > m_LoadedTilesets;
};

#endif	/* TILESET_H */
