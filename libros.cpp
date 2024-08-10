#include "libros.h"
#include "validadores.h"

// Validador de apertura de archivos
bool verificarfile(ifstream &file, string archivo) {
  file.open(archivo);
  if (!file.is_open()) {
    cout << "Error al abrir el archivo: " << archivo << endl;
    return false;
  }
  return true;
}

// Leer libros en el archivo para que el programa funcione a traves de eso
int cargarlibros(Tlibro libros[]) {
  ifstream archivo; // Definir variable para leer el archivo
  if (!verificarfile(archivo, "libros.txt")) {
    return 0;
  }
  int contador = 0;
  while (contador < MAX_LIBROS &&
         archivo >>
             libros[contador].id // Leer el archivo y guardarlo en el arreglo de libros
         && archivo.ignore() && getline(archivo, libros[contador].titulo) &&
         getline(archivo, libros[contador].autor) &&
         archivo >> libros[contador].anioPublicacion && archivo.ignore() &&
         getline(archivo, libros[contador].editorial) &&
         archivo >> libros[contador].alquilado) {
    contador++; // Cuenta cuantos libros hay en el archivo
  }

  archivo.close();
  return contador; // Retorna la cantidad de libros leídos
}

// Funcion util para guardar libros en el archivo
bool guardarLibros(Tlibro libros[], int cantidadLibros,
                   const string &nombreArchivo) {
  ofstream archivo(nombreArchivo);
  if (!archivo.is_open()) {
    cout << "Error al abrir el archivo para guardar los libros." << endl;
    return false;
  }

  for (int i = 0; i < cantidadLibros; i++) {
    archivo << libros[i].id << endl;
    archivo << libros[i].titulo << endl;
    archivo << libros[i].autor << endl;
    archivo << libros[i].anioPublicacion << endl;
    archivo << libros[i].editorial << endl;
    archivo << libros[i].alquilado << endl;
  }

  archivo.close();
  return true;
}

// Funcion para verificar si ya existe un libro con un mismo id, los id tienen
// que ser unicos
bool libroexiste(const int &id, Tlibro libros[], int cantidad) {
  for (int i = 0; i < cantidad; i++) {
    if (libros[i].id == id) {
      return true;
    }
  }
  return false;
}

void agregarLibro() {
  // Funcion para leer libro, arreglo de libros y cantidad de libros
    Tlibro libros[MAX_LIBROS];
    int cantidad = cargarlibros(libros);

    Tlibro librotemp;
    cout << "Ingrese el id del libro: ";
    while (!(cin >> librotemp.id) || !validarId(librotemp.id)) {
        cout << "ID inválido. Ingrese un número positivo: ";
        cin.clear(); // Limpiar el estado de error
        cin.ignore(); // Limpiar el buffer de entrada
    }
    cin.ignore(); // Limpiar el buffer de entrada

    if (libroexiste(librotemp.id, libros, cantidad)) {
        cout << "Error: Ya existe un libro con este ID. \nIntente con otro" << endl;
        return;
    }

    leerTextoValido(librotemp.titulo, "Ingrese el título del libro: ", "Título inválido. Ingrese nuevamente: ");
    leerTextoValido(librotemp.autor, "Ingrese el autor del libro: ", "Autor inválido. Ingrese nuevamente: ");

    cout << "Ingrese el año de publicación: ";
    while (!(cin >> librotemp.anioPublicacion) || !validarAnio(librotemp.anioPublicacion)) {
        cout << "Año inválido. Ingrese un año entre 1900 y 2024: \n";
        cin.clear(); // Limpiar el estado de error
        cin.ignore(); // Limpiar el buffer de entrada
    }
    cin.ignore(); // Limpiar el buffer de entrada

    leerTextoValido(librotemp.editorial, "Ingrese la editorial del libro: ", "Editorial inválida. Ingrese nuevamente: ");

    cout << "El libro está disponible para alquilar? (1 para sí, 0 para no): ";
    while (!(cin >> librotemp.alquilado) || !validarAlquilado(librotemp.alquilado)) {
        cout << "Entrada inválida. Ingrese 1 para sí o 0 para no: ";
        cin.clear(); // Limpiar el estado de error
        cin.ignore(); // Limpiar el buffer de entrada
    }
    cin.ignore(); // Limpiar el buffer de entrada

    libros[cantidad++] = librotemp;

    if (guardarLibros(libros, cantidad, "libros.txt")) {
        cout << "Libro agregado con éxito." << endl;
    }
}

void mostrarlibros() {
    Tlibro libros[MAX_LIBROS];
    int cantidadLibros = cargarlibros(libros);

    if (cantidadLibros == 0) {
        cout << "No hay libros para mostrar." << endl;
        return;
    }

    cout << "Lista de libros:" << endl;
    for (int i = 0; i < cantidadLibros; i++) {
        cout << "ID: " << libros[i].id << endl;
        cout << "Título: " << libros[i].titulo << endl;
        cout << "Autor: " << libros[i].autor << endl;
        cout << "Año de Publicación: " << libros[i].anioPublicacion << endl;
        cout << "Editorial: " << libros[i].editorial << endl;
        cout << "Disponible para alquilar: " << (libros[i].alquilado ? "Sí" : "No") << endl;
        cout << "---------------------------------" << endl;
    }
}

void eliminarLibro(int id){
    Tlibro libros[MAX_LIBROS];
    int cantidad = cargarlibros(libros);

    // Buscar el libro con el ID dado
    int posicion = -1;
    for (int i = 0; i < cantidad; i++) {
        if (libros[i].id == id) {
            posicion = i;
            break;
        }
    }

    if (posicion == -1) {
        cout << "No se encontró un libro con el ID " << id << endl;
        return;
    }

    // Desplazar los libros hacia abajo para eliminar el libro
    for (int i = posicion; i < cantidad - 1; i++) {
        libros[i] = libros[i + 1];
    }

    // Reducir la cantidad de libros
    cantidad--;

    // Guardar los libros en el archivo
    if (guardarLibros(libros, cantidad, "libros.txt")) {
        cout << "Libro con ID " << id << " eliminado de manera correcta." << endl;
    } else {
        cout << "Error al eliminar el libro." << endl;
    }
}