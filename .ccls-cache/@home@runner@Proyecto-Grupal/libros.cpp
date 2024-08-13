#include "libros.h"
#include "validadores.h"



// Validador de apertura de archivos
bool verificarfile(ifstream &file, string archivo) {
  file.open(archivo);
  if (!file.is_open()) {
    setColor(RED);
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

        string linea;
        int contador = 0;

        while (getline(archivo, linea) && contador < MAX_LIBROS) {
            stringstream ss(linea);
            string idStr, titulo, autor, anioStr, editorial, estadoStr;

            // Leer los datos de la línea usando el stringstream
            getline(ss, idStr, ',');
            getline(ss, titulo, ',');
            getline(ss, autor, ',');
            getline(ss, anioStr, ',');
            getline(ss, editorial, ',');
            getline(ss, estadoStr, ',');

            // Convertir los datos de tipo string a los tipos correspondientes
            libros[contador].id = stoi(idStr);
            libros[contador].titulo = titulo;
            libros[contador].autor = autor;
            libros[contador].anioPublicacion = stoi(anioStr);
            libros[contador].editorial = editorial;
            libros[contador].alquilado = stoi(estadoStr);

            contador++;
        }

        archivo.close();
        return contador; // Retorna la cantidad de libros leídos
    }


// Funcion util para guardar libros en el archivo
bool guardarLibros(Tlibro libros[], int cantidadLibros, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar los libros." << endl;
        return false;
    }

    for (int i = 0; i < cantidadLibros; i++) {
        archivo << libros[i].id << ','
                << libros[i].titulo << ','
                << libros[i].autor << ','
                << libros[i].anioPublicacion << ','
                << libros[i].editorial << ','
                << libros[i].alquilado << '\n'; // Añadir salto de línea al final de cada libro
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
    setColor(LIGHTGREEN);
    cout << "Ingrese el id del libro: ";
    while (!(cin >> librotemp.id) || !validarId(librotemp.id)) {
        setColor(RED);
        cout << "ID inválido. Ingrese un número positivo: ";
        cin.clear(); // Limpiar el estado de error
        cin.ignore(); // Limpiar el buffer de entrada
    }
    cin.ignore(); // Limpiar el buffer de entrada

    if (libroexiste(librotemp.id, libros, cantidad)) {
        setColor(RED);
        cout << "Error: Ya existe un libro con este ID. \nIntente con otro" << endl;
        return;
    }
    setColor(LIGHTGREEN);
    leerTextoValido(librotemp.titulo, "Ingrese el título del libro: ", "Título inválido. Ingrese nuevamente: ");
    leerTextoValido(librotemp.autor, "Ingrese el autor del libro: ", "Autor inválido. Ingrese nuevamente: ");
    setColor(LIGHTGREEN);
    cout << "Ingrese el año de publicación: ";
    while (!(cin >> librotemp.anioPublicacion) || !validarAnio(librotemp.anioPublicacion)) {
        setColor(RED);
        cout << "Año inválido. Ingrese un año entre 1900 y 2024: \n";
        cin.clear(); // Limpiar el estado de error
        cin.ignore(); // Limpiar el buffer de entrada
    }
    cin.ignore(); // Limpiar el buffer de entrada
    
    leerTextoValido(librotemp.editorial, "Ingrese la editorial del libro: ", "Editorial inválida. Ingrese nuevamente: ");
    setColor(LIGHTGREEN);
    cout << "El libro está disponible para alquilar? (1 para sí, 0 para no): ";
    while (!(cin >> librotemp.alquilado) || !validarAlquilado(librotemp.alquilado)) {
        setColor(RED);
        cout << "Entrada inválida. Ingrese 1 para sí o 0 para no: ";
        cin.clear(); // Limpiar el estado de error
        cin.ignore(); // Limpiar el buffer de entrada
    }
    cin.ignore(); // Limpiar el buffer de entrada

    libros[cantidad++] = librotemp;
    setColor(GREEN);
    if (guardarLibros(libros, cantidad, "libros.txt")) {
        cout << "Libro agregado con éxito." << endl;
    }
}

#include "rlutil.h" // Asegúrate de incluir rlutil.h para el manejo de teclas y colores

void mostrarlibros() {
    Tlibro libros[MAX_LIBROS];
    int cantidadLibros = cargarlibros(libros);

    if (cantidadLibros == 0) {
        setColor(RED);
        cout << "No hay libros para mostrar." << endl;
        return;
    }

    int elementosPorPagina = 5;
    int pagina = 0;
    int numPaginas = (cantidadLibros + elementosPorPagina - 1) / elementosPorPagina;

    while (true) {
        rlutil::cls(); // Limpiar la pantalla

        cout << "Lista de libros:" << endl;
        cout << "---------------------------------\n";

        int inicio = pagina * elementosPorPagina;
        int fin = std::min(inicio + elementosPorPagina, cantidadLibros);

        for (int i = inicio; i < fin; ++i) {
            setColor(WHITE);
            cout << "ID: " << libros[i].id << endl;
            cout << "Título: " << libros[i].titulo << endl;
            cout << "Autor: " << libros[i].autor << endl;
            cout << "Año de Publicación: " << libros[i].anioPublicacion << endl;
            cout << "Editorial: " << libros[i].editorial << endl;
            cout << "Disponible para alquilar: " << (libros[i].alquilado ? "Si" : "No") << endl;
            cout << "---------------------------------\n";
        }

        cout << "\nUsa 'p' para ir a la página siguiente, 'o' para ir a la página anterior. Presiona 'q' para salir." << endl;

        int key = rlutil::getkey(); // Capturar la tecla presionada

        if (key == 'p' && pagina < numPaginas - 1) {
            pagina++;
        } else if (key == 'o' && pagina > 0) {
            pagina--;
        } else if (key == 'q') { // Salir si presionas 'q'
            break;
        }

        // DEBUG: Mostrar valores de la página y teclas
        cout << "Página actual: " << pagina + 1 << " de " << numPaginas << endl;
        //rlutil::anykey("Presiona cualquier tecla para continuar...");
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
// modificar un libro 

// Función auxiliar para leer texto válido opcionalmente
void leerTextoValidoOpcional(string &input, const string &mensaje, const string &valorActual) {
    cout << mensaje << "(" << valorActual << "): ";
    getline(cin, input);

    if (input.empty()) {
        input = valorActual; // Mantener el valor actual si no se ingresa nada
    }
}


// Función para modificar un libro
void modificarLibro(int id) {
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

    // Mostrar los detalles actuales del libro
    cout << "Detalles actuales del libro:" << endl;
    cout << "Título: " << libros[posicion].titulo << endl;
    cout << "Autor: " << libros[posicion].autor << endl;
    cout << "Año de Publicación: " << libros[posicion].anioPublicacion << endl;
    cout << "Editorial: " << libros[posicion].editorial << endl;
    cout << "Disponible para alquilar: " << (libros[posicion].alquilado ? "Sí" : "No") << endl;

    // Modificar los detalles del libro
    cout << "Ingrese los nuevos datos (presione enter para mantener el valor actual):" << endl;

    string nuevoTitulo, nuevoAutor, nuevaEditorial;
    string nuevoAnioStr, nuevoEstadoStr;
    int nuevoAnio, nuevoEstado;
    
    cin.ignore();
    leerTextoValidoOpcional(nuevoTitulo, "Nuevo título: ", libros[posicion].titulo);
    leerTextoValidoOpcional(nuevoAutor, "Nuevo autor: ", libros[posicion].autor);

    cout << "Nuevo año de publicación (" << libros[posicion].anioPublicacion << "): ";
    getline(cin, nuevoAnioStr);
    if (!nuevoAnioStr.empty()) {
        nuevoAnio = stoi(nuevoAnioStr);
        if (!validarAnio(nuevoAnio)) {
            cout << "Año inválido. No se realizaron cambios en el año de publicación." << endl;
            nuevoAnio = libros[posicion].anioPublicacion;
        }
    } else {
        nuevoAnio = libros[posicion].anioPublicacion;
    }

    leerTextoValidoOpcional(nuevaEditorial, "Nueva editorial: ", libros[posicion].editorial);

    cout << "¿Está disponible para alquilar? (1 para sí, 0 para no): ";
    getline(cin, nuevoEstadoStr);
    if (!nuevoEstadoStr.empty()) {
        nuevoEstado = stoi(nuevoEstadoStr);
        if (!validarAlquilado(nuevoEstado)) {
            cout << "Entrada inválida. No se realizaron cambios en el estado de alquiler." << endl;
            nuevoEstado = libros[posicion].alquilado;
        }
    } else {
        nuevoEstado = libros[posicion].alquilado;
    }

    // Actualizar el libro con los nuevos datos
    libros[posicion].titulo = nuevoTitulo;
    libros[posicion].autor = nuevoAutor;
    libros[posicion].anioPublicacion = nuevoAnio;
    libros[posicion].editorial = nuevaEditorial;
    libros[posicion].alquilado = nuevoEstado;

    // Guardar los cambios en el archivo
    if (guardarLibros(libros, cantidad, "libros.txt")) {
        cout << "Libro modificado con éxito." << endl;
    } else {
        cout << "Error al modificar el libro." << endl;
    }
}


