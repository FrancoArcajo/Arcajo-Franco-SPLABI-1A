#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "LinkedList.h"
#include "paises.h"
#include "parsers.h"

int controller_loadFromText(char* path , LinkedList* pLinkedList);

int controller_List(LinkedList* pLinkedList);

LinkedList* controller_asignarEstadisticas(LinkedList* pLinkedList);

int controller_saveAsText(char* path , LinkedList* pLinkedList);

LinkedList* controller_filterPaisesExitosos(LinkedList* pLinkedList);

LinkedList* controller_filterPaisesHorno(LinkedList* pLinkedList);

int controller_paisesMasCastigados(LinkedList* pLinkedList);
#endif // CONTROLLER_H_INCLUDED
