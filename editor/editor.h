#ifndef __EDITOR_H_
#define __EDITOR_H_

#include <windows.h>

#include "menu.h"

typedef enum
{
    VIEW = MENU_VIEW,
    LAYOUT = MENU_LAYOUT
} MODE;

typedef struct tagTEXTDATA {
    char *text;
    int *strOffsets;
    int strCount;
    int maxStrWidth;
} TEXTDATA;

typedef struct tagTEXTRNDDATA {
    int xLeftUp, yLeftUp;
    int symsPerW, symsPerH;
    int curLineInStr;
} TEXTRNDDATA;

BOOL readFile( char const *name, TEXTDATA *data );
int findMaxStrWidth( TEXTDATA *td, int yStart, int yEnd );
void freeTextData( TEXTDATA *td );
int strByteLength( TEXTDATA *td, int number );
int strTextLength( TEXTDATA *td, int number );
int linesInCurStr( int strTL, TEXTRNDDATA *trd );
void endOfDocument( MODE m, TEXTDATA *td, TEXTRNDDATA *trd,
                    int *endYLeftUp, int *endCurLineInStr );

#endif // __EDITOR_H_
