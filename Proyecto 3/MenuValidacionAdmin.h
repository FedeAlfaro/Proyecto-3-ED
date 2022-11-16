#pragma once
#include "MenuAdmin.h"

namespace Proyecto3Pruebita {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	//ArbolC* AAdmin;

	
	
	public ref class MenuValidacionAdmin : public System::Windows::Forms::Form
	{

	public:

		MenuValidacionAdmin(void) //
		{

			//AAdmin = pAAdmin;
			InitializeComponent();
		
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuValidacionAdmin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btIngresar;
	protected:

	private: System::Windows::Forms::TextBox^ textBoxIdentificacion;
	private: System::Windows::Forms::Label^ lbCliente;


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
			this->lbCliente = (gcnew System::Windows::Forms::Label());
			this->btVolver = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btIngresar
			// 
			this->btIngresar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btIngresar->Location = System::Drawing::Point(238, 147);
			this->btIngresar->Name = L"btIngresar";
			this->btIngresar->Size = System::Drawing::Size(54, 23);
			this->btIngresar->TabIndex = 15;
			this->btIngresar->Text = L"Ingresar";
			this->btIngresar->UseVisualStyleBackColor = true;
			this->btIngresar->Click += gcnew System::EventHandler(this, &MenuValidacionAdmin::btIngresar_Click);
			// 
			// textBoxIdentificacion
			// 
			this->textBoxIdentificacion->Location = System::Drawing::Point(40, 150);
			this->textBoxIdentificacion->Name = L"textBoxIdentificacion";
			this->textBoxIdentificacion->Size = System::Drawing::Size(192, 20);
			this->textBoxIdentificacion->TabIndex = 13;
			// 
			// lbCliente
			// 
			this->lbCliente->AutoSize = true;
			this->lbCliente->Location = System::Drawing::Point(26, 64);
			this->lbCliente->Name = L"lbCliente";
			this->lbCliente->Size = System::Drawing::Size(299, 13);
			this->lbCliente->TabIndex = 12;
			this->lbCliente->Text = L"Por favor ingrese su número de identificación de administrador";
			// 
			// btVolver
			// 
			this->btVolver->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btVolver->Location = System::Drawing::Point(14, 282);
			this->btVolver->Name = L"btVolver";
			this->btVolver->Size = System::Drawing::Size(75, 23);
			this->btVolver->TabIndex = 11;
			this->btVolver->Text = L"Volver";
			this->btVolver->UseVisualStyleBackColor = true;
			this->btVolver->Click += gcnew System::EventHandler(this, &MenuValidacionAdmin::btVolver_Click);
			// 
			// MenuValidacionAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(340, 317);
			this->Controls->Add(this->btIngresar);
			this->Controls->Add(this->textBoxIdentificacion);
			this->Controls->Add(this->lbCliente);
			this->Controls->Add(this->btVolver);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MenuValidacionAdmin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu Validacion Administrador";
			this->Load += gcnew System::EventHandler(this, &MenuValidacionAdmin::MenuValidacionAdmin_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MenuValidacionAdmin_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void btIngresar_Click(System::Object^ sender, System::EventArgs^ e) {
		/*
		bool encontrado = false;
		int pCodAdministrador = 0;
		encontrado = AAdmin.BuscarCedula(AAdmin.raiz, pCodAdministrador);
		*/
		if (this->textBoxIdentificacion->Text == "123456") {//
			Proyecto3Pruebita::MenuAdmin^ menuAdmin = gcnew Proyecto3Pruebita::MenuAdmin();
			this->Visible = false;
			menuAdmin->ShowDialog();
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
