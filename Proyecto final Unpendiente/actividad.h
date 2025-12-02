#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H

#include <string>
#include <iostream>
using namespace std;

class Actividad {
private:
    string nombre;
    string tipo;
    int prioridad;
    bool completada;

public:
    Actividad() : nombre(""), tipo(""), prioridad(0), completada(false) {}
    
    Actividad(string nom, string tip, int pri) 
        : nombre(nom), tipo(tip), prioridad(pri), completada(false) {}
    
    string get_nombre() const { return nombre; }
    string get_tipo() const { return tipo; }
    int get_prioridad() const { return prioridad; }
    bool is_completada() const { return completada; }
    
    void marcar_completada() {
        completada = true;
    }
    
    void mostrar() const {
        cout << "  Actividad: " << nombre << endl;
        cout << "  Tipo: " << tipo << endl;
        cout << "  Prioridad: " << prioridad << endl;
        cout << "  Estado: " << (completada ? " Completada :)" : " Pendiente :|") << endl;
    }
};

#endif