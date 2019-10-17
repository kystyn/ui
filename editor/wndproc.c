#include <stdio.h>
#include <windows.h>
#include "wndproc.h"
#include "editor.h"

void OnPaint( HWND hWnd, TEXTDATA *td, TEXTRNDDATA *trd, TEXTMETRIC *tm )
{
    int i;
    PAINTSTRUCT ps;
    BeginPaint(hWnd, &ps);

    for (i = trd->yLeftUp; i < min(trd->symsPerH + trd->yLeftUp, td->strCount); i++)
        TextOut(ps.hdc, 0, (i - trd->yLeftUp) * tm->tmHeight,
                td->text + td->strOffsets[i] + trd->xLeftUp,
                min(td->strOffsets[i + 1] - td->strOffsets[i] - 1 -
                    (td->text[td->strOffsets[i] - 2] == '\r') - trd->xLeftUp,
                    trd->symsPerW));

    EndPaint(hWnd, &ps);
}

void OnSize( HWND hWnd, TEXTRNDDATA *trd, TEXTMETRIC *tm, int newW, int newH )
{
    int
        oldW = trd->symsPerW,
        oldH = trd->symsPerH;
    RECT rc;

    trd->symsPerW = newW / tm->tmAveCharWidth;
    trd->symsPerH = newH / tm->tmHeight;

    // vertical
    rc.top = 0;
    rc.bottom = max(newH, oldH);
    rc.left = (min(trd->symsPerW, oldW) - 1) * tm->tmAveCharWidth;
    rc.right = (max(trd->symsPerW, oldW) + 1) * tm->tmAveCharWidth ;
    InvalidateRect(hWnd, &rc, TRUE);

    // horizontal
    rc.top = (min(trd->symsPerH, oldH) - 1) * tm->tmHeight;
    rc.bottom = (max(trd->symsPerH, oldH) + 1) * tm->tmHeight;
    rc.left = 0;
    rc.right = newW;
    InvalidateRect(hWnd, &rc, TRUE);
}

void invalidateScreen( HWND hWnd, TEXTRNDDATA *trd, TEXTMETRIC *tm )
{
    RECT rc;
    rc.left = 0;
    rc.top = 0;
    rc.right = (trd->symsPerW + 1) * tm->tmAveCharWidth;
    rc.bottom = (trd->symsPerH + 1) * tm->tmHeight;
    InvalidateRect(hWnd, &rc, TRUE);
}
/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )

{
    static TEXTDATA td;
    static TEXTRNDDATA trd;
    static TEXTMETRIC tm;
    static HFONT hFont;

    HDC hDC;

    switch (message)                  /* handle the msg */
    {
    case WM_CREATE:
        hDC = GetDC(hWnd);

        hFont = CreateFont(
                             26,
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

        SelectObject(hDC, hFont);
        SetTextColor(hDC, RGB(255, 255, 255));
        SetBkColor(hDC, RGB(0, 0, 255));

        GetTextMetrics(hDC, &tm);
        //ReleaseDC(hWnd, hDC);
        if (!readFile(((CREATESTRUCT *)lParam)->lpCreateParams, &td))
            ;// check incorrect file
        break;
    case WM_DESTROY:
        freeTextData(&td);
        PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
        break;
    case WM_PAINT:
        OnPaint(hWnd, &td, &trd, &tm);
        break;
    case WM_SIZE:
        OnSize(hWnd, &trd, &tm, LOWORD(lParam), HIWORD(lParam));
        break;
    case WM_CLOSE:
        freeTextData(&td);
        exit(0);
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_RIGHT:
            trd.xLeftUp++;
            invalidateScreen(hWnd, &trd, &tm);
            break;
        case VK_LEFT:
            if (trd.xLeftUp > 0)
            {
                trd.xLeftUp--;
                invalidateScreen(hWnd, &trd, &tm);
            }
            break;
        case VK_UP:
            if (trd.yLeftUp > 0)
            {
                trd.yLeftUp--;
                invalidateScreen(hWnd, &trd, &tm);
            }
            break;
        case VK_DOWN:
            if (trd.yLeftUp < td.strCount - 1)
            {
                trd.yLeftUp++;
                invalidateScreen(hWnd, &trd, &tm);
            }
            break;
        case VK_PRIOR:
            trd.yLeftUp -= min(trd.yLeftUp, trd.symsPerH) - 1;
            invalidateScreen(hWnd, &trd, &tm);
            break;
        case VK_NEXT:
            if (td.strCount - 1 - trd.yLeftUp > trd.symsPerH)
                trd.yLeftUp += trd.symsPerH - 1;
            invalidateScreen(hWnd, &trd, &tm);
            break;
        case VK_HOME:
            if (!GetAsyncKeyState(VK_CONTROL))
                trd.xLeftUp = 0;
            else
                trd.yLeftUp = 0;
            invalidateScreen(hWnd, &trd, &tm);
            break;
        case VK_END:
            if (!GetAsyncKeyState(VK_CONTROL))
            {
                int i;
                int maxLenIdx = 0, maxLen = 0;
                for (i = trd.yLeftUp; i < min(trd.yLeftUp + trd.symsPerH, td.strCount); i++)
                    if (td.strOffsets[i + 1] - td.strOffsets[i] > maxLen)
                    {
                        maxLen = td.strOffsets[i + 1] - td.strOffsets[i];
                        maxLenIdx = i;
                    }

                if (td.strOffsets[maxLenIdx + 1] - td.strOffsets[maxLenIdx] - 1 >= trd.symsPerW)
                        trd.xLeftUp =
                            td.strOffsets[maxLenIdx + 1] - td.strOffsets[maxLenIdx] - 1 - trd.symsPerW - 1;
            }
            else
                trd.yLeftUp = td.strCount - 1 - trd.symsPerH;
            invalidateScreen(hWnd, &trd, &tm);
            break;
        }
        break;
    default:                      /* for msg that we don't deal with */
        return DefWindowProc (hWnd, message, wParam, lParam);
    }

    return 0;
}
