#include "collision/MaskAABB.h"

MaskAABB::MaskAABB(float width, float height) : width(width), height(height){
}

MaskAABB::~MaskAABB(){
}

//Cette méthode est-elle vraiment juste ?!//
bool MaskAABB::_collide_(const MaskAABB& box2) const{
	MaskAABB const& box1 = *this;
	if(box1.pos.x > box2.pos.x + box2.width) return false;
	if(box2.pos.x > box1.pos.x + box1.width) return false;
	if(box1.pos.y > box2.pos.y + box2.height) return false;
	if(box2.pos.y > box1.pos.y + box1.height) return false;
	return true;
}

bool MaskAABB::_collide_(const MaskCercle &c) const{
	Point closestPoint = c.pos;
	if( c.pos.x < pos.x - width/2 ) closestPoint.x = pos.x - width/2;
	else if( c.pos.x > pos.x + width/2 ) closestPoint.x = pos.x + width/2;
	if( c.pos.y < pos.y - height/2 ) closestPoint.y = pos.y - height/2;
	else if( c.pos.y > pos.y + height/2 ) closestPoint.y = pos.y + height/2;
	Point diff=c.pos-closestPoint;
	return (diff.x*diff.x + diff.y*diff.y < c.rayon*c.rayon);
}

bool MaskAABB::_collide_(const MaskOBB &box2) const{
	//Adaptation de l'algo pour 2 OBB :
	MaskAABB const& box1 = *this;
	Point HG, HD, BG, BD;	//Sommets d'une des deux boîtes
	VecteurNorme axe;		//Axe testé sur la OBB
	float t, tmin, tmax;	//Valeurs des projections courante, min et max
	float origine;			//Valeur de la projection du centre de l'autre boîte
	float intervalle;		//Rayon de l'intervalle correspondant à l'axe courant

	//Projection de la OBB sur AABB//
	HG=box2.pointHG();
	HD=box2.pointHD();
	BG=box2.pointBG();
	BD=box2.pointBD();

	//Axe horizontal//
	//axe="Axe X";
	origine=box1.pos.x;
	intervalle=box1.width/2;
	tmin=HG.x; tmax=tmin;
	//t=HD.x;
	if (HD.x<tmin) tmin=HD.x;	else if (HD.x>tmax) tmax=HD.x;
	//t=BG.x;
	if (BG.x<tmin) tmin=BG.x;	else if (BG.x>tmax) tmax=BG.x;
	//t=BD.x;
	if (BD.x<tmin) tmin=BD.x;	else if (BD.x>tmax) tmax=BD.x;
	if (tmin > origine+intervalle || tmax < origine-intervalle) return false;

	//Axe Vertical
	//axe="Axe Y";
	origine=box1.pos.y;
	intervalle=box1.height/2;
	tmin=HG.y; tmax=tmin;
	//t=HD.y;
	if (HD.y<tmin) tmin=HD.y;	else if (HD.y>tmax) tmax=HD.y;
	//t=BG.y;
	if (BG.y<tmin) tmin=BG.y;	else if (BG.y>tmax) tmax=BG.y;
	//t=BD.y;
	if (BD.y<tmin) tmin=BD.y;	else if (BD.y>tmax) tmax=BD.y;
	if (tmin > origine+intervalle || tmax < origine-intervalle) return false;

	//Projection de la AABB sur la OBB//
	HG=box1.pointHG();
	HD=box1.pointHD();
	BG=box1.pointBG();
	BD=box1.pointBD();

	//Axe horizontal//
	axe=box2.rotation;
	origine=box2.pos*axe;
	intervalle=box2.width/2;
	tmin=axe*HG; tmax=tmin;
	t=axe*HD;
	if (t<tmin) tmin=t;	else if (t>tmax) tmax=t;
	t=axe*BG;
	if (t<tmin) tmin=t;	else if (t>tmax) tmax=t;
	t=axe*BD;
	if (t<tmin) tmin=t;	else if (t>tmax) tmax=t;
	if (tmin > origine+intervalle || tmax < origine-intervalle) return false;

	//Axe Vertical
	axe=!box2.rotation;
	origine=box2.pos*axe;
	intervalle=box2.height/2;
	tmin=axe*HG; tmax=tmin;
	t=axe*HD;
	if (t<tmin) tmin=t;	else if (t>tmax) tmax=t;
	t=axe*BG;
	if (t<tmin) tmin=t;	else if (t>tmax) tmax=t;
	t=axe*BD;
	if (t<tmin) tmin=t;	else if (t>tmax) tmax=t;
	if (tmin > origine+intervalle || tmax < origine-intervalle) return false;

	return true;
}

bool MaskAABB::_collide_(const MaskPoint &p) const{
	MaskAABB const& box = *this;
	if(p.pos.x > box.pos.x + box.width/2) return false;
	if(p.pos.x < box.pos.x - box.width/2) return false;
	if(p.pos.y > box.pos.y + box.height/2) return false;
	if(p.pos.y < box.pos.y - box.height/2) return false;
	return true;
}

bool MaskAABB::_collide_(const MaskSegment& seg) const{
	MaskAABB const& box = *this;
	float minX, maxX;
	float minY, maxY;

	float width_ = box.width / 2.0f;
	float boxMinX = box.pos.x - width_;
	float boxMaxX = box.pos.x + width_;

	if(seg.vecteur.x == 0.0f){
		if(seg.pos.x <= boxMinX || seg.pos.x >= boxMaxX) return false;

		// Find corresponding min and max Y for min and max X we found before
		if(seg.vecteur.y > 0.0f){
			minY = seg.pos.y;
			maxY = minY+seg.vecteur.y;
		}else{
			maxY = seg.pos.y;
			minY = maxY+seg.vecteur.y;
		}

	}else{

		// Find min and max X for the segment
		if(seg.vecteur.x > 0.0f){
			minX = seg.pos.x;
			maxX = minX+seg.vecteur.x;
		}else{
			maxX = seg.pos.x;
			minX = maxX+seg.vecteur.x;
		}

		// Find the intersection of the segment's and rectangle's x-projections
		if(maxX > boxMaxX) maxX = boxMaxX;
		if(minX < boxMinX) minX = boxMinX;
		// If X-projections do not intersect return false
		if(minX >= maxX) return false;

		// Find corresponding min and max Y for min and max X we found before
		float a = seg.vecteur.y / seg.vecteur.x;
		float b = seg.pos.y - a * seg.pos.x;
		if(a > 0.0f){
			minY = a * minX + b;
			maxY = a * maxX + b;
		}else{
			minY = a * maxX + b;
			maxY = a * minX + b;
		}
	}

	float height_ = box.height / 2.0f;
	float boxMinY = box.pos.y - height_;
	float boxMaxY = box.pos.y + height_;

	// Find the intersection of the segment's and rectangle's y-projections
	if(maxY > boxMaxY) maxY = boxMaxY;
	if(minY < boxMinY) minY = boxMinY;
	// If Y-projections do not intersect return false
	return (minY < maxY);
}

bool MaskAABB::_collide_(const MaskComposite& m) const{
	return m._collide_(*this);
}
