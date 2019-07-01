#include "Interface.h"
#include <Windows.h>

using namespace SupaDupaPaint;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Interface);

	return 0;
}
