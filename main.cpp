#include <iostream>
#include "calendario.h"
using namespace std;


int main() {
    Calendario mi_calendario;

    // Agregar algunas tareas
    mi_calendario.agregar_tarea(Tarea("Estudiar C++", "2025-09-27", 1, 120));
    mi_calendario.agregar_tarea(Tarea("Dormir", "2025-09-26", 2, 480));
    mi_calendario.agregar_tarea(Tarea("Ejercicio", "2025-09-26", 3, 60));
    mi_calendario.agregar_tarea(Tarea("Jugar videojuegos", "2025-09-28", 5, 180));

    // Mostrar
    mi_calendario.mostrar_tareas();

    // Ordenadas por prioridad 
    cout << "\n- Ordenadas por prioridad (Bubble sort)\n";
    mi_calendario.bubble_sort_prioridad();
    mi_calendario.mostrar_tareas();

    // Ordenadas por duracion
    cout << "\n- Ordenadas por duración (Selection sort)\n";
    mi_calendario.selec_sort_duracion();
    mi_calendario.mostrar_tareas();

    // Ordenadas por fecha
    cout << "\n- Ordenadas por fecha (Merge sort)\n";
    mi_calendario.ordenar_p_fecha();
    mi_calendario.mostrar_tareas();

    return 0;
}