#ifndef __EDITOR_H_
#define __EDITOR_H_

#include <windows.h>

typedef struct tagTEXTDATA {
    char **text;
    int *strSize;
    int strCount;
} TEXTDATA;

typedef struct tagTEXTRNDDATA {
    int xLeftUp, yLeftUp;
    int symsPerW, symsPerH;
} TEXTRNDDATA;

BOOL readFile( char const *name, TEXTDATA *data );
void freeTextData( TEXTDATA *td );

#endif // __EDITOR_H_
