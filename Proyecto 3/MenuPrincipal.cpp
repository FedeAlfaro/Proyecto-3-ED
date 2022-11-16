#include "MenuPrincipal.h"



using namespace std;
using namespace System;
using namespace System::Windows::Forms;



[STAThreadAttribute]
void Main() {



	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Proyecto3Pruebita::MenuPrincipal form;
	Application::Run(% form);
}
