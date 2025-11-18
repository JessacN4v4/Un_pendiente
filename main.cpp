#include <iostream>
#include <limits>
#include "gestor.h"
using namespace std;

void mostrar_menu() {
    cout << "    SISTEMA MIS PENDIENTES" << endl;
    cout << " " << endl;
    cout << "1. Agregar una nueva actividad" << endl;
    cout << "2. Ver lista de actividades" << endl;
    cout << "3. Marcar una actividad como completada" << endl;
    cout << "4. Eliminar una actividad" << endl;
    cout << "5. Ordenar las actividades por prioridad" << endl;
    cout << "6. Salir" << endl;
    cout << " " << endl;
    cout << "Selecciona una opción: ";
}

void limpiar_buffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Gestor_actividades gestor;
    int opcion;
    
    cout << "Bienvenido al Sistema de Organización Personal y Académica" << endl;
    
    do {
        mostrar_menu();
        cin >> opcion;
        limpiar_buffer();
        
        switch(opcion) {
            case 1: {
                string nombre, tipo;
                int prioridad;
                
                cout << "\n AGREGAR NUEVA ACTIVIDAD " << endl;
                cout << "Nombre de la actividad: ";
                getline(cin, nombre);
                
                cout << "Tipo (Clase/Tarea/Personal/Dormir/Descanso): ";
                getline(cin, tipo);
                
                cout << "Prioridad (1-10, donde 10 es máxima prioridad): ";
                cin >> prioridad;
                limpiar_buffer();
                
                if (prioridad < 1 || prioridad > 10) {
                    cout << "Prioridad inválida. Debe estar entre 1 y 10." << endl;
                    break;
                }
                
                Actividad nuevaActividad(nombre, tipo, prioridad);
                gestor.agregar_actividad(nuevaActividad);
                break;
            }
            
            case 2: {
                gestor.mostrar_actividades();
                break;
            }
            
            case 3: {
                if (gestor.get_cantidad_actividades() == 0) {
                    cout << "No hay actividades registradas." << endl;
                    break;
                }
                
                gestor.mostrar_actividades();
                cout << "\nIngresa el número de la actividad a marcar como completada: ";
                int indice;
                cin >> indice;
                limpiar_buffer();
                
                gestor.marcar_completada(indice - 1);
                break;
            }
            
            case 4: {
                if (gestor.get_cantidad_actividades() == 0) {
                    cout << "No hay actividades registradas." << endl;
                    break;
                }
                
                gestor.mostrar_actividades();
                cout << "\nIngresa el número de la actividad a eliminar: ";
                int indice;
                cin >> indice;
                limpiar_buffer();
                
                gestor.eliminar_actividad(indice - 1);
                break;
            }
            
            case 5: {
                cout << "\n ORDENAR ACTIVIDADES POR PRIORIDAD " << endl;
                gestor.ordenar_prioridad();
                cout << "\nActividades ordenadas:" << endl;
                gestor.mostrar_actividades();
                break;
            }
            
            case 6: {
                cout << "\nGracias por usar el Sistema Mis Pendientes. ¡Hasta pronto!" << endl;
                break;
            }
            
            default: {
                cout << "Opción inválida. Por favor intenta de nuevo." << endl;
                break;
            }
        }
        
    } while(opcion != 6);
    
    return 0;
}
