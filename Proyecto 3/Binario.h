
#ifndef _BINARIO_H
#define	_BINARIO_H
#include "NodoBinario.h"
#include "Pila.h"
#include <sstream>
#include <cmath>

using namespace std;

class Binario{
public:
    pNodoBinario raiz;

    Binario():raiz(NULL){}
	
	//double evaluar(pNodoBinario raiz);
	void InsertaNodo(int pCodPasillo,string nombre);
    pNodoBinario InsertaNodo(pNodoBinario i, pNodoBinario r, pNodoBinario d);
    void PreordenI();
	string InordenI(string resultado);
    string InordenR2(pNodoBinario R, string resultado);
    void InordenR(pNodoBinario raiz);
    void InordenRAA(pNodoBinario raiz, int pCodPasillo, int pCodProducto);
    void PreordenR(pNodoBinario raiz);
    void PostordenR(NodoBinario *R);
    bool Vacio(NodoBinario *r) { return r==NULL; };
    void PostordenI();
    void InsertarProductos(pNodoBinario raiz, int pCodPasillo, int pCodProducto, string pNombre);
    void InsertarMarcas(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca, string pNombre, int pCantidadGondola, int precio);
    void InsertarInventarios(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca, string pNombre, int pCantidadStock, int CodCanasta);
    bool BuscarPasillo(pNodoBinario raiz, int pCodPasillo);
    bool BuscarProducto(pNodoBinario raiz, int pCodPasillo, int direccion);
    bool BuscarProductoC(pNodoBinario raiz, int pCodPasillo, int pCodProducto);
    bool BuscarPasillo2(pNodoBinario raiz, int pCodPasillo);
    bool BuscarMarcaC(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca);
    int BuscarPrecio(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca);
    int BuscarCB(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca);
    int buscarGondola(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca);
    string devolverNombrePas(pNodoBinario raiz, int pCodPasillo, string resultado);
    int BuscarStock(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca);
    void ModificarStock(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca, int CantidadStock);
	string BuscarProducto1(pNodoBinario raiz, int pCodPasillo);
	
	void BorrarPasillo(NodoBinario *raiz, NodoBinario * raizArbol, int pCodPasillo);
	void Borrar(NodoBinario *raiz, NodoBinario *raizArbol, int pCodPasillo);
	NodoBinario * EncontrarMayorDeLosMenores(NodoBinario * raiz);
	NodoBinario * BuscarNodo(NodoBinario *raizArbol, int pCodPasillo);
	void BuscarPasilloBorrar(NodoBinario* raiz, NodoBinario* raizArbol, int pCodPasillo, int pCodProducto);

    /*
    void PostordenI();
	void Equilibrar1(NodoBinario* n, bool Hh);
	void Equilibrar2(NodoBinario* n, bool Hh);
	void InsertarBalanceado(pNodoBinario &ra, bool &Hh, int x);
	void RotacionDobleIzquierda(NodoBinario* &n, NodoBinario* &n1);
	void RotacionDobleDerecha(NodoBinario* &n, NodoBinario* &n1);
	void RotacionSimpleDerecha(NodoBinario* &n, NodoBinario* &n1);
	void RotacionSimpleIzquierda(NodoBinario* &n, NodoBinario* &n1);
	void Mostrar();
	void InordenRAVL(NodoBinario *R);
	
    bool Hh;
    */

};

//funciones
void Binario::BuscarPasilloBorrar(NodoBinario* raiz, NodoBinario* raizArbol, int pCodPasillo, int pCodProducto) {
	if (raiz == NULL) {
		cout << "Pasillo no encontrado!" << endl;
		return;
	}
	if (raiz->CodPasillo < pCodPasillo) {
		BuscarPasilloBorrar(raiz->Hizq, raizArbol, pCodPasillo, pCodProducto);
	}
	else if (raiz->CodPasillo > pCodPasillo) {
		BuscarPasilloBorrar(raiz->Hder, raizArbol, pCodPasillo, pCodProducto);
	}
	else if (raiz->CodPasillo == pCodPasillo) {
		bool Hh = false;
		raiz->avl.BorrarBalanceado(raiz->avl.raiz, Hh, pCodPasillo);
	}
}

string Binario::BuscarProducto1(pNodoBinario raiz, int pCodPasillo) {
	if (raiz != NULL) {
		if (pCodPasillo < raiz->CodPasillo) {
			raiz = raiz->Hder;
			return BuscarProducto1(raiz, pCodPasillo);
		}
		else if (pCodPasillo > raiz->CodPasillo) {
			raiz = raiz->Hizq;
			return BuscarProducto1(raiz, pCodPasillo);
		}
		else {
			return raiz->avl.InordenRAVL(raiz->avl.raiz,"");
		}
	}
}

void Binario::BorrarPasillo(NodoBinario *raiz, NodoBinario * raizArbol, int pCodPasillo){
	if(raiz == NULL){
		cout<<"Pasillo no encontrado!"<<endl;
		return;
	}
	if(raiz->CodPasillo < pCodPasillo){
		BorrarPasillo(raiz->Hizq, raizArbol, pCodPasillo);
	}else if(raiz->CodPasillo > pCodPasillo){
		BorrarPasillo(raiz->Hder, raizArbol, pCodPasillo);
	}else if(raiz->CodPasillo == pCodPasillo){
		Borrar(raiz, raizArbol, pCodPasillo);
	}	
}

void Binario::Borrar(NodoBinario *raicita, NodoBinario *raizArbol, int pCodPasillo){
	//si el que se borra es una hoja
	if(raicita->Hder == NULL && raicita->Hizq == NULL){
		NodoBinario * aux = BuscarNodo(raizArbol, pCodPasillo);
		if(aux->Hder == raicita){
			aux->Hder = raicita->Hder;
			delete raicita;
		}else if(aux->Hizq == raicita){
			aux->Hizq = raicita->Hder;
			delete raicita;
		}
	//si el que se borra tiene un hijo
	}else if(raicita->Hizq != NULL && raicita->Hder == NULL){
		NodoBinario *aux = BuscarNodo(raizArbol, pCodPasillo);
		if(aux->Hder == raicita){
			aux->Hder = raicita->Hizq;
			delete raicita;
		}else if(aux->Hizq == raicita){
			aux->Hizq = raicita->Hizq;
			delete raicita;
		}else if(aux == raicita){
			if(aux->Hder != NULL){
				raiz = raicita->Hder;
				delete aux;
			}else if(aux->Hizq != NULL){
				raiz = raicita->Hizq;
				delete aux;
			}
		}		
	}else if(raicita->Hizq == NULL && raicita->Hder != NULL){	
		NodoBinario *aux = BuscarNodo(raizArbol, pCodPasillo);
		if(aux->Hder == raicita){
			aux->Hder = raicita->Hder;
			raicita = NULL;
			delete raicita;
		}else if(aux->Hizq == raicita){
			aux->Hizq = raicita->Hder;
			raicita = NULL;
			delete raicita;
		}else if(aux == raicita){
			if(aux->Hder != NULL){
				raiz = raicita->Hder;
				aux = NULL;
				delete aux;
			}else if(aux->Hizq != NULL){
				raiz = raicita->Hizq;
				aux = NULL;
				delete aux;
			}
		}
	//si el que se borra tiene 2 hijos		
	}else{
		NodoBinario *aux = BuscarNodo(raizArbol, pCodPasillo); //Nodo antecesor al que se borra
		NodoBinario *raizAux = EncontrarMayorDeLosMenores(raiz->Hizq);
		if(aux->Hizq == raicita){
			raizAux->Hder = raicita->Hder;
			raicita->Hder = raizAux;
			NodoBinario * auxiliarcito = BuscarNodo(raizArbol, raizAux->CodPasillo);
			if(auxiliarcito != raicita){
				if(auxiliarcito->Hder == raizAux){
					auxiliarcito->Hder = raizAux->Hizq;
				}
				else if(auxiliarcito->Hizq == raizAux){
					auxiliarcito->Hizq = raicita->Hizq;
				}
			}
			aux->Hizq = raizAux;
			raicita = NULL;
			delete raicita;
		}else if(aux->Hder == raicita){
			raizAux->Hder = raicita->Hder;
			raicita->Hder = raizAux;
			NodoBinario * auxiliarcito = BuscarNodo(raizArbol, raizAux->CodPasillo);
			if(auxiliarcito != raicita){
				if(auxiliarcito->Hder == raizAux){
					auxiliarcito->Hder = raizAux->Hizq;
				}
				else if(auxiliarcito->Hizq == raizAux){
					auxiliarcito->Hizq = raicita->Hizq;
				}
			}
			aux->Hder = raizAux;
			raicita = NULL;
			delete raicita;
		}
	}	
}

NodoBinario * Binario::EncontrarMayorDeLosMenores(NodoBinario * raiz){
	while(raiz->Hder->Hder != NULL){
		raiz = raiz->Hder;
	}
	if(raiz->Hder->Hder == NULL){
		if(raiz->Hder != NULL){
			NodoBinario * aux = raiz->Hder;
			raiz->Hder = raiz->Hder->Hder;
			raiz = aux;
		}
	}
	return raiz;
}

NodoBinario * Binario::BuscarNodo(NodoBinario *raizArbol, int pCodPasillo){
	if(raizArbol->CodPasillo < pCodPasillo){
		if(raizArbol->Hizq->CodPasillo == pCodPasillo){
			return raizArbol;
		}else{
			BuscarNodo(raizArbol->Hizq, pCodPasillo);
		}
	}else if(raizArbol->CodPasillo > pCodPasillo){
		if(raizArbol->Hder->CodPasillo == pCodPasillo){
			return raizArbol;
		}else{
			BuscarNodo(raizArbol->Hder, pCodPasillo);
		}
	}else{
		if(raizArbol->CodPasillo == pCodPasillo){
			return raizArbol;
		}
	}
}

 void Binario::PostordenR(NodoBinario *R){ //se cambió el izq y der del cod original

    if(R==NULL){
        return;
    }else{
        PostordenR(R->Hder);
        PostordenR(R->Hizq);
        cout<<R->CodPasillo <<" <-> ";
    }
}

void Binario::InsertaNodo(int pCodPasillo, string nombre )
{
    if(raiz==NULL){
        raiz = new NodoBinario(pCodPasillo, nombre);
    }else{
        raiz->InsertaBinario(pCodPasillo, nombre);
    }
}


void Binario::PreordenI(){
    NodoBinario *Act = raiz;
    Pila p;
    while(p.Vacia()==false || (Act!=NULL)){
        if(Act!=NULL){
            cout<<Act->CodPasillo<<" <-> ";
            p.Push(Act);
            Act = Act->Hizq;
        }else{
            Act=p.Pop();
            Act=Act->Hder;
        }
    }
}

string Binario::InordenI(string resultado) {
	NodoBinario* Act = raiz;
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


void Binario::PostordenI(){
    NodoBinario *Act = raiz;
    Pila p;
    Pila p2;
    while(!p.Vacia() || Act!=NULL){
        if(Act!=NULL){
            p2.Push(new NodoBinario(Act->CodPasillo, Act->Nombre));            
            p.Push(Act);
            Act = Act->Hder;
        }else{            
            Act=p.Pop();
            Act = Act->Hizq;
        }
    }
    while(!p2.Vacia()){
        NodoBinario *salida=p2.Pop();
        cout<<salida->CodPasillo<<" - ";
    }
}

void Binario::PreordenR(NodoBinario *R){
    
    if(R==NULL){
        return;
    }else{
        cout<<R->CodPasillo<<" <-> ";
        PreordenR(R->Hder);
        PreordenR(R->Hizq);
    }
}

string Binario::InordenR2(pNodoBinario R, string resultado) { //se cambió el izq y der del cod original
	if (R != NULL) {
		try {
			return InordenR2(R->Hder, resultado);
		}
		catch (...) {
			cout << "Error en inordenR der" << endl;
		}
		try {
			int pCodPasillo= R->CodPasillo;
			return resultado+=  "\n Numero de pasillo: " + to_string(pCodPasillo) + "   Nombre de pasillo: " + R->Nombre + "";
		}
		catch (...) {
			cout << "Error en inordenR raiz" << endl;
		}
		try {
			return InordenR2(R->Hizq, resultado);
		}
		catch (...) {
			cout << "Error en inordenR izq" << endl;
		}
	}
	return resultado;
}

void Binario::InordenR(pNodoBinario R){ //se cambió el izq y der del cod original
    if(R==NULL){
        return;
    }else{
    	try{
			InordenR(R->Hder);
		}catch(...){
			cout<<"Error en inordenR der"<<endl;
		}
		try{
			cout<<endl<<"Numero de pasillo: "<<R->CodPasillo<<"   Nombre de pasillo: "<<R->Nombre<< "";
		}catch(...){
			cout<<"Error en inordenR raiz"<<endl;
		}
		try{
			InordenR(R->Hizq);
		}catch(...){
			cout<<"Error en inordenR izq"<<endl;
		}
    }
}

void Binario::InordenRAA(pNodoBinario raiz, int pCodPasillo, int pCodProducto){
	if(raiz != NULL){
		if(pCodPasillo < raiz->CodPasillo){
			raiz=raiz->Hder;
			InordenRAA(raiz, pCodPasillo, pCodProducto);
		}
		else if(pCodPasillo > raiz->CodPasillo){
			raiz=raiz->Hizq;
			InordenRAA(raiz, pCodPasillo, pCodProducto);
		}
		else{
			//raiz->avl.InordenRAA(raiz->avl.raiz, pCodProducto);
		}	
	}
}

void Binario::InsertarProductos(pNodoBinario raiz, int pCodPasillo, int pCodProducto, string pNombre){
	if(raiz != NULL){
		if(pCodPasillo < raiz->CodPasillo){
			raiz=raiz->Hder;
			InsertarProductos(raiz, pCodPasillo, pCodProducto, pNombre);
		}
		else if(pCodPasillo > raiz->CodPasillo){
			raiz=raiz->Hizq;
			InsertarProductos(raiz, pCodPasillo, pCodProducto, pNombre);
		}
		else{
			raiz->avl.InsertarBalanceado(raiz->avl.raiz, raiz->avl.Hh, pCodPasillo, pCodProducto, pNombre);
		}	
	}
}

void Binario::InsertarMarcas(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca, string pNombre, int pCantidadGondola, int precio){
	if(raiz != NULL){
		if(pCodPasillo < raiz->CodPasillo){
			raiz=raiz->Hder;
			InsertarMarcas(raiz, pCodPasillo, pCodProducto, pCodMarca, pNombre, pCantidadGondola, precio);
		}
		else if(pCodPasillo > raiz->CodPasillo){
			raiz=raiz->Hizq;
			InsertarMarcas(raiz, pCodPasillo, pCodProducto, pCodMarca, pNombre, pCantidadGondola, precio);
		}
		else{
			raiz->avl.InsertarMarcas(raiz->avl.raiz, pCodPasillo, pCodProducto, pCodMarca, pNombre, pCantidadGondola, precio);
		}	
	}
}

void Binario::InsertarInventarios(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca, string pNombre, int pCantidadStock, int CodCanasta){
	if(raiz != NULL){
		if(pCodPasillo < raiz->CodPasillo){
			raiz=raiz->Hder;
			InsertarInventarios(raiz, pCodPasillo, pCodProducto, pCodMarca, pNombre, pCantidadStock, CodCanasta);
		}
		else if(pCodPasillo > raiz->CodPasillo){
			raiz=raiz->Hizq;
			InsertarInventarios(raiz, pCodPasillo, pCodProducto, pCodMarca, pNombre, pCantidadStock, CodCanasta);
		}
		else{
			raiz->avl.InsertarInventarios(raiz->avl.raiz, pCodPasillo, pCodProducto, pCodMarca, pNombre, pCantidadStock, CodCanasta);
		}	
	}
}

bool Binario::BuscarPasillo(pNodoBinario raiz, int pCodPasillo){
	bool encontrado = false;
	if(raiz != NULL){
		if(pCodPasillo < raiz->CodPasillo){
			raiz=raiz->Hder;
			return BuscarPasillo(raiz, pCodPasillo);
		}
		else if(pCodPasillo > raiz->CodPasillo){
			raiz=raiz->Hizq;
			return BuscarPasillo(raiz, pCodPasillo);
		}
		else{
			encontrado = true;
			return encontrado;
		}
	}
	return encontrado;
}

bool Binario::BuscarProducto(pNodoBinario raiz, int pCodPasillo, int direccion) {
	int pCodProductito;
	if (raiz != NULL) {
		if (pCodPasillo < raiz->CodPasillo) {
			raiz = raiz->Hder;
			return BuscarProducto(raiz, pCodPasillo, direccion);
		}
		else if (pCodPasillo > raiz->CodPasillo) {
			raiz = raiz->Hizq;
			return BuscarProducto(raiz, pCodPasillo, direccion);
		}
		else {
			switch (direccion) {
			case 1:
				raiz->avl.InordenRAVL(raiz->avl.raiz,"");
				break;
			case 2:
				raiz->avl.InordenRAVL(raiz->avl.raiz,"");
				cout << endl << endl;
				cout << "Por favor ingrese el codigo del producto que desea visualizar: ";
				cin >> pCodProductito;
				raiz->avl.BuscarMarca(raiz->avl.raiz, pCodProductito, 1);
				break;
			case 3:
				raiz->avl.InordenRAVL(raiz->avl.raiz,"");
				cout << endl << endl;
				cout << "Por favor ingrese el codigo del producto que desea visualizar: ";
				cin >> pCodProductito;
				raiz->avl.BuscarMarca(raiz->avl.raiz, pCodProductito, 2);
				break;
			case 4:
				raiz->avl.InordenRAVL(raiz->avl.raiz,"");
				cout << endl << endl;
				cout << "Por favor ingrese el codigo del producto que desea visualizar: ";
				cin >> pCodProductito;
				raiz->avl.BuscarMarca(raiz->avl.raiz, pCodProductito, 3);
				break;
			case 5:
				raiz->avl.InordenRAVL(raiz->avl.raiz,"");
				cout << endl << endl;
				cout << "Por favor ingrese el codigo del producto que desea agregar: ";
				cin >> pCodProductito;
				raiz->avl.BuscarMarca(raiz->avl.raiz, pCodProductito, 4);
				break;
			}
		}
	}
	else {
		return false;
	}
}


int Binario::BuscarPrecio(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca){
	if(raiz != NULL){
		if(pCodPasillo < raiz->CodPasillo){
			raiz=raiz->Hder;
			return BuscarPrecio(raiz, pCodPasillo, pCodProducto, pCodMarca);
		}
		else if(pCodPasillo > raiz->CodPasillo){
			raiz=raiz->Hizq;
			return BuscarPrecio(raiz, pCodPasillo, pCodProducto, pCodMarca);
		}
		else{
			return raiz->avl.BuscarPrecio(raiz->avl.raiz, pCodProducto, pCodMarca);			
		}
	}
}

int Binario::BuscarCB(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca){
	if(raiz != NULL){
		if(pCodPasillo < raiz->CodPasillo){
			raiz=raiz->Hder;
			BuscarCB(raiz, pCodPasillo, pCodProducto, pCodMarca);
		}
		else if(pCodPasillo > raiz->CodPasillo){
			raiz=raiz->Hizq;
			BuscarCB(raiz, pCodPasillo, pCodProducto, pCodMarca);
		}
		else{
			return raiz->avl.BuscarCB(raiz->avl.raiz, pCodProducto, pCodMarca);			
		}
	}
}

bool Binario::BuscarPasillo2(pNodoBinario p, int pCodPasillo){
	bool encontrado = false;
	if(p != NULL){
		if(pCodPasillo < p->CodPasillo){
			p=p->Hder;
			BuscarPasillo2(p, pCodPasillo);
		}
		else if(pCodPasillo > p->CodPasillo){
			p=p->Hizq;
			BuscarPasillo2(p, pCodPasillo);
		}
		else{
			if(p->avl.Vacio(p->avl.raiz)){
				cout<<"No hay productos en este pasillo "<<endl;
			}else{
				p->avl.InordenRAVL(p->avl.raiz,"");
				encontrado = true;
			}	
			return encontrado;
		}
	}
}

bool Binario::BuscarProductoC(pNodoBinario raiz, int pCodPasillo, int pCodProducto){
	bool resultado=false;
	if(raiz != NULL){
		if(pCodPasillo < raiz->CodPasillo){
			raiz=raiz->Hder;
			return BuscarProductoC(raiz, pCodPasillo, pCodProducto);
		}
		else if(pCodPasillo > raiz->CodPasillo){
			raiz=raiz->Hizq;
			return BuscarProductoC(raiz, pCodPasillo, pCodProducto);
		}
		else{
			//cout<<"Valor de raiz: "<< raiz->avl.raiz->CodProducto <<endl<<endl;
			resultado= raiz->avl.BuscarProducto2(raiz->avl.raiz, pCodProducto);
			//cout<<endl<<endl<<"Resultado: "<<resultado;
			return resultado;
		}
	}
	return resultado;
}

bool Binario::BuscarMarcaC(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca){
	bool resultado;
	if(raiz != NULL){
		if(pCodPasillo < raiz->CodPasillo){
			raiz=raiz->Hder;
			return BuscarMarcaC(raiz, pCodPasillo, pCodProducto, pCodMarca);
		}
		else if(pCodPasillo > raiz->CodPasillo){
			raiz=raiz->Hizq;
			return BuscarMarcaC(raiz, pCodPasillo, pCodProducto, pCodMarca);
		}
		else{
			resultado= raiz->avl.BuscarMarcaC(raiz->avl.raiz, pCodProducto, pCodMarca);
			return resultado;
		}
	}
}

int Binario::buscarGondola(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca){
	int resultado;
	if(raiz != NULL){
		if(pCodPasillo < raiz->CodPasillo){
			raiz=raiz->Hder;
			buscarGondola(raiz, pCodPasillo, pCodProducto, pCodMarca);
		}
		else if(pCodPasillo > raiz->CodPasillo){
			raiz=raiz->Hizq;
			buscarGondola(raiz, pCodPasillo, pCodProducto, pCodMarca);
		}
		else{
			resultado= raiz->avl.BuscarGondola(raiz->avl.raiz, pCodProducto, pCodMarca);
			return resultado;
		}
	}
}

int Binario::BuscarStock(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca){
	int resultado;
	if(raiz != NULL){
		if(pCodPasillo < raiz->CodPasillo){
			raiz=raiz->Hder;
			BuscarStock(raiz, pCodPasillo, pCodProducto, pCodMarca);
		}
		else if(pCodPasillo > raiz->CodPasillo){
			raiz=raiz->Hizq;
			BuscarStock(raiz, pCodPasillo, pCodProducto, pCodMarca);
		}
		else{
			resultado= raiz->avl.BuscarStock(raiz->avl.raiz, pCodProducto, pCodMarca);
			return resultado;
		}
	}
}

void Binario::ModificarStock(pNodoBinario raiz, int pCodPasillo, int pCodProducto, int pCodMarca, int CantidadStock){
	if(raiz != NULL){
		if(pCodPasillo < raiz->CodPasillo){
			raiz=raiz->Hder;
			ModificarStock(raiz, pCodPasillo, pCodProducto, pCodMarca, CantidadStock);
		}
		else if(pCodPasillo > raiz->CodPasillo){
			raiz=raiz->Hizq;
			ModificarStock(raiz, pCodPasillo, pCodProducto, pCodMarca, CantidadStock);
		}
		else{
			raiz->avl.ModificarStock(raiz->avl.raiz, pCodProducto, pCodMarca, CantidadStock);
		}
	}
}
string Binario::devolverNombrePas(pNodoBinario aux, int pCodPasillo, string resultado){
	resultado="Codigo pasillo inexistente";
	if(aux != NULL){
		if(pCodPasillo < aux->CodPasillo){
			aux=aux->Hder;
			return devolverNombrePas(aux,pCodPasillo, resultado);
		}
		else if(pCodPasillo > aux->CodPasillo){
			aux=aux->Hizq;
			return devolverNombrePas(aux,pCodPasillo, resultado);
		}
		else{
			
			cout<<"resultado: "<<aux->Nombre<<endl;
			return aux->Nombre;
		}
	}else{
		cout<<"Problemas "<<endl;
	}
	return resultado;
}


#endif	/* _BINARIO_H */

