#ifndef __WIN_H_INCLUDED
#define __WIN_H_INCLUDED

#include <windows.h>

HWND initWnd( HINSTANCE hInst, LPSTR lpszArgument,
              int nCmdShow, WNDPROC wndProc );

int runMsgLoop( void );

#endif // WIN_H_INCLUDED
