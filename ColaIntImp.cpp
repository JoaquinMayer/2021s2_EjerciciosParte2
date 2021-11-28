#include "ColaInt.h"

#ifdef COLA_INT_IMP

struct NodoColaInt {
	int dato;
	NodoColaInt* sig;
	NodoColaInt(int d) : dato(d), sig(NULL) {}
};

struct _cabezalColaInt {
	NodoColaInt* ppio;
	NodoColaInt* fin;
	unsigned int largo;
};

ColaInt crearColaInt() {
	ColaInt c = new _cabezalColaInt;
	c->ppio = NULL;
	c->fin = NULL;
	c->largo = 0;
	return c;
}

void encolar(ColaInt& c, int e) {
	NodoColaInt* d = new NodoColaInt(e);

	if (c->fin == NULL) {
		c->ppio = d;
		c->fin = d;
	}
	else {
		c->fin->sig = d;
		c->fin = d;
	}

	c->largo++;
}

int principio(ColaInt c) {
	assert(!esVacia(c));
	return c->ppio->dato;
}

void desencolar(ColaInt& c) {
	assert(!esVacia(c));
	NodoColaInt* borrar = c->ppio;
	c->ppio = c->ppio->sig;
	delete borrar;
	c->largo--;

	if (c->largo == 0) {
		c->fin = NULL;
	}
}

bool esVacia(ColaInt c) {
	return c->largo == 0;
}

unsigned int cantidadElementos(ColaInt c) {
	return c->largo;
}

ColaInt clon(ColaInt c) {
	ColaInt clonada = crearColaInt();
	NodoColaInt* tmp = c->ppio;
	while (tmp != NULL) {
		encolar(clonada, tmp->dato);
		tmp = tmp->sig;
	}
	return clonada;
}

void destruir(ColaInt& c) {
	while (!esVacia(c)) {
		desencolar(c);
	}
	delete c;
	c = NULL;
}

#endif