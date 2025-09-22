//Guia K
//Ejercicio 3
//Tomas Gabriel Vecchi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion.h"
#include "utils.h"
#include "nombre.h"

#define MAX_NOMBRE 100
#define LARGO_SOPORTADO 80

void ingreso_nombre(alumno_t *base, size_t item)
{
    int opcionRepetir = 0;

    char nombreCorregido[MAX_NOMBRE];
    char nombreNOCorregido[MAX_NOMBRE];
    while(1)
    {
        printf("Ingrese nombre del alumno: ");
        fgets(nombreNOCorregido, MAX_NOMBRE, stdin);

        corregir_nombre(nombreNOCorregido, nombreCorregido);

        if(strlen(nombreCorregido) >= LARGO_SOPORTADO)
        {
            printf("NOmbre muy largo, ingrese de nuevo\n");
            continue;
        }
        break;
    }
    
    char apellidoCorregido[MAX_NOMBRE];
    char apellidoNOCorregido[MAX_NOMBRE];
    while(1)
    {
        printf("Ingrese apellido del alumno: ");
        fgets(apellidoNOCorregido, MAX_NOMBRE, stdin);

        corregir_nombre(apellidoNOCorregido, apellidoCorregido);

        if(buscar_nombre(base, item, nombreCorregido, apellidoCorregido))
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
    

    int szNombre = strlen(nombreCorregido) + 1;
    int szApellido = strlen(apellidoCorregido) + 1;

    base[item].nombre = (char*)malloc(szNombre * sizeof(char));
    if(base[item].nombre == NULL)
    {
        printf("Error de memoria");
        return;
    }
    strcpy(base[item].nombre, nombreCorregido);

    base[item].apellido = (char*)malloc(szApellido * sizeof(char));
    if(base[item].apellido == NULL)
    {
        printf("Error de memoria");
        return;
    }
    strcpy(base[item].apellido, apellidoCorregido);
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