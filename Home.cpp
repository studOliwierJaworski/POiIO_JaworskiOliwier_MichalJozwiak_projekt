#include "Home.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array <String^>^ args) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AplikacjaHotelowa::Home form;
	Application::Run(% form);
	return 0;

}