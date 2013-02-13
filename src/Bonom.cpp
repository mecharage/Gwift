#include "Bonom.h"

#include "controls/ControlsManager.h"
#include "controls/KeyboardKey.h"
#include "graphic/Image.h"
#include "graphic/Sprite.h"
#include "util/math_utils.h"
#include "AppContext.h"

Perso::Perso() :
m_x(400.),
m_y(300.),
m_frame(.0),
m_xscale(1.),
rightsheet(Image::loadFromFile("explorer.png")),
upsheet(Image::loadFromFile("exploreru.png")),
downsheet(Image::loadFromFile("explorerd.png")),
m_sprite(new Sprite()),
left_key(		CurrentControls->addButton(new KeyboardKey(SDLK_LEFT))),
right_key(		CurrentControls->addButton(new KeyboardKey(SDLK_RIGHT))),
up_key(			CurrentControls->addButton(new KeyboardKey(SDLK_UP))),
down_key(		CurrentControls->addButton(new KeyboardKey(SDLK_DOWN)))
{
	m_sprite
	->setSheet(rightsheet)
	->sliceSheet(32, 32, 8)
	->setOrigin(16, 16);
}

Perso::~Perso()
{
	delete m_sprite;
	delete rightsheet;
	delete upsheet;
	delete downsheet;
}

void Perso::performFrame(float elapsedSeconds)
{
	float
	x_v = CurrentControls->held(right_key) - CurrentControls->held(left_key),
	y_v = CurrentControls->held(down_key) - CurrentControls->held(up_key);

	x_v *= elapsedSeconds * 256;
	y_v *= elapsedSeconds * 256;

	m_x += x_v;
	m_y += y_v;

	if(x_v || y_v)
	{
		if(x_v)
		{
			m_sprite->setSheet(rightsheet);
			m_xscale = SIGN(x_v);
		}
		else
		{
			m_xscale = 1.0;
			if(SIGN(y_v) < 0)
				m_sprite->setSheet(upsheet);
			else
				m_sprite->setSheet(downsheet);
		}

		m_frame += elapsedSeconds * 16;
	}
	else
		m_frame = 0;

	m_sprite->drawTransformed(m_x, m_y, m_frame, m_xscale * 4, 4, 0);
}
