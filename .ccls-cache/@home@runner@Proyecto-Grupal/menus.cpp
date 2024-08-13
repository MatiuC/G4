#include "menus.h"
#include "libros.h"
#include "usuarios.h"
// Menu principal de inicio
string user = " ";
int menu_usuarios() {
  int op = -1;
  while ((op < 0) || (op > 2)) {
    setColor(GREEN);
    cout  << "--------------------------------------" << endl;
    cout << R"(
+--------------------------+
|BIENVENIDO A LA BIBLIOTECA|
+--------------------------+
)" << endl;
    setColor(WHITE);
    cout <<  " 1. Iniciar sesión " << endl;
    setColor(WHITE);
    cout << " 2. Registrarse" << endl;
    setColor(WHITE);
    cout << " 0. Salir " << endl;
    setColor(LIGHTCYAN);
    cout << "Ingrese el numero de opcion: ";
    cin >> op;
    if ((op < 0) || (op > 2)) {
      setColor(RED);
      cout 
           << "------ Opción no valida, ingrese una opcion valida. ------"
           << endl;
    }
  }
  cout << endl;
  return op;
}

int usuarios() {
  int opcion;
  opcion = menu_usuarios();
  while (opcion != 0) {
    switch (opcion) {
    case 1:
      iniciar_sesion();
      break;
    case 2:
      registro();
      break;
    default: {
      cout
           << "------ Opción no valida, ingrese una opcion valida. ------"
           << endl;
      break;
    }
    }
    opcion = menu_usuarios();
  }
  return 0;
}

// Menu de inicio de sesion USUARIO-ADMINISTRADOR

int menu_inicio_sesion() {
  int op = -1;
  while ((op < 0) || (op > 3)) {
    setColor(GREEN);
    cout << "--------------------------------------" << endl;
    cout << R"(
+------------------------------+
|BIENVENIDO AL INICIO DE SESION|
+------------------------------+
)" << endl;
    setColor(WHITE);
    cout  << " 1. Usuario " << endl;
    setColor(WHITE);
    cout << " 2. Administrador" << endl;
    setColor(WHITE);
    cout << " 0. Regresar " << endl;
    setColor(LIGHTCYAN);
    cout << "Ingrese el numero de opcion: ";
    cin >> op;
    if ((op < 0) || (op > 3)) {
      setColor(RED);
      cout 
           << "------ Opción no valida, ingrese una opcion valida. ------"
           << endl;
    }
  }
  cout << endl;
  return op;
}

int iniciar_sesion() {
  int opcion;
  opcion = menu_inicio_sesion();
  while (opcion != 0) {
    switch (opcion) {
    case 1:
      user = iniciar_usuario(user);
      break;
    case 2:
      iniciar_admin();
      break;
    }
    opcion = menu_inicio_sesion();
  }

  return 0;
}

// Menu opciones unicamente del administrador
int menu_admin() {
  int op = -1;
  while ((op < 0) || (op > 5)) {
    setColor(GREEN);
    cout  << "--------------------------------------" << endl;
    cout  << R"(
+-------------------+
|MENU ADMINISTRATIVO|
+-------------------+
        )"
         << endl;
    // cout << LGREEN << "///MENU ADMINISTRATIVO///" << endl;
    setColor(WHITE);
    cout  << " 1. Mostrar libros " << endl;
    setColor(WHITE);
    cout << " 2. Agregar libros " << endl;
    setColor(WHITE);
    cout << " 3. Modificar libros" << endl;
    setColor(WHITE);
    cout << " 4. Eliminar libros" << endl;
    setColor(WHITE);
    cout << " 5. Mostrar usuarios y contraseña" << endl;
    cout << " 0. Cerrar Sesión " << endl;
    setColor(LIGHTCYAN);
    cout << "Ingrese el numero de opcion: ";
    cin >> op;
    if ((op < 0) || (op > 5)) {
      setColor(RED);
      cout 
           << "------ Opción no valida, ingrese una opcion valida. ------"
           << endl;
    }
  }
  cout << endl;
  return op;
}

int opciones_admin() {
  int opcion, id;
  opcion = menu_admin();
  while (opcion != 0) {
    switch (opcion) {
    case 1:
      mostrarlibros();
      break;
    case 2:
      agregarLibro();
      break;
    case 3:
      setColor(WHITE);
      cout << "Ingrese el ID del libro que desea modificar: " 
           << endl;
      cin >> id;
      modificarLibro(id);
      break;
    case 4:
      setColor(WHITE);
      cout 
           << "Ingrese el ID del libro que desea eliminar: ";
      cin >> id;
      eliminarLibro(id);
        break;
    case 5:
      mostrar_usuarios();
      break;
    }
    opcion = menu_admin();
  }
  return 0;
}

// Menu opciones unicamente del usuario

int menu_usuario() {
  int op = -1;
  while ((op < 0) || (op > 3)) {
    setColor(GREEN);
    cout  << "--------------------------------------" << endl;
    cout  << R"(
+-----------------------------+
|BIENVENIDO AL MENU DE USUARIO|
+-----------------------------+
)" << endl;
    // cout << LGREEN << "///BIENVENIDO AL MENÚ DE USUARIO///" << endl;
    setColor(WHITE);
    cout << " 1. Alquilar libro " << endl;
    setColor(WHITE);
    cout << " 2. Devolver libro " << endl;
    setColor(WHITE);
    cout << " 3. Buscar libro " << endl;
    setColor(WHITE);
    cout << " 0. Cerrar Sesión " << endl;
    setColor(LIGHTCYAN);
    cout << "Ingrese el numero de opcion: ";
    cin >> op;
    if ((op < 0) || (op > 3)) {
      setColor(RED);
      cout << "------ Opción no valida, ingrese una opcion valida. ------"
           << endl;
    }
  }
  cout << endl;
  return op;
}

int opciones_usuario() {
  int opcion, a, b;
  setColor(WHITE);
  cout << "usuario actual: " << user << endl;

  opcion = menu_usuario();
  while (opcion != 0) {
    switch (opcion) {
    case 1:
      cout << " " << endl;
      setColor(WHITE);
      cout << "Ingrese la id del libro que desea alquilar:" << endl;
      cin >> a;
      alquilar_libro(a, user);
      break;
    case 2:
      cout << " " << endl;
      setColor(WHITE);
      cout << "Ingrese la id del libro que desea devolver:" << endl;
      cin >> b;
      devolver_libro(b, user);
      break;
    case 3:
      mostrarlibros();
      break;
    }
    opcion = menu_usuario();
  }
  return 0;
}
