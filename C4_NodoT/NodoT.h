#pragma once
#include <cstddef>
#include <iostream>
template<class T>
class NodoT
{
public:
	T value;
	NodoT* next;
	int index;
	NodoT(T v, int index1) : value(v), index(index1)
	{
		next = NULL;
	}
};