#pragma once
#include <cstddef>
#include <iostream>
#include <exception>
#include "NodoT.h"

template<class T>
class ListaS
{
public:
	NodoT<T>* first;
	NodoT<T>* last;
	int size = 0;
	void Add(T val);
	void Print();
	void Delete_at(int index);
	void Delete(T*);
	NodoT<T>* Get_at(int index);
	bool Search(T val);
	NodoT<T>* GetNode(NodoT<T>* s);
	int GetNodeIndex(NodoT<T>* s);
	bool Search(NodoT<T>* s);
	T advance(int x);
	//void Delete_at_Value(NodoT<T>* index);
	ListaS();
	~ListaS();
};


template<class T>
ListaS<T>::ListaS()
{
	first = NULL;
	last = NULL;
	size = 0;
}

template<class T>
ListaS<T>::~ListaS()
{
}

/**
* Agrega un elemento al final de la lista
*
* @param val Es el valor a almacenar el la lista
*/
template<class T>
void ListaS<T>::Add(T val)
{
	try
	{
		if (first == NULL)
		{
			first = new NodoT<T>(val, 0);
			last = first;
			size++;
		}
		else {
			if (first == last)
			{
				last = new NodoT<T>(val, 1);
				first->next = last;
				size++;
			}
			else {
				last->next = new NodoT<T>(val, (last->index + 1));
				last = last->next;
				size++;
			}
		}
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

}

/**
* Elimina el elemento de la lista en el índice especificado
*
* @param index Es el índice del elemento que se desea eliminar
*/
template<class T>
void ListaS<T>::Delete_at(int index)
{

	try
	{
		bool pass = false;
		int counter = 0;
		if (first == NULL && index == 0) { // la lista está completamente vacía
			last = first; // el primero y el último son el mismo
		}
		else {
			if (first == last) { // sólo hay un elemento en la lista
				if (index == 0)
				{
					first = NULL;
				}
				else if (index == 1)
				{
					last = NULL;
				}
			}
			else { // hay 2 o más elementos en la lista

				if (index >= size)
				{
					return;
				}

				else
				{
					NodoT<T>* it = first->next;
					while (it != NULL)
					{
						if ((it->index - 1) == index)
						{
							it->next = it->next->next;
						}

						if (counter >= index + 1)
						{
							it->index--;
						}

						it = it->next;
						counter++;
					}
				}


			}
			size--;
		}
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

}


/**
* Obtiene el elemento de la lista en el índice especificado
*
* @param index Es el índice del elemento que se desea eliminar
* @return devuelve el apuntador al nodo en el índice indicado, si sólo si es un índice válido
*/
template<class T>
NodoT<T>* ListaS<T>::Get_at(int index)
{
	try
	{
		if (index == 0)
		{
			return first;
		}

		else if (index == size - 1)
		{
			return last;
		}

		else
		{
			NodoT<T>* it = first->next;
			while (it != NULL)
			{
				if ((it->index) == index)
				{
					return it;
				}
				it = it->next;
			}
		}

		return NULL;
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		return NULL;
	}


}

/**
* Busca el elemento con el valor especificado
*
* @param val Es el valor del elemento que se desea encontrar
*/
template<class T>
bool ListaS<T>::Search(T val)
{
	try
	{
		// Devuelve true en la primera aparición del valor en algún nodo
		NodoT<T>* it = first->next;
		while (it != NULL)
		{
			if ((it->value) == val)
			{
				return true;
			}
			it = it->next;
		}
		return false;
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		return false;
	}

}

template <class T>
void ListaS<T>::Print() {
	try
	{
		NodoT<T>* it = first;
		while (it != NULL)
		{
			std::cout << it->index << ") " << it->value << std::endl;
			it = it->next;
		}
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

}

template <class T>
NodoT<T>* ListaS<T>::GetNode(NodoT<T>* s) 
{
	bool found = false;
	try
	{
		NodoT<T>* it = first;
		while (it != NULL)
		{
			if (it == s)
			{
				found = true;
			}
		}
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	if (found)
	{
		return s;
	}
	else
	{
		return NULL;
	}

}

template <class T>
int ListaS<T>::GetNodeIndex(NodoT<T>* s)
{
	int index = 0;
	bool found = false;
	try
	{
		NodoT<T>* it = first;
		while (it != NULL)
		{
			if ((it->value) == s)
			{
				found = true;
				index = it->index;
			}
			it = it->next;
		}
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	if (found)
	{
		return index;
	}
	else
	{
		return index;
	}
}

template <class T>
bool ListaS<T>::Search(NodoT<T>* s)
{
	bool found = false;
	try
	{
		NodoT<T>* it = first;
		while (it != NULL)
		{
			if (it == s)
			{
				found = true;
			}
		}
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return found;
}

template <class T>
T ListaS<T>::advance(int x)
{
	if (x < size)
	{
	NodoT<T>* it = first;
	bool find = true;
		for (int i = 0; i < x; i++)
		{
			it = it->next;
			find = true;
		}
		if (find)
		{
			return it->value;
		}
	}

	else if (x == size)
	{
		return first->value;
	}
	else
	{
		return nullptr;
	}
}

template <class T>
void ListaS<T>::Delete(T* s)
{
	bool found = false;
	try
	{
		NodoT<T>* it = first;
		while (it != NULL)
		{
			if (it == s)
			{
				found = true;
			}
		}

		if (found)
		{
			s = nullptr;
		}
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}