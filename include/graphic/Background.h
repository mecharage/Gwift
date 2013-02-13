#ifndef BACKGROUND_H
#define	BACKGROUND_H

#include "Image.h"

// Une image utilisable pour recouvrir des surfaces par répétition.

class Background : public Image
{
public:
	Background();
	virtual ~Background();
	static Background* newFromFile(std::string fname);

	bool isValid() const;
	// Affiche une seule fois le background à la position spécifiée.
	void draw(int x, int y) const;
	// Pave le rectangle avec le background, agrandi par les facteurs xscale et yscale, et décalé d'un offset.
	void tileRectangle(int x1, int y1, int x2, int y2, float xscale = 1, float yscale = 1, int xoffset = 0, int yoffset = 0) const;
};

#endif	/* BACKGROUND_H */