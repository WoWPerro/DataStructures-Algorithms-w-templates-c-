#pragma once
#include <cstddef>
#include <iostream>
#include <exception>
#include "NodoT.h"

template<class T>
class StackT {
public:
	NodoT<T>* first;
	NodoT<T>* last;
	int size;
	void push_front(T val);
	void print();
	NodoT<T>* pop();
	NodoT<T>* get_at(int index);
	bool search(T val);
	StackT();
	~StackT();
};

template<class T>
StackT<T>::StackT()
{
	first = NULL;
	last = NULL;
	size = 0;
}

template<class T>
StackT<T>::~StackT()
{
}

/**
* Agrega un elemento al principo (first)
*
* @param val Es el valor a agregar
*/
template<class T>
void StackT<T>::push_front(T val)
{

	try
	{
		NodoT<T>* temp;
		if (first == NULL) { // la lista está completamente vacía
			first = new NodoT<T>(val, 0);
			last = first; // el primero y el último son el mismo
			size++;
		}
		else {
			if (first == last) { // sólo hay un elemento en la lista
				temp = first;
				first = new NodoT<T>(val, 0);
				first->next = temp;
				last = temp;
				last->index++;
			}
			else { // hay 2 o más elementos en la lista
				temp = first;
				first = new NodoT<T>(val, 0);
				first->next = temp;
				NodoT<T>* it = first->next; // se crea un "iterador"
				while (it != NULL) { // si el iterador no es nulo...
					it->index++;
					it = it->next; // se actualiza el iterador por el siguiente nodo en la lista
					// si it->next es null, entonces it será null, y se detendrá el While.
				}
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
* Imprime los datos
*/
template <class T>
void StackT<T>::print() {
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

/**
* Elimina el último del Stack
*
* @return devuelve el NodoT<T> eliminado
*/
template <class T>
NodoT<T>* StackT<T>::pop() {

	NodoT<T>* temp = first;
	first = first->next;
	size--;

	NodoT<T>* it = first; // se crea un "iterador"
	while (it != NULL) { // si el iterador no es nulo...
		it->index--; // imprime el valor del iterador
		it = it->next; // se actualiza el iterador por el siguiente nodo en la Stack
		// si it->next es null, entonces it será null, y se detendrá el While.
	}
	return temp;
}


/**
* Obtiene el elemento del stack en el índice especificado
*
* @param index Es el índice del elemento que se desea obtener
* @return devuelve el apuntador al nodo en el índice indicado, si sólo si es un índice válido
*/
template<class T>
NodoT<T>* StackT<T>::get_at(int index)
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
* buscae el elemento del stack
*
* @param val Es el valor del elemento que se desea buscar
* @return devuelve un bool 1 si lo encontro 0 si no
*/
template<class T>
bool StackT<T>::search(T val)
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