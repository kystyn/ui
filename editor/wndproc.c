#include <stdio.h>
#include <windows.h>
#include "wndproc.h"
#include "editor.h"

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    switch (message)                  /* handle the msg */
    {
    case WM_CREATE:
        readFile(((CREATESTRUCT *)lParam)->lpCreateParams);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
        break;
    default:                      /* for msg that we don't deal with */
        return DefWindowProc (hWnd, message, wParam, lParam);
    }

    return 0;
}
