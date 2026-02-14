[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/5ESmLAlU)
# 🎮 Proyecto Final – Torneo Piedra, Papel o Tijera
## PROGRAMACIÓN DE ESTRUCTURAS DINÁMICAS

---

## 📌 Descripción del Proyecto

Este proyecto consiste en el desarrollo del juego **Piedra, Papel o Tijera** en C++, utilizando estructuras dinámicas circulares.

El sistema permite:

- Inscribir jugadores.
- Almacenar jugadores en una lista circular simple.
- Ejecutar un torneo donde todos juegan contra todos.
- Asignar puntajes automáticamente.
- Mostrar el ganador final del torneo.
- Mostrar ayuda e integrantes.

## 🕹️ Jugabilidad

1. Se inscriben los jugadores ingresando:
   - Nombre
   - ID o CARNET

2. Los jugadores se almacenan en una **lista circular simple**.

3. Se ejecuta el torneo:
   - Todos juegan contra todos.
   - Cada jugador realiza una elección aleatoria (Piedra, Papel o Tijera).
   - Se asignan puntos:
     - Victoria → +3 puntos
     - Empate → +1 punto cada jugador
     - Derrota → 0 puntos

4. Al finalizar todas las partidas, el sistema muestra el ganador del torneo.

---

## 🧠 Estructura de Datos Utilizada

Se implementó una **Lista Circular Simple**.

Cada jugador se almacena en un nodo con la siguiente estructura:

```cpp
struct NodoJugador {
    string nombre;
    string id;
    int puntos;
    NodoJugador* sig;
};
```
---

## 📚 Temas Aplicados en el Código

✔ Clases en C++  
✔ Encapsulamiento  
✔ Punteros  
✔ Memoria dinámica (`new` y `delete`)  
✔ Lista enlazada circular  
✔ Validación de datos  
✔ Manejo de archivos 
✔ Modularización con archivos `.h` y `.cpp`  

---

## 📦 Librerías Utilizadas

```cpp
#include <iostream>   // Entrada y salida
#include <string>     // Manejo de cadenas
#include <cstdlib>    // rand() y system()
#include <ctime>      // time() para aleatoriedad
#include <fstream>    // Creación y manejo de archivos
```

---

## 📄 Instrucciones de Ejecución

1. Clona este repositorio en la máquina local:
   ```bash
   https://github.com/proyecto-ped-03-2025/proyecto-ped-interciclo-appwiz-cpl.git
2. Busca la carpeta del repositorio clonado y escriba esto en la bash:
   ```bash
   code .

3. Una vez dentro de Visual Studio Code abre una nueva terminal (Ctrl + shift + ñ) y escribe lo siguiente para compilar:
   ```bash
   g++ gamePPT.cpp -o gamePPT
   
4. Ejecuta el juego
   ```bash
   ./gamePPT

## 👥 Integrantes:

1. **Nombre:** Barrera Gómez, Heraldo Riquelmy.
   **Carnet:** 00226325

2. **Nombre:** Escobar Menjivar, Jorge Alberto.
   **Carnet:** 00072325

3. **Nombre:** Escobar Arteaga, Rosario Guadalupe 
   **Carnet:** 00235325 

---

## 📌 Nota Importante

El programa utiliza:

```cpp
system("cls");
system("pause");
```

Por lo tanto, estas funciones funcionan correctamente en el sistema operativo de Windows.  
En otros sistemas operativos pueden requerir adaptación.
