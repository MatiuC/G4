// Funciones para guardar archivos
#include "archivos.h"

void leerfile(const string &filename) {
  tDatos libro; // Estructura para manejar los datos del archivo
  ifstream file;
  file.open(filename);
  // Verificar si el archivo se abre correctamente
  if (!file.is_open()) {
    cout << "El archivo no se pudo abrir. " << endl;
    // return -1; revisar como salir de la funcion
  }
  // Leer los datos del archivo y guardarlos en la estructura
  // Lectura de datos
  tDatos libros[100]; // Arreglo para almacenar los datos de los libros (asume
                      // un máximo de 100 libros)
  int numLibros = 0;  // Contador para el número de libros
  while (file >> libro.id && libro.id != -1) {
    file.ignore(); // Ignorar el ','
    getline(file, libro.nombre, ',');
    getline(file, libro.autor, ',');
    getline(file, libro.editorial, ',');
    file >> libro.year;
    file.ignore(); // Ignorar el ','
    file >> libro.disponibilidad;
    file.ignore(); // Ignorar el ','
    // Agregar los datos a los arreglos temporales (implementar en el main)
    libros[numLibros] = libro; // Agrega el libro al arreglo
    numLibros++;               // Incrementa el contador
    cout << libro.id << " " << libro.nombre << " " << libro.autor << " "
         << libro.editorial << " " << libro.year << " " << libro.disponibilidad
         << endl;
  }
  file.close();
}

void escribirfile(const string &filename) {
  tDatos libro; // Estructura para manejar los datos del archivo
  ofstream file;
  file.open(filename, ios::app); // Abre el archivo en modo append
  // Verificar si el archivo se abre correctamente
  if (!file.is_open()) {
    cout << "El archivo no se pudo abrir. " << endl;
    // return -1; revisar como salir de la funcion
  }
  // Lectura de datos
  cout << "Ingrese el ID del libro: ";
  cin >> libro.id;
  cout << "Ingrese el nombre del libro: ";
  cin.ignore();
  getline(cin, libro.nombre);
  cout << "Ingrese el autor del libro: ";
  getline(cin, libro.autor);
  cout << "Ingrese la editorial del libro: ";
  getline(cin, libro.editorial);
  cout << "Ingrese el año del libro: ";
  cin >> libro.year;
  cout << "Ingrese la disponibilidad del libro (0 para no disponible, 1 para "
          "disponible): ";
  cin >> libro.disponibilidad;
  // Guardar los datos en el archivo
  file << libro.id << "," << libro.nombre << "," << libro.autor << ","
       << libro.editorial << "," << libro.year << "," << libro.disponibilidad
       << endl;
  file.close();
}