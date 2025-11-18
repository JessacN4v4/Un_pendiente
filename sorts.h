#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <iostream>
#include "actividad.h"
using namespace std;

class Sorts {
public:
    // Bubble Sort Iterativo
    static void bubble_sort(vector<Actividad>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j].get_prioridad() < arr[j + 1].get_prioridad()) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
    
    // Selection Sort Iterativo
    static void selection_sort(vector<Actividad>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int maxIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j].get_prioridad() > arr[maxIdx].get_prioridad()) {
                    maxIdx = j;
                }
            }
            if (maxIdx != i) {
                swap(arr[i], arr[maxIdx]);
            }
        }
    }
    
    // Merge Sort Recursivo
    static void merge_sort(vector<Actividad>& arr, int inicio, int fin) {
        if (inicio < fin) {
            int medio = inicio + (fin - inicio) / 2;
            merge_sort(arr, inicio, medio);
            merge_sort(arr, medio + 1, fin);
            merge(arr, inicio, medio, fin);
        }
    }
    
    // Funcion de seleccion automatica
    static void ordenar_automatico(vector<Actividad>& arr) {
        int n = arr.size();
        
        if (n == 0) {
            cout << "No hay actividades para ordenar." << endl;
            return;
        }
        
        if (n < 20) {
            cout << "Usando Bubble Sort (lista pequeña: " << n << " elementos)" << endl;
            bubble_sort(arr);
        } else if (n < 50) {
            cout << "Usando Selection Sort (lista mediana: " << n << " elementos)" << endl;
            selection_sort(arr);
        } else {
            cout << "Usando Merge Sort (lista grande: " << n << " elementos)" << endl;
            merge_sort(arr, 0, n - 1);
        }
        
        cout << "Actividades ordenadas exitosamente." << endl;
    }

private:
    // Funcion auxiliar para Merge Sort
    static void merge(vector<Actividad>& arr, int inicio, int medio, int fin) {
        int n1 = medio - inicio + 1;
        int n2 = fin - medio;
        
        vector<Actividad> izq(n1);
        vector<Actividad> der(n2);
        
        for (int i = 0; i < n1; i++)
            izq[i] = arr[inicio + i];
        for (int j = 0; j < n2; j++)
            der[j] = arr[medio + 1 + j];
        
        int i = 0, j = 0, k = inicio;
        
        while (i < n1 && j < n2) {
            if (izq[i].get_prioridad() >= der[j].get_prioridad()) {
                arr[k] = izq[i];
                i++;
            } else {
                arr[k] = der[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k] = izq[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            arr[k] = der[j];
            j++;
            k++;
        }
    }
};

#endif
