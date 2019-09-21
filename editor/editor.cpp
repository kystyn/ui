#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

char * readFile( char const *name )
{
    FILE *F = fopen(name, "rb");
    int len = ftell(F);
    char *buf = malloc(len + 1);
    if (buf == NULL)
        return NULL;

    //fseek(F, F)
}
