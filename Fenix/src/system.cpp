
#pragma once

#include "win32.h"
#include "input.h"

struct System
{
	HDC hdc;
	HINSTANCE hInstance;
	HWND windowH;
	HANDLE handles[10];
	int countH;
	Windows windowsD;

	Input* input;


};
