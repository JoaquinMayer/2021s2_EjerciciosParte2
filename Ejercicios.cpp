#include "Ejercicios.h"


//FUNCIONES AUXILIARES

//PRE: 
//POS: Se agrega el dato del nodo a la lista
void recorrerInOrder(NodoABInt* a, ListaOrdInt& lista)
{
	if (a != NULL) {
		recorrerInOrder(a->izq, lista);
		agregar(lista, a->dato);
		recorrerInOrder(a->der, lista);
	}
}

// PRE:
// POS: Devuelve un booleano si se encuentra o no los items de la pila 1 en la pila 2
bool estaEnPila(PilaInt& pila1, PilaInt pila2) {
	PilaInt aux = pila2;
	if (esVacia(pila1)) {
		return true;
	}
	else if (esVacia(aux)) {
		return false;
	}
	else {
		if (top(pila1) == top(aux)) {
			pop(pila1);
			return true;
		}
		else if (esVacia(aux)) {
			return false;
		}
		else {
			pop(aux);
			estaEnPila(pila1, aux);
		}
	}
}

//FIN FUNCIONES AUXILIARES

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
	PilaInt pila1 = clon(p1);
	PilaInt pila2 = clon(p2);

	bool estaContenida = true;

	while (estaContenida && !esVacia(pila1)) {
		estaContenida = estaEnPila(pila1, pila2);
	}

	return estaContenida;
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
