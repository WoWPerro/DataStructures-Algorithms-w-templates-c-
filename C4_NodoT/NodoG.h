#pragma once
#include "ListaS.h"

template <class T>
class NodoG
{
public:
	bool visited = false;
	T nodoData; // Esto guarda el objeto deseado
	ListaS<NodoG<T>*> l; // esto guarda los apuntadores a los hijos
	NodoG<T>(T dat) : nodoData(dat) {}
};