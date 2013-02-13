#ifndef PARTICLETYPE_H
#define	PARTICLETYPE_H

#include "util/types.h"
#include "graphic/Sprite.h"
#include "graphic/Draw.h"
#include "util/Vecteur.h"

enum PTshape
{
	point,
	circle,
	disk,
	flare,
	square,
	sprite
};

class ParticleType
{
public:
	ParticleType();
	ParticleType(const ParticleType& orig);
	virtual ~ParticleType();

	ParticleType& setShape(PTshape shape);
	ParticleType& setSprite(Sprite *sprite);
//	ParticleType& setColors();		// Varargs
	ParticleType& setInitialMoment(float hspeed, float vspeed);
	ParticleType& setInitialMomentPolar(float angle, float speed);
	ParticleType& setSteering(float accel, float steer);
	ParticleType& setAccel(Vecteur& accel);
	ParticleType& setAccel(float xaccel, float yaccel);

private:
	PTshape m_shape;
	Sprite *m_sprite;
	Color *m_colors;
	float *m_colorsRamp;
	ubyte m_colorsNum;
	Vecteur m_initM, m_steerM, m_addM;		// Vecteurs d'initialisation et évolution du mouvement.
	float m_initHalfSpread;
};

#endif	/* PARTICLETYPE_H */

