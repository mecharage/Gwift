#ifndef HASAABB_H
#define	HASAABB_H

class MaskAABB;

struct HasAABB
{

	virtual ~HasAABB() { };
	virtual MaskAABB aabb() const = 0;
};

#endif	/* HASAABB_H */

