#include "menus.h"
#include "libros.h"
#include "usuarios.h"
#include "rlutil.h"

string user = " ";

void showMenu(const char* options[], int posx, int posy, int selected) {
    setBackgroundColor(BLACK);
    setColor(WHITE);
    hidecursor();
    for (int i = 0; options[i] != NULL; i++) {
        if (i == selected) {
            setBackgroundColor(BLUE);
            locate(posx , posy + i);
            cout << " " << (char)61 << " " << options[i] << " " << (char)61 << endl;
        } else {
            setBackgroundColor(BLACK);
            locate(posx + 12, posy + i);
            cout << options[i] << endl;
        }
    }
    setBackgroundColor(BLACK);
}

//Menu principal de inicio

int usuarios() {
    const char* options[] = {"INICIAR SESION", "REGISTRARSE", "SALIR", NULL};
    int op = 1, y = 0; 
    do {
        cls(); 
        showMenu(options, 30, 10, y); 
        switch (getkey()) {
            case 65: // Bajar
                y--;
                if (y < 0) {
                    y = 0; 
                }
                break;
            case 66: // subir
                y++;
                if (y > 2) {
                    y = 2; 
                }
                break;
            case 32: // Espacio
                 if (y == 0) {
                     iniciar_sesion();
                 } else if (y == 1){
                    registro ();
                 } else {
                     exit(0);
                 }
                 break;
                
        }
    } while ((op != 2 ));
    return 0;
}


// Menu de inicio de sesion USUARIO-ADMINISTRADOR
int iniciar_sesion() {
    const char* options[] = {"USUARIO", "ADMINISTRADOR", "SALIR", NULL};
    int op = 1, y = 0; 
    do {
        cls(); 
        showMenu(options, 30, 10, y); 
        switch (getkey()) {
            case 65: // Bajar
                y--;
                if (y < 0) {
                    y = 0; 
                }
                break;
            case 66: // subir
                y++;
                if (y > 2) {
                    y = 2; 
                }
                break;
            case 32: // Espacio
                if (y == 0) {
                    iniciar_usuario(user);
                } else if (y == 1) {
                    iniciar_admin();
                } else {
                    usuarios();
                }
                break;
        }
    } while (op != 2); 
    return 0;
}


// Menu opciones unicamente del administrador
int opciones_admin() {
  int id;
  const char* options[] = {"MOSTRAR LIBROS", "AGREGAR LIBROS", "MODIFICAR LIBROS", "MOSTRAR USUARIOS Y CONTRASEÑAS","CERRAR SESION", NULL};
      int op = 1, y = 0; 
      do {
          cls(); 
          showMenu(options, 30, 10, y); 
          switch (getkey()) {
              case 65: // Bajar
                  y--;
                  if (y < 0) {
                      y = 0; 
                  }
                  break;
              case 66: // subir
                  y++;
                  if (y > 5) {
                      y = 5; 
                  }
                  break;
              case 32: // Espacio
                  if (y == 0) {
                      mostrarlibros();
                    break;
                  } else if (y == 1) {
                      agregarLibro();
                    break;
                  } else if (y== 2) {
                      cout << "Ingrese el ID del libro que desea modificar: " 
                         << endl;
                      cin >> id;
                      modificarLibro(id);
                    break;
                  } else if (y == 3){  
                       mostrar_usuarios();
                    break;
                  } else {
                      iniciar_sesion();
                  }
                  break;
          }
      } while (op != 3); 
      return 0;
  }

int opciones_usuario() {
  int  a, b;
      string autor;
      const char* options[] = {"MOSTRAR CATALOGO", "ALQUILAR LIBRO", "DEVOLVER LIBRO", "MOSTRAR LIBROS DISPONIBLES", "BUSCAR LIBRO POR AUTOR", "CERRAR SESION" , NULL};
      int op = 1, y = 0; 
      do {
          cls(); 
          showMenu(options, 30, 10, y); 
          switch (getkey()) {
              case 65: // Bajar
                  y--;
                  if (y < 0) {
                      y = 0; 
                  }
                  break;
              case 66: // subir
                  y++;
                  if (y > 5) {
                      y = 5; 
                  }
                  break;
              case 32: // Espacio
                if (y ==0 ) {
                      mostrarlibros();
                }else if (y == 1) {
                      cout << " " << endl;
                      cout << "Ingrese la id del libro que desea alquilar:" << endl;
                      cin >> a;
                      alquilar_libro(a, user);
                    break;
                } else if (y == 2) {
                      cout << " " << endl;
                      cout << "Ingrese la id del libro que desea devolver:" << endl;
                      cin >> b;
                      devolver_libro(b, user);
                    break;
                } else if (y == 3) {
                    buscarDisponibles();
                    break;
                  }else if (y == 4){
                      cout << "Ingrese el nombre del autor: ";
                      getline(cin, autor);
                      buscarPorAutor(autor);
                  } else {
                      iniciar_sesion();
                  }
                  break;
          }
      } while (op != 4); 

  return 0;
}
