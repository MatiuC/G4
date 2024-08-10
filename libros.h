#ifndef LIBROS_H
#define LIBROS_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct Tlibro {
    int id;                   // Identificador único del libro
    string titulo;       // Título del libro
    string autor;        // Nombre del autor
    int anioPublicacion;      // Año de publicación
    string editorial;    // Editorial del libro
    bool alquilado;      // Indica si el libro está alquilado o no
} ;




const int MAX_LIBROS = 1000;

//Validador de apertura de archivos
bool verificarfile(ifstream &file, string archivo);
//
int cargarlibros(Tlibro libros[]);
//Verificar si la id de un libro ya existe
bool libroexiste(const int& id, Tlibro libros[], int cantidad);
//Funcion util para guardar libros en el archivo
bool guardarLibros(Tlibro libros[], int cantidadLibros, const string &nombreArchivo);
// Función para agregar un libro al archivo
void agregarLibro();
//Mostrar los libros del archivo
void mostrarlibros();
//Eliminar un libro del archivo por su ID.
void eliminarLibro(int id);

#endif
