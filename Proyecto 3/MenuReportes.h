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
	public ref class MenuReportes : public System::Windows::Forms::Form
	{
	public:
		MenuReportes(void)
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
		~MenuReportes()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btVolver;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ btPasillosSupermercado;
	private: System::Windows::Forms::Button^ btProductosDeUnPasillo;
	private: System::Windows::Forms::Button^ btMarcasProducto;
	private: System::Windows::Forms::Button^ btProductoMasCargado;
	private: System::Windows::Forms::Button^ btClienteMasCompro;
	private: System::Windows::Forms::Button^ btProductosPorPasilloMasVendidos;
	private: System::Windows::Forms::Button^ btPasilloMasVisitado;
	private: System::Windows::Forms::Button^ btInventarioSupermercado;
	private: System::Windows::Forms::Button^ btClientesSupermercado;
	private: System::Windows::Forms::Button^ btFacturaMayorMonto;
	private: System::Windows::Forms::Button^ btClienteMasFacturo;
	private: System::Windows::Forms::Button^ btClienteMenosCompro;
	private: System::Windows::Forms::Button^ btMarcasMasVendidas;
	private: System::Windows::Forms::Button^ btPasilloMenosVisitado;
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
			this->btVolver = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btPasillosSupermercado = (gcnew System::Windows::Forms::Button());
			this->btProductosDeUnPasillo = (gcnew System::Windows::Forms::Button());
			this->btMarcasProducto = (gcnew System::Windows::Forms::Button());
			this->btProductoMasCargado = (gcnew System::Windows::Forms::Button());
			this->btClienteMasCompro = (gcnew System::Windows::Forms::Button());
			this->btProductosPorPasilloMasVendidos = (gcnew System::Windows::Forms::Button());
			this->btPasilloMasVisitado = (gcnew System::Windows::Forms::Button());
			this->btInventarioSupermercado = (gcnew System::Windows::Forms::Button());
			this->btClientesSupermercado = (gcnew System::Windows::Forms::Button());
			this->btFacturaMayorMonto = (gcnew System::Windows::Forms::Button());
			this->btClienteMasFacturo = (gcnew System::Windows::Forms::Button());
			this->btClienteMenosCompro = (gcnew System::Windows::Forms::Button());
			this->btMarcasMasVendidas = (gcnew System::Windows::Forms::Button());
			this->btPasilloMenosVisitado = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btVolver
			// 
			this->btVolver->Location = System::Drawing::Point(-111, 308);
			this->btVolver->Name = L"btVolver";
			this->btVolver->Size = System::Drawing::Size(75, 23);
			this->btVolver->TabIndex = 29;
			this->btVolver->Text = L"Volver";
			this->btVolver->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(12, 367);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 37;
			this->button1->Text = L"Volver";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuReportes::button1_Click);
			// 
			// btPasillosSupermercado
			// 
			this->btPasillosSupermercado->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btPasillosSupermercado->Location = System::Drawing::Point(12, 323);
			this->btPasillosSupermercado->Name = L"btPasillosSupermercado";
			this->btPasillosSupermercado->Size = System::Drawing::Size(196, 34);
			this->btPasillosSupermercado->TabIndex = 36;
			this->btPasillosSupermercado->Text = L"Pasillos del supermercado";
			this->btPasillosSupermercado->UseVisualStyleBackColor = true;
			this->btPasillosSupermercado->Click += gcnew System::EventHandler(this, &MenuReportes::btPasillosSupermercado_Click);
			// 
			// btProductosDeUnPasillo
			// 
			this->btProductosDeUnPasillo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btProductosDeUnPasillo->Location = System::Drawing::Point(12, 268);
			this->btProductosDeUnPasillo->Name = L"btProductosDeUnPasillo";
			this->btProductosDeUnPasillo->Size = System::Drawing::Size(196, 34);
			this->btProductosDeUnPasillo->TabIndex = 35;
			this->btProductosDeUnPasillo->Text = L"Productos de un pasillo";
			this->btProductosDeUnPasillo->UseVisualStyleBackColor = true;
			this->btProductosDeUnPasillo->Click += gcnew System::EventHandler(this, &MenuReportes::btProductosDeUnPasillo_Click);
			// 
			// btMarcasProducto
			// 
			this->btMarcasProducto->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btMarcasProducto->Location = System::Drawing::Point(12, 213);
			this->btMarcasProducto->Name = L"btMarcasProducto";
			this->btMarcasProducto->Size = System::Drawing::Size(196, 34);
			this->btMarcasProducto->TabIndex = 34;
			this->btMarcasProducto->Text = L"Marcas de un producto";
			this->btMarcasProducto->UseVisualStyleBackColor = true;
			this->btMarcasProducto->Click += gcnew System::EventHandler(this, &MenuReportes::btMarcasProducto_Click);
			// 
			// btProductoMasCargado
			// 
			this->btProductoMasCargado->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btProductoMasCargado->Location = System::Drawing::Point(12, 161);
			this->btProductoMasCargado->Name = L"btProductoMasCargado";
			this->btProductoMasCargado->Size = System::Drawing::Size(196, 34);
			this->btProductoMasCargado->TabIndex = 33;
			this->btProductoMasCargado->Text = L"Producto más cargado en góndolas";
			this->btProductoMasCargado->UseVisualStyleBackColor = true;
			this->btProductoMasCargado->Click += gcnew System::EventHandler(this, &MenuReportes::btProductoMasCargado_Click);
			// 
			// btClienteMasCompro
			// 
			this->btClienteMasCompro->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btClienteMasCompro->Location = System::Drawing::Point(12, 109);
			this->btClienteMasCompro->Name = L"btClienteMasCompro";
			this->btClienteMasCompro->Size = System::Drawing::Size(196, 34);
			this->btClienteMasCompro->TabIndex = 32;
			this->btClienteMasCompro->Text = L"Cliente que más compró";
			this->btClienteMasCompro->UseVisualStyleBackColor = true;
			this->btClienteMasCompro->Click += gcnew System::EventHandler(this, &MenuReportes::btClienteMasCompro_Click);
			// 
			// btProductosPorPasilloMasVendidos
			// 
			this->btProductosPorPasilloMasVendidos->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btProductosPorPasilloMasVendidos->Location = System::Drawing::Point(12, 58);
			this->btProductosPorPasilloMasVendidos->Name = L"btProductosPorPasilloMasVendidos";
			this->btProductosPorPasilloMasVendidos->Size = System::Drawing::Size(196, 34);
			this->btProductosPorPasilloMasVendidos->TabIndex = 31;
			this->btProductosPorPasilloMasVendidos->Text = L"Productos por pasillo más vendidos";
			this->btProductosPorPasilloMasVendidos->UseVisualStyleBackColor = true;
			this->btProductosPorPasilloMasVendidos->Click += gcnew System::EventHandler(this, &MenuReportes::btProductosPorPasilloMasVendidos_Click);
			// 
			// btPasilloMasVisitado
			// 
			this->btPasilloMasVisitado->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btPasilloMasVisitado->Location = System::Drawing::Point(12, 6);
			this->btPasilloMasVisitado->Name = L"btPasilloMasVisitado";
			this->btPasilloMasVisitado->Size = System::Drawing::Size(196, 34);
			this->btPasilloMasVisitado->TabIndex = 30;
			this->btPasilloMasVisitado->Text = L"Pasillo más visitado";
			this->btPasilloMasVisitado->UseVisualStyleBackColor = true;
			this->btPasilloMasVisitado->Click += gcnew System::EventHandler(this, &MenuReportes::btPasilloMasVisitado_Click);
			// 
			// btInventarioSupermercado
			// 
			this->btInventarioSupermercado->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btInventarioSupermercado->Location = System::Drawing::Point(217, 323);
			this->btInventarioSupermercado->Name = L"btInventarioSupermercado";
			this->btInventarioSupermercado->Size = System::Drawing::Size(196, 34);
			this->btInventarioSupermercado->TabIndex = 44;
			this->btInventarioSupermercado->Text = L"Inventario del supermercado";
			this->btInventarioSupermercado->UseVisualStyleBackColor = true;
			this->btInventarioSupermercado->Click += gcnew System::EventHandler(this, &MenuReportes::btInventarioSupermercado_Click);
			// 
			// btClientesSupermercado
			// 
			this->btClientesSupermercado->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btClientesSupermercado->Location = System::Drawing::Point(217, 264);
			this->btClientesSupermercado->Name = L"btClientesSupermercado";
			this->btClientesSupermercado->Size = System::Drawing::Size(196, 34);
			this->btClientesSupermercado->TabIndex = 43;
			this->btClientesSupermercado->Text = L"Clientes del supermercado";
			this->btClientesSupermercado->UseVisualStyleBackColor = true;
			this->btClientesSupermercado->Click += gcnew System::EventHandler(this, &MenuReportes::btClientesSupermercado_Click);
			// 
			// btFacturaMayorMonto
			// 
			this->btFacturaMayorMonto->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btFacturaMayorMonto->Location = System::Drawing::Point(217, 211);
			this->btFacturaMayorMonto->Name = L"btFacturaMayorMonto";
			this->btFacturaMayorMonto->Size = System::Drawing::Size(196, 34);
			this->btFacturaMayorMonto->TabIndex = 42;
			this->btFacturaMayorMonto->Text = L"Factura de mayor monto";
			this->btFacturaMayorMonto->UseVisualStyleBackColor = true;
			this->btFacturaMayorMonto->Click += gcnew System::EventHandler(this, &MenuReportes::btFacturaMayorMonto_Click);
			// 
			// btClienteMasFacturo
			// 
			this->btClienteMasFacturo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btClienteMasFacturo->Location = System::Drawing::Point(217, 158);
			this->btClienteMasFacturo->Name = L"btClienteMasFacturo";
			this->btClienteMasFacturo->Size = System::Drawing::Size(196, 34);
			this->btClienteMasFacturo->TabIndex = 41;
			this->btClienteMasFacturo->Text = L"Cliente que más facturó";
			this->btClienteMasFacturo->UseVisualStyleBackColor = true;
			this->btClienteMasFacturo->Click += gcnew System::EventHandler(this, &MenuReportes::btClienteMasFacturo_Click);
			// 
			// btClienteMenosCompro
			// 
			this->btClienteMenosCompro->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btClienteMenosCompro->Location = System::Drawing::Point(217, 107);
			this->btClienteMenosCompro->Name = L"btClienteMenosCompro";
			this->btClienteMenosCompro->Size = System::Drawing::Size(196, 34);
			this->btClienteMenosCompro->TabIndex = 40;
			this->btClienteMenosCompro->Text = L"Cliente que menos compró";
			this->btClienteMenosCompro->UseVisualStyleBackColor = true;
			this->btClienteMenosCompro->Click += gcnew System::EventHandler(this, &MenuReportes::btClienteMenosCompro_Click);
			// 
			// btMarcasMasVendidas
			// 
			this->btMarcasMasVendidas->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btMarcasMasVendidas->Location = System::Drawing::Point(217, 55);
			this->btMarcasMasVendidas->Name = L"btMarcasMasVendidas";
			this->btMarcasMasVendidas->Size = System::Drawing::Size(196, 34);
			this->btMarcasMasVendidas->TabIndex = 39;
			this->btMarcasMasVendidas->Text = L"Marcas más vendidas";
			this->btMarcasMasVendidas->UseVisualStyleBackColor = true;
			this->btMarcasMasVendidas->Click += gcnew System::EventHandler(this, &MenuReportes::btMarcasMasVendidas_Click);
			// 
			// btPasilloMenosVisitado
			// 
			this->btPasilloMenosVisitado->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btPasilloMenosVisitado->Location = System::Drawing::Point(217, 6);
			this->btPasilloMenosVisitado->Name = L"btPasilloMenosVisitado";
			this->btPasilloMenosVisitado->Size = System::Drawing::Size(196, 34);
			this->btPasilloMenosVisitado->TabIndex = 38;
			this->btPasilloMenosVisitado->Text = L"Pasillo menos visitado";
			this->btPasilloMenosVisitado->UseVisualStyleBackColor = true;
			this->btPasilloMenosVisitado->Click += gcnew System::EventHandler(this, &MenuReportes::btPasilloMenosVisitado_Click);
			// 
			// MenuReportes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(425, 402);
			this->Controls->Add(this->btInventarioSupermercado);
			this->Controls->Add(this->btClientesSupermercado);
			this->Controls->Add(this->btFacturaMayorMonto);
			this->Controls->Add(this->btClienteMasFacturo);
			this->Controls->Add(this->btClienteMenosCompro);
			this->Controls->Add(this->btMarcasMasVendidas);
			this->Controls->Add(this->btPasilloMenosVisitado);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btPasillosSupermercado);
			this->Controls->Add(this->btProductosDeUnPasillo);
			this->Controls->Add(this->btMarcasProducto);
			this->Controls->Add(this->btProductoMasCargado);
			this->Controls->Add(this->btClienteMasCompro);
			this->Controls->Add(this->btProductosPorPasilloMasVendidos);
			this->Controls->Add(this->btPasilloMasVisitado);
			this->Controls->Add(this->btVolver);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MenuReportes";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Reportes";
			this->Load += gcnew System::EventHandler(this, &MenuReportes::MenuReportes_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MenuReportes_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btPasilloMasVisitado_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btPasilloMenosVisitado_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btProductosPorPasilloMasVendidos_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btMarcasMasVendidas_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btClienteMasCompro_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btClienteMenosCompro_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btProductoMasCargado_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btClienteMasFacturo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btMarcasProducto_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btFacturaMayorMonto_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btProductosDeUnPasillo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btClientesSupermercado_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btPasillosSupermercado_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btInventarioSupermercado_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
