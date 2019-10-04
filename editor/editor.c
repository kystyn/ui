#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

int symsCount( char *arr, int len, char sym )
{
    int i;
    int cnt = 0;
    for (i = 0; i < len; i++)
        cnt += arr[i] == sym;

    return cnt + 1;
}

BOOL readFile( char const *name, TEXTDATA *data )
{
    int i, curStr = 0, prev = 0, len;
    char *buf;
    FILE *F = fopen(name, "rb");

    if (F == NULL)
        return FALSE;

    fseek(F, 0, SEEK_END);
    len = ftell(F);
    fseek(F, SEEK_SET, 0);

    buf = malloc(len + 1);
    if (buf == NULL)
        return FALSE;

    fread(buf, len, 1, F);
    data->strCount = symsCount(buf, len, '\n');

    data->text = malloc(sizeof(char *) * data->strCount);
    if (data->text == NULL)
        return FALSE;

    data->strSize = malloc(sizeof(int) * data->strCount);
    if (data->strSize == NULL)
        return FALSE;

    for (i = 0; i < len; i++)
        if (buf[i] == '\n' || i + 1 == len)
        {
            data->strSize[curStr] = i - prev + 1;
            data->text[curStr] = malloc(data->strSize[curStr] + 1);
            if (data->text[curStr] == NULL)
                return FALSE;
            memcpy(data->text[curStr], buf + prev, data->strSize[curStr]);
            curStr++;
            prev = i + 1;
        }

    free(buf);

    return TRUE;
}

void freeTextData( TEXTDATA *td )
{
    int i;
    free(td->strSize);
    for (i = 0; i < td->strCount; i++)
        free(td->text[i]);
    free(td->text);
}
