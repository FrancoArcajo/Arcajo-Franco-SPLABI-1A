#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getCadena(char *pAux, int limit, int reintentos, char* mensaje, char* mensajeError);

int getCadena(char* pAux, int limit);

int isChar(char str[]);

int utn_getFlotante(float* pFloat, int reintentos, char* mensaje, char*mensajeError, float minimo, float maximo);

int getFloat(float*pAux);

int isFloat(char* pAux);

int utn_getEntero(int* pEntero, int reintentos, char* mensaje, char* mensajeError, int minimo, int maximo);

int getInt(int* pAux);

int isInt(char *pAux);

int strLwr(char* str);

int normalizeStr(char* str);

int isValidName(char* cadena, int tam);

int isNumeric(char* cadena, int tam);

int menuOpciones();

int getOption(int min, int max);

int getPath(char *path, int maxLen);

#endif // UTN_H_INCLUDED
