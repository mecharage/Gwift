#include "BvhTree.h"

/***************************************
 * Implémentation de la classe BvhTree *
 ***************************************/

BvhTree::BvhTree() { }

BvhTree::~BvhTree() { }

template <typename T_ref>
BvhTree<T_ref>::Leaf* BvhTree::include(MaskAABB const& bounds) { }

/****************************************
 * Implémentation de la classe BaseNode *
 ****************************************/

template <typename T_ref>
BvhTree<T_ref>::BaseNode::BaseNode(Node *parent, MaskAABB const& bounds) :
m_parent(parent),
m_bounds(new MaskAABB(bounds)) { }

template <typename T_ref>
BvhTree<T_ref>::BaseNode::~BaseNode() { }

/************************************
 * Implémentation de la classe Node *
 ************************************/

template <typename T_ref>
BvhTree<T_ref>::Node::Node(Node *parent, MaskAABB const& bounds) : BaseNode(parent, bounds) { }

template <typename T_ref>
BvhTree<T_ref>::Node::~Node() { }

template <typename T_ref>
void BvhTree<T_ref>::Node::_fitChildren()
{
	m_bounds = *m_child[0]->m_bounds;
	m_bounds->include(*m_child[1]->m_bounds);
}

/************************************
 * Implémentation de la classe Leaf *
 ************************************/

template <typename T_ref>
BvhTree<T_ref>::Leaf::Leaf(Node *parent, MaskAABB const& bounds) :
BaseNode(parent, bounds),
m_ownBounds(false) { }

template <typename T_ref>
BvhTree<T_ref>::Leaf::~Leaf()
{
	BaseNode *s = _getSibling();
	*m_parent->_parentPointer() = s;
	s->m_parent = m_parent->m_parent;

	if(m_ownBounds)
		delete m_bounds;

	s->m_parent->_fitChildren();
}

template <typename T_ref>
void BvhTree<T_ref>::Leaf::setBounds(MaskAABB const& bounds)
{
	*m_bounds = bounds;
	m_parent->_fitChildren();
}

template <typename T_ref>
void BvhTree<T_ref>::Leaf::bindBounds(MaskAABB *bounds)
{
	if(m_ownBounds)
		delete m_bounds;
	m_bounds = bounds;
	m_ownBounds = false;
	m_parent->_fitChildren();
}

template <typename T_ref>
void BvhTree<T_ref>::Leaf::unbindBounds()
{
	if(m_ownBounds)
		return;
	m_bounds = m_bounds->clone();
	m_ownBounds =  true;
	m_parent->_fitChildren();
}

template <typename T_ref>
void BvhTree<T_ref>::Leaf::_addSibling(BaseNode *other)
{
	m_parent = new Node(m_parent, new T_bounds());
	m_parent->m_child = {this, other};
	m_parent->_fitChildren();
}