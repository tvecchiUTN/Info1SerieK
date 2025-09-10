#include <stdio.h>
#include <stdlib.h>
#include "gestion.h"
#include "utils.h"

#define INGRESAR 1
#define MODIFICAR 2
#define CONSULTAR 3
#define ELIMINAR 4
#define SALIR 5

#define INICIAL 100

int main(void)
{
    alumno_t *baseDatos = NULL;

    baseDatos = (alumno_t *)malloc(INICIAL * sizeof(alumno_t));
    size_t szBase = 0;

    int opcion = 0;
    while (opcion != SALIR)
    {
        printf("1- Ingresar datos de alumno.\n");
        printf("2- Modificar datos de alumno.\n");
        printf("3- Consultar datos de alumno.\n");
        printf("4- Eliminar datos de alumno.\n");
        printf("5- Salir.\n");

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case INGRESAR:
                ingreso_alumno(baseDatos, &szBase);
            break;
            
            case MODIFICAR:
                modificar_alumno(baseDatos, &szBase);
            break;
            
            case CONSULTAR:
                consultar_alumno(baseDatos, &szBase);
            break;

            case ELIMINAR:
                eliminar_alumno(baseDatos, &szBase);
            break;

            case SALIR:
                printf("Saliendo...\n");
            break;

            default:
                printf("Numero fuera de parametro, ingrese de nuevo\n");
            break;
        }
    }
    free(baseDatos);

    return 0;
}