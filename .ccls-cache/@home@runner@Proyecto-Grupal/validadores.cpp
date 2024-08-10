#include "validadores.h"

// Función para validar un ID de libro
bool validarId(int id) {
    return id > 0; // El ID debe ser un número positivo
}

// Función para validar el año de publicación
bool validarAnio(int anio) {
    return anio >= 1900 && anio <= 2100; // El año debe estar entre 1900 y 2100
}

// Función para validar el texto (no vacío)
bool validarTexto(const string& texto) {
    return !texto.empty(); // El texto no debe estar vacío
}

// Función para validar si el libro está alquilado (1 o 0)
bool validarAlquilado(int alquilado) {
    return alquilado == 0 || alquilado == 1; // Solo se permite 0 o 1
}

// Función para leer un texto y validarlo
void leerTextoValido(string &texto, const string &mensaje, const string &errorMensaje) {
    cout << mensaje;
    getline(cin, texto);
    while (!validarTexto(texto)) {
        cout << errorMensaje;
        getline(cin, texto);
    }
}