#ifndef LIBROS_H
#define LIBROS_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
struct Libro {
    int id;                   // Identificador único del libro
    string titulo;       // Título del libro
    string autor;        // Nombre del autor
    int anioPublicacion;      // Año de publicación
    string editorial;    // Editorial del libro
};

// Función para agregar un libro al archivo
void agregarLibro(const Libro& libro);

// Función para modificar un libro existente
void modificarLibro(int id, const Libro& libroModificado);

// Función para eliminar un libro por ID
void eliminarLibro(int id);

// Función para buscar un libro por ID
Libro buscarLibro(int id, int& encontrado);

// Función para listar todos los libros
void listarLibros();

// Función para cargar libros desde el archivo
Libro* cargarLibros(int& cantidad);

// Función para guardar libros en el archivo
void guardarLibros(Libro* libros, int cantidad);

#endif
