#ifndef __WIN_H_INCLUDED
#define __WIN_H_INCLUDED

#include <windows.h>

/* Initialize window function.
 * ARGUMENTS:
 *   standard WinMain arguments.
 * RETURNS:
 *   (BOOL) TRUE if success, TRUE otherwise.
 */
BOOL initWnd( HINSTANCE hInst, LPSTR lpszArgument,
              int nCmdShow, WNDPROC wndProc );

/* Run message loop function.
 * ARGUMENTS: None.
 * RETURNS:
 *   (int) system exit code.
 */
int runMsgLoop( void );

#endif // WIN_H_INCLUDED
