#pragma once
#include <cstddef>
#include <iostream>
#include <exception>
#include "NodoT.h"

template<class T>
class Queue {
public:
	NodoT<T>* first;
	NodoT<T>* last;
	int size;
	void push_back(T val);
	void print();
	NodoT<T>* pop();
	NodoT<T>* get_at(int index);
	bool search(T val);
	Queue();
	~Queue();
};

template<class T>
Queue<T>::Queue()
{
	first = NULL;
	last = NULL;
	size = 0;
}

template<class T>
Queue<T>::~Queue()
{
}


/**
* Agrega un elemento al final de la Queue
*
* @param val Es el valor a almacenar el la Queue
*/
template<class T>
void Queue<T>::push_back(T val) {

	try
	{
		if (first == NULL) { // la lista está completamente vacía
			first = new NodoT<T>(val, 0);
			last = first; // el primero y el último son el mismo
		}
		else {
			if (first == last) { // sólo hay un elemento en la lista
				last = new NodoT<T>(val, 1); // last ahora es diferente
				first->next = last; // el siguiente de first ahora es el nuevo nodo
			}
			else { // hay 2 o más elementos en la lista
				last->next = new NodoT<T>(val, (last->index + 1)); // last->next era null, ahora es un nodo
				last = last->next; // last ahora es el nodo nuevo
			}
		}
		size++;
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

/**
* Imprime todos los valores de la Queue
*
*/
template<class T>
void Queue<T>::print() {

	try
	{
		NodoT<T>* it = first; // se crea un "iterador"
		while (it != NULL) { // si el iterador no es nulo...
			std::cout << it->index << ") " << it->value << std::endl; // imprime el valor del iterador
			it = it->next; // se actualiza el iterador por el siguiente nodo en la Queue
			// si it->next es null, entonces it será null, y se detendrá el While.
		}
	}
	catch(...)
	{

	}
	
}

/**
* Elimina el elemento de la Queue en el índice especificado
*
* @param index Es el índice del elemento que se desea eliminar
*/
template<class T>
NodoT<T>* Queue<T>::pop() {

	try
	{
		NodoT<T>* it = first; // se crea un "iterador"
		while (it->index < size - 2) { // si el iterador no es nulo...
			it = it->next;
		}
		NodoT<T>* temp = it->next;
		it->next = NULL;
		last = it;
		size--;
		return temp;
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		return NULL;
	}
}


/**
* Obtiene el elemento de la Queue en el índice especificado
*
* @param index Es el índice del elemento que se desea eliminar
* @return devuelve el apuntador al nodo en el índice indicado, si sólo si es un índice válido
*/
template<class T>
NodoT<T>* Queue<T>::get_at(int index) {
	try
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
bool Queue<T>::search(T val) {
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