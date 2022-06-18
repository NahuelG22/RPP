/*
 * servicios.c
 *
 *  Created on: 17 jun. 2022
 *      Author: Nahuel A
 */
#include "servicios.h"

void inicializarListaServicios(eServicio listaServicios[], int sizeServicios)
{
	for(int i=10; i<sizeServicios; i++)
	{
		listaServicios[i].asignacion=LIBRE;
		listaServicios[i].id=0;
	}
}

eServicio obtenerServicio()
{
	eServicio servicio;

	printf("\nIntroduzca el nombre del cliente: ");
	fflush(stdin);
	gets(servicio.nombreCliente);
	servicio.fecha=pedirFecha();
	servicio.vehiculo=obtenerDatosVehiculo();
	return servicio;
}

eFecha pedirFecha()
{
	eFecha fecha;

	printf("\nIntroduzca el dia en el que se pidio el servicio: ");
	scanf("%d", &fecha.dia);

	while(fecha.dia>31)
	{
		printf("\nError. Introduzca el dia en el que se pidio el servicio: ");
		scanf("%02d", &fecha.dia);
	}

	printf("\nIntroduzca el mes en el que se pidio el servicio: ");
	scanf("%d", &fecha.mes);

	while(fecha.mes>12)
	{
		printf("\nError. Introduzca el mes en el que se pidio el servicio: ");
		scanf("%d", &fecha.mes);
	}

	printf("\nIntroduzca el año en el que se pidio el servicio: ");
	scanf("%d", &fecha.anio);

	while(fecha.anio<2022 || fecha.anio>2022)
	{
		printf("\nError. Introduzca el año en el que se pidio el servicio: ");
		scanf("%d", &fecha.anio);
	}

	return fecha;
}

eVehiculo obtenerDatosVehiculo()
{
	eVehiculo vehiculo;
	printf("\nIngrese la patente del vehiculo: ");
	fflush(stdin);
	gets(vehiculo.patente);
	printf("\nIngrese el kilometraje del vehiculo: ");
	scanf("%f", &vehiculo.km);
	printf("\nIngrese la marca del vehiculo: ");
	fflush(stdin);
	gets(vehiculo.marca);
	vehiculo.id++;//revisar en caso de error
	return vehiculo;
}


int buscarServicioLibre(eServicio listaServicios[], int sizeServicios)
{
	int index;

	index=-1;

	for(int i=0; i<sizeServicios; i++)
	{
		if(listaServicios[i].asignacion==LIBRE && listaServicios[i].id==0)
		{
			index=i;
			break;
		}
	}
	return index;
}

int cargarServicio(eServicio listaServicios[], int sizeServicios, int id)
{
	int index;

	index=buscarServicioLibre(listaServicios, sizeServicios);

	if(index!=-1)
	{
		listaServicios[index]=obtenerServicio();
		listaServicios[index].id=id;
	}
	else
	{
		printf("\nNo hay espacio libre para mas servicios.");
	}

	return index;

}

void ordenarVehiculos(eServicio listaServicios[], int sizeServicios)
{
	eServicio aux;
	for(int i=0; i<sizeServicios; i++)
	{
		for(int j=i+1; j<sizeServicios; j++)
		{
			if(strcmp(listaServicios[i].vehiculo.marca,listaServicios[j].vehiculo.marca)>0)
			{
				strcpy(aux.vehiculo.marca,listaServicios[i].vehiculo.marca);
				strcpy(listaServicios[i].vehiculo.marca,listaServicios[j].vehiculo.marca);
				strcpy(listaServicios[j].vehiculo.marca,aux.vehiculo.marca);//ordenado por marca
				if(strcmp(listaServicios[i].vehiculo.marca,listaServicios[j].vehiculo.marca)==0)
				{
					aux.vehiculo.km=listaServicios[i].vehiculo.km;
					listaServicios[i].vehiculo.km=listaServicios[j].vehiculo.km;
					listaServicios[j].vehiculo.km=aux.vehiculo.km;//en caso de ser misma marca ordena por km
				}
			}
		}
	}
}//ordeno por marca y a su vez por km

void mostrarServicios(eServicio listaServicios[], int sizeServicios)
{
	int anchoColumnaArrays = -20;
	int anchoColumnaNumerico = -15;
	int anchoFecha=-9;
	printf("+---------------+--------------------+---------------+--------------------+--------------------+---------------+\n");
	printf("|%*s|%*s|%*s|%*s|%*s|%*s|\n", anchoColumnaNumerico, "ID",
			anchoColumnaArrays, "Nombre del cliente",
			anchoColumnaNumerico, "Fecha",
			anchoColumnaArrays,  "Diagnostico",
			anchoColumnaArrays, "Descripcion",
			anchoColumnaNumerico, "Cotizacion");
	printf("+---------------+--------------------+---------------+--------------------+--------------------+---------------+\n");
	for(int i=0; i<sizeServicios; i++)
	{
		if(listaServicios[i].asignacion==OCUPADO)
		{
			printf("|%*d|%*s|%02d/%02d/%*d|%*d|%*s|%*f|\n"
					,anchoColumnaNumerico, listaServicios[i].id,
					anchoColumnaArrays, listaServicios[i].nombreCliente,
					listaServicios[i].fecha.dia,listaServicios[i].fecha.mes, anchoFecha,listaServicios[i].fecha.anio,
					anchoColumnaArrays, listaServicios[i].diagnostico.identificador,
					anchoColumnaArrays, listaServicios[i].diagnostico.descripcion,
					anchoColumnaNumerico, listaServicios[i].diagnostico.cotizacion);
		}
	}
	printf("+---------------+--------------------+---------------+--------------------+--------------------+---------------+\n");
}

void listarXVehiculo(eServicio listaServicios[], int sizeServicios)
{
	printf("+---------------+--------------------+---------------+--------------------+--------------------+---------------+---------------+---------------+---------------+\n");
	printf("|%-15s|%-20s|%-15s|%-20s|%-20s|%-15s|%-15s|%-15s|%-20s|%-20s|%-15s|\n", "ID", "Nombre del cliente", "Fecha", "Diagnostico",
			"Descripcion", "Cotizacion", "ID del vehiculo", "Patente","Marca", "Modelo", "Kilometraje");
	printf("+---------------+--------------------+---------------+--------------------+--------------------+---------------+---------------+---------------+---------------+\n");
	for(int i=0; i<sizeServicios; i++)
	{
		if(listaServicios[i].asignacion==OCUPADO)
		{
			ordenarVehiculos(listaServicios, sizeServicios);
			printf("|%-15d|%-20s|%02d/%02d/%-20d|%-20d|%-20s|%-15f|%-15d|%-15s|%-15f|\n"
					, listaServicios[i].id, listaServicios[i].nombreCliente,
					listaServicios[i].fecha.dia,listaServicios[i].fecha.mes, listaServicios[i].fecha.anio,
					listaServicios[i].diagnostico.identificador, listaServicios[i].diagnostico.descripcion,
					listaServicios[i].diagnostico.cotizacion, listaServicios[i].vehiculo.id,
					listaServicios[i].vehiculo.patente ,listaServicios[i].vehiculo.km);
		}
	}
	printf("+---------------+--------------------+---------------+--------------------+--------------------+---------------+---------------+---------------+---------------+\n");
}

void mostrarAltaServicio(eServicio listaServicios[], int sizeServicios)
{
	int anchoColumnaArrays = -20;
	int anchoColumnaNumerico = -15;
	int anchoFecha=-9;
	printf("+---------------+--------------------+---------------+--------------------+--------------------+---------------+\n");
	printf("|%*s|%*s|%*s|%*s|%*s|%*s|\n", anchoColumnaNumerico, "ID",
			anchoColumnaArrays, "Nombre del cliente",
			anchoColumnaNumerico, "Fecha", anchoColumnaArrays, "Marca", anchoColumnaArrays, "Patente",
			anchoColumnaNumerico, "KM");
	printf("+---------------+--------------------+---------------+--------------------+--------------------+---------------+\n");
	for(int i=0; i<sizeServicios; i++)
	{
		if(listaServicios[i].id != 0)
		{
			printf("|%*d|%*s|%02d/%02d/%*d|%*s|%*s|%*f|\n",anchoColumnaNumerico, listaServicios[i].id,
					anchoColumnaArrays, listaServicios[i].nombreCliente,
					listaServicios[i].fecha.dia,listaServicios[i].fecha.mes, anchoFecha,
					listaServicios[i].fecha.anio, anchoColumnaArrays, listaServicios[i].vehiculo.marca,
					anchoColumnaArrays, listaServicios[i].vehiculo.patente, anchoColumnaNumerico,
					listaServicios[i].vehiculo.km);
		}
	}
	printf("+---------------+--------------------+---------------+--------------------+--------------------+---------------+\n");
}

int cancelarServicio(eServicio listaServicios[], int sizeServicios, int id)
{
	int remove;
	remove=-1;

	id=getInt("\nIngrese el id para eliminar: ");

	for(int i=0; i<sizeServicios; i++)
	{
		if(listaServicios[i].asignacion==OCUPADO && listaServicios[i].id==id)
		{
			listaServicios[i].asignacion=LIBRE;
			listaServicios[i].id = 0;
			remove=1;
			printf("\nSe ha eliminado al cliente correctamente\n\n");
			break;
		}
	}
	return remove;
}

void listarServicios(eServicio listaServicios[], int sizeServicios)
{
	for(int i=0; i<sizeServicios; i++)
	{
		printf("%4d %10s %4d %10s %4.2f\n", listaServicios[i].id, listaServicios[i].nombreCliente ,listaServicios[i].diagnostico.identificador,
				listaServicios[i].diagnostico.descripcion, listaServicios[i].diagnostico.cotizacion);
	}
}

void listarServiciosSinDiagnosticar(eServicio listaServicios[], int sizeServicios)
{
	for(int i=0; i<sizeServicios; i++)
	{
		if(listaServicios[i].diagnostico.identificador=='\0')
		{
			printf("%d %s %d/%d/%d", listaServicios[i].id, listaServicios[i].nombreCliente, listaServicios[i].fecha.dia, listaServicios[i].fecha.mes,
					listaServicios[i].fecha.anio);
		}
	}
}

void ordenarServiciosPorFecha(eServicio listaServicios[], int sizeServicios)
{
	eServicio aux;
	for(int i=0; i<sizeServicios-1; i++)
	{
		for(int j=i+1; j<sizeServicios; j++)
		{
			if(listaServicios[i].fecha.mes<listaServicios[j].fecha.mes)
			{
				aux=listaServicios[i];
				listaServicios[i]=listaServicios[j];
				listaServicios[j]=aux;
			}
		}
		printf("\n%d %s %d/%d/%d %s %f", listaServicios[i].id, listaServicios[i].nombreCliente, listaServicios[i].fecha.dia, listaServicios[i].fecha.mes,
				listaServicios[i].fecha.anio, listaServicios[i].diagnostico.descripcion, listaServicios[i].diagnostico.cotizacion);
	}
}

void listadoFechaDeterminada(eServicio listaServicios[], int sizeServicios)
{
	char especialidad[20];

	printf("\nIntroduzca la especialidad: ");
	scanf("%[^\n]s", especialidad);
	for(int i=0; i<sizeServicios; i++)
	{
		if(strcmp(listaServicios[i].diagnostico.descripcion, especialidad))
		{
			if(listaServicios[i].fecha.anio==2022)
			{
				if(listaServicios[i].fecha.mes>2 || listaServicios[i].fecha.mes<6)
				{
					printf("|%d\t|%s\t|%02d/%02d/%d\t|%d\t|%s\t|\n", listaServicios[i].id, listaServicios[i].nombreCliente, listaServicios[i].fecha.dia,
							listaServicios[i].fecha.mes, listaServicios[i].fecha.anio,  listaServicios[i].diagnostico.identificador,
							listaServicios[i].diagnostico.descripcion);
				}
			}
		}
	}
}

void calcularDesperfectosMasDiagnosticados(eServicio listaServicios[], int sizeServicios)
{
	int num;
	eServicio aux;
	num=0;
	for(int i=0; i<sizeServicios; i++)
	{
		for(int j=i+1; j<sizeServicios; j++)
		{
			while(num!=3)
			{
				if(listaServicios[i].diagnostico.contador>listaServicios[j].diagnostico.contador)
				{
					aux=listaServicios[i];
					listaServicios[i]=listaServicios[j];
					listaServicios[j]=aux;
				}
				printf(listaServicios[i].diagnostico.descripcion);
				num++;
			}
		}
	}
}
