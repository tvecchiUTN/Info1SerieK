#include <stdio.h>
#include <string.h>
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

#define MAYUS 32 //De la A a la a, (Mayuscula y miniscula) hay una separacion de 32 digitos

//Se supone qu ela palabra esta con un solo espacio entre palabras
void capitalizar(char *str)
{
    int inicioPalabra = 1;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(inicioPalabra)
        {
            if((str[i] > 96) && (str[i] < 123))
            {
                str[i] = str[i] - MAYUS;
            }
            inicioPalabra = 0;
            continue;
        }

        if(str[i] == ' ')
        {
            inicioPalabra = 1;
        }

        if((str[i] > 64) && (str[i] < 91))
        {
            str[i] = str[i] + MAYUS;
        }
    }


}

void corregir_nombre(char *dts)
{
    char copia[80];
    strcpy(copia, dts);
    eliminar_espacios(copia, dts);
    eliminar_salto(dts);
    capitalizar(dts);
}