#ifndef MASKMAP_H
#define MASKMAP_H

#include "collision/Mask.h"

class MaskMap : public Mask
{
public:
    MaskMap();
	virtual ~MaskMap();



	virtual MaskAABB aabb() const = 0;

	virtual bool collide(const Mask &m) const {
		return m._collide_(*this);
	}
	virtual bool _collide_(const MaskAABB& box) const;
	virtual bool _collide_(const MaskCercle& c) const;
	virtual bool _collide_(const MaskOBB& box) const;
	virtual bool _collide_(const MaskPoint& p) const;
	virtual bool _collide_(const MaskSegment& seg) const;
	virtual bool _collide_(const MaskMap& m) const;

	virtual bool _collide_(const MaskComposite& m) const;
};

#endif // MASKMAP_H
