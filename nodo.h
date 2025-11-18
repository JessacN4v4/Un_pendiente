#ifndef NODO_H
#define NODO_H

#include "actividad.h"

class Nodo {
public:
    Actividad datos;
    Nodo* siguiente;
    Nodo* anterior;
    
    // Constructor
    Nodo(const Actividad& act) : datos(act), siguiente(nullptr), anterior(nullptr) {}
    
    // Constructor por defecto
    Nodo() : datos(), siguiente(nullptr), anterior(nullptr) {}
};

#endif
