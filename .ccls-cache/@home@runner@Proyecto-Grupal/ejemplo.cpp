/*#include <iostream>
#include "rlutil.h"   
#include <cstring> 
using namespace std;

void showMenu(const char* options[], int posx, int posy, int selected) {
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    rlutil::hidecursor();
    for (int i = 0; options[i] != NULL; i++) {
        if (i == selected) {
            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::locate(posx-3, posy + i);
            cout << " " << (char)61 << " " << options[i] << " " << (char)61 << endl;
        } else {
            rlutil::setBackgroundColor(rlutil::BLACK);
            rlutil::locate(posx-3, posy + i);
            cout << options[i] << endl;
        }
    }
    rlutil::setBackgroundColor(rlutil::BLACK);
}
int main() {
    const char* options[] = {"OPCION 1", "OPCION 2", "OPCION 3", "SALIR", NULL};
    int op = 1, y = 0; 
    do {
        rlutil::cls(); 
        showMenu(options, 30, 10, y); 
        switch (rlutil::getkey()) {
            case 65: // Bajar
                y--;
                if (y < 0) {
                    y = 0; 
                }
                break;
            case 66: // subir
                y++;
                if (y >= 4) {
                    y = 4; 
                }
                break;
            case 32: // Enter
                op = y; 
                break;
        }
    } while (op != 3); 
    return 0;
}

*/