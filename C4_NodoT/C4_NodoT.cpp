//Programa que contiene las clases Nodo, Lista, Stack y Queue hecho con Templates
//
// Created by Carlo Andrés Hinojosa Relión (WoWPerro) on 17/10/19.
// Copyright © 2019 Carlo Andrés Hinojosa Relión (WoWPerro). All rights reserved.
//

#include <iostream>
#include "ListaT.h"
#include "StackT.h"
#include "Queue.h"
#include "TreeB.h"
#include "NodoG.h"
#include "Grafo.h"

int main()
{
	ListaT<int> listaT;
	listaT.push_back(0);
	listaT.push_back(1);
	listaT.push_back(2);
	listaT.push_front(3);
	listaT.push_front(4);
	listaT.push_front(5);
	listaT.push_at(6, 0);
	listaT.push_at(7, 3);
	listaT.push_at(8, 7);
	listaT.push_at(9, 8);
	listaT.delete_at(0);
	listaT.delete_at(listaT.size - 1);
	listaT.delete_at(2);
	listaT.push_back(10);
	listaT.push_back(13);
	listaT.push_back(12);
	listaT.push_back(11);
	listaT.push_back(17);
	listaT.push_back(0);
	
	listaT.print();
	std::cout << "At 0: (" << listaT.get_at(0)->index << ", " << listaT.get_at(0)->value << ")" << std::endl;
	std::cout << "At 3: (" << listaT.get_at(3)->index << ", " << listaT.get_at(3)->value << ")" << std::endl;
	std::cout << "At Size - 1: (" << listaT.get_at(listaT.size - 1)->index << ", " << listaT.get_at(listaT.size - 1)->value << ")" << std::endl;
	std::cout << "Size: " << listaT.size << std::endl;
	std::cout << "Hay un 1? " << listaT.search(1) << std::endl;
	std::cout << "Hay un 0? " << listaT.search(0) << std::endl;
	//listaT.burbuja();
	listaT.print();

	std::cout << std::endl;

	ListaT<char> listacharT;
	listacharT.push_back('a');
	listacharT.push_back('b');
	listacharT.push_back('c');
	listacharT.push_front('d');
	listacharT.push_front('e');
	listacharT.push_front('f');
	listacharT.push_at('F', 0);
	listacharT.push_at('F', 7);
	listacharT.print();

	//===================================================================
	std::cout << std::endl;

	StackT<int> stack;
	stack.push_front(0);
	stack.push_front(1);
	stack.push_front(2);
	stack.push_front(3);
	stack.get_at(0);
	stack.pop();
	stack.print();

	//====================================================================
	std::cout << std::endl;

	Queue<int> queue;
	queue.push_back(0);
	queue.push_back(1);
	queue.push_back(2);
	queue.push_back(3);
	queue.push_back(4);
	queue.push_back(5);
	queue.push_back(6);
	queue.get_at(0);
	queue.pop();
	queue.print();

	//==================================================
	std::cout << std::endl;
	std::cout << "Burbuja" << std::endl;
	ListaT<int> burb;
	burb.push_back(7);
	burb.push_back(6);
	burb.push_back(5);
	burb.push_back(4);
	burb.push_back(3);
	burb.push_back(2);
	burb.push_back(1);
	//burb.burbuja();
	burb.print();

	//==================================================
	std::cout << std::endl;
	std::cout << "Insert Sort" << std::endl;
	ListaT<int> insrt;
	insrt.push_back(5);
	insrt.push_back(8);
	insrt.push_back(14);
	insrt.push_back(2);
	insrt.push_back(8);
	insrt.push_back(6);
	insrt.push_back(0);
	insrt.InsertSort();
	insrt.print();

	//========================================		
	TreeB<int> TreeBalanced;

	TreeBalanced.insert(50);
	TreeBalanced.insert(75);
	TreeBalanced.insert(25);
	TreeBalanced.find(25);
	TreeBalanced.print();

	std::cout << std::endl;
	std::cout << std::endl;
	//======================================================
	std::cout << "GRAFO================================================" << std::endl;
	Grafo<int> GRAFO;
	NodoG<int>* first = new NodoG<int>(3);
	NodoG<int>* second = new NodoG<int>(111);

	GRAFO.insertaNodo(9, first);
	GRAFO.insertaNodo(0, first);
	GRAFO.insertaNodo(1, first);
	GRAFO.insertaNodo(2, first);
	GRAFO.insertaNodo(3, first);
	GRAFO.insertaNodo(2, second);
	GRAFO.insertaNodo(5, second);
	
	
	GRAFO.insertaNodo(second, first);

	std::cout << "Comprobar que funciona 2 veces seguidas el print===========" << std::endl;
	GRAFO.imprimeGrafo();
	std::cout << std::endl << "---------------------------" << std::endl;
	GRAFO.imprimeGrafo();

	//GRAFO.buscaNodo(5);

	GRAFO.eliminaNodo(1);
	std::cout << std::endl << "---------------------------" << std::endl;
	GRAFO.imprimeGrafo();
}