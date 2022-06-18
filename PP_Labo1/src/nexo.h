/*
 * nexo.h
 *
 *  Created on: 17 jun. 2022
 *      Author: Nahuel A
 */

#ifndef NEXO_H_
#define NEXO_H_
#include "servicios.h"
#include "mecanicos.h"

/// @fn void asignarMecanico(eServicio[], eMecanico[], int, int)
/// @brief Se encarga de asignar un mecanico a la hora de diagnosticar un servicio
///
/// @param listaServicios
/// @param listaMecanicos
/// @param sizeServicios
/// @param sizeMecanicos
void asignarMecanico(eServicio listaServicios[], eMecanico listaMecanicos[], int sizeServicios, int sizeMecanicos);

/// @fn int modificarServicio(eServicio[], int, eMecanico[], int)
/// @brief Permite modificar un servicio seleccionado
///
/// @param listaServicios
/// @param sizeServicios
/// @param listaMecanicos
/// @param sizeMecanicos
/// @return la modificacion
int modificarServicio(eServicio listaServicios[], int sizeServicios, eMecanico listaMecanicos[], int sizeMecanicos);

/// @fn void calcularCotizacionesCambioAceite(eMecanico[], int, eServicio[], int)
/// @brief Calcula y muestra las cotizaciones en cuanto a cambio de aceite de determinado dia
///
/// @param listaMecanicos
/// @param sizeMecanicos
/// @param listaServicios
/// @param sizeServicios
void calcularCotizacionesCambioAceite(eMecanico listaMecanicos[], int sizeMecanicos, eServicio listaServicios[], int sizeServicios);

#endif /* NEXO_H_ */
