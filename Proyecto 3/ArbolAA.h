#include <iostream>

using namespace std;

class NodoAA{
	public:
		
		NodoAA():
			x(0), CodProducto(0), CodPasillo(0), Nombre(""), CantidadStock(0), CodCanasta(0),  nivel(1), Hder(NULL), Hizq(NULL), Padre(NULL){}
			//CodMarca(0), CodPasillo(0), CodProducto(0), Nombre(""), Precio(0), CantidadGondola(0), nivel(1), leftTree(NULL), rightTree(NULL), parent(NULL){ }
		
		int x;
		int nivel;
		int CodProducto;
		int CodPasillo;
		string Nombre;
		int CantidadStock;
		int CodCanasta;
		
		NodoAA *Hizq, *Hder, *Padre;
        
        friend class ArbolAA;
};
typedef NodoAA *pNodoAA;

class ArbolAA{

	public:
		pNodoAA raiz;
		
		ArbolAA(): raiz(NULL){}
		
		void Insertar(int CodPasillo, int CodProducto, int x, string Nombre, int CantidadStock, int CodCanasta, pNodoAA T);
		void Giro(pNodoAA T);
		void Reparto(pNodoAA);
		void InordenRAA(pNodoAA T);
		void insertar(int CodPasillo, int CodProducto, int x, string Nombre, int CantidadStock, int CodCanasta);
		void RepartoDoble(pNodoAA T);
		void GiroDoble(pNodoAA T);
		int BuscarCB(pNodoAA raiz, int pCodMarca);
		int BuscarStock(pNodoAA raiz, int pCodMarca);
		void ModificarStock(pNodoAA raiz, int pCodMarca, int CantidadStock);
};

void ArbolAA::insertar(int CodPasillo, int CodProducto, int x, string Nombre, int CantidadStock, int CodCanasta){
	if(raiz == NULL){
		
		raiz = new NodoAA();
		raiz->x = x;
		raiz->CodProducto = CodProducto;
		raiz->CodPasillo = CodPasillo;
		raiz->Nombre = Nombre;
		raiz->CantidadStock = CantidadStock;
		raiz->CodCanasta = CodCanasta;
		raiz->nivel = 1;
		raiz->Hder = NULL;
		raiz->Hizq = NULL;
		raiz->Padre = NULL;
	}
	else{
		Insertar(CodPasillo, CodProducto, x, Nombre, CantidadStock, CodCanasta, raiz);
	}
}

void ArbolAA::Insertar(int CodPasillo, int CodProducto, int x, string Nombre, int CantidadStock, int CodCanasta, pNodoAA T){
	if(T->nivel == 1){
		while(T->Hder != NULL){
			T = T->Hder;
		}
		if(x != T->x){
			pNodoAA AAux = new NodoAA();
			raiz->x = x;
			raiz->CodProducto = CodProducto;
			raiz->CodPasillo = CodPasillo;
			raiz->Nombre = Nombre;
			raiz->CantidadStock = CantidadStock;
			raiz->CodCanasta = CodCanasta;
			AAux->nivel = 1;
			AAux->Hder = NULL;
			AAux->Hizq = NULL;
			AAux->Padre = T;
			T->Hder = AAux;
			if(AAux->Padre != NULL){
				if(AAux->Padre->x > AAux->x && AAux->Padre->nivel == AAux->nivel){
					Giro(AAux);
					if(AAux->Padre != NULL){
						if(AAux->Padre->x > AAux->x && AAux->Padre->nivel == AAux->nivel){
							GiroDoble(AAux);
						}
					}	
				}	
			}
			if(T->Padre != NULL && AAux->Padre != NULL){
				if(T->Padre->nivel == AAux->Padre->nivel){
					if(AAux->Hder == NULL){
						Reparto(AAux->Padre);
					}else{
						Reparto(AAux);	
					}
				}
			}
			if(AAux->Hder != NULL && AAux->Hder->Hder != NULL){
				if(AAux->Hder->nivel == AAux->Hder->Hder->nivel){
					Reparto(AAux->Hder);
				}		
			}
		}
	}else{
		if(x < T->x){
			Insertar(CodPasillo, CodProducto, x, Nombre, CantidadStock, CodCanasta, T->Hizq);
		}else if(x > T->x){
			Insertar(CodPasillo, CodProducto, x, Nombre, CantidadStock, CodCanasta, T->Hder);
		}
	}
	
}

void ArbolAA::Giro(pNodoAA T){
	if(T->Padre->Padre != NULL){
		if(T->Padre->Padre->nivel == T->nivel){	
			pNodoAA aux = T->Padre;
			aux->Padre->Hder = T;
			T->Padre = aux->Padre;
			aux->Hder = T->Hder;
			aux->Padre = T;
			T->Hder = aux;
			if(T->Hder == raiz){
				raiz = T;
			}
		}else if(T->Padre->Padre->nivel != T->nivel){			
			if(T->Padre->Padre->x > T->x){
				pNodoAA aux = T->Padre;
				aux->Padre->Hizq = T;
				T->Padre = aux->Padre;
				aux->Hder = T->Hder;
				aux->Padre = T;
				T->Hder = aux;
			}else if(T->Padre->Padre->x < T->x){
				pNodoAA aux = T->Padre;
				aux->Padre->Hder = T;
				T->Padre = aux->Padre;
				aux->Hder = T->Hder;
				aux->Padre = T;
				T->Hder = aux;
			}
		}
	}else{
		pNodoAA aux = T->Padre;
		T->Padre = aux->Padre;
		aux->Padre = T;
		aux->Hder = T->Hder;
		T->Hder = aux;
		if(T->Hder == raiz){
			raiz = T;
		}	
	}
}

void ArbolAA::GiroDoble(pNodoAA T){
	if(T->Padre->Padre != NULL){
		if(T->Padre->Padre->x < T->x){
			pNodoAA aux = T->Padre;
			T->Hder->Padre = aux;
			aux->Hder = T->Hder;
			aux->Padre->Hder = T;
			T->Padre = aux->Padre;
			aux->Padre = T;
			T->Hder = aux;
			if(T->Hder == raiz){
				raiz = T;
			}	
		}else if(T->Padre->Padre->x > T->x){
			
			pNodoAA aux = T->Padre;
			T->Hder->Padre = aux;
			aux->Hder = T->Hder;
			aux->Padre->Hizq = T;
			T->Padre = aux->Padre;
			aux->Padre = T;
			T->Hder = aux;
			if(T->Hder == raiz){
				raiz = T;
			}
		}
	}else{
		pNodoAA aux = T->Padre;
		T->Padre = aux->Padre;
		aux->Hder = T->Hder;
		aux->Padre = T;
		T->Hder = aux;
		if(T->Hder == raiz){
			raiz = T;
		}
	}	
}

void ArbolAA::Reparto(pNodoAA T){
	if(T->Padre->Padre != NULL){
		if(T->Padre->Padre->x > T->x){
			//caso 2, 4, 6
			pNodoAA aux = T->Padre->Padre;
			T->Padre->Hder = T->Hizq;
			T->Hder->Padre = aux;
			T->Hizq = aux->Hizq;
			aux->Hizq = T->Hder;
			T->Hder = aux;
			T->Padre = aux->Padre;
			if(aux->Padre != NULL){
				if(aux->Padre->x < T->x){
					aux->Padre->Hder = T;
				}
				else{
					aux->Padre->Hizq = T;
				}	
			}
			T->Hizq->Padre = T;
			aux->Padre = T;
			T->nivel += 1;
			if(T->Hder == raiz){
				raiz = T;
			} 
		}else{
			pNodoAA aux = T->Padre->Padre;
			T->Padre->Padre = T;
			T->Padre->Hder = T->Hizq;
			aux->Hder = T;
			T->Hizq = T->Padre;
			T->Padre = aux;
			T->nivel += 1;
			if(T->Hder == raiz){
				raiz = T;
			} 
		}
	}else{
		//caso 1
		T->Padre->Hder = T->Hizq;
		T->Hizq = T->Padre;
		T->Padre->Padre = T;
		T->Padre = NULL;
		T->nivel += 1;
		raiz = T;
	}
	if(T->Padre != NULL && T->Hder != NULL){
		if(T->Padre->nivel == T->nivel && T->Hder->nivel == T->nivel){
			//cout<<"Holi: "<<T->x<<endl;
			RepartoDoble(T);
		}	
		else if(T->Hder->Hder != NULL && T->Padre->Padre != NULL){
			if(T->Hder->nivel == T->nivel && T->Hder->Hder->nivel == T->nivel){
				RepartoDoble(T->Hder);
			}else if(T->Padre->nivel == T->nivel && T->Padre->Padre->nivel == T->nivel){
				RepartoDoble(T->Padre);
			}
		} 		
	}else if(T->Padre == NULL && T->Hder != NULL){
		if(T->Hder->Hder != NULL){
			if(T->Hder->nivel == T->nivel && T->Hder->Hder->nivel == T->nivel){
				RepartoDoble(T->Hder);
			}
		}	
	}else if(T->Padre != NULL && T->Hder == NULL){
		if(T->Padre->Padre != NULL){
			if(T->Padre->nivel == T->nivel && T->Padre->Padre->nivel == T->nivel){
				RepartoDoble(T->Padre);
			}
		}
	}
}

void ArbolAA::RepartoDoble(pNodoAA T){
	//cout<<"Holiwis: "<<T->x<<endl;
	if(T->Padre->Padre != NULL){
		if(T->Padre->Padre->x > T->x){
			pNodoAA aux = T->Padre->Padre;
			T->Padre->Hder = T->Hizq;
			T->Hizq->Padre = T->Padre;
			T->Hizq = T->Padre;
			aux->Hizq = T->Hder;
			T->Hder->Padre = aux;
			T->Padre = aux->Padre;
			aux->Padre = T;
			T->Hizq->Padre = T;
			T->Hder = aux;
			T->nivel += 1;
			if(T->Hder == raiz){
				raiz = T;
			}
		}else if(T->Padre->Padre->x < T->x){
			pNodoAA aux = T->Padre->Padre;
			T->Padre->Hder = T->Hizq;
			T->Hizq->Padre = T->Padre;
			T->Hizq = aux->Hder;
			aux->Hder = T;
			T->Padre->Padre = T;
			T->Padre = aux;
			T->nivel += 1;
		}
	}else{
		pNodoAA aux = T->Padre;
		aux->Hder = T->Hizq;
		T->Hizq->Padre = aux;
		T->Padre = aux->Padre;
		aux->Padre = T;
		T->Hizq = aux;
		T->nivel += 1;
		if(T->Hizq == raiz){
			raiz = T;
		}
	}
	
	if(T->Padre != NULL && T->Hder != NULL){
		
		if(T->Padre->nivel == T->nivel && T->Hder->nivel == T->nivel){
			RepartoDoble(T);
		}
		if(T->Hder->Hder != NULL){
			if(T->Hder->nivel == T->nivel && T->Hder->Hder->nivel == T->nivel){
				RepartoDoble(T->Hder);
			}
			else if(T->Padre->Padre != NULL){
				if(T->Padre->nivel == T->nivel && T->Padre->Padre->nivel == T->nivel){
					RepartoDoble(T->Padre);
				}	
			}	
		}		
	}else if(T->Padre == NULL && T->Hder != NULL){
		if(T->Hder->Hder != NULL){
			if(T->Hder->nivel == T->nivel && T->Hder->Hder->nivel == T->nivel){
				RepartoDoble(T->Hder);
			}	
		}
	}else if(T->Padre != NULL && T->Hder == NULL){
		if(T->Padre->nivel == T->nivel && T->Padre->Padre->nivel == T->nivel){
			RepartoDoble(T->Padre);
		}
	}
	
}

void ArbolAA::InordenRAA(pNodoAA T){ //se cambió el izq y der del cod original
	if(T==NULL){
        return;
    }else{
    	try{
    		//cout<<"Holi"<<T->x<<endl;
			InordenRAA(T->Hizq);
		}catch(...){
			cout<<"Error en inordenR der"<<endl;
		}
		try{
			//if(T->Hder != NULL && T->Hizq != NULL)	
				//cout<<"Hizq: "<<T->Hizq->x<<" | X: "<<T->x<<" | Hder: "<<T->Hder->x<<endl;
			//else if(T->Hder != NULL){
				//cout<<"X: "<<T->x<<" | Hder: "<<T->Hder->x<<endl;
			//}else{
				cout<<"X: "<<T->x<<endl;	
			//}
	
		}catch(...){
			cout<<"Error en inordenR raiz"<<endl;
		}
		try{
			InordenRAA(T->Hder);
		}catch(...){
			cout<<"Error en inordenR izq"<<endl;
		}
    }
}

int ArbolAA::BuscarCB(pNodoAA raiz, int pCodMarca){
	pNodoAA aux= raiz;
	if(aux != NULL){
		if(pCodMarca > aux->x){
			aux=aux->Hder;
			BuscarCB(aux,pCodMarca);
		}
		else if(pCodMarca < aux->x){
			aux=aux->Hizq;
			BuscarCB(aux,pCodMarca);
		}
		else{
			cout << "Codigo Canasta " <<aux->CodCanasta <<endl;
			return aux->CodCanasta;
		}	
	}
}

int ArbolAA::BuscarStock(pNodoAA raiz, int pCodMarca){
	pNodoAA aux= raiz;
	if(aux != NULL){
		if(pCodMarca > aux->x){
			aux=aux->Hder;
			BuscarStock(aux,pCodMarca);
		}
		else if(pCodMarca < aux->x){
			aux=aux->Hizq;
			BuscarStock(aux,pCodMarca);
		}
		else{
			return aux->CantidadStock;
		}	
	}
}

void ArbolAA::ModificarStock(pNodoAA raiz,int pCodMarca, int CantidadStock){
	pNodoAA aux= raiz;
	if(aux != NULL){
		if(pCodMarca > aux->x){
			aux=aux->Hder;
			ModificarStock(aux,pCodMarca, CantidadStock);
		}
		else if(pCodMarca < aux->x){
			aux=aux->Hizq;
			ModificarStock(aux,pCodMarca, CantidadStock);
		}
		else{
			aux->CodCanasta = CantidadStock;
		}	
	}
}
