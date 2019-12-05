#pragma once
#include <cstddef>
#include <iostream>
#include <exception>
#include "NodoT.h"

template<class T>
class ListaT{
public:
	NodoT<T>* first;
	NodoT<T>* last;
	int size;
	void push_back(T val);
	void push_front(T val);
	void print();
	void push_at(T val, int index);
	void delete_at(int index); 
	NodoT<T>* get_at(int index); 
	bool search(T val);
	NodoT<T>* Swap(NodoT<T>* it1, NodoT<T>* it2);
	void burbuja();
	void InsertSort();
	ListaT();
	~ListaT();
};

template<class T>
ListaT<T>::ListaT()
{
	first = NULL;
	last = NULL;
	size = 0;
}

template<class T>
ListaT<T>::~ListaT()
{
}

/**
* Agrega un elemento al final de la lista
*
* @param val Es el valor a almacenar el la lista
*/
template<class T>
void ListaT<T>::push_back(T val)
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
* Agrega un elemento al inicio de la lista
*
* @param val Es el valor a almacenar
*/
template<class T>
void ListaT<T>::push_front(T val)
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
* Agrega un elemento en el índice indicado de la lista
*
* @param val Es el valor a almacenar
* @param index Es el índice en el que se debe agregar el nuevo elemento
*/
template<class T>
void ListaT<T>::push_at(T val, int index)
{

	try
	{
		// para realizar esta función, debes agregar el atributo index a la clase Nodo
	// por ende debes actualizar la definición de las funciones push_back y push_front
		NodoT<T>* temp;
		int counter = 0;
		if (first == NULL && index == 0) { // la lista está completamente vacía
			first = new NodoT<T>(val, 0);
			last = first; // el primero y el último son el mismo
			size++;
		}
		else {
			if (first == last) { // sólo hay un elemento en la lista
				if (index == 0)
				{
					push_front(val);
				}
				else if (index == 1)
				{
					push_back(val);
				}
			}
			else { // hay 2 o más elementos en la lista

				if (index >= size)
				{
					return;
				}

				else if (index == 0)
				{
					push_front(val);
				}

				else if (index == size - 1)
				{
					push_back(val);
				}

				else
				{
					NodoT<T>* it = first->next;
					while (it != NULL)
					{

						if ((it->index) == index - 1)
						{
							temp = it->next;
							it->next = new NodoT<T>(val, index);
							it->next->next = temp;
							it->next->next->index++;
							it->next->next->next->index++;
						}


						if (counter > index + 1)
						{
							it->index++;
						}

						it = it->next;
						counter++;
					}
					size++;
				}

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
void ListaT<T>::delete_at(int index)
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
NodoT<T>* ListaT<T>::get_at(int index)
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
bool ListaT<T>::search(T val)
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

/**
* Ordena de mayor a menor los números
*
* @param NULL
* @return NULL
*/
template<class T>
void ListaT<T>::burbuja()
{
	//si temp = NUUL
	//Checar caso first
	//checar caso en medio
	//Checar no cambiar
	try
	{
		NodoT<T>* it = first;
		NodoT<T>* temp = first;
		NodoT<T>* before = first;
		bool swap = true;
		int i = 0;

		while (swap)
		{	
			swap = false;
			while (it->next != NULL)
			{
				i++;
				if ((it->value) > it->next->value)
				{
					swap = true;
					if (it == first)
					{						
						first = it->next;
						NodoT<T>* temp = it->next->next;
						it->next->next = it;
						it->next = temp;
						before = first;
					}

					else
					{
						before->next = it->next;
						NodoT<T>* temp = it->next->next;
						it->next->next = it;
						it->next = temp;
						before = before->next;
					}

				}
				else
				{
					it = it->next;
				}
			}
			it = first;
		}
		std::cout << "Iteraciones: " << i << std::endl;
	}

	
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}


/**
* Ordena de mayor a menor los números
*
* @param NULL
* @return NULL
*/
template<class T>
NodoT<T>* ListaT<T>::Swap(NodoT<T>* it1, NodoT<T>* it2)
{
	if (it1 == first)
	{
		first = it2;
	}
	it1->next = it2->next;
	it2->next = it1;
	return it2;
}

/**
* Ordena de mayor a menor los números
*
* @param NULL
* @return NULL
*/
template<class T>
void ListaT<T>::InsertSort()
{
	NodoT<T>* it_sorted = first;
	NodoT<T>* it_unsorted = first->next;
	NodoT<T>* Mayor = first;

	NodoT<T>* temp = first;
	NodoT<T>* before = first;
}

/**
* Imprime todos los valores de la lista
*
*/
template <class T>
void ListaT<T>::print() {
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