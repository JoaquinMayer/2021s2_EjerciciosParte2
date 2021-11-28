#include "Ejercicios.h"

void recorrerInOrder(NodoABInt* a, ListaOrdInt& lista)
{
	if (a != NULL) {
		recorrerInOrder(a->izq, lista);
		agregar(lista, a->dato);
		recorrerInOrder(a->der, lista);
	}
}

ListaOrdInt Enlistar(NodoABInt* a)
{
	ListaOrdInt lista = crearListaOrdInt();
	recorrerInOrder(a, lista);
	return lista;
}

ListaOrdInt UnionListaOrd(ListaOrdInt l1, ListaOrdInt l2)
{
	ListaOrdInt lista1 = crearListaOrdInt();
	lista1 = clon(l1);

	ListaOrdInt lista2 = crearListaOrdInt();
	lista2 = clon(l2);
	
	ListaOrdInt lista = crearListaOrdInt();

	while (!esVacia(lista1) || !esVacia(lista2)) {

		if (esVacia(lista2)) {
			agregar(lista, minimo(lista1));
			borrarMinimo(lista1);
		}
		else if (esVacia(lista1)) {
			agregar(lista, minimo(lista2));
			borrarMinimo(lista2);
		}
		else if (minimo(lista1) < minimo(lista2)) {
			agregar(lista, minimo(lista1));
			borrarMinimo(lista1);
		}
		else if (minimo(lista1) > minimo(lista2)) {
			agregar(lista, minimo(lista2));
			borrarMinimo(lista2);
		}
		else {
			agregar(lista, minimo(lista1));
			borrarMinimo(lista1);
			agregar(lista, minimo(lista2));
			borrarMinimo(lista2);
		}
	}

	return lista;
}

bool EstaContenida(PilaInt p1, PilaInt p2)
{

	/*PilaInt pila1 = crearPilaInt();
	pila1 = clon(p1);
	
	PilaInt pila2 = crearPilaInt();
	pila2 = clon(p2);

	bool estaContenida = false;

	if (esVacia(pila1)) {
		estaContenida = true;
	}
	else {
		bool seguirChequeando = true;

		int currentValue = top(pila1);

		while (seguirChequeando && !esVacia(pila1) && !esVacia(pila2)) {

			while (!esVacia(pila2)) {
				if (currentValue == top(pila2)) {
					pop(pila1);
				}
				else {
					pop(pila2);
				}
			}

			if (esVacia(pila1)) {
				estaContenida = true;
				seguirChequeando = false;
			}
			else if (currentValue == top(pila1)) {
				estaContenida = false;
				seguirChequeando = false;
			}
			else {
				pila2 = clon(p2);
			}
		}

	}*/

	return true;
}


ListaOrdInt ObtenerRepetidos(MultisetInt m) 
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

MultisetInt Xor(MultisetInt m1, MultisetInt m2)
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

ColaPrioridadInt MenorPrioridad(ColaPrioridadInt c) {
	//IMPLEMENTAR SOLUCION
	return NULL;
}

