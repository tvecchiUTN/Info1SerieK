//Guia K
//Ejercicio 1
//Tomas Gabriel VECCHI

#ifndef __NOMBRE_H
#define __NOMBRE_H

void ingreso_nombre(alumno_t *base, size_t item);

int buscar_legajo(const alumno_t *base, size_t sz, uint32_t legBuscar);

int buscar_nombre(const alumno_t *base, size_t sz, char* strNombre, char* strApellido);

#endif