
#ifndef PARSERS_H_INCLUDED
#define PARSERS_H_INCLUDED

#include "LinkedList.h"
#include "paises.h"

/** \brief Parsea los datos los datos de los paises desde el archivo vacunas.csv (modo texto).
 *
 * \param path del archivo a cargar
 * \param LinkedList
 * \return 1 en caso de error, o 0 en caso de exito
 *
 */

int parser_FromText(FILE* pFile , LinkedList* pLinkedList);


#endif // PARSERS_H_INCLUDED

