#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <stdio.h>
#include <tchar.h>
#include "win.h"
#include "wndproc.h"

int WINAPI WinMain( HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nCmdShow )
{
    HWND hWnd = initWnd(hThisInstance, lpszArgument,
                        nCmdShow, WindowProcedure);
    runMsgLoop();
    return 0;
}
