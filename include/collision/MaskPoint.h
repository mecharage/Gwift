#ifndef MASKPOINT_H
#define MASKPOINT_H

#include "collision/Mask.h"

class MaskPoint : public Mask
{

public:
	MaskPoint(const Point& p);
	virtual ~MaskPoint();

	virtual MaskAABB aabb() const;// {return MaskAABB(0,0);}

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

#endif // MASKPOINT_H
