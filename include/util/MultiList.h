#ifndef MULTILIST_H
#define	MULTILIST_H

#include "types.h"

#include <vector>

#define GLOBAL_KEY 0	// Clef pour la sous-liste complète. Elle ne peut pas être déliée par l'utilisateur.

typedef uint T_key;
//typedef std::vector<T_key> T_keylist;	// Liste d'initialisation


// Collection hybride itérable séquentiellement
// en totalité ou selon une sous-liste accédée par une clé.

template <typename T_ref>
class MultiList
{
public:
	class Cell;
	class iterator;
	friend class Cell;

	// Construit une multiliste dotée d'un certain nombre de sous-listes.
	// Les sous listes sont indicées de 1 à keys et non de 0 à keys-1 !
	MultiList(uint keys);

	virtual ~MultiList();

	// Adjoint une copie de l'objet à la liste et retourne une référence sur sa cellule.
	Cell& append(T_ref const &object);

	// Adjoint l'objet à la liste sans le copier et retourne une référence sur sa cellule.
	Cell& append(T_ref *object);
	//Cell& append(T_ref &object, T_keylist);	// Liste d'initialisation

	// Retourne un itérateur suivant la clef key et pointant sur la première cellule de cette sous-liste.
	iterator begin(T_key key) const;

	// Retourne un itérateur sur la sous-liste complète, pointant sur son premier élément.
	iterator begin() const;

	// Retourne l'itérateur post-fin.
	iterator end() const;

private:
	MultiList();

	uint const m_keys;
	Cell m_heads;


public:

	/*********************************
	 * Déclaration de la classe Cell *
	 *********************************/

	// Cellule d'une multiliste

	class Cell
	{
		friend class MultiList<T_ref>;
		friend class MultiList<T_ref>::iterator;
		struct Node;

	public:

		// Retourne une référence sur l'objet pointé par cette cellule.
		T_ref& get() const;

		// Lie la cellule à une sous-liste si elle ne l'est déjà.
		Cell& link(T_key key);

		// Délie la cellule de la sous-liste si elle en fait partie.
		Cell& unlink(T_key key);

		T_ref& remove();

	private:
		Cell();
		Cell(MultiList<T_ref> &list, T_ref *object);
		virtual ~Cell();

		Cell& _unlink(T_key key);

		Node& node(T_key key) const;

		MultiList &m_list;
		Node * const m_nodes;
		T_ref *m_ref;

		struct Node
		{
			Cell *m_previous, *m_next;

			Node() : m_previous(NULL), m_next(NULL) { }

			bool bound()
			{
				return m_previous != NULL;
			}
		};
	};

	/*************************************
	 * Déclaration de la classe iterator *
	 *************************************/

	class iterator
	{
		friend class MultiList<T_ref>;

	public:
		~iterator();

		bool operator==(iterator const& other) const;

		bool operator!=(iterator const& other) const;

		iterator& operator++();

		Cell& operator*() const;

		Cell* operator->() const;

	private:
		iterator();
		iterator(MultiList<T_ref> &list, T_key key, Cell *cell);

		MultiList<T_ref> &m_list;
		T_key const m_key;
		Cell *m_cell, *m_next;
	};

};

#include "MultiList.tpp"

#endif	/* MULTILIST_H */