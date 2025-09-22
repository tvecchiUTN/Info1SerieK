#include <stdio.h>
#include <stdlib.h>

char *strWriter();

int main(void)
{
    char *prueba = strWriter();

    printf("Palabra magica es: %s\n", prueba);
    free(prueba);
    return 0;
}

char *strWriter()
{
    int capacidad = 15;
    char *word = (char*)malloc(capacidad * sizeof(char));
    if(!word)
    {
        printf("Error de memoria\n");
        return NULL;
    }
    printf("Introduzca la palabra: ");
    
    int i = 0;
    while(1)
    {
        if(i >= capacidad)
        {
            capacidad *= 2;
            char *temp = (char*)realloc(word, capacidad * sizeof(char));
            if(!temp)
            {
                printf("Error al agranadar memoria\n");
                free(word);
                return NULL;
            }
            word = temp;
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
    
    char *last_aux = (char*)realloc(word, (i+1) * sizeof(char));
    if(!last_aux)
    {

        return word;
    }

    return last_aux;
}