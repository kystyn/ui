#include <stdio.h>
#include <windows.h>
#include "wndproc.h"
#include "editor.h"


void OnPaint( HWND hWnd, TEXTDATA *td )
{
    int i = 0;
    PAINTSTRUCT ps;
    BeginPaint(hWnd, &ps);
    TEXTMETRIC tm;
    GetTextMetrics(ps.hdc, &tm);

    for (i = 0; i < td->strCount; i++)
        TextOut(ps.hdc, 0, i * tm.tmHeight * 6 / 5, td->text[i], td->strSize[i]);
    EndPaint(hWnd, NULL);
}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )

{
    static TEXTDATA td;
    switch (message)                  /* handle the msg */
    {
    case WM_CREATE:
        readFile(((CREATESTRUCT *)lParam)->lpCreateParams, &td);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
        break;
    case WM_PAINT:
        OnPaint(hWnd, &td);
        break;
    case WM_CLOSE:
        freeTextData(&td);
        break;
    default:                      /* for msg that we don't deal with */
        return DefWindowProc (hWnd, message, wParam, lParam);
    }

    return 0;
}
