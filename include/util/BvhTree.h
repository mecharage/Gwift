#ifndef BVHTREE_H
#define	BVHTREE_H

#include "collision/HasAABB.h"
#include "collision/MaskAABB.h"

/************************************
 * Déclaration de la classe BvhTree *
 ************************************/

class BvhTree
{
public:
	class Node;

	BvhTree();
	virtual ~BvhTree();

	// Ajoute le mask à l'abre et retourne la feuille le contenant.
	Node* include(HasAABB &object);

private:
	Node *m_head;

public:
	/*********************************
	 * Déclaration de la classe Node *
	 *********************************/

	// Noeud d'un BVHT

	class Node
	{
		friend class BvhTree;

	public:
		virtual ~Node();

	private:
		Node();
		Node(Node *parent, MaskAABB const& bounds, HasAABB *ref);

		bool isLeaf();


		Node *m_parent, *m_child[2];
		MaskAABB m_bounds;
		HasAABB *m_ref;
	};
};

#endif	/* BVHTREE_H */

