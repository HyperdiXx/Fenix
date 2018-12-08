
#pragma once


#include <windows.h>

#include "memory.cpp"




struct Windows
{
    HINSTANCE hinstance;
    HINSTANCE previnstance;
    LPSTR comd;
    int cmdShow;
};


Windows windowsData(HINSTANCE instance, HINSTANCE prevInstance, LPSTR commandLine, int cmdShow) 
{	
	Windows w;
	w.hinstance = instance;
	w.previnstance = prevInstance;
	w.comd = commandLine;
	w.cmdShow = cmdShow;

	return w;
}

struct ThreadQueue;
#define APPMAINFUNCTION(name) void name(bool init, bool reload, bool *isRunning, Windows windowsData, ThreadQueue* threadQueue, Memory* memory)
typedef APPMAINFUNCTION(appMainType);
appMainType* platform_appMain;