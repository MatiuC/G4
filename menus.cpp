#include "usuarios.h"
#include "libros.h"

//Menu principal de inicio

int usuarios (){
  int opcion;
  opcion = menu_usuarios(); 
  while (opcion != 0) { 
    switch (opcion)
    {
    case 1:
        iniciar_sesion();
    break;
    case 2:
        registro();
    break;
    }  
    opcion = menu_usuarios(); 
  }
  return 0;
} 

int menu_usuarios(){
    int op = -1;
    while ((op < 0)|| (op > 3))
    {
        cout << "BIENVENIDO A LA BIBLIOTECA" << endl;      
        cout << " 1. Iniciar sesión " << endl;
        cout << " 2. Registrarse" << endl;
        cout << " 0. Salir " << endl;
        cout << "Ingrese el numero de opcion: ";
        cin >> op;
        if ((op < 0)|| (op > 3)){
            cout << "------ Opción no valida, ingrese una opcion valida. ------" << endl;
        }
    }
    cout << endl;
    return op;
}

// Menu de inicio de sesion USUARIO-ADMINISTRADOR

int iniciar_sesion(){
      int opcion;
      opcion = menu_inicio_sesion(); 
      while (opcion != 0) { 
        switch (opcion)
        {
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

int menu_inicio_sesion(){
    int op = -1;
    while ((op < 0)|| (op > 3))
    {
        cout << "BIENVENIDO AL INICIO DE SESIÓN" << endl;      
        cout << " 1. Usuario " << endl;
        cout << " 2. Administrador" << endl;
        cout << " 0. Regresar " << endl;
        cout << "Ingrese el numero de opcion: ";
        cin >> op;
        if ((op < 0)|| (op > 3)){
            cout << "------ Opción no valida, ingrese una opcion valida. ------" << endl;
        }
    }
    cout << endl;
    return op;
}

//Menu opciones unicamente del usuario 

int menu_usuario(){
    int op = -1;
    while ((op < 0)|| (op > 3))
    {
        cout << "BIENVENIDO AL MENÚ DE USUARIO" << endl;      
        cout << " 1. Alquilar libro " << endl;
        cout << " 2. Devolver libro " << endl;
        cout << " 0. Regresar " << endl;
        cout << "Ingrese el numero de opcion: ";
        cin >> op;
        if ((op < 0)|| (op > 3)){
            cout << "------ Opción no valida, ingrese una opcion valida. ------" << endl;
        }
    }
    cout << endl;
    return op;
}

int opciones_usuario(){
      int opcion;
      opcion = menu_usuario(); 
      while (opcion != 0) { 
        switch (opcion)
        {
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
        }  
        opcion = menu_usuario(); 
      }
      return 0;
}

//Menu opciones unicamente del administrador
int menu_admin(){
    int op = -1;
    while ((op < 0)|| (op > 5))
    {
        cout << "BIENVENIDO AL MENU ADMINISTRADOR " << endl;      
        cout << " 1. Mostrar libros " << endl;
        cout << " 2. Agregar libros " << endl;
        cout << " 3. Modificar libros" << endl;    
        cout << " 4. Mostrar usuarios y contraseña" << endl; 
        cout << " 0. Regresar " << endl;
        cout << "Ingrese el numero de opcion: ";
        cin >> op;
        if ((op < 0)|| (op > 5)){
            cout << "------ Opción no valida, ingrese una opcion valida. ------" << endl;
        }
    }
    cout << endl;
    return op;
}

int opciones_admin(){
      int opcion;
      opcion = menu_admin(); 
      while (opcion != 0) { 
        switch (opcion)
        {
        case 1:
            mostrarlibros();
        break;
        case 2:
            agregarLibro();
        break;
        case 3:
            modificarLibro(2);
        break;
        case 4:
            mostrar_usuarios();  
        break;
        }  
        opcion = menu_admin(); 
      }
      return 0;
}

