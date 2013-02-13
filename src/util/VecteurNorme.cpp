#include "util/VecteurNorme.h"

VecteurNorme::VecteurNorme(const float x, const float y) : Vecteur(x, y)
{
	Vecteur::normer();
}

VecteurNorme::VecteurNorme(const float angle) : Vecteur(cos(angle), sin(angle)) { }

VecteurNorme::VecteurNorme(const Vecteur& p) : Vecteur(p)
{
	Vecteur::normer();
}

VecteurNorme::VecteurNorme(const VecteurNorme& p) : Vecteur(p) { }

VecteurNorme::~VecteurNorme() { }

VecteurNorme VecteurNorme::operator= (const VecteurNorme& c)
{
	x = c.x;
	y = c.y;
	return *this; //inutile de tester si &c==this : cas rare et sans bug.
}

VecteurNorme VecteurNorme::operator= (const Vecteur& c)
{
	x = c.x;
	y = c.y;
	Vecteur::normer();
	return *this; //inutile de tester si &c==this : cas rare et sans bug.
}

Vecteur operator| (const Vecteur& incident, const VecteurNorme& droite)
{
	Vecteur incident_(incident);
	return incident_ |= droite;
}

Vecteur operator>> (const Vecteur& incident, const VecteurNorme& droite)
{
	Vecteur incident_(incident);
	return incident_ >>= droite;
}

Vecteur operator<< (const VecteurNorme& droite, const Vecteur& incident)
{
	Vecteur incident_(incident);
	return incident_ >>= droite;
}

Vecteur Vecteur::operator|= (const VecteurNorme& droite)
{
	float facteur = droite.x * x + droite.y*y;
	x = facteur * droite.x;
	y = facteur * droite.y;
	return *this;
}

Vecteur Vecteur::operator>>= (const VecteurNorme& droite)
{
	float facteur = 2.0f * (droite.x * x + droite.y * y);
	x = facteur * droite.x - x;
	y = facteur * droite.y - y;
	return *this;
}

float operator^ (const VecteurNorme& a, const Vecteur& b)
{
	float cosAB = a * b / b.norme();
	if ((a & b) >= 0.0f)
	{
		return acos(cosAB);
	}
	else
	{
		return -acos(cosAB);
	}
}

float operator^ (const Vecteur& a, const VecteurNorme& b)
{
	float cosAB = a * b / a.norme();
	if ((a & b) >= 0.0f)
	{
		return acos(cosAB);
	}
	else
	{
		return -acos(cosAB);
	}
}

float operator^ (const VecteurNorme& a, const VecteurNorme& b)
{
	float cosAB = a*b;
	if ((a & b) >= 0.0f)
	{
		return acos(cosAB);
	}
	else
	{
		return -acos(cosAB);
	}
}

VecteurNorme VecteurNorme::rotation(const float a) const
{
	float cosA = cos(a);
	float sinA = sin(a);
	return Vecteur(x * cosA - y*sinA, x * sinA + y * cosA);
}
