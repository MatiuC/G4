#ifndef VALIDADORES_H
#define VALIDADORES_H

#include <string>
#include <iostream>
#include <limits>
#include "libros.h"

using namespace std;


bool validarId(int id);
bool validarAnio(int anio);
bool validarTexto(const string& texto);
bool validarAlquilado(int alquilado);

void leerTextoValido(string &texto, const string &mensaje, const string &errorMensaje);

#endif // VALIDADORES_H
