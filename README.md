# Proyecto Mis Pendientes 

Sistema de Organización Personal y Académica  

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
- Registrar nuevas actividades**  
- Marcar tareas como completadas**  
- Eliminar registros** (de forma definitiva o temporal)  
- Visualizar la información, tanto en modo calendario como en modo lista  
- Ordenar las actividades por prioridad, de mayor a menor 
- Diferenciar las prioridades por colores(colores aún por definir)  


## Avance actual del proyecto  

En esta etapa del desarrollo del proyecto, ya se cuenta con:  
- Un sistema de registro y almacenamiento de actividades en memoria  
- La implementación de algoritmos de ordenamiento tales como *Selection Sort*, *Bubble Sort* y *Merge Sort* para organizar las tareas según su prioridad 
- Una interfaz de consola funcional la cual le permite al usuario agregar, marcar o eliminar actividades fácilmente 
- Una estructura modular con funciones iterativas, recursivas y directas, permitiendo un código más organizado y eficiente.  

Actualmente, el foco principal está en la optimización del ordenamiento y en la futura implementación de la visualización tipo calendario.  

## Uso del programa  

1. Ejecutar el programa desde la consola o entorno de desarrollo.  
2. El menú principal mostrará las siguientes opciones:  
   - Agregar una nueva actividad  
   - Ver lista de actividades  
   - Marcar una actividad como completada  
   - Eliminar una actividad  
   - Ordenar las actividades por prioridad  
3. Al ordenar, el usuario puede seleccionar el algoritmo a usar (por ejemplo, Bubble Sort o Merge Sort), lo que permite comparar resultados y tiempos.  
4. El programa muestra el resultado ordenado y, en caso de usar Merge Sort, de igual manera, informa la complejidad temporal.  

## Evaluación de la complejidad
#### Identificación de necesidades funcionales:

1. El sistema debe responder rápidamente cuando el usuario agrega o elimina actividades, incluso si existen muchas tareas registradas 
2. Debe poder reordenar dinámicamente las actividades cada vez que se modifica la prioridad o se marca una tarea como completada 
3. La estructura debe permitir una lectura ordenada e intuitiva, sin sacrificar demasiados recursos del sistema  
4. Debe existir una diferenciación de desempeño entre listas pequeñas (personales o diarias) y listas grandes (mensuales o con muchas categorías).  

#### Evaluación de metodologías aplicadas:

Con base en esos criterios, se determina que:  
- *Bubble Sort* y *Selection Sort* son metodologías apropiadas para demostración didáctica y mantenimiento sencillo en escenarios con pocas tareas (menos de 20) 
- *Merge Sort* ofrece una metodología de alto rendimiento cuando el programa se usa de forma intensiva, con más de 200 registros.  
- En el punto medio, se permite mantener flexibilidad seleccionando *Selection Sort*, equilibrando legibilidad y rendimiento.  
 
El programa incluye un análisis de complejidad automatico para los algoritmos de ordenamiento implementados:  

- Bubble Sort Iterativo: O(n²) : O(1) : Adecuado para listas pequeñas; fácil de implementar.
- Selection Sort Iterativo :O(n²) : O(1) : Permite observar el proceso de selección directa. 
- Merge Sort Recursivo : O(n log n) : O(n) : Recomendado para grandes volúmenes de datos. 

El código realiza pruebas con los tres métodos para analizar cuál es más eficiente según el número de actividades registradas. Esto demuestra una evaluación completa de los componentes algorítmicos.  



##  Próximos pasos 

- Añadir colores representativos para cada nivel de prioridad 
- Implementar un modo calendario gráfico
- Guardar los registros en un archivo externo para mantener persistencia entre ejecuciones
- Integrar una opción de filtrado por tipo de actividad o fecha
