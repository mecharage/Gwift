#include "util/BvhTree.h"

#include "collision/HasAABB.h"
#include "collision/MaskAABB.h"

BvhTree::BvhTree():
m_head(NULL)
{

}

BvhTree::~BvhTree()
{
	delete m_head;
}

BvhTree::Node *BvhTree::include(HasAABB &object)
{
	Node *n = new Node(NULL, object.aabb(), &object);

	if(m_head)
	{

	}
	else
		m_head = n;

	return n;
}

	/************************************
	 * Implémentation de la classe Node *
	 ************************************/

BvhTree::Node::Node(Node* parent, MaskAABB const& bounds, HasAABB *ref):
m_parent(parent),
m_bounds(bounds),
m_ref(ref)
{
	m_child[0] = m_child[1] = NULL;
}

BvhTree::Node::~Node()
{
	delete m_child[0];
	delete m_child[1];
}

bool BvhTree::Node::isLeaf()
{
	return !*m_child;
}