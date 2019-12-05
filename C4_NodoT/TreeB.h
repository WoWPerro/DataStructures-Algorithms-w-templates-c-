#pragma once
#include "NodoA.h"
#include <stdlib.h>
#include <exception>

template <class T>
class TreeB
{
public:
	NodoA<T>* root;
	NodoA<T>* last; // es recomendable guardar un apuntador hacia el 'ultimo nodo insertado
	TreeB();
	~TreeB();
	void insert(T val); //30% debes colocar el nodo donde va, según las reglas antes definidas
	void deleteN(T val);//30% re-acomoda los nodos hijos del nodo eliminado, según su prioridad
	bool find(T val);/////30% hay dos formas de encontrar nodos, por profundidad y por amplitud
	void print();////30% imprime los nodos de manera que se entienda el orden del árbol.
	void printgood(NodoA<T>* N);
	int height(NodoA<T>* N);
	bool IsBalanced(NodoA<T>* root);
	void LLrotation(NodoA<T>* r);
	void LRrotation(NodoA<T>* r);
	void RRrotation(NodoA<T>* r);
	void RLrotation(NodoA<T>* r);
	char firstM;
	char secondM;
};

template <class T>
TreeB<T>::TreeB()
{
	root = nullptr;
	last = nullptr;
}

template <class T>
TreeB<T>::~TreeB()
{

}

template <class T>
void TreeB<T>::LLrotation(NodoA<T>* r)
{
	try
	{
		bool derecha;
		NodoA<T>* tempd1 = r->der;
		NodoA<T>* tempd2 = r->izq;

		NodoA<T>* temph2 = r->padre;
		NodoA<T>* tempd3 = temph2->der;

		NodoA<T>* temph3 = r->padre->padre;
		NodoA<T>* tempd4 = temph3->der;

		NodoA<T>* before = temph3->padre;
		
		if (before->der == temph3)
		{
			derecha = true;
		}
		else
		{
			derecha = false;
		}

		temph3->padre = temph2;

		temph2->der = temph3;

		temph2->izq = r;

		temph3->der = tempd4;
		temph3->izq = tempd3;

		if (derecha)
		{
			before->der = temph2;
		}
		else
		{
			before->izq = temph2;
		}
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

template <class T>
void TreeB<T>::LRrotation(NodoA<T>* r)
{
	try
	{
		bool derecha;
		NodoA<T>* before = r->padre->padre->padre;
		if (before->der == r)
		{
			derecha = true;
		}
		else
		{
			derecha = false;
		}

		NodoA<T>* temph1 = r->padre;
		NodoA<T>* temph2 = r->padre->padre;

		NodoA<T>* tempd1 = r->der;
		NodoA<T>* tempd2 = r->izq;

		NodoA<T>* tempd3 = r->padre->izq;

		NodoA<T>* tempd4 = r->padre->padre->der;

		//Acomodo
		r->der = temph2;
		r->izq = temph1;
		temph2->izq = tempd1;
		temph1->der = tempd2;

		r->padre = before;
		temph2->padre = r;
		temph1->padre = r;
		tempd1->padre = temph2;
		tempd2->padre = temph1;
		if (derecha)
		{
			before->der = r;
		}
		else
		{
			before->izq = r;
		}
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
}

template <class T>
void TreeB<T>::RRrotation(NodoA<T>* r)
{
	try
	{
		bool derecha;
		NodoA<T>* tempd1 = r->der;
		NodoA<T>* tempd2 = r->izq;

		NodoA<T>* temph2 = r->padre;
		NodoA<T>* tempd3 = temph2->izq;

		NodoA<T>* temph3 = r->padre->padre;
		NodoA<T>* tempd4 = temph3->izq;

		NodoA<T>* before = temph3->padre;

		if (before->der == temph3)
		{
			derecha = true;
		}
		else
		{
			derecha = false;
		}

		temph3->padre = temph2;

		temph2->izq = temph3;

		temph2->der = r;

		temph3->izq = tempd4;
		temph3->der = tempd3;

		if (derecha)
		{
			before->der = temph2;
		}
		else
		{
			before->izq = temph2;
		}
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

template <class T>
void TreeB<T>::RLrotation(NodoA<T>* r)
{
	try
	{
		bool derecha;
		NodoA<T>* before = r->padre->padre->padre;
		if (before != NULL)
		{
			if (before->der == r)
			{
				derecha = true;
			}
			else
			{
				derecha = false;
			}
		}
		

		NodoA<T>* temph1 = r->padre;
		NodoA<T>* temph2 = r->padre->padre;

		NodoA<T>* tempd1 = r->der;
		NodoA<T>* tempd2 = r->izq;

		NodoA<T>* tempd3 = r->padre->der;

		NodoA<T>* tempd4 = r->padre->padre->izq;

		//Acomodo
		r->der = temph1;
		r->izq = temph2;

		temph2->der = tempd2;
		temph1->izq = tempd1;

		temph2->padre = r;
		temph1->padre = r;
		tempd1->padre = temph2;
		tempd2->padre = temph1;

		if (before != nullptr)
		{
			r->padre = before;
			if (derecha)
			{
				before->der = r;
			}
			else
			{
				before->izq = r;
			}
		}
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
}

/**
* Agrega un elemento al final de la Queue
*
* @param val Es el valor a almacenar el la Queue
*/
template <class T>
void TreeB<T>::insert(T val)
{
	if (root == nullptr)
	{
		root = new NodoA<T>(val);
		last = root;
	}
	else if (last == root)
	{
		if (root->obj < val)
		{
			root->izq = new NodoA<T>(val, root);
			root->izq->padre = root;
			last = root->izq;
			firstM = 'L';
		}
		else
		{
			root->der = new NodoA<T>(val, root);
			root->der->padre = root;
			last = root->der;
			firstM = 'R';
		}
	}

	else
	{
		NodoA<T>* it = root;
		NodoA<T>* before = root;
		while (it != nullptr) { 
			if (it->obj < val)
			{
				before = it;
				it = it->izq;
				if (it == nullptr)
				{
					before->izq = new NodoA<T>(val, root);
					before->izq->padre = before;
					if (secondM != 'L' && secondM != 'R')
					{
						secondM = 'L';
					}
					else
					{
						firstM = secondM;
						secondM = 'L';
					}
					if (!IsBalanced(root))
					{
						if (firstM == 'L' && secondM == 'L')
						{
							LLrotation(before->izq);
						}
						else if (firstM == 'R' && secondM == 'L')
						{
							RLrotation(before->izq);
						}
						else if (firstM == 'R' && secondM == 'R')
						{
							RRrotation(before->izq);
						}
						else if (firstM == 'L' && secondM == 'R')
						{
							LRrotation(before->izq);
						}
					}
				}
			}
			else
			{
				before = it;
				it = it->der;
				if (it == nullptr)
				{
					before->der = new NodoA<T>(val, root);
					before->der->padre = before;
					if ((secondM != 'L') && (secondM != 'R'))
					{
						secondM = 'R';
					}
					else
					{
						firstM = secondM;
						secondM = 'R';
					}
					if (!IsBalanced(root))
					{
						if (firstM == 'L' && secondM == 'L')
						{
							LLrotation(before->der);
						}
						else if (firstM == 'R' && secondM == 'L')
						{
							RLrotation(before->der);
						}
						else if (firstM == 'R' && secondM == 'R')
						{
							RRrotation(before->der);
						}
						else if (firstM == 'L' && secondM == 'R')
						{
							LRrotation(before->der);
						}
					}
				}
			}
		}
	}
}


/**
* Agrega un elemento al final de la Queue
*
* @param val Es el valor a almacenar el la Queue
*/
template <class T>
void TreeB<T>::deleteN(T val)
{

}


/**
* Agrega un elemento al final de la Queue
*
* @param val Es el valor a almacenar el la Queue
*/
template <class T>
bool TreeB<T>::find(T val)
{
	NodoA<T>* it = root;
	while (it != nullptr)
	{
		if (it->obj == val)
		{
			return true;
		}
		else if (it->obj > val)
		{
			it = it->der;
		}
		else
		{
			it = it->izq;
		}
	}
	return false;
}


/**
* Agrega un elemento al final de la Queue
*
* @param val Es el valor a almacenar el la Queue
*/
template <class T>
void TreeB<T>::print()
{
	printgood(root);
}


/**
* Agrega un elemento al final de la Queue
*
* @param val Es el valor a almacenar el la Queue
*/
template <class T>
bool TreeB<T>::IsBalanced(NodoA<T>* root)
{
	if (root == nullptr)
	{
		return true;
	}
	
	int lh = height(root->izq);
	int rh = height(root->der);

	if (abs(lh - rh) <= 1) //&& isBalanced(root->left) && isBalanced(root->right))
	{
		return true;
	}
	
	return false;
}

template <class T>
int TreeB<T>::height(NodoA<T>* N)
{
	if (N == nullptr)
	{
		return 0;
	}

	int h = 1 + height(N->izq) + height(N->der);

	return h;
}

template <class T>
void TreeB<T>::printgood(NodoA<T>* N)
{
	if (N == nullptr)
	{
		return;
	}

	for (int i = 0; i < height(N); i++)
	{
		std::cout << "--------------";
	}
	std::cout << N->obj;
	std::cout << std::endl;
	
	printgood(N->izq);
	printgood(N->der);
}