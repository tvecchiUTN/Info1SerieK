//Guia K
//Ejercicio 2
//Tomas Gabriel Vecchi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestion.h"
#include "utils.h"
#include "nombre.h"

void reordenar(alumno_t *base, size_t *sz, size_t item);

//Ingreso de datos
void ingreso_alumno(alumno_t *base, size_t *sz)
{
    uint32_t nLegajo = 0;
    while(1)
    {
        printf("Ingrese el numero de legajo: ");
        scanf("%u", &nLegajo);
        if(nLegajo == 0)
        {
            printf("Numero de legajo no permitido\n");
            continue;
        }
        else if(buscar_legajo(base, *sz, nLegajo))
        {
            printf("Numero de legajo repetido\n");
            continue;
        }
        break;
    }
    
    while(getchar() != '\n'){}; //Se utiliza para sacar el \n del scanf de arriba

    ingreso_nombre(base, *sz);    

    base[*sz].legajo = nLegajo;
    (*sz)++; 
}

//Modificacion de datos de alumno
void modificar_alumno(alumno_t *base, size_t *sz)
{
    uint32_t nLegajo = 0;
    printf("Ingrese el numero de legajo: ");
    scanf("%u", &nLegajo);
    
    while(getchar() != '\n'){};

    for(int i = 0; i < (*sz); i++)
    {
        if((nLegajo == (base[i].legajo)) && (nLegajo > 0))
        {
            printf("Legajo encontrado\n");

            free(base[i].nombre);
            free(base[i].apellido);
            
            ingreso_nombre(base, i);
            return;
        }
    }
    printf("Legajo no encontrado\n");
}

//Consultar datos de alumno
void consultar_alumno(const alumno_t *base, size_t sz)
{
    printf("¿Desea consultar sobre uno solo o muchos? \n");
    printf("Poner 0 es para todos. ");
    int opcionCuantos = 0;
    scanf("%d", &opcionCuantos);

    printf("\n");
    if(opcionCuantos)
    {
        uint32_t nLegajo = 0;
        printf("Ingrese el numero de legajo: ");
        scanf("%u", &nLegajo);

        for(int i = 0; i < (sz); i++)
        {
            if((nLegajo == (base[i].legajo)) && (nLegajo > 0))
            {
                printf("Legajo encontrado\n");
                
                printf("Nombre: ");
                printf("%s\n", base[i].nombre);

                printf("Apellido: ");
                printf("%s\n", base[i].apellido);

                printf("\n");
                return;
            }
        }
        printf("Legajo no encontrado\n");
    }else
    {
        printf("----------------------------------------------------------------------------------------------------------\n");
        printf("  Legajos | Nombre del alumno | Apellido del alumno \n");
        for(int i = 0; i < (sz); i++)
        {
            
            printf(" %8d | %17s | %19s \n", base[i].legajo, base[i].nombre, base[i].apellido);
        }
        printf("----------------------------------------------------------------------------------------------------------\n");
        return;
    }
}

//Eliminacion de datos de alumno
void eliminar_alumno(alumno_t *base, size_t *sz)
{
    uint32_t nLegajo = 0;
    printf("Ingrese el numero de legajo: ");
    scanf("%u", &nLegajo);

    for(int i = 0; i < (*sz); i++)
    {
        if((nLegajo == (base[i].legajo)) && (nLegajo > 0))
        {
            printf("Legajo encontrado\n");
            printf("Eliminando datos de %s %s\n", base[i].nombre, base[i].apellido);
            free(base[i].nombre);
            free(base[i].apellido);
            
            reordenar(base, sz, i);

            return;
        }
    }

    printf("Legajo no encontrado\n");
}

void reordenar(alumno_t *base, size_t *sz, size_t item)
{
    for (size_t j = item; j < (*sz - 1); j++) 
    {
        base[j] = base[j + 1];
    }

    (*sz)--;
}