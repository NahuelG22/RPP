/*
 * mecanicos.h
 *
 *  Created on: 17 jun. 2022
 *      Author: Nahuel A
 */

#ifndef MECANICOS_H_
#define MECANICOS_H_
#include "servicios.h"

typedef struct
{
	int identificador;
	char descripcion[30];
	int contador;
}eEspecialidad;

typedef struct
{
	int id;
	char nombreMecanico[50];
	eEspecialidad especialidad;
	int asignacion;
	float acumulador;
	int contador;
}eMecanico;

/// @fn void listarMecanicos(eMecanico[], int)
/// @brief lista a todos los mecanicos
///
/// @param listaMecanicos
/// @param sizeMecanicos
void listarMecanicos(eMecanico listaMecanicos[], int sizeMecanicos);

/// @fn void inicializarListaMecanicos(eMecanico[], int)
/// @brief inicializa la lista de mecanicos en libre
///
/// @param listaMecanicos
/// @param sizeMecanicos
void inicializarListaMecanicos(eMecanico listaMecanicos[], int sizeMecanicos);

/// @fn void listarMecanicosSinAsignar(eMecanico[], int)
/// @brief lista los mecanicos sin asignar
///
/// @param listaMecanicos
/// @param sizeMecanicos
void listarMecanicosSinAsignar(eMecanico listaMecanicos[], int sizeMecanicos);

/// @fn void calcularCotizacionPromedio(eMecanico[], int)
/// @brief calcula la cotizacion promedio de cada mecanico
///
/// @param listaMecanicos
/// @param sizeMecanicos
void calcularCotizacionPromedio(eMecanico listaMecanicos[], int sizeMecanicos);

/// @fn void listarServiciosOrdenadosEspecialidad(eMecanico[], int)
/// @brief lista de servicios ordenados por especialidad del mecánico alfabéticamente
///
/// @param listaMecanicos
/// @param sizeMecanicos
void listarServiciosOrdenadosEspecialidad(eMecanico listaMecanicos[], int sizeMecanicos);

/// @fn void listarMecanicosConMasDiagnosticos(eMecanico[], int)
/// @brief lista a los mecanicos que realizaron mas diagnosticos
///
/// @param listaMecanicos
/// @param sizeMecanicos
void listarMecanicosConMasDiagnosticos(eMecanico listaMecanicos[], int sizeMecanicos);

/// @fn void calcularEspecialidadesMasEstudiadas(eMecanico[], int)
/// @brief calcula las 3 especialidades mas estudiadas por los mecanicos
///
/// @param listaMecanicos
/// @param sizeMecanicos
void calcularEspecialidadesMasEstudiadas(eMecanico listaMecanicos[], int sizeMecanicos);
#endif /* MECANICOS_H_ */
