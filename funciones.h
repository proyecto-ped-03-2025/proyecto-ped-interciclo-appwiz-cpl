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

    void titulo()
    {
        cout << R"(
██████╗ ██╗███████╗██████╗ ██████╗ 
██╔══██╗██║██╔════╝██╔══██╗██╔══██╗
██████╔╝██║█████╗  ██║  ██║██████╔╝
██╔═══╝ ██║██╔══╝  ██║  ██║██╔══██╗
██║     ██║███████╗██████╔╝██║  ██║
╚═╝     ╚═╝╚══════╝╚═════╝ ╚═╝  ╚═╝
)";
    }

    void piedra() { cout << " [ PIEDRA ]\n"; }
    void papel() { cout << " [ PAPEL ]\n"; }
    void tijera() { cout << " [ TIJERA ]\n"; }

    void mostrarJugada(int op)
    {
        if (op == 0)
            piedra();
        else if (op == 1)
            papel();
        else
            tijera();
    }

    string nombreJugada(int op)
    {
        if (op == 0)
            return "Piedra";
        if (op == 1)
            return "Papel";
        return "Tijera";
    }
};
#endif