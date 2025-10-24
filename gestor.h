#ifndef GESTOR_H
#define GESTOR_H

#include <iostream>
#include <vector>
#include "actividad.h"
using namespace std;

class Gestor {
private:
    vector<Actividad> lista;

    void merge(int left, int mid, int right) {
        vector<Actividad> temp;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (lista[i].prioridad >= lista[j].prioridad)
                temp.push_back(lista[i++]);
            else
                temp.push_back(lista[j++]);
        }
        while (i <= mid) temp.push_back(lista[i++]);
        while (j <= right) temp.push_back(lista[j++]);
        for (int k = left; k <= right; k++) lista[k] = temp[k - left];
    }

    void merge_sort(int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
    }

public:
    void agregar(Actividad a) {
        lista.push_back(a);
        cout << "Actividad agregada.\n";
    }

    void mostrar() {
        if (lista.empty()) {
            cout << "No hay actividades.\n";
            return;
        }
        cout << "\nLista de actividades:\n";
        for (int i = 0; i < lista.size(); i++) {
            cout << i + 1 << ". ";
            lista[i].mostrar();
        }
    }

    void marcar(int i) {
        if (i < 1 || i > lista.size()) return;
        lista[i - 1].completada = true;
        cout << "Actividad marcada como completada.\n";
    }

    void eliminar(int i) {
        if (i < 1 || i > lista.size()) return;
        lista.erase(lista.begin() + i - 1);
        cout << "Actividad eliminada.\n";
    }

    void bubble_sort() {
        for (int i = 0; i < lista.size() - 1; i++) {
            for (int j = 0; j < lista.size() - i - 1; j++) {
                if (lista[j].prioridad < lista[j + 1].prioridad)
                    swap(lista[j], lista[j + 1]);
            }
        }
        cout << "Ordenado por prioridad (Bubble Sort).\n";
    }

    void selection_sort() {
        for (int i = 0; i < lista.size() - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < lista.size(); j++) {
                if (lista[j].nombre < lista[minIndex].nombre)
                    minIndex = j;
            }
            swap(lista[i], lista[minIndex]);
        }
        cout << "Ordenado alfabéticamente (Selection Sort).\n";
    }

    void ordenar_merge() {
        if (!lista.empty()) {
            merge_sort(0, lista.size() - 1);
            cout << "Ordenado por prioridad (Merge Sort).\n";
        }
    }
};

#endif
