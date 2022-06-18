/*
 * mecanicos.c
 *
 *  Created on: 17 jun. 2022
 *      Author: Nahuel A
 */
#include "mecanicos.h"

void inicializarListaMecanicos(eMecanico listaMecanicos[], int sizeMecanicos)
{
	for(int i=0; i<sizeMecanicos; i++)
	{
		listaMecanicos[i].asignacion=LIBRE;
		listaMecanicos[i].acumulador=0;
		listaMecanicos[i].contador=0;
	}
}

void listarMecanicosConMasDiagnosticos(eMecanico listaMecanicos[], int sizeMecanicos)
{
	int i;
	eMecanico aux;
	int anchoColumnaArrays = -20;
	int anchoColumnaNumerico = -5;
	printf("+-----+--------------------+--------------------+--------------------+\n");
	printf("|%*s|%*s|%*s\t|%*s|\n", anchoColumnaNumerico, "ID", anchoColumnaArrays, "Nombre del mecanico", anchoColumnaNumerico, "especialidad",
			anchoColumnaArrays, "Servicios diagnosticados");
	printf("+-----+--------------------+--------------------+--------------------+\n");
	for(i=0; i<sizeMecanicos; i++)
	{
		for(int j=i+1; j<sizeMecanicos; j++)
		{
			if(listaMecanicos[i].contador>listaMecanicos[j].contador)
			{
				aux=listaMecanicos[i];
				listaMecanicos[i]=listaMecanicos[j];
				listaMecanicos[j]=aux;
			}
		}
		printf("|%*d|%*s|%*s|%*d|\n",anchoColumnaNumerico, listaMecanicos[i].id, anchoColumnaArrays, listaMecanicos[i].nombreMecanico, anchoColumnaArrays,
				listaMecanicos[i].especialidad.descripcion, anchoColumnaArrays, listaMecanicos[i].contador);
	}
	printf("+-----+--------------------+--------------------+--------------------+\n");
}

void listarMecanicos(eMecanico listaMecanicos[], int sizeMecanicos)
{
	int i;
	eMecanico aux;
	int anchoColumnaArrays = -20;
	int anchoColumnaNumerico = -5;
	printf("+-----+--------------------+--------------------+\n");
	printf("|%*s|%*s|%*s|\n", anchoColumnaNumerico, "ID", anchoColumnaArrays, "Nombre del mecanico", anchoColumnaNumerico, "especialidad");
	printf("+-----+--------------------+--------------------+\n");
	for (i=0; i<sizeMecanicos; i++)
	{
		for(int j=i+1; j<sizeMecanicos; j++)
		{
			if(listaMecanicos[i].id>listaMecanicos[j].id)
			{
				aux=listaMecanicos[i];
				listaMecanicos[i]=listaMecanicos[j];
				listaMecanicos[j]=aux;
			}
		}
		printf("|%*d|%*s|%*s|\n",anchoColumnaNumerico, listaMecanicos[i].id, anchoColumnaArrays, listaMecanicos[i].nombreMecanico,
				anchoColumnaArrays, listaMecanicos[i].especialidad.descripcion);
	}
	printf("+-----+--------------------+--------------------+\n");
}

void listarMecanicosSinAsignar(eMecanico listaMecanicos[], int sizeMecanicos)
{
	for(int i=0; i<sizeMecanicos; i++)
	{
		if(listaMecanicos[i].asignacion==LIBRE)
		{
			printf("|%-5d|%-20s|%-20s|%-5d|\n",listaMecanicos[i].id, listaMecanicos[i].nombreMecanico,
							listaMecanicos[i].especialidad.descripcion, listaMecanicos[i].especialidad.identificador);
		}
	}
}

void listarServiciosOrdenadosEspecialidad(eMecanico listaMecanicos[], int sizeMecanicos)
{
	eMecanico aux;
	for(int i=0; i<sizeMecanicos; i++)
	{
		for(int i = 0; i < sizeMecanicos-1; i++)
		{
			for(int j = i+1; j<sizeMecanicos; j++)
			{
				if(strcmp(listaMecanicos[i].nombreMecanico, listaMecanicos[j].nombreMecanico)<0)
				{
					strcpy(aux.nombreMecanico, listaMecanicos[i].nombreMecanico);
					strcpy(listaMecanicos[i].nombreMecanico, listaMecanicos[j].nombreMecanico);
					strcpy(listaMecanicos[j].nombreMecanico, aux.nombreMecanico);
				}
			}
		}
		printf("\n%15s %15s %5d", listaMecanicos[i].especialidad.descripcion, listaMecanicos[i].nombreMecanico, listaMecanicos[i].id);
	}
}

void calcularCotizacionPromedio(eMecanico listaMecanicos[], int sizeMecanicos)
{
	float promedio;
	int i;
	eMecanico aux;
	int anchoColumnaArrays = -20;
	int anchoColumnaNumerico = -5;
	printf("+-----+--------------------+--------------------+--------------------+\n");
	printf("|%*s|%*s|%*s\t|%*s|\n", anchoColumnaNumerico, "ID", anchoColumnaArrays, "Nombre del mecanico", anchoColumnaNumerico, "Especialidad",
			anchoColumnaArrays, "Cotizacion");
	printf("+-----+--------------------+--------------------+--------------------+\n");
	for(i=0; i<sizeMecanicos; i++)
	{
		for(int j=i+1; j<sizeMecanicos; j++)
		{
			if(listaMecanicos[i].id>listaMecanicos[j].id)
			{
				aux=listaMecanicos[i];
				listaMecanicos[i]=listaMecanicos[j];
				listaMecanicos[j]=aux;
			}
		}
		if(listaMecanicos[i].contador==0)
		{
			promedio=0;
		}
		else
		{
			promedio=listaMecanicos[i].acumulador/listaMecanicos[i].contador;
		}

		printf("|%*d|%*s|%*s|%*f|\n",anchoColumnaNumerico, listaMecanicos[i].id, anchoColumnaArrays, listaMecanicos[i].nombreMecanico, anchoColumnaArrays,
				listaMecanicos[i].especialidad.descripcion, anchoColumnaArrays, promedio);
	}
	printf("+-----+--------------------+--------------------+--------------------+\n");
}

void calcularEspecialidadesMasEstudiadas(eMecanico listaMecanicos[], int sizeMecanicos)
{
	int num;
	eMecanico aux;
	num=0;
	for(int i=0; i<sizeMecanicos; i++)
	{
		for(int j=i+1; j<sizeMecanicos; j++)
		{
			while(num!=3)
			{
				if(listaMecanicos[i].especialidad.contador>listaMecanicos[j].especialidad.contador)
				{
					aux.especialidad=listaMecanicos[i].especialidad;
					listaMecanicos[i].especialidad=listaMecanicos[j].especialidad;
					listaMecanicos[j].especialidad=aux.especialidad;
				}
				printf(listaMecanicos[i].especialidad.descripcion);
				num++;
			}
		}
	}
}
