#


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring> //biblioteca donde estan las funciones de manejo de cadenas
using namespace std;


void registro();
int iniciar_sesion();
void iniciar_admin();
void iniciar_usuario();
int menu_usuarios();
int opciones_usuario();
int menu_admin();
int opciones_admin();
void mostrar_usuarios();
int menu_inicio_sesion(); 
void existencia_usuario();
bool verificar_existencia_usuario(char a[]);

int usuarios ();
const int MAX = 50;

typedef struct {
    char usuario[MAX], contrasena[MAX];
}tUsuario;

