#pragma once

#pragma once

#ifndef _LISTA_H
#define	_LISTA_H
#include "Binario.h"
using namespace std;


class Pila {
public:
    Pila() : plista(NULL) {}

    void Push(pnodo v);
    bool Vacia() { return plista == NULL; }
    pnodo Pop();
    int Size();
    void Mostrar();

    pnodo plista;

};

void Pila::Mostrar() {
    if (Vacia()) {
        cout << "Vacia" << endl;
    }
    NodoBinario* aux = plista;
    while (aux != NULL) {
        cout << aux->CodPasillo << " => ";
        aux = aux->siguiente;
    }
}

void Pila::Push(pnodo v)
{
    if (Vacia()) {
        plista = v;
    }
    else {
        NodoBinario* aux = plista;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = v;
        v->anterior = aux;

    }
}

pnodo Pila::Pop()
{
    NodoBinario* borrar;
    NodoBinario* salida;
    if (Vacia()) {
        cout << "Pila Vacia" << endl;
    }
    else {
        borrar = plista;
        while (borrar->siguiente) {
            borrar = borrar->siguiente;
        }
        if (Size() > 1) {
            salida = borrar;
            borrar->anterior->siguiente = NULL;
            borrar = NULL;
            delete borrar;
        }
        else {
            salida = plista;
            plista = NULL;
        }
    }
    return salida;
}

int Pila::Size() {
    while (plista && plista->anterior) plista = plista->anterior;
    int cont = 0;
    NodoBinario* aux;
    aux = plista;
    while (aux) {
        cont++;
        aux = aux->siguiente;
    }
    return cont;
}
#endif	/* _LISTADOBLES_H */
