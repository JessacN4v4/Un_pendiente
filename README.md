# Proyecto Mis Pendientes
## Sistema de Organización Personal y Académica

## Descripción del proyecto
Personalmente, en mi día a día, al igual que muchas personas, presento dificultades para organizar mis actividades pendientes, tanto personales como académicas. A pesar de que existen muchas aplicaciones que ofrecen recordatorios, horarios y registros de tareas, personalmente no me gusta utilizar ninguna de ellas.
Por esa razón decidí desarrollar mi propio sistema de seguimiento y organización de horarios, adaptado a mis necesidades.

El programa permite organizar distintos tipos de actividades:
- Clases
- Tareas pendientes
- Actividades personales
- Hora de dormir y hora de levantarse
- Días libres o de descanso

Además, el sistema permite:
- Registrar nuevas actividades
- Marcar tareas como completadas
- Eliminar registros (de forma definitiva o temporal)
- Visualizar la información, tanto en modo calendario como en modo lista
- Ordenar las actividades por prioridad, de mayor a menor
- Diferenciar las prioridades por colores (colores aún por definir)
- **Persistencia de datos mediante archivos**
- **Navegación bidireccional entre actividades**
- **Consultas eficientes de actividades específicas**

## Avance 1 del proyecto
En esta etapa del desarrollo del proyecto, ya se cuenta con:
- Un sistema de registro y almacenamiento de actividades en memoria
- La implementación de algoritmos de ordenamiento tales como Selection Sort, Bubble Sort y Merge Sort para organizar las tareas según su prioridad
- Una interfaz de consola funcional la cual le permite al usuario agregar, marcar o eliminar actividades fácilmente
- Una estructura modular con funciones iterativas, recursivas y directas, permitiendo un código más organizado y eficiente.

## Avance 2 del proyecto
En esta segunda etapa del desarrollo, se implementan mejoras significativas en la estructura de datos y persistencia de información:

### Implementación de Lista Doblemente Ligada
Se reemplaza el vector (std::vector) por una **Lista Doblemente Ligada personalizada** como estructura principal de almacenamiento. Esta decisión se fundamenta en las siguientes ventajas:

Beneficios de la Lista Doblemente Ligada:
- Navegación bidireccional: Permite recorrer las actividades tanto hacia adelante como hacia atrás, facilitando operaciones como "ver actividad anterior" o "ir a la última actividad"
- Inserción y eliminación eficientes: Las operaciones de agregar o eliminar actividades en cualquier posición se realizan en tiempo O(1) cuando se tiene la referencia al nodo, sin necesidad de desplazar elementos
- Reorganización dinámica: Facilita el reordenamiento de actividades por prioridad sin necesidad de recrear toda la estructura
- Gestión natural de tareas completadas: Permite mover fácilmente las tareas completadas al final de la lista manteniendo el orden de las pendientes

Estructura implementada:
```cpp
Nodo {
    Actividad datos;          // Información de la actividad
    Nodo* siguiente;          // Apuntador al siguiente nodo
    Nodo* anterior;           // Apuntador al nodo anterior
}

ListaDoblementeLigada {
    Nodo* cabeza;             // Primer nodo de la lista
    Nodo* cola;               // Último nodo de la lista
    int tamaño;               // Contador de elementos
}
```

### Sistema de Persistencia de Datos
Se implementa un sistema completo de lectura y escritura de archivos que permite:

Funcionalidades de persistencia:
- Carga automática al iniciar: Al ejecutar el programa, se cargan automáticamente las actividades guardadas previamente
- Guardado automático: Los cambios se guardan automáticamente al:
  - Agregar una nueva actividad
  - Marcar una actividad como completada
  - Eliminar una actividad
  - Ordenar las actividades
  - Salir del programa
- Formato de archivo estructurado: Los datos se almacenan en formato CSV (valores separados por comas) para facilitar la lectura y portabilidad

Formato del archivo `mis_pendientes.txt`:
```
Prioridad,Tipo,Nombre,Estado
8,Tarea,Entregar proyecto,Pendiente
5,Clase,Matemáticas Discretas,Pendiente
3,Personal,Ir al gimnasio,Completada
```

### Funciones de Consulta Implementadas
Se agregan mecanismos eficientes para consultar información de la estructura:

1. `obtener_primera()`: Retorna la primera actividad de la lista (más prioritaria después de ordenar)
2. `obtener_ultima()`: Retorna la última actividad de la lista
3. `obtener_por_indice(int indice)`: Accede a una actividad específica por su posición
4. `buscar_por_prioridad(int prioridad)`: Encuentra todas las actividades con una prioridad específica
5. `contar_pendientes()`: Cuenta cuántas actividades están pendientes
6. `contar_completadas()`: Cuenta cuántas actividades están completadas
7. `esta_vacia()`: Verifica si la lista está vacía

### Integración con Algoritmos de Ordenamiento
Los algoritmos de ordenamiento (Bubble Sort, Selection Sort y Merge Sort) se adaptan para trabajar con la Lista Doblemente Ligada, manteniendo la funcionalidad de selección automática según el tamaño de la lista.

## Uso del programa
1. Ejecutar el programa desde la consola o entorno de desarrollo.
2. El sistema carga automáticamente las actividades guardadas previamente (si existen).
3. El menú principal mostrará las siguientes opciones:
   - Agregar una nueva actividad
   - Ver lista de actividades
   - Marcar una actividad como completada
   - Eliminar una actividad
   - Ordenar las actividades por prioridad
   - Ver actividad específica (primera, última o por índice)
   - Buscar por prioridad
   - Ver estadísticas (pendientes vs completadas)
   - Salir (guarda automáticamente)
4. El programa automáticamente selecciona el algoritmo de ordenamiento más eficiente según el número de actividades registradas.
5. Todos los cambios se guardan automáticamente en el archivo `mis_pendientes.txt`.

## Evaluación de la complejidad

### Identificación de necesidades funcionales:
1. El sistema debe responder rápidamente cuando el usuario agrega o elimina actividades, incluso si existen muchas tareas registradas
2. Debe poder reordenar dinámicamente las actividades cada vez que se modifica la prioridad o se marca una tarea como completada
3. La estructura debe permitir una lectura ordenada e intuitiva, sin sacrificar demasiados recursos del sistema
4. Debe existir una diferenciación de desempeño entre listas pequeñas (personales o diarias) y listas grandes (mensuales o con muchas categorías)
5. Los datos deben persistir entre ejecuciones del programa
6. Las operaciones de consulta deben ser eficientes y directas

### Complejidad de la Lista Doblemente Ligada

#### Operaciones principales:
- Inserción al inicio: O(1) - acceso directo a la cabeza
- Inserción al final: O(1) - acceso directo a la cola
- Eliminación al inicio: O(1) - ajuste directo de cabeza
- Eliminación al final: O(1) - ajuste directo de cola
- Búsqueda por índice: O(n) - recorrido secuencial necesario
- Búsqueda por valor: O(n) - recorrido completo en el peor caso
- Acceso a primer elemento: O(1) - apuntador directo
- Acceso a último elemento: O(1) - apuntador directo
- Complejidad espacial: O(n) - cada nodo requiere espacio para datos y dos apuntadores

### Evaluación de metodologías aplicadas:

#### Bubble Sort (Iterativo)
 - Mejor caso: O(n) - cuando la lista ya está ordenada
 - Caso promedio: O(n²)
 - Peor caso: O(n²) - cuando la lista está en orden inverso
 - Complejidad espacial: O(1)
 - Justificación: Adecuado para listas pequeñas (menos de 20 elementos), fácil de implementar y mantener. Útil para demostración didáctica. Adaptado para trabajar con nodos en lugar de índices.

#### Selection Sort (Iterativo)
 - Mejor caso: O(n²)
 - Caso promedio: O(n²)
 - Peor caso: O(n²)
 - Complejidad espacial: O(1)
 - Justificación: Realiza siempre el mismo número de comparaciones independientemente del orden inicial. Equilibra legibilidad y rendimiento en listas medianas. Permite observar claramente el proceso de selección directa del elemento mínimo. Funciona eficientemente con la estructura de nodos enlazados.

#### Merge Sort (Recursivo)
 - Mejor caso: O(n log n)
 - Caso promedio: O(n log n)
 - Peor caso: O(n log n)
 - Complejidad espacial: O(n)
 - Justificación: Ofrece rendimiento consistente y predecible. Recomendado para grandes volúmenes de datos (más de 50 registros). Es el algoritmo seleccionado para uso intensivo del sistema debido a su eficiencia garantizada. Implementado recursivamente sobre la lista ligada.

### Decisión de implementación:
Con base en el análisis de complejidad y las necesidades funcionales identificadas, el sistema implementa:

Selección automática de algoritmo de ordenamiento:
- Para listas con menos de 20 actividades: Bubble Sort - O(n) en el mejor caso
- Para listas entre 20 y 50 actividades: Selection Sort - O(n²) predecible
- Para listas con más de 50 actividades: Merge Sort - O(n log n) garantizado

Estructura de datos principal:
- Lista Doblemente Ligada: Optimiza inserciones y eliminaciones frecuentes, típicas en un gestor de tareas. Aunque el acceso por índice es O(n), esta operación es menos frecuente que agregar/eliminar tareas.

Sistema de persistencia:
- Formato CSV: Balance entre legibilidad humana y facilidad de procesamiento
- Guardado automático: Previene pérdida de datos sin intervención del usuario
- Carga al inicio: Experiencia fluida sin configuración adicional

Esta arquitectura garantiza un rendimiento óptimo para el caso de uso real: usuarios que frecuentemente agregan y completan tareas, ocasionalmente las reordenan, y raramente necesitan acceso aleatorio por índice.

## Licencia
Este proyecto es de uso académico
