#ifndef __EDITOR_H_
#define __EDITOR_H_

#include <windows.h>

#include "menu.h"

/* Representation methods */
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
    int xLeftUp, yLeftUp;   /* Current upper left (x, y) point */
    int symsPerW, symsPerH; /* symbols per linear size */
    int curLineInStr;       /* cur line in str (actual in layout
                             * mode. in view - zero
                             */
} TEXTRNDDATA;

BOOL readFile( char const *name, TEXTDATA *data );
int findMaxStrWidth( TEXTDATA *td, int yStart, int yEnd );
void freeTextData( TEXTDATA *td );

/* number - number of string in document */
int strByteLength( TEXTDATA *td, int number );
int strTextLength( TEXTDATA *td, int number );
int linesInCurStr( int strTL, TEXTRNDDATA *trd );

/* find document end method.
 * endYLeftUp, endCurLineInStr are TEXTRNDDATA parameters
 * which will let us see document finish*/
void endOfDocument( MODE m, TEXTDATA *td, TEXTRNDDATA *trd,
                    int *endYLeftUp, int *endCurLineInStr );

#endif // __EDITOR_H_
