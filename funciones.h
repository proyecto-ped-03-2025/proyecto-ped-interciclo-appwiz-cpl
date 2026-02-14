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

void inscribirJugador() //Función para inscripción de jugadores
    {
        char opcion;
        cin.ignore();

        do
        {
            limpiar();
            cout << "INSCRIPCION DE JUGADORES\n";
            cout << "========================\n";

            NodoJugador *nuevo = new NodoJugador;

            cout << "Ingrese el nombre del jugador: ";
            getline(cin, nuevo->nombre);

            if (nuevo->nombre.empty())
            {
                cout << "Nombre invalido.\n";
                delete nuevo;
                pausa();
                return;
            }

            cout << "Ingrese el ID del jugador: ";
            cin >> nuevo->id;

            nuevo->puntos = 0;

            if (!primero)
            {
                primero = nuevo;
                nuevo->sig = primero;
            }
            else
            {
                NodoJugador *aux = primero;
                while (aux->sig != primero)
                    aux = aux->sig;

                aux->sig = nuevo;
                nuevo->sig = primero;
            }

            cout << "\nDesea agregar otro jugador? (s/n): ";
            cin >> opcion;
            cin.ignore();

        } while (opcion == 's' || opcion == 'S');

        pausa();
    }

void listaJugadores() //Funcion para mostrar listado de jugadores inscritos
    {
        limpiar();
        cout << "LISTADO DE JUGADORES\n";
        cout << "====================\n";

        if (!primero)
        {
            cout << "No hay jugadores.\n";
            pausa();
            return;
        }

        NodoJugador *aux = primero;
        do
        {
            cout << aux->nombre
                 << " | ID: " << aux->id
                 << " | Puntaje: " << aux->puntos << endl;

            aux = aux->sig;

        } while (aux != primero);

        pausa();
    }

      void liberarMemoria() //Función para liberar memoria
    {
        if (!primero)
            return;

        NodoJugador *actual = primero->sig;

        while (actual != primero)
        {
            NodoJugador *temp = actual;
            actual = actual->sig;
            delete temp;
        }

        delete primero;
        primero = NULL;
    }
};
#endif