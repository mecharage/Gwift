#include "collision/MaskComposite.h"

MaskComposite::MaskComposite(){
}

MaskComposite::~MaskComposite(){
	for(unsigned int i=0 ; i < collection.size() ; i++){
		delete collection[i];
	}
}

MaskAABB MaskComposite::aabb() const{
	float minX, maxX, minY, maxY;
	MaskAABB curr = collection[0]->aabb();
	minX = curr.pos.x - curr.width/2;
	maxX = minX + curr.width;
	minY = curr.pos.y - curr.height/2;
	maxY = minY + curr.height;
	for(unsigned int i=1 ; i < collection.size(); i++){
		float temp;
		curr = collection[i]->aabb();
		temp = curr.pos.x - curr.width/2;
		if (temp < minX) minX = temp;
		temp += curr.width;
		if (temp > maxX) maxX = temp;
		temp = curr.pos.y - curr.height/2;
		if (temp < minY) minY = temp;
		temp += curr.height;
		if (temp > maxY) maxY = temp;
	}
	MaskAABB box(maxX - minX, maxY - minY);
	box.pos = Point(maxX + (maxX - minX)/2, maxY + (maxY - minY)/2);
	return box;
}

bool MaskComposite::_collide_(const MaskAABB& box) const{
	for(unsigned int i=0 ; i < collection.size() ; i++){
		if (collection[i]->_collide_(box)) return true;
	}
	return false;
}

bool MaskComposite::_collide_(const MaskCercle &c) const{
	for(unsigned int i=0 ; i < collection.size() ; i++){
		if (collection[i]->_collide_(c)) return true;
	}
	return false;
}

bool MaskComposite::_collide_(const MaskOBB &box) const{
	for(unsigned int i=0 ; i < collection.size() ; i++){
		if (collection[i]->_collide_(box)) return true;
	}
	return false;
}

bool MaskComposite::_collide_(const MaskPoint &p) const{
	for(unsigned int i=0 ; i < collection.size() ; i++){
		if (collection[i]->_collide_(p)) return true;
	}
	return false;
}

bool MaskComposite::_collide_(const MaskSegment& seg) const{
	for(unsigned int i=0 ; i < collection.size() ; i++){
		if (collection[i]->_collide_(seg)) return true;
	}
	return false;
}

// Il semblerait que cette méthode ne soit jamais appelée... à vérifier. //
bool MaskComposite::_collide_(const MaskComposite& m) const{
	for(unsigned int i=0 ; i < collection.size() ; i++){
		if (collection[i]->_collide_(m)) return true;
	}
	return false;
}
