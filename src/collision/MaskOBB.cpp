#include "collision/MaskOBB.h"

MaskOBB::MaskOBB(float width, float height, float angle) : width(width), height(height), rotation(angle){
}

MaskOBB::MaskOBB(float width, float height, VecteurNorme rotation) : width(width), height(height), rotation(rotation) {
}

MaskOBB::~MaskOBB(){
}

MaskAABB MaskOBB::aabb() const{
	//Vecteur diagonaux de la OBB
	Vecteur diag1=Vecteur(width,height).rotation(rotation);
	Vecteur diag2=Vecteur(width,-height).rotation(rotation);
	MaskAABB box(max(abs(diag1.x),abs(diag2.x)), max(abs(diag1.y),abs(diag2.y)));
	box.pos=pos;
	return box;
}

bool MaskOBB::_collide_(const MaskAABB& box2) const{
	return box2._collide_(*this);
}

bool MaskOBB::_collide_(const MaskCercle &c) const{
	return c._collide_(*this);
}

bool MaskOBB::_collide_(const MaskOBB &box2) const{
	MaskOBB const& box1 = *this;
	Point HG, HD, BG, BD;	//Sommets d'une des 2 boîtes
	VecteurNorme axe;		//Axe testé sur l'autre boîte
	float t, tmin, tmax;	//Valeurs des projections courante, min et max
	float origine;			//Valeur de la projection du centre de l'autre boîte
	float intervalle;		//Rayon de l'intervalle correspondant à l'axe courant

	//Projection de box2 sur box1//
	HG=box2.pointHG();
	HD=box2.pointHD();
	BG=box2.pointBG();
	BD=box2.pointBD();

	//Axe horizontal//
	axe=box1.rotation;
	origine=box1.pos*axe;
	intervalle=box1.width/2;
	tmin=axe*HG; tmax=tmin;
	t=axe*HD;
	if (t<tmin) tmin=t;	else if (t>tmax) tmax=t;
	t=axe*BG;
	if (t<tmin) tmin=t;	else if (t>tmax) tmax=t;
	t=axe*BD;
	if (t<tmin) tmin=t;	else if (t>tmax) tmax=t;
	if (tmin > origine+intervalle || tmax < origine-intervalle) return false;

	//Axe Vertical
	axe=!box1.rotation;
	origine=box1.pos*axe;
	intervalle=box1.height/2;
	tmin=axe*HG; tmax=tmin;
	t=axe*HD;
	if (t<tmin) tmin=t;	else if (t>tmax) tmax=t;
	t=axe*BG;
	if (t<tmin) tmin=t;	else if (t>tmax) tmax=t;
	t=axe*BD;
	if (t<tmin) tmin=t;	else if (t>tmax) tmax=t;
	if (tmin > origine+intervalle || tmax < origine-intervalle) return false;

	//Projection de box1 sur box2//
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

bool MaskOBB::_collide_(const MaskPoint &p) const{
	//Point transformé dans le repère de la OBB
	Point transf = (p.pos - pos).rotation(rotation.angleInverse())*2;
	//même algo que pour AABB :
	if(transf.x > pos.x + width) return false;
	if(transf.x < pos.x - width) return false;
	if(transf.y > pos.y + height) return false;
	if(transf.y < pos.y - height) return false;
	return true;
}

bool MaskOBB::_collide_(const MaskSegment& seg) const{
	// Test des projection sur les axes de la OBB //
	MaskOBB const& box = *this;
	Vecteur decalage=seg.pos-box.pos;	//vecteur entre le centre de la boite et l'origine du segment
	float p1,p2;
	p1=box.rotation*decalage;			//projection de l'origine du segment sur le côté direct de la OBB
	p2=box.rotation*seg.vecteur;		//projection du vecteur de segment point sur le côté direct de la OBB
	if (p1>p2){
		  if(p2<-width/2 || p1>width/2) return false;	//teste si la projection appartient au côté de la OBB
	}else if(p1<-width/2 || p2>width/2) return false;
	Vecteur rotation_=!box.rotation;	//idem avec l'autre côté de la OBB
	p1=rotation_*decalage;				//
	p2=rotation_*seg.vecteur;			//
	if (p1>p2){							//
		  if(p2<-height/2 || p1>height/2) return false;
	}else if(p1<-height/2 || p2>height/2) return false;
	// Test de projection sur l'orthogonale du segment //
	p1 = Point(-width,height).rotation(rotation)*!seg.vecteur;
	p2 = Point(width,height).rotation(rotation)*!seg.vecteur;
	if (p1*p1 < p2*p2) p1=p2;
	if (p1<0.0f) p1=-p1;
	//projection du centre
	float p0 = decalage*seg.vecteur;
	return (0.0f < p0-p1 && p0+p1 > seg.vecteur.normeCarre());
}

bool MaskOBB::_collide_(const MaskComposite& m) const{
	return m._collide_(*this);
}
