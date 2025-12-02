#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "nodo.h"
#include "actividad.h"
using namespace std;

class Lista_doblemente_ligada {
private:
    Nodo* cabeza;
    Nodo* cola;
    int tam;

public:
    // Constructor
    Lista_doblemente_ligada() : cabeza(nullptr), cola(nullptr), tam(0) {}
    
    // Destructor
    ~Lista_doblemente_ligada() {
        limpiar();
    }
    
    // Metodo para limpiar toda la lista
    void limpiar() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
        cabeza = nullptr;
        cola = nullptr;
        tam = 0;
    }
    
    // Agregar al final de la lista 
    void agregar_final(const Actividad& act) {
        Nodo* nuevo = new Nodo(act);
        
        if (esta_vacia()) {
            cabeza = nuevo;
            cola = nuevo;
        } else {
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
        }
        tam++;
    }
    
    // Agregar al inicio de la lista 
    void agregar_inicio(const Actividad& act) {
        Nodo* nuevo = new Nodo(act);
        
        if (esta_vacia()) {
            cabeza = nuevo;
            cola = nuevo;
        } else {
            nuevo->siguiente = cabeza;
            cabeza->anterior = nuevo;
            cabeza = nuevo;
        }
        tam++;
    }
    
    // Verificar si esta vacia 
    bool esta_vacia() const {
        return cabeza == nullptr;
    }
    
    // Obtener tamaño 
    int obtener_tamanio() const {
        return tam;
    }
    
    // Obtener primera actividad 
    Actividad* obtener_primera() const {
        if (esta_vacia()) {
            return nullptr;
        }
        return &(cabeza->datos);
    }
    
    // Obtener ultima actividad 
    Actividad* obtener_ultima() const {
        if (esta_vacia()) {
            return nullptr;
        }
        return &(cola->datos);
    }
    
    // Obtener actividad por indice 
    Actividad* obtener_por_indice(int indice) const {
        if (indice < 0 || indice >= tam) {
            return nullptr;
        }
        
        Nodo* actual = cabeza;
        for (int i = 0; i < indice; i++) {
            actual = actual->siguiente;
        }
        return &(actual->datos);
    }
    
    // Buscar por prioridad
    vector<Actividad*> buscar_por_prioridad(int prioridad) const {
        vector<Actividad*> resultado;
        Nodo* actual = cabeza;
        
        while (actual != nullptr) {
            if (actual->datos.get_prioridad() == prioridad) {
                resultado.push_back(&(actual->datos));
            }
            actual = actual->siguiente;
        }
        
        return resultado;
    }
    
    // Contar actividades pendientes 
    int contar_pendientes() const {
        int contador = 0;
        Nodo* actual = cabeza;
        
        while (actual != nullptr) {
            if (!actual->datos.is_completada()) {
                contador++;
            }
            actual = actual->siguiente;
        }
        
        return contador;
    }
    
    // Contar actividades completadas 
    int contar_completadas() const {
        int contador = 0;
        Nodo* actual = cabeza;
        
        while (actual != nullptr) {
            if (actual->datos.is_completada()) {
                contador++;
            }
            actual = actual->siguiente;
        }
        
        return contador;
    }
    
    // Marcar como completada por indice 
    bool marcar_completada(int indice) {
        Actividad* act = obtener_por_indice(indice);
        if (act != nullptr) {
            act->marcar_completada();
            return true;
        }
        return false;
    }
    
    // Eliminar por indice 
    bool eliminar_por_indice(int indice) {
        if (indice < 0 || indice >= tam) {
            return false;
        }
        
        Nodo* actual = cabeza;
        
        // Avanzar hasta el indice
        for (int i = 0; i < indice; i++) {
            actual = actual->siguiente;
        }
        
        // Caso: unico nodo
        if (actual == cabeza && actual == cola) {
            cabeza = nullptr;
            cola = nullptr;
        }
        // Caso: primer nodo
        else if (actual == cabeza) {
            cabeza = actual->siguiente;
            cabeza->anterior = nullptr;
        }
        // Caso: ultimo nodo
        else if (actual == cola) {
            cola = actual->anterior;
            cola->siguiente = nullptr;
        }
        // Caso: nodo intermedio
        else {
            actual->anterior->siguiente = actual->siguiente;
            actual->siguiente->anterior = actual->anterior;
        }
        
        delete actual;
        tam--;
        return true;
    }
    
    // Mostrar todas las actividades
    void mostrar_todas() const {
        if (esta_vacia()) {
            cout << "No hay actividades registradas." << endl;
            return;
        }
        
        cout << "\n LISTA DE ACTIVIDADES " << endl;
        Nodo* actual = cabeza;
        int contador = 1;
        
        while (actual != nullptr) {
            cout << "\nActividad #" << contador << ":" << endl;
            actual->datos.mostrar();
            actual = actual->siguiente;
            contador++;
        }
    }
    
    // Convertir a vector para algoritmos de ordenamiento
    vector<Actividad> a_vector() const {
        vector<Actividad> vec;
        Nodo* actual = cabeza;
        
        while (actual != nullptr) {
            vec.push_back(actual->datos);
            actual = actual->siguiente;
        }
        
        return vec;
    }
    
    // Reconstruir desde vector despues de ordenar
    void desde_vector(const vector<Actividad>& vec) {
        limpiar();
        for (const Actividad& act : vec) {
            agregar_final(act);
        }
    }
    
    // Guardar en archivo 
    bool guardar_en_archivo(const string& nombre_archivo) const {
        ofstream archivo(nombre_archivo);
        
        if (!archivo.is_open()) {
            cerr << "Error al abrir el archivo para escritura." << endl;
            return false;
        }
        
        // Escribir encabezado
        archivo << "Prioridad,Tipo,Nombre,Estado" << endl;
        
        // Escribir cada actividad
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            archivo << actual->datos.get_prioridad() << ","
                   << actual->datos.get_tipo() << ","
                   << actual->datos.get_nombre() << ","
                   << (actual->datos.is_completada() ? "Completada" : "Pendiente") << endl;
            actual = actual->siguiente;
        }
        
        archivo.close();
        return true;
    }
    
    // Cargar desde archivo 
    bool cargar_desde_archivo(const string& nombre_archivo) {
        ifstream archivo(nombre_archivo);
        
        if (!archivo.is_open()) {
            // Si el archivo no existe, no es un error critico
            return false;
        }
        
        limpiar(); // Limpiar lista actual
        
        string linea;
        // Saltar la linea de encabezado
        getline(archivo, linea);
        
        // Leer cada linea
        while (getline(archivo, linea)) {
            if (linea.empty()) continue;
            
            stringstream ss(linea);
            string prioridad_str, tipo, nombre, estado;
            
            // Parsear CSV
            getline(ss, prioridad_str, ',');
            getline(ss, tipo, ',');
            getline(ss, nombre, ',');
            getline(ss, estado, ',');
            
            try {
                int prioridad = stoi(prioridad_str);
                Actividad act(tipo, nombre, prioridad);
                
                if (estado == "Completada") {
                    act.marcar_completada();
                }
                
                agregar_final(act);
            } catch (const exception& e) {
                cerr << "Error al parsear linea: " << linea << endl;
                continue;
            }
        }
        
        archivo.close();
        return true;
    }
    
    // Obtener cabeza (para algoritmos de ordenamiento)
    Nodo* obtener_cabeza() const {
        return cabeza;
    }
    
    // Establecer cabeza (para algoritmos de ordenamiento)
    void establecer_cabeza(Nodo* nueva_cabeza) {
        cabeza = nueva_cabeza;
        
        // Actualizar cola
        if (cabeza == nullptr) {
            cola = nullptr;
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            cola = actual;
        }
    }
};

#endif