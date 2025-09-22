//Guia K
//Ejercicio 6
//Tomas Gabriel Vecchi

#include <stdio.h>
#include <stdlib.h>
#include "gestion.h"
#include "utils.h"

void eliminar_todo(alumno_t *base, size_t sz);

#define INGRESAR 1
#define MODIFICAR 2
#define CONSULTAR 3
#define ELIMINAR 4
#define SALIR 5

#define QTTY_MEMO_ALLOC 10

int main(void)
{
    alumno_t *baseDatos = NULL;

    size_t szBase = 0;
    size_t capacidad = 1;
    baseDatos = (alumno_t *)malloc(capacidad * sizeof(alumno_t)); //Inicializo con uno
    if(baseDatos == NULL)
    {
        printf("Error de memoria\n");
        return 1;
    }

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
        while(getchar() != '\n'){};

        switch(opcion)
        {
            case INGRESAR:
                if(capacidad == szBase)
                {
                    capacidad += QTTY_MEMO_ALLOC;
                    baseDatos = (alumno_t*)realloc(baseDatos, capacidad * sizeof(alumno_t));
                }
                if(baseDatos == NULL)
                {
                    printf("Error al solicitar memoria");

                    //opcion = SALIR;
                }
                else
                {
                    ingreso_alumno(baseDatos, &szBase);
                }
                
            break;
            
            case MODIFICAR:
                modificar_alumno(baseDatos, &szBase);
            break;
            
            case CONSULTAR:
                consultar_alumno(baseDatos, szBase);
            break;

            case ELIMINAR:
                eliminar_alumno(baseDatos, &szBase);
                if((capacidad - szBase) > 20)
                {
                    capacidad = szBase;
                    baseDatos = (alumno_t*)realloc(baseDatos, szBase * sizeof(alumno_t));
                    if(baseDatos == NULL)
                    {
                        printf("Error al solicitar memoria\n");
                        //opcion = SALIR;
                    }
                }
            break;

            case SALIR:
                printf("Saliendo...\n");
            break;

            default:
                printf("Numero fuera de parametro, ingrese de nuevo\n");
            break;
        }
    }
    eliminar_todo(baseDatos, szBase);
    return 0;
}

void eliminar_todo(alumno_t *base, size_t sz)
{
    for(int i = 0; i < sz; i++)
    {
        if(base[i].legajo != 0)
        {
            free(base[i].nombre);
            free(base[i].apellido);
        }
    }

    free(base);
}