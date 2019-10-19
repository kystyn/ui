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
        int stringsFromEnd = 0, i;

        for (i = 0; i < trd->symsPerH && stringsFromEnd <= trd->symsPerH; i++)
            stringsFromEnd += linesInCurStr(strTextLength(td, td->strCount - 1 - i), trd);

        if (trd->curLineInStr == linesInCurStr(strTL, trd) - 1 ||
            trd->yLeftUp == td->strCount - 1 - i)
        {
            trd->yLeftUp = min(td->strCount - 1 - i, trd->yLeftUp + 1);
            trd->curLineInStr = (trd->yLeftUp == td->strCount - 1 - i) *
                    (trd->symsPerH - linesInCurStr(strTextLength(td, td->strCount - 1 - i), trd));
        }
        else
            trd->curLineInStr++;
    }
}

void PageUp( MODE m, TEXTDATA *td, TEXTRNDDATA *trd )
{
    if (m == VIEW)
        trd->yLeftUp -= min(trd->yLeftUp, trd->symsPerH - 1);
}

void PageDown( MODE m, TEXTDATA *td, TEXTRNDDATA *trd )
{
    int toSkip = min(td->strCount - 1 - trd->yLeftUp - trd->symsPerH, trd->symsPerH - 1);

    if (m == VIEW)
        trd->yLeftUp += toSkip;
    else
    {
        int skipped = 0; // how many strings are printed
        for (; skipped < toSkip; trd->yLeftUp++)
        {
            int strTL = strTextLength(td, trd->yLeftUp);
            int lineCount = linesInCurStr(strTL, trd);

            trd->curLineInStr = (skipped + lineCount - trd->curLineInStr > toSkip) *
                                toSkip - skipped;
        }
    }
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
