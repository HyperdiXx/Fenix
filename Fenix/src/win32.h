#pragma once

#include <windows.h>


struct Windows
{
	HINSTANCE hinstance;
	HINSTANCE previnstance;
	LPSTR comd;
	int cmdShow;
};
