#pragma once
#include "MenuMantenimiento.h"
#include "MenuReportes.h"
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
	public ref class MenuAdmin : public System::Windows::Forms::Form
	{
	public:
		MenuAdmin(void)
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
		~MenuAdmin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btVolver;
	protected:
	private: System::Windows::Forms::Button^ btReportes;
	private: System::Windows::Forms::Button^ btVerificarInventario;
	private: System::Windows::Forms::Button^ btRevisarGondolas;
	private: System::Windows::Forms::Button^ btFacturar;
	private: System::Windows::Forms::Button^ btMantenimiento;

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
			this->btReportes = (gcnew System::Windows::Forms::Button());
			this->btVerificarInventario = (gcnew System::Windows::Forms::Button());
			this->btRevisarGondolas = (gcnew System::Windows::Forms::Button());
			this->btFacturar = (gcnew System::Windows::Forms::Button());
			this->btMantenimiento = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btVolver
			// 
			this->btVolver->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btVolver->Location = System::Drawing::Point(12, 282);
			this->btVolver->Name = L"btVolver";
			this->btVolver->Size = System::Drawing::Size(75, 23);
			this->btVolver->TabIndex = 11;
			this->btVolver->Text = L"Volver";
			this->btVolver->UseVisualStyleBackColor = true;
			this->btVolver->Click += gcnew System::EventHandler(this, &MenuAdmin::btVolver_Click);
			// 
			// btReportes
			// 
			this->btReportes->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btReportes->Location = System::Drawing::Point(103, 244);
			this->btReportes->Name = L"btReportes";
			this->btReportes->Size = System::Drawing::Size(137, 34);
			this->btReportes->TabIndex = 10;
			this->btReportes->Text = L"Reportes";
			this->btReportes->UseVisualStyleBackColor = true;
			this->btReportes->Click += gcnew System::EventHandler(this, &MenuAdmin::btReportes_Click);
			// 
			// btVerificarInventario
			// 
			this->btVerificarInventario->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btVerificarInventario->Location = System::Drawing::Point(103, 189);
			this->btVerificarInventario->Name = L"btVerificarInventario";
			this->btVerificarInventario->Size = System::Drawing::Size(137, 34);
			this->btVerificarInventario->TabIndex = 9;
			this->btVerificarInventario->Text = L"Verificar Inventario";
			this->btVerificarInventario->UseVisualStyleBackColor = true;
			this->btVerificarInventario->Click += gcnew System::EventHandler(this, &MenuAdmin::btVerificarInventario_Click);
			// 
			// btRevisarGondolas
			// 
			this->btRevisarGondolas->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btRevisarGondolas->Location = System::Drawing::Point(103, 134);
			this->btRevisarGondolas->Name = L"btRevisarGondolas";
			this->btRevisarGondolas->Size = System::Drawing::Size(137, 34);
			this->btRevisarGondolas->TabIndex = 8;
			this->btRevisarGondolas->Text = L"Revisar góndolas";
			this->btRevisarGondolas->UseVisualStyleBackColor = true;
			this->btRevisarGondolas->Click += gcnew System::EventHandler(this, &MenuAdmin::btRevisarGondolas_Click);
			// 
			// btFacturar
			// 
			this->btFacturar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btFacturar->Location = System::Drawing::Point(103, 83);
			this->btFacturar->Name = L"btFacturar";
			this->btFacturar->Size = System::Drawing::Size(137, 34);
			this->btFacturar->TabIndex = 7;
			this->btFacturar->Text = L"Facturar";
			this->btFacturar->UseVisualStyleBackColor = true;
			this->btFacturar->Click += gcnew System::EventHandler(this, &MenuAdmin::btFacturar_Click);
			// 
			// btMantenimiento
			// 
			this->btMantenimiento->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btMantenimiento->Location = System::Drawing::Point(103, 33);
			this->btMantenimiento->Name = L"btMantenimiento";
			this->btMantenimiento->Size = System::Drawing::Size(137, 34);
			this->btMantenimiento->TabIndex = 6;
			this->btMantenimiento->Text = L"Mantenimiento de la base de datos";
			this->btMantenimiento->UseVisualStyleBackColor = true;
			this->btMantenimiento->Click += gcnew System::EventHandler(this, &MenuAdmin::btMantenimiento_Click);
			// 
			// MenuAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(340, 317);
			this->Controls->Add(this->btVolver);
			this->Controls->Add(this->btReportes);
			this->Controls->Add(this->btVerificarInventario);
			this->Controls->Add(this->btRevisarGondolas);
			this->Controls->Add(this->btFacturar);
			this->Controls->Add(this->btMantenimiento);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MenuAdmin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Menu Administrador";
			this->Load += gcnew System::EventHandler(this, &MenuAdmin::MenuAdmin_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MenuAdmin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btMantenimiento_Click(System::Object^ sender, System::EventArgs^ e) {
		Proyecto3Pruebita::MenuMantenimiento^ menuMantenimiento = gcnew Proyecto3Pruebita::MenuMantenimiento();
		this->Visible = false;
		menuMantenimiento->ShowDialog();
		this->Visible = true;
	}
	private: System::Void btFacturar_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btRevisarGondolas_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btVerificarInventario_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btReportes_Click(System::Object^ sender, System::EventArgs^ e) {
		Proyecto3Pruebita::MenuReportes^ menuReportes = gcnew Proyecto3Pruebita::MenuReportes();
		this->Visible = false;
		menuReportes->ShowDialog();
		this->Visible = true;
	}
};
}
