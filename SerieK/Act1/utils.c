#include <stdio.h>
#include "utils.h"

void eliminar_salto(char *str)
{
    for(int i = 0; str[i] != 0; i++)
    {
        if(str[i] == '\n')
        {
            str[i] = '\0';
        }
    }
}

void eliminar_espacios(const char *src, char *dts)
{
    int iSrc = 0;
    int iDts = 0;

    while (src[iSrc] != '\0')
    {
        if ((src[iSrc] != ' ') || ((iDts > 0) && (dts[iDts - 1] != ' ')))
        {
            dts[iDts] = src[iSrc];
            iDts++;
        }
        iSrc++;
    }
    dts[iDts] = '\0';
}

void corregir_nombre(const char *src, char *dts)
{
    eliminar_espacios(src, dts);
    eliminar_salto(dts);
}