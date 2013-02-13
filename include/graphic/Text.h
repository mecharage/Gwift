#ifndef TEXT_H
#define	TEXT_H

#include <FTGL/ftgl.h>
#include <string>
#include <vector>

#include "util/types.h"

#define FA_LEFT		0
#define FA_CENTER	.5
#define FA_RIGHT	1
#define FA_TOP		1
#define FA_MIDDLE	.5
#define FA_BOTTOM	0

typedef ubyte font_id;

// Classe statique de fonctions d'affichage de texte.

class Text
{
public:
	// Charge une police depuis un fichier et retourne son identifiant.
	static font_id loadFont(std::string const& fname, int pixelSize);

	// Définit la police d'écriture.
	static void setFont(font_id font);

	// Affiche un texte avec la police et la couleur courantes.
	static void draw(std::string const& text, int x, int y, float ha = FA_LEFT, float va = FA_TOP, float xscale = 1, float yscale = 1, float rot = 0);

	// Libère toutes les polices chargées.
	static void unloadAll();

private:
	Text();

	static std::vector<FTFont* > fonts;
	static FTFont *currentFont;
};

#endif	/* TEXT_H */