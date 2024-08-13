#include "menus.h"
#include "colores.h"
#include "libros.h"
#include "usuarios.h"
// Menu principal de inicio

int menu_usuarios() {
  int op = -1;
  while ((op < 0) || (op > 2)) {
    cout << ROJO << "--------------------------------------" << endl;
    cout << LGREEN << R"(
+--------------------------+
|BIENVENIDO A LA BIBLIOTECA|
+--------------------------+
)" << endl;
    // cout << LGREEN << "///BIENVENIDO A LA BIBLIOTECA///" << endl;
    cout << GRIS << " 1. Iniciar sesión " << endl;
    cout << " 2. Registrarse" << endl;
    cout << " 0. Salir " << endl;
    cout << "Ingrese el numero de opcion: ";
    cin >> op;
    if ((op < 0) || (op > 2)) {
      cout << ROJO
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
      cout << ROJO
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
    cout << ROJO << "--------------------------------------" << endl;
    cout << LGREEN << R"(
+------------------------------+
|BIENVENIDO AL INICIO DE SESION|
+------------------------------+
)" << endl;
    // cout << LGREEN << "///BIENVENIDO AL INICIO DE SESIÓN///" << endl;
    cout << GRIS << " 1. Usuario " << endl;
    cout << " 2. Administrador" << endl;
    cout << " 0. Regresar " << endl;
    cout << "Ingrese el numero de opcion: ";
    cin >> op;
    if ((op < 0) || (op > 3)) {
      cout << ROJO
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
      iniciar_usuario();
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
  while ((op < 0) || (op > 4)) {
    cout << GRIS << "--------------------------------------" << endl;
    cout << LGREEN << R"(
+-------------------+
|MENU ADMINISTRATIVO|
+-------------------+
        )"
         << endl;
    // cout << LGREEN << "///MENU ADMINISTRATIVO///" << endl;
    cout << GRIS << " 1. Mostrar libros " << endl;
    cout << " 2. Agregar libros " << endl;
    cout << " 3. Modificar libros" << endl;
    cout << " 4. Mostrar usuarios y contraseña" << endl;
    cout << " 0. Cerrar Sesión " << endl;
    cout << "Ingrese el numero de opcion: ";
    cin >> op;
    if ((op < 0) || (op > 4)) {
      cout << ROJO
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
      cout << ROJO
           << "Ingrese el ID del libro que desea modificar: " << RESTABLECER
           << endl;
      cin >> id;
      modificarLibro(id);
      break;
    case 4:
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
    cout << GRIS << "--------------------------------------" << endl;
    cout << LGREEN << R"(
+-----------------------------+
|BIENVENIDO AL MENU DE USUARIO|
+-----------------------------+
)" << endl;
    // cout << LGREEN << "///BIENVENIDO AL MENÚ DE USUARIO///" << endl;
    cout << GRIS << " 1. Alquilar libro " << endl;
    cout << " 2. Devolver libro " << endl;
    cout << " 3. Buscar libro " << endl;
    cout << " 0. Cerrar Sesión " << endl;
    cout << "Ingrese el numero de opcion: ";
    cin >> op;
    if ((op < 0) || (op > 3)) {
      cout << ROJO
           << "------ Opción no valida, ingrese una opcion valida. ------"
           << endl;
    }
  }
  cout << endl;
  return op;
}

int opciones_usuario() {
  int opcion, a, b;
  opcion = menu_usuario();
  while (opcion != 0) {
    switch (opcion) {
    case 1:
      cout << " " << endl;
      cout << "Ingrese la id del libro que desea alquilar:" << endl;
      cin >> a;
      alquilar_libro(a, "derek");
      break;
    case 2:
      cout << " " << endl;
      cout << "Ingrese la id del libro que desea devolver:" << endl;
      cin >> b;
      devolver_libro(b, "derek");
      break;
    case 3:
      mostrarlibros();
      break;
    }
    opcion = menu_usuario();
  }
  return 0;
}
