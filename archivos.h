#pragma once
#include <iostream>
#include <fstream>
using namespace std;

typedef struct{
  int id;
  string nombre;
  string autor;
  string editorial;
  int year;
  bool disponibilidad;
} tDatos;

//Funciones
void leerfile (const string& namefile);
void escribirfile(const string &filename);