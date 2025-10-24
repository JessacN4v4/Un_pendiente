#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H

#include <iostream>
#include <string>
using namespace std;

// Clase Actividad
class Actividad {
public:
    string nombre;
    int prioridad;
    bool completada;

    Actividad(string n = "", int p = 0) : nombre(n), prioridad(p), completada(false) {}
    void mostrar();
};

#endif
