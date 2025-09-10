#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestion.h"
#include "utils.h"
#include "nombre.h"

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
    *sz = *sz + 1; 
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
void consultar_alumno(const alumno_t *base, size_t *sz)
{
    uint32_t nLegajo = 0;
    printf("Ingrese el numero de legajo: ");
    scanf("%u", &nLegajo);

    for(int i = 0; i < (*sz); i++)
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
            printf("Legajo encontrado, eliminando datos\n");
            free(base[i].nombre);
            free(base[i].apellido);

            for (size_t j = i; j < (*sz - 1); j++) {
                base[j] = base[j + 1];
            }

            (*sz)--;
            return;
        }
    }

    printf("Legajo no encontrado\n");
}