#include <iostream>
#include "Rojinegro.h"
#include "ArbolAA.h"
#ifndef _NODOBINARIO_H
#define	_NODOBINARIO_H

using namespace std;

class NodoAVL {
	
   public:

    NodoAVL(int pCodPasillo, string nombre, int pCodProducto, NodoAVL *der = NULL, NodoAVL *izq = NULL, NodoAVL *sig=NULL, NodoAVL *ant=NULL):
        Nombre(nombre),Hizq(izq), Hder(der), CodProducto(pCodProducto),CodPasillo(pCodPasillo), siguiente(sig), anterior(ant), FB(0) {}
        
	void InsertaBalanceado(int pCodPasillo, string nombre, int pCodProducto);

    int CodPasillo;
    string Nombre;
    int CodProducto;
    int FB;
	bst rn;
	ArbolAA AA;
    
    
    NodoAVL *Hizq, *Hder, *siguiente, *anterior;

    //friend class Pila;
    friend class ArbolAVL;
    friend class NodoBinario;
    friend class Binario;

};

typedef NodoAVL *pNodoAVL;


class ArbolAVL{
public:
	
    pNodoAVL raiz;

    ArbolAVL():raiz(NULL){}
	
    //void InordenRAVL(pNodoAVL raiz);
	void Equilibrar1(NodoAVL* n, bool Hh);
	void Equilibrar2(NodoAVL* n, bool Hh);
	void InsertarBalanceado(pNodoAVL  &ra, bool &Hh, int pCodPasillo, int pCodProducto, string pNombre);
	void RotacionDobleIzquierda(NodoAVL* &n, NodoAVL* &n1);
	void RotacionDobleDerecha(NodoAVL* &n, NodoAVL* &n1);
	void RotacionSimpleDerecha(NodoAVL* &n, NodoAVL* &n1);
	void RotacionSimpleIzquierda(NodoAVL* &n, NodoAVL* &n1);
	bool Vacio(NodoAVL *r) { return r==NULL; };
	string InordenRAVL(NodoAVL *R,string resultado);
	void InordenRAA(pNodoAVL raiz, int pCodProducto);
	void InsertarMarcas(pNodoAVL raiz, int pCodPasillo, int pCodProducto, int pCodMarca, string pNombre, int pCantidadGondola, int precio);
	void InsertarInventarios(pNodoAVL raiz, int pCodPasillo, int pCodProducto, int pCodMarca, string pNombre, int pCantidadStock, int CodCanasta);
	void BuscarMarca(pNodoAVL raiz, int pCodProducto, int direccion);
	bool BuscarProducto2(pNodoAVL raiz, int pCodProducto);
	bool BuscarMarcaC(pNodoAVL raiz, int pCodProducto, int pCodMarca);
	int BuscarPrecio(pNodoAVL raiz, int pCodProducto, int pCodMarca);
	int BuscarCB(pNodoAVL raiz, int pCodProducto, int pCodMarca);
	int BuscarGondola(pNodoAVL raiz, int pCodProducto, int pCodMarca);
	int BuscarStock(pNodoAVL raiz, int pCodProducto, int pCodMarca);
	void ModificarStock(pNodoAVL raiz, int pCodProducto, int pCodMarca, int CantidadStock);
	void BorrarBalanceado(NodoAVL* &raicita, bool &Hh, int x);
	void Borrar(NodoAVL* &D, bool &Hh, int x);
	NodoAVL * BuscarNodo(NodoAVL *raizArbol, int pCodProducto);

    bool Hh;
    
    
    
};



class NodoBinario {
	
   public:

/*
    NodoBinario(string v, NodoBinario *der = NULL, NodoBinario *izq = NULL, NodoBinario *sig=NULL, NodoBinario *ant=NULL):
        Hizq(izq), Hder(der), valor(v), siguiente(sig), anterior(ant){}
*/       
     
    NodoBinario(int pCodPasillo, string nombre, NodoBinario *der = NULL, NodoBinario *izq = NULL, NodoBinario *sig=NULL, NodoBinario *ant=NULL):
        Nombre(nombre),Hizq(izq), Hder(der), CodPasillo(pCodPasillo), siguiente(sig), anterior(ant), FB(0) {}
        
        
	void InsertaBinario(int pCodPasillo, string nombre);

	
    int CodPasillo;
    string Nombre;
    int FB;
    ArbolAVL avl;
    
    NodoBinario *Hizq, *Hder, *siguiente, *anterior;

    friend class Pila;
    friend class Binario;
    friend class menus;

};

typedef NodoBinario *pnodo;
typedef NodoBinario *pNodoBinario;

void PreordenR(NodoBinario* R);
void InordenR(NodoBinario* R);
void PostordenR(NodoBinario* R);



void NodoBinario::InsertaBinario(int pCodPasillo, string nombre)
{
    if(pCodPasillo<CodPasillo){
        if(Hder==NULL){
            Hder = new NodoBinario(pCodPasillo, nombre);
        }else{
            Hder->InsertaBinario(pCodPasillo, nombre);
        }
    }else{
        if(Hizq==NULL){
            Hizq = new NodoBinario(pCodPasillo, nombre);
        }else{
            Hizq->InsertaBinario(pCodPasillo, nombre);
        }
    }
}

void ArbolAVL::BorrarBalanceado(NodoAVL* &raicita, bool &Hh, int x)
{
    pNodoAVL auxiliarcito = NULL;
    if(raicita != NULL){
        if(x < raicita->CodProducto){
            BorrarBalanceado(raicita->Hizq, Hh, x);
            if(Hh){
                Equilibrar1(raicita, Hh);
            }
        }else{
            if(x > raicita->CodProducto){	
                BorrarBalanceado(raicita->Hder, Hh, x);
                if(Hh){
                    Equilibrar2(raicita, Hh);
                }
            }else{
                auxiliarcito=raicita;
            }
        }
        if(auxiliarcito != NULL){
        	if(auxiliarcito->Hder==NULL){
		        raicita = auxiliarcito->Hizq;
		        Hh=true;
		        auxiliarcito = NULL;
		        delete auxiliarcito;
    		}else{
	            if(auxiliarcito->Hizq==NULL){
	                raicita=auxiliarcito->Hder;
	                Hh = true;
	                auxiliarcito = NULL;
	            	delete auxiliarcito;
	            }else{
	                Borrar(auxiliarcito->Hizq, Hh, x);
	            }
	            if(Hh){
	                Equilibrar1(raicita, Hh);
	            }
    		} 
		}	
    }
}

NodoAVL * ArbolAVL::BuscarNodo(NodoAVL *raizArbol, int pCodProducto){
	if(raizArbol->CodProducto < pCodProducto){
		if(raizArbol->Hizq->CodProducto == pCodProducto){
			return raizArbol;
		}else{
			BuscarNodo(raizArbol->Hizq, pCodProducto);
		}
	}else if(raizArbol->CodProducto > pCodProducto){
		if(raizArbol->Hder->CodProducto == pCodProducto){
			return raizArbol;
		}else{
			BuscarNodo(raizArbol->Hder, pCodProducto);
		}
	}else{
		if(raizArbol->CodProducto == pCodProducto){
			return raizArbol;
		}
	}
}

void ArbolAVL::Borrar(NodoAVL* &D, bool &Hh, int x)
{
    NodoAVL *q = NULL;
    if(D->Hder != NULL){
    	cout<<"Holi"<<D->CodProducto<<endl;
        Borrar(D->Hder, Hh, x);
        if(Hh){
            Equilibrar2(D, Hh);
        }else{
            q=D;
            D=D->Hizq;
            Hh = true;
        }
    }else{
    	q = BuscarNodo(raiz, x); 
        D->Hder = q->Hder;
        if(q == raiz){
        	raiz = D;	
		}
        Hh = true;
        q = NULL;
        delete q;
	}
}

string ArbolAVL::InordenRAVL(NodoAVL *R,string resultado){ //se cambió el izq y der del cod original
    if(R==NULL){
        return resultado;
    }else{
    	try{
			return InordenRAVL(R->Hizq,resultado);
		}catch(...){
			cout<<"Error en inordenR der"<<endl;
		}
		try{
			int CodProducto = R->CodProducto;
			resultado += "\n Numero de producto: " + to_string(CodProducto) + "   Nombre de producto: " + R->Nombre + "";
			return InordenRAVL(R->Hder, resultado);
		}catch(...){
			cout<<"Error en inordenR raiz"<<endl;
		}
		try{
			return InordenRAVL(R->Hder, resultado);
		}catch(...){
			cout<<"Error en inordenR izq"<<endl;
		}
    }
}

void ArbolAVL::InordenRAA(pNodoAVL raiz, int pCodProducto){
	if(raiz != NULL){
		if(pCodProducto > raiz->CodProducto){
			raiz=raiz->Hder;
			InordenRAA(raiz, pCodProducto);
		}
		else if(pCodProducto < raiz->CodProducto){
			raiz=raiz->Hizq;
			InordenRAA(raiz, pCodProducto);
		}
		else{
			return raiz->AA.InordenRAA(raiz->AA.raiz);
		}	
	}
}

void ArbolAVL::Equilibrar1(NodoAVL* n, bool Hh){
    NodoAVL *n1;
    switch (n->FB){
        case -1: n->FB = 0;
        break;
        case 0: n->FB = 1;
        Hh = false;
        break;
        case 1: n1 = n->Hder;
        if(n1->FB>=0){
            if(n1->FB=0){
                Hh = false;
                RotacionSimpleDerecha(n, n1);
            }else{
                RotacionDobleDerecha(n, n1);
            }
        }
    }
}

void ArbolAVL::Equilibrar2(NodoAVL* n, bool Hh){
    NodoAVL *n1;
    switch (n->FB){
        case 1: n->FB = 0;
        break;
        case 0: n->FB = 1;
        Hh = false;
        break;
        case -1: n1 = n->Hizq;
        if(n1->FB<=0){
            if(n1->FB=0){
                Hh = false;
                RotacionSimpleIzquierda(n, n1);
            }else{
                RotacionDobleIzquierda(n, n1);
            }
        }
    }
}


void ArbolAVL::InsertarBalanceado(pNodoAVL  &ra, bool &Hh, int pCodPasillo, int pCodProducto, string pNombre){
	
    pNodoAVL n1;
    
    if(ra==NULL){
    	Hh = true;
        ra=new NodoAVL(pCodPasillo, pNombre, pCodProducto);
    }else{
        if(pCodProducto<ra->CodProducto){
            InsertarBalanceado(ra->Hizq, Hh, pCodPasillo, pCodProducto, pNombre);
	        if(Hh){
	            switch(ra->FB){
	                case 1: ra->FB=0;
		                Hh = false;
		                break;
	                case 0: ra->FB  = -1;
	                	break;
	                case -1: n1=ra->Hizq;
		                if(n1->FB =-1){
		                    RotacionSimpleIzquierda(ra, n1);
		                }else{
		                    RotacionDobleIzquierda(ra,n1);
		                }
		                Hh = false;
		                break;
	            }
	        }
        }else{
            if(pCodProducto>ra->CodProducto){
                InsertarBalanceado(ra->Hder, Hh, pCodPasillo, pCodProducto, pNombre);
                if(Hh){
                    switch(ra->FB){
                        case -1: ra->FB=0;
	                        Hh = false;
	                        break;
                        case 0: ra->FB=1;
                        	break;
                        case 1:n1=ra->Hder;
	                        if(n1->FB=1){
	                            RotacionSimpleDerecha(ra, n1);
	                        }else{
	                            RotacionDobleDerecha(ra, n1);
	                        }
	                        Hh=false;
	                        break;
                    }
                }
            }
        }
    }
}



void ArbolAVL::RotacionDobleIzquierda(NodoAVL* &n, NodoAVL* &n1){
    NodoAVL *n2;
    n2=n1->Hder;
    n->Hizq = n2->Hder;
    n2->Hder=n;
    n1->Hder=n2->Hizq;
    n2->Hizq=n1;

    if(n2->FB==1){
        n1->FB=-1;
    }else{
        n1->FB=0;
    }
    if(n2->FB==-1){
        n->FB=1;
    }else{
        n->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void ArbolAVL::RotacionDobleDerecha(NodoAVL* &n, NodoAVL* &n1){
    NodoAVL *n2;
    n2=n1->Hizq;
    n->Hder = n2->Hizq;
    n2->Hizq=n;
    n1->Hizq=n2->Hder;
    n2->Hder=n1;

    if(n2->FB==1){
        n->FB=-1;
    }else{
        n->FB=0;
    }
    if(n2->FB==-1){
        n1->FB=1;
    }else{
        n1->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void ArbolAVL::RotacionSimpleDerecha(NodoAVL* &n, NodoAVL* &n1){
    n->Hder=n1->Hizq;
    n1->Hizq=n;

    if(n1->FB==1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=1;
        n1->FB=-1;
    }
    n=n1;
}

void ArbolAVL::RotacionSimpleIzquierda(NodoAVL* &n, NodoAVL* &n1){
    n->Hizq=n1->Hder;
    n1->Hder=n;

    if(n1->FB==-1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=-1;
        n1->FB=-1;
    }
    n=n1;
}

void ArbolAVL::InsertarMarcas(pNodoAVL raiz, int pCodPasillo, int pCodProducto, int pCodMarca, string pNombre, int pCantidadGondola, int precio){
	if(raiz != NULL){
		if(pCodProducto > raiz->CodProducto){
			raiz=raiz->Hder;
			InsertarMarcas(raiz, pCodPasillo, pCodProducto, pCodMarca, pNombre, pCantidadGondola, precio);
		}
		else if(pCodProducto < raiz->CodProducto){
			raiz=raiz->Hizq;
			InsertarMarcas(raiz, pCodPasillo, pCodProducto, pCodMarca, pNombre, pCantidadGondola, precio);
		}
		else{
			raiz->rn.insert(pCodPasillo, pCodProducto, pCodMarca, pNombre, pCantidadGondola, precio);
		}	
	}
}

void ArbolAVL::InsertarInventarios(pNodoAVL raiz, int pCodPasillo, int pCodProducto, int pCodMarca, string pNombre, int pCantidadStock, int CodCanasta){
	if(raiz != NULL){
		if(pCodProducto > raiz->CodProducto){
			raiz=raiz->Hder;
			InsertarInventarios(raiz, pCodPasillo, pCodProducto, pCodMarca, pNombre, pCantidadStock, CodCanasta);
		}
		else if(pCodProducto < raiz->CodProducto){
			raiz=raiz->Hizq;
			InsertarInventarios(raiz, pCodPasillo, pCodProducto, pCodMarca, pNombre, pCantidadStock, CodCanasta);
		}
		else{
			raiz->AA.insertar(pCodPasillo, pCodProducto, pCodMarca, pNombre, pCantidadStock, CodCanasta);
		}	
	}
}

void ArbolAVL::BuscarMarca(pNodoAVL raiz, int pCodProducto, int direccion){
	int pCodMarquita;
	if(raiz != NULL){
		if(pCodProducto > raiz->CodProducto){
			raiz=raiz->Hder;
			BuscarMarca(raiz, pCodProducto, direccion);
		}
		else if(pCodProducto < raiz->CodProducto){
			raiz=raiz->Hizq;
			BuscarMarca(raiz, pCodProducto, direccion);
		}
		else{
			switch(direccion){
				case 1:
					raiz->rn.inorder();
					break;
				case 2:
					raiz->rn.inorder();
					cout<<endl<<"Por favor indique el codigo de la marca que desea visualizar el precio: ";
					cin>>pCodMarquita;
					raiz->rn.buscarPrecio(pCodMarquita);
					break;
				case 3:
					raiz->rn.inorder();
					int modificar;
					cout<<endl<<"Por favor indique el codigo de la marca que desea modificar: ";
					cin>>pCodMarquita;
					cout<<endl<<"Por favor digite 1 si desea modificar el nombre, o 2 si desea modificar el precio: ";
					cin>>modificar;
					switch(modificar){
						case 1:
							raiz->rn.modificarNombre(pCodMarquita);
							break;
						case 2:
							raiz->rn.modificarPrecio(pCodMarquita);
							break;
						default:
							cout<<"Por favor ingrese un numero valido!"<<endl;
							break;
					}	
					break;
				case 4:
					int CodPasillo = raiz->CodPasillo;
					int CodProducto = raiz->CodProducto;					
					int CodMarca;
					string Nombre = "";
					int CantidadGondola;
					int CantidadStock;
					int Precio;
					int CodigoCanasta;
					string CodCanasta = "";
					cout<<endl;
					cout<<"Por favor inserte el codigo de la marca que desea registrar: ";
					cin>>CodMarca;
					cout<<endl<<"Por favor inserte el nombre de la marca que desea registrar: ";
					cin>>Nombre;
					cout<<endl<<"Por favor inserte la cantidad en gondola de la marca que desea registrar: ";
					cin>>CantidadGondola;
					cout<<endl<<"Por favor inserte la cantidad en stock de la marca que desea registrar: ";
					cin>>CantidadStock;
					cout<<endl<<"Por favor inserte el precio de la marca que desea registrar: ";
					cin>>Precio;
					cout<<endl<<"El articulo pertenece a la canasta basica? [Y/N]: ";
					cin>>CodCanasta;
					if(CodCanasta == "Y"){
						CodigoCanasta = 2;
					}else if(CodCanasta == "N"){
						CodigoCanasta = 1;
					}else{
						CodigoCanasta = 0;
					}
					switch(CodigoCanasta){
						case 1:
							//caso que no pertenezca
							raiz->rn.insert(CodPasillo, CodProducto, CodMarca, Nombre, CantidadGondola, Precio);
							cout<<endl<<"Articulo ingresado con exito!"<<endl;
							break;
						case 2:
							//caso que pertenezca
							raiz->rn.insert(CodPasillo, CodProducto, CodMarca, Nombre, CantidadGondola, Precio);
							cout<<endl<<"Articulo ingresado con exito!"<<endl;
							break;
						default:
							cout<<"Por favor ingrese un codigo valido!"<<endl;
							BuscarMarca(raiz, pCodProducto, direccion);
					}	
					break;
			}
		}	
	}
}


int ArbolAVL::BuscarPrecio(pNodoAVL raiz, int pCodProducto, int pCodMarca){
	if(raiz != NULL){
		if(pCodProducto > raiz->CodProducto){
			raiz=raiz->Hder;
			return BuscarPrecio(raiz, pCodProducto, pCodMarca);
		}
		else if(pCodProducto < raiz->CodProducto){
			raiz=raiz->Hizq;
			return BuscarPrecio(raiz, pCodProducto, pCodMarca);
		}
		else{
			return raiz->rn.buscarPrecio2(pCodMarca);
		}	
	}
}

int ArbolAVL::BuscarCB(pNodoAVL raiz, int pCodProducto, int pCodMarca){
	if(raiz != NULL){
		if(pCodProducto > raiz->CodProducto){
			raiz=raiz->Hder;
			BuscarCB(raiz, pCodProducto, pCodMarca);
		}
		else if(pCodProducto < raiz->CodProducto){
			raiz=raiz->Hizq;
			BuscarCB(raiz, pCodProducto, pCodMarca);
		}
		else{
			return raiz->AA.BuscarCB(raiz->AA.raiz, pCodMarca);
		}	
	}
}

bool ArbolAVL::BuscarProducto2(pNodoAVL raiz, int pCodProducto){
	bool resultado=false;
	if(raiz != NULL){
		if(pCodProducto > raiz->CodProducto){
			raiz=raiz->Hder;
			return BuscarProducto2(raiz, pCodProducto);
		}
		else if(pCodProducto < raiz->CodProducto){
			raiz=raiz->Hizq;
			return BuscarProducto2(raiz, pCodProducto);
		}else{
			if(raiz->rn.Vacio()){
				cout<<endl<<"No hay marcas de este producto "<<endl;
			}else{
				raiz->rn.inorder(raiz->rn.root);
				resultado=true;
				return resultado;
			}
		}
	}else{
		cout<<endl<<"No hay productos en este pasillo :( "<<endl;
	}
	return resultado;
}

bool ArbolAVL::BuscarMarcaC(pNodoAVL raiz, int pCodProducto, int pCodMarca){
	bool resultado=false;
	if(raiz != NULL){
		if(pCodProducto > raiz->CodProducto){
			raiz=raiz->Hder;
			return BuscarMarcaC(raiz, pCodProducto, pCodMarca);
		}
		else if(pCodProducto < raiz->CodProducto){
			raiz=raiz->Hizq;
			return BuscarMarcaC(raiz, pCodProducto, pCodMarca);
		}
		else{
			resultado=raiz->rn.BuscarMarcaC(pCodMarca);
			return resultado;
		}	
	}
}

int ArbolAVL::BuscarGondola(pNodoAVL raiz, int pCodProducto, int pCodMarca){
	int resultado;
	if(raiz != NULL){
		if(pCodProducto > raiz->CodProducto){
			raiz=raiz->Hder;
			BuscarGondola(raiz, pCodProducto, pCodMarca);
		}
		else if(pCodProducto < raiz->CodProducto){
			raiz=raiz->Hizq;
			BuscarGondola(raiz, pCodProducto, pCodMarca);
		}
		else{
			resultado=raiz->rn.BuscarGondola(pCodMarca);
			return resultado;
		}	
	}
}

int ArbolAVL::BuscarStock(pNodoAVL raiz, int pCodProducto, int pCodMarca){
	int resultado;
	if(raiz != NULL){
		if(pCodProducto > raiz->CodProducto){
			raiz=raiz->Hder;
			BuscarStock(raiz, pCodProducto, pCodMarca);
		}
		else if(pCodProducto < raiz->CodProducto){
			raiz=raiz->Hizq;
			BuscarStock(raiz, pCodProducto, pCodMarca);
		}
		else{
			resultado=raiz->AA.BuscarStock(raiz->AA.raiz, pCodMarca);
			return resultado;
		}	
	}
}

void ArbolAVL::ModificarStock(pNodoAVL raiz, int pCodProducto, int pCodMarca, int CantidadStock){
	int resultado;
	if(raiz != NULL){
		if(pCodProducto > raiz->CodProducto){
			raiz=raiz->Hder;
			ModificarStock(raiz, pCodProducto, pCodMarca, CantidadStock);
		}
		else if(pCodProducto < raiz->CodProducto){
			raiz=raiz->Hizq;
			ModificarStock(raiz, pCodProducto, pCodMarca, CantidadStock);
		}
		else{
			raiz->AA.ModificarStock(raiz->AA.raiz, pCodMarca, CantidadStock);
		}	
	}
}
#endif	

