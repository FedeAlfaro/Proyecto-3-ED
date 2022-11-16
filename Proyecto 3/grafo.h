#include "lista.h"

struct Grafo{
   	ListaSimple* vertices;
   	Grafo(){
    	vertices = new ListaSimple();       
   	} 
   	void insertarVertice(int d, string e);
   	void insertarArista(int origen, int destino, int peso);
   	void imprimir();
   	void borrarArista(int origen, int destino);
   	void borrarVertice(int dato);
   	void visitarVertice(int dato);
   	bool visitadoVertice(int dato);
   	void limpiarVisitados();
   	void visitarAdyacentes(int nodo);
   	void profundidad(Nodo * v);
   	void anchura(Nodo * v);
   	void Dijkstra(Nodo * origen, Nodo * destino);
   	void Prim(Nodo * origen);
   	void Kruskal(Nodo * origen);
   	void PuntosDeArticulacion(Nodo * origen);
   	int buscarPesoAdyacenteMayor(Nodo * nodos[]);
   	//void holiwis(Nodo * nodito);
   	bool verificarCiclo(Nodo * noditoOrigen, Nodo * noditoDestino, bool &bandera);
   	void limpiarVisitadosAristas();
};
   	// para insertar un vertice
void Grafo::insertarVertice(int d, string e){
    // valida que no exista
    Nodo * tmp = vertices->buscar(d);
    // si es null no existe, lo inserta
    if (tmp == NULL){
        // solo llama a insertar de lista            
        vertices->insertarAlFinal(d, e);
    }
    else{
        cout << "El nodo "<< d << "ya existe"<<endl;    
    }
} 
   
void Grafo::insertarArista(int origen, int destino, int peso){
    // si existe el vertice inserta
    Nodo * tmp = vertices->buscar(origen);
    Nodo * tmpDest = vertices->buscar(destino);
    if(tmp != NULL){
    	if(tmpDest != NULL){
            // si la arista no existe       
            Arista * arista = tmp->aristas->buscar(destino);
            if (arista == NULL){
               tmp->aristas->insertarAlFinal(destino, origen, peso);
			   tmpDest->aristas->insertarAlFinal(origen, destino, peso);           
           	}else{
               cout << "Arista ya existe"<<endl;    
            }
       	}else{
            cout << "Destino no existe"<<endl;    
        } 
    }else{
    	cout << "Nodo origen no existe"<< endl;    
    }
}
       

// IMPRIMIR IMPRIMIR IMPRIMIR       
void Grafo::imprimir(){
    Nodo * tmp = vertices->primerNodo;
    while(tmp != NULL){
        cout << tmp->nombreCiudad <<": ";
        tmp->aristas->imprimir();
        cout << endl; 
        tmp = tmp -> siguiente;  
    }     
}
// BORRAR ARISTA  BORRAR ARISTA
void Grafo::borrarArista(int origen, int destino){
	Nodo * tmp = vertices->buscar(origen);     
	if(tmp != NULL){
        int posA = tmp->aristas->posicion(destino);
        if(posA > -1){
           tmp->aristas->borrarEnPosicion(posA);
           cout << "Eliminada arista "<<origen<<" - "<< destino<<endl;         
        }           
    }     
}       

// BORRAR BORRAR BORRAR

void Grafo::borrarVertice(int dato){
     // se usan las funciones de lista
    int posV = vertices->posicion(dato);
     // si lo encontro, posV es <> -1
    if(posV > -1){
        //recorre toda la lista de vertices
        // eliminando aristas a dato    
        Nodo * tmp = vertices->primerNodo;
        while(tmp != NULL){
            // usa borrar arista
            borrarArista(tmp->codCiudad, dato);
            tmp = tmp->siguiente;      
        }    
        // ya borro las aristas, ahora el vertice
        vertices->borrarEnPosicion(posV);
    }
    else{
        cout << "Vertice no existe"<<endl;    
    }

}

// visitar vertice
void Grafo::visitarVertice(int dato){
    Nodo * tmp = vertices->buscar(dato);
	if(tmp != NULL)
    	tmp->visitado = true;     
}

// visitar vertice
bool Grafo::visitadoVertice(int dato){
    Nodo * tmp = vertices->buscar(dato);
    if(tmp != NULL)
    	return tmp->visitado;
    else
        return false;     
}

// limpiar visitados
void Grafo::limpiarVisitados(){
    Nodo * tmp = vertices->primerNodo;
    while(tmp != NULL){
        tmp->visitado = false;
        tmp = tmp->siguiente;      
    }     
}

void Grafo::limpiarVisitadosAristas(){
	Nodo * tmp = vertices->primerNodo;
	while(tmp != NULL){
		Arista * aux = tmp->aristas->primerNodo;
		while(aux != NULL){
			aux->visitado = false;
			aux = aux->siguiente;
		}
		tmp = tmp->siguiente;
	}
}

// visitar Adyacentes

void Grafo::visitarAdyacentes(int nodo){
    // visita el nodo
    visitarVertice(nodo);
    cout << nodo << "  " ;     
    // busca el vertice para recorrer aristas
    Nodo * tmp = vertices->buscar(nodo); 
    if(tmp != NULL){
        // recorre las lista de adyacencia
        Arista * actual = tmp->aristas->primerNodo;
        while(actual!=NULL){
            // si no esta visitado
            if(visitadoVertice(actual->codCiudadOrigen)==false){
                visitarAdyacentes(actual->codCiudadOrigen);
            }
            actual = actual->siguiente;      
        }        
    }     
}

/*
Nodo* Grafo::VisitarAdyacentesUnoPorUno(Nodo * Nodito){
	//visita el nodo
	visitarVertice(nodito->codCiudad);
	if(nodito != NULL){
		
	}
}
*/
// PROFUNDIDAD - Recorrido por profundidad

void Grafo::profundidad(Nodo * v){
    // hace un while de n para recorrer todos
    // aun cuando el grafo es disconexo
    while(v != NULL){
        if(v->visitado == false)
            visitarAdyacentes(v->codCiudad);          
        v = v->siguiente;
    }
    limpiarVisitados();
}

// ANCHURA - recorrido anchura
//se le da el vertice de inicio
void Grafo::anchura(Nodo * v){
    cout << v->codCiudad << "  " ;
    visitarVertice(v->codCiudad);// marca el primer nodo
    ListaSimple * cola = new ListaSimple();
    // mete a la cola los adyacentes del nodo inicial
    Arista * aristaTmp = v->aristas->primerNodo;
    while(aristaTmp != NULL){
        // encola
        cola->encolar(aristaTmp->codCiudadOrigen, v->nombreCiudad);
        // visita el nodo
        visitarVertice(aristaTmp->codCiudadOrigen);
        aristaTmp = aristaTmp -> siguiente;                
	}
     // mientras no se vacíe la cola
    while(cola->primerNodo !=NULL){
        // trabaja con el primero de la cola
        Nodo * actual = cola->desencolar();
        visitarVertice(actual->codCiudad);
        // imprime el vertice
        cout << actual->codCiudad << "  ";
        // para cada arista del vertice en la cola
        // va a meter a la cola los adyacentes
        Nodo * nodoCola = vertices->buscar(actual->codCiudad);
        Arista * aristaTmp = nodoCola->aristas->primerNodo;
        while(aristaTmp != NULL){
              // si no se ha visitado, se mete en cola
              if(visitadoVertice(aristaTmp->codCiudadOrigen) == false){
                 visitarVertice(aristaTmp->codCiudadOrigen);
                 cola->encolar(aristaTmp->codCiudadOrigen, v->nombreCiudad);                       
              }     
              aristaTmp = aristaTmp->siguiente;
        }
    }
    limpiarVisitados();        
}  

void Grafo::Dijkstra(Nodo * origen, Nodo * destino){
	//se lipian los visitados
	limpiarVisitados();
	//se inicializa el vector de distancias
	int distancias[100];
	Nodo *nodosVisitados[100];
	Nodo *nodosNoVisitados[100];
	Nodo *ruta[100];
	int resultado = 0;
	//se inicializan todos los espacios del vector en 0
	for(int i = 0; i<sizeof(distancias)/sizeof(distancias[0]); i++){
		distancias[i] = 0;
	}
	if(origen != destino){
		
	}
	for(int i = 0; i<sizeof(distancias)/sizeof(distancias[0]); i++){
		resultado += distancias[i]; 
	}
	cout<<resultado<<endl;
}  

void Grafo::Prim(Nodo * origen){
	//cantidad de nodos en el grafo
	//Nodo *nodos[100];
	//cantidad de nodos visitados
	Nodo *visitado[100];
	int i = 0;
	int pesoSeleccionado;
	int costo = 0;
	int largo = 0;
	string resultado = "";
	string resultadoTmp = "";
	Nodo * nodoAux;
	Nodo * nodoSeleccionado;
	Arista * aux;
	//recorre todos los nodos del grafo
	for(int i = 0; i<sizeof(visitado)/sizeof(visitado[0]); i++){
		visitado[i] = NULL;
	}
	while(origen != NULL){	
		//verifica si ya origen se visito
		if(origen->visitado == false){
			visitado[i] = origen;
			origen->visitado = true;
			pesoSeleccionado = 0;
			largo = 0;
			for(int k = 0; k<sizeof(visitado)/sizeof(visitado[0]); k++){
				if(visitado[k] != NULL){
					largo++;
				}
			}
			//recorre los nodos visitados buscando el menor peso para determinar la ruta
			for(int j = 0; j<largo; j++){
				//aux va a ser el primer nodo adyacente de origen
				nodoAux = visitado[j];
				aux = nodoAux->aristas->primerNodo;
				//recorre todos los nodos adyacentes de origen
				while(aux != NULL){
					//verifica el peso menor de los adyacentes no visitados y escoge el peso menor para visitarlo
					if(pesoSeleccionado != 0 && aux->peso <= pesoSeleccionado && vertices->buscar(aux->codCiudadOrigen)->visitado == false){
						nodoSeleccionado = vertices->buscar(aux->codCiudadOrigen);
						pesoSeleccionado = aux->peso;
						resultadoTmp = nodoAux->nombreCiudad + " ==> " + vertices->buscar(aux->codCiudadOrigen)->nombreCiudad;
					}else if(pesoSeleccionado == 0 && vertices->buscar(aux->codCiudadOrigen)->visitado == false){
						nodoSeleccionado = vertices->buscar(aux->codCiudadOrigen);
						pesoSeleccionado = aux->peso;
						resultadoTmp = nodoAux->nombreCiudad + " ==> " + vertices->buscar(aux->codCiudadOrigen)->nombreCiudad;
					}
					aux = aux->siguiente;
				}
			}
			//se almacena resultados
			resultado += resultadoTmp + "\n";
			resultadoTmp = "";	
			costo += pesoSeleccionado;
		}
		origen = nodoSeleccionado;
		nodoSeleccionado = NULL;
		i++;
	}
	//enviar resultados al archivo
	cout<<"Costo: "<<costo<<endl;
	cout<<resultado<<endl;
	//se limpian los visitados para poder usarlos en otro algoritmo
	limpiarVisitados();
}
int Grafo::buscarPesoAdyacenteMayor(Nodo * nodos[]){
	int i = 0;
	Arista * aux;
	Nodo * nodoAux;
	int pesoSeleccionado = 0;
	while(nodos[i] != NULL){
		nodoAux = nodos[i];
		aux = nodoAux->aristas->primerNodo;
		while(aux != NULL){
			if(aux->peso > pesoSeleccionado){
				pesoSeleccionado = aux->peso;
			}
			aux = aux->siguiente;
		}
		i++;
	}
	return pesoSeleccionado;
}

bool Grafo::verificarCiclo(Nodo * noditoOrigen, Nodo * noditoDestino, bool &bandera){
	Arista * aux = noditoOrigen->aristas->primerNodo;
	if(bandera == false){
		while(aux != NULL){
			if(aux->visitado == true){
				//cout<<"Holis"<<endl;
				if(vertices->buscar(aux->codCiudadOrigen) == noditoDestino){
					bandera = true;
					return bandera;
				}else{
					verificarCiclo(vertices->buscar(aux->codCiudadOrigen), noditoDestino, bandera);	
				}
			}
			aux = aux->siguiente;
		}
	}
	cout<<bandera<<endl;
	return bandera;
}


void Grafo::Kruskal(Nodo * origen){
	//cantidad de nodos en el grafo
	Nodo *nodos[100];
	//cantidad de nodos visitados
	Nodo *visitado[100];
	//cantidad de nodos adyacentes que cumplen con el AEM
	Nodo *adyacentes[100];
	//cantidad de aristas que cumplen con el AEM
	Arista *visitada[100];
	//se inicializan todos los nodos en NULL
	for(int i = 0; i<sizeof(nodos)/sizeof(nodos[0]); i++){
		nodos[i] = NULL;
	}
	for(int i = 0; i<sizeof(visitado)/sizeof(visitado[0]); i++){
		visitado[i] = NULL;
	}
	for(int i = 0; i<sizeof(adyacentes)/sizeof(adyacentes[0]); i++){
		adyacentes[i] = NULL;
	}
	for(int i = 0; i<sizeof(visitada)/sizeof(visitada[0]); i++){
		visitada[i] = NULL;
	}
	Arista * aux;
	Arista * aristaSeleccionada;
	Nodo * nodoAux;
	Nodo * nodoSeleccionado;
	int i = 0, j = 0, k = 0;
	int largo = 0;
	int costo = 0;
	string verticesOrdenados[100];
	for(int i = 0; i<sizeof(verticesOrdenados)/sizeof(verticesOrdenados[0]); i++){
		verticesOrdenados[i] = "";
	}
	//se guardan todos los nodos del grafo en nodos[]
	while(origen != NULL){
		if(nodos[0] != NULL){
			for(j = 0; j<sizeof(nodos)/sizeof(nodos[0]); j++){
				if(nodos[j] != NULL){
					largo++;
				}
			}
			j = 0;
			for(k = 0; k<1; k++){
				nodoAux = nodos[i];
				aux = nodoAux->aristas->primerNodo;
				while(aux != NULL){
					if(vertices->buscar(aux->codCiudadOrigen)->visitado == false){
						vertices->buscar(aux->codCiudadOrigen)->visitado = true;
						nodos[largo+j] = vertices->buscar(aux->codCiudadOrigen);
						j++;
					}
					aux = aux->siguiente;	
				}	
			}	
		}else{
			nodos[i] = origen;
			origen->visitado = true;
			for(j = 0; j<sizeof(nodos)/sizeof(nodos[0]); j++){
				if(nodos[j] != NULL){
					largo++;
				}
			}
			j = 0; 
			for(k = i; k<1; k++){
				nodoAux = nodos[k];
				aux = nodoAux->aristas->primerNodo;
				j = 1;
				while(aux != NULL){
					if(vertices->buscar(aux->codCiudadOrigen)->visitado == false){
						vertices->buscar(aux->codCiudadOrigen)->visitado = true;
						nodos[k+j] = vertices->buscar(aux->codCiudadOrigen);
					}
					aux = aux->siguiente;
					j++;
				}
			}
		}
		largo = 0;
		i++;
		origen = nodos[i];
	}
	limpiarVisitados();
	i = 0, j = 1, k = 0;
	int m = 0, n = 0;
	int largoNodos = 0;
	for(i = 0; i<sizeof(nodos)/sizeof(nodos[0]); i++){
		if(nodos[i] != NULL){
			largoNodos++;
		}
	}
	largoNodos = (largoNodos-1)*2;
	i = 0;
	//lista de adyacencias ordenada y AEM
	bool bandera = false;
	while(j <= buscarPesoAdyacenteMayor(nodos)){
		if(m < largoNodos){	
			while(nodos[i] != NULL){
				nodoAux = nodos[i];
				aux = nodoAux->aristas->primerNodo;
				while(aux != NULL){
					if(aux->peso == j){
						verticesOrdenados[k] = nodoAux->nombreCiudad + " - " + vertices->buscar(aux->codCiudadOrigen)->nombreCiudad + ": " + to_string(aux->peso);
						k++;
						if(aux->visitado == false){
							if(nodoAux->visitado == false){
								aux->visitado = true;
								nodoAux->visitado = true;
								visitada[m] = aux;
								if(m != 0){
									aristaSeleccionada = visitada[m-1];
									if(vertices->buscar(aux->codCiudadOrigen) != vertices->buscar(aristaSeleccionada->codCiudadDestino) && vertices->buscar(aristaSeleccionada->codCiudadOrigen) != vertices->buscar(aux->codCiudadDestino)){
										bandera = true;
									}
								}else{
									costo += aux->peso;
								}	
								if(bandera){
									costo += aux->peso;
								}
								bandera = false;
								m++;
							}else if(nodoAux->visitado == true && vertices->buscar(aux->codCiudadOrigen)->visitado == false){
								vertices->buscar(aux->codCiudadOrigen)->visitado = true;
								visitada[m] = aux;
								if(m != 0){
									aristaSeleccionada = visitada[m-1];
									if(vertices->buscar(aux->codCiudadOrigen) != vertices->buscar(aristaSeleccionada->codCiudadDestino) && vertices->buscar(aristaSeleccionada->codCiudadOrigen) != vertices->buscar(aux->codCiudadDestino)){
										bandera = true;
									}
								}
								if(bandera){
									costo += aux->peso;
								}
								bandera = false;
								m++;
							}else{
								//verificar ciclo
								aristaSeleccionada = visitada[m-1];
								if(vertices->buscar(aux->codCiudadOrigen) != vertices->buscar(aristaSeleccionada->codCiudadDestino) && vertices->buscar(aristaSeleccionada->codCiudadOrigen) != vertices->buscar(aux->codCiudadDestino)){
									bool &banderita = bandera;
									if(!verificarCiclo(nodoAux,vertices->buscar(aux->codCiudadOrigen), banderita)){
										visitada[m] = aux;
										m++;
									}
								}
								else{
									visitada[m] = aux;
									m++;
								}
							}
						}
					}
					aux = aux->siguiente;
				}
				i++;
			}
			i = 0;
		}
		j++;
	}
	limpiarVisitados();
	limpiarVisitadosAristas();
	for(j = 0; j<sizeof(verticesOrdenados)/sizeof(verticesOrdenados[0]); j++){
		if(verticesOrdenados[j] != ""){
			largo++;
		}
	}
	for(i = 0; i<largo; i++){
		if(verticesOrdenados[i] != ""){
			string holi = verticesOrdenados[i]+"\n";
			cout<<holi<<endl;
		}
	}
	
	largo = 0;
	for(n = 0; n<sizeof(visitada)/sizeof(visitada[0]); n++){
		if(visitada[n] != NULL){
			largo++;
		}
	}
	string holi = "";
	for(i = 0; i<largo; i++){
		if(visitada[i] != NULL){
			if(i%2 == 0){
				nodoAux = vertices->buscar(visitada[i]->codCiudadDestino);
				holi += nodoAux->nombreCiudad;
			}else{
				nodoAux = vertices->buscar(visitada[i]->codCiudadDestino);
				holi += " ==> " + nodoAux->nombreCiudad + "\n";
			}
		}
	}
	cout<<holi<<endl;
	cout<<"Costo: "<<costo<<endl;
}

void Grafo::PuntosDeArticulacion(Nodo * origen){
	/*
		visitados.add(v) pone visitado en true
		hijos = 0 crea la variable hijos
		for w in grafo.adyacentes(v) revisa los adyacentes del vertice
			if w not in visitados: si no esta visitado
				orden[w] = orden[v] + 1     agrega a orden 1
				hijos += 1  suma uno a hijos
				puntos_articulacion(grafo, w, visitados, false, orden, mas_bajo, p_art) llama recursivamente la funcion para revisar el nodo que se acaba de visitar
				if mas_bajo[w] >= orden[v] 
					p_art.add(v) lo agrega a los puntos de articulacion
				mas_bajo[v] = min(mas_bajo[v], mas_bajo[w]) establece el nodo mas abajo en el orden
			else:
				mas_bajo[v] = min(mas_bajo[w], mas_bajo[v]) establece el nodo mas abajo en el orden
		if es_raiz and hijos > 1: si es raiz y tiene mas de un hijo
			p_art.add(v) se agrega a los puntos de articulacion
	
	*/
}
// fin struct




