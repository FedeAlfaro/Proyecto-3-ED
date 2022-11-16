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
	public ref class MenuVendedor : public System::Windows::Forms::Form
	{
	public:
		MenuVendedor(void)
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
		~MenuVendedor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btVolver;
	protected:
	private: System::Windows::Forms::Button^ btConsultarMarcasProducto;
	private: System::Windows::Forms::Button^ btConsultarProductosPasillo;
	private: System::Windows::Forms::Button^ btConsultarDescuentoCliente;
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
			this->btConsultarMarcasProducto = (gcnew System::Windows::Forms::Button());
			this->btConsultarProductosPasillo = (gcnew System::Windows::Forms::Button());
			this->btConsultarDescuentoCliente = (gcnew System::Windows::Forms::Button());
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
			this->btVolver->Click += gcnew System::EventHandler(this, &MenuVendedor::btVolver_Click);
			// 
			// btConsultarMarcasProducto
			// 
			this->btConsultarMarcasProducto->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btConsultarMarcasProducto->Location = System::Drawing::Point(102, 210);
			this->btConsultarMarcasProducto->Name = L"btConsultarMarcasProducto";
			this->btConsultarMarcasProducto->Size = System::Drawing::Size(137, 34);
			this->btConsultarMarcasProducto->TabIndex = 8;
			this->btConsultarMarcasProducto->Text = L"Consultar marcas de un producto";
			this->btConsultarMarcasProducto->UseVisualStyleBackColor = true;
			// 
			// btConsultarProductosPasillo
			// 
			this->btConsultarProductosPasillo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btConsultarProductosPasillo->Location = System::Drawing::Point(102, 150);
			this->btConsultarProductosPasillo->Name = L"btConsultarProductosPasillo";
			this->btConsultarProductosPasillo->Size = System::Drawing::Size(137, 34);
			this->btConsultarProductosPasillo->TabIndex = 7;
			this->btConsultarProductosPasillo->Text = L"Consultar productos de un pasillo";
			this->btConsultarProductosPasillo->UseVisualStyleBackColor = true;
			// 
			// btConsultarDescuentoCliente
			// 
			this->btConsultarDescuentoCliente->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btConsultarDescuentoCliente->Location = System::Drawing::Point(102, 93);
			this->btConsultarDescuentoCliente->Name = L"btConsultarDescuentoCliente";
			this->btConsultarDescuentoCliente->Size = System::Drawing::Size(137, 34);
			this->btConsultarDescuentoCliente->TabIndex = 6;
			this->btConsultarDescuentoCliente->Text = L"Consultar descuento de un cliente";
			this->btConsultarDescuentoCliente->UseVisualStyleBackColor = true;
			// 
			// btConsultarPrecio
			// 
			this->btConsultarPrecio->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btConsultarPrecio->Location = System::Drawing::Point(102, 38);
			this->btConsultarPrecio->Name = L"btConsultarPrecio";
			this->btConsultarPrecio->Size = System::Drawing::Size(137, 34);
			this->btConsultarPrecio->TabIndex = 5;
			this->btConsultarPrecio->Text = L"Consultar precio";
			this->btConsultarPrecio->UseVisualStyleBackColor = true;
			this->btConsultarPrecio->Click += gcnew System::EventHandler(this, &MenuVendedor::btConsultarPrecio_Click);
			// 
			// MenuVendedor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(340, 317);
			this->Controls->Add(this->btVolver);
			this->Controls->Add(this->btConsultarMarcasProducto);
			this->Controls->Add(this->btConsultarProductosPasillo);
			this->Controls->Add(this->btConsultarDescuentoCliente);
			this->Controls->Add(this->btConsultarPrecio);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MenuVendedor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu Vendedor";
			this->Load += gcnew System::EventHandler(this, &MenuVendedor::MenuVendedor_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void MenuVendedor_Load(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void btConsultarPrecio_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
}
