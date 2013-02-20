#ifndef BVHTREE_H
#define	BVHTREE_H

#include "collision/Mask.h"

/************************************
 * Déclaration de la classe BvhTree *
 ************************************/

template <typename T_ref>
class BvhTree
{
public:
	BvhTree();
	virtual ~BvhTree();

	// Ajoute le mask à l'abre et retourne la feuille le contenant.
	Leaf* include(Mask const& bounds);

private:
	BaseNode m_head;

	/*************************************
	 * Déclaration de la classe BaseNode *
	 *************************************/

	class BaseNode
	{
		friend class BvhTree;

	public:
		virtual ~BaseNode();

	private:
		BaseNode();
		BaseNode(Node *parent, MaskAABB const& bounds);

		virtual bool _isLeaf() const = 0;

		// Retourne le jumeau du noeud, ou NULL.
		BaseNode* _getSibling();

		// Retourne le pointeur du parent référençant le noeud, ou NULL.
		BaseNode** _parentPointer();

		Node *m_parent;
		MaskAABB *m_bounds;
	};


public:

	/*********************************
	 * Déclaration de la classe Node *
	 *********************************/

	// Noeud d'un BVHT pointant sur deux descendants

	class Node : public BaseNode
	{
		friend class Leaf;

	public:
		virtual ~Node();

	private:
		Node();
		Node(Node *parent, MaskAABB const& bounds);

		// Ajuste le BV du noeud à ceux de ses enfants.
		void _fitChildren();

		bool _isLeaf() const
		{
			return false;
		}

		BaseNode m_child[2];
	};

	/*********************************
	 * Déclaration de la classe Leaf *
	 *********************************/

	// Feuille d'un BVHT pointant sur un objet

	class Leaf : public BaseNode
	{
	public:
		virtual ~Leaf();

		void setBounds(MaskAABB const& bounds);
		void bindBounds(MaskAABB *bounds);
		void unbindBounds();

	private:
		Leaf();
		Leaf(Node *parent, MaskAABB const& bounds);

		void _addSibling(BaseNode &other);

		bool _isLeaf() const
		{
			return true;
		}

		T_ref *m_ref;
		bool m_ownBounds;
	};
};

#include "BvhTree.tpp"

#endif	/* BVHTREE_H */

