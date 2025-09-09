#ifndef __GESTION_H
#define __GESTION_H

#include <stdint.h>

#define MAX_NOMBRE 80

typedef struct
{
    char *nombre;
    char *apellido;
    uint32_t legajo;
}alumno_t;

#endif
