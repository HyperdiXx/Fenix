


#ifndef RELEASE

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <stdio.h>
#include <windows.h>

#include "platformlayerwin32.cpp"
#include "memory.cpp"


#else

#include "applicationd3d.cpp"

#endif // !RELEASE


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmd, int prevcmd)
{
#ifndef RELEASE

	AllocConsole();

	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);

#endif // !RELEASE


	Windows dataW = windowsData(hInstance, hPrevInstance, cmd, prevcmd);

	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	int coreCount = sysInfo.dwNumberOfProcessors;

    //Threads th;

    bool isRunning = true;

    while (isRunning)
    {

    }



	return 0;
}
