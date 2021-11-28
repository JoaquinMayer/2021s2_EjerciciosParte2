#include "DiccionarioInt.h"

#ifdef DICCIONARIO_INT_IMP

struct NodoDiccionarioInt {
	int dato;
	NodoDiccionarioInt* sig;
	NodoDiccionarioInt(int d) : dato(d), sig(NULL) {}
};

// FUNCIONES AUXILIARES

//PRE:
//POS:
// PRE:
// POS: Agrega el dato creando un nuevo nodo
void agregar(NodoDiccionarioInt*& d, int dato) {
	if (d == NULL) {
		d = new NodoDiccionarioInt(dato);
	}
	else { 
		agregar(d->sig, dato);
	}
}

// FIN FUNCIONES AUXILIARES

struct _cabezalDiccionarioInt {
	/*NodoDiccionarioInt* ppio;
	unsigned int largo;*/
};


DiccionarioInt crearDiccionarioInt(unsigned int esperados) {
	
	/*DiccionarioInt d = new _cabezalDiccionarioInt();
	d->ppio = NULL;
	d->largo = 0;
	return d;*/
}

void agregar(DiccionarioInt& d, int e) {
	// NO IMPLEMENTADO
}

void borrar(DiccionarioInt& d, int e) {
	// NO IMPLEMENTADO
}

bool pertenece(DiccionarioInt d, int e) {
	// NO IMPLEMENTADO
	return false;
}

int elemento(DiccionarioInt d) {
	/*assert(!esVacio(d));*/
	// NO IMPLEMENTADO
	return 0;
}

bool esVacio(DiccionarioInt d) {
	/*return d->largo == 0;*/
	return true;
}

unsigned int cantidadElementos(DiccionarioInt d) {
	//return d->largo;
	return 0;
}

DiccionarioInt clon(DiccionarioInt d) {
	// NO IMPLEMENTADO
	return NULL;
}

void destruir(DiccionarioInt& d) {
	// NO IMPLEMENTADO
}


#endif