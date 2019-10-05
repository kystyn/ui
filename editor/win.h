#ifndef __WIN_H_INCLUDED
#define __WIN_H_INCLUDED

#include <windows.h>

BOOL initWnd( HINSTANCE hInst, LPSTR lpszArgument,
              int nCmdShow, WNDPROC wndProc );

int runMsgLoop( void );

#endif // WIN_H_INCLUDED
