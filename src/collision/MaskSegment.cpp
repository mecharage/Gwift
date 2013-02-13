#include "collision/MaskSegment.h"

MaskSegment::MaskSegment(Point debut, Vecteur vect) : Mask(debut), vecteur(vect) {
}

MaskSegment::~MaskSegment(){
}

MaskAABB MaskSegment::aabb() const{
	MaskAABB box(abs(vecteur.x), abs(vecteur.y));
	box.pos=pos+vecteur/2;
	return box;
}

bool MaskSegment::_collide_(const MaskAABB& box) const{
	return box._collide_(*this);
}

bool MaskSegment::_collide_(const MaskCercle &c) const{
	return c._collide_(*this);
}

bool MaskSegment::_collide_(const MaskOBB &box) const{
	return box._collide_(*this);
}

bool MaskSegment::_collide_(const MaskPoint &p) const{
	return false;
}

bool MaskSegment::_collide_(const MaskSegment& seg2) const{
	MaskSegment const& seg1 = *this;
	float Det(seg1.vecteur & seg2.vecteur);
	if(Det == 0.0f)			 return false;	// segments parallèles
	Vecteur v(seg2.pos - seg1.pos);
	float t = (v & seg2.vecteur) / Det;		//paramètre sur seg2
	if(t < 0.0f || 1.0f < t) return false;	// intersection en dehors de seg2
	float u = (v & seg1.vecteur) / Det;		//paramètre sur seg1
	return (0.0f < u && u < 1.0f);			// intersection est-elle dans seg1 ?
}

bool MaskSegment::_collide_(const MaskComposite& m) const{
	return m._collide_(*this);
}
