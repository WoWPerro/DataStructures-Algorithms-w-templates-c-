#pragma once

template <class T>
class NodoA
{
public:
	NodoA<T>* padre;
	NodoA<T>* izq;
	NodoA<T>* der;
	int prio; // prioridad
	T obj;
	NodoA(T v);
	NodoA(T v, NodoA<T>* p);
};

template<class T>
NodoA<T>::NodoA(T v)
{
	obj = v;
	padre = nullptr;
	izq = nullptr;
	der = nullptr;
}

template<class T>
NodoA<T>::NodoA(T v, NodoA<T>* p)
{
	obj = v;
	padre = p;
	izq = nullptr;
	der = nullptr;
}