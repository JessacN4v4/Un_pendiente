#ifndef GESTOR_H
#define GESTOR_H

#include <vector>
#include <iostream>
#include "actividad.h"
#include "sorts.h"
using namespace std;

class Gestor_actividades {
private:
    vector<Actividad> actividades;

public:
    void agregar_actividad(const Actividad& act) {
        actividades.push_back(act);
        cout << "Actividad agregada exitosamente." << endl;
    }
    
    void mostrar_actividades() const {
        if (actividades.empty()) {
            cout << "No hay actividades registradas." << endl;
            return;
        }
        
        cout << "\n LISTA DE ACTIVIDADES \n" << endl;
        for (size_t i = 0; i < actividades.size(); i++) {
            cout << "Actividad #" << (i + 1) << ":" << endl;
            actividades[i].mostrar();
        }
    }
    
    void marcar_completada(int indice) {
        if (indice < 0 || indice >= (int)actividades.size()) {
            cout << "Índice inválido." << endl;
            return;
        }
        
        actividades[indice].marcar_completada();
        cout << "Actividad marcada como completada." << endl;
    }
    
    void eliminar_actividad(int indice) {
        if (indice < 0 || indice >= (int)actividades.size()) {
            cout << "Índice inválido." << endl;
            return;
        }
        
        actividades.erase(actividades.begin() + indice);
        cout << "Actividad eliminada exitosamente." << endl;
    }
    
    void ordenar_prioridad() {
        Sorts::ordenar_automatico(actividades);
    }
    
    int get_cantidad_actividades() const {
        return actividades.size();
    }
};

#endif
