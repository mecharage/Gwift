#ifndef MASKAABB_H
#define MASKAABB_H

#include "collision/HasAABB.h"
#include "collision/Mask.h"

class MaskAABB : public Mask, public HasAABB
{

public:
	MaskAABB(float width = .0, float height = .0);
	virtual ~MaskAABB();

	float width, height;

	MaskAABB aabb() const {return *this;}

	Point pointHG() const {return Mask::pos+Point(-width * .5, height * .5);}
	Point pointHD() const {return Mask::pos+Point(width* .5, height * .5);}
	Point pointBG() const {return Mask::pos+Point(-width* .5, -height * .5);}
	Point pointBD() const {return Mask::pos+Point(width* .5, -height * .5);}

	virtual MaskAABB& include(MaskAABB const& other);
	virtual float costToInclude(MaskAABB const& other);

	virtual bool collide(const Mask &m) const {
		return m._collide_(*this);
	}
	virtual bool _collide_(const MaskAABB& box) const;
	virtual bool _collide_(const MaskCercle& c) const;
	virtual bool _collide_(const MaskOBB& box) const;
	virtual bool _collide_(const MaskPoint& p) const;
	virtual bool _collide_(const MaskSegment& seg) const;
	virtual bool _collide_(const MaskMap& map) const;

	virtual bool _collide_(const MaskComposite& m) const;
};

#endif // MASKAABB_H
