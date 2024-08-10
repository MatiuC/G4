#include "usuarios.h"

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

//Funion para mostrar el menu de ingreso o registro al programa
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

// Funcion para el registro de un nuevo usuario al sistema 
void registro(){
    tUsuario persona[MAX];
    int i = 0;
    bool usuario_existe = true; 
    char usuario[MAX];
    
  while (usuario_existe) {
      cout << "Ingrese su usuario: ";
      cin >> usuario; 
      //Funcion para verificar la existencia o no de un usuario para que no se repita
      usuario_existe= verificar_existencia_usuario(usuario); 
      if (usuario_existe) {
          cout << "El usuario ya existe. Ingrese otro usuario: " << endl;
      }
  }
    //strcpy permite copiar el contenido de una cadena a otra
    strcpy(persona[i].usuario, usuario); 
    cout << "Ingrese su contraseña: ";
    cin >> persona[i].contrasena;
    ofstream dato_usuario; 
    //ios::app permite agregar nuevos datos en un archivo ya escrito
    dato_usuario.open("usuario.txt", ios::app);
    dato_usuario << persona[i].usuario << " " << persona[i].contrasena << endl; 
    cout << "\nRegistro exitoso" << endl;
} 
//Funcion para el ingreso al sistema bibliotecario
void iniciar_usuario(){
    tUsuario persona[MAX];
    char a[MAX], b[MAX]; 
    int i = 0;
    ifstream dato_usuario;
    dato_usuario.open("usuario.txt");
    dato_usuario>> a;
    dato_usuario>> b;
    dato_usuario.close();
    cout << "Ingrese su usuario: " ;
    cin >> persona[i].usuario;
    cout << "Ingrese su contraseña: " ;
    cin >> persona[i].contrasena;
    if (a == persona[i].usuario && b == persona[i].contrasena){
            cout << "Inicio de sesion exitoso" << endl;
        }
        else {
            cout << "Inicio de sesion fallido, vuelva a intentar" << endl;
        }
}

//Funcion que permite saber si el usuario ingresado ya existe o no 
bool verificar_existencia_usuario(char a[])
{
  char line[MAX]; 
  ifstream dato_usuario("usuario.txt"); 
  while (dato_usuario >> line){
      if (strcmp(line, a) == 0) {
          return true; 
      }
  }
  return false;
}

//Funcion para el ingreso al sistema administrativo

void iniciar_admin(){
    string admin, contraseña, admin1, contraseña1;
    ifstream lectura_admin;
        lectura_admin.open("u_admin.txt");
          lectura_admin>> admin;
          lectura_admin>> contraseña;
        lectura_admin.close();
    cout << "Ingrese su usuario: " ;
    cin >> admin1;
    cout << "Ingrese su contraseña: " ;
    cin >> contraseña1;
    if (admin == admin1 && contraseña == contraseña1){
        cout << "Inicio de sesion exitoso" << endl;
    }
    else {
        cout << "Inicio de sesion fallido, vuelva a intentar" << endl;
    }
}

//Funcion para elegir el tipo de usuario al que se quiere ingresar
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

//Funcion para mostrar el menu de inicio de sesion

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

