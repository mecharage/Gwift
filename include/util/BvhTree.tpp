#include "BvhTree.h"

/***************************************
 * Implémentation de la classe BvhTree *
 ***************************************/

BvhTree::BvhTree() { }

BvhTree::~BvhTree() { }

template <typename T_bounds, typename T_ref>
BvhTree<T_bounds, T_ref>::Leaf* BvhTree::include(Mask const& mask) { }

/****************************************
 * Implémentation de la classe BaseNode *
 ****************************************/

template <typename T_bounds, typename T_ref>
BvhTree<T_bounds, T_ref>::BaseNode::BaseNode(Node *parent, T_bounds const& bounds) :
m_parent(parent),
m_bounds(new T_bounds(bounds)) { }

template <typename T_bounds, typename T_ref>
BvhTree<T_bounds, T_ref>::BaseNode::~BaseNode() { }

template <typename T_bounds, typename T_ref>
void BvhTree<T_bounds, T_ref>::BaseNode::fitChildren() {
 }

/************************************
 * Implémentation de la classe Node *
 ************************************/

template <typename T_bounds, typename T_ref>
BvhTree<T_bounds, T_ref>::Node::Node(Node *parent, T_bounds const& bounds) : BaseNode(parent, bounds) { }

template <typename T_bounds, typename T_ref>
BvhTree<T_bounds, T_ref>::Node::~Node() { }

/************************************
 * Implémentation de la classe Leaf *
 ************************************/

template <typename T_bounds, typename T_ref>
BvhTree<T_bounds, T_ref>::Leaf::Leaf(Node *parent, T_bounds const& bounds) :
BaseNode(parent, bounds),
m_ownBounds(false) { }

template <typename T_bounds, typename T_ref>
BvhTree<T_bounds, T_ref>::Leaf::~Leaf() { }

template <typename T_bounds, typename T_ref>
void BvhTree<T_bounds, T_ref>::Leaf::setBounds(T_bounds const& bounds)
{
	*m_bounds = bounds;
	m_parent->fitChildren();
}

template <typename T_bounds, typename T_ref>
void BvhTree<T_bounds, T_ref>::Leaf::bindBounds(T_bounds *bounds)
{
	if(m_ownBounds)
		delete m_bounds;
	m_bounds = bounds;
	m_ownBounds = false;
	m_parent->fitChildren();
}

template <typename T_bounds, typename T_ref>
void BvhTree<T_bounds, T_ref>::Leaf::unbindBounds()
{
	if(!m_ownBounds)
		m_bounds = new T_bounds(*m_bounds);
}

template <typename T_bounds, typename T_ref>
void BvhTree<T_bounds, T_ref>::Leaf::detach() { }

template <typename T_bounds, typename T_ref>
void BvhTree<T_bounds, T_ref>::Leaf::addSibling(BaseNode &other) { }