/*
 * input.h
 *
 *  Created on: 21 abr. 2022
 *      Author: Nahuel A
 */

#ifndef INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define INPUT_H_

int getInt(char mensaje[]);
char getString(char mensaje[]);
void getVector(int numeros[], int size);
char getChar(char mensaje[]);
int confirmChange(char mensaje[]);
int myGets(char* cadena, int longitud);
void validar(char []);
int esEnteroValido(char cadena[]);
int esFlotanteValido(char *cadena);
int validacionCadena(char cadena[]);

#endif /* INPUT_H_ */
