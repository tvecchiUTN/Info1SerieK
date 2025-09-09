#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int code, cant;
  char *desc;
} data_t;

int setData(data_t *pd, int cod, int qtt, char *str);
void prtData(const data_t *pd);
void freeData(const data_t *pd);

int main() {
  data_t da, db, dc;

  setData(&da, 2456, 365, "Colector de base abstracta");
  setData(&db, 0056, 126, "Bromuro de sustrato metalico A o B (56:A / 57:B)");

  if (!da.desc || !db.desc) {
    fprintf(stdout, "Error grave de memoria\n");
    fprintf(stdout, "La aplicación finaliza\n");
    return 1;
  }

  dc = db;
  dc.code++;
  dc.cant++;

  fprintf(stdout, "-----------------------------\n");

  prtData(&da);
  prtData(&db);
  prtData(&dc);

  fprintf(stdout, "-----------------------------\n");

  freeData(&da);
  freeData(&db);
  //freeData(&dc); Este es el unico error que se encuentra en el presente codigo
  //Esto es debido a que ya se libero "desc" en freeData(&db)
  return 0;
}

int setData(data_t *pd, int cod, int qtt, char *str) {
  int aux = strlen(str) + 1;
  pd->code = cod;
  pd->cant = qtt;

  if ((pd->desc = (char *)malloc(aux * sizeof(char)))) {
    strcpy(pd->desc, str);
    return 1;
  }
  return 0;
}

void prtData(const data_t *pd) {
  fprintf(stdout, "code: %5d | cant: %4d ", pd->code, pd->cant);
  fprintf(stdout, "| %s\n", pd->desc);
}

void freeData(const data_t *pd) { free(pd->desc); }
