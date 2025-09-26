#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// CLASE TAREA 
class Tarea {
public:
    string nombre;
    string fecha;     // año/mes/día
    int prioridad;    // 1 = alta / 5 = baja
    int duracion;     // en minutos
    bool completada;

    // Constructor
    Tarea(string n="", string f="", int p=5, int d=0) {
        nombre = n;
        fecha = f;
        prioridad = p;
        duracion = d;
        completada = false;
    }

    // Visualizacion de la tarea
    void visualizar() {
        cout << nombre << " | Fecha: " << fecha 
             << " | Prioridad: " << prioridad   
             << " | Duración: " << duracion << " mins" 
             << " | Estado: ";
             if (completada){
                cout << "Hecha";
             } else {
                cout << "Pendiente";
             }              
                cout << endl;
    }
};
#endif 