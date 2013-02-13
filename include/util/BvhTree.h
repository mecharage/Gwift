#ifndef BVHTREE_H
#define	BVHTREE_H

//TEMP

class Mask
{
	Mask* collide(Mask const* other);
};

template <typename T_bounds, typename T_ref>
class BvhTree
{
public:
	BvhTree();

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
		Leaf();

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
		void detach();

	private:
		Leaf();

		void addSibling(BaseNode &other);

		bool isLeaf() const
		{
			return true;
		}

		T_ref *m_ref;
	};
};

#endif	/* BVHTREE_H */

