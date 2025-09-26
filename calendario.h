#ifndef CALENDARIO_H
#define CALENDARIO_H

#include <iostream>
#include <vector>
#include <string>
#include "tarea.h"
using namespace std;

// CLASE CALENDARIO 
class Calendario {
private:
    vector<Tarea> tareas;

public:
    int contar_tareas() { return tareas.size(); }

    // Funcion iterativa
    void mostrar_tareas() {
        cout << "\n Lista de tareas \n";
        for (int i = 0; i < tareas.size(); i++) {
            cout << i+1 << ". ";
            tareas[i].visualizar();
        }
    }

    // Agregar tarea
    void agregar_tarea(Tarea t) {
        tareas.push_back(t);
    }

    // Algoritmos de ordenamiento y busqueda
    void bubble_sort_prioridad() {
        for (int i = 0; i < tareas.size()-1; i++) {
            for (int j = 0; j < tareas.size()-i-1; j++) {
                if (tareas[j].prioridad > tareas[j+1].prioridad) {
                    swap(tareas[j], tareas[j+1]);
                }
            }
        }
    }

    void selec_sort_duracion() {
        for (int i = 0; i < tareas.size()-1; i++) {
            int minIndex = i;
            for (int j = i+1; j < tareas.size(); j++) {
                if (tareas[j].duracion < tareas[minIndex].duracion) {
                    minIndex = j;
                }
            }
            swap(tareas[i], tareas[minIndex]);
        }
    }

    // Merge sort por fecha, función recursiva
    void merge_sort_fecha(int left, int right) {
        if (left >= right) return; // Caso base

        int mid = left + (right - left)/2;
        merge_sort_fecha(left, mid);
        merge_sort_fecha(mid+1, right);
        merge(left, mid, right);
    }

    void merge(int left, int mid, int right) {
        vector<Tarea> temp;
        int i = left, j = mid+1;
        while (i <= mid && j <= right) {
            if (tareas[i].fecha <= tareas[j].fecha)
                temp.push_back(tareas[i++]);
            else
                temp.push_back(tareas[j++]);
        }
        while (i <= mid) temp.push_back(tareas[i++]);
        while (j <= right) temp.push_back(tareas[j++]);
        for (int k = left; k <= right; k++) {
            tareas[k] = temp[k-left];
        }
    }

    // LLamada a merge sort
    void ordenar_p_fecha() {
        if (!tareas.empty())
            merge_sort_fecha(0, tareas.size()-1);
    }
};
#endif 