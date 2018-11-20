
#ifndef RELEASE

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <stdio.h>

#include "loader.cpp"

#else

#include "app.cpp"

#endif // !RELEASE


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmd, int prevcmd)
{
	AllocConsole();

	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);

	Windows dataW = windowsData(hInstance, hPrevInstance, cmd, prevcmd);

	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	int coreCount = sysInfo.dwNumberOfProcessors;





	return 0;
}
