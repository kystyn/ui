#ifndef __EDITOR_H_
#define __EDITOR_H_

#include <windows.h>

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
void endOfDocument( TEXTDATA *td, TEXTRNDDATA *trd,
                    int *endYLeftUp, int *endCurLineInStr );

#endif // __EDITOR_H_
