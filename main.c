#include <stdio.h>
#include <stdlib.h>

char *strWriter(int max);

int main(void)
{
    char *prueba = strWriter(80);

    printf("Palabra magica es: %s\n", prueba);
    free(prueba);
    return 0;
}

char *strWriter(int max)
{
    int capacidad = 15;
    char *word = (char*)malloc(capacidad * sizeof(char));
    printf("Introduzca la palabra: ");
    
    int i = 0;
    while(i < max)
    {
        if(i >= capacidad)
        {
            capacidad *= 2;
            word = (char*)realloc(word, capacidad * sizeof(char));
        }
        int c = getchar();
        if(c == '\n')
        {
            break;
        }
        *(word+i) = (char)c;
        i++;
    }
    *(word+i) = '\0';
    word = (char*)realloc(word, (i+1) * sizeof(char));


    return word;
}