#ifndef __EDITOR_H_
#define __EDITOR_H_

#include <windows.h>

typedef struct tagTEXTDATA {
    char **text;
    int *strSize;
    int strCount;
} TEXTDATA;

BOOL readFile( char const *name, TEXTDATA *data );
void freeTextData( TEXTDATA *td );

#endif // __EDITOR_H_
