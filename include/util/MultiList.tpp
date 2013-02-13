#include "MultiList.h"

#include "types.h"
#include "MultiListException.h"

#include <iostream>
#include <stdio.h>

template <typename T_ref>
MultiList<T_ref>::MultiList(uint keys) :
m_keys(keys + 1),
m_heads(*this, NULL)
{
	for(T_key k = 0; k < m_keys; k++)
	{
		m_heads.node(k).m_previous = &m_heads;
		m_heads.node(k).m_next = &m_heads;
	}
}

template <typename T_ref>
MultiList<T_ref>::~MultiList()
{
	Cell *c = m_heads.m_nodes[GLOBAL_KEY].m_next, *t;
	while(c != &m_heads)
	{
		t = c->m_nodes[GLOBAL_KEY].m_next;
		delete c;
		c = t;
	}
}

template <typename T_ref>
typename MultiList<T_ref>::Cell& MultiList<T_ref>::append(T_ref const &object)
{
	return append(new T_ref(object));
}

template <typename T_ref>
typename MultiList<T_ref>::Cell& MultiList<T_ref>::append(T_ref *object)
{
	return (new Cell(*this, object))->link(GLOBAL_KEY);
}

//template <typename T_ref>
//Cell<T_ref>& MultiList<T_ref>::append(T_ref &object, T_keylist);	// Liste d'initialisation - instable

template <typename T_ref>
typename MultiList<T_ref>::iterator MultiList<T_ref>::begin(T_key key) const
{
	return iterator(*this, key, m_heads.node(key).m_next);
}

template <typename T_ref>
typename MultiList<T_ref>::iterator MultiList<T_ref>::begin() const
{
	return begin(GLOBAL_KEY);
}

template <typename T_ref>
typename MultiList<T_ref>::iterator MultiList<T_ref>::end() const
{
	return iterator(*this, GLOBAL_KEY, &m_heads);
}

/************************************
 * Implémentation de la classe Cell *
 ************************************/

template <typename T_ref>
MultiList<T_ref>::Cell::Cell(MultiList<T_ref> &list, T_ref *object) :
m_list(list),
m_nodes(new Node[m_list.m_keys]),
m_ref(object) { }

template <typename T_ref>
MultiList<T_ref>::Cell::~Cell()
{
	for(T_key k = 0; k < m_list.m_keys; k++)
		_unlink(k);
	delete[] m_nodes;
}

template <typename T_ref>
T_ref& MultiList<T_ref>::Cell::get() const
{
	return *m_ref;
}

template <typename T_ref>
typename MultiList<T_ref>::Cell& MultiList<T_ref>::Cell::link(T_key key)
{
	Node &n = node(key);
	if(!n.bound())
	{
		Node &h = m_list.m_heads.node(key);

		n.m_previous = h.m_previous;
		n.m_next = &m_list.m_heads;
		h.m_previous->node(key).m_next = this;
		h.m_previous = this;
	}
	return *this;
}

template <typename T_ref>
T_ref& MultiList<T_ref>::Cell::remove()
{
	for(T_key k = 0; k < m_list.m_keys; k++)
		_unlink(k);
	T_ref &r;
	delete this;
	return r;
}

template <typename T_ref>
typename MultiList<T_ref>::Cell& MultiList<T_ref>::Cell::unlink(T_key key)
{
	if(key = GLOBAL_KEY)
		throw MultiListException("Impossible de délier la clef globale !");
	else
		_unlink(key);
	return *this;
}

template <typename T_ref>
typename MultiList<T_ref>::Cell& MultiList<T_ref>::Cell::_unlink(T_key key)
{
	Node &n = node(key);
	if(n.bound())
	{
		n.m_previous->node(key).m_next = n.m_next;
		n.m_next->node(key).m_previous = n.m_previous;
		n.m_previous = NULL;
		n.m_next = NULL;
	}
	return *this;
}

template <typename T_ref>
typename MultiList<T_ref>::Cell::Node& MultiList<T_ref>::Cell::node(T_key key) const
{
	if(key >= m_list.m_keys)
		throw MultiListException("Clef incorrecte.");
	return m_nodes[key];
}

/****************************************
 * Implémentation de la classe iterator *
 ****************************************/

template <typename T_ref>
MultiList<T_ref>::iterator::iterator(MultiList<T_ref> &list, T_key key, Cell *cell) :
m_list(list),
m_key(key),
m_cell(cell),
m_next(NULL)
{
	if(m_cell)
		m_next = m_cell->node(m_key).m_next;
}

template <typename T_ref>
MultiList<T_ref>::iterator::~iterator() { }

template <typename T_ref>
bool MultiList<T_ref>::iterator::operator==(MultiList<T_ref>::iterator const& other) const
{
	return m_cell == other.m_cell;
}

template <typename T_ref>
bool MultiList<T_ref>::iterator::operator!=(MultiList<T_ref>::iterator const& other) const
{
	return m_cell != other.m_cell;
}

template <typename T_ref>
typename MultiList<T_ref>::iterator& MultiList<T_ref>::iterator::operator++()
{
	m_cell = m_next;
	m_next = m_next = m_cell->m_nodes[m_key].m_next;
	return *this;
}

template <typename T_ref>
typename MultiList<T_ref>::Cell& MultiList<T_ref>::iterator::operator*() const
{
	return *m_cell;
}

template <typename T_ref>
typename MultiList<T_ref>::Cell* MultiList<T_ref>::iterator::operator->() const
{
	return m_cell;
}