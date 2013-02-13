#ifndef MASKOBB_H
#define MASKOBB_H

#include "collision/Mask.h"

class MaskOBB : public Mask
{
public:
	MaskOBB(float width, float height, float angle);
	MaskOBB(float width, float height, VecteurNorme rotation);
	virtual ~MaskOBB();

	float width, height;
	VecteurNorme rotation;

	virtual MaskAABB aabb() const;

	Point pointHG() const {return pos+Point(-width/2,height/2).rotation(rotation);}
	Point pointHD() const {return pos+Point(width/2,height/2).rotation(rotation);}
	Point pointBG() const {return pos+Point(-width/2,-height/2).rotation(rotation);}
	Point pointBD() const {return pos+Point(width/2,-height/2).rotation(rotation);}

	virtual bool collide(const Mask &m) const {
		return m._collide_(*this);
	}
	virtual bool _collide_(const MaskAABB& box) const;
	virtual bool _collide_(const MaskCercle& c) const;
	virtual bool _collide_(const MaskOBB& box) const;
	virtual bool _collide_(const MaskPoint& p) const;
	virtual bool _collide_(const MaskSegment& seg) const;

	virtual bool _collide_(const MaskComposite& m) const;
};

#endif // MASKOBB_H
