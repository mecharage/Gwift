#include "collision/MaskCercle.h"

MaskCercle::MaskCercle(float rayon) : rayon(rayon){
}

MaskCercle::~MaskCercle(){
}

MaskAABB MaskCercle::aabb() const{
	MaskAABB box(rayon*2, rayon*2);
	box.pos=pos;
	return box;
}

bool MaskCercle::_collide_(const MaskAABB& box2) const{
	return box2._collide_(*this);
}

bool MaskCercle::_collide_(const MaskCercle &c) const{
	Point diff=pos-c.pos;
	float som_rayon=rayon+c.rayon;
	return (diff.x*diff.x + diff.y*diff.y < som_rayon*som_rayon);
}

bool MaskCercle::_collide_(const MaskOBB &box) const{
	//Centre du cercle transformé dans le repère de la OBB
	Point transf = (pos - box.pos).rotation(box.rotation.angleInverse());
	//même algo que pour AABB :
	Point closestPoint = transf;
	if( transf.x < box.pos.x - box.width/2 ) closestPoint.x = box.pos.x - box.width/2;
	else if( transf.x > box.pos.x + box.width/2 ) closestPoint.x = box.pos.x + box.width/2;
	if( transf.y < box.pos.y - box.height/2 ) closestPoint.y = box.pos.y - box.height/2;
	else if( transf.y > box.pos.y + box.height/2 ) closestPoint.y = box.pos.y + box.height/2;
	Point diff = transf - closestPoint;
	return (diff.x*diff.x + diff.y*diff.y < rayon*rayon);
}

bool MaskCercle::_collide_(const MaskPoint &p) const{
	Point diff=pos-p.pos;
	return (diff.x*diff.x + diff.y*diff.y < rayon*rayon);
}

bool MaskCercle::_collide_(const MaskSegment& seg) const{
	Vecteur seg_c=pos-seg.pos;
	float prod=(seg.vecteur*seg_c);
	if(prod<=0.0f)
		return (seg_c.normeCarre() < rayon*rayon);
	else if(prod>=seg.vecteur.normeCarre())
		return ((seg_c-seg.vecteur).normeCarre() < rayon*rayon);
	else {
		//Vecteur entre le centre du cercle et sa projection orthogonale sur la droite normale au segment//
		Vecteur projection = !(this->pos - seg.pos) | seg.vecteur;
		return (projection.normeCarre() < rayon*rayon);
	}
}

bool MaskCercle::_collide_(const MaskComposite& m) const{
	return m._collide_(*this);
}
