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

## Avance 1 del proyecto
En esta etapa del desarrollo del proyecto, ya se cuenta con:
- Un sistema de registro y almacenamiento de actividades en memoria
- La implementación de algoritmos de ordenamiento tales como Selection Sort, Bubble Sort y Merge Sort para organizar las tareas según su prioridad
- Una interfaz de consola funcional la cual le permite al usuario agregar, marcar o eliminar actividades fácilmente
- Una estructura modular con funciones iterativas, recursivas y directas, permitiendo un código más organizado y eficiente.


## Uso del programa
1. Ejecutar el programa desde la consola o entorno de desarrollo.
2. El menú principal mostrará las siguientes opciones:
   - Agregar una nueva actividad
   - Ver lista de actividades
   - Marcar una actividad como completada
   - Eliminar una actividad
   - Ordenar las actividades por prioridad
3. El programa automáticamente selecciona el algoritmo de ordenamiento más eficiente según el número de actividades registradas, optimizando el rendimiento sin intervención del usuario.
4. El programa muestra el resultado ordenado de las actividades según su prioridad.

## Evaluación de la complejidad

### Identificación de necesidades funcionales:
1. El sistema debe responder rápidamente cuando el usuario agrega o elimina actividades, incluso si existen muchas tareas registradas
2. Debe poder reordenar dinámicamente las actividades cada vez que se modifica la prioridad o se marca una tarea como completada
3. La estructura debe permitir una lectura ordenada e intuitiva, sin sacrificar demasiados recursos del sistema
4. Debe existir una diferenciación de desempeño entre listas pequeñas (personales o diarias) y listas grandes (mensuales o con muchas categorías).

### Evaluación de metodologías aplicadas:

#### Bubble Sort (Iterativo)
 - Mejor caso: O(n) - cuando la lista ya está ordenada
 - Caso promedio: O(n²)
 - Peor caso: O(n²) - cuando la lista está en orden inverso
 - Complejidad espacial: O(1)
 - Justificación: Adecuado para listas pequeñas (menos de 20 elementos), fácil de implementar y mantener. Útil para demostración didáctica.

#### Selection Sort (Iterativo)
 - Mejor caso: O(n²)
 - Caso promedio: O(n²)
 - Peor caso: O(n²)
 - Complejidad espacial: O(1)
 - Justificación: Realiza siempre el mismo número de comparaciones independientemente del orden inicial. Equilibra legibilidad y rendimiento en listas medianas. Permite observar claramente el proceso de selección directa del elemento mínimo.

#### Merge Sort (Recursivo)
 - Mejor caso: O(n log n)
 - Caso promedio: O(n log n)
 - Peor caso: O(n log n)
 - Complejidad espacial: O(n)
 - Justificación: Ofrece rendimiento consistente y predecible. Recomendado para grandes volúmenes de datos (más de 200 registros). Es el algoritmo seleccionado para uso intensivo del sistema debido a su eficiencia garantizada.

### Decisión de implementación:
Con base en el análisis de complejidad y las necesidades funcionales identificadas, el sistema implementa un mecanismo de selección automática que elige el algoritmo más adecuado según el contexto:

- Para listas con menos de 20 actividades: Se utiliza **Bubble Sort**, aprovechando su simplicidad y eficiencia en el mejor caso O(n) cuando las tareas ya están parcialmente ordenadas, situación común en el uso diario.

- Para listas entre 20 y 50 actividades: Se utiliza **Selection Sort**, que ofrece un rendimiento predecible O(n²) y mantiene la simplicidad del código.

- Para listas con más de 50 actividades: Se utiliza **Merge Sort**, garantizando un rendimiento óptimo y consistente de O(n log n) en todos los casos, sin importar el orden inicial de los datos.

Esta estrategia de selección automática optimiza el rendimiento del sistema en cada escenario de uso, asegurando tiempos de respuesta rápidos tanto para usuarios con pocas tareas como para aquellos con grandes volúmenes de actividades registradas. El programa toma la decisión más eficiente de forma transparente.
