#include "usuarios.h"

int cont_usuario = 6;

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
// Funcion para el ingreso al sistema bibliotecario
void iniciar_usuario(){
    string usuario, contrasena;
    int x = 0;
    cout << "Ingrese su usuario: ";
    cin >> usuario;
    cout << "Ingrese su contraseña: ";
    cin >> contrasena;
    ifstream dato_usuario("usuario.txt");
    if (!dato_usuario) {
        cout << "\nArchivo de usuarios no encontrado" << endl;
         return; 
    }
    string a, b;
    while (dato_usuario >> a >> b) {
        if (a == usuario && b == contrasena) {
             x = 1;
             break;
        }
    }
    dato_usuario.close();
     if (x == 1) {
        cout << "Inicio de sesion exitoso" << endl;
    } else {
        cout << "Usuario o contraseña incorrectos" << endl;
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
        opciones_admin();
    }
    else {
        cout << "Inicio de sesion fallido, vuelva a intentar" << endl;
    }
}

void mostrar_usuarios() {
    string usuario, contraseña;
    ifstream lectura_usuario("usuario.txt");

    //Verifica si el archivo existe
    if (!lectura_usuario.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    
    cout << "Usuarios: " << endl << "Contraseña:" << endl; //Separacion de 5 digitos
    
    while (lectura_usuario >> usuario >> contraseña) {
        cout << usuario << endl << contraseña <<  setw(4) << "|" << endl;
        cout << "-------------------------------"  << endl;
    }

    lectura_usuario.close();
}

//Funciones para alquilar o devolver un libro por su ID