#include <stdio.h>
#include <windows.h>
#include "wndproc.h"
#include "editor.h"
#include "menu.h"

typedef enum
{
    VIEW = 0,
    LAYOUT = 1
} Mode;

void invalidateScreen( HWND hWnd, TEXTRNDDATA *trd, TEXTMETRIC *tm )
{
    RECT rc;
    rc.left = 0;
    rc.top = 0;
    rc.right = (trd->symsPerW + 1) * tm->tmAveCharWidth;
    rc.bottom = (trd->symsPerH + 1) * tm->tmHeight;
    InvalidateRect(hWnd, &rc, TRUE);
}

void OnPaint( HWND hWnd, TEXTDATA *td, TEXTRNDDATA *trd, TEXTMETRIC *tm, Mode m )
{
    int i;
    PAINTSTRUCT ps;
    BeginPaint(hWnd, &ps);

    if (m == VIEW)
        for (i = trd->yLeftUp; i < min(trd->symsPerH + trd->yLeftUp, td->strCount); i++)
            TextOut(ps.hdc, 0, (i - trd->yLeftUp) * tm->tmHeight,
                    td->text + td->strOffsets[i] + trd->xLeftUp,
                    min(strTextLength(td, i) - trd->xLeftUp,
                        trd->symsPerW));

    else
    {
        int printed = 0;
        for (i = trd->yLeftUp; i < min(trd->symsPerH + trd->yLeftUp, td->strCount) && printed <= trd->symsPerH; i++)
        {
            int
                strBL = strByteLength(td, i),
                strTL = strTextLength(td, i);
            int strCount = strTL / trd->symsPerW + (strTL % trd->symsPerW != 0);
            for (; trd->curLineInStr < strCount; trd->curLineInStr++, printed++)
                TextOut(ps.hdc, 0, printed * tm->tmHeight,
                        td->text + td->strOffsets[i] + strBL * trd->curLineInStr,
                        min(strTL, trd->symsPerW));
        }
    }
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

void OnKeyDown( HWND hWnd, WPARAM wParam,
               TEXTDATA *td,
               TEXTRNDDATA *trd, TEXTMETRIC *tm, Mode m )
{
    int minScroll, maxScroll;
    GetScrollRange(hWnd, SB_VERT, &minScroll, &maxScroll);

    switch (wParam)
    {
    case VK_RIGHT:
        if (m == LAYOUT)
            break;
        trd->xLeftUp++;
        invalidateScreen(hWnd, trd, tm);
        break;
    case VK_LEFT:
        if (m == LAYOUT)
            break;
        trd->xLeftUp = max(0, trd->xLeftUp - 1);
        invalidateScreen(hWnd, trd, tm);
        break;
    case VK_UP:
        if (m == VIEW)
            trd->yLeftUp = max(0, trd->yLeftUp - 1);
        else
        {
            int strTL = strTextLength(td, trd->yLeftUp);
            if (trd->curLineInStr == 0)
            {
                trd->yLeftUp = max(0, trd->yLeftUp - 1);
                trd->curLineInStr = linesInCurStr(strTL, trd) - 1;
            }
            else
                trd->curLineInStr++;
        }
        invalidateScreen(hWnd, trd, tm);
        break;
    case VK_DOWN:
        if (m == VIEW)
            trd->yLeftUp = min(td->strCount - 1 - trd->symsPerH, trd->yLeftUp + 1);
        else
        {
            int strTL = strTextLength(td, trd->yLeftUp);
            if (trd->curLineInStr == linesInCurStr(strTL, trd) - 1)
            {
                trd->yLeftUp = min(td->strCount - 1 - trd->symsPerH, trd->yLeftUp + 1);
                trd->curLineInStr = 0;
            }
            else
                trd->curLineInStr--;
        }
        invalidateScreen(hWnd, trd, tm);
        break;
    case VK_PRIOR:
        trd->yLeftUp -= min(trd->yLeftUp, trd->symsPerH - 1);
        invalidateScreen(hWnd, trd, tm);
        break;
    case VK_NEXT:
        trd->yLeftUp += min(td->strCount - 1 - trd->yLeftUp - trd->symsPerH, trd->symsPerH - 1);
        invalidateScreen(hWnd, trd, tm);
        break;
    case VK_HOME:
        if (!GetAsyncKeyState(VK_CONTROL))
        {
            if (m == LAYOUT)
                break;
            trd->xLeftUp = 0;
        }
        else
            trd->yLeftUp = 0;
        invalidateScreen(hWnd, trd, tm);
        break;
    case VK_END:
        if (!GetAsyncKeyState(VK_CONTROL))
        {
            int maxStrW;
            if (m == LAYOUT)
                break;

            maxStrW = findMaxStrWidth(td, trd->yLeftUp, min(trd->yLeftUp + trd->symsPerH, td->strCount));
            if (maxStrW - 1 >= trd->symsPerW)
                trd->xLeftUp = maxStrW - 1 - trd->symsPerW;
        }
        else
            trd->yLeftUp = td->strCount - 1 - trd->symsPerH;
        invalidateScreen(hWnd, trd, tm);
        break;
    }

    SetScrollPos(hWnd, SB_VERT, minScroll + trd->yLeftUp * (float)(maxScroll - minScroll) / (td->strCount - 1 - trd->symsPerH), TRUE);
    SetScrollPos(hWnd, SB_HORZ, minScroll + trd->xLeftUp * (float)(maxScroll - minScroll) / (td->maxStrWidth - 1 - trd->symsPerW), TRUE);
}

void OnVScroll( HWND hWnd, WPARAM wParam, TEXTDATA *td, TEXTRNDDATA *trd, TEXTMETRIC *tm )
{
    int minScroll, maxScroll;
    int pos = HIWORD(wParam);
    GetScrollRange(hWnd, SB_VERT, &minScroll, &maxScroll);

    switch (LOWORD(wParam))
    {
    case SB_THUMBTRACK:
        trd->yLeftUp = (float)(pos - minScroll) / (maxScroll - minScroll) * (td->strCount - 1 - trd->symsPerH);
        SetScrollPos(hWnd, SB_VERT, HIWORD(wParam), TRUE);
        invalidateScreen(hWnd, trd, tm);
        break;
    case SB_LINEDOWN:
        trd->yLeftUp = min(td->strCount - 1 - trd->symsPerH, trd->yLeftUp + 1);
        invalidateScreen(hWnd, trd, tm);
        break;
    case SB_LINEUP:
        trd->yLeftUp = max(0, trd->yLeftUp - 1);
        invalidateScreen(hWnd, trd, tm);
        break;
    }
}

void OnHScroll( HWND hWnd, WPARAM wParam, TEXTDATA *td, TEXTRNDDATA *trd, TEXTMETRIC *tm )
{
    int minScroll, maxScroll;
    int pos = HIWORD(wParam);

    GetScrollRange(hWnd, SB_HORZ, &minScroll, &maxScroll);

    switch (LOWORD(wParam))
    {
    case SB_THUMBTRACK:
        trd->xLeftUp = (float)(pos - minScroll) / (maxScroll - minScroll) * (td->maxStrWidth - 1 - trd->symsPerW);
        SetScrollPos(hWnd, SB_HORZ, HIWORD(wParam), TRUE);
        invalidateScreen(hWnd, trd, tm);
        break;
    case SB_LINEDOWN:
        trd->xLeftUp = min(td->maxStrWidth - 1 - trd->symsPerW, trd->xLeftUp + 1);
        invalidateScreen(hWnd, trd, tm);
        break;
    case SB_LINEUP:
        trd->xLeftUp = max(0, trd->xLeftUp - 1);
        invalidateScreen(hWnd, trd, tm);
        break;
    }
}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )

{
    static TEXTDATA td;
    static TEXTRNDDATA trd;
    static TEXTMETRIC tm;
    static HFONT hFont;
    static int minScroll = 0, maxScroll = 2000;
    static int fontSize = 26;
    static Mode m = VIEW;

    HDC hDC;
    HMENU hMenu;

    switch (message)                  /* handle the msg */
    {
    case WM_CREATE:
        hDC = GetDC(hWnd);

        hFont = CreateFont(
                             fontSize,
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
        if (!readFile(((CREATESTRUCT *)lParam)->lpCreateParams, &td))
            PostQuitMessage(0);// check incorrect file
        SetScrollRange(hWnd, SB_VERT, minScroll, maxScroll, TRUE);
        SetScrollRange(hWnd, SB_HORZ, minScroll, maxScroll, TRUE);

        trd.curLineInStr = 0;
        trd.xLeftUp = 0;
        trd.yLeftUp = 0;
        break;
    case WM_DESTROY:
        freeTextData(&td);
        PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
        break;
    case WM_PAINT:
        OnPaint(hWnd, &td, &trd, &tm, m);
        break;
    case WM_SIZE:
        OnSize(hWnd, &trd, &tm, LOWORD(lParam), HIWORD(lParam));
        break;
    case WM_CLOSE:
        freeTextData(&td);
        PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
        break;
    case WM_KEYDOWN:
        OnKeyDown(hWnd, wParam, &td, &trd, &tm, m);
        break;
    case WM_VSCROLL:
        OnVScroll(hWnd, wParam, &td, &trd, &tm);
        break;
    case WM_HSCROLL:
        OnHScroll(hWnd, wParam, &td, &trd, &tm);
        break;
    case WM_COMMAND:
        hMenu = GetMenu(hWnd);
        switch (LOWORD(wParam))
        {
        case MENU_VIEW:
            CheckMenuItem(hMenu, MENU_VIEW, MF_CHECKED);
            CheckMenuItem(hMenu, MENU_LAYOUT, MF_UNCHECKED);
            m = VIEW;
            invalidateScreen(hWnd, &td, &trd);
            break;
        case MENU_LAYOUT:
            CheckMenuItem(hMenu, MENU_VIEW, MF_UNCHECKED);
            CheckMenuItem(hMenu, MENU_LAYOUT, MF_CHECKED);
            m = LAYOUT;
            invalidateScreen(hWnd, &td, &trd);
            break;
        }
        break;
    case WM_QUIT:
        freeTextData(&td);
        break;
    default:                      /* for msg that we don't deal with */
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}
