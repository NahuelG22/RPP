#include "input.h"

int getInt(char mensaje[])
{
    int entero;
	printf("%s",mensaje);
	scanf("%d", &entero);
    return entero;
}

char getChar(char mensaje[])
{
    char caracter;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&caracter);
    return caracter;
}

void getVector(int numeros[], int size)
{
	for(int i=0; i<size; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &numeros[i]);
	}
}

//int confirmChange(char mensaje[])
//{
//	char confirmar;
//
//	confirmar=-1;
//
//	printf("%s", mensaje);
//	fflush(stdin);
//	gets(confirmar);
//
//	if(confirmar=="Si")
//	{
//		confirmar=0;
//	}
//
//	return confirmar;
//}


//void validar(char num[])
//{
//    for(int i=0; i<strlen(num); i++)
//    {
//        if(!isdigit(num[i]))
//        {
//            printf("Ingrese un numero valido");
//            break;
//        }
//    }
//}


//int esFlotanteValido(char *cadena)
//{
//    int longitud = strlen(cadena);
//    // Quitar espacios, saltos de línea, etcétera
//    while (longitud > 0 && isspace(cadena[longitud - 1]))
//        longitud--;
//    if (longitud <= 0) return 0;
//    int i;
//    int haEncontradoElPunto = 0;
//    for (i = 0; i < longitud; ++i)
//    {
//        // En caso de que sea un guión, y que no esté al inicio, no es válido
//        if (cadena[i] == '-' && i > 0)
//        {
//            return 0;
//        }
//        // El punto solo puede aparecer una vez
//        if (cadena[i] == '.')
//        {
//            // Si ya lo ha encontrado antes, entonces no es válido
//            if (haEncontradoElPunto)
//            {
//                return 0;
//            }
//            else
//            {
//
//                haEncontradoElPunto = 1;
//            }
//        }
//        // Si no es dígito, tampoco es válido
//        if (!isdigit(cadena[i]) && cadena[i] != '-' && cadena[i] != '.')
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//
int esEnteroValido(char cadena[])
{
    int longitud = strlen(cadena);
    // Quitar espacios, saltos de línea, etcétera
    while (longitud > 0 && isspace(cadena[longitud - 1]))
        longitud--;
    if (longitud <= 0) return 0;
    int i;
    for (i = 0; i < longitud; ++i)
    {
        // En caso de que sea un guión, y que no esté al inicio, no es válido
        if (cadena[i] == '-' && i > 0)
        {
            return 0;
        }
        // Si no es dígito, tampoco es válido
        if (!isdigit(cadena[i]) && cadena[i] != '-')
        {
            return 0;
        }
    }
    return 1;
}

//int cadenaValida(char cadena[], char mensaje[])
//{
//	printf("%s", mensaje);
//	scanf("%s", cadena);
//	if (!isalpha(cadena))
//	{
//	    printf("\nNo es una cadena, reingrese: ");
//	    scanf("%s", cadena);
//	}
//	if(isspace(cadena))
//	{
//
//	}
//	return cadena;
//}

//int validacionCadena(char cadena[])
//{
//	int i;
//	int rtn;
//
//	i=0;
//	rtn=1;
//
//	while(cadena[i])
//	{
//		if(!isalpha(cadena[i])&& cadena[i]=='')
//		{
//			rtn=0;
//			i++;
//		}
//	}
//
//	return rtn;
//}
