#include <cstdlib>
#include <iostream>
using namespace std;


// estructura nodo para lista simple

// estructura arista para lista de aristas
struct Arista{
    int codCiudadOrigen; // parte de datos
    int codCiudadDestino;
	int peso;
    bool visitado;
    //string nombreCiudad;
    Arista * siguiente;// puntero para enlazar nodos
       // constructor
       
    Arista(int d, int o, int p){
        codCiudadOrigen = d; // asigna los datos 
        codCiudadDestino = o;
        peso = p;
        visitado = false;
        siguiente = NULL; // sig es null           
    }
       
    // imprimir
    void imprimir(){
        cout <<codCiudadOrigen << "("<<peso<<")";
    }
};

struct ListaAristas{
       // solo con pN es suficiente
   	Arista *primerNodo, *ultimoNodo;
   
   	ListaAristas(){
    	primerNodo = ultimoNodo = NULL;
   	}
   
   	// encabezados de funcion
   	void insertarAlInicio (int dato, int dato1, int peso);
   	Arista* borrarAlInicio();
   	void imprimir();
   	void insertarAlFinal(int dato, int dato1, int peso);
   	Arista* borrarAlFinal();
   	Arista* buscar (int dato);//
   	int largo ();//
   	bool vacia(); 
   	void borrarEnPosicion(int pos);       
   	int posicion (int);      
};

// funcion que inserta un nodo nuevo en la lista
// entradas: el dato a guardar
// salidas: no tiene
void ListaAristas::insertarAlInicio(int dato, int dato1, int peso){
     // si no hay elementos
    if (primerNodo == NULL){
        // ambos apuntan al nuevo en memoria
        primerNodo = new Arista(dato, dato1, peso);
        ultimoNodo = primerNodo; // ambos apuntan al nuevo               
    }else{
        Arista *nuevo = new Arista(dato, dato1, peso);
        // a lo que apunta pN ahora es el segundo
        // por eso, nuevo->siguiente es pN
        nuevo->siguiente = primerNodo;
        // ahora devolvemos pN a que apunte al nuevo
        // y primero de las lista
        primerNodo = nuevo; 
        // el puntero nuevo deja de existir, no se libera
        // memoria porque se pierde la info
    }
}

// funcion que elimina el primer elemento de las lista
// entradas: no tiene
// salidas: el puntero al primer nodo. Este puntero
// en siguiente apuntara a null. No se libera memoria

Arista* ListaAristas::borrarAlInicio(){
    // si no hay elementos, no borra nada, retorna null
    if(primerNodo == NULL){
        return NULL;
    }else{
        // un puntero que apunta al nodo que se
        // "despegara" de la lista y se retorna
        Arista* borrado = primerNodo;     
        // pN se pasa al segundo de la lista
        // porque el primero se eliminara
        primerNodo = primerNodo->siguiente;
        // el nodo borrado, se debe despegar
        // entonces siguiente apunta a null y no
        // al segundo de la lista que ahora es pN
        borrado->siguiente = NULL;
        // aca se deberia liberar la memoria si no se
        // retornara el borrado
        return borrado;
    }
}


// funcion que recorre toda la lista con pt tmp
// imprimiendo en consola cada dato de nodos
// entradas no tiene
// salidas: no tiene, solo imprime en consola
void ListaAristas::imprimir(){
    // puntero temporal que avanza
    // por toda la lista
    // apunta a los mismo que pN
    Arista *tmp = primerNodo; 
    // mientras tmp no sea nulo, avanza
    while(tmp != NULL){
        // imprime el dato del nodo en el que esta tmp
        cout << tmp->codCiudadOrigen << " Peso ("<<tmp->peso<<") | ";
        // tmp avanza al siguiente nodo
        // esto no puede faltar porque se encicla
        tmp = tmp->siguiente;
    }
}

// funcion que inserta un nodo nuevo al final de la lista
// entradas: el dato a guardar
// salidas: no tiene
void ListaAristas::insertarAlFinal (int dato, int dato1, int peso){
    // si no hay elementos
    if(primerNodo == NULL){
        // ambos apuntan al nuevo en memoria
        primerNodo = new Arista(dato,dato1,peso);
        ultimoNodo = primerNodo; // ambos apuntan al nuevo               
    }else{
        // se crea el nuevo nodo
        Arista *nuevo = new Arista(dato, dato1, peso);
        // uN siguiente debe apuntar al nuevo nodo
        // uN debe apuntar al nuevo nodo enlazado
        ultimoNodo->siguiente = nuevo;
        ultimoNodo = nuevo;
        // el puntero nuevo deja de existir, no se libera
        // memoria porque se pierde la info
    }
}



// funcion que retorna true si la lista es vacia
// entradas: ninguna
// salidas: true si es no tiene elmentos, false otro caso
bool ListaAristas::vacia(){
    // si primerNodo es nulo, no hay elementos
    if(primerNodo == NULL)
        return true;
    else
        return false;     
}



Arista* ListaAristas::borrarAlFinal(){
    if(vacia())
        return NULL;
    // este caso es cuando tiene un solo elemento
    else if(primerNodo->siguiente == NULL)
    {
        Arista* actual = primerNodo;
        primerNodo = ultimoNodo = NULL;
        return actual;
    }else{
        // referencia al primero para recorrer la lista
        Arista * actual = primerNodo;
        // recorre la lista hasta llegar al penultimo nodo
        //while (actual->siguiente != NULL)
        while (actual->siguiente->siguiente != NULL)
            actual = actual->siguiente;       
        // al salir actual referencia al penultimo nodo
        // refencia nueva al ultimo nodo para despues retornarlo
        Arista* tmp = ultimoNodo;
        // ultimo nodo pasa al penultimo
        ultimoNodo = actual;
        //le quita el enlace al que era ultimo
        actual->siguiente = NULL;
        // retorna el que desenlazo al final
        return tmp;
    }
}

// LARGO LARGO LARGO
int ListaAristas::largo(){
    int contador = 0;
     // apunta a los mismo que pN
     Arista *tmp = primerNodo;
     
     // mientras tmp no sea nulo, avanza
     while (tmp != NULL)
     {
           contador++;
           // tmp avanza al siguiente nodo
           // esto no puede faltar porque se encicla
           tmp = tmp->siguiente;
     }
     return contador;
}

// BUSCAR BUSCAR BUSCAR
Arista *ListaAristas::buscar(int valor)
{
       Arista * tmp = primerNodo;
       while (tmp!=NULL)
       {
             if (tmp->codCiudadOrigen == valor)
                return tmp;
             
             tmp = tmp->siguiente;      
             
       }       
       
       return NULL;
}

// BORRAR POSICION BORRAR POSICION
// Funcion que elimina el elmento de la lista en una posicion
// esta funcion no retorna el nodo eliminado, por lo que
// si libera memoria
void ListaAristas::borrarEnPosicion(int pos){
    // si esta vacia no borra
    if (vacia()){ }
    // pos 0 borra el inicio
    else if(pos == 0){
        // borrar al inicial no libera memoria, se hace
        // luego de llamar a la funcion
        Arista * borrado = borrarAlInicio();
        if (borrado != NULL)
            delete borrado;        
    }else{
        //recorre la lista hasta el nodo previo a eliminar
        Arista *actual = primerNodo;
        // deja el puntero en el nodo antes a eliminar
        for(int i=1; i < pos && actual->siguiente != NULL;i++)
            actual=actual->siguiente;
            
        // si es el ultimo borra el final
        if(actual->siguiente == NULL){
            // borrar al final no libera memoria, se hace
            // luego de llamar a la funcion
            Arista* borrado = borrarAlFinal();
            if(borrado != NULL)
                delete borrado;
        }else{
            //referencia tmp que apunta al que se eliminara
            Arista *tmp = actual->siguiente;
            // anterior a borrar siguiente será el sig.sig
            actual->siguiente = actual->siguiente->siguiente;
            // el que se eliminara.sig sera null
            tmp->siguiente = NULL;
            delete tmp;
        }
    }
}
    
// POSICION POSICION
int ListaAristas::posicion(int valor){
    int pos = 0;
    Arista * tmp = primerNodo;
    while(tmp!=NULL){
        if(tmp->codCiudadOrigen == valor)
            return pos;     
        pos++;
        tmp = tmp->siguiente;              
    }           
	return -1;
}

struct Nodo{
    int codCiudad;
	string nombreCiudad; // parte de datos
    ListaAristas * aristas;
    bool visitado;
    Nodo* siguiente;// puntero para enlazar nodos
    // constructor  
    Nodo(int d, string e){
        codCiudad = d;
		nombreCiudad = e;// asigna los datos
        aristas = new ListaAristas(); 
        visitado = false;
        siguiente = NULL; // sig es null
    }   
};

struct ListaSimple{
       // solo con pN es suficiente
    Nodo *primerNodo, *ultimoNodo;
       
    ListaSimple(){
        primerNodo = ultimoNodo = NULL;
    }
       
    // encabezados de funcion
   	void insertarAlInicio (int codCiudad, string nombreCiudad);
   	Nodo* borrarAlInicio();
   	void imprimir();
   	void insertarAlFinal(int codCiudad, string nombreCiudad);
   	Nodo* borrarAlFinal();
   	Nodo* buscar (int codCiudad);//
   	int largo ();//
   	int largoRec ();
   	int largo_aux(Nodo*);
   	void insertarAlFinalConRecorrido(int codCiudad, string nombreCiudad);//
   	bool vacia();
   	ListaSimple* retornaNuevaListaInvertida();//
   	void insertarEnPosicion(int codCiudad, string nombreCiudad, int pos);
   	void borrarEnPosicion(int pos);       
   	int posicion (int);
   	void encolar(int, string);
   	Nodo* desencolar();
};

// funcion que inserta un nodo nuevo en la lista
// entradas: el dato a guardar
// salidas: no tiene
void ListaSimple::insertarAlInicio(int codCiudad, string nombreCiudad){
    // si no hay elementos
    if(primerNodo == NULL){
        // ambos apuntan al nuevo en memoria
        primerNodo = new Nodo(codCiudad, nombreCiudad);
        ultimoNodo = primerNodo; // ambos apuntan al nuevo               
    }
    else{
        Nodo *nuevo = new Nodo(codCiudad, nombreCiudad);
        // a lo que apunta pN ahora es el segundo
        // por eso, nuevo->siguiente es pN
        nuevo->siguiente = primerNodo;
        // ahora devolvemos pN a que apunte al nuevo
        // y primero de las lista
        primerNodo = nuevo; 
        // el puntero nuevo deja de existir, no se libera
        // memoria porque se pierde la info
    }
}

// funcion que elimina el primer elemento de las lista
// entradas: no tiene
// salidas: el puntero al primer nodo. Este puntero
// en siguiente apuntara a null. No se libera memoria

Nodo* ListaSimple::borrarAlInicio(){
    // si no hay elementos, no borra nada, retorna null
    if(primerNodo == NULL){
        return NULL;
    }else{
        // un puntero que apunta al nodo que se
        // "despegara" de la lista y se retorna
        Nodo* borrado = primerNodo;     
        // pN se pasa al segundo de la lista
        // porque el primero se eliminara
        primerNodo = primerNodo->siguiente;
        // el nodo borrado, se debe despegar
        // entonces siguiente apunta a null y no
        // al segundo de la lista que ahora es pN
        borrado->siguiente = NULL;
        // aca se deberia liberar la memoria si no se
        // retornara el borrado
        return borrado;
    }
}


// funcion que recorre toda la lista con pt tmp
// imprimiendo en consola cada dato de nodos
// entradas no tiene
// salidas: no tiene, solo imprime en consola
void ListaSimple::imprimir(){
	// puntero temporal que avanza
    // por toda la lista
    // apunta a los mismo que pN
    Nodo *tmp = primerNodo;
    // mientras tmp no sea nulo, avanza
    while(tmp != NULL){
        // imprime el dato del nodo en el que esta tmp
        cout << tmp->codCiudad << "  ";
        // tmp avanza al siguiente nodo
        // esto no puede faltar porque se encicla
        tmp = tmp->siguiente;
    }
    cout << endl;
}

// funcion que inserta un nodo nuevo al final de la lista
// entradas: el dato a guardar
// salidas: no tiene
void ListaSimple::insertarAlFinal(int codCiudad, string nombreCiudad){
     // si no hay elementos
     if(primerNodo == NULL){
         // ambos apuntan al nuevo en memoria
        primerNodo = new Nodo(codCiudad, nombreCiudad);
        ultimoNodo = primerNodo; // ambos apuntan al nuevo               
    }
    else{
        // se crea el nuevo nodo
        Nodo *nuevo = new Nodo(codCiudad, nombreCiudad);
        // uN siguiente debe apuntar al nuevo nodo
        // uN debe apuntar al nuevo nodo enlazado
        ultimoNodo->siguiente = nuevo;
        ultimoNodo = nuevo;
        // el puntero nuevo deja de existir, no se libera
        // memoria porque se pierde la info
    }
}



// funcion que retorna true si la lista es vacia
// entradas: ninguna
// salidas: true si es no tiene elmentos, false otro caso
bool ListaSimple::vacia(){
    // si primerNodo es nulo, no hay elementos
    if(primerNodo == NULL)
        return true;
    else
        return false;     
}

Nodo* ListaSimple::borrarAlFinal(){
    if (vacia())
         return NULL;
    // este caso es cuando tiene un solo elemento
    else if (primerNodo->siguiente == NULL){
        Nodo* actual = primerNodo;
        primerNodo = ultimoNodo = NULL;
        return actual;
    }else {
        // referencia al primero para recorrer la lista
        Nodo* actual = primerNodo;
        // recorre la lista hasta llegar al penultimo nodo
        //while (actual->siguiente != NULL)
        while (actual->siguiente->siguiente != NULL)
            actual = actual->siguiente;       
        // al salir actual referencia al penultimo nodo
        // refencia nueva al ultimo nodo para despues retornarlo
        Nodo* tmp = ultimoNodo;
        // ultimo nodo pasa al penultimo
        ultimoNodo = actual;
        //le quita el enlace al que era ultimo
        actual->siguiente = NULL;
        // retorna el que desenlazo al final
        return tmp;
    }
}

Nodo * ListaSimple::buscar(int valor){
    Nodo * tmp = primerNodo;
    while (tmp!=NULL){
        if (tmp->codCiudad == valor)
            return tmp; 
        tmp = tmp->siguiente;              
    }       
    return NULL;
}

int ListaSimple::posicion(int valor){
    int pos = 0;
    Nodo * tmp = primerNodo;
    while(tmp!=NULL){
        if (tmp->codCiudad == valor)
            return pos; 
        pos++;
        tmp = tmp->siguiente;              
    }       
    return -1;
}




// Funcion que elimina el elmento de la lista en una posicion
// esta funcion no retorna el nodo eliminado, por lo que
// si libera memoria
void ListaSimple::borrarEnPosicion(int pos){
     // si esta vacia no borra
        if(vacia())
        { }
        // pos 0 borra el inicio
        else
        if (pos == 0){
        	// borrar al inicial no libera memoria, se hace
            // luego de llamar a la funcion
            Nodo* borrado = borrarAlInicio();
            if(borrado != NULL)
            	delete borrado;        
        }else{
            //recorre la lista hasta el nodo previo a eliminar
            Nodo *actual = primerNodo;
            // deja el puntero en el nodo antes a eliminar
            for(int i=1; i < pos && actual->siguiente != NULL;i++)
                actual=actual->siguiente;
            
            // si es el ultimo borra el final
            if(actual->siguiente == NULL){
                // borrar al final no libera memoria, se hace
                // luego de llamar a la funcion
                Nodo* borrado = borrarAlFinal();
                if (borrado != NULL)
                    delete borrado;
            }
            else{
                //referencia tmp que apunta al que se eliminara
                Nodo *tmp = actual->siguiente;
                // anterior a borrar siguiente será el sig.sig
                actual->siguiente = actual->siguiente->siguiente;
                // el que se eliminara.sig sera null
                tmp->siguiente = NULL;
                delete tmp;
            }
        }
    }
    
// se hace un borrar al inicio llamado desencolar
// para simular una cola
Nodo* ListaSimple::desencolar(){
    // si no hay elementos, no borra nada, retorna null
    if(primerNodo == NULL){
        return NULL;
    }else{
        // un puntero que apunta al nodo que se
        // "despegara" de la lista y se retorna
        Nodo* borrado = primerNodo;     
        // pN se pasa al segundo de la lista
        // porque el primero se eliminara
        primerNodo = primerNodo->siguiente;
        // el nodo borrado, se debe despegar
        // entonces siguiente apunta a null y no
        // al segundo de la lista que ahora es pN
        borrado->siguiente = NULL;
        // aca se deberia liberar la memoria si no se
        // retornara el borrado
        return borrado;
    }
}

// se hace un insertar al final, llamado encolar
void ListaSimple::encolar(int codCiudad, string nombreCiudad){
     // si no hay elementos
    if(primerNodo == NULL){
         // ambos apuntan al nuevo en memoria
        primerNodo = new Nodo(codCiudad, nombreCiudad);
        ultimoNodo = primerNodo; // ambos apuntan al nuevo               
    }else{
        // se crea el nuevo nodo
        Nodo *nuevo = new Nodo(codCiudad, nombreCiudad);
        // uN siguiente debe apuntar al nuevo nodo
        // uN debe apuntar al nuevo nodo enlazado
        ultimoNodo->siguiente = nuevo;
        ultimoNodo = nuevo;
        // el puntero nuevo deja de existir, no se libera
        // memoria porque se pierde la info
    }
}
