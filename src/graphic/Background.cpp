#include "graphic/Background.h"

Background::Background() { }

Background::~Background() { }

Background* Background::newFromFile(std::string fname)
{
	return (Background*) Image::loadFromFile(fname);
}

void Background::tileRectangle(int x1, int y1, int x2, int y2, float xscale, float yscale, int xoffset, int yoffset) const
{
	int w = x2 - x1, h = y2 - y1;

	drawPart(xoffset, yoffset, w / xscale + xoffset, h / yscale + yoffset, x1, y1, x2, y2);
}