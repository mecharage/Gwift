#include "BvhTree.h"

/***************************************
 * Implémentation de la classe BvhTree *
 ***************************************/

BvhTree::BvhTree() { }

BvhTree::~BvhTree() { }

Leaf* BvhTree::include(Mask const& mask) { }

/****************************************
 * Implémentation de la classe BaseNode *
 ****************************************/

BaseNode::BaseNode(Node *parent, T_bounds const& bounds) :
m_parent(parent),
m_bounds(new T_bounds(bounds)) { }

BaseNode::~BaseNode() { }

/************************************
 * Implémentation de la classe Node *
 ************************************/

Node::Node(Node *parent, T_bounds const& bounds) : BaseNode(parent, bounds) { }

/************************************
 * Implémentation de la classe Leaf *
 ************************************/

Leaf::Leaf(Node *parent, T_bounds const& bounds) : BaseNode(parent, bounds) { }

Leaf::~Leaf() { }

void Leaf::setBounds(T_bounds const& bounds) { }

void Leaf::bindBounds(T_bounds *bounds) { }

void Leaf::detach() { }

void Leaf::addSibling(BaseNode &other) { }