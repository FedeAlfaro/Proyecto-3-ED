#pragma once

namespace Proyecto3Pruebita {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MenuInsertar : public System::Windows::Forms::Form
	{
	public:
		MenuInsertar(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuInsertar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btVolver;
	protected:
	private: System::Windows::Forms::Button^ btRegistrarVendedores;
	private: System::Windows::Forms::Button^ btRegistrarAdministradores;
	private: System::Windows::Forms::Button^ btRegistrarClientes;
	private: System::Windows::Forms::Button^ btInsertarInventario;
	private: System::Windows::Forms::Button^ btMarcaNueva;
	private: System::Windows::Forms::Button^ btProductoNuevo;
	private: System::Windows::Forms::Button^ btInsertarPasillo;

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
			this->btVolver = (gcnew System::Windows::Forms::Button());
			this->btRegistrarVendedores = (gcnew System::Windows::Forms::Button());
			this->btRegistrarAdministradores = (gcnew System::Windows::Forms::Button());
			this->btRegistrarClientes = (gcnew System::Windows::Forms::Button());
			this->btInsertarInventario = (gcnew System::Windows::Forms::Button());
			this->btMarcaNueva = (gcnew System::Windows::Forms::Button());
			this->btProductoNuevo = (gcnew System::Windows::Forms::Button());
			this->btInsertarPasillo = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btVolver
			// 
			this->btVolver->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btVolver->Location = System::Drawing::Point(12, 282);
			this->btVolver->Name = L"btVolver";
			this->btVolver->Size = System::Drawing::Size(75, 23);
			this->btVolver->TabIndex = 15;
			this->btVolver->Text = L"Volver";
			this->btVolver->UseVisualStyleBackColor = true;
			this->btVolver->Click += gcnew System::EventHandler(this, &MenuInsertar::btVolver_Click);
			// 
			// btRegistrarVendedores
			// 
			this->btRegistrarVendedores->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btRegistrarVendedores->Location = System::Drawing::Point(101, 228);
			this->btRegistrarVendedores->Name = L"btRegistrarVendedores";
			this->btRegistrarVendedores->Size = System::Drawing::Size(137, 34);
			this->btRegistrarVendedores->TabIndex = 14;
			this->btRegistrarVendedores->Text = L"Registrar vendedores";
			this->btRegistrarVendedores->UseVisualStyleBackColor = true;
			this->btRegistrarVendedores->Click += gcnew System::EventHandler(this, &MenuInsertar::btRegistrarVendedores_Click);
			// 
			// btRegistrarAdministradores
			// 
			this->btRegistrarAdministradores->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btRegistrarAdministradores->Location = System::Drawing::Point(191, 164);
			this->btRegistrarAdministradores->Name = L"btRegistrarAdministradores";
			this->btRegistrarAdministradores->Size = System::Drawing::Size(137, 34);
			this->btRegistrarAdministradores->TabIndex = 13;
			this->btRegistrarAdministradores->Text = L"Registrar administradores";
			this->btRegistrarAdministradores->UseVisualStyleBackColor = true;
			this->btRegistrarAdministradores->Click += gcnew System::EventHandler(this, &MenuInsertar::btRegistrarAdministradores_Click);
			// 
			// btRegistrarClientes
			// 
			this->btRegistrarClientes->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btRegistrarClientes->Location = System::Drawing::Point(191, 97);
			this->btRegistrarClientes->Name = L"btRegistrarClientes";
			this->btRegistrarClientes->Size = System::Drawing::Size(137, 34);
			this->btRegistrarClientes->TabIndex = 12;
			this->btRegistrarClientes->Text = L"Registrar clientes";
			this->btRegistrarClientes->UseVisualStyleBackColor = true;
			this->btRegistrarClientes->Click += gcnew System::EventHandler(this, &MenuInsertar::btRegistrarClientes_Click);
			// 
			// btInsertarInventario
			// 
			this->btInsertarInventario->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btInsertarInventario->Location = System::Drawing::Point(191, 34);
			this->btInsertarInventario->Name = L"btInsertarInventario";
			this->btInsertarInventario->Size = System::Drawing::Size(137, 34);
			this->btInsertarInventario->TabIndex = 11;
			this->btInsertarInventario->Text = L"Insertar inventario";
			this->btInsertarInventario->UseVisualStyleBackColor = true;
			this->btInsertarInventario->Click += gcnew System::EventHandler(this, &MenuInsertar::btInsertarInventario_Click);
			// 
			// btMarcaNueva
			// 
			this->btMarcaNueva->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btMarcaNueva->Location = System::Drawing::Point(12, 164);
			this->btMarcaNueva->Name = L"btMarcaNueva";
			this->btMarcaNueva->Size = System::Drawing::Size(137, 34);
			this->btMarcaNueva->TabIndex = 10;
			this->btMarcaNueva->Text = L"Marca nueva";
			this->btMarcaNueva->UseVisualStyleBackColor = true;
			this->btMarcaNueva->Click += gcnew System::EventHandler(this, &MenuInsertar::btMarcaNueva_Click);
			// 
			// btProductoNuevo
			// 
			this->btProductoNuevo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btProductoNuevo->Location = System::Drawing::Point(12, 97);
			this->btProductoNuevo->Name = L"btProductoNuevo";
			this->btProductoNuevo->Size = System::Drawing::Size(137, 34);
			this->btProductoNuevo->TabIndex = 9;
			this->btProductoNuevo->Text = L"Producto Nuevo";
			this->btProductoNuevo->UseVisualStyleBackColor = true;
			this->btProductoNuevo->Click += gcnew System::EventHandler(this, &MenuInsertar::btProductoNuevo_Click);
			// 
			// btInsertarPasillo
			// 
			this->btInsertarPasillo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btInsertarPasillo->Location = System::Drawing::Point(12, 34);
			this->btInsertarPasillo->Name = L"btInsertarPasillo";
			this->btInsertarPasillo->Size = System::Drawing::Size(137, 34);
			this->btInsertarPasillo->TabIndex = 8;
			this->btInsertarPasillo->Text = L"Insertar pasillo";
			this->btInsertarPasillo->UseVisualStyleBackColor = true;
			this->btInsertarPasillo->Click += gcnew System::EventHandler(this, &MenuInsertar::btInsertarPasillo_Click);
			// 
			// MenuInsertar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(340, 317);
			this->Controls->Add(this->btVolver);
			this->Controls->Add(this->btRegistrarVendedores);
			this->Controls->Add(this->btRegistrarAdministradores);
			this->Controls->Add(this->btRegistrarClientes);
			this->Controls->Add(this->btInsertarInventario);
			this->Controls->Add(this->btMarcaNueva);
			this->Controls->Add(this->btProductoNuevo);
			this->Controls->Add(this->btInsertarPasillo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MenuInsertar";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Insertar";
			this->Load += gcnew System::EventHandler(this, &MenuInsertar::MenuInsertar_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MenuInsertar_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void btVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btInsertarPasillo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btInsertarInventario_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btProductoNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btRegistrarClientes_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btMarcaNueva_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btRegistrarAdministradores_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btRegistrarVendedores_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
