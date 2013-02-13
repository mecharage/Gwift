#ifndef MASKSEGMENT_H
#define MASKSEGMENT_H

#include "collision/Mask.h"

class MaskSegment : public Mask
{

public:
	MaskSegment(Point deb, Vecteur vect);
	virtual ~MaskSegment();

	Vecteur vecteur;
	Point debut() const {return pos;}
	Point fin() const {return pos+vecteur;}

	virtual MaskAABB aabb() const;

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

#endif // MASKSEGMENT_H
