#include <stdio.h>
#include <windows.h>
#include "wndproc.h"
#include "editor.h"


void OnPaint( HWND hWnd, TEXTDATA *td, TEXTRNDDATA *trd, int tHeight )
{
    int i;
    PAINTSTRUCT ps;
    BeginPaint(hWnd, &ps);

    HFONT hFont = CreateFont(
                             16,
                             0,
                             0,
                             0,
                             FW_NORMAL,
                             FALSE,
                             FALSE,
                             FALSE,
                             ANSI_CHARSET,
                             OUT_TT_PRECIS,
                             CLIP_CHARACTER_PRECIS,
                             CLEARTYPE_QUALITY,
                             FIXED_PITCH,
                             TEXT("Courier"));
    SelectObject(ps.hdc, hFont);
    for (i = trd->yLeftUp; i < min(trd->symsPerH, td->strCount) + trd->yLeftUp; i++)
        TextOut(ps.hdc, 0, i * tHeight * 6 / 5, td->text[i] + trd->xLeftUp,
                min(td->strSize[i], trd->symsPerW) - trd->xLeftUp);
    EndPaint(hWnd, NULL);
    DeleteObject(hFont);
}

void OnSize( TEXTRNDDATA *trd, TEXTMETRIC *tm, int newW, int newH )
{
    trd->symsPerW = newW / tm->tmAveCharWidth;
    trd->symsPerH = newH / tm->tmHeight;

}
/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )

{
    static TEXTDATA td;
    static TEXTRNDDATA trd;
    static TEXTMETRIC tm;

    HDC hDC;
    RECT rc;
    rc.left = 0;
    rc.top = 0;

    switch (message)                  /* handle the msg */
    {
    case WM_CREATE:
        hDC = GetDC(hWnd);
        GetTextMetrics(hDC, &tm);
        ReleaseDC(hWnd, hDC);
        if (!readFile(((CREATESTRUCT *)lParam)->lpCreateParams, &td))
            exit(0);
        break;
    case WM_DESTROY:
        freeTextData(&td);
        PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
        break;
    case WM_PAINT:
        OnPaint(hWnd, &td, &trd, tm.tmHeight);
        break;
    case WM_SIZE:
        rc.right = LOWORD(lParam);
        rc.bottom = HIWORD(lParam);
        OnSize(&trd, &tm, LOWORD(lParam), HIWORD(lParam));
        InvalidateRect(hWnd, &rc, TRUE);
        break;
    case WM_CLOSE:
        freeTextData(&td);
        exit(0);
        break;
    default:                      /* for msg that we don't deal with */
        return DefWindowProc (hWnd, message, wParam, lParam);
    }

    return 0;
}
