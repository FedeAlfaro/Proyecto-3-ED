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
	public ref class MenuClientes : public System::Windows::Forms::Form
	{
	public:
		MenuClientes(void)
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
		~MenuClientes()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btVolver;
	protected:
	public: System::Windows::Forms::Button^ btComprar;
	private: System::Windows::Forms::Button^ btConsultarProductos;
	public: System::Windows::Forms::Button^ btConsultarDescuento;
	private: System::Windows::Forms::Button^ btConsultarPrecio;

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
			this->btComprar = (gcnew System::Windows::Forms::Button());
			this->btConsultarProductos = (gcnew System::Windows::Forms::Button());
			this->btConsultarDescuento = (gcnew System::Windows::Forms::Button());
			this->btConsultarPrecio = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btVolver
			// 
			this->btVolver->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btVolver->Location = System::Drawing::Point(12, 282);
			this->btVolver->Name = L"btVolver";
			this->btVolver->Size = System::Drawing::Size(75, 23);
			this->btVolver->TabIndex = 9;
			this->btVolver->Text = L"Volver";
			this->btVolver->UseVisualStyleBackColor = true;
			this->btVolver->Click += gcnew System::EventHandler(this, &MenuClientes::btVolver_Click);
			// 
			// btComprar
			// 
			this->btComprar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btComprar->Location = System::Drawing::Point(103, 219);
			this->btComprar->Name = L"btComprar";
			this->btComprar->Size = System::Drawing::Size(137, 34);
			this->btComprar->TabIndex = 8;
			this->btComprar->Text = L"Comprar";
			this->btComprar->UseVisualStyleBackColor = true;
			this->btComprar->Click += gcnew System::EventHandler(this, &MenuClientes::btComprar_Click);
			// 
			// btConsultarProductos
			// 
			this->btConsultarProductos->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btConsultarProductos->Location = System::Drawing::Point(103, 164);
			this->btConsultarProductos->Name = L"btConsultarProductos";
			this->btConsultarProductos->Size = System::Drawing::Size(137, 34);
			this->btConsultarProductos->TabIndex = 7;
			this->btConsultarProductos->Text = L"Consultar productos";
			this->btConsultarProductos->UseVisualStyleBackColor = true;
			this->btConsultarProductos->Click += gcnew System::EventHandler(this, &MenuClientes::btConsultarProductos_Click);
			// 
			// btConsultarDescuento
			// 
			this->btConsultarDescuento->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btConsultarDescuento->Location = System::Drawing::Point(103, 107);
			this->btConsultarDescuento->Name = L"btConsultarDescuento";
			this->btConsultarDescuento->Size = System::Drawing::Size(137, 34);
			this->btConsultarDescuento->TabIndex = 6;
			this->btConsultarDescuento->Text = L"Consultar descuento";
			this->btConsultarDescuento->UseVisualStyleBackColor = true;
			this->btConsultarDescuento->Click += gcnew System::EventHandler(this, &MenuClientes::btConsultarDescuento_Click);
			// 
			// btConsultarPrecio
			// 
			this->btConsultarPrecio->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btConsultarPrecio->Location = System::Drawing::Point(103, 52);
			this->btConsultarPrecio->Name = L"btConsultarPrecio";
			this->btConsultarPrecio->Size = System::Drawing::Size(137, 34);
			this->btConsultarPrecio->TabIndex = 5;
			this->btConsultarPrecio->Text = L"Consultar precio";
			this->btConsultarPrecio->UseVisualStyleBackColor = true;
			this->btConsultarPrecio->Click += gcnew System::EventHandler(this, &MenuClientes::btConsultarPrecio_Click);
			// 
			// MenuClientes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(340, 317);
			this->Controls->Add(this->btVolver);
			this->Controls->Add(this->btComprar);
			this->Controls->Add(this->btConsultarProductos);
			this->Controls->Add(this->btConsultarDescuento);
			this->Controls->Add(this->btConsultarPrecio);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MenuClientes";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu Clientes";
			this->Load += gcnew System::EventHandler(this, &MenuClientes::MenuClientes_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MenuClientes_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btConsultarPrecio_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void btConsultarDescuento_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void btConsultarProductos_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void btComprar_Click(System::Object^ sender, System::EventArgs^ e) {

	}
};
}
