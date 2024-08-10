#include "libros.h"

void agregarLibro(const Libro& libro){
  ofstream archivo("libros.txt", std::ios::app);

  // Verificar si el archivo se abrió correctamente
  if (!archivo) {
      std::cerr << "Error al abrir el archivo para agregar el libro." << std::endl;
      return;
  }

  // Escribir los datos del libro en el archivo
  archivo << libro.id << "\n";
  archivo << libro.titulo << "\n";
  archivo << libro.autor << "\n";
  archivo << libro.anioPublicacion << "\n";
  archivo << libro.editorial << "\n";

  // Cerrar el archivo
  archivo.close();

  std::cout << "Libro agregado correctamente." << std::endl;
}

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
