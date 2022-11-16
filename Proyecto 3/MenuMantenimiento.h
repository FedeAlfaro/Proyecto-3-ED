#pragma once
#include "MenuInsertar.h"
#include "MenuEliminar.h"
#include "MenuModificar.h"
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
	public ref class MenuMantenimiento : public System::Windows::Forms::Form
	{
	public:
		MenuMantenimiento(void)
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
		~MenuMantenimiento()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btVolver;
	protected:
	private: System::Windows::Forms::Button^ btModificarDescuento;
	private: System::Windows::Forms::Button^ btConsultarDescuento;
	private: System::Windows::Forms::Button^ btConsultarPrecio;
	private: System::Windows::Forms::Button^ btModificarProducto;
	private: System::Windows::Forms::Button^ btEliminarProducto;
	private: System::Windows::Forms::Button^ btInsertar;

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
			this->btModificarDescuento = (gcnew System::Windows::Forms::Button());
			this->btConsultarDescuento = (gcnew System::Windows::Forms::Button());
			this->btConsultarPrecio = (gcnew System::Windows::Forms::Button());
			this->btModificarProducto = (gcnew System::Windows::Forms::Button());
			this->btEliminarProducto = (gcnew System::Windows::Forms::Button());
			this->btInsertar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btVolver
			// 
			this->btVolver->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btVolver->Location = System::Drawing::Point(12, 282);
			this->btVolver->Name = L"btVolver";
			this->btVolver->Size = System::Drawing::Size(53, 23);
			this->btVolver->TabIndex = 13;
			this->btVolver->Text = L"Volver";
			this->btVolver->UseVisualStyleBackColor = true;
			this->btVolver->Click += gcnew System::EventHandler(this, &MenuMantenimiento::btVolver_Click);
			// 
			// btModificarDescuento
			// 
			this->btModificarDescuento->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btModificarDescuento->Location = System::Drawing::Point(108, 271);
			this->btModificarDescuento->Name = L"btModificarDescuento";
			this->btModificarDescuento->Size = System::Drawing::Size(137, 34);
			this->btModificarDescuento->TabIndex = 12;
			this->btModificarDescuento->Text = L"Modificar el descuento";
			this->btModificarDescuento->UseVisualStyleBackColor = true;
			this->btModificarDescuento->Click += gcnew System::EventHandler(this, &MenuMantenimiento::btModificarDescuento_Click);
			// 
			// btConsultarDescuento
			// 
			this->btConsultarDescuento->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btConsultarDescuento->Location = System::Drawing::Point(108, 219);
			this->btConsultarDescuento->Name = L"btConsultarDescuento";
			this->btConsultarDescuento->Size = System::Drawing::Size(137, 34);
			this->btConsultarDescuento->TabIndex = 11;
			this->btConsultarDescuento->Text = L"Consultar descuento";
			this->btConsultarDescuento->UseVisualStyleBackColor = true;
			this->btConsultarDescuento->Click += gcnew System::EventHandler(this, &MenuMantenimiento::btConsultarDescuento_Click);
			// 
			// btConsultarPrecio
			// 
			this->btConsultarPrecio->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btConsultarPrecio->Location = System::Drawing::Point(108, 166);
			this->btConsultarPrecio->Name = L"btConsultarPrecio";
			this->btConsultarPrecio->Size = System::Drawing::Size(137, 34);
			this->btConsultarPrecio->TabIndex = 10;
			this->btConsultarPrecio->Text = L"Consultar precio";
			this->btConsultarPrecio->UseVisualStyleBackColor = true;
			this->btConsultarPrecio->Click += gcnew System::EventHandler(this, &MenuMantenimiento::btConsultarPrecio_Click);
			// 
			// btModificarProducto
			// 
			this->btModificarProducto->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btModificarProducto->Location = System::Drawing::Point(108, 116);
			this->btModificarProducto->Name = L"btModificarProducto";
			this->btModificarProducto->Size = System::Drawing::Size(137, 34);
			this->btModificarProducto->TabIndex = 9;
			this->btModificarProducto->Text = L"Modificar";
			this->btModificarProducto->UseVisualStyleBackColor = true;
			this->btModificarProducto->Click += gcnew System::EventHandler(this, &MenuMantenimiento::btModificarProducto_Click);
			// 
			// btEliminarProducto
			// 
			this->btEliminarProducto->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btEliminarProducto->Location = System::Drawing::Point(108, 63);
			this->btEliminarProducto->Name = L"btEliminarProducto";
			this->btEliminarProducto->Size = System::Drawing::Size(137, 34);
			this->btEliminarProducto->TabIndex = 8;
			this->btEliminarProducto->Text = L"Eliminar";
			this->btEliminarProducto->UseVisualStyleBackColor = true;
			this->btEliminarProducto->Click += gcnew System::EventHandler(this, &MenuMantenimiento::btEliminarProducto_Click);
			// 
			// btInsertar
			// 
			this->btInsertar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btInsertar->Location = System::Drawing::Point(108, 12);
			this->btInsertar->Name = L"btInsertar";
			this->btInsertar->Size = System::Drawing::Size(137, 34);
			this->btInsertar->TabIndex = 7;
			this->btInsertar->Text = L"Insertar";
			this->btInsertar->UseVisualStyleBackColor = true;
			this->btInsertar->Click += gcnew System::EventHandler(this, &MenuMantenimiento::btInsertar_Click);
			// 
			// MenuMantenimiento
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(340, 317);
			this->Controls->Add(this->btVolver);
			this->Controls->Add(this->btModificarDescuento);
			this->Controls->Add(this->btConsultarDescuento);
			this->Controls->Add(this->btConsultarPrecio);
			this->Controls->Add(this->btModificarProducto);
			this->Controls->Add(this->btEliminarProducto);
			this->Controls->Add(this->btInsertar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MenuMantenimiento";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu Mantenimiento";
			this->Load += gcnew System::EventHandler(this, &MenuMantenimiento::MenuMantenimiento_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MenuMantenimiento_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btInsertar_Click(System::Object^ sender, System::EventArgs^ e) {
		Proyecto3Pruebita::MenuInsertar^ menuInsertar = gcnew Proyecto3Pruebita::MenuInsertar();
		this->Visible = false;
		menuInsertar->ShowDialog();
		this->Visible = true;
	}
	private: System::Void btEliminarProducto_Click(System::Object^ sender, System::EventArgs^ e) {
		Proyecto3Pruebita::MenuEliminar^ menuEliminar = gcnew Proyecto3Pruebita::MenuEliminar();
		this->Visible = false;
		menuEliminar->ShowDialog();
		this->Visible = true;
	}
	private: System::Void btModificarProducto_Click(System::Object^ sender, System::EventArgs^ e) {
		Proyecto3Pruebita::MenuModificar^ menuModificar = gcnew Proyecto3Pruebita::MenuModificar();
		this->Visible = false;
		menuModificar->ShowDialog();
		this->Visible = true;
	}
	private: System::Void btConsultarPrecio_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btConsultarDescuento_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btModificarDescuento_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
