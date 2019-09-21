#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

char * readFile( char const *name )
{
    FILE *F = fopen(name, "rb");

    fseek(F, 0, SEEK_END);
    int len = ftell(F);
    fseek(F, SEEK_SET, 0);

    char *buf = malloc(len + 1);
    if (buf == NULL)
        return NULL;

    fread(buf, len, 1, F);

    printf("%s\n", buf);

    return buf;
}
