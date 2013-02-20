#include "collision/MaskMap.h"

MaskMap::MaskMap() { }

MaskMap::~MaskMap()
{
	
}

// TODO actual functions

MaskAABB MaskMap::aabb() const
{
	return MaskAABB();
}

bool MaskMap::_collide_(const MaskAABB& box) const
{
	return false;
}

bool MaskMap::_collide_(const MaskCercle& c) const
{
	return false;
}

bool MaskMap::_collide_(const MaskOBB& box) const
{
	return false;
}

bool MaskMap::_collide_(const MaskPoint& p) const
{
	return false;
}

bool MaskMap::_collide_(const MaskSegment& seg) const
{
	return false;
}

bool MaskMap::_collide_(const MaskMap& m) const
{
	return false;
}

bool MaskMap::_collide_(const MaskComposite& m) const
{
	return false;
}
