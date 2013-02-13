#include "graphic/Text.h"

#include <GL/glew.h>

std::vector<FTFont* > Text::fonts;
FTFont *Text::currentFont = NULL;

font_id Text::loadFont(std::string const& fname, int pixelSize)
{
	FTTextureFont *fnt = new FTTextureFont(fname.c_str());
	fnt->FaceSize(pixelSize);
	fonts.push_back(fnt);
	return fonts.size() - 1;
}

void Text::setFont(font_id font)
{
	if(font > fonts.size())
		currentFont = NULL;
	else
		currentFont = fonts[font];
}

void Text::draw(std::string const& text, int x, int y, float ha, float va, float xscale, float yscale, float rot)
{
	if(!currentFont)
		return;

	FTBBox bb = currentFont->BBox(text.c_str());
	ha *= bb.Lower().X() - bb.Upper().X();
	va *= bb.Lower().Y() - bb.Upper().Y();

	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotatef(rot, 0, 0, -1);
	glScalef(xscale, -yscale, 0);
	glTranslatef(ha, va, 0);

	currentFont->Render(text.c_str(), -1);
	glPopMatrix();
}

void Text::unloadAll()
{
	for(FTFont *f : fonts)
		delete f;
	fonts.clear();
	currentFont = NULL;
}