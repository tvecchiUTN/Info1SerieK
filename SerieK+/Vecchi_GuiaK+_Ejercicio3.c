//Guia K+
//Ejercicio 3
//Tomas Gabriel Vecchi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_BUFF 1000
char *getAllocNombre() {
  char *nombresFemeninos[] = {
      "María",     "Ana",      "Laura",     "Luisa",   "Sofía",    "Lucía",
      "Elena",     "Isabel",   "Carmen",    "Rosa",    "Patricia", "Teresa",
      "Raquel",    "Natalia",  "Julia",     "Andrea",  "Clara",    "Victoria",
      "Eva",       "Sara",     "Paula",     "Beatriz", "Monica",   "Olga",
      "Marta",     "Carolina", "Mónica",    "Silvia",  "Diana",    "Gloria",
      "Susana",    "Lorena",   "Yolanda",   "Adela",   "Lidia",    "Antonia",
      "Fabiola",   "Camila",   "Manuela",   "Eloisa",  "Rocio",    "Liliana",
      "Celia",     "Lourdes",  "Rosario",   "Elisa",   "Alicia",   "Clotilde",
      "Esperanza", "Milagros", "Constanza", "Renata",  "Gabriela", "Adriana",
      "Marina",    "Eugenia",  "Fernanda",  "Rita",    "Josefina"};
  char *nombresMaculinos[] = {
      "Néstor",    "Juan",      "Carlos",   "Luis",     "Pedro",     "José",
      "Miguel",    "Alejandro", "Javier",   "Fernando", "David",     "Manuel",
      "Antonio",   "Francisco", "Pablo",    "Jorge",    "Rafael",    "Diego",
      "Daniel",    "Roberto",   "Alberto",  "Santiago", "José Luis", "Andrés",
      "Ricardo",   "Lorenzo",   "Ángel",    "Víctor",   "Enrique",   "Héctor",
      "Guillermo", "Eduardo",   "Ignacio",  "Óscar",    "Emilio",    "Hugo",
      "Félix",     "Tomás",     "Marcos",   "Raúl",     "Felipe",    "Nicolás",
      "Armando",   "Rogelio",   "Alfredo",  "Gustavo",  "Samuel",    "Ernesto",
      "Rodrigo",   "Esteban",   "Sergio",   "Adrián",   "Abel",      "Benjamín",
      "Arturo",    "César",     "Leonardo", "Mariano",  "Mauricio"};
  char **s;
  char *sRet;
  int sz, i,cant;
  char sBuff[SIZE_BUFF];

  if (rand() % 2) {
    s = nombresFemeninos;
    sz = sizeof(nombresFemeninos) / sizeof(*nombresFemeninos);
  } else {
    s = nombresMaculinos;
    sz = sizeof(nombresMaculinos) / sizeof(*nombresMaculinos);
  }
  sBuff[0] = 0;
  cant = 1 + rand() % 4;
  for (i = 0; i < cant; i++) {
    strcat(sBuff, s[rand() % sz]);
    strcat(sBuff, " ");
  }
  sBuff[strlen(sBuff) - 1] = 0;
  sRet = (char *)malloc(SIZE_BUFF * sizeof(char));
  strcpy(sRet, sBuff);
  return sRet;
}

#define SIZE_TEST 10000
int main() {
  char **s;
  int i;
  //unsigned ejecuciones_DEBUG = 0;
  while (1) {
    s = (char **)malloc(SIZE_TEST * sizeof(char *));
    if (!s) {
      printf("Error de Memoria");
      return 1;
    }
    for (i = 0; i < SIZE_TEST; i++) {
      s[i] = getAllocNombre();
    }

    for (i = 0; i < SIZE_TEST; i++)
    {
      printf("%s\n", s[i]);
      free(s[i]);

    }
    free(s);
    /*
    ejecuciones_DEBUG++;

    if(ejecuciones_DEBUG > 1000)
    {
      break;
    }
    */
  }
  return 0;
}
