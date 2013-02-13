#include <stdlib.h>
#include <iostream>

#include <list>

#include "util/MultiList.h"

#include "AppContext.h"

int main(int argc, char **argv)
{
	std::cout << "KOUKOU\n";

	AppContext::init();

	AppContext::mainLoop();

	exit(0);
}

/*
template <typename T_ref>
void MultiList<T_ref>::print(T_key key)	//TEMP
{
	Cell *c = m_heads.node(key).m_next;

	while(c != &m_heads)
	{
		std::cout << *(c->m_ref) << std::endl;
		c = c->node(key).m_next;
	}
}*/
/*
void print(MultiList<std::string const>& ml, T_key key)
{
	for(typename MultiList<std::string const>::iterator i = ml.begin(key), e = ml.end(); i!= e; ++i)
		std::cout << i->get() << std::endl;
}

int main(int argc, char **argv)
{
	MultiList<std::string const> ml(2);
	T_key const manger = 1, boire = 2;

	ml.append("Pain").link(manger);
	ml.append("Eau").link(boire);
	ml.append("Nutella").link(manger);
	ml.append("Mandarine").link(manger);
	ml.append("Coca").link(boire);
	ml.append("Café").link(boire);

	std::cout << "Tous :" << std::endl;
	print(ml, GLOBAL_KEY);
	std::cout << "Manger :" << std::endl;
	print(ml, manger);
	std::cout << "Boire :" << std::endl;
	print(ml, boire);

	return 0;
}*/