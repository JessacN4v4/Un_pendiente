#include <iostream>
#include <limits>
#include "gestor.h"
using namespace std;

void mostrar_menu() {
    cout << "\n " << endl;
    cout << "    SISTEMA MIS PENDIENTES         " << endl;
    cout << " " << endl;
    cout << "1.  Agregar una nueva actividad" << endl;
    cout << "2.  Ver lista de actividades" << endl;
    cout << "3.  Marcar una actividad como completada" << endl;
    cout << "4.  Eliminar una actividad" << endl;
    cout << "5.  Ordenar las actividades por prioridad" << endl;
    cout << "6.  Ver primera actividad" << endl;
    cout << "7.  Ver última actividad" << endl;
    cout << "8.  Ver actividad por número" << endl;
    cout << "9.  Buscar por prioridad" << endl;
    cout << "10. Ver estadísticas" << endl;
    cout << "11. Salir" << endl;
    cout << "─────────────────────────────────────────" << endl;
    cout << "Selecciona una opción: ";
}

void limpiar_buffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pausar() {
    cout << "\nPresiona Enter para continuar...";
    cin.get();
}

int main() {
    Gestor_actividades gestor;
    int opcion;
    
    cout << "\n " << endl;
    cout << "  Bienvenido al Sistema de Organización Personal  " << endl;
    cout << "           y Académica - Mis Pendientes            " << endl;
    cout << " \n" << endl;
    
    do {
        mostrar_menu();
        cin >> opcion;
        limpiar_buffer();
        
        switch(opcion) {
            case 1: {
                string nombre, tipo;
                int prioridad;
                
                cout << "\n " << endl;
                cout << "   AGREGAR NUEVA ACTIVIDAD        " << endl;
                cout << " " << endl;
                
                cout << "Nombre de la actividad: ";
                getline(cin, nombre);
                
                cout << "Tipo (Clase/Tarea/Personal/Dormir/Descanso): ";
                getline(cin, tipo);
                
                cout << "Prioridad (1-10, donde 10 es máxima prioridad): ";
                cin >> prioridad;
                limpiar_buffer();
                
                if (prioridad < 1 || prioridad > 10) {
                    cout << " Prioridad inválida. Debe estar entre 1 y 10." << endl;
                    pausar();
                    break;
                }
                
                Actividad nuevaActividad(nombre, tipo, prioridad);
                gestor.agregar_actividad(nuevaActividad);
                pausar();
                break;
            }
            
            case 2: {
                gestor.mostrar_actividades();
                pausar();
                break;
            }
            
            case 3: {
                if (gestor.get_cantidad_actividades() == 0) {
                    cout << "No hay actividades registradas." << endl;
                    pausar();
                    break;
                }
                
                gestor.mostrar_actividades();
                cout << "\n Ingresa el número de la actividad a marcar como completada: ";
                int indice;
                cin >> indice;
                limpiar_buffer();
                
                gestor.marcar_completada(indice - 1);
                pausar();
                break;
            }
            
            case 4: {
                if (gestor.get_cantidad_actividades() == 0) {
                    cout << "No hay actividades registradas." << endl;
                    pausar();
                    break;
                }
                
                gestor.mostrar_actividades();
                cout << "\nIngresa el número de la actividad a eliminar: ";
                int indice;
                cin >> indice;
                limpiar_buffer();
                
                gestor.eliminar_actividad(indice - 1);
                pausar();
                break;
            }
            
            case 5: {
                cout << "\n " << endl;
                cout << "  ORDENAR ACTIVIDADES POR PRIORIDAD   " << endl;
                cout << " " << endl;
                gestor.ordenar_prioridad();
                cout << "\n Actividades ordenadas:" << endl;
                gestor.mostrar_actividades();
                pausar();
                break;
            }
            
            case 6: {
                gestor.mostrar_primera();
                pausar();
                break;
            }
            
            case 7: {
                gestor.mostrar_ultima();
                pausar();
                break;
            }
            
            case 8: {
                if (gestor.get_cantidad_actividades() == 0) {
                    cout << "No hay actividades registradas." << endl;
                    pausar();
                    break;
                }
                
                cout << "Ingresa el número de la actividad (1-" << gestor.get_cantidad_actividades() << "): ";
                int indice;
                cin >> indice;
                limpiar_buffer();
                
                gestor.mostrar_por_indice(indice - 1);
                pausar();
                break;
            }
            
            case 9: {
                cout << "Ingresa la prioridad a buscar (1-10): ";
                int prioridad;
                cin >> prioridad;
                limpiar_buffer();
                
                if (prioridad < 1 || prioridad > 10) {
                    cout << " Prioridad inválida." << endl;
                } else {
                    gestor.buscar_por_prioridad(prioridad);
                }
                pausar();
                break;
            }
            
            case 10: {
                gestor.mostrar_estadisticas();
                pausar();
                break;
            }
            
            case 11: {
                cout << "\n " << endl;
                cout << "  Guardando datos...                   " << endl;
                cout << "  Gracias por usar Mis Pendientes      " << endl;
                cout << "  ¡Hasta pronto!                       " << endl;
                cout << " \n" << endl;
                break;
            }
            
            default: {
                cout << " Opción inválida. Por favor intenta de nuevo." << endl;
                pausar();
                break;
            }
        }
        
    } while(opcion != 11);
    
    return 0;
}
