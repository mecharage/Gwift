#ifndef BVHTREE_H
#define	BVHTREE_H

//TEMP

class Mask
{
	virtual Mask* collide(Mask const* other) = 0;
	virtual Mask& include(Mask const& other) = 0;
	virtual float costToInclude(Mask const& other) = 0;
};

	/************************************
	 * Déclaration de la classe BvhTree *
	 ************************************/

template <typename T_bounds, typename T_ref>
class BvhTree
{
public:
	BvhTree();
	virtual ~BvhTree();
	Leaf* include(Mask const& mask);

private:
	BaseNode *m_head;

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
		BaseNode(Node *parent, T_bounds const& bounds);

		virtual bool isLeaf() const = 0;
		void fitChildren();

		Node *m_parent;
		T_bounds *m_bounds;
	};


public:

	/*********************************
	 * Déclaration de la classe Node *
	 *********************************/

	// Noeud d'un BVHT pointant sur deux descendants

	class Node : public BaseNode
	{
	public:
		virtual ~Node();

	private:
		Node();
		Node(Node *parent, T_bounds const& bounds);

		bool isLeaf() const
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

		void setBounds(T_bounds const& bounds);
		void bindBounds(T_bounds *bounds);
		void unbindBounds();
		void detach();

	private:
		Leaf();
		Leaf(Node *parent, T_bounds const& bounds);

		void addSibling(BaseNode &other);

		bool isLeaf() const
		{
			return true;
		}

		T_ref *m_ref;
		bool m_ownBounds;
	};
};

#include "BvhTree.tpp"

#endif	/* BVHTREE_H */

