#pragma once

#pragma once

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class NodoCliente {

public:

    /*
        NodoCliente(string v, NodoCliente *der = NULL, NodoCliente *izq = NULL, NodoCliente *sig=NULL, NodoCliente *ant=NULL):
            Hizq(izq), Hder(der), valor(v), siguiente(sig), anterior(ant){}
    */

    NodoCliente(int pCedula, string pNombre, int pTelefono, string pCorreo, NodoCliente* der = NULL, NodoCliente* izq = NULL, NodoCliente* sig = NULL, NodoCliente* ant = NULL) :
        Nombre(pNombre), Telefono(pTelefono), Correo(pCorreo), Hizq(izq), Hder(der), Cedula(pCedula), siguiente(sig), anterior(ant) {}


    void InsertaArbolC(int pCedula, string pNombre, int pTelefono, string pCorreo);


    int Cedula;
    string Nombre;
    int Telefono;
    string Correo;

    NodoCliente* Hizq, * Hder, * siguiente, * anterior;

    friend class Pila;
    friend class ArbolC;
    friend class MenuPrincipal;

};

typedef NodoCliente* pNodoC;
typedef NodoCliente* pNodoCliente;

void PreordenR(NodoCliente* R);
void InordenR(NodoCliente* R);
void PostordenR(NodoCliente* R);



void NodoCliente::InsertaArbolC(int pCedula, string pNombre, int pTelefono, string pCorreo)
{
    if (pCedula < Cedula) {
        if (Hder == NULL) {
            Hder = new NodoCliente(pCedula, pNombre, pTelefono, pCorreo);
        }
        else {
            Hder->InsertaArbolC(pCedula, pNombre, pTelefono, pCorreo);
        }
    }
    else {
        if (Hizq == NULL) {
            Hizq = new NodoCliente(pCedula, pNombre, pTelefono, pCorreo);
        }
        else {
            Hizq->InsertaArbolC(pCedula, pNombre, pTelefono, pCorreo);
        }
    }
}



class ArbolC {
public:
    pNodoCliente raiz;

    ArbolC() :raiz(NULL) {}

    //double evaluar(pNodoCliente raiz);
    void InsertaNodo(int pCedula, string pNombre, int pTelefono, string pCorreo);
    void PreordenI();
    void InordenI();
    void InordenR(pNodoCliente raiz);
    void PreordenR(pNodoCliente raiz);
    void PostordenR(NodoCliente* R);
    bool Vacio(NodoCliente* r) { return r == NULL; };
    void PostordenI();
    bool BuscarCedula(pNodoCliente raiz, int pCedula);
    string devolverNombre(int pCedula);

	void BorrarPersona(pNodoCliente raiz, pNodoCliente  raizArbol, int pCedula);
	void Borrar(pNodoCliente raicita, pNodoCliente raizArbol, int pCodPasillo);
	pNodoCliente EncontrarMayorDeLosMenores(pNodoCliente raiz);
	pNodoCliente BuscarNodo(pNodoCliente raizArbol, int pCedula);

    /*
    void PostordenI();
    void Equilibrar1(NodoCliente* n, bool Hh);
    void Equilibrar2(NodoCliente* n, bool Hh);
    void InsertarBalanceado(pNodoCliente &ra, bool &Hh, int x);
    void RotacionDobleIzquierda(NodoCliente* &n, NodoCliente* &n1);
    void RotacionDobleDerecha(NodoCliente* &n, NodoCliente* &n1);
    void RotacionSimpleDerecha(NodoCliente* &n, NodoCliente* &n1);
    void RotacionSimpleIzquierda(NodoCliente* &n, NodoCliente* &n1);
    void Mostrar();
    void InordenRAVL(NodoCliente *R);

    bool Hh;
    */

};


void ArbolC::BorrarPersona(pNodoCliente raiz, pNodoCliente  raizArbol, int pCedula) {
	if (raiz == NULL) {
		cout << "Pasillo no encontrado!" << endl;
		return;
	}
	if (raiz->Cedula < pCedula) {
		BorrarPersona(raiz->Hizq, raizArbol, pCedula);
	}
	else if (raiz->Cedula > pCedula) {
		BorrarPersona(raiz->Hder, raizArbol, pCedula);
	}
	else if (raiz->Cedula == pCedula) {
		Borrar(raiz, raizArbol, pCedula);
	}
}

void ArbolC::Borrar(pNodoCliente raicita, pNodoCliente raizArbol, int pCodPasillo) {
	//si el que se borra es una hoja
	if (raicita->Hder == NULL && raicita->Hizq == NULL) {
		pNodoCliente aux = BuscarNodo(raizArbol, pCodPasillo);
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
		pNodoCliente aux = BuscarNodo(raizArbol, pCodPasillo);
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
		pNodoCliente aux = BuscarNodo(raizArbol, pCodPasillo);
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
		pNodoCliente aux = BuscarNodo(raizArbol, pCodPasillo); //Nodo antecesor al que se borra
		pNodoCliente raizAux = EncontrarMayorDeLosMenores(raiz->Hizq);
		if (aux->Hizq == raicita) {
			raizAux->Hder = raicita->Hder;
			raicita->Hder = raizAux;
			pNodoCliente auxiliarcito = BuscarNodo(raizArbol, raizAux->Cedula);
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
			pNodoCliente auxiliarcito = BuscarNodo(raizArbol, raizAux->Cedula);
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

pNodoCliente ArbolC::EncontrarMayorDeLosMenores(pNodoCliente raiz) {
	while (raiz->Hder->Hder != NULL) {
		raiz = raiz->Hder;
	}
	if (raiz->Hder->Hder == NULL) {
		if (raiz->Hder != NULL) {
			pNodoCliente  aux = raiz->Hder;
			raiz->Hder = raiz->Hder->Hder;
			raiz = aux;
		}
	}
	return raiz;
}

pNodoCliente ArbolC::BuscarNodo(pNodoCliente raizArbol, int pCedula) {
	if (raizArbol->Cedula < pCedula) {
		if (raizArbol->Hizq->Cedula == pCedula) {
			return raizArbol;
		}
		else {
			BuscarNodo(raizArbol->Hizq, pCedula);
		}
	}
	else if (raizArbol->Cedula > pCedula) {
		if (raizArbol->Hder->Cedula == pCedula) {
			return raizArbol;
		}
		else {
			BuscarNodo(raizArbol->Hder, pCedula);
		}
	}
	else {
		if (raizArbol->Cedula == pCedula) {
			return raizArbol;
		}
	}
}


void ArbolC::PostordenR(NodoCliente* R) { //se cambió el izq y der del cod original

    if (R == NULL) {
        return;
    }
    else {
        PostordenR(R->Hder);
        PostordenR(R->Hizq);
        cout << R->Cedula << " <-> ";
    }
}

void ArbolC::InsertaNodo(int pCedula, string pNombre, int pTelefono, string pCorreo)
{
    if (raiz == NULL) {
        raiz = new NodoCliente(pCedula, pNombre, pTelefono, pCorreo);
    }
    else {
        raiz->InsertaArbolC(pCedula, pNombre, pTelefono, pCorreo);
    }
}




void ArbolC::InordenR(pNodoCliente R) { //se cambió el izq y der del cod original
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
            cout << endl << "Numero de cedula: " << R->Cedula << "   Nombre del cliente: " << R->Nombre << "";
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

bool ArbolC::BuscarCedula(pNodoCliente raiz, int pCedula) {
    bool encontrado = false;
    if (raiz != NULL) {
        if (pCedula < raiz->Cedula) {
            raiz = raiz->Hder;
            return BuscarCedula(raiz, pCedula);
        }
        else if (pCedula > raiz->Cedula) {
            raiz = raiz->Hizq;
            return BuscarCedula(raiz, pCedula);
        }
        else {
            encontrado = true;
            return encontrado;
        }
    }
    return encontrado;
}

string ArbolC::devolverNombre(int pCedula) {
    string nombre = "";
    if (raiz != NULL) {
        if (pCedula < raiz->Cedula) {
            raiz = raiz->Hder;
            devolverNombre(pCedula);
        }
        else if (pCedula > raiz->Cedula) {
            raiz = raiz->Hizq;
            devolverNombre(pCedula);
        }
        else {
            return raiz->Nombre;
        }
    }
}



