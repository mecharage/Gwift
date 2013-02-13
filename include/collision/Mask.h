#ifndef MASK_H
#define MASK_H

#include "util/Vecteur.h"
#include "util/VecteurNorme.h"

class MaskAABB;
class MaskCercle;
class MaskOBB;
class MaskPoint;
class MaskSegment;
class MaskComposite;
class MaskMap;

class Mask
{

public:
	Mask();
	Mask(Point position);
	virtual ~Mask();

	Point getPos() const {return pos;}
	void setPos(Point pos){this->pos = pos;}

	Point pos;

	virtual MaskAABB aabb() const =0;

	virtual bool collide(const Mask &m) const =0;
	virtual bool _collide_(const MaskAABB& box) const =0;
	virtual bool _collide_(const MaskCercle& c) const =0;
	virtual bool _collide_(const MaskOBB& box) const =0;
	virtual bool _collide_(const MaskPoint& p) const =0;
	virtual bool _collide_(const MaskSegment& seg) const =0;

	virtual bool _collide_(const MaskComposite& m) const =0;
	virtual bool _collide_(const MaskMap &map) const =0;

};

#include "collision/MaskAABB.h"
#include "collision/MaskCercle.h"
#include "collision/MaskOBB.h"
#include "collision/MaskPoint.h"
#include "collision/MaskSegment.h"

#include "collision/MaskComposite.h"

#endif // MASK_H
