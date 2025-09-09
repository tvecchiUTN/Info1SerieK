#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int len, size;
  char *str;
} data_t;

int setData(data_t *pd, char *str);
int addData(data_t *pd, char *str);
void freeData(const data_t *pd);

int main() {
  data_t db = {0, 0, NULL};
  data_t da;
  int aux = 0;

  aux = setData(&da, "Buenos días,\n");
  aux += addData(&da, "Este es un codigo que presenta algunos problemas.");
  aux += addData(&da, "Te animas a encontrarlos y corregirlos.\n");
  aux += addData(&da, "Quizas debas replantear parte de la solución.\n");
  if (aux != 4) {
    fprintf(stdout, "Error de memoria. Chau!!\n");
    return 1;
  }

  fprintf(stdout, "-----------------------------\n");
  fprintf(stdout, ":--> %s\n", da.str);
  fprintf(stdout, "-----------------------------\n");

  aux = 0;
  aux = addData( &db, "Bien, en este caso estamos iniciando con un addData en form directa\n");
  aux += addData(&db, "Podemos hacer esto?.\n");
  aux += addData(&db, "Parecería que si, pues esto no se cuelga, por lo que debería estar bien.\n");
  aux += addData(&db, "Si. parece que esta perfecto!!!.\n");
  if (aux != 4) {
    fprintf(stdout, "Error de memoria. Chau!!\n");
	  free(da.str);
    return 1;
  }
  fprintf(stdout, ":--> %s\n", db.str);
  fprintf(stdout, "-----------------------------\n");
  aux = setData(&da, "Estamos llegando al final de codigo,\n");
  aux += addData(&da, "Quien dijo que este codigo presenta algunos problemas.");
  aux += addData(&da, "Por lo que veo anda perfecto.\n");
  aux += addData(&da, "o quizás no? tendra eso que le llaman \"vicios ocultos\".\n");
  if (aux != 4) {
    fprintf(stdout, "Error de memoria. Chau!!\n");
    return 1;
  }
  fprintf(stdout, ":--> %s\n", da.str);
  fprintf(stdout, "-----------------------------\n");

  freeData(&da);
  freeData(&db);
  return 0;
}

#define SIZE_BLOCK 64
int setData(data_t *pd, char *str) {
  int aux = strlen(str) + 1;
  aux = SIZE_BLOCK * ((aux / SIZE_BLOCK) + 1);

  if ((pd->str = (char *)malloc(aux * sizeof(char)))) {
    strcpy(pd->str, str);
    pd->len = strlen(str);
    pd->size = aux;
    return 1;
  }
  return 0;
}

int addData(data_t *pd, char *str) {
  int lx = strlen(str);
  int sz;
  if (pd->size > pd->len + lx) {
    strcat(pd->str, str);
    pd->len += lx;
    return 1;
  }

  sz = pd->len + lx;
  sz = SIZE_BLOCK * ((sz / SIZE_BLOCK) + 1);
  if ((pd->str = (char *)realloc(pd->str, sz * sizeof(char)))) {
    strcat(pd->str, str);
    pd->len += lx;
    pd->size = sz;
    return 1;
  }
  return 0;
}

void freeData(const data_t *pd) { free(pd->str); }
