/*
 ============================================================================
 Name        : PP_Labo1.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "nexo.h"
#define TAM 200
#define P 25

int main(void)
{
	setbuf(stdout,NULL);
	eServicio listaServicios[TAM]={{1, "Pepe", {2, 3, 2022},{1,"LM372", 52093.2, "Nissan"}},
	{2, "Jorge", {10, 9, 2022}, {2,"MP572", 9870.6, "Ford"}}, {3, "Lucas", {25, 6, 2022},{3,"PL321", 5430, "Audi"}},
	{4, "Pedro", {7, 8, 2022},{4,"TY323", 2134.9, "Ford"}},{5, "Dario", {27, 3, 2022}, {5,"PL293", 59212 , "Nissan"}},
	{6, "Geronimo", {14, 5 ,2022}, {6,"ME514", 21345.9, "Audi"}}, {7, "Matias", {12, 2, 2022}, {7,"DM100",39329.1,"Audi"}},
	{8, "Cristian", {24, 1, 2022}, {8,"LO452", 54220 ,"Ford"}},{9, "Carlos", {7, 10, 2022}, {9,"NN206", 3275.3, "Nissan"}},
	{10, "Leandro", {3, 12, 2022},{10,"RC293", 220.9, "Nissan"}}};
	eMecanico listaMecanicos[P]={{104, "Carlos Alfonso", {1, "cambio de aceite"}}, {216, "Sergio Berardi", {1,"cambio de aceite"}},
	{123, "Manuel Cardozo", {3,"suspension"}}, {156, "Fernando Cristal", {3,"suspension"}}, {190, "Raul Damianski", {3,"suspension"}},
	{200, "Marcos Fonte", {2, "reparacion de motor"}}, {130, "Raul Gomez", {2, "reparacion de motor"}}, {211, "Mauricio Gimenez", {3,"suspension"}},
	{207, "Pedro Jota", {1, "cambio de aceite"}}, {178, "Cristian Monet", {1, "cambio de aceite"}}, {165, "Pablo Petroli", {1, "cambio de aceite"}},
	{145, "Martin Soto", {2, "reparacion de motor"}}, {99, "Jorge Laroi", {4,"cambio de llantas"}}, {43, "Julio Agostini", {5,"reparacion de frenos"}},
	{78, "Cristobal Santino", {6,"limpieza de tubos"}}, {102, "Julian Bosali", {2, "reparacion de motor"}}, {48, "Sandro Perez", {2, "reparacion de motor"}},
	{90, "Fabricio Bussalino", {4,"cambio de llantas"}}, {256, "Cesar Talar", {5,"reparacion de frenos"}}, {101, "Alfredo Casco", {4,"cambio de llantas"}},
	{23, "Santiago Mesa",{5,"reparacion de frenos"}}, {35, "Felipe Damas", {4,"cambio de llantas"}}, {69, "Pablo Cornelli", {6,"limpieza de tubos"}},
	{72, "Enzo Alvarez",{6,"limpieza de tubos"}}, {87, "Miguel Dominguez", {5,"reparacion de frenos"}}};
	int opcion;
	int id;
	int retorno;
	char listar;

	id=10;

	opcion=0;

	inicializarListaServicios(listaServicios, TAM); 
	inicializarListaMecanicos( listaMecanicos, P);

	opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");

	do
	{
		switch(opcion)
		{
			case 1:
				id++;
				retorno=cargarServicio(listaServicios, TAM, id);
				mostrarAltaServicio(listaServicios, TAM);
				opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
			break;
			case 2:
				retorno=modificarServicio(listaServicios, TAM, listaMecanicos, P);
				if(retorno==1)
				{
					printf("\nSe ha modificado el nombre del cliente correctamente\n");
				}
				else
				{
					if(retorno==2)
					{
						printf("\nSe ha modificado la fecha correctamente\n");
					}
					else
					{
						if(retorno==3)
						{
							printf("\nSe ha modificado al mecanico correctamente\n");
						}
					}
				}
				mostrarServicios(listaServicios, TAM);
				opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
			break;
			case 3:
				retorno=cancelarServicio(listaServicios, TAM, id);
				mostrarServicios(listaServicios, TAM);
				opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
			break;
			case 4:
				asignarMecanico(listaServicios, listaMecanicos, TAM, P);
				opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
			break;
			case 5:
				listar=getChar("\n¿Que desea listar?\n a. Todos los mecanicos\nb. Todos los servicios\n"
						"c. Todos los mecanicos a los que no se les asigno ningun servicio\nd. Listado de servicios ordenados por fecha desde el mas antiguo hasta el mas reciente\n"
						"e. Saber suma de cotizaciones de determinada fecha en concepto de cambio de aceite\nf. Cotizacion promedio de cada uno de los mecanicos\n"
						"g. Mecanicos que diagnosticaron mas servicios\nh. Listado de servicios ordenados por especialidad del mecanico alfabeticamente\n"
						"i. Listado de todos los servicios entre el mes de Marzo y Mayo del 2022 para una especialidad determinada\n"
						"j. Porcentaje de servicio diagnosticados que atiende cada mecanico en funcion del total de diagnosticos\n"
						"k. Los 3 desperfectos mas diagnosticados\nl. Las 3 especialidades mas estudiadas\nm. Listar por vehiculo\n\nSeleccione: ");
				switch(listar)
				{
					case 'a':
						listarMecanicos(listaMecanicos, P);
						opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
					break;
					case 'b':
						listarServicios(listaServicios, TAM);
						opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
					break;
					case 'c':
						listarMecanicosSinAsignar(listaMecanicos, P);
						opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
					break;
					case 'd':
						ordenarServiciosPorFecha(listaServicios, TAM);
						opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
					break;
					case 'e':
						calcularCotizacionesCambioAceite(listaMecanicos, P, listaServicios, TAM);
						opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
					break;
					case 'f':
						calcularCotizacionPromedio(listaMecanicos, P);
						opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
					break;
					case 'g':
						listarMecanicosConMasDiagnosticos(listaMecanicos, P);
						opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
					break;
					case 'h':
						listarServiciosOrdenadosEspecialidad(listaMecanicos, P);
						opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
					break;
					case 'i':
						listadoFechaDeterminada(listaServicios, TAM);
						opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
					break;
					case 'j':
						opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
					break;
					case 'k':
						calcularDesperfectosMasDiagnosticados(listaServicios, TAM);
						opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
					break;
					case 'l':
						calcularEspecialidadesMasEstudiadas(listaMecanicos, P);
						opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
					break;
					case 'm':
						listarXVehiculo(listaServicios, TAM);
						opcion=getInt("1. Alta servicio\n2. Modificar servicio\n3. Cancelar servicio\n4. Diagnosticar\n5. Listar\n6. Salir\n\nIngresar: ");
					break;
				}
			break;
		}
	}while(opcion!=6);

	if(opcion==6)
	{
		printf("\nEl programa finalizo.");
	}

	return EXIT_SUCCESS;
}
