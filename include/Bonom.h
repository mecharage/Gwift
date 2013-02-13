#ifndef PERSO_H
#define PERSO_H

#include "controls/Controls.h"
#include "graphic/Sprite.h"

// Objet de test

class Perso
{
public:
	Perso();
	virtual ~Perso();

	void performFrame(float elapsedSeconds);
private:
	float
	m_x,
	m_y,
	m_frame,
	m_xscale;

	SpriteSheet *rightsheet, *upsheet, *downsheet;
	Sprite *m_sprite;

	button_id
	left_key,
	right_key,
	up_key,
	down_key;
};

#endif // PERSO_H
