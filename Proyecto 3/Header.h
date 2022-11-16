#pragma once
#include <iostream>
#include <sstream>
#include <cmath>


using namespace std;

class NodoAA {

public:

    /*
        NodoCliente(string v, NodoCliente *der = NULL, NodoCliente *izq = NULL, NodoCliente *sig=NULL, NodoCliente *ant=NULL):
            Hizq(izq), Hder(der), valor(v), siguiente(sig), anterior(ant){}
    */

    NodoAA(int pCodProducto, int pCodPasillo, int pX, string pNombre, int pCantidadStock, int pCodCanasta, NodoAA* der = NULL, NodoAA* izq = NULL, NodoAA* sig = NULL, NodoAA* ant = NULL) :
        CodProducto(pCodProducto), CodPasillo(pCodPasillo), x(pX), Nombre(pNombre), CantidadStock(pCantidadStock), CodCanasta(pCodCanasta), Hizq(izq), Hder(der), siguiente(sig), anterior(ant) {}


    void InsertaArbolAA(int pCodProducto, int pCodPasillo, int x, string pNombre, int pCantidadStock, int pCodCanasta);

    int CodProducto;
    int CodPasillo;
    int x;
    string Nombre;
    int CantidadStock;
    int CodCanasta;

    NodoAA* Hizq, * Hder, * siguiente, * anterior;

    friend class Pila;
    friend class ArbolAA;

};

typedef NodoAA* pNodoAA;

void PreordenR(NodoAA* R);
void InordenR(NodoAA* R);
void PostordenR(NodoAA* R);



void NodoAA::InsertaArbolAA(int pCodProducto, int pCodPasillo, int pX, string pNombre, int pCantidadStock, int pCodCanasta)
{
    if (pX < x) {
        if (Hder == NULL) {
            Hder = new NodoAA(pCodProducto, pCodPasillo, pX, pNombre, pCantidadStock, pCodCanasta);
        }
        else {
            Hder->InsertaArbolAA(pCodProducto, pCodPasillo, pX, pNombre, pCantidadStock, pCodCanasta);
        }
    }
    else {
        if (Hizq == NULL) {
            Hizq = new NodoAA(pCodProducto, pCodPasillo, pX, pNombre, pCantidadStock, pCodCanasta);
        }
        else {
            Hizq->InsertaArbolAA(pCodProducto, pCodPasillo, pX, pNombre, pCantidadStock, pCodCanasta);
        }
    }
}



class ArbolAA {
public:
    pNodoAA raiz;

    ArbolAA() :raiz(NULL) {}

    //double evaluar(pNodoCliente raiz);
    void insertar(int pCodProducto, int pCodPasillo, int pX, string pNombre, int pCantidadStock, int pCodCanasta);
    void PreordenI();
    //string InordenI(string resultado);
    void InordenR(pNodoAA raiz);
    void PreordenR(pNodoAA raiz);
    void PostordenR(pNodoAA R);
    bool Vacio(pNodoAA r) { return r == NULL; };
    void PostordenI();
    int BuscarCB(pNodoAA raiz, int pCedula);
    int BuscarStock(pNodoAA raiz, int pCantidadStock);
    void ModificarStock(pNodoAA raiz, int pCodMarca, int pCantidadStock);
    string devolverNombre(int pCedula);

    void BorrarInventario(pNodoAA raiz, pNodoAA  raizArbol, int pCodPasillo);
    void Borrar(pNodoAA raicita, pNodoAA raizArbol, int pCodPasillo);
    pNodoAA EncontrarMayorDeLosMenores(pNodoAA raiz);
    pNodoAA BuscarNodo(pNodoAA raizArbol, int pCodPasillo);

};

void ArbolAA::BorrarInventario(pNodoAA raiz, pNodoAA  raizArbol, int pCodPasillo) {
    if (raiz == NULL) {
        cout << "Pasillo no encontrado!" << endl;
        return;
    }
    if (raiz->CodPasillo < pCodPasillo) {
        BorrarInventario(raiz->Hizq, raizArbol, pCodPasillo);
    }
    else if (raiz->CodPasillo > pCodPasillo) {
        BorrarInventario(raiz->Hder, raizArbol, pCodPasillo);
    }
    else if (raiz->CodPasillo == pCodPasillo) {
        Borrar(raiz, raizArbol, pCodPasillo);
    }
}

void ArbolAA::Borrar(pNodoAA raicita, pNodoAA raizArbol, int pCodPasillo) {
    //si el que se borra es una hoja
    if (raicita->Hder == NULL && raicita->Hizq == NULL) {
        pNodoAA  aux = BuscarNodo(raizArbol, pCodPasillo);
        if (aux->Hder == raicita) {
            aux->Hder = raicita->Hder;
            delete raicita;
        }
        else if (aux->Hizq == raicita) {
            aux->Hizq = raicita->Hder;
            delete raicita;
        }
        //si el que se borra tiene un hijo
    }
    else if (raicita->Hizq != NULL && raicita->Hder == NULL) {
        pNodoAA aux = BuscarNodo(raizArbol, pCodPasillo);
        if (aux->Hder == raicita) {
            aux->Hder = raicita->Hizq;
            delete raicita;
        }
        else if (aux->Hizq == raicita) {
            aux->Hizq = raicita->Hizq;
            delete raicita;
        }
        else if (aux == raicita) {
            if (aux->Hder != NULL) {
                raiz = raicita->Hder;
                delete aux;
            }
            else if (aux->Hizq != NULL) {
                raiz = raicita->Hizq;
                delete aux;
            }
        }
    }
    else if (raicita->Hizq == NULL && raicita->Hder != NULL) {
        pNodoAA aux = BuscarNodo(raizArbol, pCodPasillo);
        if (aux->Hder == raicita) {
            aux->Hder = raicita->Hder;
            raicita = NULL;
            delete raicita;
        }
        else if (aux->Hizq == raicita) {
            aux->Hizq = raicita->Hder;
            raicita = NULL;
            delete raicita;
        }
        else if (aux == raicita) {
            if (aux->Hder != NULL) {
                raiz = raicita->Hder;
                aux = NULL;
                delete aux;
            }
            else if (aux->Hizq != NULL) {
                raiz = raicita->Hizq;
                aux = NULL;
                delete aux;
            }
        }
        //si el que se borra tiene 2 hijos		
    }
    else {
        pNodoAA aux = BuscarNodo(raizArbol, pCodPasillo); //Nodo antecesor al que se borra
        pNodoAA raizAux = EncontrarMayorDeLosMenores(raiz->Hizq);
        if (aux->Hizq == raicita) {
            raizAux->Hder = raicita->Hder;
            raicita->Hder = raizAux;
            pNodoAA  auxiliarcito = BuscarNodo(raizArbol, raizAux->CodPasillo);
            if (auxiliarcito != raicita) {
                if (auxiliarcito->Hder == raizAux) {
                    auxiliarcito->Hder = raizAux->Hizq;
                }
                else if (auxiliarcito->Hizq == raizAux) {
                    auxiliarcito->Hizq = raicita->Hizq;
                }
            }
            aux->Hizq = raizAux;
            raicita = NULL;
            delete raicita;
        }
        else if (aux->Hder == raicita) {
            raizAux->Hder = raicita->Hder;
            raicita->Hder = raizAux;
            pNodoAA auxiliarcito = BuscarNodo(raizArbol, raizAux->CodPasillo);
            if (auxiliarcito != raicita) {
                if (auxiliarcito->Hder == raizAux) {
                    auxiliarcito->Hder = raizAux->Hizq;
                }
                else if (auxiliarcito->Hizq == raizAux) {
                    auxiliarcito->Hizq = raicita->Hizq;
                }
            }
            aux->Hder = raizAux;
            raicita = NULL;
            delete raicita;
        }
    }
}

pNodoAA ArbolAA::EncontrarMayorDeLosMenores(pNodoAA raiz) {
    while (raiz->Hder->Hder != NULL) {
        raiz = raiz->Hder;
    }
    if (raiz->Hder->Hder == NULL) {
        if (raiz->Hder != NULL) {
            pNodoAA  aux = raiz->Hder;
            raiz->Hder = raiz->Hder->Hder;
            raiz = aux;
        }
    }
    return raiz;
}

pNodoAA ArbolAA::BuscarNodo(pNodoAA raizArbol, int pCodPasillo) {
    if (raizArbol->CodPasillo < pCodPasillo) {
        if (raizArbol->Hizq->CodPasillo == pCodPasillo) {
            return raizArbol;
        }
        else {
            BuscarNodo(raizArbol->Hizq, pCodPasillo);
        }
    }
    else if (raizArbol->CodPasillo > pCodPasillo) {
        if (raizArbol->Hder->CodPasillo == pCodPasillo) {
            return raizArbol;
        }
        else {
            BuscarNodo(raizArbol->Hder, pCodPasillo);
        }
    }
    else {
        if (raizArbol->CodPasillo == pCodPasillo) {
            return raizArbol;
        }
    }
}


void ArbolAA::ModificarStock(pNodoAA raiz, int pCodMarca, int pCantidadStock) {
    if (raiz != NULL) {
        if (pCodMarca < raiz->x) {
            raiz = raiz->Hder;
            ModificarStock(raiz, pCodMarca, pCantidadStock);
        }
        else if (pCodMarca > raiz->x) {
            raiz = raiz->Hizq;
            ModificarStock(raiz, pCodMarca, pCantidadStock);
        }
        else {
            raiz->CantidadStock = pCantidadStock;
        }
    }
}

void ArbolAA::PostordenR(pNodoAA R) { //se cambió el izq y der del cod original

    if (R == NULL) {
        return;
    }
    else {
        PostordenR(R->Hder);
        PostordenR(R->Hizq);
        cout << R->x << " <-> ";
    }
}

void ArbolAA::insertar(int pCodProducto, int pCodPasillo, int pX, string pNombre, int pCantidadStock, int pCodCanasta)
{
    if (raiz == NULL) {
        raiz = new NodoAA(pCodProducto, pCodPasillo, pX, pNombre, pCantidadStock, pCodCanasta);
    }
    else {
        raiz->InsertaArbolAA(pCodProducto, pCodPasillo, pX, pNombre, pCantidadStock, pCodCanasta);
    }
}
/*
string ArbolAA::InordenI(string resultado) {
    NodoAA* Act = raiz;
    Pila p;
    bool band = true;
    while (band) {
        while (Act != NULL) {
            p.Push(Act);
            Act = Act->Hder;
        }
        if (!p.Vacia()) {
            Act = p.Pop();
            string holi = to_string(Act->CodPasillo);
            resultado += "Codigo del pasillo: " + holi + " Nombre del pasillo: " + Act->Nombre + "\n";
            Act = Act->Hizq;
        }
        if (p.Vacia() && Act == NULL) {
            break;
        }
    }
    return resultado;
}
*/

void ArbolAA::InordenR(pNodoAA R) { //se cambió el izq y der del cod original
    if (R == NULL) {
        return;
    }
    else {
        try {
            InordenR(R->Hder);
        }
        catch (...) {
            cout << "Error en inordenR der" << endl;
        }
        try {
            cout << endl << "Numero de cedula: " << R->x << "   Nombre del cliente: " << R->Nombre << "";
        }
        catch (...) {
            cout << "Error en inordenR raiz" << endl;
        }
        try {
            InordenR(R->Hizq);
        }
        catch (...) {
            cout << "Error en inordenR izq" << endl;
        }
    }
}

int ArbolAA::BuscarCB(pNodoAA raiz, int pCodCanasta) {
    bool encontrado = false;
    if (raiz != NULL) {
        if (pCodCanasta < raiz->CodCanasta) {
            raiz = raiz->Hder;
            BuscarCB(raiz, pCodCanasta);
        }
        else if (pCodCanasta > raiz->CodCanasta) {
            raiz = raiz->Hizq;
            BuscarCB(raiz, pCodCanasta);
        }
        else {
            int resultado = raiz->CodCanasta;
            return resultado;
        }
    }
}

int ArbolAA::BuscarStock(pNodoAA raiz, int pCantidadStock) {
    bool encontrado = false;
    if (raiz != NULL) {
        if (pCantidadStock < raiz->CantidadStock) {
            raiz = raiz->Hder;
            BuscarCB(raiz, pCantidadStock);
        }
        else if (pCantidadStock > raiz->CantidadStock) {
            raiz = raiz->Hizq;
            BuscarCB(raiz, pCantidadStock);
        }
        else {
            int resultado = raiz->CantidadStock;
            return resultado;
        }
    }
}
