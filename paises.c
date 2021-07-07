#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "paises.h"

ePais* newPais()
{
    ePais* newPais = (ePais*) malloc(sizeof(ePais));
    if (newPais != NULL)
    {
        newPais->id=0;
        strcpy(newPais->nombre,"");
        newPais->vac1dosis=0;
        newPais->vac2dosis=0;
        newPais->sinVacunar=0;

    }
    return newPais;
}

ePais* newpaisParam(char* idStr, char* nombreStr, char* vac1dosisStr, char* vac2dosisStr, char* sinVacunarStr)
{
    ePais* pais = newPais();

    if (pais != NULL)
    {
        pais_setId(pais, atoi(idStr));
        pais_setNombre(pais, nombreStr);
        pais_setVac1dosis(pais, atoi(vac1dosisStr));
        pais_setVac2dosis(pais, atoi(vac2dosisStr));
        pais_setSinVacunar(pais, atoi(sinVacunarStr));
    }
    else
    {
        free(pais);
        pais = NULL;
    }
    return pais;
}

void deletePais(ePais* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int mostrarPais(ePais * this)
{
    int error = 0;
    int id;
    char nombre[25];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;

    if(this != NULL)
    {
        pais_getId(this,&id);
        pais_getNombre(this,nombre);
        pais_getVac1dosis(this,&vac1dosis);
        pais_getVac2dosis(this,&vac2dosis);
        pais_getSinVacunar(this,&sinVacunar);
        printf(" %4d  %20s        %7d %%      %7d %%       %7d %%\n", id, nombre, vac1dosis, vac2dosis, sinVacunar);
        error = 1;
    }
    return error;
}

int pais_setId(ePais* this, int id)
{
    int retorno=0;
    if(this != NULL && id > 0)
    {
        this->id=id;
        retorno=1;
    }
    return retorno;
}


int pais_getId(ePais* this,int* id)
{
    int retorno=0;
    if( this != NULL && id != NULL)
    {
        *id = this->id;
        retorno=1;
    }
    return retorno;
}

int pais_setNombre(ePais* this, char* nombre)
{
    int retorno=0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno=1;
    }
    return retorno;
}

int pais_getNombre(ePais* this, char* nombre)
{
    int retorno=0;
    if( this != NULL && nombre!=NULL )
    {
        strcpy(nombre, this->nombre);
        retorno=1;
    }
    return retorno;
}

int pais_setVac1dosis(ePais* this, int vac1dosis)
{
    int retorno = 0;
    if(this != NULL && vac1dosis >=0 )
    {
        this->vac1dosis=vac1dosis;
        retorno=1;
    }
    return retorno;
}

int pais_getVac1dosis(ePais* this, int* vac1dosis)
{
    int retorno=0;
    if(this != NULL)
    {
        *vac1dosis = this->vac1dosis;
        retorno=1;
    }
    return retorno;
}

int pais_setVac2dosis(ePais* this, int vac2dosis)
{
    int retorno=0;
    if(this != NULL && vac2dosis >= 0)
    {
        this->vac2dosis = vac2dosis;
        retorno=1;
    }
    return retorno;
}

int pais_getVac2dosis(ePais* this, int* vac2dosis)
{
    int retorno=0;
    if( this != NULL && vac2dosis != NULL)
    {
        *vac2dosis = this->vac2dosis;
        retorno=1;
    }
    return retorno;
}

int pais_setSinVacunar(ePais* this, int sinVacunar)
{
    int retorno=0;
    if(this != NULL && sinVacunar >= 0)
    {
        this->sinVacunar = sinVacunar;
        retorno=1;
    }
    return retorno;
}

int pais_getSinVacunar(ePais* this, int* sinVacunar)
{
    int retorno=0;
    if( this != NULL && sinVacunar != NULL)
    {
        *sinVacunar = this->sinVacunar;
        retorno=1;
    }
    return retorno;
}

void* setValoresRandom(void* auxP)
{
    ePais* pPais = NULL;
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;

    pPais = (ePais*) auxP;

    if( pPais != NULL)
    {
        vac1dosis = rand()%(100-0+1)+0;
        vac2dosis = rand()%((100-vac1dosis)-0+1)+0;
        sinVacunar = 100-(vac1dosis+vac2dosis);

        pPais-> vac1dosis = vac1dosis;
        pPais-> vac2dosis = vac2dosis;
        pPais-> sinVacunar = sinVacunar;

    }
    return pPais;
}

int filterPaisesExitosos(void* auxP)
{
    int vac2dosis;
    int error = 0;
    ePais* pPais = NULL;
    pPais = (ePais*) auxP;

    if(pPais != NULL)
    {
        pais_getVac2dosis(pPais,&vac2dosis);
        if(vac2dosis > 30)
        {
            error = 1;
        }
    }
    return error;
}

int filterPaisesEnElHorno(void* auxP)
{
    int sinVacunar;
    int vac1dosis;
    int vac2dosis;
    int vacunados;

    int error = 0;
    ePais* pais = (ePais*) auxP;

    if(pais != NULL)
    {
        pais_getSinVacunar(pais,&sinVacunar);
        pais_getVac1dosis(pais,&vac1dosis);
        pais_getVac2dosis(pais,&vac2dosis);
        vacunados = vac1dosis + vac2dosis;

        if(vacunados < sinVacunar)
        {
            error = 1;
        }
    }
    return error;
}

int compareVac1dosis(void* auxP1,void* auxP2)
{
    int error = 0;
    ePais * pPais1 = (ePais*) auxP1;
    ePais * pPais2 = (ePais*) auxP2;

    if( pPais1 != NULL && pPais2 != NULL)
    {
        if(pPais1->vac1dosis > pPais2->vac1dosis)
        {
            error = 1;
        }
        else if(pPais1->vac1dosis < pPais2->vac1dosis)
        {
            error = -1;
        }
    }
    return error;
}

int compareSinVacunar(void* auxP1,void* auxP2)
{
    int error = 0;
    ePais * pPais1 = (ePais*) auxP1;
    ePais * pPais2 = (ePais*) auxP2;

    if( pPais1 != NULL && pPais2 != NULL)
    {
        if(pPais1->sinVacunar > pPais2->sinVacunar)
        {
            error = 1;
        }
        else if(pPais1->sinVacunar < pPais2->sinVacunar)
        {
            error = -1;
        }
    }
    return error;
}
