//Sistema de biblioteca (libros, autores, usuario)
//Lista de funcionalidades
/*-
-Búsqueda de información y menús (es decir la parte que el usuario puede ingresar lo que quiere buscar y tiene que mostrar) 
- Almacenamiento de datos (eliminar, modificar y añadir)
- ⁠Presentación del programa (interfaces, mostrar resultados de manera linda)*/
#include <iostream>
#include <cstdio>
#include <string>
#include "libros.h"
#include "usuarios.h"
#include "validadores.h"
using namespace std;
int menu();

//Agregar libro -- correcto
//mostrar libros -- correcto
//string archivo = "libros.txt";

int main() {
    int id;
   mostrarlibros();
    cout << "que libro va a eliminar?";
    cin >> id;
    eliminarLibro(id);
mostrarlibros()
    return 0;
}


