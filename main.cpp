#include <iostream>
#include "gestor.h"
using namespace std;

int main() {
    Gestor gestor;
    int opcion;

    do {
        cout << "\n1. Agregar actividad\n";
        cout << "2. Mostrar actividades\n";
        cout << "3. Marcar completada\n";
        cout << "4. Eliminar actividad\n";
        cout << "5. Ordenar (Bubble / Selection / Merge)\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string nombre; int prioridad;
            cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
            cout << "Prioridad: "; cin >> prioridad;
            gestor.agregar(Actividad(nombre, prioridad));
            break;
        }
        case 2: gestor.mostrar(); break;
        case 3: {
            int i; cout << "Numero: "; cin >> i;
            gestor.marcar(i); break;
        }
        case 4: {
            int i; cout << "Numero: "; cin >> i;
            gestor.eliminar(i); break;
        }
        case 5: {
            int m;
            cout << "1. Bubble\n2. Selection\n3. Merge\nMetodo: ";
            cin >> m;
            if (m == 1) gestor.bubble_sort();
            else if (m == 2) gestor.selection_sort();
            else if (m == 3) gestor.ordenar_merge();
            break;
        }
        }
    } while (opcion != 0);

    cout << "Programa finalizado.\n";
    return 0;
}
