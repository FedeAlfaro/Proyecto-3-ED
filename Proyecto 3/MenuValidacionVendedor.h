#pragma once
#include "MenuVendedor.h"
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
	public ref class MenuValidacionVendedor : public System::Windows::Forms::Form
	{
	public:
		MenuValidacionVendedor(void)
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
		~MenuValidacionVendedor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btIngresar;
	protected:
	private: System::Windows::Forms::TextBox^ textBoxIdentificacion;
	private: System::Windows::Forms::Label^ lbVendedor;

	private: System::Windows::Forms::Button^ btVolver;

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
			this->btIngresar = (gcnew System::Windows::Forms::Button());
			this->textBoxIdentificacion = (gcnew System::Windows::Forms::TextBox());
			this->lbVendedor = (gcnew System::Windows::Forms::Label());
			this->btVolver = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btIngresar
			// 
			this->btIngresar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btIngresar->Location = System::Drawing::Point(236, 147);
			this->btIngresar->Name = L"btIngresar";
			this->btIngresar->Size = System::Drawing::Size(54, 23);
			this->btIngresar->TabIndex = 19;
			this->btIngresar->Text = L"Ingresar";
			this->btIngresar->UseVisualStyleBackColor = true;
			this->btIngresar->Click += gcnew System::EventHandler(this, &MenuValidacionVendedor::btIngresar_Click);
			// 
			// textBoxIdentificacion
			// 
			this->textBoxIdentificacion->Location = System::Drawing::Point(38, 150);
			this->textBoxIdentificacion->Name = L"textBoxIdentificacion";
			this->textBoxIdentificacion->Size = System::Drawing::Size(192, 20);
			this->textBoxIdentificacion->TabIndex = 18;
			// 
			// lbVendedor
			// 
			this->lbVendedor->AutoSize = true;
			this->lbVendedor->Location = System::Drawing::Point(24, 64);
			this->lbVendedor->Name = L"lbVendedor";
			this->lbVendedor->Size = System::Drawing::Size(282, 13);
			this->lbVendedor->TabIndex = 17;
			this->lbVendedor->Text = L"Por favor ingrese su número de identificación de vendedor";
			// 
			// btVolver
			// 
			this->btVolver->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btVolver->Location = System::Drawing::Point(12, 282);
			this->btVolver->Name = L"btVolver";
			this->btVolver->Size = System::Drawing::Size(75, 23);
			this->btVolver->TabIndex = 16;
			this->btVolver->Text = L"Volver";
			this->btVolver->UseVisualStyleBackColor = true;
			this->btVolver->Click += gcnew System::EventHandler(this, &MenuValidacionVendedor::btVolver_Click);
			// 
			// MenuValidacionVendedor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(340, 317);
			this->Controls->Add(this->btIngresar);
			this->Controls->Add(this->textBoxIdentificacion);
			this->Controls->Add(this->lbVendedor);
			this->Controls->Add(this->btVolver);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MenuValidacionVendedor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu Validacion Vendedor";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btIngresar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->textBoxIdentificacion->Text == "123456") {
			Proyecto3Pruebita::MenuVendedor^ menuVendedor = gcnew Proyecto3Pruebita::MenuVendedor();
			this->Visible = false;
			menuVendedor->ShowDialog();
			this->Visible = true;
			this->textBoxIdentificacion->Text = "";
		}
		else {
			MessageBox::Show("Administrador no encontrado, por favor ingrese una identidficación válida", "Administrador no encontrado!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	}
	private: System::Void btVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
