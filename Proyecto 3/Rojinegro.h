#define BLACK 1
#define RED 0
#include <iostream>
 
using namespace std;
 
class bst {
	
private:
	
    struct Node {
        int CodMarca;
        int CodPasillo;
        int CodProducto;
        string Nombre;
        int CantidadGondola;
        int Precio;
        bool color;
        Node *leftTree, *rightTree, *parent;
 
        Node() : CodMarca(0), CodPasillo(0), CodProducto(0), Nombre(""), Precio(0), CantidadGondola(0), color(RED), leftTree(NULL), rightTree(NULL), parent(NULL) { }        

        Node* grandparent() {
            if(parent == NULL){
                return NULL;
            }
            return parent->parent;
        }
 
        Node* uncle() {
            if(grandparent() == NULL) {
                return NULL;
            }
            if(parent == grandparent()->rightTree)
                return grandparent()->leftTree;
            else
                return grandparent()->rightTree;
        }
 
        Node* sibling() {
            if(parent->leftTree == this)
                return parent->rightTree;
            else
                return parent->leftTree;
        }
    };
    void rotate_right(Node *p){
        Node *gp = p->grandparent();
        Node *fa = p->parent;
        Node *y = p->rightTree;
 
        fa->leftTree = y;
 
        if(y != NIL)
            y->parent = fa;
        p->rightTree = fa;
        fa->parent = p;
 
        if(root == fa)
            root = p;
        p->parent = gp;
 
        if(gp != NULL){
            if(gp->leftTree == fa)
                gp->leftTree = p;
            else
                gp->rightTree = p;
        }
 
    }
 
    void rotate_left(Node *p){
        if(p->parent == NULL){
            root = p;
            return;
        }
        Node *gp = p->grandparent();
        Node *fa = p->parent;
        Node *y = p->leftTree;
 
        fa->rightTree = y;
 
        if(y != NIL)
            y->parent = fa;
        p->leftTree = fa;
        fa->parent = p;
 
        if(root == fa)
            root = p;
        p->parent = gp;
 
        if(gp != NULL){
            if(gp->leftTree == fa)
                gp->leftTree = p;
            else
                gp->rightTree = p;
        }
    }
 
    void inorder(Node *p){
        if(p == NIL)
            return;
 
        if(p->leftTree)
            inorder(p->leftTree);
 
        cout<<endl<<"Numero de marca: "<<p->CodMarca<<"   Nombre de la marca: "<<p->Nombre<< "";        
        if(p->rightTree)
            inorder(p->rightTree);
    }
 	
 	void buscarPrecio(Node *p, int pCodMarca){
 		if(p == NIL)
            return;
 		if(p->CodMarca == pCodMarca){
 			cout<<endl<<"Numero de la marca: "<<p->Nombre<<"   Precio: "<<p->Precio<< "";
		}
        if(p->leftTree){
        	buscarPrecio(p->leftTree, pCodMarca);
		}
                    
        if(p->rightTree){
        	buscarPrecio(p->rightTree, pCodMarca);
		}
            
	}
	
	int buscarPrecio2(Node *p, int pCodMarca){
 		if(p == NIL)
            return 0;
 		if(p->CodMarca == pCodMarca){
 			return p->Precio;
		}
        if(p->leftTree){
        	buscarPrecio2(p->leftTree, pCodMarca);
		}
                    
        if(p->rightTree){
        	buscarPrecio2(p->rightTree, pCodMarca);
		}
            
	}
	
	void modificarPrecio(Node *p, int pCodMarca){
		int precio;
 		if(p == NIL)
            return;
 
        if(p->leftTree && (p->CodMarca == pCodMarca)){
        	modificarPrecio(p->leftTree, pCodMarca);
        	cout<<"Digite el precio nuevo que desea ingresar: ";
        	cin>>precio;
        	p->Precio = precio;
 			cout<<endl<<"Numero de la marca: "<<p->Nombre<<"   Precio: "<<p->Precio<< "";
		}
                    
        if(p->rightTree)
            modificarPrecio(p->rightTree, pCodMarca);
	}
	
	void modificarNombre(Node *p, int pCodMarca){
		string nombre;
 		if(p == NIL)
            return;
        if(p->leftTree && (p->CodMarca == pCodMarca)){
        	modificarNombre(p->leftTree, pCodMarca);
        	cout<<"Digite el nombre nuevo que desea ingresar (No ingresar espacios): ";
        	cin>>nombre;
        	p->Nombre = nombre;
 			cout<<endl<<"Numero de la marca: "<<p->Nombre<<"   Precio: "<<p->Precio<< "";
 			return;
		}          
        if(p->rightTree)
            modificarNombre(p->rightTree, pCodMarca);
	}
	
	
	bool BuscarMarcaC(Node *p, int pCodMarca){
		bool encontrado = false;
		if(p != NULL){
			if(pCodMarca > p-> CodMarca){
				p= p->rightTree;
				BuscarMarcaC(p, pCodMarca);
			}
			else if(pCodMarca < p-> CodMarca){
				p= p->leftTree;
				BuscarMarcaC(p, pCodMarca);
			}
			else{
				encontrado = true;
				return encontrado;
			}
		}
	}
	
	int BuscarGondola(Node *p, int pCodMarca){
		if(p != NULL){
			if(pCodMarca > p-> CodMarca){
				p= p->rightTree;
				BuscarMarcaC(p, pCodMarca);
			}
			else if(pCodMarca < p-> CodMarca){
				p= p->leftTree;
				BuscarMarcaC(p, pCodMarca);
			}
			else{
				return p-> CantidadGondola;
			}
		}
	}
	
    string outputColor (bool color) {
        return color ? "BLACK" : "RED";
    }
 
    Node* getSmallestChild(Node *p){
        if(p->leftTree == NIL)
            return p;
        return getSmallestChild(p->leftTree);
    }
 
    bool delete_child(Node *p, int data){
        if(p->CodMarca > data){
            if(p->leftTree == NIL){
                return false;
            }
            return delete_child(p->leftTree, data);
        } else if(p->CodMarca < data){
            if(p->rightTree == NIL){
                return false;
            }
            return delete_child(p->rightTree, data);
        } else if(p->CodMarca == data){
            if(p->rightTree == NIL){
                delete_one_child (p);
                return true;
            }
            Node *smallest = getSmallestChild(p->rightTree);
            swap(p->CodMarca, smallest->CodMarca);
            delete_one_child (smallest);
 
            return true;
        }else{
           return false;
         }
    }
 
    void delete_one_child(Node *p){
        Node *child = p->leftTree == NIL ? p->rightTree : p->leftTree;
        if(p->parent == NULL && p->leftTree == NIL && p->rightTree == NIL){
            p = NULL;
            root = p;
            return;
        }
        
        if(p->parent == NULL){
            delete  p;
            child->parent = NULL;
            root = child;
            root->color = BLACK;
            return;
        }
        
        if(p->parent->leftTree == p){
            p->parent->leftTree = child;
        } else {
            p->parent->rightTree = child;
        }
        child->parent = p->parent;
 
        if(p->color == BLACK){
            if(child->color == RED){
                child->color = BLACK;
            } else
                delete_case (child);
        }
 
        delete p;
    }
 
    void delete_case(Node *p){
        if(p->parent == NULL){
            p->color = BLACK;
            return;
        }
        if(p->sibling()->color == RED) {
            p->parent->color = RED;
            p->sibling()->color = BLACK;
            if(p == p->parent->leftTree)
                rotate_left(p->sibling());
            else
                rotate_right(p->sibling());
        }
        if(p->parent->color == BLACK && p->sibling()->color == BLACK
                && p->sibling()->leftTree->color == BLACK && p->sibling()->rightTree->color == BLACK) {
            p->sibling()->color = RED;
            delete_case(p->parent);
        } else if(p->parent->color == RED && p->sibling()->color == BLACK
                && p->sibling()->leftTree->color == BLACK && p->sibling()->rightTree->color == BLACK) {
            p->sibling()->color = RED;
            p->parent->color = BLACK;
        } else {
            if(p->sibling()->color == BLACK) {
                if(p == p->parent->leftTree && p->sibling()->leftTree->color == RED
                        && p->sibling()->rightTree->color == BLACK) {
                    p->sibling()->color = RED;
                    p->sibling()->leftTree->color = BLACK;
                    rotate_right(p->sibling()->leftTree);
                } else if(p == p->parent->rightTree && p->sibling()->leftTree->color == BLACK
                        && p->sibling()->rightTree->color == RED) {
                    p->sibling()->color = RED;
                    p->sibling()->rightTree->color = BLACK;
                    rotate_left(p->sibling()->rightTree);
                }
            }
            p->sibling()->color = p->parent->color;
            p->parent->color = BLACK;
            if(p == p->parent->leftTree){
                p->sibling()->rightTree->color = BLACK;
                rotate_left(p->sibling());
            } else {
                p->sibling()->leftTree->color = BLACK;
                rotate_right(p->sibling());
            }
        }
    }
 
    void insert(Node *p, int pCodPasillo, int pCodProducto, int data, string pNombre, int pCantidadGondola, int pPrecio){
        if(p->CodMarca > data){
            if(p->leftTree != NIL)
                insert(p->leftTree, pCodPasillo, pCodProducto, data, pNombre, pCantidadGondola, pPrecio);
            else {
                Node *tmp = new Node();
                tmp->CodMarca = data;
                tmp->CodPasillo = pCodPasillo;
                tmp->CodProducto = pCodProducto;
                tmp->CantidadGondola = pCantidadGondola;
                tmp->Precio = pPrecio;
                tmp->Nombre = pNombre;
                tmp->leftTree = tmp->rightTree = NIL;
                tmp->parent = p;
                p->leftTree = tmp;
                insert_case (tmp);
            }
        } else if(p->CodMarca < data){
            if(p->rightTree != NIL)
                insert(p->rightTree, pCodPasillo, pCodProducto, data, pNombre, pCantidadGondola, pPrecio);
            else {
                Node *tmp = new Node();
                tmp->CodMarca = data;
                tmp->CodPasillo = pCodPasillo;
                tmp->CodProducto = pCodProducto;
                tmp->CantidadGondola = pCantidadGondola;
                tmp->Precio = pPrecio;
                tmp->Nombre = pNombre;
                tmp->leftTree = tmp->rightTree = NIL;
                tmp->parent = p;
                p->rightTree = tmp;
                insert_case (tmp);
            }
        }
    }
 
    void insert_case(Node *p){
        if(p->parent == NULL){
            root = p;
            p->color = BLACK;
            return;
        }
        if(p->parent->color == RED){
            if(p->uncle()->color == RED) {
                p->parent->color = p->uncle()->color = BLACK;
                p->grandparent()->color = RED;
                insert_case(p->grandparent());
            } else {
                if(p->parent->rightTree == p && p->grandparent()->leftTree == p->parent) {
                    rotate_left (p);
                    rotate_right (p);
                    p->color = BLACK;
                    p->leftTree->color = p->rightTree->color = RED;
                } else if(p->parent->leftTree == p && p->grandparent()->rightTree == p->parent) {
                    rotate_right (p);
                    rotate_left (p);
                    p->color = BLACK;
                    p->leftTree->color = p->rightTree->color = RED;
                } else if(p->parent->leftTree == p && p->grandparent()->leftTree == p->parent) {
                    p->parent->color = BLACK;
                    p->grandparent()->color = RED;
                    rotate_right(p->parent);
                } else if(p->parent->rightTree == p && p->grandparent()->rightTree == p->parent) {
                    p->parent->color = BLACK;
                    p->grandparent()->color = RED;
                    rotate_left(p->parent);
                }
            }
        }
    }
 
    void DeleteTree(Node *p){
        if(!p || p == NIL){
            return;
        }
        DeleteTree(p->leftTree);
        DeleteTree(p->rightTree);
        delete p;
    }
public:
 
    bst() {
        NIL = new Node();
        NIL->color = BLACK;
        root = NULL;
    }
 
    ~bst() {
        if (root)
            DeleteTree (root);
        delete NIL;
    }
 
    void inorder() {
        if(root == NULL)
            return;
        inorder (root);
        cout << endl;
    }
    
    void buscarPrecio(int pCodMarca){
    	if(root == NULL)
            return;
        buscarPrecio(root, pCodMarca);
	}
	
	 int buscarPrecio2(int pCodMarca){
    	if(root == NULL)
            return 0;
        return buscarPrecio2(root, pCodMarca);
	 }
	
	void modificarPrecio(int pCodMarca){
    	if(root == NULL)
            return;
        modificarPrecio(root, pCodMarca);
	}

	void modificarNombre(int pCodMarca){
    	if(root == NULL)
            return;
        modificarNombre(root, pCodMarca);
	}
	
	bool BuscarMarcaC(int pCodMarca){
		if(root == NULL)
            return false;
        return BuscarMarcaC(root, pCodMarca);
	}
	
	int BuscarGondola(int pCodMarca){
		if(root == NULL)
            return 0;
        return BuscarGondola(root, pCodMarca);
	}

    void insert (int pCodPasillo, int pCodProducto, int x, string pNombre, int pCantidadGondola, int pPrecio) {
        if(root == NULL){
            root = new Node();
            root->color = BLACK;
            root->leftTree = root->rightTree = NIL;
            root->CodMarca = x;
            root->CodPasillo = pCodPasillo;
            root->CodProducto = pCodProducto;
            root->CantidadGondola = pCantidadGondola;
            root->Precio = pPrecio;
            root->Nombre = pNombre;
        } else {
            insert(root, pCodPasillo, pCodProducto, x, pNombre, pCantidadGondola, pPrecio);
        }
    }
 
    bool delete_CodMarca (int data) {
        return delete_child(root, data);
    }
    
    bool Vacio(){
    	return root==NULL;
	}
    	
private:
    Node *root, *NIL;
    
    friend class ArbolAVL;
	friend class NodoAVL;
};

