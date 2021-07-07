#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

int utn_getCadena(char *pAux, int limit, int reintentos, char* mensaje, char* mensajeError)
{
	int todoOk = -1;
    char auxString[limit];

    if(pAux != NULL && mensaje != NULL && mensajeError != NULL && limit > 0 && reintentos >= 0)
    {
        do
        {
        	printf("%s", mensaje);

            if(getCadena(auxString, limit) == 0 && isChar(auxString) == 0)
            {
                strncpy(pAux, auxString, limit);
                todoOk = 0;
                break;
            }
            else
            {
            	printf("%s", mensajeError);
            }
            reintentos--;

        }while(reintentos>=0);
    }
    return todoOk;
}

int getCadena(char* pAux, int limit)
{
    char auxString[4000];
    int todoOk = -1;

    if (pAux != NULL && limit > 0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limit)
        {
            strncpy(pAux, auxString, limit);
            todoOk = 0;
        }
    }
    return todoOk;
}

int isChar(char str[])
{
	int todoOk = 0;

	for(int i = 0; str[i] != '\0'; i++)
	{
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			todoOk = -1;
		}
	}
	return todoOk;
}

int utn_getFlotante(float* pFloat, int reintentos, char* mensaje, char* mensajeError, float minimo, float maximo)
{
    int todoOk = -1;
    float auxFloat;

    if(pFloat != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",mensaje);

            if(getFloat(&auxFloat) == 0 && auxFloat >= minimo && auxFloat <= maximo)
            {
                *pFloat= auxFloat;
                todoOk = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}

int getFloat(float*pAux)
{
    char auxString[200];
    int todoOk = -1;

    if(getCadena(auxString,200) == 0 && isFloat(auxString) == 0)
    {
        *pAux = atof(auxString);
        todoOk = 0;
    }
    return todoOk;
}

int isFloat(char* pAux)
{
    int todoOk = -1;
    int i = 0;
    int contador = 0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) == '.')
        {
            contador++;
            if(contador == 2)
            {
                break;
            }
        }
        else if(*(pAux + i) < '0'|| *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
        todoOk = 0;
    }
    return todoOk;
}

int utn_getEntero(int* pEntero, int reintentos, char* mensaje, char* mensajeError, int minimo, int maximo)
{
    int todoOk = -1;
    int auxInt;

    if(pEntero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s", mensaje);

            if(getInt(&auxInt) == 0 && auxInt >= minimo && auxInt <= maximo)
            {
                *pEntero = auxInt;
                todoOk = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}

int getInt(int* pAux)
{
    char auxString[400];
    int todoOk = -1;

    if(getCadena(auxString, sizeof(auxString)) == 0 && isInt(auxString ) == 0)
    {
        *pAux = atoi(auxString);
        todoOk = 0;
    }
    return todoOk;
}

int isInt(char *pAux)
{
    int todoOk = -1;
    int i = 0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) < '0' || *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
        todoOk = 0;
    }

    return todoOk;
}

int strLwr(char* str)
{
	int todoOk = -1;
	int i = 0;

	if(str != NULL)
	{
		while(str[i] != '\0')
		{
			str[i] = tolower(str[i]);
			i++;
		}
		todoOk = 0;
	}
	return todoOk;
}

int normalizeStr(char* str)
{
	int todoOk = -1;
	int i = 0;

	if(str != NULL)
	{
		strLwr(str);
		str[0] = toupper(str[0]);

		while(str[i] != '\0')
		{
			if(str[i] == ' ')
			{
				str[i + 1] = toupper(str[i + 1]);
				todoOk = 0;
			}
			i++;
		}
	}
	return todoOk;
}

int isValidName(char* cadena, int tam)
{
	int todoOk = 1;

	if(cadena != NULL && tam > 0)
	{
		for(int i = 0; cadena[i] != '\0' && i < tam; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
			{
				todoOk = 0;
				break;
			}
		}
	}
	return todoOk;
}

int isNumeric(char* cadena, int tam)
{
	int todoOk = -1;

	if(cadena != NULL && tam > 0)
	{
		todoOk = 0;
		for(int i = 0; i < tam && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				break;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				todoOk = 0;
				break;
			}
		}
	}
	return todoOk;
}

int menuOpciones()
{
    int opcion;
    system("cls");
	printf("***MENU PRINCIPAL***\n\n");
    printf("1. Cargar archivo\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar estadisticas\n");
    printf("4. Filtrar por paises exitosos\n");
    printf("5. Filtrar por paises en el horno\n");
    printf("6. Ordenar por nivel de vacunacion\n");
    printf("7. Mostrar mas castigado\n");
    printf("8. Salir\n\n");

	utn_getEntero(&opcion, 7, "Ingrese opcion: ", "Error, opcion invalida\n", 1, 8);

	return opcion;
}

int getPath(char* path, int maxLen)
{
    int retorno = 0;
    char aux[maxLen + 5];
    if(path!=NULL && maxLen > 0 && maxLen < maxLen + 5)
    {
        printf("Ingrese path: ");
        fflush(stdin);
        fgets(aux,maxLen+5,stdin);
        while(strlen(aux) > maxLen)
        {
            printf("El maximo numero de caracteres permitidos es %d. Reingrese nombre: ",maxLen);
            fflush(stdin);
            fgets(aux,maxLen+5,stdin);
        }
        aux[strlen(aux)-1]='\0';
        strcpy(path, aux);
        retorno=1;
    }
    return retorno;
}
