/*
 * nexo.c
 *
 *  Created on: 17 jun. 2022
 *      Author: Nahuel A
 */
#include "nexo.h"

void asignarMecanico(eServicio listaServicios[], eMecanico listaMecanicos[], int sizeServicios, int sizeMecanicos)
{
	int encontreServicio = 0;
	int encontreMecanico = 0;
	int id_mecanico;
	int id_servicio;
	listarMecanicos(listaMecanicos, sizeMecanicos);
	printf("\nSeleccione el id de un mecanico: ");
	scanf("%d", &id_mecanico);
	mostrarAltaServicio(listaServicios, sizeServicios);
	printf("\nSeleccione el id del servicio: ");
	scanf("%d", &id_servicio);
	for(int j=0; j<sizeServicios; j++)
	{
		if(listaServicios[j].id==id_servicio)
		{
			encontreServicio = 1;
			for(int i=0; i<sizeMecanicos; i++)
			{
				if(listaMecanicos[i].id==id_mecanico)
				{
					encontreMecanico = 1;
					listaMecanicos[i].asignacion=OCUPADO;
					listaServicios[j].asignacion=OCUPADO;
					listaServicios[j].mecanico=listaMecanicos[i].id;
					listaServicios[j].diagnostico.identificador=listaMecanicos[i].especialidad.identificador;
					listaServicios[j].diagnostico.contador++;
					strcpy(listaServicios[j].diagnostico.descripcion, listaMecanicos[i].especialidad.descripcion);
					printf("\nIngrese la cotizacion: ");
					scanf("%f", &listaServicios[j].diagnostico.cotizacion);
					listaMecanicos[i].acumulador += listaServicios[j].diagnostico.cotizacion;
					listaMecanicos[i].contador += 1;
					listaMecanicos[i].especialidad.contador++;
				}
			}
		}
	}
	if(encontreServicio == 0)
	{
		printf("\nNo se encontro el ID del servicio ingresado");
	}
	if(encontreMecanico == 0)
	{
		printf("\nNo se encontro el ID del mecanico ingresado");
	}
	mostrarServicios(listaServicios, sizeServicios);
}

int modificarServicio(eServicio listaServicios[], int sizeServicios, eMecanico listaMecanicos[], int sizeMecanicos)
{
	int id;
	int modificacion;
	int opcion;

	mostrarServicios(listaServicios, sizeServicios);
	modificacion=-1;

	id=getInt("\nIngrese el id a modificar: ");

	for(int i=0; i<sizeServicios; i++)
	{
		if(listaServicios[i].asignacion==OCUPADO && listaServicios[i].id==id)
		{
			opcion=getInt("\n¿Que desea modificar?\n1-Nombre\n2-Fecha\n3-Mecanico\nIngresar: ");
			switch(opcion)
			{
				case 1:
					printf("\nIngrese el nombre: \n");
					fflush(stdin);
					gets(listaServicios[i].nombreCliente);
					modificacion=1;
				break;
				case 2:
					printf("Ingrese la nueva fecha: \n");
					listaServicios[i].fecha=pedirFecha();
					modificacion=2;
				break;
				case 3:
					listarMecanicos(listaMecanicos, sizeMecanicos);
					printf("Ingrese el id del nuevo mecanico: \n");
					scanf("%d", &listaMecanicos[i].id);
					modificacion=3;
				break;
			}
		}
	}
	mostrarServicios(listaServicios, sizeServicios); // Borrar despues de debuggear

	return modificacion;
}

void calcularCotizacionesCambioAceite(eMecanico listaMecanicos[], int sizeMecanicos, eServicio listaServicios[], int sizeServicios)
{
	int dia;
	int mes;
	int anio;
	float acumulador;

	acumulador=0;

	dia=getInt("\nIngrese el dia: ");
	mes=getInt("\nIngrese el mes: ");
	anio=getInt("\nIngrese el año: ");
	mostrarServicios(listaServicios,sizeServicios );
	for(int i=0; i<sizeServicios; i++)
	{
		if(dia==listaServicios[i].fecha.dia && mes==listaServicios[i].fecha.mes && anio==listaServicios[i].fecha.anio)
		{
			if(strcmp(listaServicios[i].diagnostico.descripcion, "cambio de aceite")==0)
			{
				acumulador+=listaServicios[i].diagnostico.cotizacion;
			}
		}
	}
	printf("\n%f\n", acumulador);
}

