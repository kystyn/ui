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
} TEXTRNDDATA;

BOOL readFile( char const *name, TEXTDATA *data );
int findMaxStrWidth( TEXTDATA *td, int yStart, int yEnd );
void freeTextData( TEXTDATA *td );

#endif // __EDITOR_H_
