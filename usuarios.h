#ifndef USUARIOS_H
#define USUARIOS_H

//#include "libros.h"
#include <cctype>
#include <cstring> //biblioteca donde estan las funciones de manejo de cadenas
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//variable global


void registro();
bool verificar_existencia_usuario(char a[]);
string iniciar_usuario(string &usuario);
void iniciar_admin();
void mostrar_usuarios();

// ALQUILER
void alquilar_libro(int id, string usuario);
void devolver_libro(int id, string usuario);

const int MAX = 50;

typedef struct {
  char usuario[MAX], contrasena[MAX];
} tUsuario;

#endif
