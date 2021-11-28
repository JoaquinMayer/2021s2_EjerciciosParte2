#include "PilaInt.h"

#ifdef PILA_INT_IMP

struct NodoPilaInt {
	int dato;
	NodoPilaInt* sig;
};

struct _cabezalPilaInt {
	NodoPilaInt* ppio;
	unsigned int cantidadElementos;
};

PilaInt crearPilaInt() 
{
	PilaInt p = new _cabezalPilaInt;
	p->ppio = NULL;
	p->cantidadElementos = 0;
	return p;
}

void push(PilaInt& p, int e) {
	NodoPilaInt* nuevo = new NodoPilaInt;
	nuevo->dato = e;
	nuevo->sig = p->ppio;
	p->ppio = nuevo;
	p->cantidadElementos++;
}

int top(PilaInt p) {
	assert(!esVacia(p));
	return p->ppio->dato;
}

void pop(PilaInt& p) {
	assert(!esVacia(p));
	NodoPilaInt* borrar = p->ppio;
	p->ppio = p->ppio->sig;
	delete borrar;
	p->cantidadElementos--;
}

unsigned int cantidadElementos(PilaInt p) {
	return p->cantidadElementos;
}

bool esVacia(PilaInt p) {
	return p->cantidadElementos == 0;
}

NodoPilaInt* clon(NodoPilaInt* p) {
	if (p == NULL) return NULL;
	NodoPilaInt* nuevo = new NodoPilaInt;
	nuevo->dato = p->dato;
	nuevo->sig = clon(p->sig);
	return nuevo;
}

PilaInt clon(PilaInt p) {
	PilaInt cabezal = new _cabezalPilaInt;
	cabezal->ppio = clon(p->ppio);
	cabezal->cantidadElementos = p->cantidadElementos;
	return cabezal;
}

void destruir(PilaInt& p) {
	while (!esVacia(p)) {
		pop(p);
	}

	delete p;
	p = NULL;
}


#endif