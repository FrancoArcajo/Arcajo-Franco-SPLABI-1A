#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "controller.h"
#include "utn.h"
#include "paises.h"

int main()
{
    srand(time(NULL));
    char path[20];
    char salir;
    int flagArch = 1;
    int flagEstado = 1;

    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaFiltrada = NULL;

    if(lista == NULL)
    {
        printf("ERROR: No se pudo crear la lista\n");
        exit(EXIT_FAILURE);
    }
    do
    {
        switch(menuOpciones())
        {
        case 1:
            if(flagArch)
            {
                getPath(path,20);
                if(controller_loadFromText(path,lista))
                {
                    printf("\nCarga de datos exitosa\n\n");
                    flagArch = 0;
                }
                else
                {
                    printf("\nERROR: Ha ocurrido un error al cargar el archivo\n\n");
                }
            }
            else
            {
                printf("ERROR: Ya se ha cargado un archivo\n\n");
            }
            break;

        case 2:
            if(!flagArch)
            {
                controller_List(lista);
            }
            else
            {
                printf("ERROR: Primero debe cargar el archivo\n\n");
            }
            break;

        case 3:
            if(!flagArch)
            {
                lista = ll_map(lista,setValoresRandom);

                if(lista != NULL)
                {
                    controller_List(lista);
                    flagEstado = 0;
                }
            }
            else
            {
                printf("ERROR: Primero debe cargar el archivo\n\n");
            }
            break;

        case 4:
            if(!flagArch && !flagEstado)
            {
                listaFiltrada = controller_filterPaisesExitosos(lista);
                if(listaFiltrada != NULL)
                {
                    printf("* La lista se ha guardado en paisesExitosos.csv\n\n");
                }
                else
                {
                    printf("ERROR: Ha ocurrido un error al guardar los datos\n\n");
                }
            }
            else
            {
                printf("ERROR: Primero debe cargar el archivo y asignar las estadisticas\n\n");
            }
            break;

        case 5:
            if(!flagArch && !flagEstado)
            {
                listaFiltrada = controller_filterPaisesHorno(lista);
                if(listaFiltrada != NULL)
                {
                    printf("* La lista se ha guardado en paisesEnElHorno.csv\n\n");
                }
                else
                {
                    printf("ERROR: Ha ocurrido un error al guardar los datos\n\n");
                }
            }
            else
            {
                printf("ERROR: Primero debe cargar el archivo y asignar las estadisticas\n\n");
            }
            break;

        case 6:
            if(!flagArch && !flagEstado)
            {
                if(!ll_sort(lista,compareVac1dosis,0))
                {
                    printf("La lista se ha ordenado exitosamente\n\n");
                }
                else
                {
                    printf("ERROR: Ha ocurrido un problema al ordenar la lista\n\n");
                }
            }
            else
            {
                printf("ERROR: Primero debe cargar el archivo y asignar las estadisticas\n\n");
            }
            break;

        case 7:
            if(!flagArch && !flagEstado)
            {
                printf("Pais o paises mas castigados:\n");
                if(!controller_paisesMasCastigados(lista))
                {
                    printf("ERROR: Ha ocurrido un problema al calcular los datos\n\n");
                }
            }
            else
            {
                printf("ERROR: Primero debe cargar el archivo y asignar las estadisticas\n\n");
            }
            break;

        case 8:
            printf("Seguro que desea salir?\n");
            fflush(stdin);
            salir = getchar();
            printf("\n");
            if(salir == 's')
            {
                ll_deleteLinkedList(lista);
                ll_deleteLinkedList(listaFiltrada);
                printf("Programa cerrado\n\n");
            }
            break;
        }
        system("pause");
    }
    while(salir != 's');

    return 0;
}
