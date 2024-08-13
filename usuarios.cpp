#include "usuarios.h"
#include "libros.h"
#include "menus.h"

// Funcion para el registro de un nuevo usuario al sistema
void registro() {
  tUsuario persona[MAX];
  int i = 0;
  bool usuario_existe = true;
  char usuario[MAX];

  while (usuario_existe) {
    setColor(RED);
    cout << "--------------------------------------" << endl;
    setColor(WHITE);
    cout << "Ingrese su usuario: ";
    cin >> usuario;
    // Funcion para verificar la existencia o no de un usuario para que no se
    // repita
    usuario_existe = verificar_existencia_usuario(usuario);
    if (usuario_existe) {
      setColor(RED);
      cout << "El usuario ya existe. Ingrese otro usuario: " << endl;
    }
  }
  // strcpy permite copiar el contenido de una cadena a otra
  strcpy(persona[i].usuario, usuario);
  cout << "Ingrese su contraseña: ";
  cin >> persona[i].contrasena;
  ofstream dato_usuario;
  // ios::app permite agregar nuevos datos en un archivo ya escrito
  dato_usuario.open("usuario.txt", ios::app);
  dato_usuario << persona[i].usuario << " " << persona[i].contrasena << endl;
  cout << "\nRegistro exitoso" << endl;
}

//  Funcion para el ingreso al sistema bibliotecario

string iniciar_usuario(string &usuario) {
  string contrasena;
  bool autenticado = false;

  while (!autenticado) { // Ciclo hasta que se valide una contraseña correcta
    cout << "--------------------------------------" << endl;
    setColor(WHITE);
    cout << "Ingrese su usuario: ";
    cin >> usuario;

    // Limpiar el buffer de entrada para evitar problemas con saltos de línea
    cin.ignore();

    setColor(WHITE);
    cout << "Ingrese su contraseña: ";
    cin >> contrasena;

    // Limpiar el buffer de entrada nuevamente
    cin.ignore();

    ifstream dato_usuario("usuario.txt");
    if (!dato_usuario) {
      setColor(RED);
      cout << "\nArchivo de usuarios no encontrado" << endl;
      return " ";
    }

    string a, b;
    while (dato_usuario >> a >> b) {
      if (a == usuario && b == contrasena) {
        autenticado = true;
        break;
      }
    }
    dato_usuario.close();

    if (autenticado) {
      setColor(WHITE);
      cout << "Inicio de sesión exitoso" << endl;
      opciones_usuario();
    } else {
      setColor(RED);
      cout << "Usuario o contraseña incorrectos" << endl;
      cout << "Presione ENTER para volver a intentar o 'Q' para salir: ";
      char opcion;
      cin.get(
          opcion); // Usa cin.get() para leer un solo carácter, incluyendo ENTER

      if (opcion == 'q' || opcion == 'Q') {
        return " "; // Salir si se presiona 'q'
      }
      cout << endl; // Inserta una línea en blanco para mantener la separación
                    // en el siguiente intento
    }
  }

  return usuario;
}

// Funcion que permite saber si el usuario ingresado ya existe o no
bool verificar_existencia_usuario(char a[]) {
  char line[MAX];
  ifstream dato_usuario("usuario.txt");
  while (dato_usuario >> line) {
    if (strcmp(line, a) == 0) {
      return true;
    }
  }
  return false;
}

// Funcion para el ingreso al sistema administrativo

void iniciar_admin() {
  string admin, contraseña, admin1, contraseña1;
  ifstream lectura_admin;

  while (true) { // Ciclo infinito hasta que se valide una contraseña correcta
    lectura_admin.open("u_admin.txt");
    lectura_admin >> admin >> contraseña;
    lectura_admin.close();

    cout << "--------------------------------------" << endl;
    setColor(WHITE);
    cout << "Ingrese su usuario: ";
    cin >> admin1;

    // Limpiar el buffer de entrada para evitar problemas con saltos de línea
    cin.ignore();

    setColor(WHITE);
    cout << "Ingrese su contraseña: ";
    cin >> contraseña1;

    // Limpiar el buffer de entrada nuevamente
    cin.ignore();

    if (admin == admin1 && contraseña == contraseña1) {
      cout << "Inicio de sesión exitoso" << endl;
      opciones_admin();
      break; // Sale del ciclo si la autenticación es exitosa
    } else {
      setColor(RED);
      cout << "*** Inicio de sesión fallido, vuelva a intentar ***" << endl;
      cout << "Presione ENTER para volver a intentar o 'Q' para salir: ";
      char opcion;
      cin.get(
          opcion); // Usa cin.get() para leer un solo carácter, incluyendo ENTER

      if (opcion == 'q' || opcion == 'Q') {
        break; // Salir del ciclo si se presiona 'q'
      }
      cout << endl; // Inserta una línea en blanco para mantener la separación
                    // en el siguiente intento
    }
  }
}

void mostrar_usuarios() {
  string usuarios[MAX];
  string contrasenas[MAX];
  int cantidadUsuarios = 0;

  ifstream lectura_usuario("usuario.txt");

  // Verifica si el archivo existe
  if (!lectura_usuario.is_open()) {
    setColor(RED);
    cout << "Error al abrir el archivo." << endl;
    return;
  }

  // Leer todos los usuarios y contraseñas y guardarlos en los arreglos
  while (lectura_usuario >> usuarios[cantidadUsuarios] >>
         contrasenas[cantidadUsuarios]) {
    cantidadUsuarios++;
    if (cantidadUsuarios >= MAX) {
      break; // Evitar desbordamiento del arreglo
    }
  }
  lectura_usuario.close();

  if (cantidadUsuarios == 0) {
    setColor(RED);
    cout << "No hay usuarios para mostrar." << endl;
    return;
  }

  int elementosPorPagina = 5;
  int pagina = 0;
  int numPaginas =
      (cantidadUsuarios + elementosPorPagina - 1) / elementosPorPagina;

  while (true) {
    rlutil::cls(); // Limpiar la pantalla

    setColor(WHITE);
    cout << "Usuarios con su respectiva contraseña:" << endl;
    cout << "--------------------------------------" << endl;

    int inicio = pagina * elementosPorPagina;
    int fin = std::min(inicio + elementosPorPagina, cantidadUsuarios);

    for (int i = inicio; i < fin; ++i) {
      cout << "Usuario: " << usuarios[i] << endl
           << "Contraseña: " << contrasenas[i] << endl;
      cout << "--------------------------------------" << endl;
    }
    cout << "Página actual: " << pagina + 1 << " de " << numPaginas << endl;
    cout << "\nUsa 'p' para ir a la página siguiente, 'o' para ir a la página "
            "anterior. Presiona 'q' para salir."
         << endl;

    int key = getkey(); // Capturar la tecla presionada

    if (key == 'p' && pagina < numPaginas - 1) {
      pagina++;
    } else if (key == 'o' && pagina > 0) {
      pagina--;
    } else if (key == 'q') { // Salir si presionas 'q'
      break;
    }
  }
}

// Funciones para alquilar o devolver un libro por su ID
void alquilar_libro(int id, string usuario) {
    Tlibro libros[MAX_LIBROS];
    int cantidad = cargarlibros(libros);
    int posicion = -1;

    for (int i = 0; i < cantidad; i++) {
        if (libros[i].id == id) {
            posicion = i;
            break;
        }
    }

    // Verificar si el libro existe
    if (posicion == -1) {
        setColor(WHITE);
        cout << "El libro con ID " << id << " no se encontró." << endl;
        cout << "Presione ENTER para continuar...";
        cin.ignore(); // Limpiar buffer
        cin.get(); // Esperar que el usuario presione ENTER
        return;
    }

    // Verificar si el libro está disponible
    if (libros[posicion].alquilado == false) {
        setColor(WHITE);
        cout << "El libro con ID " << id << " no está disponible para alquiler." << endl;
        cout << "Presione ENTER para continuar...";
        cin.ignore(); // Limpiar buffer
        cin.get(); // Esperar que el usuario presione ENTER
        return;
    }

    // Actualizar el estado del libro en el archivo "libros.txt"
    ofstream archivo_libros("libros.txt");
    for (int i = 0; i < cantidad; i++) {
        if (libros[i].id == id) {
            libros[i].alquilado = false;
        }
        archivo_libros << libros[i].id << "," << libros[i].titulo << ","
                       << libros[i].autor << "," << libros[i].anioPublicacion << ","
                       << libros[i].editorial << "," << libros[i].alquilado << endl;
    }
    archivo_libros.close();

    // Guardar el alquiler del libro en el archivo "alquileres.txt"
    ofstream archivo_alquileres("alquileres.txt", ios::app); // Abre el archivo en modo append
    archivo_alquileres << usuario << "," << id << endl; // Escribe el usuario y el ID del libro
    archivo_alquileres.close();

    // Mostrar el mensaje de éxito y esperar a que el usuario presione ENTER
    setColor(WHITE);
    cout << "El libro con ID " << id << " ha sido alquilado exitosamente." << endl;
    cout << "Presione ENTER para continuar...";
    cin.ignore(); // Limpiar buffer
    cin.get(); // Esperar que el usuario presione ENTER

    // Limpiar la pantalla
    cls();
}

// Funcion para devolver un libro por su ID y actualizar en los archivos
void devolver_libro(int id, string usuario) {
    Tlibro libros[MAX_LIBROS];
    int cantidad = cargarlibros(libros);
    int posicion = -1;

    for (int i = 0; i < cantidad; i++) {
        if (libros[i].id == id) {
            posicion = i;
            break;
        }
    }

    // Verificar si el libro existe
    if (posicion == -1) {
        setColor(WHITE);
        cout << "El libro con ID " << id << " no se encontró." << endl;
        cout << "Presione ENTER para continuar...";
        cin.ignore(); // Limpiar buffer
        cin.get(); // Esperar que el usuario presione ENTER
        return;
    }

    // Verificar si el libro está alquilado por el usuario
    bool libro_alquilado = false;
    ifstream archivo_alquileres("alquileres.txt");
    string linea;
    while (getline(archivo_alquileres, linea)) {
        if (linea == usuario + "," + to_string(id)) {
            libro_alquilado = true;
            break;
        }
    }
    archivo_alquileres.close();

    if (!libro_alquilado) {
        setColor(WHITE);
        cout << "El usuario " << usuario << " no tiene este libro alquilado." << endl;
        cout << "Presione ENTER para continuar...";
        cin.ignore(); // Limpiar buffer
        cin.get(); // Esperar que el usuario presione ENTER
        return;
    }

    // Actualizar el estado del libro en el archivo "libros.txt"
    ofstream archivo_libros("libros.txt");
    for (int i = 0; i < cantidad; i++) {
        if (libros[i].id == id) {
            libros[i].alquilado = true;
        }
        archivo_libros << libros[i].id << "," << libros[i].titulo << ","
                       << libros[i].autor << "," << libros[i].anioPublicacion << ","
                       << libros[i].editorial << "," << libros[i].alquilado << endl;
    }
    archivo_libros.close();

    // Eliminar el registro de alquiler del libro del usuario
    ifstream archivo_alquileres_original("alquileres.txt");
    ofstream archivo_alquileres_temp("alquileres_temp.txt"); // Archivo temporal

    while (getline(archivo_alquileres_original, linea)) {
        // Comprueba si la línea del archivo coincide con el usuario y el ID
        if (linea != usuario + "," + to_string(id)) {
            archivo_alquileres_temp << linea << endl; // Copia la línea al archivo temporal
        }
    }
    archivo_alquileres_original.close();
    archivo_alquileres_temp.close();

    // Renombra el archivo temporal al archivo original
    remove("alquileres.txt");
    rename("alquileres_temp.txt", "alquileres.txt");

    // Mostrar el mensaje de éxito y esperar a que el usuario presione ENTER
    setColor(WHITE);
    cout << "El libro con ID " << id << " ha sido devuelto exitosamente." << endl;
    cout << "Presione ENTER para continuar...";
    cin.ignore(); // Limpiar buffer
    cin.get(); // Esperar que el usuario presione ENTER

    // Limpiar la pantalla
    rlutil::cls();
}

void buscarPorAutor(const string &autor) {
  const int MAX_LIBROS = 100; // Tamaño máximo para el arreglo
  int id[MAX_LIBROS];
  string titulo[MAX_LIBROS], autorLibro[MAX_LIBROS], anio[MAX_LIBROS],
      edicion[MAX_LIBROS], stock[MAX_LIBROS];
  int cantidadLibros = 0;

  ifstream lecturalibros("libros.txt");
  if (!lecturalibros.is_open()) {
    cout << "No se pudo abrir el archivo." << endl;
    return;
  }

  while (lecturalibros >> id[cantidadLibros]) {
    lecturalibros.ignore(); // Ignora la coma

    // Lee el título, autor, año, edición y stock
    getline(lecturalibros, titulo[cantidadLibros], ',');
    getline(lecturalibros, autorLibro[cantidadLibros], ',');
    getline(lecturalibros, anio[cantidadLibros], ',');
    getline(lecturalibros, edicion[cantidadLibros], ',');
    getline(lecturalibros, stock[cantidadLibros]);

    if (autorLibro[cantidadLibros] == autor) {
      cantidadLibros++;
    }
  }
  lecturalibros.close();

  if (cantidadLibros == 0) {
    cout << "No se encontró ningún libro del autor " << autor << "." << endl;
    return;
  }

  int elementosPorPagina = 5;
  int pagina = 0;
  int numPaginas =
      (cantidadLibros + elementosPorPagina - 1) / elementosPorPagina;

  while (true) {
    cls(); // Limpiar la pantalla

    setColor(WHITE);
    cout << "Libros del autor " << autor << ":" << endl;
    cout << "-----------------------" << endl;

    int inicio = pagina * elementosPorPagina;
    int fin = min(inicio + elementosPorPagina, cantidadLibros);

    for (int i = inicio; i < fin; ++i) {
      cout << "ID: " << id[i] << endl;
      cout << "Título: " << titulo[i] << endl;
      cout << "Autor: " << autorLibro[i] << endl;
      cout << "Año: " << anio[i] << endl;
      cout << "Edición: " << edicion[i] << endl;
      cout << "Dispinibilidad: " << (stock[i] == "1" ? "Si" : "No") << endl;
      cout << "-----------------------" << endl;
    }

    cout << "\nUsa 'p' para ir a la página siguiente, 'o' para ir a la página "
            "anterior. Presiona 'q' para salir."
         << endl;

    int key = getkey(); // Capturar la tecla presionada

    if (key == 'p' && pagina < numPaginas - 1) {
      pagina++;
    } else if (key == 'o' && pagina > 0) {
      pagina--;
    } else if (key == 'q') { // Salir si presionas 'q'
      break;
    }
  }
}