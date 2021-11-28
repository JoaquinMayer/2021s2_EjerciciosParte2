#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

struct NodoListaPosInt {
	int dato;
	NodoListaPosInt* sig;
	NodoListaPosInt(int d) : dato(d), sig(NULL) {}
};

struct _cabezalListaPosInt {
	NodoListaPosInt* ppio;
	unsigned int largo;
};

ListaPosInt crearListaPosInt()
{
	ListaPosInt l = new _cabezalListaPosInt;
	l->ppio = NULL;
	l->largo = 0;
	return l;
}

void agregar(ListaPosInt& l, int e, unsigned int pos)
{
	if (l == NULL) {
		l = crearListaPosInt();
		l->ppio = new NodoListaPosInt(e);
	}
	else if (pos == 0) {
		NodoListaPosInt* nuevo = new NodoListaPosInt(e);
		nuevo->sig = l->ppio;
		l->ppio = nuevo;
	}
	else if (pos >= l->largo) {
		NodoListaPosInt* aux = l->ppio;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}

		NodoListaPosInt* nuevo = new NodoListaPosInt(e);
		aux->sig = nuevo;
	}
	else {
		NodoListaPosInt* aux = l->ppio;
		int contador = 0;
		while (contador < pos - 1) {
			aux = aux->sig;
			contador++;
		}

		NodoListaPosInt* nuevo = new NodoListaPosInt(e);
		nuevo->sig = aux->sig;
		aux->sig = nuevo;
	}

	l->largo++;
}

void borrar(ListaPosInt& l, unsigned int pos)
{
	
}

int elemento(ListaPosInt l, unsigned int pos)
{
	//IMPLEMENTAR SOLUCION
	return 0;
}

bool esVacia(ListaPosInt l)
{
	return l->largo == 0;
}

unsigned int cantidadElementos(ListaPosInt l) {
	return l->largo;
}

ListaPosInt clon(ListaPosInt l)
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

void destruir(ListaPosInt& l)
{
	//IMPLEMENTAR SOLUCION
}


#endif