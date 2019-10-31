#include "utils.h"

void LineUp( MODE m, TEXTDATA *td, TEXTRNDDATA *trd )
{
    if (m == VIEW)
        trd->yLeftUp = max(0, trd->yLeftUp - 1);
    else
    {
        int strTL;
        if (trd->curLineInStr <= 0)
        {
            trd->yLeftUp--;
            if (trd->yLeftUp < 0)
            {
                trd->yLeftUp = 0;
                trd->curLineInStr = 0;
                return;
            }
            strTL = strTextLength(td, trd->yLeftUp);
            trd->curLineInStr = max(0, linesInCurStr(strTL, trd) - 1);
        }
        else
            trd->curLineInStr--;
    }
}

void LineDown( MODE m, TEXTDATA *td, TEXTRNDDATA *trd )
{
    int endYLeftUp, endCurLineInStr;
    endOfDocument(m, td, trd, &endYLeftUp, &endCurLineInStr);
    if (m == VIEW)
        trd->yLeftUp = min(trd->yLeftUp + 1, endYLeftUp);
    else
    {
        int strTL = strTextLength(td, trd->yLeftUp);

        if (trd->curLineInStr >= linesInCurStr(strTL, trd) - 1 ||
            trd->yLeftUp == endYLeftUp)
        {
            trd->yLeftUp = min(endYLeftUp, trd->yLeftUp + 1);
            trd->curLineInStr = (trd->yLeftUp == endYLeftUp) * endCurLineInStr;
        }
        else if (!(trd->yLeftUp == endYLeftUp &&
                   trd->curLineInStr == endCurLineInStr))
            trd->curLineInStr++;
    }
}

void PageUp( MODE m, TEXTDATA *td, TEXTRNDDATA *trd )
{
    if (m == VIEW)
        trd->yLeftUp -= min(trd->yLeftUp, trd->symsPerH - 1);
    else
    {
        int skipped = 0, toSkip = trd->symsPerH - 1; // how many strings are printed
        for (; skipped < toSkip;)
        {
            int skippedOnIteration = min(trd->curLineInStr + 1, toSkip - skipped);

            trd->curLineInStr =
                /*(skippedOnIteration == trd->curLineInStr + 1) * 0 +*/
                (skippedOnIteration == toSkip - skipped) * (trd->curLineInStr - skippedOnIteration);
            skipped += skippedOnIteration;
            trd->yLeftUp -= (trd->curLineInStr == 0);

            /* start of document */
            if (trd->yLeftUp < 0)
            {
                trd->yLeftUp = 0;
                trd->curLineInStr = 0;
                return;
            }

            if (trd->curLineInStr == 0)
            {
                int strTL = strTextLength(td, trd->yLeftUp);
                trd->curLineInStr = linesInCurStr(strTL, trd) - 1;
            }
        }
    }
}

void PageDown( MODE m, TEXTDATA *td, TEXTRNDDATA *trd )
{
    int endYLeftUp, endCurLineInStr;
                endOfDocument(m, td, trd, &endYLeftUp, &endCurLineInStr);

    if (m == VIEW)
        trd->yLeftUp = min(endYLeftUp,
                            trd->yLeftUp + trd->symsPerH - 1);
    else
    {
        int skipped = 0, toSkip = trd->symsPerH - 1; // how many strings are printed
        for (; skipped < toSkip;)
        {
            int strTL = strTextLength(td, trd->yLeftUp);
            int lineCount = linesInCurStr(strTL, trd);
            int skippedOnIteration = min(lineCount - 1 - trd->curLineInStr, toSkip - skipped);

            trd->curLineInStr =
                /*(skippedOnIteration == lineCount - trd->curLineInStr) * 0 +*/
                (skippedOnIteration == toSkip - skipped) * ((trd->curLineInStr + skippedOnIteration) % lineCount);
            skipped += skippedOnIteration;
            trd->yLeftUp += (trd->curLineInStr == 0);

            // finish of document
            if (trd->yLeftUp > td->strCount - trd->symsPerH)
                if (endYLeftUp >= trd->yLeftUp)
                {
                    trd->yLeftUp = endYLeftUp;
                    trd->curLineInStr = endCurLineInStr;
                }
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
