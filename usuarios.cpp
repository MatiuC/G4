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
  int x = 0;
  cout << "--------------------------------------" << endl;
  setColor(WHITE);
  cout << "Ingrese su usuario: ";
  cin >> usuario;
  setColor(WHITE);
  cout << "Ingrese su contraseña: ";
  cin >> contrasena;
  ifstream dato_usuario("usuario.txt");
  if (!dato_usuario) {
    cout << "\nArchivo de usuarios no encontrado" << endl;
    return " ";
  }
  string a, b;
  while (dato_usuario >> a >> b) {
    if (a == usuario && b == contrasena) {
      x = 1;
      break;
    }
  }
  dato_usuario.close();

  // Validador de inicio de sesion exitoso
  if (x == 1) {
    setColor(WHITE);
    cout << "Inicio de sesion exitoso" << endl;
    opciones_usuario();
  } else {
    setColor(RED);
    cout << "Usuario o contraseña incorrectos" << endl;
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
  lectura_admin.open("u_admin.txt");
  lectura_admin >> admin;
  lectura_admin >> contraseña;
  lectura_admin.close();
  cout << "--------------------------------------" << endl;
  setColor(WHITE);
  cout << "Ingrese su usuario: ";
  cin >> admin1;
  setColor(WHITE);
  cout << "Ingrese su contraseña: ";
  cin >> contraseña1;
  if (admin == admin1 && contraseña == contraseña1) {
    cout << "Inicio de sesion exitoso" << endl;
    opciones_admin();
  } else {
  setColor(RED);
    cout << "////// Inicio de sesion fallido, vuelva a intentar //////" << endl;
  }
}

void mostrar_usuarios() {
  string usuario, contraseña;
  ifstream lectura_usuario("usuario.txt");

  // Verifica si el archivo existe
  if (!lectura_usuario.is_open()) {
    setColor(RED);
    cout << "Error al abrir el archivo." << endl;
    return;
  }
  setColor(WHITE);
  cout << "Usuarios con su respectiva contraseña:" << endl;
  cout << "--------------------------------------" << endl;
  while (lectura_usuario >> usuario >> contraseña) {
    setColor(WHITE);
    cout  << "Usuario: "  << usuario << endl
          << "Contraseña: "  << contraseña << endl;
    cout << "--------------------------------------" << endl;
  }

  lectura_usuario.close();
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
    return;
  }
  // Verificar si el libro está disponible
  if (libros[posicion].alquilado == false) {
    setColor(WHITE);
    cout << "El libro con ID " << id << " no está disponible para alquiler."
         << endl;
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
  ofstream archivo_alquileres("alquileres.txt",
                              ios::app); // Abre el archivo en modo append
  archivo_alquileres << usuario << "," << id
                     << endl; // Escribe el usuario y el ID del libro
  archivo_alquileres.close();

  cout << "El libro con ID " << id << " ha sido alquilado exitosamente."
       << endl;
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
    cout << "El libro con ID " << id << " no se encontró." << endl;
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
    cout << "El usuario " << usuario << " no tiene este libro alquilado."
         << endl;
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
      archivo_alquileres_temp << linea
                              << endl; // Copia la línea al archivo temporal
    }
  }
  archivo_alquileres_original.close();
  archivo_alquileres_temp.close();

  // Renombra el archivo temporal al archivo original
  remove("alquileres.txt");
  rename("alquileres_temp.txt", "alquileres.txt");

  cout << "El libro con ID " << id << " ha sido devuelto exitosamente." << endl;
}

void buscarPorAutor(const string& autor) {
  string id, titulo, autorLibro, anio, edicion, stock;
  bool encontrado = 0;
    ifstream lecturalibros("libros.txt");
    if (!lecturalibros.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
    }
  else{
    while (lecturalibros >> id) {
          lecturalibros.ignore(); // Ignora la coma

        // Lee mi título, autor, año, edición y stock
        getline(lecturalibros, titulo, ',');
        getline(lecturalibros, autorLibro, ',');
        getline(lecturalibros, anio, ',');
        getline(lecturalibros, edicion, ',');
        getline(lecturalibros, stock);

        if (autorLibro == autor) { //Compara el autor ingresado con el autor del libro
            cout << "ID: " << id << endl;
            cout << "Título: " << titulo << endl;
            cout << "Autor: " << autorLibro << endl;
            cout << "Año: " << anio << endl;
            cout << "Edición: " << edicion << endl;
            cout << "Stock: " << stock << endl;
            cout << "-----------------------" << endl;
            encontrado = 1;
        }
    }

    if (!encontrado) {
        cout << "No se encontró ningún libro del autor " << autor << "." << endl;
    }

    lecturalibros.close();
  }
}