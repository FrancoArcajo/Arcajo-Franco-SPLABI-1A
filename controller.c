#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "controller.h"

int controller_loadFromText(char* path, LinkedList* pLinkedList)
{
    int error = 0;

    if(pLinkedList != NULL)
    {
        FILE* f = fopen(path, "r");
        if(f != NULL)
        {
            if(parser_FromText(f, pLinkedList))
            {
                error = 1;
            }
        }
        fclose(f);
    }
    return error;
}


int controller_List(LinkedList* pLinkedList)
{
    int error = 0;
    ePais* auxPais = NULL;
    int tam = ll_len(pLinkedList);

    printf("   ID             NOMBRE             VAC1 DOSIS        VAC2 DOSIS      SIN VACUNAR\n\n");
    if(pLinkedList != NULL )
    {
        if(tam > 0)
        {
            for(int i = 0; i < tam; i++)
            {
                auxPais = ll_get(pLinkedList,i);
                mostrarPais(auxPais);
            }
            printf("\n\n");
        }
        else
        {
            printf("No hay elementos para mostrar\n\n");
        }
        error = 1;
    }
    return error;
}


int controller_saveAsText(char* path, LinkedList* pLinkedList)
{
    int error = 0;
    int tam;
    int cantidad;
    ePais * auxPais = NULL;

    FILE* f = fopen(path, "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        if(pLinkedList != NULL)
        {
            tam = ll_len(pLinkedList);
            for(int i = 0; i < tam; i++)
            {
                auxPais = ll_get(pLinkedList, i);
                if(auxPais != NULL)
                {
                    cantidad = fprintf(f,"%d, %s, %d, %d, %d\n",auxPais->id, auxPais->nombre, auxPais->vac1dosis, auxPais->vac2dosis, auxPais->sinVacunar);
                    if(cantidad < 4)
                    {
                        break;
                    }
                }
                error = 1;
            }
        }
    }
    fclose(f);
    return error;
}

LinkedList* controller_filterPaisesExitosos(LinkedList * pLinkedList)
{
    LinkedList* listaFiltrada = NULL;

    if(pLinkedList != NULL)
    {
        listaFiltrada = ll_filter(pLinkedList,filterPaisesExitosos);
        if(listaFiltrada != NULL)
        {
            controller_List(listaFiltrada);
            if(!controller_saveAsText("paisesExitosos.csv",listaFiltrada))
            {
                ll_deleteLinkedList(listaFiltrada);
            }
        }
    }
    return listaFiltrada;
}

LinkedList* controller_filterPaisesHorno(LinkedList * pLinkedList)
{
    LinkedList* listaFiltrada = NULL;

    if(pLinkedList != NULL)
    {
        listaFiltrada = ll_filter(pLinkedList,filterPaisesEnElHorno);
        if(listaFiltrada != NULL)
        {
            controller_List(listaFiltrada);
            if(!controller_saveAsText("paisesHorno.csv",listaFiltrada))
            {
                ll_deleteLinkedList(listaFiltrada);
            }
        }
    }
    return listaFiltrada;
}


int controller_paisesMasCastigados(LinkedList * pLinkedList)
{
    int error = 0;
    ePais * auxPais = NULL;
    int menorVacunados = 0;

    if(pLinkedList != NULL)
    {
        if(!ll_sort(pLinkedList,compareSinVacunar,0))
        {
            auxPais = ll_get(pLinkedList,0);

            pais_getSinVacunar(auxPais, &menorVacunados);
            for(int i = 0; i < ll_len(pLinkedList); i++)
            {
                auxPais = ll_get(pLinkedList,i);
                if(auxPais->sinVacunar == menorVacunados)
                {
                    printf(" - %s   %d %% de la poblacion sin vacunar\n\n", auxPais->nombre, auxPais->sinVacunar);
                }
            }
        }
        error = 1;
    }
    return error;
}
