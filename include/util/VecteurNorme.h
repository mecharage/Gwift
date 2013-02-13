#ifndef VECTEURNORME_H
#define VECTEURNORME_H

#include "Vecteur.h"

class VecteurNorme : public Vecteur
{
public:

	VecteurNorme(float x, float y);
	VecteurNorme(float angle = 0.0f);
	VecteurNorme(const Vecteur& v);
	VecteurNorme(const VecteurNorme& v);

	virtual ~VecteurNorme();

	//Opérateur de recopie / d'affectation//
	VecteurNorme operator=(const Vecteur& c);
	VecteurNorme operator=(const VecteurNorme& c);

	//Ajoute le vecteur a à cette instance de VecteurNorme, puis le renorme//
	VecteurNorme operator+=(const Vecteur a);
	//Soustrait le vecteur a à cette instance de VecteurNorme, puis le renorme//
	VecteurNorme operator-=(const Vecteur a);
	//Multiplie cette instance de Vecteur par le signe du scalaire d//
	VecteurNorme operator*=(const float d);
	//Multiplie cette instance de Vecteur par le signe du scalaire d//
	VecteurNorme operator/=(const float d);

	//Projection orthogonale du vecteur incident sur la droite de vecteur directeur "droite" normé//
	friend Vecteur operator|(const Vecteur& incident, const VecteurNorme& droite);
	//Réflexion du vecteur incident par rapport à la droite de vecteur directeur "droite" normé//
	friend Vecteur operator>>(const Vecteur& incident, const VecteurNorme& droite);
	friend Vecteur operator<<(const VecteurNorme& droite, const Vecteur& incident);

	//Norme de cette instance, c'est à dire 1.0//
	float norme() const;
	//Renvoie la norme au carré, c'est à dire 1.0//
	float normeCarre() const;
	//Ne fait rien//
	VecteurNorme normer();

	//Angle orienté de a vers b en radians//
	friend float operator^ (const VecteurNorme& a, const Vecteur& b);
	friend float operator^ (const Vecteur& a, const VecteurNorme& b);
	friend float operator^ (const VecteurNorme& a, const VecteurNorme& b);
	//Renvoie sans le modifier cette instance de VecteurNorme, à laquelle on a appliquée la rotation d'angle a, en radian//
	VecteurNorme rotation(const float a) const;
	//Renvoie sans la modifier cette instance de VecteurNorme, à laquelle on a appliquée la rotation
	//	d'angle représenté par le vecteur normé v.//
	VecteurNorme rotation(const VecteurNorme& v) const;

	//Modifie cette instance de manière à prendre l'opposé de l'angle qu'elle représente (~calcul du conjugué)//
	VecteurNorme inverserAngle();
	//Renvoie le VecteurNorme représentant opposé de son angle (~renvoie son conjugué)//
	VecteurNorme angleInverse() const;

};


///////////////////////////////////////////////////////////////////////////////////////////////
// inline implementations des méthodes les plus simples, cette classe étant très bas niveau. //
///////////////////////////////////////////////////////////////////////////////////////////////

inline VecteurNorme VecteurNorme::operator +=(const Vecteur a)
{
	x += a.x;
	y += a.y;
	Vecteur::normer();
	return *this;
}

inline VecteurNorme VecteurNorme::operator -=(const Vecteur a)
{
	x -= a.x;
	y -= a.y;
	Vecteur::normer();
	return *this;
}

inline VecteurNorme VecteurNorme::operator *=(const float d)
{
	if(d < 0.0f)
	{
		x = -x;
		y = -y;
	}
	return *this;
}

inline VecteurNorme VecteurNorme::operator /=(const float d)
{
	if(d < 0.0f)
	{
		x = -x;
		y = -y;
	}
	return *this;
}

inline bool operator||(const VecteurNorme& a, const VecteurNorme& b)
{
	return(a.x == b.y || a.y == b.x);
}

inline bool operator&&(const VecteurNorme& a, const VecteurNorme& b)
{
	return(a.x == b.x || a.x == -b.x);

}

inline float VecteurNorme::norme() const
{
	return 1.0f;
}

inline float VecteurNorme::normeCarre() const
{
	return 1.0f;

}

inline VecteurNorme VecteurNorme::normer()
{
	return *this;
}

inline Vecteur Vecteur::rotation(const VecteurNorme& v) const
{
	return Vecteur(x * v.x - y * v.y, x * v.y + y * v.x);
}

inline VecteurNorme VecteurNorme::rotation(const VecteurNorme& v) const
{
	return Vecteur(x * v.x - y * v.y, x * v.y + y * v.x);
}

inline VecteurNorme VecteurNorme::inverserAngle()
{
	y = -y;
	return *this;
}

inline VecteurNorme VecteurNorme::angleInverse() const
{
	return VecteurNorme(x, -y);
}

#endif // VECTEURNORME_H
