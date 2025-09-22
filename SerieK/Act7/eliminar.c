#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gestion.h"
#include "eliminar.h"
#include "utils.h"
#include "nombre.h"

#define NO_ENCONTRADO -1
#define ENCONTRADO 0
#define ENCONTRADO_MULTIPLE 1

int eliminacion_por_nombre(const alumno_t *base, size_t sz, char *nombre)
{
    int i;
    int cdad = 0;

    for (i = 0; i < sz; i++)
    {
        if (!strcmp(base[i].nombre, nombre))
        {
            cdad++;
        }
    }
    if (cdad == 0)
    {
        return NO_ENCONTRADO;
    }
    else if (cdad == 1)
    {
        return ENCONTRADO;
    }
    else
    {
        return ENCONTRADO_MULTIPLE;
    }
}

int eliminacion_por_apellido(const alumno_t *base, size_t sz, char *apellido)
{
    int i;
    int cdad = 0;

    for (i = 0; i < sz; i++)
    {
        if (!strcmp(base[i].apellido, apellido))
        {
            cdad++;
        }
    }
    if (cdad == 0)
    {
        return NO_ENCONTRADO;
    }
    else if (cdad == 1)
    {
        return ENCONTRADO;
    }
    else
    {
        return ENCONTRADO_MULTIPLE;
    }
}

int eliminacion_por_ambos(const alumno_t *base, size_t sz, char *nombre, char *apellido)
{
    int i;
    int cdad = 0;

    for (i = 0; i < sz; i++)
    {
        if (!strcmp(base[i].nombre, nombre) && !strcmp(base[i].apellido, apellido))
        {
            cdad++;
        }
    }
    if (cdad == 0)
    {
        return NO_ENCONTRADO;
    }
    else if (cdad == 1)
    {
        return ENCONTRADO;
    }
    else
    {
        return ENCONTRADO_MULTIPLE;
    }
}

void gestion_eliminacion_nombre(alumno_t *base, size_t *sz)
{
    char *nombreAux;
    printf("Ingrese el nombre: ");
    nombreAux = strWriter();
    if(!nombreAux)
    {
        printf("Error al soliciar memoria, la funcion no puede seguir\n");
        return;
    }
    corregir_nombre(nombreAux);

    int eliminacion = eliminacion_por_nombre(base, *sz, nombreAux);

    if (eliminacion == -1)
    {
        printf("Nombre no encontrado\n");
        return;
    }
    else if (eliminacion == 0)
    {
        for (int i = 0; i < *sz; i++)
        {
            if (!strcmp(base[i].nombre, nombreAux))
            {
                printf("Eliminando datos de %s %s\n", base[i].nombre, base[i].apellido);
                free(base[i].nombre);
                free(base[i].apellido);

                reordenar(base, sz, i);
            }
        }
    }
    else
    {
        printf("Se encontraron mas de uno con ese nombre, ¿que desea hacer?\n");
        printf("0- Eliminar por legajo\n");
        printf("1- Eliminar todos con ese nombre");

        int opcionMultiple = 0;
        scanf("%d", &opcionMultiple);
        while (getchar() != '\n')
        {
        };
        if (!opcionMultiple)
        {
            uint32_t nLegajo = 0;
            printf("Ingrese el numero de legajo: ");
            scanf("%u", &nLegajo);

            for (int i = 0; i < (*sz); i++)
            {
                if ((nLegajo == (base[i].legajo)) && (nLegajo > 0))
                {
                    printf("Legajo encontrado\n");
                    printf("Eliminando datos de %s %s\n", base[i].nombre, base[i].apellido);
                    free(base[i].nombre);
                    free(base[i].apellido);

                    reordenar(base, sz, i);

                    return;
                }
            }
        }
        else
        {
            for (int i = 0; i < *sz; i++)
            {
                if (!strcmp(base[i].nombre, nombreAux))
                {
                    free(base[i].nombre);
                    free(base[i].apellido);

                    reordenar(base, sz, i);
                    i--;
                }
            }
        }
    }

    free(nombreAux);
}

void gestion_eliminacion_apellido(alumno_t *base, size_t *sz)
{
    char *apellidoAux;
    printf("Ingrese el apellido: ");
    apellidoAux = strWriter();
    if(!apellidoAux)
    {
        printf("Error al soliciar memoria, la funcion no puede seguir\n");
        return;
    }
    corregir_nombre(apellidoAux);

    int eliminacion = eliminacion_por_apellido(base, *sz, apellidoAux);

    if (eliminacion == -1)
    {
        printf("Apellido no encontrado\n");
        return;
    }
    else if (eliminacion == 0)
    {
        for (int i = 0; i < *sz; i++)
        {
            if (!strcmp(base[i].apellido, apellidoAux))
            {
                printf("Eliminando datos de %s %s\n", base[i].nombre, base[i].apellido);
                free(base[i].nombre);
                free(base[i].apellido);

                reordenar(base, sz, i);
            }
        }
    }
    else
    {
        printf("Se encontraron mas de uno con ese apellido, ¿que desea hacer?\n");
        printf("0- Eliminar por legajo\n");
        printf("1- Eliminar todos con ese apellido\n");

        int opcionMultiple = 0;
        scanf("%d", &opcionMultiple);
        while (getchar() != '\n')
        {
        };
        if (!opcionMultiple)
        {
            uint32_t nLegajo = 0;
            printf("Ingrese el numero de legajo: ");
            scanf("%u", &nLegajo);

            for (int i = 0; i < (*sz); i++)
            {
                if ((nLegajo == (base[i].legajo)) && (nLegajo > 0))
                {
                    printf("Legajo encontrado\n");
                    printf("Eliminando datos de %s %s\n", base[i].nombre, base[i].apellido);
                    free(base[i].nombre);
                    free(base[i].apellido);

                    reordenar(base, sz, i);

                    return;
                }
            }
        }
        else
        {
            for (int i = 0; i < *sz; i++)
            {
                if (!strcmp(base[i].apellido, apellidoAux))
                {
                    free(base[i].nombre);
                    free(base[i].apellido);

                    reordenar(base, sz, i);
                    i--;
                }
            }
        }
    }
    free(apellidoAux);
}

void gestion_eliminacion_ambos(alumno_t *base, size_t *sz)
{
    char *nombreAux;
    char *apellidoAux;
    printf("Introduzca el nombre: ");
    nombreAux = strWriter();
    printf("Introduzca el apellido: ");
    apellidoAux = strWriter();

    if(!nombreAux)
    {
        printf("Error al soliciar memoria, la funcion no puede seguir\n");
        return;
    }
    if(!apellidoAux)
    {
        printf("Error al soliciar memoria, la funcion no puede seguir\n");
        return;
    }

    corregir_nombre(nombreAux);
    corregir_nombre(apellidoAux);

    int eliminacion = eliminacion_por_ambos(base, *sz, nombreAux, apellidoAux);

    if (eliminacion == -1)
    {
        printf("Nombre y apellido no encontrado\n");
        return;
    }
    else if (eliminacion == 0)
    {
        for (int i = 0; i < *sz; i++)
        {
            if (!strcmp(base[i].nombre, nombreAux) && !strcmp(base[i].apellido, apellidoAux))
            {
                printf("Eliminando datos de %s %s\n", base[i].nombre, base[i].apellido);
                free(base[i].nombre);
                free(base[i].apellido);

                reordenar(base, sz, i);
            }
        }
    }
    else
    {
        printf("Se encontraron mas de uno con ese apellido, ¿que desea hacer?\n");
        printf("0- Eliminar por legajo\n");
        printf("1- Eliminar todos con ese apellido\n");

        int opcionMultiple = 0;
        scanf("%d", &opcionMultiple);
        while (getchar() != '\n')
        {
        };
        if (!opcionMultiple)
        {
            uint32_t nLegajo = 0;
            printf("Ingrese el numero de legajo: ");
            scanf("%u", &nLegajo);

            for (int i = 0; i < (*sz); i++)
            {
                if ((nLegajo == (base[i].legajo)) && (nLegajo > 0))
                {
                    printf("Legajo encontrado\n");
                    printf("Eliminando datos de %s %s\n", base[i].nombre, base[i].apellido);
                    free(base[i].nombre);
                    free(base[i].apellido);

                    reordenar(base, sz, i);

                    return;
                }
            }
        }
        else
        {
            for (int i = 0; i < *sz; i++)
            {
                if (!strcmp(base[i].nombre, nombreAux) && !strcmp(base[i].apellido, apellidoAux))
                {
                    free(base[i].nombre);
                    free(base[i].apellido);

                    reordenar(base, sz, i);
                    i--;
                }
            }
        }
    }

    free(nombreAux);
    free(apellidoAux);
}

void gestion_eliminacion_legajo(alumno_t *base, size_t *sz)
{
    uint32_t nLegajo = 0;
    printf("Ingrese el numero de legajo: ");
    scanf("%u", &nLegajo);

    for (int i = 0; i < (*sz); i++)
    {
        if ((nLegajo == (base[i].legajo)) && (nLegajo > 0))
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