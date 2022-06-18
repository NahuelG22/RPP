/*
 * servicios.h
 *
 *  Created on: 17 jun. 2022
 *      Author: Nahuel A
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int id;
	char patente[10];
	float km;
	char marca[10];
	int cargado;
}eVehiculo;

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int identificador;
	char descripcion[30];
	float cotizacion;
	int contador;
}eDiagnostico;

typedef struct
{
	int id;
	char nombreCliente[50];
	eFecha fecha;
	eVehiculo vehiculo;
	int asignacion;
	int mecanico;
	eDiagnostico diagnostico;
}eServicio;

/// @fn eServicio obtenerServicio()
/// @brief Pide los datos del servicio
///
/// @return la estructura con los datos
eServicio obtenerServicio();

/// @fn int buscarServicioLibre(eServicio[], int)
/// @brief busca si en la lista de servicios hay espacio libre
///
/// @param listaServicios
/// @param sizeServicios
/// @return el index que confirma si hay o no espacio
int buscarServicioLibre(eServicio listaServicios[], int sizeServicios);


/// @fn void inicializarListaServicios(eServicio[], int)
/// @brief Pone todas las posiciones del array de la lista de servicios en libre e inicializa el id en 10(debido al harcodeo)
///
/// @param listaServicios
/// @param sizeServicios
void inicializarListaServicios(eServicio listaServicios[], int sizeServicios);

/// @fn void mostrarServicios(eServicio[], int)
/// @brief muestra los datos de los servicios diagnosticados
///
/// @param listaServicios
/// @param sizeServicios
void mostrarServicios(eServicio listaServicios[], int sizeServicios);

/// @fn void listarServiciosSinDiagnosticar(eServicio[], int)
/// @brief lista los servicios sin diagnosticar
///
/// @param listaServicios
/// @param sizeServicios
void listarServiciosSinDiagnosticar(eServicio listaServicios[], int sizeServicios);

/// @fn int cargarServicio(eServicio[], int, int)
/// @brief
///
/// @param listaServicios
/// @param sizeServicios
/// @param id
/// @return
int cargarServicio(eServicio listaServicios[], int sizeServicios, int id);

/// @fn int cancelarServicio(eServicio[], int, int)
/// @brief Permite cancelar un servicio ingresando el id
///
/// @param listaServicios
/// @param sizeServicios
/// @param id
/// @return la confirmacion de la eliminacion
int cancelarServicio(eServicio listaServicios[], int sizeServicios, int id);

/// @fn void ordenarServiciosPorFecha(eServicio[], int)
/// @brief ordena los servicios por fecha
///
/// @param listaServicios
/// @param sizeServicios
void ordenarServiciosPorFecha(eServicio listaServicios[], int sizeServicios);

/// @fn void mostrarAltaServicio(eServicio[], int)
/// @brief muestra los datos de los servicios ingresados sin diagnosticar
///
/// @param listaServicios
/// @param sizeServicios
void mostrarAltaServicio(eServicio listaServicios[], int sizeServicios);

/// @fn void listarServicios(eServicio[], int)
/// @brief lista
///
/// @param listaServicios
/// @param sizeServicios
void listarServicios(eServicio listaServicios[], int sizeServicios);

/// @fn void listadoFechaDeterminada(eServicio[], int)
/// @brief lista segun una fecha determinada
///
/// @param listaServicios
/// @param sizeServicios
void listadoFechaDeterminada(eServicio listaServicios[], int sizeServicios);

/// @fn void calcularDesperfectosMasDiagnosticados(eServicio[], int)
/// @brief calcula los 3 desperfectos mas diagnosticados
///
/// @param listaServicios
/// @param sizeServicios
void calcularDesperfectosMasDiagnosticados(eServicio listaServicios[], int sizeServicios);

/// @fn void ordenarVehiculos(eServicio[], int)
/// @brief Realiza un ordenamiento de vehiculos segun orden alfabetico y kilometraje
///
/// @param listaServicios
/// @param sizeServicios
void ordenarVehiculos(eServicio listaServicios[], int sizeServicios);

/// @fn void listarXVehiculo(eServicio[], int)
/// @brief lista los vehiculos de forma alfabetica
///
/// @param listaServicios
/// @param sizeServicios
void listarXVehiculo(eServicio listaServicios[], int sizeServicios);


/// @fn eVehiculo obtenerDatosVehiculo()
/// @brief Pide los datos del vehiculo
///
/// @return la estructura con los datos
eVehiculo obtenerDatosVehiculo();


/// @fn eFecha pedirFecha()
/// @brief Pide la fecha del servicio
///
/// @return la fecha
eFecha pedirFecha();

#endif /* SERVICIOS_H_ */
