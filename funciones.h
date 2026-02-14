#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

struct NodoJugador
{
    string nombre;
    string id;
    int puntos;
    NodoJugador *sig;
};

class GamePPT
{
private:
    NodoJugador *primero;

public:
    GamePPT()
    {
        primero = NULL;
    }

void limpiar() { system("cls"); } // Solo para Windows
void pausa() { system("pause"); } // Solo para Windows
};
#endif