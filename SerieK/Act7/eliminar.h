#ifndef __ELIMINAR_H
#define __ELIMINAR_H

//-1 no encontro, 0 si es uno solo y 1 si es muchos
int eliminacion_por_nombre(const alumno_t *base, size_t sz, char* nombre);

//-1 no encontro, 0 si es uno solo y 1 si es muchos
int eliminacion_por_apellido(const alumno_t *base, size_t sz, char* apellido);

//-1 no encontro, 0 si es uno solo y 1 si es muchos
int eliminacion_por_ambos(const alumno_t *base, size_t sz, char* nombre, char* apellido);

void gestion_eliminacion_nombre(alumno_t *base, size_t *sz);
void gestion_eliminacion_apellido(alumno_t *base, size_t *sz);
void gestion_eliminacion_ambos(alumno_t *base, size_t *sz);
void gestion_eliminacion_legajo(alumno_t *base, size_t *sz);

#endif