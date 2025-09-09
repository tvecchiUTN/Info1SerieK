#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

#define MAXLEG 8
#define SZMAX 100
#define DEBUG 0

int main(void)
{
    char* nomAlum[SZMAX];
    char* apeAlum[SZMAX];
    int legAlum[SZMAX];

    int ingresAlum = 0;
    int ingresApe = 0;
    int ingresLeg = 0;

    int posLeg = 0;
    while(1)
    {
        printf("Ingrese la opcion: \n");
        printf("1- Ingreso de datos del alumno\n");
        printf("2- Consultar datos del alumno\n");
        printf("3- Eliminacion de datos del alumno\n");
        printf("4- Salir\n");

        printf("----------------------------------------------------------------------------------------------------\n");
        int opc = 4;
        scanf("%d", &opc);
        while (getchar() != '\n');

        switch(opc)
        {
            case 1:
                printf("Estas ingresando datos del alumno\n");

                printf("Ingrese nombre del alumno: ");
                char* nombre = malloc(MAXCARAC * sizeof(char));

                if(nombre == NULL)
                {
                    printf("ERROR al solicitar memoria");
                    break;
                }

                int szNombre = 0;
                while(1)
                {
                    fgets(nombre, MAXCARAC, stdin);

                    szNombre = szStr(nombre);

                    if(szNombre > MAXCARAC-30)
                    {
                        printf("Nombre muy largo, reduzcalo");
                    }else
                    {
                        break;
                    }

                }
                nombre = realloc(nombre, szNombre * sizeof(char));

                *(nomAlum+ingresAlum) = nombre;
                ingresAlum++;

                //Seccion de Apellido
                printf("Ingrese apellido del alumno: ");
                char* apellido = malloc(MAXCARAC * sizeof(char));

                if(apellido == NULL)
                {
                    printf("ERROR al solicitar memoria");
                    break;
                }
                int szApellido = 0;
                while(1)
                {
                    fgets(apellido, MAXCARAC, stdin);

                    szApellido = szStr(apellido);

                    if(szApellido > MAXCARAC-30)
                    {
                        printf("Apellido muy largo, reduzcalo");
                    }else
                    {
                        break;
                    }

                }
                apellido = realloc(apellido, szApellido * sizeof(char));

                *(apeAlum+ingresApe) = apellido;
                ingresApe++;

				printf("Ingrese numero de legajo: ");
				int legajo = 0;
				scanf("%d",&legajo);

				*(legAlum+ingresLeg) = legajo;
				ingresLeg++;

                break;
            case 2:
                printf("Estas consultando datos del alumno\n");

                printf("Ingrese numero de legajo: ");
                int legajoBuscar = 0;
                scanf("%d", &legajoBuscar);

                posLeg = srchLeg(legajoBuscar, legAlum);

                if(posLeg == -1)
                {
                    printf("Datos no encontrados\n");
                }else
                {
                    printf("Nombre: %s\n", *(nomAlum+posLeg));
                    printf("Apellido: %s\n", *(apeAlum+posLeg));
                    printf("Legajo: %d\n", *(legAlum+posLeg));
                }

                break;
            case 3:
                printf("Estas eliminando datos del alumno\n");

                printf("Ingrese numero de legajo: ");
                int legajoEliminar = 0;
                scanf("%d", &legajoEliminar);

                posLeg = srchLeg(legajoEliminar, legAlum);

                if(posLeg != -1)
                {
                    printf("Eliminando legajo %d de la posicion %d\n", legajoEliminar, posLeg);
                    free(*(nomAlum+posLeg));
                    *(nomAlum+posLeg) = 0;
                    free(*(apeAlum+posLeg));
                    *(apeAlum+posLeg) = 0;

                    *(legAlum+posLeg) = 0;
                }
                else
                {
                    printf("Ese N de legajo ingresado no existe\n");
                }

                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Dato ingresado erroneo, ingrese de nuevo\n");
                break;
        }

        if(opc == 4)
        {
            break;
        }

    }

}
