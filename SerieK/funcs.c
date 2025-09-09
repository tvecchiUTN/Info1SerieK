#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int szStr(char *arr)
{
    for(int i = 0; i<MAXCARAC; i++)
    {
        if( *(arr+i) == '\n')
        {
            *(arr+i) = 0;
        }
        if( *(arr+i) == '\0')
        {
            return i;
        }

    }

    return -1;
}

int srchLeg(const int leg, const int *vec)
{
    for(int i = 0; i<MAXCARAC; i++)
    {
        if( *(vec+i) == leg)
        {
            return i;
        }
    }

    return -1;
}
int srchNom(const char *nom)
{
    return 2;
}
int srchApe(const char *ape)
{
    return 2;
}
