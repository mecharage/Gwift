#include "collision/MaskPoint.h"

MaskPoint::MaskPoint(const Point& p) {
	setPos(p);
}

MaskPoint::~MaskPoint(){
}

MaskAABB MaskPoint::aabb() const {
	MaskAABB box(0,0);
	box.pos = pos;
	return box;
}

bool MaskPoint::_collide_(const MaskAABB& box) const{
	return box._collide_(*this);
}

bool MaskPoint::_collide_(const MaskCercle &c) const{
	Point diff=pos-c.pos;
	return (diff.x*diff.x + diff.y*diff.y < c.rayon*c.rayon);
}

bool MaskPoint::_collide_(const MaskOBB &box) const{
	return box._collide_(*this);
}

bool MaskPoint::_collide_(const MaskPoint &p) const{
	return false;
}

bool MaskPoint::_collide_(const MaskSegment& seg) const{
	return false;
}

bool MaskPoint::_collide_(const MaskComposite& m) const{
	return m._collide_(*this);
}
