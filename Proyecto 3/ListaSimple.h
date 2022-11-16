#pragma once

#pragma once

#include <iostream>
using namespace std;
//TDA Tipo abstractos de Datos, no pertenece al lenguaje, sin embargo, cuando el programador lo define se puede empezar a utilizar

class NodoLista { //clase NODO

public:
    NodoLista(string v) // 20 Tiene diferente cantidad de parametros, diferente tipos. Mismo nombre de la clase
    {
        valor = v;//20
        siguiente = NULL;
    }


    NodoLista(string v, NodoLista* sigNodoLista) // 2 dirprimero direccion de memoria
    {
        valor = v;//2
        siguiente = sigNodoLista;//primero
    }


private: // atributos
    string valor; // tipo entero. Ej clase estudiante nombre,dir,tel,siguente
    NodoLista* siguiente; // tipo de la clase, clase autoreferencia. Direccion 


    friend class cola; // telefono, son amigas lista con la clase. Solo los metodos, constructores

};
typedef NodoLista* pNodoLista; //alias redefinir los punteros



/*
class lista {
   public:
    lista()
    {
      primero=NULL;

    }
    ~lista();
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Mostrar();
    void Primero();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void invertir();
    // PRACTICA de lista Simple
    void Buscar(int elem);
    void BuscarPos(int elem,int pos);

    void Sumar(lista &L1,lista &L2);
    void SumarListasTamD(lista &L1,lista &L2);

   private:
    pnodo primero; // nodo *primero; tipo nodo tiene derechoi direccionar un nodo

};

lista::~lista() //Destructor
{
   pnodo aux;

   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }

}

int lista::largoLista(){ //largo
    int cont=0;

    pnodo aux; //nodo *aux;
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

void lista::InsertarInicio(int v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     primero=new nodo (v,primero);
}

void lista::InsertarFinal(int v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
      }
}

void lista::InsertarPos(int v, int pos)
{
   if (ListaVacia())
     primero = new nodo(v);
   else{
        if(pos <=1){                     //InsertarInicio(v);
          pnodo nuevo = new nodo(v);
          nuevo->siguiente= primero;
          primero= nuevo;
        }
        else
        {
            if (pos>=largoLista())
               InsertarFinal(v);
            else
            {

             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v); //1 NODO
             nuevo->siguiente=aux->siguiente; // 2 Nuevo con el valor siguiente 20
             aux->siguiente=nuevo;// 3 aux con nuevo
            }

        }
        }
}

void lista::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;

   }else{
        if (primero->siguiente == NULL) {
                pnodo temp=primero;
                primero= NULL;
                delete temp;
            } else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }

              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;


                delete temp;
            }
        }
}

void lista::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;

   }else
   {
        if (primero->siguiente == NULL)
        {
                pnodo temp=primero;
                primero= NULL;
                delete temp;
        }
        else
        {

                pnodo aux = primero;
                primero=primero->siguiente;
                delete aux;
        }
   }
}



void lista:: borrarPosicion(int pos){
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
            pnodo aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            pnodo temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            delete temp;
            }
        }
     }

}


void lista::Mostrar()
{
   nodo *aux;
   if (primero== NULL)
       cout << "No hay elementos";
   else
   {


        aux = primero;
        while(aux)
        {
            cout << aux->valor << "-> ";
            aux = aux->siguiente;
        }
        cout << endl;
   }
}

void lista :: invertir()
{
    pnodo ant;
    pnodo sig= primero;
    while ( primero!= NULL)
    {
        primero= primero->siguiente;
        sig->siguiente=ant;
        ant=sig;
        sig=primero;
    }
    primero= ant;
}

//BUSCAR UN ELEMENTO
void lista::Buscar(int elem)
{
  pnodo aux= primero;
  while ((aux->siguiente!=NULL) &&( aux->valor!=elem ))
        aux=aux->siguiente;
  if(aux->valor==elem)
     cout<<"Elemento si se encuentra"<<endl;
  else
     cout<<"Elemento no se encuentra"<<endl;
}

/*BUSCAR UN ELEMENTO EN UNA POSICION
void lista::BuscarPos (int Elem,int Pos)
{
    pnodo aux=primero;
    int i;

    if(!( ListaVacia()))
    {
        i=1;
        while ((i!= Pos) &(aux->siguiente !=NULL))
        {
            aux = aux->siguiente;
            i++;
        }
        if ((i==Pos)& (aux->valor ==Elem))
            cout<<"Elemento si encontrado"<<endl;
        else
            cout<<"Elemento no encontrado"<<endl;
    }
    else
        cout<<"Lista vacia"<<endl;

}
//SUMA DOS LISTAS DE IGUAL TAMAÑO
void lista::Sumar(lista &L1, lista &L2){
    if ((L1.primero == NULL) || (L2.primero == NULL)){// ListaVacia(L1)
        cout<<"Algunas lista esta vacia"<<endl;
    }
    else{
        int largo1 = L1.largoLista();
        int largo2 = L2.largoLista();

        if(largo1 == largo2)
        {

            pnodo Aux1 = L1.primero;
            pnodo Aux2 = L2.primero;
            int suma=0;
            while(Aux1!=NULL)
            {
                suma= Aux1->valor+Aux2->valor;
                InsertarFinal(suma);
                Aux1= Aux1->siguiente;
                Aux2= Aux2->siguiente;
            }
        }
        else{
            cout<<"Las listas no son iguales"<<endl;
        }
    }
}

/*SUMA DOS LISTA DE DIFERENTE TAMAÑO
void lista::SumarListasTamD(lista &L1,lista &L2)
{

    pnodo Aux1=L1.primero;
    pnodo Aux2=L2.primero;

    while(Aux1!=NULL || Aux2!=NULL)
    {
      if(Aux1==NULL && Aux2!= NULL)
      {
          InsertarFinal(Aux2->valor);
          Aux2=Aux2->siguiente;
      }
      else
      {
          if(Aux1!=NULL && Aux2==NULL)
          {
            InsertarFinal(Aux1->valor);
            Aux1=Aux1->siguiente;
          }
          else
          {
            int suma=0;
            suma= Aux1->valor+Aux2->valor;
            InsertarFinal(suma);
            Aux1=Aux1->siguiente;
            Aux2=Aux2->siguiente;
          }

     }

    }
}
*/
