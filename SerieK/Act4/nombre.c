//Guia K
//Ejercicio 4
//Tomas Gabriel Vecchi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion.h"
#include "utils.h"
#include "nombre.h"

#define MAX_NOMBRE 100
#define LARGO_SOPORTADO 80

char *strWriter(void)
{
    int capacidad = 15;
    char *word = (char*)malloc(capacidad * sizeof(char));
    if(!word)
    {
        printf("Error de memoria\n");
        return NULL;
    }
    
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

void ingreso_nombre(alumno_t *base, size_t item)
{
    int opcionRepetir = 0;

    char *nombre_alumno;
    while(1)
    {
        printf("Ingrese nombre del alumno: ");
        nombre_alumno = strWriter();
        if(!nombre_alumno)
        {
            printf("Error al solicitar memoria para el nombre\n");
            nombre_alumno = "Alumno sin nombre";
        }

        corregir_nombre(nombre_alumno);

        if(strlen(nombre_alumno) >= LARGO_SOPORTADO)
        {
            printf("Nombre muy largo, ingrese de nuevo\n");
            free(nombre_alumno);
            continue;
        }
        break;
    }
    
    char *apellido_alumno;
    while(1)
    {
        printf("Ingrese apellido del alumno: ");
        apellido_alumno = strWriter();
        if(!apellido_alumno)
        {
            printf("Error al solicitar memoria para el apellido\n");
            apellido_alumno = "Alumno sin apellido";
        }

        corregir_nombre(apellido_alumno);

        if(strlen(apellido_alumno) >= LARGO_SOPORTADO)
        {
            printf("Nombre muy largo, ingrese de nuevo\n");
            free(apellido_alumno);
            continue;
        }

        if(buscar_nombre(base, item, nombre_alumno, apellido_alumno))
        {
            printf("Ya existe alguien con ese nombre, ");
            printf("¿Desea seguir?\n");
            scanf("%d", &opcionRepetir);
            while(getchar() != '\n'){};
            if(opcionRepetir)
            {
                break;
            }else
            {
                continue;
            }
        }

        break;
    }

    base[item].nombre = nombre_alumno;

    base[item].apellido = apellido_alumno;
}

#define NO_ENCONTRADO 0
#define ENCONTRADO 1
int buscar_legajo(const alumno_t *base, size_t sz, uint32_t legBuscar)
{
    for(int i = 0; i < sz; i++)
    {
        if(legBuscar == base[i].legajo)
        {
            return ENCONTRADO;
        }
    }

    return NO_ENCONTRADO;
}

#define NOMBRE 0
#define APELLIDO 1
int buscar_nombre(const alumno_t *base, size_t sz, char* strNombre, char* strApellido)
{
    for(int i = 0; i < sz; i++)
    {
        if((!strcmp(strNombre, base[i].nombre)) && (!strcmp(strApellido, base[i].apellido)))
        {
            return ENCONTRADO;
        }
    }

    return NO_ENCONTRADO;
    
}