#include "ParticleType.h"

#include "util/Vecteur.h"

ParticleType::ParticleType() :
m_shape(PTshape::point),
m_sprite(NULL),
m_colors(new Color[1]),
m_colorsRamp(new float[1]),
m_colorsNum(1),
m_initM(Vecteur()),
m_steerM(Vecteur(1., .0)),
m_addM(Vecteur())
{
	m_colors[0] = Color::white;
	m_colorsRamp[0] = .0;
}

ParticleType::ParticleType(const ParticleType& orig) { }

ParticleType::~ParticleType()
{
	delete m_colors;
	delete m_colorsRamp;
}

	ParticleType& setShape(PTshape shape);
	ParticleType& setSprite(Sprite *sprite);
//	ParticleType& setColors();		// Varargs
	ParticleType& setInitialMoment(float hspeed, float vspeed);
	ParticleType& setInitialMomentPolar(float angle, float speed);
	ParticleType& setSteering(float accel, float steer);
	ParticleType& setAccel(Vecteur& accel);
	ParticleType& setAccel(float xaccel, float yaccel);