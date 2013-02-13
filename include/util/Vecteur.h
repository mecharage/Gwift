//////////////////////////////////////////////////////////////////////////////////////////////////////
// Classe		: Vecteur / Point																	//
// Description	: Classe représentant un point ou un vecteur défini dans un espace à 2 dimensions.	//
//					Elle définit en outre de nombreux opérateurs applicables aux vecteurs.			//
// Version		: 1.1																				//
// Auteur(s)	: Daniel LACHAL																			//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef VECTEUR_H
#define VECTEUR_H

#include <cmath>
#include <iostream>

using namespace std;

class VecteurNorme;

class Vecteur
{
	//Alias permettant d'utiliser indiféremment le nom Point ou Vecteur//
	typedef Vecteur Point;

public:

	//Coordonnées du point ou du vecteur//
	//  Elles sont publiques afin de simplifier la syntaxe, et qu'elles n'ont nullement besoin d'être protégées.//
	float x, y;

	//Constructeur à partir des coordonnées//
	Vecteur(float x = 0.0f, float y = 0.0f);
	//Constructeur de recopie//
	Vecteur(const Vecteur&);
	//Destructeur par défaut (ne fait rien)//
	virtual ~Vecteur();

	//Opérateur de recopie / d'affectation//
	Vecteur operator=(const Vecteur& c);

	//Teste l'égalité de 2 vecteurs (par comparaison de chaque coordonnées)//
	friend bool operator ==(const Vecteur& a, const Vecteur& b);
	//Teste l'inégalité de 2 vecteurs (par comparaison de chaque coordonnées)//
	friend bool operator !=(const Vecteur& a, const Vecteur& b);

	//Inversion du vecteur (par opposition de chacune de ses coordonnées)//
	friend Vecteur operator-(const Vecteur& a);
	//Addition de 2 vecteurs, ou d'un vecteur et d'un point d'origine//
	friend Vecteur operator+(const Vecteur& a, const Vecteur& b);
	//Soustraction de 2 vecteurs ou de 2 points, idéal pour trouver le vecteur défini par un segment de 2 points//
	friend Vecteur operator-(const Vecteur& a, const Vecteur& b);
	//Multiplication d'un vecteur par un scalaire//
	friend Vecteur operator*(const Vecteur& a, const float d);
	//Multiplication d'un vecteur par un scalaire//
	friend Vecteur operator*(const float d, const Vecteur& a);
	//Division d'un vecteur par un scalaire//
	friend Vecteur operator/(const Vecteur& a, const float d);

	//Ajoute le vecteur a à cette instance de Vecteur//
	Vecteur operator+=(const Vecteur a);
	//Soustrait le vecteur a à cette instance de Vecteur//
	Vecteur operator-=(const Vecteur a);
	//Multiplie cette instance de Vecteur par le scalaire d//
	Vecteur operator*=(const float d);
	//Divise cette instance de Vecteur par le scalaire d//
	//  Précondition : d != 0
	Vecteur operator/=(const float d);

	//Renvoie le vecteur orthogonal (dans le sens direct) au vecteur a//
	//  Utilisez "-!a" ou "!-a" pour le vecteur orthogonal dans le sens indirect.//
	friend Vecteur operator!(const Vecteur& a);

	//Les vecteurs sont-ils orthogonaux ?//
	friend bool operator||(const Vecteur& a, const Vecteur& b);
	//Les vecteurs sont-ils colinéaires ?//
	friend bool operator&&(const Vecteur& a, const Vecteur& b);
	//Produit scalaire//
	friend float operator*(const Vecteur& a, const Vecteur& b);
	//Déterminant des 2 vecteurs//
	friend float operator&(const Vecteur& a, const Vecteur& b);


	//////////////////////////////////////////////////////////
	// Projection orthogonale et réflexion sur une droite : //
	//////////////////////////////////////////////////////////

	//Projection orthogonale du vecteur incident sur la droite de vecteur directeur "droite"//
	friend Vecteur operator|(const Vecteur& incident, const Vecteur& droite);
	//Projection orthogonale de cette instance sur la droite de vecteur directeur "droite"//
	Vecteur operator|=(const Vecteur& droite);
	Vecteur operator|=(const VecteurNorme& droite);
	//Réflexion du vecteur incident par rapport à la droite de vecteur directeur "droite"//
	friend Vecteur operator>>(const Vecteur& incident, const Vecteur& droite);
	friend Vecteur operator<<(const Vecteur& droite, const Vecteur& incident);
	//Réflexion de cette instance par rapport à la droite de vecteur directeur "droite"//
	Vecteur operator>>=(const Vecteur& droite);
	Vecteur operator>>=(const VecteurNorme& droite);


	//Distance entre 2 points (cad la norme du vecteur ab)//
	static float distance(const Point& a, const Point& b); //distance entre  2 points

	//Norme de cette instance de Vecteur (dans le cas d'un point, son module)//
	float norme() const;
	//Renvoie la norme au carré. Plus rapide que norme.//
	//  Utilisez-le si des simplifications sont possible dans les calculs//
	float normeCarre() const;
	//Norme cette instance de Vecteur//
	//  Précondition : ne normez pas le vecteur nul !
	Vecteur normer();

	//Angle du vecteur par rapport à l'horizontal (ou argument du point) en radian//
	float angle() const;

	//Angle orienté de a vers b en radians//
	friend float operator^ (const Vecteur& a, const Vecteur& b);
	//Renvoie sans le modifier cette instance de Vecteur, à laquelle on a appliquée la rotation d'angle a, en radian//
	Vecteur rotation(const float a) const;
	//Renvoie sans la modifier cette instance de Vecteur, à laquelle on a appliquée la rotation
	//	d'angle représenté par le vecteur normé v.//
	Vecteur rotation(const VecteurNorme& v) const;

	//Renvoie sans la modifier cette instance de Vecteur, à la norme de laquelle on a ajouter v, sans modifier la direction//
	//  Précondition : n'accélérez pas le vecteur nul !
	Vecteur accelerer(const float v) const;

	friend ostream& operator<<(ostream& os, Vecteur& p); //affichage des coordonnées (debug only !)
};
typedef Vecteur Point;


///////////////////////////////////////////////////////////////////////////////////////////////
// inline implementations des méthodes les plus simples, cette classe étant très bas niveau. //
///////////////////////////////////////////////////////////////////////////////////////////////

inline bool operator ==(const Vecteur& a, const Vecteur& b)
{
	return a.x == b.x && a.y == b.y;
}

inline bool operator !=(const Vecteur& a, const Vecteur& b)
{
	return a.x != b.x || a.y != b.y;
}

inline Vecteur operator-(const Vecteur& a)
{
	return Vecteur(-a.x, -a.y);
}

inline Vecteur operator +(const Vecteur& a, const Vecteur& b)
{
	return Vecteur(a.x + b.x, a.y + b.y);
}

inline Vecteur operator -(const Vecteur& a, const Vecteur& b)
{
	return Vecteur(a.x - b.x, a.y - b.y);
}

inline Vecteur operator *(const Vecteur& a, const float d)
{
	return Vecteur(a.x * d, a.y * d);
}

inline Vecteur operator *(const float d, const Vecteur& a)
{
	return Vecteur(a.x * d, a.y * d);
}

inline Vecteur operator /(const Vecteur& a, const float d)
{
	return Vecteur(a.x / d, a.y / d);
}

inline Vecteur Vecteur::operator +=(const Vecteur a)
{
	x += a.x;
	y += a.y;
	return *this;
}

inline Vecteur Vecteur::operator -=(const Vecteur a)
{
	x -= a.x;
	y -= a.y;
	return *this;
}

inline Vecteur Vecteur::operator *=(const float d)
{
	x *= d;
	y *= d;
	return *this;
}

inline Vecteur Vecteur::operator /=(const float d)
{
	x /= d;
	y /= d;
	return *this;
}

inline Vecteur operator!(const Vecteur& a)
{
	return Vecteur(-a.y, a.x);
}

inline bool operator||(const Vecteur& a, const Vecteur& b)
{
	return a.x * b.x + a.y * b.y == 0.0f;
}

inline bool operator&&(const Vecteur& a, const Vecteur& b)
{
	return a.x * b.y == a.y * b.x;
}

inline float operator*(const Vecteur& a, const Vecteur& b)
{
	return a.x * b.x + a.y * b.y;
}

inline float operator&(const Vecteur& a, const Vecteur& b)
{
	return a.x * b.y - a.y * b.x;
}

inline float Vecteur::norme() const
{
	return sqrt(x * x + y * y);
}

inline float Vecteur::normeCarre() const
{
	return x * x + y*y;
}

inline Vecteur Vecteur::normer()
{
	float norme = sqrt(x * x + y * y);
	x /= norme;
	y /= norme;
	return *this;
}

inline float Vecteur::angle() const
{
	return atan2(y, x);
}

#endif // VECTEUR_H
