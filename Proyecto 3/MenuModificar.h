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
	public ref class MenuModificar : public System::Windows::Forms::Form
	{
	public:
		MenuModificar(void)
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
		~MenuModificar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btVolver;
	protected:
	private: System::Windows::Forms::Button^ btEliminarVendedores;
	private: System::Windows::Forms::Button^ btEliminarAdministradores;
	private: System::Windows::Forms::Button^ btEliminarClientes;
	private: System::Windows::Forms::Button^ btEliminarInventario;
	private: System::Windows::Forms::Button^ btEliminarMarca;
	private: System::Windows::Forms::Button^ btEliminarProducto;
	private: System::Windows::Forms::Button^ btEliminarPasillo;

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
			this->btEliminarVendedores = (gcnew System::Windows::Forms::Button());
			this->btEliminarAdministradores = (gcnew System::Windows::Forms::Button());
			this->btEliminarClientes = (gcnew System::Windows::Forms::Button());
			this->btEliminarInventario = (gcnew System::Windows::Forms::Button());
			this->btEliminarMarca = (gcnew System::Windows::Forms::Button());
			this->btEliminarProducto = (gcnew System::Windows::Forms::Button());
			this->btEliminarPasillo = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btVolver
			// 
			this->btVolver->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btVolver->Location = System::Drawing::Point(12, 270);
			this->btVolver->Name = L"btVolver";
			this->btVolver->Size = System::Drawing::Size(75, 23);
			this->btVolver->TabIndex = 31;
			this->btVolver->Text = L"Volver";
			this->btVolver->UseVisualStyleBackColor = true;
			this->btVolver->Click += gcnew System::EventHandler(this, &MenuModificar::btVolver_Click);
			// 
			// btEliminarVendedores
			// 
			this->btEliminarVendedores->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btEliminarVendedores->Location = System::Drawing::Point(101, 212);
			this->btEliminarVendedores->Name = L"btEliminarVendedores";
			this->btEliminarVendedores->Size = System::Drawing::Size(137, 34);
			this->btEliminarVendedores->TabIndex = 30;
			this->btEliminarVendedores->Text = L"Modificar vendedores";
			this->btEliminarVendedores->UseVisualStyleBackColor = true;
			this->btEliminarVendedores->Click += gcnew System::EventHandler(this, &MenuModificar::btEliminarVendedores_Click);
			// 
			// btEliminarAdministradores
			// 
			this->btEliminarAdministradores->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btEliminarAdministradores->Location = System::Drawing::Point(191, 148);
			this->btEliminarAdministradores->Name = L"btEliminarAdministradores";
			this->btEliminarAdministradores->Size = System::Drawing::Size(137, 34);
			this->btEliminarAdministradores->TabIndex = 29;
			this->btEliminarAdministradores->Text = L"Modificar administradores";
			this->btEliminarAdministradores->UseVisualStyleBackColor = true;
			this->btEliminarAdministradores->Click += gcnew System::EventHandler(this, &MenuModificar::btEliminarAdministradores_Click);
			// 
			// btEliminarClientes
			// 
			this->btEliminarClientes->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btEliminarClientes->Location = System::Drawing::Point(191, 82);
			this->btEliminarClientes->Name = L"btEliminarClientes";
			this->btEliminarClientes->Size = System::Drawing::Size(137, 34);
			this->btEliminarClientes->TabIndex = 28;
			this->btEliminarClientes->Text = L"Modificar clientes";
			this->btEliminarClientes->UseVisualStyleBackColor = true;
			this->btEliminarClientes->Click += gcnew System::EventHandler(this, &MenuModificar::btEliminarClientes_Click);
			// 
			// btEliminarInventario
			// 
			this->btEliminarInventario->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btEliminarInventario->Location = System::Drawing::Point(191, 23);
			this->btEliminarInventario->Name = L"btEliminarInventario";
			this->btEliminarInventario->Size = System::Drawing::Size(137, 34);
			this->btEliminarInventario->TabIndex = 27;
			this->btEliminarInventario->Text = L"Modificar inventario";
			this->btEliminarInventario->UseVisualStyleBackColor = true;
			this->btEliminarInventario->Click += gcnew System::EventHandler(this, &MenuModificar::btEliminarInventario_Click);
			// 
			// btEliminarMarca
			// 
			this->btEliminarMarca->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btEliminarMarca->Location = System::Drawing::Point(12, 148);
			this->btEliminarMarca->Name = L"btEliminarMarca";
			this->btEliminarMarca->Size = System::Drawing::Size(137, 34);
			this->btEliminarMarca->TabIndex = 26;
			this->btEliminarMarca->Text = L"Modificar marca";
			this->btEliminarMarca->UseVisualStyleBackColor = true;
			this->btEliminarMarca->Click += gcnew System::EventHandler(this, &MenuModificar::btEliminarMarca_Click);
			// 
			// btEliminarProducto
			// 
			this->btEliminarProducto->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btEliminarProducto->Location = System::Drawing::Point(12, 82);
			this->btEliminarProducto->Name = L"btEliminarProducto";
			this->btEliminarProducto->Size = System::Drawing::Size(137, 34);
			this->btEliminarProducto->TabIndex = 25;
			this->btEliminarProducto->Text = L"Modificar producto";
			this->btEliminarProducto->UseVisualStyleBackColor = true;
			this->btEliminarProducto->Click += gcnew System::EventHandler(this, &MenuModificar::btEliminarProducto_Click);
			// 
			// btEliminarPasillo
			// 
			this->btEliminarPasillo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btEliminarPasillo->Location = System::Drawing::Point(12, 23);
			this->btEliminarPasillo->Name = L"btEliminarPasillo";
			this->btEliminarPasillo->Size = System::Drawing::Size(137, 34);
			this->btEliminarPasillo->TabIndex = 24;
			this->btEliminarPasillo->Text = L"Modificar pasillo";
			this->btEliminarPasillo->UseVisualStyleBackColor = true;
			this->btEliminarPasillo->Click += gcnew System::EventHandler(this, &MenuModificar::btEliminarPasillo_Click);
			// 
			// MenuModificar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(340, 317);
			this->Controls->Add(this->btVolver);
			this->Controls->Add(this->btEliminarVendedores);
			this->Controls->Add(this->btEliminarAdministradores);
			this->Controls->Add(this->btEliminarClientes);
			this->Controls->Add(this->btEliminarInventario);
			this->Controls->Add(this->btEliminarMarca);
			this->Controls->Add(this->btEliminarProducto);
			this->Controls->Add(this->btEliminarPasillo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MenuModificar";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Modificar";
			this->Load += gcnew System::EventHandler(this, &MenuModificar::MenuModificar_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void MenuModificar_Load(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void btEliminarPasillo_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btEliminarInventario_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btEliminarProducto_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btEliminarClientes_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btEliminarMarca_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btEliminarAdministradores_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btEliminarVendedores_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
