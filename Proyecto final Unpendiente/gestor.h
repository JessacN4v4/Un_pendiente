#ifndef GESTOR_H
#define GESTOR_H

#include <iostream>
#include <vector>
#include "actividad.h"
#include "listaligada.h"
#include "sorts.h"
using namespace std;

class Gestor_actividades {
private:
    Lista_doblemente_ligada actividades;
    string archivo_datos;

public:
    // Constructor
    Gestor_actividades(const string& archivo = "mis_pendientes.txt") 
        : archivo_datos(archivo) {
        cargar_actividades();
    }
    
    // Destructor - guarda automaticamente
    ~Gestor_actividades() {
        guardar_actividades();
    }
    
    // Cargar actividades desde archivo
    void cargar_actividades() {
        if (actividades.cargar_desde_archivo(archivo_datos)) {
            cout << "Actividades cargadas exitosamente desde " << archivo_datos << endl;
            cout << "Total de actividades: " << actividades.obtener_tamanio() << endl;
        } else {
            cout << "No se encontró archivo previo. Iniciando con lista vacía." << endl;
        }
    }
    
    // Guardar actividades en archivo
    void guardar_actividades() {
        if (actividades.guardar_en_archivo(archivo_datos)) {
            // Guardado silencioso para no molestar al usuario
        } else {
            cerr << "Error al guardar las actividades." << endl;
        }
    }
    
    // Agregar actividad
    void agregar_actividad(const Actividad& act) {
        actividades.agregar_final(act);
        cout << "Actividad agregada exitosamente." << endl;
        guardar_actividades(); // Guardar automáticamente
    }
    
    // Mostrar todas las actividades
    void mostrar_actividades() const {
        actividades.mostrar_todas();
    }
    
    // Marcar como completada
    void marcar_completada(int indice) {
        if (actividades.marcar_completada(indice)) {
            cout << "Actividad marcada como completada." << endl;
            guardar_actividades(); // Guardar automaticamente
        } else {
            cout << "Índice inválido." << endl;
        }
    }
    
    // Eliminar actividad
    void eliminar_actividad(int indice) {
        if (actividades.eliminar_por_indice(indice)) {
            cout << "Actividad eliminada exitosamente." << endl;
            guardar_actividades(); // Guardar automaticamente
        } else {
            cout << "Índice inválido." << endl;
        }
    }
    
    // Ordenar por prioridad
    void ordenar_prioridad() {
        Sorts::ordenar_automatico(actividades);
        guardar_actividades(); // Guardar automaticamente
    }
    
    // Obtener cantidad de actividades
    int get_cantidad_actividades() const {
        return actividades.obtener_tamanio();
    }
    
    // Obtener primera actividad
    void mostrar_primera() const {
        Actividad* act = actividades.obtener_primera();
        if (act != nullptr) {
            cout << "\n PRIMERA ACTIVIDAD " << endl;
            act->mostrar();
        } else {
            cout << "No hay actividades registradas." << endl;
        }
    }
    
    // Obtener ultima actividad
    void mostrar_ultima() const {
        Actividad* act = actividades.obtener_ultima();
        if (act != nullptr) {
            cout << "\n ÚLTIMA ACTIVIDAD " << endl;
            act->mostrar();
        } else {
            cout << "No hay actividades registradas." << endl;
        }
    }
    
    // Obtener actividad por índice
    void mostrar_por_indice(int indice) const {
        Actividad* act = actividades.obtener_por_indice(indice);
        if (act != nullptr) {
            cout << "\n ACTIVIDAD #" << (indice + 1) << endl;
            act->mostrar();
        } else {
            cout << "Índice inválido." << endl;
        }
    }
    
    // Buscar por prioridad
    void buscar_por_prioridad(int prioridad) const {
        vector<Actividad*> resultados = actividades.buscar_por_prioridad(prioridad);
        
        if (resultados.empty()) {
            cout << "No se encontraron actividades con prioridad " << prioridad << endl;
        } else {
            cout << "\n ACTIVIDADES CON PRIORIDAD " << prioridad << endl;
            cout << "Se encontraron " << resultados.size() << " actividad(es):" << endl;
            for (size_t i = 0; i < resultados.size(); i++) {
                cout << "\nResultado #" << (i + 1) << ":" << endl;
                resultados[i]->mostrar();
            }
        }
    }
    
    // Mostrar estadísticas
    void mostrar_estadisticas() const {
        int total = actividades.obtener_tamanio();
        int pendientes = actividades.contar_pendientes();
        int completadas = actividades.contar_completadas();
        
        cout << "\n ESTADÍSTICAS " << endl;
        cout << "Total de actividades: " << total << endl;
        cout << "Actividades pendientes: " << pendientes << endl;
        cout << "Actividades completadas: " << completadas << endl;
        
        if (total > 0) {
            double porcentaje = (completadas * 100.0) / total;
            cout << "Porcentaje completado: " << porcentaje << "%" << endl;
        }
    }
};

#endif