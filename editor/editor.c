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
    int i, curStr = 1, len;
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

    int resLen = fread(buf, 1, len, F);
    if (resLen != len)
    {
        free(buf);
        return FALSE;
    }

    data->strCount = symsCount(buf, len, '\n');
    data->text = buf;
    // +1 cause save last sym offset
    data->strOffsets = malloc(sizeof(int) * (data->strCount + 1));

    if (data->strOffsets == NULL)
    {
        free(data->text);
        return FALSE;
    }

    data->strOffsets[0] = 0;
    for (i = 1; i < len; i++)
        if (buf[i] == '\n' || i + 1 == len)
        {
            data->strOffsets[curStr++] = i + 1;
        }

    data->maxStrWidth = findMaxStrWidth(data, 0, data->strCount);
    return TRUE;
}

void freeTextData( TEXTDATA *td )
{
    if (td->strOffsets != NULL)
    {
        free(td->strOffsets);
        td->strOffsets = NULL;
    }

    if (td->text != NULL)
    {
        free(td->text);
        td->text = NULL;
    }
}

int findMaxStrWidth( TEXTDATA *td, int yStart, int yEnd )
{
    int i;
    int maxLen = 0;
    for (i = yStart; i < yEnd; i++)
        if (td->strOffsets[i + 1] - td->strOffsets[i] > maxLen)
            maxLen = td->strOffsets[i + 1] - td->strOffsets[i];

    return maxLen;
}
