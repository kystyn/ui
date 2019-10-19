#include "utils.h"

void LineUp( MODE m, TEXTDATA *td, TEXTRNDDATA *trd )
{
    if (m == VIEW)
        trd->yLeftUp = max(0, trd->yLeftUp - 1);
    else
    {
        int strTL;
        if (trd->curLineInStr == 0)
        {
            trd->yLeftUp = max(0, trd->yLeftUp - 1);
            strTL = strTextLength(td, trd->yLeftUp);
            trd->curLineInStr = linesInCurStr(strTL, trd) - 1;
        }
        else
            trd->curLineInStr--;
    }
}

void LineDown( MODE m, TEXTDATA *td, TEXTRNDDATA *trd )
{
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
            trd->curLineInStr++;
    }
}

void PageUp( MODE m, TEXTDATA *td, TEXTRNDDATA *trd )
{
    trd->yLeftUp -= min(trd->yLeftUp, trd->symsPerH - 1);
}

void PageDown( MODE m, TEXTDATA *td, TEXTRNDDATA *trd )
{
    trd->yLeftUp += min(td->strCount - 1 - trd->yLeftUp - trd->symsPerH, trd->symsPerH - 1);
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
