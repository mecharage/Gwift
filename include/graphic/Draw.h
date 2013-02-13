#ifndef PRIMITIVES_H
#define	PRIMITIVES_H

#include "util/types.h"

#include <GL/glew.h>

struct Color
{
	ubyte r, g, b, a;

	static Color const white, black, gray, red, lime, blue, yellow, fuchsia, aqua, orange, brown;
};

enum BlendFunc
{
	add = GL_FUNC_ADD,
	subtract = GL_FUNC_SUBTRACT,
	revSubtract = GL_FUNC_REVERSE_SUBTRACT,
	min = GL_MIN,
	max = GL_MAX
};

enum BlendMode
{
	zero = GL_ZERO,
	one = GL_ONE,
	srcColor = GL_SRC_COLOR,
	oneMinusSrcColor = GL_ONE_MINUS_SRC_COLOR,
	dstColor = GL_DST_COLOR,
	oneMinusDstColor = GL_ONE_MINUS_DST_COLOR,
	srcAlpha = GL_SRC_ALPHA,
	oneMinusSrcAlpha = GL_ONE_MINUS_SRC_ALPHA,
	dstAlpha = GL_DST_ALPHA,
	oneMinusDstAlpha = GL_ONE_MINUS_DST_ALPHA,
	blendColor = GL_CONSTANT_COLOR,
	oneMinusBlendColor = GL_ONE_MINUS_CONSTANT_COLOR,
	blendAlpha = GL_CONSTANT_ALPHA,
	oneMinusBlendAlpha = GL_ONE_MINUS_CONSTANT_ALPHA,
	srcAlphaSaturate = GL_SRC_ALPHA_SATURATE
};

// Classe statique de fonctions d'affichage.
class Draw
{
public:
	// Génère une couleur à partir de ses composantes RGB.
	static Color rgb(ubyte r, ubyte g, ubyte b);
	// Génère une couleur à partir de ses composantes RGBA.
	static Color rgba(ubyte r, ubyte g, ubyte b, ubyte a);

	// Définit la transparence de dessin.
	static void setAlpha(ubyte a);

	// Définit la couleur de dessin.
	static void setColor(Color const& col);
	// Définit du blanc solide comme couleur de dessin.
	static void resetColor();

	// Définit le blending mode
	static void setBlendFunction(BlendFunc function);
	static void setBlendMode(BlendMode src, BlendMode dest);
	static void setBlendColor(Color col);
	static void resetBlending();

	// Affiche une ligne.
	static void line(int x1, int y1, int x2, int y2);
	// Affiche une ligne dotée d'une épaisseur.
	static void line(int x1, int y1, int x2, int y2, int width);
	// Affiche une ligne colorée par ses deux extrémités.
	static void coloredLine(int x1, int y1, int x2, int y2, Color const& begin, Color const& end);
	// Affiche une ligne dotée d'une épaisseur colorée par ses deux extrémités.
	static void coloredLine(int x1, int y1, int x2, int y2, Color const& begin, Color const& end, int width);
	// Affiche une ligne épaisse colorée par son centre et ses bords.
	static void beam(int x1, int y1, int x2, int y2, Color const& middle, Color const& outside, int width);

	// Affiche un triangle.
	static void triangle(int x1, int y1, int x2, int y2, int x3, int y3, bool filled = false);
	// Affiche un triangle coloré par ses trois sommets.
	static void coloredTriangle(int x1, int y1, int x2, int y2, int x3, int y3, Color const& col1, Color const& col2, Color const& col3, bool filled = false);

	// Affiche un rectangle.
	static void rect(int x1, int y1, int x2, int y2, bool filled = false);
	// Affiche un rectangle coloré par ses quatre sommets.
	static void coloredRect(int x1, int y1, int x2, int y2, Color const& col1, Color const& col2, Color const& col3, Color const& col4, bool filled = false);

	// Affiche un cercle.
	static void circle(int x, int y, int r, bool filled = false, int p = 36);
	// Affiche un cercle coloré par son centre et son périmètre.
	static void coloredCircle(int x, int y, int r, Color const& center, Color const& outside, int p = 36);

private:
	Draw();
	static void begin(GLenum mode, int x = 0, int y = 0);
	static void end();

	static Color m_CurrentColor;
};

#endif	/* PRIMITIVES_H */

