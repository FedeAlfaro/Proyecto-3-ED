#pragma once
#include <msclr\marshal_cppstd.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "Binario.h"
#include "Pila.h"
#include "Clientes.h"
#include "Pasillos.h"

#include "grafo.h"

namespace Proyecto3Pruebita {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;


	Binario A1;
	Binario A2;
	ArbolC AC;
	ArbolC AAdmin;
	ArbolC Vendedor;
	Grafo* g = new Grafo();

	char primerCaracter;
	char caracterActual;
	char caracterSiguiente;
	string linea, linea1, linea2, linea3, linea4, linea5;
	bool terminar = false;
	 
	LSCompras LCompras;
	ListaReportes LR;
	ListaReportes CR;



	int pCedula;
	int pCantidadProducto;
	int pCodPasillo;
	int pCodProducto;
	int pCodMarca;

	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:

		MenuPrincipal(void)
		{


			InitializeComponent();
			string nombreArchivo1 = "Pasillos.txt";
			string nombreArchivo2 = "ProductosPasillos.txt";
			string nombreArchivo3 = "MarcasProductos.txt";
			string nombreArchivo4 = "Inventario.txt";
			string nombreArchivo5 = "Clientes.txt";
			string nombreArchivo6 = "Administradores.txt";
			string linea;
			string nombreArchivo7 = "Ciudades.txt";
			string nombreArchivo8 = "Conexiones.txt";
			string nombreArchivo9 = "Vendedores.txt";
			ifstream archivo9(nombreArchivo9.c_str());
			ifstream archivo7(nombreArchivo7.c_str());
			ifstream archivo8(nombreArchivo8.c_str());
			ifstream archivo1(nombreArchivo1.c_str());
			ifstream archivo2(nombreArchivo2.c_str());
			ifstream archivo3(nombreArchivo3.c_str());
			ifstream archivo4(nombreArchivo4.c_str());
			ifstream archivo5(nombreArchivo5.c_str());
			ifstream archivo6(nombreArchivo6.c_str());

			while (getline(archivo7, linea)) {
				string codCiudad = "";
				string nombreCiudad = "";
				primerCaracter = linea[0];
				int largoLinea = 0;
				bool bandera = false;
				while (linea[largoLinea] != NULL) {
					caracterActual = linea[largoLinea];
					if (caracterActual == ';') {
						bandera = true;
						largoLinea++;
						caracterActual = linea[largoLinea];
					}
					if (!bandera) {
						codCiudad += caracterActual;
					}
					else {
						nombreCiudad += caracterActual;
					}
					largoLinea++;
				}
				g->insertarVertice(stoi(codCiudad), nombreCiudad);
			}

			while (getline(archivo8, linea)) {
				string codCiudadOrigen = "";
				string codCiudadDestino = "";
				string peso = "";

				primerCaracter = linea[0];
				int largoLinea = 0;
				int bandera = 0;
				while (linea[largoLinea] != NULL) {
					caracterActual = linea[largoLinea];
					if (caracterActual == ';') {
						bandera += 1;
						largoLinea++;
						caracterActual = linea[largoLinea];
					}switch (bandera) {
					case 0:
						codCiudadOrigen += caracterActual;
						break;
					case 1:
						codCiudadDestino += caracterActual;
						break;
					case 2:
						peso += caracterActual;
						break;
					default:
						cout << "Error al ingresar conexion" << endl;
						break;
					}
					largoLinea++;
				}
				g->insertarArista(stoi(codCiudadOrigen), stoi(codCiudadDestino), stoi(peso));
			}

			while (getline(archivo9, linea)) {
				string codigoVendedor = "";
				string nombre = "";
				primerCaracter = linea[0];
				int largoLinea = 0;
				bool bandera = false;
				while (linea[largoLinea] != NULL) {
					caracterActual = linea[largoLinea];
					if (caracterActual == ';') {
						bandera = true;
						largoLinea++;
						caracterActual = linea[largoLinea];
					}
					if (!bandera) {
						codigoVendedor += caracterActual;
					}
					else {
						nombre += caracterActual;
					}
					largoLinea++;
				}
				//insertar Arbol B administradores
				Vendedor.InsertaNodo(stoi(codigoVendedor), nombre, 0, ""); //###
			}

			//primer archivo

			while (getline(archivo1, linea)) {
				string pasillo = "";
				string nombre = "";
				primerCaracter = linea[0];
				int largoLinea = 0;
				bool bandera = false;
				while (linea[largoLinea] != NULL) {
					caracterActual = linea[largoLinea];
					if (caracterActual == ';') {
						bandera = true;
						largoLinea++;
						caracterActual = linea[largoLinea];
					}
					if (!bandera) {
						pasillo += caracterActual;
					}
					else {
						nombre += caracterActual;
					}
					largoLinea++;
				}
				A1.InsertaNodo(stoi(pasillo), nombre);
				A2.InsertaNodo(stoi(pasillo), nombre);
			}


			//segundo archivo

			while (getline(archivo2, linea)) {
				string pasillo = "";
				string producto = "";
				string nombre = "";

				primerCaracter = linea[0];
				int largoLinea = 0;
				int bandera = 0;
				while (linea[largoLinea] != NULL) {
					caracterActual = linea[largoLinea];
					if (caracterActual == ';') {
						bandera += 1;
						largoLinea++;
						caracterActual = linea[largoLinea];
					}switch (bandera) {
					case 0:
						pasillo += caracterActual;
						break;
					case 1:
						producto += caracterActual;
						break;
					case 2:
						nombre += caracterActual;
						break;
					default:
						cout << "Error al ingresar producto" << endl;
						break;
					}
					largoLinea++;
				}
				//insertar AVL inventarios
				A1.InsertarProductos(A1.raiz, stoi(pasillo), stoi(producto), nombre);
				A2.InsertarProductos(A2.raiz, stoi(pasillo), stoi(producto), nombre);
			}

			

			//tercer archivo

			while (getline(archivo3, linea)) {
				string CodPasillo = "";
				string CodProducto = "";
				string CodMarca = "";
				string Nombre = "";
				string CantidadGondola = "";
				string Precio = "";

				primerCaracter = linea[0];
				int largoLinea = 0;
				int bandera = 0;
				while (linea[largoLinea] != NULL) {
					caracterActual = linea[largoLinea];
					if (caracterActual == ';') {
						bandera += 1;
						largoLinea++;
						caracterActual = linea[largoLinea];
					}switch (bandera) {
					case 0:
						CodPasillo += caracterActual;
						break;
					case 1:
						CodProducto += caracterActual;
						break;
					case 2:
						CodMarca += caracterActual;
						break;
					case 3:
						Nombre += caracterActual;
						break;
					case 4:
						CantidadGondola += caracterActual;
						break;
					case 5:
						Precio += caracterActual;
						break;
					default:
						cout << "Error al ingresar marcas" << endl;
						break;
					}
					largoLinea++;
				}
				A1.InsertarMarcas(A1.raiz, stoi(CodPasillo), stoi(CodProducto), stoi(CodMarca), Nombre, stoi(CantidadGondola), stoi(Precio));
			}

			//cuarto archivo
			while (getline(archivo4, linea)) {

				string CodPasillo = "";
				string CodProducto = "";
				string CodMarca = "";
				string Nombre = "";
				string CantidadStock = "";
				string CodigoCanasta = "";

				primerCaracter = linea[0];
				int largoLinea = 0;
				int bandera = 0;

				while (linea[largoLinea] != NULL) {
					caracterActual = linea[largoLinea];
					if (caracterActual == ';') {
						bandera += 1;
						largoLinea++;
						caracterActual = linea[largoLinea];
					}switch (bandera) {
					case 0:
						CodPasillo += caracterActual;
						break;
					case 1:
						CodProducto += caracterActual;
						break;
					case 2:
						CodMarca += caracterActual;
						break;
					case 3:
						Nombre += caracterActual;
						break;
					case 4:
						CantidadStock += caracterActual;
						break;
					case 5:
						CodigoCanasta += caracterActual;
						break;
					default:
						cout << "Error al ingresar inventarios" << endl;
						break;
					}
					largoLinea++;
				}
				//insertar AAA inventarios
				A2.InsertarInventarios(A2.raiz, stoi(CodPasillo), stoi(CodProducto), stoi(CodMarca), Nombre, stoi(CantidadStock), stoi(CodigoCanasta));
			}

			//quinto archivo

			while (getline(archivo5, linea)) {
				string nombre = "";
				string cedula = "";
				string telefono = "";
				string correo = "";

				primerCaracter = linea[0];
				int largoLinea = 0;
				int bandera = 0;
				while (linea[largoLinea] != NULL) {
					caracterActual = linea[largoLinea];
					if (caracterActual == ';') {
						bandera += 1;
						largoLinea++;
						caracterActual = linea[largoLinea];
					}switch (bandera) {
					case 0:
						cedula += caracterActual;
						break;
					case 1:
						nombre += caracterActual;
						break;
					case 2:
						telefono += caracterActual;
						break;
					case 3:
						correo += caracterActual;
						break;
					default:
						cout << "Error al ingresar producto" << endl;
						break;
					}
					largoLinea++;
				}
				//insertar Arbol B clientes
				AC.InsertaNodo(stoi(cedula), nombre, stoi(telefono), correo);
			}

			//sexto archivo

			while (getline(archivo6, linea)) {
				string codigoAdministrador = "";
				string nombre = "";
				primerCaracter = linea[0];
				int largoLinea = 0;
				bool bandera = false;
				while (linea[largoLinea] != NULL) {
					caracterActual = linea[largoLinea];
					if (caracterActual == ';') {
						bandera = true;
						largoLinea++;
						caracterActual = linea[largoLinea];
					}
					if (!bandera) {
						codigoAdministrador += caracterActual;
					}
					else {
						nombre += caracterActual;
					}
					largoLinea++;
				}
				//insertar Arbol B administradores
				AAdmin.InsertaNodo(stoi(codigoAdministrador), nombre, 0, ""); //###
			}


			int opcion = 0;

		}

	private:
		int contadorsote = 0; //almacena la cantidad de facturas que se han generado y se imprime como consecutivo de cada factura
		String^ facturaMasGrande = "Nadie ha facturado";
		int facturaMasGrandeInt = 0;
		String^ facturaMenosGrande = "Nadie ha facturado";
		int facturaMenosGrandeInt = -1;
		String^ ClienteMasCompro = "Nadie ha facturado";
		String^ ClienteMenosCompro = "Nadie ha facturado";
		int descuento = 5;   //###
	private: System::Windows::Forms::Button^ btnFacturar;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tPInsProd;
	private: System::Windows::Forms::TabPage^ tPModProd;
	private: System::Windows::Forms::TabPage^ tPConsPrecio;
	private: System::Windows::Forms::TabPage^ tPConsDesc;
	private: System::Windows::Forms::TabPage^ tPModDesc;
	private: System::Windows::Forms::TabPage^ tPRegCliente;
	private: System::Windows::Forms::TabControl^ tabControl3;
	private: System::Windows::Forms::TabPage^ tPPasMasVis;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::TabPage^ tPPasMenosVis;
	private: System::Windows::Forms::TabPage^ tPProdPasMas;
	private: System::Windows::Forms::TabPage^ tPMarcasMas;
	private: System::Windows::Forms::TabPage^ tPClienteMasComp;
	private: System::Windows::Forms::TabPage^ tPClienteMenosComp;
	private: System::Windows::Forms::TabPage^ tPMasCargaGondola;
	private: System::Windows::Forms::TabPage^ tPClienteMásFact;
	private: System::Windows::Forms::TabPage^ tPMostrarMarcas;
	private: System::Windows::Forms::TabPage^ tPFacturaMayor;
	private: System::Windows::Forms::TabPage^ tPMostrarProd;
	private: System::Windows::Forms::TabPage^ tPMostrarClientes;
	private: System::Windows::Forms::TabPage^ tPMosPasillos;
	private: System::Windows::Forms::TabPage^ tPMosInventario;
	private: System::Windows::Forms::Label^ lblPasMasVis;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Label^ lblPasilloMenosVis;

	private: System::Windows::Forms::Button^ btnClienteMasComp;


	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label21;


	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::TextBox^ tPCantProd;
	private: System::Windows::Forms::Button^ btnOp2;
	private: System::Windows::Forms::Button^ btnOp1;
	private: System::Windows::Forms::TextBox^ tBCantProdN;

	private: System::Windows::Forms::Label^ lblInsuficienteProd;
private: System::Windows::Forms::Label^ lblClienteActual;
private: System::Windows::Forms::Button^ btnIngresarVend;

private: System::Windows::Forms::TextBox^ textBoxVendedor;

private: System::Windows::Forms::Label^ label25;
private: System::Windows::Forms::TabControl^ tCVendedor;

private: System::Windows::Forms::TabPage^ tPConsPrecioVen;
private: System::Windows::Forms::TabPage^ tPConsDescVen;
private: System::Windows::Forms::TabPage^ tPConsProdXPasVen;
private: System::Windows::Forms::TabPage^ tPConsProdVen;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::TextBox^ tBMarcaConsPrV;

private: System::Windows::Forms::TextBox^ tBProdConsPrV;

private: System::Windows::Forms::TextBox^ tBPasConsPrV;









	String^ ClienteMasFacturo = "Nadie ha facturado";
		

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ titulo;
	protected:





	private: System::Windows::Forms::TabControl^ tCMenuPrinc;
	private: System::Windows::Forms::TabPage^ tPVendedor;


	private: System::Windows::Forms::TabPage^ tabPageAdmin;
	private: System::Windows::Forms::TabPage^ tabPageClient;



	private: System::Windows::Forms::Button^ btIngresar;
	private: System::Windows::Forms::TextBox^ textBoxIdentificacion;
	private: System::Windows::Forms::Label^ lbCliente;
private: System::Windows::Forms::Button^ btnIngresarClient;








	private: System::Windows::Forms::Button^ btNoRegistrado;
	private: System::Windows::Forms::TextBox^ textBoxClientes;

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::TabControl^ tabControl2;
	private: System::Windows::Forms::TabPage^ tPBasesDatos;
	private: System::Windows::Forms::TabPage^ tPFacturar;
	private: System::Windows::Forms::TabPage^ tPRevGondolas;
	private: System::Windows::Forms::TabPage^ tPVerInventario;
	private: System::Windows::Forms::TabPage^ tPReportes;
	private: System::Windows::Forms::TabControl^ tCClientes;
	private: System::Windows::Forms::TabPage^ tPConsultarPrecio;
	private: System::Windows::Forms::TabPage^ tPConsultaDesc;
	private: System::Windows::Forms::TabPage^ tPConsProd;
	private: System::Windows::Forms::TabPage^ tPComprar;
	private: System::Windows::Forms::Button^ BtnInicial;
	private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::TextBox^ tBPMarcaConsPrecCl;
private: System::Windows::Forms::TextBox^ tBProdConsPrecCl;


private: System::Windows::Forms::TextBox^ tBPasConsPrecCl;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::TextBox^ textBox15;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Button^ btnConsDescCl;









private: System::Windows::Forms::Button^ btnConsProdListo;





	private: System::Windows::Forms::Label^ label10;



private: System::Windows::Forms::TextBox^ tBPasConsProdCl;



	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ tBMarcaComp;

	private: System::Windows::Forms::TextBox^ tBProdComp;

	private: System::Windows::Forms::TextBox^ tBPasComp;

		private: System::Windows::Forms::Button^ button17;
		private: System::Windows::Forms::Button^ button18;
		private: System::Windows::Forms::Button^ button19;
		private: System::Windows::Forms::Label^ label17;
		private: System::Windows::Forms::Label^ label18;
		private: System::Windows::Forms::Label^ label19;
		private: System::Windows::Forms::TextBox^ textBox16;
		private: System::Windows::Forms::TextBox^ textBox17;
		private: System::Windows::Forms::TextBox^ textBox18;






		private:

		public:

		private:

		public:




		protected:




		private:
			/// <summary>
			/// Variable del diseñador necesaria.
			/// </summary>
			System::ComponentModel::Container ^components;

	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Método necesario para admitir el Diseñador. No se puede modificar
			/// el contenido de este método con el editor de código.
			/// </summary>
			void InitializeComponent(void)
			{
				this->titulo = (gcnew System::Windows::Forms::Label());
				this->tCMenuPrinc = (gcnew System::Windows::Forms::TabControl());
				this->tPVendedor = (gcnew System::Windows::Forms::TabPage());
				this->btnIngresarVend = (gcnew System::Windows::Forms::Button());
				this->textBoxVendedor = (gcnew System::Windows::Forms::TextBox());
				this->label25 = (gcnew System::Windows::Forms::Label());
				this->tCVendedor = (gcnew System::Windows::Forms::TabControl());
				this->tPConsPrecioVen = (gcnew System::Windows::Forms::TabPage());
				this->button2 = (gcnew System::Windows::Forms::Button());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->label6 = (gcnew System::Windows::Forms::Label());
				this->label7 = (gcnew System::Windows::Forms::Label());
				this->tBMarcaConsPrV = (gcnew System::Windows::Forms::TextBox());
				this->tBProdConsPrV = (gcnew System::Windows::Forms::TextBox());
				this->tBPasConsPrV = (gcnew System::Windows::Forms::TextBox());
				this->tPConsDescVen = (gcnew System::Windows::Forms::TabPage());
				this->tPConsProdXPasVen = (gcnew System::Windows::Forms::TabPage());
				this->tPConsProdVen = (gcnew System::Windows::Forms::TabPage());
				this->tabPageAdmin = (gcnew System::Windows::Forms::TabPage());
				this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
				this->tPBasesDatos = (gcnew System::Windows::Forms::TabPage());
				this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
				this->tPInsProd = (gcnew System::Windows::Forms::TabPage());
				this->tPModProd = (gcnew System::Windows::Forms::TabPage());
				this->tPConsPrecio = (gcnew System::Windows::Forms::TabPage());
				this->tPConsDesc = (gcnew System::Windows::Forms::TabPage());
				this->tPModDesc = (gcnew System::Windows::Forms::TabPage());
				this->tPRegCliente = (gcnew System::Windows::Forms::TabPage());
				this->tPFacturar = (gcnew System::Windows::Forms::TabPage());
				this->btnFacturar = (gcnew System::Windows::Forms::Button());
				this->tPRevGondolas = (gcnew System::Windows::Forms::TabPage());
				this->button14 = (gcnew System::Windows::Forms::Button());
				this->button15 = (gcnew System::Windows::Forms::Button());
				this->button16 = (gcnew System::Windows::Forms::Button());
				this->label14 = (gcnew System::Windows::Forms::Label());
				this->label15 = (gcnew System::Windows::Forms::Label());
				this->label16 = (gcnew System::Windows::Forms::Label());
				this->textBox13 = (gcnew System::Windows::Forms::TextBox());
				this->textBox14 = (gcnew System::Windows::Forms::TextBox());
				this->textBox15 = (gcnew System::Windows::Forms::TextBox());
				this->tPVerInventario = (gcnew System::Windows::Forms::TabPage());
				this->button17 = (gcnew System::Windows::Forms::Button());
				this->button18 = (gcnew System::Windows::Forms::Button());
				this->button19 = (gcnew System::Windows::Forms::Button());
				this->label17 = (gcnew System::Windows::Forms::Label());
				this->label18 = (gcnew System::Windows::Forms::Label());
				this->label19 = (gcnew System::Windows::Forms::Label());
				this->textBox16 = (gcnew System::Windows::Forms::TextBox());
				this->textBox17 = (gcnew System::Windows::Forms::TextBox());
				this->textBox18 = (gcnew System::Windows::Forms::TextBox());
				this->tPReportes = (gcnew System::Windows::Forms::TabPage());
				this->tabControl3 = (gcnew System::Windows::Forms::TabControl());
				this->tPPasMasVis = (gcnew System::Windows::Forms::TabPage());
				this->button20 = (gcnew System::Windows::Forms::Button());
				this->lblPasMasVis = (gcnew System::Windows::Forms::Label());
				this->label20 = (gcnew System::Windows::Forms::Label());
				this->tPPasMenosVis = (gcnew System::Windows::Forms::TabPage());
				this->button21 = (gcnew System::Windows::Forms::Button());
				this->lblPasilloMenosVis = (gcnew System::Windows::Forms::Label());
				this->tPProdPasMas = (gcnew System::Windows::Forms::TabPage());
				this->tPMarcasMas = (gcnew System::Windows::Forms::TabPage());
				this->tPClienteMasComp = (gcnew System::Windows::Forms::TabPage());
				this->btnClienteMasComp = (gcnew System::Windows::Forms::Button());
				this->tPClienteMenosComp = (gcnew System::Windows::Forms::TabPage());
				this->label22 = (gcnew System::Windows::Forms::Label());
				this->button23 = (gcnew System::Windows::Forms::Button());
				this->label23 = (gcnew System::Windows::Forms::Label());
				this->tPMasCargaGondola = (gcnew System::Windows::Forms::TabPage());
				this->tPClienteMásFact = (gcnew System::Windows::Forms::TabPage());
				this->tPMostrarMarcas = (gcnew System::Windows::Forms::TabPage());
				this->tPFacturaMayor = (gcnew System::Windows::Forms::TabPage());
				this->tPMostrarProd = (gcnew System::Windows::Forms::TabPage());
				this->tPMostrarClientes = (gcnew System::Windows::Forms::TabPage());
				this->tPMosPasillos = (gcnew System::Windows::Forms::TabPage());
				this->tPMosInventario = (gcnew System::Windows::Forms::TabPage());
				this->btIngresar = (gcnew System::Windows::Forms::Button());
				this->textBoxIdentificacion = (gcnew System::Windows::Forms::TextBox());
				this->lbCliente = (gcnew System::Windows::Forms::Label());
				this->tabPageClient = (gcnew System::Windows::Forms::TabPage());
				this->lblClienteActual = (gcnew System::Windows::Forms::Label());
				this->tCClientes = (gcnew System::Windows::Forms::TabControl());
				this->tPConsultarPrecio = (gcnew System::Windows::Forms::TabPage());
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->tBPMarcaConsPrecCl = (gcnew System::Windows::Forms::TextBox());
				this->tBProdConsPrecCl = (gcnew System::Windows::Forms::TextBox());
				this->tBPasConsPrecCl = (gcnew System::Windows::Forms::TextBox());
				this->tPConsultaDesc = (gcnew System::Windows::Forms::TabPage());
				this->btnConsDescCl = (gcnew System::Windows::Forms::Button());
				this->tPConsProd = (gcnew System::Windows::Forms::TabPage());
				this->btnConsProdListo = (gcnew System::Windows::Forms::Button());
				this->label10 = (gcnew System::Windows::Forms::Label());
				this->tBPasConsProdCl = (gcnew System::Windows::Forms::TextBox());
				this->tPComprar = (gcnew System::Windows::Forms::TabPage());
				this->lblInsuficienteProd = (gcnew System::Windows::Forms::Label());
				this->tBCantProdN = (gcnew System::Windows::Forms::TextBox());
				this->btnOp2 = (gcnew System::Windows::Forms::Button());
				this->btnOp1 = (gcnew System::Windows::Forms::Button());
				this->label24 = (gcnew System::Windows::Forms::Label());
				this->tPCantProd = (gcnew System::Windows::Forms::TextBox());
				this->button25 = (gcnew System::Windows::Forms::Button());
				this->button24 = (gcnew System::Windows::Forms::Button());
				this->button11 = (gcnew System::Windows::Forms::Button());
				this->label21 = (gcnew System::Windows::Forms::Label());
				this->button13 = (gcnew System::Windows::Forms::Button());
				this->label11 = (gcnew System::Windows::Forms::Label());
				this->label12 = (gcnew System::Windows::Forms::Label());
				this->label13 = (gcnew System::Windows::Forms::Label());
				this->tBMarcaComp = (gcnew System::Windows::Forms::TextBox());
				this->tBProdComp = (gcnew System::Windows::Forms::TextBox());
				this->tBPasComp = (gcnew System::Windows::Forms::TextBox());
				this->btnIngresarClient = (gcnew System::Windows::Forms::Button());
				this->btNoRegistrado = (gcnew System::Windows::Forms::Button());
				this->textBoxClientes = (gcnew System::Windows::Forms::TextBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->BtnInicial = (gcnew System::Windows::Forms::Button());
				this->tCMenuPrinc->SuspendLayout();
				this->tPVendedor->SuspendLayout();
				this->tCVendedor->SuspendLayout();
				this->tPConsPrecioVen->SuspendLayout();
				this->tabPageAdmin->SuspendLayout();
				this->tabControl2->SuspendLayout();
				this->tPBasesDatos->SuspendLayout();
				this->tabControl1->SuspendLayout();
				this->tPFacturar->SuspendLayout();
				this->tPRevGondolas->SuspendLayout();
				this->tPVerInventario->SuspendLayout();
				this->tPReportes->SuspendLayout();
				this->tabControl3->SuspendLayout();
				this->tPPasMasVis->SuspendLayout();
				this->tPPasMenosVis->SuspendLayout();
				this->tPClienteMasComp->SuspendLayout();
				this->tPClienteMenosComp->SuspendLayout();
				this->tabPageClient->SuspendLayout();
				this->tCClientes->SuspendLayout();
				this->tPConsultarPrecio->SuspendLayout();
				this->tPConsultaDesc->SuspendLayout();
				this->tPConsProd->SuspendLayout();
				this->tPComprar->SuspendLayout();
				this->SuspendLayout();
				// 
				// titulo
				// 
				this->titulo->AutoSize = true;
				this->titulo->Location = System::Drawing::Point(13, 9);
				this->titulo->Name = L"titulo";
				this->titulo->Size = System::Drawing::Size(280, 13);
				this->titulo->TabIndex = 0;
				this->titulo->Text = L"Bienvenido al sistema de supermercado de los SuperBros!";
				this->titulo->UseWaitCursor = true;
				this->titulo->Click += gcnew System::EventHandler(this, &MenuPrincipal::titulo_Click);
				// 
				// tCMenuPrinc
				// 
				this->tCMenuPrinc->Controls->Add(this->tPVendedor);
				this->tCMenuPrinc->Controls->Add(this->tabPageAdmin);
				this->tCMenuPrinc->Controls->Add(this->tabPageClient);
				this->tCMenuPrinc->HotTrack = true;
				this->tCMenuPrinc->Location = System::Drawing::Point(12, 25);
				this->tCMenuPrinc->Name = L"tCMenuPrinc";
				this->tCMenuPrinc->SelectedIndex = 0;
				this->tCMenuPrinc->Size = System::Drawing::Size(1084, 648);
				this->tCMenuPrinc->TabIndex = 6;
				this->tCMenuPrinc->Visible = false;
				// 
				// tPVendedor
				// 
				this->tPVendedor->Controls->Add(this->btnIngresarVend);
				this->tPVendedor->Controls->Add(this->textBoxVendedor);
				this->tPVendedor->Controls->Add(this->label25);
				this->tPVendedor->Controls->Add(this->tCVendedor);
				this->tPVendedor->Location = System::Drawing::Point(4, 22);
				this->tPVendedor->Name = L"tPVendedor";
				this->tPVendedor->Padding = System::Windows::Forms::Padding(3);
				this->tPVendedor->Size = System::Drawing::Size(1076, 622);
				this->tPVendedor->TabIndex = 0;
				this->tPVendedor->Text = L"Vendedor";
				this->tPVendedor->UseVisualStyleBackColor = true;
				this->tPVendedor->UseWaitCursor = true;
				this->tPVendedor->Click += gcnew System::EventHandler(this, &MenuPrincipal::tPVendedor_Click);
				// 
				// btnIngresarVend
				// 
				this->btnIngresarVend->Cursor = System::Windows::Forms::Cursors::WaitCursor;
				this->btnIngresarVend->Location = System::Drawing::Point(222, 36);
				this->btnIngresarVend->Name = L"btnIngresarVend";
				this->btnIngresarVend->Size = System::Drawing::Size(54, 23);
				this->btnIngresarVend->TabIndex = 22;
				this->btnIngresarVend->Text = L"Ingresar";
				this->btnIngresarVend->UseVisualStyleBackColor = true;
				this->btnIngresarVend->UseWaitCursor = true;
				this->btnIngresarVend->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnIngresarVend_Click);
				// 
				// textBoxVendedor
				// 
				this->textBoxVendedor->Location = System::Drawing::Point(24, 36);
				this->textBoxVendedor->Name = L"textBoxVendedor";
				this->textBoxVendedor->Size = System::Drawing::Size(192, 20);
				this->textBoxVendedor->TabIndex = 21;
				this->textBoxVendedor->UseWaitCursor = true;
				// 
				// label25
				// 
				this->label25->AutoSize = true;
				this->label25->Location = System::Drawing::Point(21, 20);
				this->label25->Name = L"label25";
				this->label25->Size = System::Drawing::Size(282, 13);
				this->label25->TabIndex = 20;
				this->label25->Text = L"Por favor ingrese su número de identificación de vendedor";
				this->label25->UseWaitCursor = true;
				// 
				// tCVendedor
				// 
				this->tCVendedor->CausesValidation = false;
				this->tCVendedor->Controls->Add(this->tPConsPrecioVen);
				this->tCVendedor->Controls->Add(this->tPConsDescVen);
				this->tCVendedor->Controls->Add(this->tPConsProdXPasVen);
				this->tCVendedor->Controls->Add(this->tPConsProdVen);
				this->tCVendedor->Location = System::Drawing::Point(6, 75);
				this->tCVendedor->Name = L"tCVendedor";
				this->tCVendedor->SelectedIndex = 0;
				this->tCVendedor->Size = System::Drawing::Size(1056, 540);
				this->tCVendedor->TabIndex = 0;
				this->tCVendedor->UseWaitCursor = true;
				// 
				// tPConsPrecioVen
				// 
				this->tPConsPrecioVen->Controls->Add(this->button2);
				this->tPConsPrecioVen->Controls->Add(this->label5);
				this->tPConsPrecioVen->Controls->Add(this->label6);
				this->tPConsPrecioVen->Controls->Add(this->label7);
				this->tPConsPrecioVen->Controls->Add(this->tBMarcaConsPrV);
				this->tPConsPrecioVen->Controls->Add(this->tBProdConsPrV);
				this->tPConsPrecioVen->Controls->Add(this->tBPasConsPrV);
				this->tPConsPrecioVen->Location = System::Drawing::Point(4, 22);
				this->tPConsPrecioVen->Name = L"tPConsPrecioVen";
				this->tPConsPrecioVen->Padding = System::Windows::Forms::Padding(3);
				this->tPConsPrecioVen->Size = System::Drawing::Size(1048, 514);
				this->tPConsPrecioVen->TabIndex = 0;
				this->tPConsPrecioVen->Text = L"Consultar Precio";
				this->tPConsPrecioVen->UseVisualStyleBackColor = true;
				this->tPConsPrecioVen->UseWaitCursor = true;
				// 
				// button2
				// 
				this->button2->Cursor = System::Windows::Forms::Cursors::WaitCursor;
				this->button2->Location = System::Drawing::Point(474, 161);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(54, 23);
				this->button2->TabIndex = 27;
				this->button2->Text = L"Listo";
				this->button2->UseVisualStyleBackColor = true;
				this->button2->UseWaitCursor = true;
				this->button2->Click += gcnew System::EventHandler(this, &MenuPrincipal::button2_Click);
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Location = System::Drawing::Point(671, 68);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(153, 13);
				this->label5->TabIndex = 26;
				this->label5->Text = L"Introduzca el número de marca";
				this->label5->UseWaitCursor = true;
				// 
				// label6
				// 
				this->label6->AutoSize = true;
				this->label6->Location = System::Drawing::Point(408, 68);
				this->label6->Name = L"label6";
				this->label6->Size = System::Drawing::Size(166, 13);
				this->label6->TabIndex = 25;
				this->label6->Text = L"Introduzca el número de producto";
				this->label6->UseWaitCursor = true;
				// 
				// label7
				// 
				this->label7->AutoSize = true;
				this->label7->Location = System::Drawing::Point(147, 68);
				this->label7->Name = L"label7";
				this->label7->Size = System::Drawing::Size(153, 13);
				this->label7->TabIndex = 24;
				this->label7->Text = L"Introduzca el número de pasillo";
				this->label7->UseWaitCursor = true;
				// 
				// tBMarcaConsPrV
				// 
				this->tBMarcaConsPrV->Location = System::Drawing::Point(674, 95);
				this->tBMarcaConsPrV->Name = L"tBMarcaConsPrV";
				this->tBMarcaConsPrV->Size = System::Drawing::Size(114, 20);
				this->tBMarcaConsPrV->TabIndex = 23;
				this->tBMarcaConsPrV->UseWaitCursor = true;
				// 
				// tBProdConsPrV
				// 
				this->tBProdConsPrV->Location = System::Drawing::Point(411, 95);
				this->tBProdConsPrV->Name = L"tBProdConsPrV";
				this->tBProdConsPrV->Size = System::Drawing::Size(122, 20);
				this->tBProdConsPrV->TabIndex = 22;
				this->tBProdConsPrV->UseWaitCursor = true;
				// 
				// tBPasConsPrV
				// 
				this->tBPasConsPrV->Location = System::Drawing::Point(145, 95);
				this->tBPasConsPrV->Name = L"tBPasConsPrV";
				this->tBPasConsPrV->Size = System::Drawing::Size(102, 20);
				this->tBPasConsPrV->TabIndex = 21;
				this->tBPasConsPrV->UseWaitCursor = true;
				// 
				// tPConsDescVen
				// 
				this->tPConsDescVen->Location = System::Drawing::Point(4, 22);
				this->tPConsDescVen->Name = L"tPConsDescVen";
				this->tPConsDescVen->Padding = System::Windows::Forms::Padding(3);
				this->tPConsDescVen->Size = System::Drawing::Size(1048, 514);
				this->tPConsDescVen->TabIndex = 1;
				this->tPConsDescVen->Text = L"Consultar Descuento de un cliente";
				this->tPConsDescVen->UseVisualStyleBackColor = true;
				this->tPConsDescVen->UseWaitCursor = true;
				// 
				// tPConsProdXPasVen
				// 
				this->tPConsProdXPasVen->Location = System::Drawing::Point(4, 22);
				this->tPConsProdXPasVen->Name = L"tPConsProdXPasVen";
				this->tPConsProdXPasVen->Size = System::Drawing::Size(1048, 514);
				this->tPConsProdXPasVen->TabIndex = 2;
				this->tPConsProdXPasVen->Text = L"Consultar Producto x Pasillo";
				this->tPConsProdXPasVen->UseVisualStyleBackColor = true;
				this->tPConsProdXPasVen->UseWaitCursor = true;
				// 
				// tPConsProdVen
				// 
				this->tPConsProdVen->Location = System::Drawing::Point(4, 22);
				this->tPConsProdVen->Name = L"tPConsProdVen";
				this->tPConsProdVen->Size = System::Drawing::Size(1048, 514);
				this->tPConsProdVen->TabIndex = 3;
				this->tPConsProdVen->Text = L"Consultar Marca de un Producto";
				this->tPConsProdVen->UseVisualStyleBackColor = true;
				this->tPConsProdVen->UseWaitCursor = true;
				// 
				// tabPageAdmin
				// 
				this->tabPageAdmin->Controls->Add(this->tabControl2);
				this->tabPageAdmin->Controls->Add(this->btIngresar);
				this->tabPageAdmin->Controls->Add(this->textBoxIdentificacion);
				this->tabPageAdmin->Controls->Add(this->lbCliente);
				this->tabPageAdmin->Location = System::Drawing::Point(4, 22);
				this->tabPageAdmin->Name = L"tabPageAdmin";
				this->tabPageAdmin->Padding = System::Windows::Forms::Padding(3);
				this->tabPageAdmin->Size = System::Drawing::Size(1076, 622);
				this->tabPageAdmin->TabIndex = 1;
				this->tabPageAdmin->Text = L"Administrador";
				this->tabPageAdmin->UseVisualStyleBackColor = true;
				this->tabPageAdmin->Visible = false;
				// 
				// tabControl2
				// 
				this->tabControl2->Controls->Add(this->tPBasesDatos);
				this->tabControl2->Controls->Add(this->tPFacturar);
				this->tabControl2->Controls->Add(this->tPRevGondolas);
				this->tabControl2->Controls->Add(this->tPVerInventario);
				this->tabControl2->Controls->Add(this->tPReportes);
				this->tabControl2->Location = System::Drawing::Point(6, 57);
				this->tabControl2->Name = L"tabControl2";
				this->tabControl2->SelectedIndex = 0;
				this->tabControl2->Size = System::Drawing::Size(1067, 562);
				this->tabControl2->TabIndex = 26;
				this->tabControl2->Visible = false;
				// 
				// tPBasesDatos
				// 
				this->tPBasesDatos->Controls->Add(this->tabControl1);
				this->tPBasesDatos->Location = System::Drawing::Point(4, 22);
				this->tPBasesDatos->Name = L"tPBasesDatos";
				this->tPBasesDatos->Padding = System::Windows::Forms::Padding(3);
				this->tPBasesDatos->Size = System::Drawing::Size(1059, 536);
				this->tPBasesDatos->TabIndex = 0;
				this->tPBasesDatos->Text = L"Mantenimiento de Bases";
				this->tPBasesDatos->UseVisualStyleBackColor = true;
				// 
				// tabControl1
				// 
				this->tabControl1->Controls->Add(this->tPInsProd);
				this->tabControl1->Controls->Add(this->tPModProd);
				this->tabControl1->Controls->Add(this->tPConsPrecio);
				this->tabControl1->Controls->Add(this->tPConsDesc);
				this->tabControl1->Controls->Add(this->tPModDesc);
				this->tabControl1->Controls->Add(this->tPRegCliente);
				this->tabControl1->Location = System::Drawing::Point(6, 3);
				this->tabControl1->Name = L"tabControl1";
				this->tabControl1->SelectedIndex = 0;
				this->tabControl1->Size = System::Drawing::Size(1047, 530);
				this->tabControl1->TabIndex = 0;
				// 
				// tPInsProd
				// 
				this->tPInsProd->Location = System::Drawing::Point(4, 22);
				this->tPInsProd->Name = L"tPInsProd";
				this->tPInsProd->Padding = System::Windows::Forms::Padding(3);
				this->tPInsProd->Size = System::Drawing::Size(1039, 504);
				this->tPInsProd->TabIndex = 0;
				this->tPInsProd->Text = L"Insertar producto";
				this->tPInsProd->UseVisualStyleBackColor = true;
				// 
				// tPModProd
				// 
				this->tPModProd->Location = System::Drawing::Point(4, 22);
				this->tPModProd->Name = L"tPModProd";
				this->tPModProd->Padding = System::Windows::Forms::Padding(3);
				this->tPModProd->Size = System::Drawing::Size(1039, 504);
				this->tPModProd->TabIndex = 1;
				this->tPModProd->Text = L"Modificar Producto";
				this->tPModProd->UseVisualStyleBackColor = true;
				// 
				// tPConsPrecio
				// 
				this->tPConsPrecio->Location = System::Drawing::Point(4, 22);
				this->tPConsPrecio->Name = L"tPConsPrecio";
				this->tPConsPrecio->Size = System::Drawing::Size(1039, 504);
				this->tPConsPrecio->TabIndex = 2;
				this->tPConsPrecio->Text = L"Consultar Precio";
				this->tPConsPrecio->UseVisualStyleBackColor = true;
				// 
				// tPConsDesc
				// 
				this->tPConsDesc->Location = System::Drawing::Point(4, 22);
				this->tPConsDesc->Name = L"tPConsDesc";
				this->tPConsDesc->Size = System::Drawing::Size(1039, 504);
				this->tPConsDesc->TabIndex = 3;
				this->tPConsDesc->Text = L"Consultar Descuento";
				this->tPConsDesc->UseVisualStyleBackColor = true;
				// 
				// tPModDesc
				// 
				this->tPModDesc->Location = System::Drawing::Point(4, 22);
				this->tPModDesc->Name = L"tPModDesc";
				this->tPModDesc->Size = System::Drawing::Size(1039, 504);
				this->tPModDesc->TabIndex = 4;
				this->tPModDesc->Text = L"Modificar Descuento";
				this->tPModDesc->UseVisualStyleBackColor = true;
				// 
				// tPRegCliente
				// 
				this->tPRegCliente->Location = System::Drawing::Point(4, 22);
				this->tPRegCliente->Name = L"tPRegCliente";
				this->tPRegCliente->Size = System::Drawing::Size(1039, 504);
				this->tPRegCliente->TabIndex = 5;
				this->tPRegCliente->Text = L"Registrar Clientes";
				this->tPRegCliente->UseVisualStyleBackColor = true;
				// 
				// tPFacturar
				// 
				this->tPFacturar->Controls->Add(this->btnFacturar);
				this->tPFacturar->Location = System::Drawing::Point(4, 22);
				this->tPFacturar->Name = L"tPFacturar";
				this->tPFacturar->Padding = System::Windows::Forms::Padding(3);
				this->tPFacturar->Size = System::Drawing::Size(1059, 536);
				this->tPFacturar->TabIndex = 1;
				this->tPFacturar->Text = L"Facturar";
				this->tPFacturar->UseVisualStyleBackColor = true;
				// 
				// btnFacturar
				// 
				this->btnFacturar->Location = System::Drawing::Point(206, 82);
				this->btnFacturar->Name = L"btnFacturar";
				this->btnFacturar->Size = System::Drawing::Size(482, 270);
				this->btnFacturar->TabIndex = 0;
				this->btnFacturar->Text = L"Facturar";
				this->btnFacturar->UseVisualStyleBackColor = true;
				this->btnFacturar->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnFacturar_Click);
				// 
				// tPRevGondolas
				// 
				this->tPRevGondolas->Controls->Add(this->button14);
				this->tPRevGondolas->Controls->Add(this->button15);
				this->tPRevGondolas->Controls->Add(this->button16);
				this->tPRevGondolas->Controls->Add(this->label14);
				this->tPRevGondolas->Controls->Add(this->label15);
				this->tPRevGondolas->Controls->Add(this->label16);
				this->tPRevGondolas->Controls->Add(this->textBox13);
				this->tPRevGondolas->Controls->Add(this->textBox14);
				this->tPRevGondolas->Controls->Add(this->textBox15);
				this->tPRevGondolas->Location = System::Drawing::Point(4, 22);
				this->tPRevGondolas->Name = L"tPRevGondolas";
				this->tPRevGondolas->Padding = System::Windows::Forms::Padding(3);
				this->tPRevGondolas->Size = System::Drawing::Size(1059, 536);
				this->tPRevGondolas->TabIndex = 2;
				this->tPRevGondolas->Text = L"Revisar góndolas";
				this->tPRevGondolas->UseVisualStyleBackColor = true;
				// 
				// button14
				// 
				this->button14->Cursor = System::Windows::Forms::Cursors::Hand;
				this->button14->Location = System::Drawing::Point(719, 59);
				this->button14->Name = L"button14";
				this->button14->Size = System::Drawing::Size(54, 23);
				this->button14->TabIndex = 31;
				this->button14->Text = L"Ok";
				this->button14->UseVisualStyleBackColor = true;
				this->button14->Click += gcnew System::EventHandler(this, &MenuPrincipal::button14_Click);
				// 
				// button15
				// 
				this->button15->Cursor = System::Windows::Forms::Cursors::Hand;
				this->button15->Location = System::Drawing::Point(458, 59);
				this->button15->Name = L"button15";
				this->button15->Size = System::Drawing::Size(54, 23);
				this->button15->TabIndex = 30;
				this->button15->Text = L"Ok";
				this->button15->UseVisualStyleBackColor = true;
				this->button15->Click += gcnew System::EventHandler(this, &MenuPrincipal::button15_Click);
				// 
				// button16
				// 
				this->button16->Cursor = System::Windows::Forms::Cursors::Hand;
				this->button16->Location = System::Drawing::Point(172, 59);
				this->button16->Name = L"button16";
				this->button16->Size = System::Drawing::Size(54, 23);
				this->button16->TabIndex = 29;
				this->button16->Text = L"Ok";
				this->button16->UseVisualStyleBackColor = true;
				this->button16->Click += gcnew System::EventHandler(this, &MenuPrincipal::button16_Click);
				// 
				// label14
				// 
				this->label14->AutoSize = true;
				this->label14->Location = System::Drawing::Point(590, 32);
				this->label14->Name = L"label14";
				this->label14->Size = System::Drawing::Size(153, 13);
				this->label14->TabIndex = 28;
				this->label14->Text = L"Introduzca el número de marca";
				this->label14->Click += gcnew System::EventHandler(this, &MenuPrincipal::label14_Click);
				// 
				// label15
				// 
				this->label15->AutoSize = true;
				this->label15->Location = System::Drawing::Point(327, 32);
				this->label15->Name = L"label15";
				this->label15->Size = System::Drawing::Size(166, 13);
				this->label15->TabIndex = 27;
				this->label15->Text = L"Introduzca el número de producto";
				this->label15->Click += gcnew System::EventHandler(this, &MenuPrincipal::label15_Click);
				// 
				// label16
				// 
				this->label16->AutoSize = true;
				this->label16->Location = System::Drawing::Point(66, 32);
				this->label16->Name = L"label16";
				this->label16->Size = System::Drawing::Size(153, 13);
				this->label16->TabIndex = 26;
				this->label16->Text = L"Introduzca el número de pasillo";
				this->label16->Click += gcnew System::EventHandler(this, &MenuPrincipal::label16_Click);
				// 
				// textBox13
				// 
				this->textBox13->Location = System::Drawing::Point(593, 59);
				this->textBox13->Name = L"textBox13";
				this->textBox13->Size = System::Drawing::Size(114, 20);
				this->textBox13->TabIndex = 25;
				this->textBox13->TextChanged += gcnew System::EventHandler(this, &MenuPrincipal::textBox13_TextChanged);
				// 
				// textBox14
				// 
				this->textBox14->Location = System::Drawing::Point(330, 59);
				this->textBox14->Name = L"textBox14";
				this->textBox14->Size = System::Drawing::Size(122, 20);
				this->textBox14->TabIndex = 24;
				this->textBox14->TextChanged += gcnew System::EventHandler(this, &MenuPrincipal::textBox14_TextChanged);
				// 
				// textBox15
				// 
				this->textBox15->Location = System::Drawing::Point(64, 59);
				this->textBox15->Name = L"textBox15";
				this->textBox15->Size = System::Drawing::Size(102, 20);
				this->textBox15->TabIndex = 23;
				this->textBox15->TextChanged += gcnew System::EventHandler(this, &MenuPrincipal::textBox15_TextChanged);
				// 
				// tPVerInventario
				// 
				this->tPVerInventario->Controls->Add(this->button17);
				this->tPVerInventario->Controls->Add(this->button18);
				this->tPVerInventario->Controls->Add(this->button19);
				this->tPVerInventario->Controls->Add(this->label17);
				this->tPVerInventario->Controls->Add(this->label18);
				this->tPVerInventario->Controls->Add(this->label19);
				this->tPVerInventario->Controls->Add(this->textBox16);
				this->tPVerInventario->Controls->Add(this->textBox17);
				this->tPVerInventario->Controls->Add(this->textBox18);
				this->tPVerInventario->Location = System::Drawing::Point(4, 22);
				this->tPVerInventario->Name = L"tPVerInventario";
				this->tPVerInventario->Size = System::Drawing::Size(1059, 536);
				this->tPVerInventario->TabIndex = 3;
				this->tPVerInventario->Text = L"Verificar inventario";
				this->tPVerInventario->UseVisualStyleBackColor = true;
				// 
				// button17
				// 
				this->button17->Cursor = System::Windows::Forms::Cursors::Hand;
				this->button17->Location = System::Drawing::Point(733, 59);
				this->button17->Name = L"button17";
				this->button17->Size = System::Drawing::Size(54, 23);
				this->button17->TabIndex = 31;
				this->button17->Text = L"Ok";
				this->button17->UseVisualStyleBackColor = true;
				// 
				// button18
				// 
				this->button18->Cursor = System::Windows::Forms::Cursors::Hand;
				this->button18->Location = System::Drawing::Point(472, 59);
				this->button18->Name = L"button18";
				this->button18->Size = System::Drawing::Size(54, 23);
				this->button18->TabIndex = 30;
				this->button18->Text = L"Ok";
				this->button18->UseVisualStyleBackColor = true;
				// 
				// button19
				// 
				this->button19->Cursor = System::Windows::Forms::Cursors::Hand;
				this->button19->Location = System::Drawing::Point(186, 59);
				this->button19->Name = L"button19";
				this->button19->Size = System::Drawing::Size(54, 23);
				this->button19->TabIndex = 29;
				this->button19->Text = L"Ok";
				this->button19->UseVisualStyleBackColor = true;
				// 
				// label17
				// 
				this->label17->AutoSize = true;
				this->label17->Location = System::Drawing::Point(604, 32);
				this->label17->Name = L"label17";
				this->label17->Size = System::Drawing::Size(153, 13);
				this->label17->TabIndex = 28;
				this->label17->Text = L"Introduzca el número de marca";
				// 
				// label18
				// 
				this->label18->AutoSize = true;
				this->label18->Location = System::Drawing::Point(341, 32);
				this->label18->Name = L"label18";
				this->label18->Size = System::Drawing::Size(166, 13);
				this->label18->TabIndex = 27;
				this->label18->Text = L"Introduzca el número de producto";
				// 
				// label19
				// 
				this->label19->AutoSize = true;
				this->label19->Location = System::Drawing::Point(80, 32);
				this->label19->Name = L"label19";
				this->label19->Size = System::Drawing::Size(153, 13);
				this->label19->TabIndex = 26;
				this->label19->Text = L"Introduzca el número de pasillo";
				// 
				// textBox16
				// 
				this->textBox16->Location = System::Drawing::Point(607, 59);
				this->textBox16->Name = L"textBox16";
				this->textBox16->Size = System::Drawing::Size(114, 20);
				this->textBox16->TabIndex = 25;
				// 
				// textBox17
				// 
				this->textBox17->Location = System::Drawing::Point(344, 59);
				this->textBox17->Name = L"textBox17";
				this->textBox17->Size = System::Drawing::Size(122, 20);
				this->textBox17->TabIndex = 24;
				// 
				// textBox18
				// 
				this->textBox18->Location = System::Drawing::Point(78, 59);
				this->textBox18->Name = L"textBox18";
				this->textBox18->Size = System::Drawing::Size(102, 20);
				this->textBox18->TabIndex = 23;
				// 
				// tPReportes
				// 
				this->tPReportes->Controls->Add(this->tabControl3);
				this->tPReportes->Location = System::Drawing::Point(4, 22);
				this->tPReportes->Name = L"tPReportes";
				this->tPReportes->Size = System::Drawing::Size(1059, 536);
				this->tPReportes->TabIndex = 4;
				this->tPReportes->Text = L"Reportes";
				this->tPReportes->UseVisualStyleBackColor = true;
				// 
				// tabControl3
				// 
				this->tabControl3->Controls->Add(this->tPPasMasVis);
				this->tabControl3->Controls->Add(this->tPPasMenosVis);
				this->tabControl3->Controls->Add(this->tPProdPasMas);
				this->tabControl3->Controls->Add(this->tPMarcasMas);
				this->tabControl3->Controls->Add(this->tPClienteMasComp);
				this->tabControl3->Controls->Add(this->tPClienteMenosComp);
				this->tabControl3->Controls->Add(this->tPMasCargaGondola);
				this->tabControl3->Controls->Add(this->tPClienteMásFact);
				this->tabControl3->Controls->Add(this->tPMostrarMarcas);
				this->tabControl3->Controls->Add(this->tPFacturaMayor);
				this->tabControl3->Controls->Add(this->tPMostrarProd);
				this->tabControl3->Controls->Add(this->tPMostrarClientes);
				this->tabControl3->Controls->Add(this->tPMosPasillos);
				this->tabControl3->Controls->Add(this->tPMosInventario);
				this->tabControl3->Location = System::Drawing::Point(12, 10);
				this->tabControl3->Name = L"tabControl3";
				this->tabControl3->SelectedIndex = 0;
				this->tabControl3->Size = System::Drawing::Size(1043, 523);
				this->tabControl3->TabIndex = 0;
				// 
				// tPPasMasVis
				// 
				this->tPPasMasVis->Controls->Add(this->button20);
				this->tPPasMasVis->Controls->Add(this->lblPasMasVis);
				this->tPPasMasVis->Controls->Add(this->label20);
				this->tPPasMasVis->Location = System::Drawing::Point(4, 22);
				this->tPPasMasVis->Name = L"tPPasMasVis";
				this->tPPasMasVis->Padding = System::Windows::Forms::Padding(3);
				this->tPPasMasVis->Size = System::Drawing::Size(1035, 497);
				this->tPPasMasVis->TabIndex = 0;
				this->tPPasMasVis->Text = L"Pasillo + visitado";
				this->tPPasMasVis->UseVisualStyleBackColor = true;
				// 
				// button20
				// 
				this->button20->Location = System::Drawing::Point(469, 298);
				this->button20->Name = L"button20";
				this->button20->Size = System::Drawing::Size(75, 23);
				this->button20->TabIndex = 2;
				this->button20->Text = L"Actualizar";
				this->button20->UseVisualStyleBackColor = true;
				this->button20->Click += gcnew System::EventHandler(this, &MenuPrincipal::button20_Click);
				// 
				// lblPasMasVis
				// 
				this->lblPasMasVis->AutoSize = true;
				this->lblPasMasVis->Location = System::Drawing::Point(454, 260);
				this->lblPasMasVis->Name = L"lblPasMasVis";
				this->lblPasMasVis->Size = System::Drawing::Size(34, 13);
				this->lblPasMasVis->TabIndex = 1;
				this->lblPasMasVis->Text = L"Vacio";
				// 
				// label20
				// 
				this->label20->AutoSize = true;
				this->label20->Location = System::Drawing::Point(96, 29);
				this->label20->Name = L"label20";
				this->label20->Size = System::Drawing::Size(0, 13);
				this->label20->TabIndex = 0;
				// 
				// tPPasMenosVis
				// 
				this->tPPasMenosVis->Controls->Add(this->button21);
				this->tPPasMenosVis->Controls->Add(this->lblPasilloMenosVis);
				this->tPPasMenosVis->Location = System::Drawing::Point(4, 22);
				this->tPPasMenosVis->Name = L"tPPasMenosVis";
				this->tPPasMenosVis->Padding = System::Windows::Forms::Padding(3);
				this->tPPasMenosVis->Size = System::Drawing::Size(1035, 497);
				this->tPPasMenosVis->TabIndex = 1;
				this->tPPasMenosVis->Text = L"Pasillo - visitado";
				this->tPPasMenosVis->UseVisualStyleBackColor = true;
				// 
				// button21
				// 
				this->button21->Location = System::Drawing::Point(480, 254);
				this->button21->Name = L"button21";
				this->button21->Size = System::Drawing::Size(75, 23);
				this->button21->TabIndex = 4;
				this->button21->Text = L"Actualizar";
				this->button21->UseVisualStyleBackColor = true;
				this->button21->Click += gcnew System::EventHandler(this, &MenuPrincipal::button21_Click);
				// 
				// lblPasilloMenosVis
				// 
				this->lblPasilloMenosVis->AutoSize = true;
				this->lblPasilloMenosVis->Location = System::Drawing::Point(464, 220);
				this->lblPasilloMenosVis->Name = L"lblPasilloMenosVis";
				this->lblPasilloMenosVis->Size = System::Drawing::Size(34, 13);
				this->lblPasilloMenosVis->TabIndex = 3;
				this->lblPasilloMenosVis->Text = L"Vacio";
				// 
				// tPProdPasMas
				// 
				this->tPProdPasMas->Location = System::Drawing::Point(4, 22);
				this->tPProdPasMas->Name = L"tPProdPasMas";
				this->tPProdPasMas->Size = System::Drawing::Size(1035, 497);
				this->tPProdPasMas->TabIndex = 2;
				this->tPProdPasMas->Text = L"Productos * Pasillo + vendidos";
				this->tPProdPasMas->UseVisualStyleBackColor = true;
				// 
				// tPMarcasMas
				// 
				this->tPMarcasMas->Location = System::Drawing::Point(4, 22);
				this->tPMarcasMas->Name = L"tPMarcasMas";
				this->tPMarcasMas->Size = System::Drawing::Size(1035, 497);
				this->tPMarcasMas->TabIndex = 3;
				this->tPMarcasMas->Text = L"Marcas + vendidas";
				this->tPMarcasMas->UseVisualStyleBackColor = true;
				// 
				// tPClienteMasComp
				// 
				this->tPClienteMasComp->Controls->Add(this->btnClienteMasComp);
				this->tPClienteMasComp->Location = System::Drawing::Point(4, 22);
				this->tPClienteMasComp->Name = L"tPClienteMasComp";
				this->tPClienteMasComp->Size = System::Drawing::Size(1035, 497);
				this->tPClienteMasComp->TabIndex = 4;
				this->tPClienteMasComp->Text = L"Cliente + compró";
				this->tPClienteMasComp->UseVisualStyleBackColor = true;
				// 
				// btnClienteMasComp
				// 
				this->btnClienteMasComp->Location = System::Drawing::Point(463, 229);
				this->btnClienteMasComp->Name = L"btnClienteMasComp";
				this->btnClienteMasComp->Size = System::Drawing::Size(75, 23);
				this->btnClienteMasComp->TabIndex = 9;
				this->btnClienteMasComp->Text = L"Ver";
				this->btnClienteMasComp->UseVisualStyleBackColor = true;
				this->btnClienteMasComp->Click += gcnew System::EventHandler(this, &MenuPrincipal::button22_Click_1);
				// 
				// tPClienteMenosComp
				// 
				this->tPClienteMenosComp->Controls->Add(this->label22);
				this->tPClienteMenosComp->Controls->Add(this->button23);
				this->tPClienteMenosComp->Controls->Add(this->label23);
				this->tPClienteMenosComp->Location = System::Drawing::Point(4, 22);
				this->tPClienteMenosComp->Name = L"tPClienteMenosComp";
				this->tPClienteMenosComp->Size = System::Drawing::Size(1035, 497);
				this->tPClienteMenosComp->TabIndex = 5;
				this->tPClienteMenosComp->Text = L"Cliente - compró";
				this->tPClienteMenosComp->UseVisualStyleBackColor = true;
				// 
				// label22
				// 
				this->label22->AutoSize = true;
				this->label22->Location = System::Drawing::Point(407, 163);
				this->label22->Name = L"label22";
				this->label22->Size = System::Drawing::Size(233, 13);
				this->label22->TabIndex = 13;
				this->label22->Text = L"El cliente que tuvo la factura menos grande fue:";
				// 
				// button23
				// 
				this->button23->Location = System::Drawing::Point(441, 241);
				this->button23->Name = L"button23";
				this->button23->Size = System::Drawing::Size(75, 23);
				this->button23->TabIndex = 12;
				this->button23->Text = L"Actualizar";
				this->button23->UseVisualStyleBackColor = true;
				// 
				// label23
				// 
				this->label23->AutoSize = true;
				this->label23->Location = System::Drawing::Point(425, 198);
				this->label23->Name = L"label23";
				this->label23->Size = System::Drawing::Size(34, 13);
				this->label23->TabIndex = 11;
				this->label23->Text = L"Vacio";
				// 
				// tPMasCargaGondola
				// 
				this->tPMasCargaGondola->Location = System::Drawing::Point(4, 22);
				this->tPMasCargaGondola->Name = L"tPMasCargaGondola";
				this->tPMasCargaGondola->Size = System::Drawing::Size(1035, 497);
				this->tPMasCargaGondola->TabIndex = 6;
				this->tPMasCargaGondola->Text = L"Producto + cargó en gondola";
				this->tPMasCargaGondola->UseVisualStyleBackColor = true;
				// 
				// tPClienteMásFact
				// 
				this->tPClienteMásFact->Location = System::Drawing::Point(4, 22);
				this->tPClienteMásFact->Name = L"tPClienteMásFact";
				this->tPClienteMásFact->Size = System::Drawing::Size(1035, 497);
				this->tPClienteMásFact->TabIndex = 7;
				this->tPClienteMásFact->Text = L"Cliente + facturó";
				this->tPClienteMásFact->UseVisualStyleBackColor = true;
				// 
				// tPMostrarMarcas
				// 
				this->tPMostrarMarcas->Location = System::Drawing::Point(4, 22);
				this->tPMostrarMarcas->Name = L"tPMostrarMarcas";
				this->tPMostrarMarcas->Size = System::Drawing::Size(1035, 497);
				this->tPMostrarMarcas->TabIndex = 8;
				this->tPMostrarMarcas->Text = L"Mostrar Marcas";
				this->tPMostrarMarcas->UseVisualStyleBackColor = true;
				// 
				// tPFacturaMayor
				// 
				this->tPFacturaMayor->Location = System::Drawing::Point(4, 22);
				this->tPFacturaMayor->Name = L"tPFacturaMayor";
				this->tPFacturaMayor->Size = System::Drawing::Size(1035, 497);
				this->tPFacturaMayor->TabIndex = 9;
				this->tPFacturaMayor->Text = L"Factura+ monto";
				this->tPFacturaMayor->UseVisualStyleBackColor = true;
				// 
				// tPMostrarProd
				// 
				this->tPMostrarProd->Location = System::Drawing::Point(4, 22);
				this->tPMostrarProd->Name = L"tPMostrarProd";
				this->tPMostrarProd->Size = System::Drawing::Size(1035, 497);
				this->tPMostrarProd->TabIndex = 10;
				this->tPMostrarProd->Text = L"Mostrar productos";
				this->tPMostrarProd->UseVisualStyleBackColor = true;
				// 
				// tPMostrarClientes
				// 
				this->tPMostrarClientes->Location = System::Drawing::Point(4, 22);
				this->tPMostrarClientes->Name = L"tPMostrarClientes";
				this->tPMostrarClientes->Size = System::Drawing::Size(1035, 497);
				this->tPMostrarClientes->TabIndex = 11;
				this->tPMostrarClientes->Text = L"Mostrar Clientes";
				this->tPMostrarClientes->UseVisualStyleBackColor = true;
				// 
				// tPMosPasillos
				// 
				this->tPMosPasillos->Location = System::Drawing::Point(4, 22);
				this->tPMosPasillos->Name = L"tPMosPasillos";
				this->tPMosPasillos->Size = System::Drawing::Size(1035, 497);
				this->tPMosPasillos->TabIndex = 12;
				this->tPMosPasillos->Text = L"Mostrar Pasillos";
				this->tPMosPasillos->UseVisualStyleBackColor = true;
				// 
				// tPMosInventario
				// 
				this->tPMosInventario->Location = System::Drawing::Point(4, 22);
				this->tPMosInventario->Name = L"tPMosInventario";
				this->tPMosInventario->Size = System::Drawing::Size(1035, 497);
				this->tPMosInventario->TabIndex = 13;
				this->tPMosInventario->Text = L"Mostrar Inventario";
				this->tPMosInventario->UseVisualStyleBackColor = true;
				// 
				// btIngresar
				// 
				this->btIngresar->Cursor = System::Windows::Forms::Cursors::Hand;
				this->btIngresar->Location = System::Drawing::Point(227, 28);
				this->btIngresar->Name = L"btIngresar";
				this->btIngresar->Size = System::Drawing::Size(54, 23);
				this->btIngresar->TabIndex = 19;
				this->btIngresar->Text = L"Ingresar";
				this->btIngresar->UseVisualStyleBackColor = true;
				this->btIngresar->Click += gcnew System::EventHandler(this, &MenuPrincipal::btIngresar_Click_1);
				// 
				// textBoxIdentificacion
				// 
				this->textBoxIdentificacion->Location = System::Drawing::Point(29, 28);
				this->textBoxIdentificacion->Name = L"textBoxIdentificacion";
				this->textBoxIdentificacion->Size = System::Drawing::Size(192, 20);
				this->textBoxIdentificacion->TabIndex = 18;
				this->textBoxIdentificacion->TextChanged += gcnew System::EventHandler(this, &MenuPrincipal::textBoxIdentificacion_TextChanged);
				// 
				// lbCliente
				// 
				this->lbCliente->AutoSize = true;
				this->lbCliente->Location = System::Drawing::Point(26, 12);
				this->lbCliente->Name = L"lbCliente";
				this->lbCliente->Size = System::Drawing::Size(299, 13);
				this->lbCliente->TabIndex = 17;
				this->lbCliente->Text = L"Por favor ingrese su número de identificación de administrador";
				this->lbCliente->Click += gcnew System::EventHandler(this, &MenuPrincipal::lbCliente_Click);
				// 
				// tabPageClient
				// 
				this->tabPageClient->Controls->Add(this->lblClienteActual);
				this->tabPageClient->Controls->Add(this->tCClientes);
				this->tabPageClient->Controls->Add(this->btnIngresarClient);
				this->tabPageClient->Controls->Add(this->btNoRegistrado);
				this->tabPageClient->Controls->Add(this->textBoxClientes);
				this->tabPageClient->Controls->Add(this->label1);
				this->tabPageClient->Location = System::Drawing::Point(4, 22);
				this->tabPageClient->Name = L"tabPageClient";
				this->tabPageClient->Size = System::Drawing::Size(1076, 622);
				this->tabPageClient->TabIndex = 2;
				this->tabPageClient->Text = L"Clientes";
				this->tabPageClient->UseVisualStyleBackColor = true;
				// 
				// lblClienteActual
				// 
				this->lblClienteActual->AutoSize = true;
				this->lblClienteActual->Location = System::Drawing::Point(376, 35);
				this->lblClienteActual->Name = L"lblClienteActual";
				this->lblClienteActual->Size = System::Drawing::Size(142, 13);
				this->lblClienteActual->TabIndex = 17;
				this->lblClienteActual->Text = L"El cliente actual es: Ninguno";
				// 
				// tCClientes
				// 
				this->tCClientes->Controls->Add(this->tPConsultarPrecio);
				this->tCClientes->Controls->Add(this->tPConsultaDesc);
				this->tCClientes->Controls->Add(this->tPConsProd);
				this->tCClientes->Controls->Add(this->tPComprar);
				this->tCClientes->Location = System::Drawing::Point(13, 83);
				this->tCClientes->Name = L"tCClientes";
				this->tCClientes->SelectedIndex = 0;
				this->tCClientes->Size = System::Drawing::Size(1052, 491);
				this->tCClientes->TabIndex = 16;
				this->tCClientes->Visible = false;
				// 
				// tPConsultarPrecio
				// 
				this->tPConsultarPrecio->Controls->Add(this->button1);
				this->tPConsultarPrecio->Controls->Add(this->label4);
				this->tPConsultarPrecio->Controls->Add(this->label3);
				this->tPConsultarPrecio->Controls->Add(this->label2);
				this->tPConsultarPrecio->Controls->Add(this->tBPMarcaConsPrecCl);
				this->tPConsultarPrecio->Controls->Add(this->tBProdConsPrecCl);
				this->tPConsultarPrecio->Controls->Add(this->tBPasConsPrecCl);
				this->tPConsultarPrecio->Location = System::Drawing::Point(4, 22);
				this->tPConsultarPrecio->Name = L"tPConsultarPrecio";
				this->tPConsultarPrecio->Padding = System::Windows::Forms::Padding(3);
				this->tPConsultarPrecio->Size = System::Drawing::Size(1044, 465);
				this->tPConsultarPrecio->TabIndex = 0;
				this->tPConsultarPrecio->Text = L"Consultar precio";
				this->tPConsultarPrecio->UseVisualStyleBackColor = true;
				// 
				// button1
				// 
				this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
				this->button1->Location = System::Drawing::Point(362, 121);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(54, 23);
				this->button1->TabIndex = 20;
				this->button1->Text = L"Listo";
				this->button1->UseVisualStyleBackColor = true;
				this->button1->Click += gcnew System::EventHandler(this, &MenuPrincipal::button1_Click);
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Location = System::Drawing::Point(559, 28);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(153, 13);
				this->label4->TabIndex = 19;
				this->label4->Text = L"Introduzca el número de marca";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Location = System::Drawing::Point(296, 28);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(166, 13);
				this->label3->TabIndex = 18;
				this->label3->Text = L"Introduzca el número de producto";
				this->label3->Click += gcnew System::EventHandler(this, &MenuPrincipal::label3_Click);
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(35, 28);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(153, 13);
				this->label2->TabIndex = 17;
				this->label2->Text = L"Introduzca el número de pasillo";
				this->label2->Click += gcnew System::EventHandler(this, &MenuPrincipal::label2_Click);
				// 
				// tBPMarcaConsPrecCl
				// 
				this->tBPMarcaConsPrecCl->Location = System::Drawing::Point(562, 55);
				this->tBPMarcaConsPrecCl->Name = L"tBPMarcaConsPrecCl";
				this->tBPMarcaConsPrecCl->Size = System::Drawing::Size(114, 20);
				this->tBPMarcaConsPrecCl->TabIndex = 16;
				// 
				// tBProdConsPrecCl
				// 
				this->tBProdConsPrecCl->Location = System::Drawing::Point(299, 55);
				this->tBProdConsPrecCl->Name = L"tBProdConsPrecCl";
				this->tBProdConsPrecCl->Size = System::Drawing::Size(122, 20);
				this->tBProdConsPrecCl->TabIndex = 15;
				// 
				// tBPasConsPrecCl
				// 
				this->tBPasConsPrecCl->Location = System::Drawing::Point(33, 55);
				this->tBPasConsPrecCl->Name = L"tBPasConsPrecCl";
				this->tBPasConsPrecCl->Size = System::Drawing::Size(102, 20);
				this->tBPasConsPrecCl->TabIndex = 14;
				// 
				// tPConsultaDesc
				// 
				this->tPConsultaDesc->Controls->Add(this->btnConsDescCl);
				this->tPConsultaDesc->Location = System::Drawing::Point(4, 22);
				this->tPConsultaDesc->Name = L"tPConsultaDesc";
				this->tPConsultaDesc->Padding = System::Windows::Forms::Padding(3);
				this->tPConsultaDesc->Size = System::Drawing::Size(1044, 465);
				this->tPConsultaDesc->TabIndex = 1;
				this->tPConsultaDesc->Text = L"Consultar descuento";
				this->tPConsultaDesc->UseVisualStyleBackColor = true;
				// 
				// btnConsDescCl
				// 
				this->btnConsDescCl->Cursor = System::Windows::Forms::Cursors::Hand;
				this->btnConsDescCl->Location = System::Drawing::Point(400, 192);
				this->btnConsDescCl->Name = L"btnConsDescCl";
				this->btnConsDescCl->Size = System::Drawing::Size(167, 23);
				this->btnConsDescCl->TabIndex = 31;
				this->btnConsDescCl->Text = L"Consultar Descuento";
				this->btnConsDescCl->UseVisualStyleBackColor = true;
				this->btnConsDescCl->Click += gcnew System::EventHandler(this, &MenuPrincipal::button5_Click);
				// 
				// tPConsProd
				// 
				this->tPConsProd->Controls->Add(this->btnConsProdListo);
				this->tPConsProd->Controls->Add(this->label10);
				this->tPConsProd->Controls->Add(this->tBPasConsProdCl);
				this->tPConsProd->Location = System::Drawing::Point(4, 22);
				this->tPConsProd->Name = L"tPConsProd";
				this->tPConsProd->Size = System::Drawing::Size(1044, 465);
				this->tPConsProd->TabIndex = 2;
				this->tPConsProd->Text = L"Consultar productos";
				this->tPConsProd->UseVisualStyleBackColor = true;
				// 
				// btnConsProdListo
				// 
				this->btnConsProdListo->Cursor = System::Windows::Forms::Cursors::Hand;
				this->btnConsProdListo->Location = System::Drawing::Point(427, 242);
				this->btnConsProdListo->Name = L"btnConsProdListo";
				this->btnConsProdListo->Size = System::Drawing::Size(54, 23);
				this->btnConsProdListo->TabIndex = 29;
				this->btnConsProdListo->Text = L"Listo";
				this->btnConsProdListo->UseVisualStyleBackColor = true;
				this->btnConsProdListo->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnConsProdListo_Click);
				// 
				// label10
				// 
				this->label10->AutoSize = true;
				this->label10->Location = System::Drawing::Point(424, 167);
				this->label10->Name = L"label10";
				this->label10->Size = System::Drawing::Size(153, 13);
				this->label10->TabIndex = 26;
				this->label10->Text = L"Introduzca el número de pasillo";
				// 
				// tBPasConsProdCl
				// 
				this->tBPasConsProdCl->Location = System::Drawing::Point(427, 194);
				this->tBPasConsProdCl->Name = L"tBPasConsProdCl";
				this->tBPasConsProdCl->Size = System::Drawing::Size(102, 20);
				this->tBPasConsProdCl->TabIndex = 23;
				// 
				// tPComprar
				// 
				this->tPComprar->Controls->Add(this->lblInsuficienteProd);
				this->tPComprar->Controls->Add(this->tBCantProdN);
				this->tPComprar->Controls->Add(this->btnOp2);
				this->tPComprar->Controls->Add(this->btnOp1);
				this->tPComprar->Controls->Add(this->label24);
				this->tPComprar->Controls->Add(this->tPCantProd);
				this->tPComprar->Controls->Add(this->button25);
				this->tPComprar->Controls->Add(this->button24);
				this->tPComprar->Controls->Add(this->button11);
				this->tPComprar->Controls->Add(this->label21);
				this->tPComprar->Controls->Add(this->button13);
				this->tPComprar->Controls->Add(this->label11);
				this->tPComprar->Controls->Add(this->label12);
				this->tPComprar->Controls->Add(this->label13);
				this->tPComprar->Controls->Add(this->tBMarcaComp);
				this->tPComprar->Controls->Add(this->tBProdComp);
				this->tPComprar->Controls->Add(this->tBPasComp);
				this->tPComprar->Location = System::Drawing::Point(4, 22);
				this->tPComprar->Name = L"tPComprar";
				this->tPComprar->Size = System::Drawing::Size(1044, 465);
				this->tPComprar->TabIndex = 3;
				this->tPComprar->Text = L"Comprar";
				this->tPComprar->UseVisualStyleBackColor = true;
				this->tPComprar->Click += gcnew System::EventHandler(this, &MenuPrincipal::tPComprar_Click);
				// 
				// lblInsuficienteProd
				// 
				this->lblInsuficienteProd->AutoSize = true;
				this->lblInsuficienteProd->Location = System::Drawing::Point(247, 301);
				this->lblInsuficienteProd->Name = L"lblInsuficienteProd";
				this->lblInsuficienteProd->Size = System::Drawing::Size(560, 13);
				this->lblInsuficienteProd->TabIndex = 41;
				this->lblInsuficienteProd->Text = L"Por favor ingrese la cantidad del producto que desee comprar, asegurese de no sob"
					L"repasar la cantidad en gondolas: ";
				this->lblInsuficienteProd->Visible = false;
				// 
				// tBCantProdN
				// 
				this->tBCantProdN->Location = System::Drawing::Point(296, 344);
				this->tBCantProdN->Name = L"tBCantProdN";
				this->tBCantProdN->Size = System::Drawing::Size(102, 20);
				this->tBCantProdN->TabIndex = 40;
				this->tBCantProdN->Visible = false;
				// 
				// btnOp2
				// 
				this->btnOp2->Location = System::Drawing::Point(555, 373);
				this->btnOp2->Name = L"btnOp2";
				this->btnOp2->Size = System::Drawing::Size(69, 28);
				this->btnOp2->TabIndex = 39;
				this->btnOp2->Text = L"Opcion 2";
				this->btnOp2->UseVisualStyleBackColor = true;
				this->btnOp2->Visible = false;
				this->btnOp2->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnOp2_Click);
				// 
				// btnOp1
				// 
				this->btnOp1->Location = System::Drawing::Point(296, 373);
				this->btnOp1->Name = L"btnOp1";
				this->btnOp1->Size = System::Drawing::Size(69, 28);
				this->btnOp1->TabIndex = 38;
				this->btnOp1->Text = L"Opcion 1";
				this->btnOp1->UseVisualStyleBackColor = true;
				this->btnOp1->Visible = false;
				this->btnOp1->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnOp1_Click);
				// 
				// label24
				// 
				this->label24->AutoSize = true;
				this->label24->Location = System::Drawing::Point(759, 155);
				this->label24->Name = L"label24";
				this->label24->Size = System::Drawing::Size(227, 13);
				this->label24->TabIndex = 37;
				this->label24->Text = L"Introduzca la cantidad del producto que desea";
				// 
				// tPCantProd
				// 
				this->tPCantProd->Location = System::Drawing::Point(762, 182);
				this->tPCantProd->Name = L"tPCantProd";
				this->tPCantProd->Size = System::Drawing::Size(102, 20);
				this->tPCantProd->TabIndex = 36;
				// 
				// button25
				// 
				this->button25->Cursor = System::Windows::Forms::Cursors::Hand;
				this->button25->Location = System::Drawing::Point(555, 109);
				this->button25->Name = L"button25";
				this->button25->Size = System::Drawing::Size(102, 25);
				this->button25->TabIndex = 35;
				this->button25->Text = L"Mostrar Marcas";
				this->button25->UseVisualStyleBackColor = true;
				// 
				// button24
				// 
				this->button24->Cursor = System::Windows::Forms::Cursors::Hand;
				this->button24->Location = System::Drawing::Point(338, 109);
				this->button24->Name = L"button24";
				this->button24->Size = System::Drawing::Size(102, 25);
				this->button24->TabIndex = 34;
				this->button24->Text = L"Mostrar Productos";
				this->button24->UseVisualStyleBackColor = true;
				// 
				// button11
				// 
				this->button11->Cursor = System::Windows::Forms::Cursors::Hand;
				this->button11->Location = System::Drawing::Point(72, 109);
				this->button11->Name = L"button11";
				this->button11->Size = System::Drawing::Size(102, 25);
				this->button11->TabIndex = 31;
				this->button11->Text = L"Mostrar Pasillos";
				this->button11->UseVisualStyleBackColor = true;
				this->button11->Click += gcnew System::EventHandler(this, &MenuPrincipal::button11_Click);
				// 
				// label21
				// 
				this->label21->AutoSize = true;
				this->label21->Location = System::Drawing::Point(27, 17);
				this->label21->Name = L"label21";
				this->label21->Size = System::Drawing::Size(268, 13);
				this->label21->TabIndex = 30;
				this->label21->Text = L"Introduzca la información del objeto que desea comprar";
				// 
				// button13
				// 
				this->button13->Cursor = System::Windows::Forms::Cursors::Hand;
				this->button13->Location = System::Drawing::Point(470, 239);
				this->button13->Name = L"button13";
				this->button13->Size = System::Drawing::Size(54, 23);
				this->button13->TabIndex = 29;
				this->button13->Text = L"Listo";
				this->button13->UseVisualStyleBackColor = true;
				this->button13->Click += gcnew System::EventHandler(this, &MenuPrincipal::button13_Click);
				// 
				// label11
				// 
				this->label11->AutoSize = true;
				this->label11->Location = System::Drawing::Point(552, 155);
				this->label11->Name = L"label11";
				this->label11->Size = System::Drawing::Size(153, 13);
				this->label11->TabIndex = 28;
				this->label11->Text = L"Introduzca el número de marca";
				// 
				// label12
				// 
				this->label12->AutoSize = true;
				this->label12->Location = System::Drawing::Point(335, 155);
				this->label12->Name = L"label12";
				this->label12->Size = System::Drawing::Size(166, 13);
				this->label12->TabIndex = 27;
				this->label12->Text = L"Introduzca el número de producto";
				// 
				// label13
				// 
				this->label13->AutoSize = true;
				this->label13->Location = System::Drawing::Point(69, 155);
				this->label13->Name = L"label13";
				this->label13->Size = System::Drawing::Size(153, 13);
				this->label13->TabIndex = 26;
				this->label13->Text = L"Introduzca el número de pasillo";
				this->label13->Click += gcnew System::EventHandler(this, &MenuPrincipal::label13_Click);
				// 
				// tBMarcaComp
				// 
				this->tBMarcaComp->Location = System::Drawing::Point(555, 182);
				this->tBMarcaComp->Name = L"tBMarcaComp";
				this->tBMarcaComp->Size = System::Drawing::Size(114, 20);
				this->tBMarcaComp->TabIndex = 25;
				this->tBMarcaComp->TextChanged += gcnew System::EventHandler(this, &MenuPrincipal::textBox10_TextChanged);
				// 
				// tBProdComp
				// 
				this->tBProdComp->Location = System::Drawing::Point(338, 182);
				this->tBProdComp->Name = L"tBProdComp";
				this->tBProdComp->Size = System::Drawing::Size(122, 20);
				this->tBProdComp->TabIndex = 24;
				// 
				// tBPasComp
				// 
				this->tBPasComp->Location = System::Drawing::Point(72, 182);
				this->tBPasComp->Name = L"tBPasComp";
				this->tBPasComp->Size = System::Drawing::Size(102, 20);
				this->tBPasComp->TabIndex = 23;
				// 
				// btnIngresarClient
				// 
				this->btnIngresarClient->Cursor = System::Windows::Forms::Cursors::Hand;
				this->btnIngresarClient->Location = System::Drawing::Point(211, 30);
				this->btnIngresarClient->Name = L"btnIngresarClient";
				this->btnIngresarClient->Size = System::Drawing::Size(54, 23);
				this->btnIngresarClient->TabIndex = 15;
				this->btnIngresarClient->Text = L"Ingresar";
				this->btnIngresarClient->UseVisualStyleBackColor = true;
				this->btnIngresarClient->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnIngresarClient_Click);
				// 
				// btNoRegistrado
				// 
				this->btNoRegistrado->Cursor = System::Windows::Forms::Cursors::Hand;
				this->btNoRegistrado->Location = System::Drawing::Point(712, 33);
				this->btNoRegistrado->Name = L"btNoRegistrado";
				this->btNoRegistrado->Size = System::Drawing::Size(112, 23);
				this->btNoRegistrado->TabIndex = 14;
				this->btNoRegistrado->Text = L"No estoy registrado";
				this->btNoRegistrado->UseVisualStyleBackColor = true;
				this->btNoRegistrado->Click += gcnew System::EventHandler(this, &MenuPrincipal::btNoRegistrado_Click);
				// 
				// textBoxClientes
				// 
				this->textBoxClientes->Location = System::Drawing::Point(13, 33);
				this->textBoxClientes->Name = L"textBoxClientes";
				this->textBoxClientes->Size = System::Drawing::Size(192, 20);
				this->textBoxClientes->TabIndex = 13;
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(10, 14);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(302, 13);
				this->label1->TabIndex = 12;
				this->label1->Text = L"Si está registrado por favor ingrese su número de identificación";
				// 
				// BtnInicial
				// 
				this->BtnInicial->Location = System::Drawing::Point(279, 261);
				this->BtnInicial->Name = L"BtnInicial";
				this->BtnInicial->Size = System::Drawing::Size(410, 189);
				this->BtnInicial->TabIndex = 0;
				this->BtnInicial->Text = L"button1";
				this->BtnInicial->UseVisualStyleBackColor = true;
				this->BtnInicial->UseWaitCursor = true;
				this->BtnInicial->Click += gcnew System::EventHandler(this, &MenuPrincipal::BtnInicial_Click);
				// 
				// MenuPrincipal
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->ClientSize = System::Drawing::Size(1089, 674);
				this->Controls->Add(this->titulo);
				this->Controls->Add(this->tCMenuPrinc);
				this->Controls->Add(this->BtnInicial);
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
				this->Name = L"MenuPrincipal";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"Menu Principal";
				this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
				this->tCMenuPrinc->ResumeLayout(false);
				this->tPVendedor->ResumeLayout(false);
				this->tPVendedor->PerformLayout();
				this->tCVendedor->ResumeLayout(false);
				this->tPConsPrecioVen->ResumeLayout(false);
				this->tPConsPrecioVen->PerformLayout();
				this->tabPageAdmin->ResumeLayout(false);
				this->tabPageAdmin->PerformLayout();
				this->tabControl2->ResumeLayout(false);
				this->tPBasesDatos->ResumeLayout(false);
				this->tabControl1->ResumeLayout(false);
				this->tPFacturar->ResumeLayout(false);
				this->tPRevGondolas->ResumeLayout(false);
				this->tPRevGondolas->PerformLayout();
				this->tPVerInventario->ResumeLayout(false);
				this->tPVerInventario->PerformLayout();
				this->tPReportes->ResumeLayout(false);
				this->tabControl3->ResumeLayout(false);
				this->tPPasMasVis->ResumeLayout(false);
				this->tPPasMasVis->PerformLayout();
				this->tPPasMenosVis->ResumeLayout(false);
				this->tPPasMenosVis->PerformLayout();
				this->tPClienteMasComp->ResumeLayout(false);
				this->tPClienteMenosComp->ResumeLayout(false);
				this->tPClienteMenosComp->PerformLayout();
				this->tabPageClient->ResumeLayout(false);
				this->tabPageClient->PerformLayout();
				this->tCClientes->ResumeLayout(false);
				this->tPConsultarPrecio->ResumeLayout(false);
				this->tPConsultarPrecio->PerformLayout();
				this->tPConsultaDesc->ResumeLayout(false);
				this->tPConsProd->ResumeLayout(false);
				this->tPConsProd->PerformLayout();
				this->tPComprar->ResumeLayout(false);
				this->tPComprar->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	#pragma endregion
		private: System::Void MenuPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
			this->BtnInicial->Visible = true;
			this->titulo->Visible = true;
		
		}

		public: static string toStandardString(System::String^ string)
		{
			using System::Runtime::InteropServices::Marshal;
			System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
			char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
			std::string returnString(charPointer, string->Length);
			Marshal::FreeHGlobal(pointer);
			return returnString;

		}

	
		private: System::Void btCerrarPrograma_Click(System::Object^ sender, System::EventArgs^ e) {
			System::Windows::Forms::DialogResult opcion;

			MessageBox::Show("¿Está seguro que desea salir del sistema?", "Saliendo del sistema!", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			if (opcion==System::Windows::Forms::DialogResult::Yes) {
				this->Close();
			};
		}
	private: System::Void titulo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lbCliente_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBoxIdentificacion_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btIngresar_Click_1(System::Object^ sender, System::EventArgs^ e) {
		bool encontrado = false;
		string textoDeCaja = this->toStandardString(this->textBoxIdentificacion->Text);
		int pCodAdministrador = 2343;
		if (textoDeCaja != "") { 
			pCodAdministrador = stoi(textoDeCaja); 
		}
		encontrado = AAdmin.BuscarCedula(AAdmin.raiz, pCodAdministrador);
		if (encontrado) {//this->textBoxIdentificacion->Text == "123456"
			this->tabControl2->Visible = true;
		}
		else {
			MessageBox::Show("Administrador no encontrado, por favor ingrese una identificación válida", "Administrador no encontrado!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		
		}
	}
	private: System::Void btConsultarPrecio_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btConsultarProductos_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btConsultarDescuento_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btComprar_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tPVendedor_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void BtnInicial_Click(System::Object^ sender, System::EventArgs^ e) {
		this->tCMenuPrinc->Visible = true;
		this->BtnInicial->Visible = false;
	}
	private: System::Void btNoRegistrado_Click(System::Object^ sender, System::EventArgs^ e) {
		pCedula = 0;
		this->button11->Visible = false;
		this->label13->Visible = false;
		this->tBPasComp->Visible = false;
		this->button24->Visible = false;
		this->label12->Visible = false;
		this->tBProdComp->Visible = false;
		this->button25->Visible = false;
		this->label11->Visible = false;
		this->tBMarcaComp->Visible = false;
		this->label24->Visible = false;
		this->tPCantProd->Visible = false;
		this->button13->Visible = false;
		this->label21->Visible = false;
		this->btnConsDescCl->Visible = false;

		
		this->tCClientes->Visible = true;
		this->lblClienteActual->Text = msclr::interop::marshal_as<String^>("El cliente actual es : No registrado" );
	}
	private: System::Void btnIngresarClient_Click(System::Object^ sender, System::EventArgs^ e) {
		bool encontrado = false;
		string textoDeCaja = this->toStandardString(this->textBoxClientes->Text);
		int pCodCliente = 2343;
		if (textoDeCaja != "") { 
			pCodCliente = stoi(textoDeCaja); 
		}
		encontrado = AC.BuscarCedula(AC.raiz, pCodCliente);
		if (encontrado) {
			this->tCClientes->Visible = true;
			this->button11->Visible = true;
			this->label13->Visible = true;
			this->tBPasComp->Visible = true;
			this->button24->Visible = true;
			this->label12->Visible = true;
			this->tBProdComp->Visible = true;
			this->button25->Visible = true;
			this->label11->Visible = true;
			this->tBMarcaComp->Visible = true;
			this->label24->Visible = true;
			this->tPCantProd->Visible = true;
			this->button13->Visible = true;
			this->label21->Visible = true;
			this->btnConsDescCl->Visible = true;

			this->lblClienteActual->Text = msclr::interop::marshal_as<String^>("El cliente actual es : "+AC.devolverNombre(pCodCliente));
		}
		else {
			MessageBox::Show("Cliente no encontrado, por favor ingrese una identificación válida", "Cliente no encontrado!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label16_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label14_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label15_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox13_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox14_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox15_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnFacturar_Click(System::Object^ sender, System::EventArgs^ e) {
		int opcion = 0;
		bool encontrado = false;   //###
		int pCodAdministrador = 0;
		int contadorcito = 0;
		if (contadorsote < LCompras.largoLista()) { //Si no se ha recorrido toda la lista
			double total = 0;
			ofstream archivo;
			int cedula = LCompras.buscarCedula(contadorsote);
			string nombreArchivo(to_string(cedula) + "#" + to_string(contadorsote) + ".txt");
			archivo.open(nombreArchivo.c_str(), fstream::out); //se abre el archivo
			if (archivo.fail()) {
				cout << "No se pudo abrir el archivo";
				exit(1);
			}
			archivo << cedula << "#" << contadorsote << endl;
			contadorcito = 0;
			bool descontar = false;  //###
			while (contadorcito < LCompras.tamanoLM(contadorsote)) { //Mientras no se hayan recorrido todos los productos que desea comprar un cliente con una cédula específica
				int CodPasillo = LCompras.obtenerPasillo(contadorsote, contadorcito);
				int CodProducto = LCompras.obtenerProducto(contadorsote, contadorcito);
				int CodMarca = LCompras.obtenerMarca(contadorsote, contadorcito);
				int CantidadUsuario = LCompras.obtenerCantidad(contadorsote, contadorcito);
				//int cedula= LCompras.obtenerCedula(contadorsote);
				int precio = A1.BuscarPrecio(A1.raiz, CodPasillo, CodProducto, CodMarca);
				int codCanasta = A2.BuscarCB(A2.raiz, CodPasillo, CodProducto, CodMarca);
				if (codCanasta == 0) {
					precio = precio * 1.01;
					archivo << endl << "CodProducto:" << CodProducto << "|| CodMarca: " << CodMarca << "|| Cantidad: " << CantidadUsuario << "|| precio por unidad con impuesto de 1%: " << precio << " colones" << endl;
					precio = precio * CantidadUsuario;
				}
				else if (codCanasta == 1) {
					precio = precio * 1.13;
					archivo << endl << "CodProducto:" << CodProducto << "|| CodMarca: " << CodMarca << "|| Cantidad: " << CantidadUsuario << "|| precio por unidad con impuesto de 13%: " << precio << " colones" << endl;
					precio = precio * CantidadUsuario;
				}
				else {
					cout << "Codigo canasta invalido" << endl;
				}

				total += precio;
				contadorcito++;

				/*
				pasilloRepetido.InsertarFinal(CodPasillo);
				ClienteMasFacturo.InsertarFinal(cedula);
				LSVentas.verificarCedula(cedula, CodPasillo, CodProducto, CodMarca, " ",CantidadUsuario);
				*/
			}
			descontar = LCompras.verificarDescuento(cedula);
			if (descontar) {
				total = total * (1 - descuento / 100);
			}
			if (total > facturaMasGrandeInt) { //###
				facturaMasGrandeInt = total;
				facturaMasGrande =  msclr::interop::marshal_as<String^>( to_string(cedula) + "#" + to_string(contadorsote) );
				ClienteMasCompro = msclr::interop::marshal_as<String^>(  AC.devolverNombre(cedula)  );
			}
			cout << "Factura más grande " << endl;
			if (total < facturaMenosGrandeInt || facturaMenosGrandeInt == -1) { //###
				facturaMenosGrandeInt = total;
				facturaMenosGrande = msclr::interop::marshal_as<String^>(  to_string(cedula) + "#" + to_string(contadorsote)  );
				ClienteMenosCompro = msclr::interop::marshal_as<String^>(  AC.devolverNombre(cedula)  );
			}
			cout << "Factura menos grande " << endl;
			LCompras.facturar(contadorsote);
			archivo << endl << "El total de la factura es de: " << total << " colones" << endl;
			if (descontar) {
				archivo << endl << "El descuento es de: " << descuento << "%" << endl;
			}
			else {
				archivo << endl << "El descuento es de: 0%" << endl;
			}
			archivo.close(); //se cierra el archivo
			CR.InsertarFinal(cedula);
			contadorsote++;
		}
		else if (LCompras.largoLista() == 0) {
			cout << "No hay compras por facturar" << endl;
		}
		else {
			cout << "No hay mas clientes que necesiten facturar" << endl;
		}
	}



	private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
		int pasilloMas = LR.encontrarMas();
		string pasilloMasStr = "No se ha realizado ninguna compra";
		if (LCompras.ListaVacia()) {
			pasilloMasStr = "El pasillo mas visitado fue: " + A1.devolverNombrePas(A1.raiz, pasilloMas,"") + "  cuyo codigo pasillo es: " + to_string(pasilloMas);
		}
		this->lblPasMasVis->Text = msclr::interop::marshal_as<String^>( pasilloMasStr );
	}
	private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
		int pasilloMenos = LR.encontrarMenos();
		string pasilloMenosStr = "No se ha realizado ninguna compra";
		if (LCompras.ListaVacia()) {
			pasilloMenosStr = "El pasillo menos visitado fue: " + A1.devolverNombrePas(A1.raiz, pasilloMenos,"") + "  cuyo codigo pasillo es: " + to_string(pasilloMenos);
		}
		this->lblPasilloMenosVis->Text = msclr::interop::marshal_as<String^>(pasilloMenosStr);
	}
	private: System::Void button22_Click_1(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show(msclr::interop::marshal_as<String^>( to_string(A1.BuscarPrecio(A1.raiz, 01, 20, 51))) );
		MessageBox::Show(ClienteMasFacturo);
	}

	private: System::Void label13_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox10_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
		int opcion = 0;
		int opcion2 = 0;
		pCodPasillo= stoi(this->toStandardString(this->tBPasComp->Text));
		pCodProducto= stoi(this->toStandardString(this->tBProdComp->Text));
		pCodMarca= stoi(this->toStandardString(this->tBMarcaComp->Text));
		pCantidadProducto= stoi(this->toStandardString(this->tPCantProd->Text)); 
		bool encontrado;
		encontrado = A1.BuscarPasillo2(A1.raiz, pCodPasillo);
		if (encontrado) {
			LR.InsertarFinal(pCodPasillo);
			encontrado = A1.BuscarProductoC(A1.raiz, pCodPasillo, pCodProducto);
			if (encontrado) {
				encontrado = A1.BuscarMarcaC(A1.raiz, pCodPasillo, pCodProducto, pCodMarca);
				if (encontrado) {
					int pCantidadGondola = A1.buscarGondola(A1.raiz, pCodPasillo, pCodProducto, pCodMarca); //###
					if (pCantidadGondola < pCantidadProducto) {
						MessageBox::Show(msclr::interop::marshal_as<String^>("Actualmente no hay suficiente cantidad de productos de la marca escogida por lo que se le brinda dos soluciones:  1. Elegir nuevamente la cantidad   2. Comprar las "+ to_string(pCantidadGondola) + " unidades del producto \n Elija una opcion, si elije cualquier otro numero la compra no se reallizara: "));
						this->btnOp1->Visible = true;
						this->btnOp2->Visible = true;
						this->lblInsuficienteProd->Visible = true;
						this->tBCantProdN->Visible = true;
					}
					else {
						LCompras.verificarCedula(pCedula, pCodPasillo, pCodProducto, pCodMarca, " ", pCantidadProducto);
						MessageBox::Show(msclr::interop::marshal_as<String^>("Se ha agregado exitosamente el producto a la lista de compras"));
					}
				}
				else {
					MessageBox::Show(msclr::interop::marshal_as<String^>("La marca digitada, dentro del pasillo y producto elegido no se encuentra en nuestra base de datos, por favor intentelo de nuevo. Agradecemos su paciencia"));
				}
			}
			else {
				MessageBox::Show(msclr::interop::marshal_as<String^>("El producto digitado no se encuentra en nuestra base de datos dentro del pasillo elegido, por favor intentelo de nuevo. Agradecemos su paciencia"));
			}
		}
		else {
			MessageBox::Show(msclr::interop::marshal_as<String^>("El pasillo digitado no se encuentra en nuestra base de datos, por favor intentelo de nuevo. Agradecemos su paciencia"));
		}
	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show(msclr::interop::marshal_as<String^>(A1.InordenI("")));
	}
	private: System::Void btnOp2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->btnOp1->Visible = false;
		this->btnOp2->Visible = false;
		this->lblInsuficienteProd->Visible = false;
		this->tBCantProdN->Visible = false;
		int pCantidadGondola = A1.buscarGondola(A1.raiz, pCodPasillo, pCodProducto, pCodMarca);
		pCantidadProducto = pCantidadGondola;
		LCompras.verificarCedula(pCedula, pCodPasillo, pCodProducto, pCodMarca, " ", pCantidadProducto);
		MessageBox::Show(msclr::interop::marshal_as<String^>("Se ha agregado exitosamente el producto a la lista de compras"));
		pCantidadGondola = -1;
		pCantidadProducto = 0;
		pCodPasillo = 0;
		pCodProducto = 0;
		pCodMarca = 0;
	}
	private: System::Void btnOp1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->btnOp1->Visible = false;
		this->btnOp2->Visible = false;
		this->lblInsuficienteProd->Visible = false;
		this->tBCantProdN->Visible = false;
		pCantidadProducto = stoi(this->toStandardString(this->tBCantProdN->Text)) ;
		int pCantidadGondola = A1.buscarGondola(A1.raiz, pCodPasillo, pCodProducto, pCodMarca);
		if (pCantidadGondola < pCantidadProducto) {
			MessageBox::Show(msclr::interop::marshal_as<String^>("No se realizo la compra debido a que se quiere comprar más de lo disponible"));
		}
		else {
			LCompras.verificarCedula(pCedula, pCodPasillo, pCodProducto, pCodMarca, " ", pCantidadProducto);
			MessageBox::Show(msclr::interop::marshal_as<String^>("Se ha agregado exitosamente el producto a la lista de compras"));
		}
		pCantidadGondola = -1;
		pCantidadProducto=0;
		pCodPasillo=0;
		pCodProducto=0;
		pCodMarca=0;
	}

	private: System::Void tPComprar_Click(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void btnConsProdListo_Click(System::Object^ sender, System::EventArgs^ e) {
	pCodPasillo = stoi(this->toStandardString(this->tBPasConsProdCl->Text));
	bool encontrado;
	encontrado = A1.BuscarPasillo(A1.raiz, pCodPasillo);
	if (encontrado) {
		MessageBox::Show(msclr::interop::marshal_as<String^>(A1.BuscarProducto1(A1.raiz, pCodPasillo)));
	}else {
		MessageBox::Show(msclr::interop::marshal_as<String^>("El pasillo digitado no se encuentra en nuestra base de datos, por favor intentelo de nuevo. Agradecemos su paciencia"));
	}
	pCodPasillo = 0;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	bool descontar = false;
	descontar = LCompras.verificarDescuento(pCedula); //###
	if (descontar) {
		MessageBox::Show(msclr::interop::marshal_as<String^>("El descuento es de: " + to_string(descuento)+"%" ));
	}
	else {
		MessageBox::Show(msclr::interop::marshal_as<String^>("El descuento es de: 0%"));
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	pCodPasillo = stoi(this->toStandardString(this->tBPasConsPrecCl->Text));
	pCodProducto = stoi(this->toStandardString(this->tBProdConsPrecCl->Text));
	pCodMarca = stoi(this->toStandardString(this->tBPMarcaConsPrecCl->Text));
	bool encontrado;
	encontrado = A1.BuscarPasillo2(A1.raiz, pCodPasillo);
	if (encontrado) {
		LR.InsertarFinal(pCodPasillo);
		encontrado = A1.BuscarProductoC(A1.raiz, pCodPasillo, pCodProducto);
		if (encontrado) {
			encontrado = A1.BuscarMarcaC(A1.raiz, pCodPasillo, pCodProducto, pCodMarca);
			if (encontrado) {
				int precio= A1.BuscarPrecio(A1.raiz, pCodPasillo, pCodProducto, pCodMarca);
				MessageBox::Show(msclr::interop::marshal_as<String^>("El precio del producto consultado es de "+ to_string(precio) + " unidades monetarias."));
			}
			else {
				MessageBox::Show(msclr::interop::marshal_as<String^>("La marca digitada, dentro del pasillo y producto elegido no se encuentra en nuestra base de datos, por favor intentelo de nuevo. Agradecemos su paciencia"));
			}
		}
		else {
			MessageBox::Show(msclr::interop::marshal_as<String^>("El producto digitado no se encuentra en nuestra base de datos dentro del pasillo elegido, por favor intentelo de nuevo. Agradecemos su paciencia"));
		}
	}
	else {
		MessageBox::Show(msclr::interop::marshal_as<String^>("El pasillo digitado no se encuentra en nuestra base de datos, por favor intentelo de nuevo. Agradecemos su paciencia"));
	}
	pCodPasillo = 0;
	pCodProducto = 0;
	pCodMarca = 0;
}
private: System::Void btnIngresarVend_Click(System::Object^ sender, System::EventArgs^ e) {
	bool encontrado = false;
	string textoDeCaja = this->toStandardString(this->textBoxVendedor->Text);
	int pCodVendedor = 2343;
	if (textoDeCaja != "") {
		pCodVendedor = stoi(textoDeCaja);
	}
	encontrado = Vendedor.BuscarCedula(Vendedor.raiz, pCodVendedor);
	if (encontrado) {
		this->tCVendedor->Visible = true;
	}
	else {
		MessageBox::Show("Administrador no encontrado, por favor ingrese una identificación válida", "Administrador no encontrado!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	pCodPasillo = stoi(this->toStandardString(this->tBPasConsPrV->Text));
	pCodProducto = stoi(this->toStandardString(this->tBProdConsPrV->Text));
	pCodMarca = stoi(this->toStandardString(this->tBMarcaConsPrV->Text));
	bool encontrado;
	encontrado = A1.BuscarPasillo2(A1.raiz, pCodPasillo);
	if (encontrado) {
		LR.InsertarFinal(pCodPasillo);
		encontrado = A1.BuscarProductoC(A1.raiz, pCodPasillo, pCodProducto);
		if (encontrado) {
			encontrado = A1.BuscarMarcaC(A1.raiz, pCodPasillo, pCodProducto, pCodMarca);
			if (encontrado) {
				int precio = A1.BuscarPrecio(A1.raiz, pCodPasillo, pCodProducto, pCodMarca);
				MessageBox::Show(msclr::interop::marshal_as<String^>("El precio del producto consultado es de " + to_string(precio) + " unidades monetarias."));
			}
			else {
				MessageBox::Show(msclr::interop::marshal_as<String^>("La marca digitada, dentro del pasillo y producto elegido no se encuentra en nuestra base de datos, por favor intentelo de nuevo. Agradecemos su paciencia"));
			}
		}
		else {
			MessageBox::Show(msclr::interop::marshal_as<String^>("El producto digitado no se encuentra en nuestra base de datos dentro del pasillo elegido, por favor intentelo de nuevo. Agradecemos su paciencia"));
		}
	}
	else {
		MessageBox::Show(msclr::interop::marshal_as<String^>("El pasillo digitado no se encuentra en nuestra base de datos, por favor intentelo de nuevo. Agradecemos su paciencia"));
	}
	pCodPasillo = 0;
	pCodProducto = 0;
	pCodMarca = 0;
}
};
}
