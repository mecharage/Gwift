#ifndef PARTICLES_H
#define	PARTICLES_H

#include "util/types.h"
#include "graphic/Draw.h"
#include "util/Vecteur.h"

typedef ubyte ptype_id;

enum PTshape
{
	point,
	circle,
	square
};

class Particle
{
public:
	Particle(ptype_id type);

private:
};

#endif	/* PARTICLES_H */
