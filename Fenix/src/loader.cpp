
#pragma once

#include "loader.h"


Windows windowsData(HINSTANCE instance, HINSTANCE prevInstance, LPSTR commandLine, int cmdShow) 
{	
	Windows w;
	w.hinstance = instance;
	w.previnstance = prevInstance;
	w.comd = commandLine;
	w.cmdShow = cmdShow;

	return w;
}