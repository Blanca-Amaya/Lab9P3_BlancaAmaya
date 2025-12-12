#include <iostream>
#include <cstdlib>
#include "Fabrica.h"
using namespace std;

void menu() {
    Fabrica* fabrica = new Fabrica();
    int opcion;
    bool resp = true;
    while (resp) {
        cout << "----- TOYOTA -----" << endl;
        cout << "1. Crear nuevo carro" << endl;
        cout << "2. Listar todos los carros" << endl;
        cout << "3. Listar carros con defectos" << endl;
        cout << "4. Listar carros con defectos" << endl;
        cout << "5. Guardar carros" << endl;
        cout << "6. Cargar carros" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccion una opcion: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            fabrica->agregarCarroNuevo();
            break;
        case 2:
            fabrica->listarTodos();
            break;
        case 3:

        case 4:

        case 5:

        case 6:

        case 7:
            cout << "Saliendo..." << endl;
            resp = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    }
}

int main() {
    menu();
}