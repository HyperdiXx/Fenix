
#pragma once

#include <mmsystem.h>

#include "input.h"
#include "platformlayerwin32.cpp"

struct Monitor
{
    HMONITOR handle;
};


struct WindowsSetup
{
    int refreshRate;
    int curResX, curResY;

    Monitor monitors[3];

    int aspectRatio;

    bool isFullscreen;
    int style;
};

struct System
{
	HDC hdc;
	HINSTANCE hInstance;
	HWND windowHWND;
	HANDLE handles[10];
	int countH;
	Windows windowsD;

	Input *input;

    void *mainFiber;
    void *messageFiber;

    int coreCount;
    int fontHeight;

    bool isMax;
    bool isFocus;
    bool isFocusOff;
    bool windowFocused;

    bool vsync;

};



LRESULT CALLBACK windowCallback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
    System *data = (System*)GetWindowLongPtr(window, GWLP_USERDATA);


    switch (msg)
    {
    case WM_CLOSE:
        PostMessage(window, msg, wParam, lParam);
        break;
    case WM_QUIT:
        PostMessage(window, msg, wParam, lParam);
        break;
    case WM_DESTROY:
        PostMessage(window, msg, wParam, lParam);
        break;    
    case WM_SIZE:
    {
        if (wParam == SIZE_MAXIMIZED)
        {
            data->isMax = true;
        }
        else if (wParam == SIZE_RESTORED)
        {
            data->isMax = false;
        }

        data->input->isResized = true;
    }break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(window, &ps);
        EndPaint(window, &ps);

        data->vsync = true;
        SwitchToFiber(data->mainFiber);
        return 0;
    }break;

    case WM_TIMER:
    {
        data->vsync = true;
        SwitchToFiber(data->mainFiber);
    }break;

    case WM_SETFOCUS:
    {
        data->isFocus = true;
        data->windowFocused = true;
    }break;

    case WM_KILLFOCUS:
    {
        data->windowFocused = false;
        data->isFocusOff = true;
        data->vsync = true;
        SwitchToFiber(data->mainFiber);
    }break;

    case WM_MENUCHAR: {
        if (LOWORD(wParam) & VK_RETURN)
            return MAKELRESULT(0, MNC_CLOSE);
        return DefWindowProc(window, msg, wParam, lParam);
    } break;

    default:
    {
        return DefWindowProc(window, msg, wParam, lParam);
    }break;
        
        
    }

    return 1;
}

BOOL CALLBACK monitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData);

void initSystem(WindowsSetup *windowsettings, System *data, Windows wdata, int resx, int resy, int style, int , int monitor)
{
    DEVMODE dev;

    data->windowsD = wdata;
    
    EnumDisplayMonitors(0, 0, monitorEnumProc, ((LPARAM)windowsettings));
    EnumDisplaySettings(0, ENUM_CURRENT_SETTINGS, &dev);

    windowsettings->refreshRate = dev.dmDisplayFrequency;
    windowsettings->curResX = resx;
    windowsettings->curResY = resy;
    windowsettings->aspectRatio = (float)resx / (float)resy;
    windowsettings->style = style;

    RECT cr = {0, 0, resx, resy};

    AdjustWindowRectEx(&cr, windowsettings->style, 0, 0);

    int ww = cr.right - cr.left;
    int wh = cr.bottom - cr.top;

    int wx, wy;

    {
        Monitor *mondata = windowsettings->monitors + monitor;
        
    }


    WNDCLASS wndclass = {};
    wndclass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wndclass.lpfnWndProc = windowCallback;
    wndclass.hInstance = data->hInstance;
    wndclass.lpszClassName = "Fenix";

    if(!RegisterClass(&wndclass))
    {
        DWORD error = GetLastError();
        int dum = 2;
    }

    //data->windowHWND = CreateWindowEx(0, wndclass.lpszClassName, "", );

    


}