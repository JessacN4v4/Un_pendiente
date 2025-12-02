# Proyecto Mis Pendientes
## Sistema de Organización Personal y Académica


## Descripción General del proyecto
Mis Pendientes es un sistema de organización personal y académica que permite registrar actividades, asignar prioridades, marcar tareas como completadas y generar estadísticas de progreso. Utiliza una lista doblemente ligada como estructura principal de almacenamiento dinámico, múltiples algoritmos de ordenamiento (Bubble Sort, Selection Sort y Merge Sort) con selección automática según el tamaño de datos, y un sistema completo de persistencia mediante archivos CSV. El proyecto evolucionó desde un sistema básico con menú de consola hasta una arquitectura completa con navegación bidireccional, consultas eficientes y guardado automático de datos.
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
- Persistencia de datos mediante archivos
- Navegación bidireccional entre actividades
- Consultas eficientes de actividades específicas
  
## Descripción del avance 1 del proyecto
Comienza el desarrollo del proyecto de gestión de actividades en el que se implementa un sistema de registro y almacenamiento en memoria con una interfaz de consola funcional. Se implementaron tres algoritmos de ordenamiento: Bubble Sort para listas pequeñas (menos de 20 elementos), Selection Sort para listas medianas (20-50 elementos) y Merge Sort para listas grandes (más de 50 elementos). El sistema permite al usuario agregar, marcar o eliminar actividades fácilmente a través de un menú interactivo. La estructura inicial utiliza funciones iterativas, recursivas y directas, permitiendo un código modular y organizado. La limitación principal de este avance es que los datos no se guardan para persistir entre ejecuciones del programa.


## Descripción del avance 2 del proyecto
El avance 2 representa una mejora significativa en la arquitectura del proyecto mediante la implementación de una Lista Doblemente Ligada personalizada como estructura principal de almacenamiento. Esta decisión elimina las limitaciones de estructuras estáticas y permite un crecimiento dinámico según las necesidades del usuario.
Implementación de Lista Doblemente Ligada
Se implementa una lista doblemente ligada con las siguientes características:


Estructura implementada:
```cpp
Nodo {
    Actividad datos;      // Información de la actividad
    Nodo* siguiente;      // Apuntador al siguiente nodo
    Nodo* anterior;       // Apuntador al nodo anterior
}


Lista_doblemente_ligada {
    Nodo* cabeza;         // Primer nodo de la lista
    Nodo* cola;           // Último nodo de la lista
    int tam;              // Contador de elementos
}
```
### Beneficios de la Lista Doblemente Ligada:
 - Navegación bidireccional: Permite recorrer las actividades tanto hacia adelante como hacia atrás, facilitando operaciones como "ver actividad anterior" o "ir a la última actividad"
 - Inserción y eliminación eficientes: Las operaciones de agregar o eliminar actividades al inicio o final se realizan en tiempo O(1)
 - Reorganización dinámica: Facilita el reordenamiento de actividades por prioridad sin necesidad de recrear toda la estructura
 - Gestión natural de tareas: Permite acceso directo tanto a la primera como a la última actividad mediante los apuntadores cabeza y cola


### Cambios sobre el primer avance
Se implementó la clase Nodo en nodo.h: El nodo encapsula los datos de la actividad junto con los apuntadores de navegación bidireccional. Esto permite una estructura más robusta donde cada elemento conoce tanto a su predecesor como a su sucesor.
Se creó la clase Lista_doblemente_ligada en listaligada.h: Esta clase maneja todas las operaciones de la estructura incluyendo agregar_final(), agregar_inicio(), eliminar_por_indice(), obtener_por_indice(), obtener_primera(), obtener_ultima() y métodos de conversión a vector para los algoritmos de ordenamiento.
Se integró con los algoritmos de ordenamiento existentes: Los algoritmos de ordenamiento (Bubble Sort, Selection Sort y Merge Sort) se adaptan para trabajar con la Lista Doblemente Ligada mediante conversión a vector, ordenamiento y reconstrucción de la lista, manteniendo la funcionalidad de selección automática según el tamaño.


## Descripción del avance 3 del proyecto
El avance 3 completa el sistema agregando las funcionalidades de persistencia de datos y mecanismos eficientes de consulta. Ahora el proyecto permite guardar todas las actividades en un archivo CSV, cargar automáticamente al iniciar, y consultar información específica de la estructura de manera eficiente.
Este avance representa la culminación del sistema, debido a que ahora se tiene un ciclo completo de gestión de actividades: se pueden registrar tareas, consultarlas por diferentes criterios, ordenarlas por prioridad y mantener toda la información entre sesiones. La implementación del sistema de persistencia permite al usuario no perder sus datos al cerrar el programa, siendo fundamental para un sistema de organización real.


### Cambios sobre el segundo avance
Se implementó el sistema de persistencia bidireccional: El avance 2 solo tenía la estructura de datos en memoria. Ahora con las funciones guardar_en_archivo() y cargar_desde_archivo() en listaligada.h, el usuario tiene persistencia completa. Los datos se almacenan en formato CSV (valores separados por comas) para facilitar la lectura y portabilidad.


Formato del archivo mis_pendientes.txt:
```
Prioridad,Tipo,Nombre,Estado
8,Tarea,Entregar proyecto,Pendiente
5,Clase,Matemáticas Discretas,Pendiente
3,Personal,Ir al gimnasio,Completada
```

Se implementó guardado automático: Anteriormente los cambios se perdían al cerrar el programa. Ahora el Gestor_actividades en gestor.h realiza guardado automático al agregar una actividad, marcar como completada, eliminar una actividad, ordenar las actividades y al salir del programa mediante el destructor.

Se agregaron los mecanismos de consulta de información: 
Se implementaron múltiples funciones para consultar información eficientemente de la estructura:
- obtener_primera(): Retorna la primera actividad de la lista en O(1)
- obtener_ultima(): Retorna la última actividad de la lista en O(1)
- obtener_por_indice(int indice): Accede a una actividad específica por su posición
- buscar_por_prioridad(int prioridad): Encuentra todas las actividades con una prioridad específica
- contar_pendientes(): Cuenta cuántas actividades están pendientes
- contar_completadas(): Cuenta cuántas actividades están completadas
- esta_vacia(): Verifica si la lista está vacía en O(1)


## Instrucciones para compilar y ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal para compilar:
```g++ main.cpp -o mis_pendientes```

Ejecuta el siguiente comando en la terminal para ejecución:
```./mis_pendientes```


### Descripción de las entradas del avance de proyecto
El proyecto acepta dos tipos de entradas:
El usuario ingresa información a través del menú de opciones. Para agregar una actividad debe ingresar el nombre de la actividad, el tipo (Clase/Tarea/Personal/Dormir/Descanso) y la prioridad (1-10, donde 10 es máxima prioridad).

El proyecto carga automáticamente las actividades desde el archivo mis_pendientes.txt si existe. El formato CSV esperado es:

```
Prioridad,Tipo,Nombre,Estado 
8,Tarea,Entregar proyecto,Pendiente 
5,Clase,Matemáticas,Pendiente 
3,Personal,Ejercicio,Completada
```

El archivo incluido contiene actividades representativas que muestran el potencial del sistema con diferentes tipos, prioridades variadas y estados pendientes/completados.
Descripción de las salidas del avance de proyecto:

Al ejecutar el registro de una actividad desde el menú se muestra:
```
Actividad agregada exitosamente.
```
Al ver la lista de actividades:
```
LISTA DE ACTIVIDADES

Actividad #1:
  Actividad: Entregar proyecto
  Tipo: Tarea
  Prioridad: 8
  Estado: Pendiente :|
```
Al marcar como completada:
```
Actividad marcada como completada.
```
Al ver estadísticas:
```
ESTADÍSTICAS

Total de actividades: 5
Actividades pendientes: 3
Actividades completadas: 2
Porcentaje completado: 40%
```
Al ordenar por prioridad:
```
Usando Bubble Sort (lista pequeña: 5 elementos)
Actividades ordenadas exitosamente.
```
Al cargar desde archivo:
```
Actividades cargadas exitosamente desde mis_pendientes.txt
Total de actividades: 5
```
## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

En el proyecto se implementan tres algoritmos de ordenamiento en sorts.h. Al analizar sus tres casos de complejidad:

Bubble Sort (bubble_sort):
 - Mejor caso: O(n) - cuando la lista ya está ordenada y se implementa la optimización de bandera swapped que detecta si no hubo intercambios
 - Caso promedio: O(n²) - estadísticamente realizará la mitad de los intercambios posibles en cada pasada
 - Peor caso: O(n²) - cuando la lista está en orden inverso, debe realizar el máximo de intercambios posibles
 - Complejidad espacial: O(1) - ordenamiento in-place
 - Justificación: Adecuado para listas pequeñas (menos de 20 elementos), fácil de implementar y tiene buen desempeño cuando los datos están casi ordenados

Selection Sort (selection_sort):
 - Mejor caso: O(n²) - siempre busca el máximo elemento en cada iteración
 - Caso promedio: O(n²) - realiza el mismo número de comparaciones sin importar el orden inicial
 - Peor caso: O(n²) - comportamiento idéntico en todos los casos
 - Complejidad espacial: O(1) - ordenamiento in-place
 - Justificación: Consistente y predecible. Minimiza el número de intercambios, útil cuando el costo de intercambio es alto

Merge Sort (merge_sort):
 - Mejor caso: O(n log n) - división recursiva siempre en mitades
 - Caso promedio: O(n log n) - comportamiento consistente
 - Peor caso: O(n log n) - garantizado sin importar el orden inicial
 - Complejidad espacial: O(n) - requiere espacio adicional para los subarreglos temporales
 - Justificación: Ofrece rendimiento consistente y predecible. Recomendado para grandes volúmenes de datos (más de 50 registros). Implementado recursivamente con función  -auxiliar merge()
   
En este programa cada algoritmo tiene un propósito específico: Bubble Sort se beneficia de datos casi ordenados, Selection Sort es el más consistente y Merge Sort garantiza eficiencia en listas grandes.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

El proyecto utiliza la Lista Doblemente Ligada como estructura principal, analizada con sus tres casos:

Lista_doblemente_ligada (listaligada.h):

Para agregar_final() y agregar_inicio():
- Mejor caso: O(1) - acceso directo mediante apuntadores cabeza/cola
- Caso promedio: O(1) - siempre actualiza solo los apuntadores necesarios
- Peor caso: O(1) - no depende del tamaño de la lista
- Justificación: Los apuntadores cabeza y cola permiten inserción constante en ambos extremos

Para obtener_primera() y obtener_ultima():
- Mejor caso: O(1) - retorna directamente cabeza->datos o cola->datos
- Caso promedio: O(1) - acceso directo sin recorrido
- Peor caso: O(1) - siempre acceso constante mediante apuntadores
- Justificación: Fundamental para consultas rápidas de extremos de la lista

Para obtener_por_indice(int indice):
- Mejor caso: O(1) - cuando se accede al primer elemento (índice 0)
- Caso promedio: O(n) - estadísticamente se busca en la mitad de la lista
- Peor caso: O(n) - cuando se busca el último elemento recorriendo desde cabeza
- Justificación: Requiere recorrido secuencial desde la cabeza hasta el índice deseado

Para eliminar_por_indice(int indice):
- Mejor caso: O(1) - si se elimina el primer elemento, solo ajusta cabeza
- Caso promedio: O(n) - debe recorrer hasta encontrar el elemento
- Peor caso: O(n) - eliminar el último elemento recorriendo toda la lista
- Justificación: Después de encontrar el nodo, la eliminación es O(1) ajustando apuntadores

Para buscar_por_prioridad(int prioridad):
- Mejor caso: O(n) - debe recorrer toda la lista para encontrar todas las coincidencias
- Caso promedio: O(n) - siempre recorre completamente para no perder coincidencias
- Peor caso: O(n) - comportamiento lineal garantizado
- Justificación: Búsqueda exhaustiva necesaria para retornar todas las actividades con esa prioridad

Para contar_pendientes() y contar_completadas():
- Mejor caso: O(n) - debe verificar el estado de cada actividad
- Caso promedio: O(n) - recorrido completo necesario
- Peor caso: O(n) - comportamiento lineal en todos los casos
- Justificación: Conteo requiere inspeccionar cada nodo de la lista

Para esta_vacia():
- Mejor caso: O(1) - verifica si cabeza == nullptr
- Caso promedio: O(1) - comparación directa
- Peor caso: O(1) - siempre constante
- Justificación: No depende del tamaño de la lista

Para a_vector() y desde_vector():
- Mejor caso: O(n) - debe copiar cada elemento
- Caso promedio: O(n) - recorrido completo
- Peor caso: O(n) - transferencia lineal de datos
- Justificación: Conversión necesaria para integrar con algoritmos de ordenamiento
        
Complejidad espacial de la estructura: O(n) - cada nodo requiere espacio para datos (Actividad) y dos apuntadores (siguiente y anterior)
    
Una lista doblemente ligada ofrece excelentes operaciones en los extremos O(1) a cambio de acceso aleatorio O(n), siendo ideal para un gestor de tareas donde agregar y eliminar es más frecuente que buscar por índice.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

Analizando el programa completo con sus tres casos de complejidad:

Componentes del Gestor_actividades (gestor.h):

agregar_actividad():
- Mejor caso: O(1) - agregar_final es O(1), luego guardar O(n)
- Caso promedio: O(n) - dominado por guardar_en_archivo
- Peor caso: O(n) - escritura de todo el archivo
- Justificación: La inserción es constante pero el guardado automático es lineal

marcar_completada(int indice):
- Mejor caso: O(n) - obtener_por_indice + guardar_en_archivo
- Caso promedio: O(n) - dominado por búsqueda y guardado
- Peor caso: O(n) - comportamiento lineal
- Justificación: Combina búsqueda por índice con persistencia

eliminar_actividad(int indice):
- Mejor caso: O(n) - eliminar_por_indice + guardar_en_archivo
- Caso promedio: O(n) - dominado por guardado
- Peor caso: O(n) - comportamiento lineal

ordenar_prioridad():
- Mejor caso: O(n) - si usa Bubble Sort con datos ordenados
- Caso promedio: O(n²) - Bubble/Selection Sort o O(n log n) Merge Sort
- Peor caso: O(n²) - dependiendo del algoritmo seleccionado
- Justificación: Selección automática según tamaño de lista

mostrar_estadisticas():
- Mejor caso: O(n) - recorre toda la lista para contar
- Caso promedio: O(n) - comportamiento lineal
- Peor caso: O(n) - siempre recorrido completo

Componentes de Persistencia (listaligada.h):

guardar_en_archivo():
- Mejor caso: O(n) - debe escribir cada actividad
- Caso promedio: O(n) - recorrido completo de la lista
- Peor caso: O(n) - comportamiento lineal garantizado
- Justificación: Cada nodo se escribe secuencialmente al archivo

cargar_desde_archivo():
- Mejor caso: O(n) - donde n es el número de líneas del archivo
- Caso promedio: O(n) - lectura y parseo de cada línea
- Peor caso: O(n) - comportamiento lineal
- Justificación: Cada línea se procesa e inserta en la lista

Componentes del menú principal (main.cpp):

- mostrar_menu(): O(1) impresión fija de opciones
- limpiar_buffer(): O(1) operación de entrada
- pausar(): O(1) - espera de entrada

Complejidad final del programa:
- Mejor caso del sistema - O(1): Cuando el usuario solo consulta primera/última actividad o verifica si la lista está vacía. Operaciones que no requieren recorrido ni ordenamiento.
- Caso promedio del sistema - O(n): El uso típico involucra agregar actividades O(1) + guardar O(n), mostrar actividades O(n), buscar por prioridad O(n), ver estadísticas O(n), cargar al iniciar O(n). La mayoría de operaciones requieren un recorrido lineal de la lista o del archivo.
- Peor caso del sistema - O(n²): Ocurre cuando el usuario ordena frecuentemente las actividades con Bubble Sort o Selection Sort. Si la lista tiene n elementos y se ordena múltiples veces por sesión, cada operación de ordenamiento es O(n²). Con listas grandes (>50 elementos), Merge Sort reduce esto a O(n log n).

Resumen de operaciones individuales:
- agregar_actividad: O(n) por guardado automático
- mostrar_actividades: O(n) en los tres casos
- obtener_primera/ultima: O(1) en los tres casos
- obtener_por_indice: mejor O(1), promedio O(n), peor O(n)
- ordenar: mejor O(n), promedio O(n²) o O(n log n), peor O(n²)
- buscar_por_prioridad: O(n) en los tres casos
- estadísticas: O(n) en los tres casos
- cargar/guardar archivo: O(n) en los tres casos
    
La complejidad final del programa es: mejor caso O(1) para consultas simples, caso promedio O(n) para uso normal, peor caso O(n²) cuando se ordena frecuentemente con algoritmos cuadráticos.
En general un sistema puede tener múltiples complejidades dependiendo del patrón de uso, y el guardado automático después de cada operación importante agrega un costo O(n) pero garantiza la persistencia de datos e historial sobre el cual trabajar.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

En el archivo sorts.h se implementa la función ordenar_automatico() que selecciona el algoritmo más apropiado según el tamaño de la lista:

- Para listas con menos de 20 actividades: Bubble Sort - Su complejidad O(n) en el mejor caso (datos casi ordenados) lo hace ideal para listas pequeñas donde el overhead de algoritmos más complejos no se justifica. Además, es fácil de depurar y mantener.
- Para listas entre 20 y 50 actividades: Selection Sort - Ofrece comportamiento O(n²) consistente y predecible. Minimiza el número de intercambios, lo cual es útil cuando las actividades tienen datos complejos.
- Para listas con más de 50 actividades: Merge Sort - Garantiza O(n log n) en todos los casos. Para un usuario con muchas actividades (planificación mensual), este algoritmo asegura rendimiento óptimo.
- La implementación utiliza conversión a vector (a_vector()), ordenamiento y reconstrucción (desde_vector()) para integrar los algoritmos con la lista doblemente ligada sin modificar la lógica de ordenamiento.
- La selección automática de algoritmos basada en el tamaño de datos permite optimizar el rendimiento, balanceando simplicidad en casos pequeños con eficiencia en casos grandes.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

El proyecto utiliza la Lista Doblemente Ligada como estructura principal por las siguientes razones:

- Crecimiento dinámico: A diferencia de arreglos estáticos, la lista puede crecer según las necesidades del usuario sin límite predefinido. Esto es crítico para un gestor de tareas donde el número de actividades es impredecible.
- Inserción eficiente: agregar_final() en O(1) es la operación más frecuente ya que el usuario registra actividades continuamente. El apuntador cola permite esta eficiencia.
- Navegación bidireccional: Los apuntadores anterior y siguiente permiten recorrer la lista en ambas direcciones, facilitando funcionalidades como "ver actividad anterior" o navegar desde el final.
- Eliminación flexible: Al tener referencia al nodo anterior y siguiente, eliminar cualquier elemento requiere solo ajustar apuntadores después de encontrarlo, sin necesidad de desplazar elementos.
- Acceso a extremos en O(1): Los apuntadores cabeza y cola permiten obtener_primera() y obtener_ultima() instantáneamente, útil para ver la tarea más/menos prioritaria después de ordenar.
  
Un gestor de tareas constantemente agrega, elimina y recorre actividades, pero raramente necesita acceso aleatorio por índice, lo que hace a la lista doblemente ligada ideal sobre vectores y algunas otras estructuras.

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctos.

El proyecto implementa múltiples mecanismos de consulta en listaligada.h y gestor.h:

Consulta de extremos - O(1):
- obtener_primera(): Retorna &(cabeza->datos) directamente, permitiendo ver la actividad más prioritaria después de ordenar
- obtener_ultima(): Retorna &(cola->datos) directamente, permitiendo ver la última actividad agregada o la de menor prioridad

Consulta por índice - O(n):
- obtener_por_indice(int indice): Recorre desde cabeza hasta el índice especificado. Valida que el índice esté en rango [0, tam-1] antes de recorrer

Consulta por criterio - O(n):
- buscar_por_prioridad(int prioridad): Recorre toda la lista comparando la prioridad de cada actividad. Retorna un vector<Actividad*> con todas las coincidencias, permitiendo múltiples resultados

Consultas de conteo - O(n):
- contar_pendientes(): Recorre la lista verificando !is_completada() en cada nodo
- contar_completadas(): Recorre la lista verificando is_completada() en cada nodo
- obtener_tamanio(): Retorna el contador tam en O(1) sin necesidad de recorrer

Consulta de estado - O(1):
- esta_vacia(): Verifica cabeza == nullptr para determinar si hay elementos

En gestor.h, estas funciones se exponen a través del menú:
- mostrar_primera(): Llama obtener_primera() y muestra los datos
- mostrar_ultima(): Llama obtener_ultima() y muestra los datos
- mostrar_por_indice(int indice): Llama obtener_por_indice() con validación
- buscar_por_prioridad(int prioridad): Filtra y muestra todas las coincidencias
- mostrar_estadisticas(): Combina contar_pendientes(), contar_completadas() y obtener_tamanio() para generar un resumen

Para diferentes tipos de consulta se requieren diferentes estrategias: acceso directo por apuntadores para extremos, recorrido secuencial para búsquedas por criterio, y contadores mantenidos para consultas de tamaño.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

La carga de datos se implementa en cargar_desde_archivo() en listaligada.h:

Proceso de lectura:
1 Se abre el archivo con ifstream verificando que exista y sea accesible
2 Se descarta la primera línea (encabezados CSV: "Prioridad,Tipo,Nombre,Estado")
3 Para cada línea restante:
- Se crea un stringstream para parsear los campos separados por comas
- Se extraen: prioridad_str, tipo, nombre, estado
- Se convierte prioridad_str a entero con stoi()
- Se crea un objeto Actividad con los datos parseados
- Si estado == "Completada", se llama act.marcar_completada()
- Se agrega a la lista con agregar_final()

Manejo de errores:
- Si el archivo no existe, retorna false sin error crítico (lista vacía inicial)
- Si una línea tiene formato incorrecto, se captura la excepción y se continúa con la siguiente
- Se reporta el error por cerr para debugging

Integración con Gestor_actividades: En el constructor de Gestor_actividades se llama cargar_actividades() que invoca cargar_desde_archivo(). Esto garantiza que al iniciar el programa se restauren automáticamente las actividades de la sesión anterior.

La complejidad es O(n) donde n es el número de líneas del archivo, ya que cada línea se procesa y se inserta en O(1) al final de la lista. La lectura de archivos debe ser robusta ante errores, mantener compatibilidad con el formato de escritura, y ejecutarse automáticamente para una experiencia fluida del usuario.

#### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.

La escritura de datos se implementa en guardar_en_archivo() en listaligada.h:

Proceso de escritura:
1 Se abre/crea el archivo con ofstream
2 Se escribe la línea de encabezados: "Prioridad,Tipo,Nombre,Estado"
3 Se recorre la lista desde cabeza hasta cola:
- Para cada nodo, se escribe una línea CSV con formato:
prioridad,tipo,nombre,estado
- El estado se determina con: is_completada() ? "Completada" : "Pendiente"
4 Se cierra el archivo

Guardado automático: En gestor.h, se implementa guardado automático llamando -  guardar_actividades() después de:
- agregar_actividad(): Cada nueva actividad se persiste inmediatamente
- marcar_completada(): El cambio de estado se guarda
- eliminar_actividad(): La eliminación se refleja en el archivo
- ordenar_prioridad(): El nuevo orden se preserva
- ~Gestor_actividades(): El destructor garantiza guardado al salir

Formato de salida:
```
Prioridad,Tipo,Nombre,Estado
8,Tarea,Entregar proyecto,Pendiente
5,Clase,Matemáticas,Completada
```
Este formato es completamente compatible con cargar_desde_archivo(), permitiendo un flujo bidireccional de datos. Un archivo guardado puede ser cargado sin modificaciones en la siguiente ejecución.

La complejidad es O(n) donde n es el número de actividades, ya que debe recorrer toda la lista para escribir cada elemento.

Para el programa, la escritura de archivos requiere considerar el formato de datos para compatibilidad con la lectura, el guardado automático previene pérdida de datos, y el formato CSV es portable y legible tanto por humanos como por el programa.

## Uso del programa

1 Ejecutar el programa desde la consola o entorno de desarrollo
2 El sistema carga automáticamente las actividades guardadas previamente (si existen)
3 El menú principal muestra las siguientes opciones:
- Agregar una nueva actividad
- Ver lista de actividades
- Marcar una actividad como completada
- Eliminar una actividad
- Ordenar las actividades por prioridad
- Ver primera actividad
- Ver última actividad
- Ver actividad por número
- Buscar por prioridad
- Ver estadísticas
- Salir (guarda automáticamente)
4 El programa automáticamente selecciona el algoritmo de ordenamiento más eficiente según el número de actividades registradas
5 Si el archivo mis_pendientes.txt no existe, se crea automáticamente al agregar la primera actividad
6 Todos los cambios se guardan automáticamente en el archivo mis_pendientes.txt

## Licencia
Este proyecto es de uso académico
