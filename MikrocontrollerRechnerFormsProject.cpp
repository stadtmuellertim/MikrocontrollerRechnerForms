#include "pch.h"

using namespace System;

#include "Form1.h"

using namespace System::Windows::Forms;

[STAThread]

int main()
{
	SerialPort comPort = SerialPort();
	ResultCache results = ResultCache();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MikrocontrollerRechnerFormsProject::Form1(&comPort, &results));
	
	return 0;
}