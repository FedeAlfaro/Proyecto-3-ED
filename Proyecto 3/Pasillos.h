#include <iostream>
#include <sstream>
using namespace std;


class nodo3 {
   public:
    nodo3(int v, int p, int m, string n, int c, int r)
    {
       CodPasillo = v;
       CodProducto = p;
       CodMarca = m;
       Nombre = n;
       CantidadGondola = c;
       Precio = r;
       siguiente = NULL;
       anterior =NULL;
    }

nodo3(int v, int p, int m, string n, int c, int r, nodo3 * signodo3)
    {
       CodPasillo = v;
       CodProducto = p;
       CodMarca = m;
       Nombre = n;
       CantidadGondola = c;
       Precio = r;
       siguiente = signodo3;
    }

   private:
    int CodPasillo;
    int CodProducto;
    int CodMarca;
    string Nombre;
    int CantidadGondola;
    int Precio;
    nodo3 *siguiente;
    nodo3 *anterior;
    
   friend class LSCompras;   
   friend class LCMarcas;
};

typedef nodo3 *pnodo3;

class LCMarcas {
   public:
    LCMarcas() { primero =  NULL; }
    ~LCMarcas();
    
    void InsertarInicio(int v, int p, int m, string n, int c, int r);
    void InsertarFinal(int v, int p, int m, string n, int c, int r);
    void InsertarPos (int v, int p, int m, string n, int c, int r, int pos);
    bool ListaVacia() { return primero == NULL; } 
	void Imprimir();
	void Borrar(int v, int p, int m, string n, int c, int r);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    bool verificarRepetidos(int CodMarca);
    int largoLista();
    void mostrarMarca();
   	int buscarPrecio(int CodMarca);
   	int buscarCantidad(int CodMarca);
   	int obtenerPasillo(int contadorsito);
   	int obtenerProducto(int contadorsito);
   	int obtenerMarca(int contadorsito);
	int obtenerCantidad(int contadorsito);
    bool facturado;
    
   private:
    pnodo3 primero;
    
    
};

LCMarcas::~LCMarcas()
{
   pnodo3 aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   
}

int LCMarcas::largoLista(){
    int cont=0;

    pnodo3 aux= primero;
    if(ListaVacia())
        return cont;
    else
    {
      while(aux->siguiente!=primero)
      {
        cont++;        
       aux=aux->siguiente;
      }
      cont=cont+1;
      return cont;
     }
}


void LCMarcas::InsertarInicio(int v, int p, int m, string n, int c, int r)
{
   if (ListaVacia())
   {
     pnodo3 nuevo= new nodo3(v,p,m,n,c,r);
     primero = nuevo;
     nuevo->siguiente=primero;
   }  
   else
   {
    pnodo3 nuevo= new nodo3(v,p,m,n,c,r);
    pnodo3 aux=primero;
    while (aux->siguiente!=primero)
       aux= aux->siguiente;
    nuevo->siguiente=primero;   
    aux->siguiente=nuevo;
    primero=nuevo;   
   } 
}
 
void LCMarcas::InsertarFinal(int v, int p, int m, string n, int c, int r)
{
   if (ListaVacia())
   {
     pnodo3 nuevo= new nodo3(v,p,m,n,c,r);
     primero = nuevo;
     nuevo->siguiente=primero;
   }  
   else
   { 
      pnodo3 nuevo=new nodo3(v,p,m,n,c,r);
      pnodo3 aux = primero;
      while (aux->siguiente!=primero)  
         aux= aux->siguiente;
      nuevo->siguiente= primero;
      aux->siguiente= nuevo; 
      
   }    
}


void LCMarcas::InsertarPos(int v, int p, int m, string n, int c, int r,int pos)
{
   if (ListaVacia())
   {
     pnodo3 nuevo= new nodo3(v,p,m,n,c,r);
     primero = nuevo;
     nuevo->siguiente=primero;
   } 
   else
   {
     if(pos <=1)
     {
       InsertarInicio(v,p,m,n,c,r);
     }      
     else
     {
       pnodo3 aux= primero;
       int i =2;
       while((i != pos )&&(aux->siguiente!= primero))
       {
          i++;
          aux=aux->siguiente;
       }
       pnodo3 nuevo= new nodo3(v,p,m,n,c,r);
       nuevo->siguiente=aux->siguiente;
       aux->siguiente=nuevo;
      }
     }
}
      
void LCMarcas::BorrarFinal()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        pnodo3 temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         pnodo3 aux = primero;
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         pnodo3 temp = aux->siguiente;
         aux->siguiente= primero;
         delete temp;
      }
    }
}

void LCMarcas::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        pnodo3 temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        pnodo3 aux = primero;
        pnodo3 temp= primero;
        while (aux->siguiente!=primero)
            aux= aux->siguiente;
        primero=primero->siguiente;                
        aux->siguiente=primero;
        delete temp;
      }
    }
}

void LCMarcas:: borrarPosicion(int pos)
{
  if(ListaVacia())
    cout << "Lista vacia" <<endl;
  else
  {
   if((pos>largoLista())||(pos<0))
     cout << "Error en posicion" << endl;
   else
    {
      if(pos==1)
        BorrarInicio();
      else
      {
       int cont=2;
       pnodo3 aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       pnodo3 temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       delete temp;
     }
    }
  }
}
 
void LCMarcas::Mostrar()
{
	pnodo3 aux=primero;
	if(ListaVacia()){
   
	}else{
		while(aux->siguiente!=primero)
     	{
      		cout<<"----------------------------------------------------------------------------------------------------------"<<endl;                          
      		cout << aux->CodPasillo<<" "<<aux->CodProducto<<" "<<aux->CodMarca<<" "<<aux->Nombre<<" "<<aux->CantidadGondola<<" "<<aux->Precio<<"->";
      		aux = aux->siguiente;
     	}
     	cout << aux->CodPasillo<<" "<<aux->CodProducto<<" "<<aux->CodMarca<<" "<<aux->Nombre<<" "<<aux->CantidadGondola<<" "<<aux->Precio<<"->";
     	cout<<endl;
     	cout<<"----------------------------------------------------------------------------------------------------------"<<endl; 
	}
   
}


bool LCMarcas::verificarRepetidos(int CodMarca){
	pnodo3 aux = primero;
	bool bandera = false;
	if(ListaVacia()){

	}else{
		do{
			if(aux->CodMarca == CodMarca){
				bandera = true;
			}else{
				aux=aux->siguiente;
			}
		}while(aux!=primero &&  !bandera);	
	}
	return bandera;
}

void LCMarcas::mostrarMarca()
{
	if(ListaVacia()){
		cout<< "No hay marcas para mostrar"<< endl;;
	}else{
		pnodo3 aux=primero;
	    while(aux->siguiente!=primero){                              
	    	cout<<endl<< "Codigo de marca: " <<aux->CodMarca<<"     Nombre del producto:"<<aux->Nombre;
	    	aux = aux->siguiente;
	    }
	    cout<< endl;
	    cout<< "Codigo de marca: " << aux->CodMarca<<"     Nombre del producto:"<<aux->Nombre<< endl;
	}
   
} 

int LCMarcas::buscarPrecio(int CodMarca){
	int precio= 0;
	pnodo3 aux = primero;
	if(ListaVacia()){
		return precio;
	}else{
		do{
			if(aux->CodMarca == CodMarca){
				return aux->Precio;
			}else{
				aux=aux->siguiente;
			}
		}while(aux!=NULL);
	
		return precio;
	}
}

int LCMarcas::buscarCantidad(int CodMarca){
	int CantidadGondola=-1;
	pnodo3 aux = primero;
	if(ListaVacia()){
		return CantidadGondola;
	}else{
		do{
			if(aux->CodMarca == CodMarca){
				return aux->CantidadGondola;
			}else{
				aux=aux->siguiente;
			}
		}while(aux!=NULL);
	
		return CantidadGondola;
	}
}

int LCMarcas::obtenerPasillo(int contadorsito){
	int contador=0;
	int CodPasillo=0;
	if(ListaVacia()){
		cout<<"No se ha realizado ninguna compra"<<endl;
	}else{
		pnodo3 aux= primero;
		while(contador<=contadorsito){
			aux=aux->siguiente;
			contador++;
		}
		CodPasillo=aux->CodPasillo;
	}
	return CodPasillo;	
}

int LCMarcas::obtenerProducto(int contadorsito){
	int contador=0;
	int CodProducto=0;
	if(ListaVacia()){
		cout<<"No se ha realizado ninguna compra";
	}else{
		pnodo3 aux= primero;
		while(contador<=contadorsito){
			aux=aux->siguiente;
			contador++;
		}
		CodProducto=aux->CodProducto;
	}
	return CodProducto;	
}

int LCMarcas::obtenerMarca(int contadorsito){
	int contador=0;
	int CodMarca=0;
	if(ListaVacia()){
		cout<<"No se ha realizado ninguna compra";
	}else{
		pnodo3 aux= primero;
		while(contador<=contadorsito){
			aux=aux->siguiente;
			contador++;
		}
		CodMarca=aux->CodMarca;
	}
	return CodMarca;	
}

int LCMarcas::obtenerCantidad(int contadorsito){
	int contador=0;
	int Cantidad=0;
	if(ListaVacia()){
		cout<<"No se ha realizado ninguna compra";
	}else{
		pnodo3 aux= primero;
		while(contador<=contadorsito){
			aux=aux->siguiente;
			contador++;
		}
		Cantidad=aux->CantidadGondola;
	}
	return Cantidad;	
}

//------------------------------------------------------------------------------------------------------------
class nodo6 { 
	
   public:
    nodo6(int v, int p, int pr, int m, string n, int c) 
    {
       cedula = v;
       lm.InsertarFinal(p, pr, m, n, c, 0);
       siguiente = NULL;
    }

 
    nodo6(int v, int p, int pr, int m, string n, int c, nodo6 * signodo6) 
    {
       cedula = v;//2
       lm.InsertarFinal(p, pr, m, n, c, 0);
       siguiente = signodo6;//primero
    }


   private: // atributos
    int cedula; 
    LCMarcas lm;
    nodo6 *siguiente; // tipo de la clase, clase autoreferencia. Direccion 
    
        
   friend class LSCompras; 
   friend class LCMarcas;
   

};
typedef nodo6 *pnodo6; //alias redefinir los punteros

class LSCompras {
   public:
    LSCompras()
	{
      primero=NULL;   	
    	
	}
    ~LSCompras();
    void InsertarInicio(int v, int p, int pr, int m, string n, int c);
    void InsertarFinal(int v, int p, int pr, int m, string n, int c);
    void InsertarPos (int v, int p, int pr, int m, string n, int c, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Mostrar();
    void Primero();
	void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void verificarCedula(int cedula, int CodPasillo, int CodProducto, int CodMarca, string Nombre, int CantidadGondola);
    int buscarCedula(int numeroNodo);
    int tamanoLM(int contadorsote);
    int obtenerPasillo(int contadorsote, int contadorcito);
    int obtenerProducto(int contadorsote, int contadorcito);
    int obtenerMarca(int contadorsote, int contadorcito);
    int obtenerCantidad(int contadorsote, int contadorcito);  
    int obtenerCedula(int contadorsote); 
    void facturar(int numeroNodo);
    int verificarDescuento(int pCedula);
    //string productoMasVendido(LDCPasillo &L1, string CodPasillo);
	  
   private:
    pnodo6 primero; // nodo *primero; tipo nodo tiene derechoi direccionar un nodo
    
    friend class ListaReportes;
};
  
LSCompras::~LSCompras() //Destructor
{
   pnodo6 aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
  
}

int LSCompras::largoLista(){ //largo
    int cont=0;

    pnodo6 aux; //nodo *aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}

void LSCompras::InsertarInicio(int v, int p, int pr, int m, string n, int c)
{
   if (ListaVacia())
     primero = new nodo6(v, p, pr, m, n, c);
   else
     primero=new nodo6 (v, p, pr, m, n, c);
}
 
void LSCompras::InsertarFinal(int v, int p, int pr, int m, string n, int c)
{
   if (ListaVacia())
     primero = new nodo6(v, p, pr, m, n, c);
   else
     { pnodo6 aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo6(v, p, pr, m, n, c);
      }    
}

void LSCompras::InsertarPos(int v, int p, int pr, int m, string n, int c, int pos) 
{
   if (ListaVacia())
     primero = new nodo6(v, p, pr, m, n, c);
   else{
        if(pos <=1){                     //InsertarInicio(v);
          pnodo6 nuevo = new nodo6(v, p, pr, m, n, c);
          nuevo->siguiente= primero;
          primero= nuevo;     
        }      
        else
		{
        	if (pos>=largoLista())
			   InsertarFinal(v, p, pr, m, n, c);
			else
			{
			
             pnodo6 aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo6 nuevo= new nodo6(v, p, pr, m, n, c); //1 NODO
             nuevo->siguiente=aux->siguiente; // 2 Nuevo con el valor siguiente 20
             aux->siguiente=nuevo;// 3 aux con nuevo
            }
             
        }
        }
}
      
void LSCompras::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la LSCompras:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
        	    pnodo6 temp=primero;
                primero= NULL;
                delete temp;
            } else {

                pnodo6 aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
              pnodo6 temp = aux->siguiente;
              aux->siguiente= NULL;

                
                delete temp;
            }
        }
}

void LSCompras::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la LSCompras:" << endl;
    
   }else
   {
        if (primero->siguiente == NULL)
		{
        	    pnodo6 temp=primero;
                primero= NULL;
                delete temp;
        }
		else
		{

                pnodo6 aux = primero;
                primero=primero->siguiente;                
                delete aux;
        }
   }
}



void LSCompras:: borrarPosicion(int pos){
    if(ListaVacia()){
        cout << "Lista vacia" <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        }else{
        if(pos==1){
        //Primera forma	
        //pnodo aux=primero;
        //primero=primero->siguiente;
        //delete aux;
        //Segunda forma
        BorrarInicio();
        }else{
          int cont=2;
            pnodo6 aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            pnodo6 temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            delete temp;
            }
        }
     }

}
 

void LSCompras::Mostrar()
{
   nodo6 *aux;
   if (primero== NULL)
       cout << "No hay elementos";  
   else
   {
   		aux = primero;
		while(aux!=NULL) 
		{
		    cout<<aux->cedula<<"=>";
		    aux->lm.Mostrar();
		    aux = aux->siguiente;
		}
		cout << endl;
   }
}


void LSCompras::verificarCedula(int cedula, int CodPasillo, int CodProducto, int CodMarca, string Nombre, int CantidadGondola){
	pnodo6 aux = primero;
	bool bandera = false;
	if(ListaVacia()){
		InsertarFinal(cedula, CodPasillo, CodProducto, CodMarca, Nombre, CantidadGondola);
	}else{
		do{
			if(aux->cedula == cedula){
				bandera = true;
				if(aux->lm.facturado){
					InsertarFinal(cedula, CodPasillo, CodProducto, CodMarca, Nombre, CantidadGondola);
				}else{
					aux->lm.InsertarFinal(CodPasillo, CodProducto, CodMarca, Nombre, CantidadGondola, 0);	
				}	
				break;			
			}else{
				aux=aux->siguiente;
			}
		}while(aux!=NULL);
		if(!bandera){
			InsertarFinal(cedula, CodPasillo, CodProducto, CodMarca, Nombre, CantidadGondola);
		}
	}
}

int LSCompras::buscarCedula(int numeroNodo){
	int CedulaActual=0; 
	int contador=0;
	if (ListaVacia()){
		cout<<"No se ha realizado ninguna compra"<<endl;
	}else{
		pnodo6 aux= primero;
		while(contador<numeroNodo){
			aux=aux->siguiente;
			contador++;
		}
		CedulaActual=aux->cedula;
	}
	return CedulaActual;
}

void LSCompras::facturar(int numeroNodo){
	int contador=0;
	if (!ListaVacia()){
		pnodo6 aux= primero;
		while(contador<numeroNodo){
			aux=aux->siguiente;
			contador++;
		}
		aux->lm.facturado=true;
	}
}

int LSCompras::tamanoLM(int contadorsote){
	int contador=0;
	int tamano=0;
	if (ListaVacia()){
		cout<<"No se ha realizado ninguna compra"<<endl;
	}else{
		pnodo6 aux= primero;
		while(contador<contadorsote){
			aux=aux->siguiente;
			contador++;
		}
		tamano=aux->lm.largoLista();
	}
	return tamano;	
}

int LSCompras::obtenerPasillo(int contadorsote, int contadorcito){
	int contador=0;
	int CodPasillo=0;
	if (ListaVacia()){
		cout<<"No se ha realizado ninguna compra"<<endl;
	}else{
		pnodo6 aux= primero;
		while(contador<contadorsote){
			aux=aux->siguiente;
			contador++;
		}
		CodPasillo=aux->lm.obtenerPasillo(contadorcito);
	}
	return CodPasillo;	
}

int LSCompras::obtenerProducto(int contadorsote, int contadorcito){
	int contador=0;
	int CodProducto=0;
	if (ListaVacia()){
		cout<<"No se ha realizado ninguna compra"<<endl;
	}else{
		pnodo6 aux= primero;
		while(contador<contadorsote){
			aux=aux->siguiente;
			contador++;
		}
		CodProducto=aux->lm.obtenerProducto(contadorcito);
	}
	return CodProducto;	
}

int LSCompras::obtenerMarca(int contadorsote, int contadorcito){
	int contador=0;
	int CodMarca=0;
	if (ListaVacia()){
		cout<<"No se ha realizado ninguna compra"<<endl;
	}else{
		pnodo6 aux= primero;
		while(contador<contadorsote){
			aux=aux->siguiente;
			contador++;
		}
		CodMarca=aux->lm.obtenerMarca(contadorcito);
	}
	return CodMarca;	
}

int LSCompras::obtenerCedula(int contadorsote){
	int contador=0;
	int Cedula=0;
	if (ListaVacia()){
		cout<<"No se ha realizado ninguna compra"<<endl;
	}else{
		pnodo6 aux= primero;
		while(contador<contadorsote){
			aux=aux->siguiente;
			contador++;
		}
		Cedula=aux->cedula;
	}
	return Cedula;	
}


int LSCompras::obtenerCantidad(int contadorsote, int contadorcito){
	int contador=0;
	int Cantidad=0;
	if (ListaVacia()){
		cout<<"No se ha realizado ninguna compra"<<endl;
	}else{
		pnodo6 aux= primero;
		while(contador<contadorsote){
			aux=aux->siguiente;
			contador++;
		}
		Cantidad=aux->lm.obtenerCantidad(contadorcito);
	}
	return Cantidad;
}

int LSCompras::verificarDescuento(int pCedula){  //###
	bool resultado=false;
	if(!ListaVacia()){
		pnodo6 aux= primero;
		int contador=0;
		while(aux){
			if(aux->cedula==pCedula && aux->lm.facturado==true){
				contador++;
			}
			aux=aux->siguiente;
		}
		if(contador>2){
			resultado=true;
		}
	}
	return resultado;
}



/*
string LSCompras::productoMasVendido(LDCPasillo &L1, string CodPasillo){
	ListaReportes productoMasVendido;
	string respuesta = "No se ha vendido ningun producto";
	if(!ListaVacia()){
		pnodo6 aux = primero;
		while(aux!=NULL){
			if(CodPasillo == aux->lm.{
				productoMasVendido.InsertarFinal(aux->CodProducto);
				aux=aux->siguiente;
			}
			aux=aux->siguiente;
		}
		respuesta = productoMasVendido.encontrarPasilloMasVisitado();
	}
	return respuesta;
}
*/

//-------------------------------------------------------------------------------------------------------------------------------
class nodo7 { 
	
   public:
    nodo7(int a) 
    {
       repeticiones = 0;
       codigo = a;
       siguiente = NULL;
    }

 
    nodo7(int a, nodo7 * signodo7) 
    {
    	codigo = a;
       	repeticiones = 0;//2
       	siguiente = signodo7;
    }


   private: 
    int repeticiones; 
    int codigo;
    nodo7 *siguiente; 
    
        
   friend class ListaReportes; 

};
typedef nodo7 *pnodo7; 

class ListaReportes {
   public:
    ListaReportes()
	{
      primero=NULL;   	
    	
	}
    ~ListaReportes();
    void InsertarInicio(int a);
    void InsertarFinal(int a);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Mostrar();
    void Primero();
    int largoLista();
    int encontrarMas();
    int encontrarMenos();
    bool repetido(int pCod);

      
      
      
   private:
    pnodo7 primero; // nodo7 *primero; tipo nodo7 tiene derechoi direccionar un nodo7
   
   friend class LSCompras;
};
  
ListaReportes::~ListaReportes() //Destructor
{
   pnodo7 aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
  
}

int ListaReportes::largoLista(){ //largo
    int cont=0;

    pnodo7 aux; //nodo7 *aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}

void ListaReportes::InsertarInicio(int a)
{
   if (ListaVacia())
     primero = new nodo7(a);
   else
     primero=new nodo7 (a,primero);
}
 
void ListaReportes::InsertarFinal(int a)
{
    if(ListaVacia()){
		primero = new nodo7(a);
    }else{ 
	 	pnodo7 aux = primero;
        while ( aux->siguiente != NULL){
        	if(aux->codigo == a){
        		aux->repeticiones++;
        		break;	
			}else if(aux->siguiente->codigo == a){
				aux->siguiente->repeticiones++;
				break;
			}else{
				aux=aux->siguiente;
			}
		}  
        aux->siguiente=new nodo7(a);
      }    
}



 

void ListaReportes::Mostrar()
{
   nodo7 *aux;
   if (primero== NULL)
       cout << "No hay elementos";  
   else
   {
   
       
   		aux = primero;
		while(aux) 
		{
		    cout << aux->repeticiones << "-> ";
		    aux = aux->siguiente;
		}
		cout << endl;
   }
}

int ListaReportes::encontrarMas(){
	int encontrarMas = 0;
	if(!ListaVacia()){
		pnodo7 aux = primero;
		int repeticionesMax = aux->repeticiones;
		encontrarMas = aux->codigo;
		while(aux!=NULL){
			if(aux->repeticiones > repeticionesMax){
				repeticionesMax = aux->repeticiones;
				encontrarMas = aux->codigo;
			}
			aux=aux->siguiente;
		}
	}
	return encontrarMas;
}

int ListaReportes::encontrarMenos(){
	int encontrarMenos = 0;
	if(!ListaVacia()){
		pnodo7 aux = primero;
		int repeticionesMin = aux->repeticiones;
		encontrarMenos = aux->codigo;
		while(aux!=NULL){
			if(aux->repeticiones <= repeticionesMin){
				repeticionesMin = aux->repeticiones;
				encontrarMenos = aux->codigo;
			}
			aux=aux->siguiente;
		}
	}
	return encontrarMenos;
}

bool ListaReportes::repetido(int pCod){
	bool repetido=false;
	if(!ListaVacia()){
		pnodo7 aux = primero;
		while(aux!=NULL){
			if(aux->codigo == pCod){
				repetido=true;
				break;
			}
			aux=aux->siguiente;
		}
	}
	return repetido;
}

