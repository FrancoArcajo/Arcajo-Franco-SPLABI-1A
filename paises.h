
#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED
#include "LinkedList.h"

typedef struct{
    int id;
    char nombre[25];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
}ePais;


ePais* newPais();

ePais* newpaisParam(char* idStr, char* nombreStr, char* vac1dosisStr, char* vac2dosisStr, char* sinVacunarStr);

int mostrarPais(ePais * this);

void deletePais(ePais* this);

int pais_getId(ePais* this, int * id);

int pais_getNombre(ePais* this, char * nombre);

int pais_getVac1dosis(ePais* this, int * vac1dosis);

int pais_getVac2dosis(ePais* this, int * vac2dosis);

int pais_getSinVacunar(ePais* this, int * sinVacunar);

int pais_setId(ePais* this, int id);

int pais_setNombre(ePais* this, char* nombre);

int pais_setVac1dosis(ePais* this, int vac1dosis);

int pais_setVac2dosis(ePais* this,int vac2dosis);

int pais_setSinVacunar(ePais* this,int sinVacunar);

void* setValoresRandom(void* auxP);

int filterPaisesEnElHorno(void* auxP);

int filterPaisesExitosos(void* auxP);

int compareVac1dosis(void* auxP1,void* auxP2);

int compareSinVacunar(void* auxP1,void* auxP2);
#endif // PAISES_H_INCLUDED
