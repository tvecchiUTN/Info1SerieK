#ifndef __GESTION_H
#define __GESTION_H

#include <stdint.h>
typedef struct
{
    char *nombre;
    char *apellido;
    uint32_t legajo;
}alumno_t;

void ingreso_alumno(alumno_t *base, size_t *sz);

void modificar_alumno(alumno_t *base, size_t *sz);

void consultar_alumno(const alumno_t *base, size_t sz);

void eliminar_alumno(alumno_t *base, size_t *sz);

void reordenar(alumno_t *base, size_t *sz, size_t item);

#endif
