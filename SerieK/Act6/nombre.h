//Guia K
//Ejercicio 6
//Tomas Gabriel Vecchi

#ifndef __NOMBRE_H
#define __NOMBRE_H

//Recordar liberar memoria al utilizar la funcion
char *strWriter(void);

void ingreso_nombre(alumno_t *base, size_t item);

int buscar_legajo(const alumno_t *base, size_t sz, uint32_t legBuscar);

int buscar_nombre(const alumno_t *base, size_t sz, char* strNombre, char* strApellido);

#endif