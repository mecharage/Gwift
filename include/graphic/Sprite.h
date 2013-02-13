#ifndef SPRITE_H
#define SPRITE_H

#include "Image.h"

typedef Image SpriteSheet;

// En réalité un metasprite. Classe décrivant un sprite comme une série de frames issues d'une même feuille de sprites.

class Sprite
{
public:
	Sprite();
	Sprite* setSheet(Image *sheet);
	Sprite* setSize(uint w, uint h);
	Sprite* setOrigin(int xorig, int yorig);
	// Détermine le nombre et la position des images dans la feuille.
	Sprite* sliceSheet(uint w, uint h, uint framenum, uint columns = (uint) -1, uint sheetx = 0, uint sheety = 0, uint hgap = 0, uint vgap = 0);
	// Vrai si le sprite pointe bien sur une feuille, possède une taille et au moins une frame.
	bool isValid() const;
	uint getWidth() const;
	uint getHeight() const;
	int getXorig() const;
	int getYorig() const;
	uint getFrameNum() const;
	// Fonction primitive. Plaque la frame du sprite sur un quad rectangulaire de taille adaptée.
	void drawAsGLQuad(uint frame) const;
	// Affiche le sprite aux coordonnées (x,y)
	void draw(int x, int y, uint frame) const;
	// Affiche le sprite aux coordonnées (x,y), étiré horizontalement et verticalement, et pivoté dans le sens direct (en degrés)
	void drawTransformed(int x, int y, uint frame, float xscale, float yscale, float rotation) const;
private:
	Image *m_sheet; // La feuille de sprites
	uint
	m_w, m_h, // Taille
	m_framenum, // Nombre de frames
	m_sheetx, m_sheety, // Position de la premi�re frame dans la feuille
	m_pw, m_ph, // Taille dans la feuille incluant les marges entre les frames
	m_columns; // Nombre de colonnes dans la feuille
	int m_xorig, m_yorig; // Origine du sprite
};

#endif // SPRITE_H
