#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

BOOL readFile( char const *name, char **buf, int *len )
{
    FILE *F = fopen(name, "rb");

    if (F == NULL)
        return FALSE;

    fseek(F, 0, SEEK_END);
    *len = ftell(F);
    fseek(F, SEEK_SET, 0);

    *buf = malloc(len + 1);
    if (*buf == NULL)
        return NULL;

    fread(*buf, *len, 1, F);

    printf("%s\n", *buf);
    return TRUE;
}
