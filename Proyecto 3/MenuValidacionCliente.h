#pragma once
#include "MenuClientes.h"
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
	public ref class MenuValidacionCliente : public System::Windows::Forms::Form
	{
	public:
		MenuValidacionCliente(void)
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
		~MenuValidacionCliente()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbCliente;
	protected:

	protected:



	private: System::Windows::Forms::Button^ btVolver;
	private: System::Windows::Forms::TextBox^ textBoxIdentificacion;
	private: System::Windows::Forms::Button^ btNoRegistrado;

	private: System::Windows::Forms::Button^ btIngresar;


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
			this->lbCliente = (gcnew System::Windows::Forms::Label());
			this->btVolver = (gcnew System::Windows::Forms::Button());
			this->textBoxIdentificacion = (gcnew System::Windows::Forms::TextBox());
			this->btNoRegistrado = (gcnew System::Windows::Forms::Button());
			this->btIngresar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbCliente
			// 
			this->lbCliente->AutoSize = true;
			this->lbCliente->Location = System::Drawing::Point(24, 64);
			this->lbCliente->Name = L"lbCliente";
			this->lbCliente->Size = System::Drawing::Size(302, 13);
			this->lbCliente->TabIndex = 7;
			this->lbCliente->Text = L"Si está registrado por favor ingrese su número de identificación";
			this->lbCliente->Click += gcnew System::EventHandler(this, &MenuValidacionCliente::lbCliente_Click);
			// 
			// btVolver
			// 
			this->btVolver->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btVolver->Location = System::Drawing::Point(12, 282);
			this->btVolver->Name = L"btVolver";
			this->btVolver->Size = System::Drawing::Size(75, 23);
			this->btVolver->TabIndex = 6;
			this->btVolver->Text = L"Volver";
			this->btVolver->UseVisualStyleBackColor = true;
			this->btVolver->Click += gcnew System::EventHandler(this, &MenuValidacionCliente::btVolver_Click);
			// 
			// textBoxIdentificacion
			// 
			this->textBoxIdentificacion->Location = System::Drawing::Point(38, 150);
			this->textBoxIdentificacion->Name = L"textBoxIdentificacion";
			this->textBoxIdentificacion->Size = System::Drawing::Size(192, 20);
			this->textBoxIdentificacion->TabIndex = 8;
			this->textBoxIdentificacion->TextChanged += gcnew System::EventHandler(this, &MenuValidacionCliente::textBoxIdentificacion_TextChanged);
			// 
			// btNoRegistrado
			// 
			this->btNoRegistrado->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btNoRegistrado->Location = System::Drawing::Point(214, 282);
			this->btNoRegistrado->Name = L"btNoRegistrado";
			this->btNoRegistrado->Size = System::Drawing::Size(112, 23);
			this->btNoRegistrado->TabIndex = 9;
			this->btNoRegistrado->Text = L"No estoy registrado";
			this->btNoRegistrado->UseVisualStyleBackColor = true;
			this->btNoRegistrado->Click += gcnew System::EventHandler(this, &MenuValidacionCliente::btNoRegistrado_Click);
			// 
			// btIngresar
			// 
			this->btIngresar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btIngresar->Location = System::Drawing::Point(236, 147);
			this->btIngresar->Name = L"btIngresar";
			this->btIngresar->Size = System::Drawing::Size(54, 23);
			this->btIngresar->TabIndex = 10;
			this->btIngresar->Text = L"Ingresar";
			this->btIngresar->UseVisualStyleBackColor = true;
			this->btIngresar->Click += gcnew System::EventHandler(this, &MenuValidacionCliente::btIngresar_Click);
			// 
			// MenuValidacionCliente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(340, 317);
			this->Controls->Add(this->btIngresar);
			this->Controls->Add(this->btNoRegistrado);
			this->Controls->Add(this->textBoxIdentificacion);
			this->Controls->Add(this->lbCliente);
			this->Controls->Add(this->btVolver);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MenuValidacionCliente";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu Clientes";
			this->Load += gcnew System::EventHandler(this, &MenuValidacionCliente::MenuClientes_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MenuClientes_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void btIngresar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->textBoxIdentificacion->Text == "118640057") {
			Proyecto3Pruebita::MenuClientes^ menuClientes = gcnew Proyecto3Pruebita::MenuClientes();
			this->Visible = false;
			menuClientes->ShowDialog();
			this->Visible = true;
			this->textBoxIdentificacion->Text = "";
		}
		else {
			MessageBox::Show("Cliente no encontrado, por favor ingrese una identidficación válida", "Cliente no encontrado!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	}
	private: System::Void btVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btNoRegistrado_Click(System::Object^ sender, System::EventArgs^ e) {
		Proyecto3Pruebita::MenuClientes^ menuClientes = gcnew Proyecto3Pruebita::MenuClientes();
		menuClientes->btComprar->Enabled = false;
		menuClientes->btConsultarDescuento->Enabled = false;
		this->Visible = false;
		menuClientes->ShowDialog();
		this->Visible = true;
	}
private: System::Void textBoxIdentificacion_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lbCliente_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
