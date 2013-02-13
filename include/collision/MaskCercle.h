#ifndef MASKCERCLE_H
#define MASKCERCLE_H

#include "collision/Mask.h"

class MaskCercle : public Mask
{
public:
	MaskCercle(float rayon);
	virtual ~MaskCercle();

	float rayon;

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

#endif // MASKCERCLE_H
