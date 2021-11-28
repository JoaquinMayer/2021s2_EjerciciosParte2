#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

struct NodoListaPosInt {
	int dato;
	NodoListaPosInt* sig;
	NodoListaPosInt() : dato(0), sig(NULL) {}
	NodoListaPosInt(int d) : dato(d), sig(NULL) {}
};

// FUNCIONES AUXILIARES

// PRE:
// POS: Retorna un puntero a la copia de todos los nodos
NodoListaPosInt* clon(NodoListaPosInt* l) {
	if (l == NULL) return NULL;
	NodoListaPosInt* nuevo = new NodoListaPosInt;
	nuevo->dato = l->dato;
	nuevo->sig = clon(l->sig);
	return nuevo;
}

// PRE:
// POS: Borra todos los nodos
void vaciar(NodoListaPosInt*& l) {
	if (l != NULL) {
		vaciar(l->sig);
		delete l;
		l = NULL;
	}
}

// FIN FUNCIONES AUXILIARES

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
	if (l != NULL && l->largo > 0) {
		if (pos == 0) {
			NodoListaPosInt* borrar = l->ppio;
			l->ppio = l->ppio->sig;
			l->largo--;
			delete borrar;
		}
		else if (pos < l->largo) {
			NodoListaPosInt* aux = l->ppio;
			int contador = 0;
			while (contador < pos - 1) {
				aux = aux->sig;
				contador++;
			}

			NodoListaPosInt* borrar = aux->sig;
			aux->sig = aux->sig->sig;
			l->largo--;
			delete borrar;
		}
	}
}

int elemento(ListaPosInt l, unsigned int pos)
{
	assert(0 <= pos && pos < cantidadElementos(l));
	NodoListaPosInt* aux = l->ppio;
	int contador = 0;

	while (contador < pos) {
		aux = aux->sig;
		contador++;
	}

	return aux->dato;
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
	ListaPosInt clonada = crearListaPosInt();
	clonada->ppio = clon(l->ppio);
	clonada->largo = l->largo;
	return clonada;
}

void destruir(ListaPosInt& l)
{
	vaciar(l->ppio);
	delete l;
	l = NULL;
}


#endif