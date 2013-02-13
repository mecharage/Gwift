#ifndef MASKCOMPOSITE_H
#define MASKCOMPOSITE_H

#include "collision/Mask.h"
#include <vector>

class MaskComposite : public Mask
{

public:
    MaskComposite();
	virtual ~MaskComposite();

	virtual MaskAABB aabb() const;

	vector<Mask*> collection;

	//FAUX : trouver comment créer l'objet
	void addMask(Mask& m) {
		collection.push_back(&m);
	}

	virtual bool collide(const Mask &m) const {
		for(unsigned int i=0 ; i < collection.size() ; i++){
			if (m.collide(*collection[i])) return true;
		}
		return false;
	}
	virtual bool _collide_(const MaskAABB& box) const;
	virtual bool _collide_(const MaskCercle& c) const;
	virtual bool _collide_(const MaskOBB& box) const;
	virtual bool _collide_(const MaskPoint& p) const;
	virtual bool _collide_(const MaskSegment& seg) const;

	virtual bool _collide_(const MaskComposite& m) const;
};

#endif // MASKCOMPOSITE_H
