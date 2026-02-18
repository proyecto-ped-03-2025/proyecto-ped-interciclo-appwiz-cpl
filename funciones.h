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

    bool idExiste(string idBuscado)
    {
        if (!primero)
            return false;

        NodoJugador *aux = primero;
        do
        {
            if (aux->id == idBuscado)
                return true;

            aux = aux->sig;

        } while (aux != primero);

        return false;
    }

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

    void inscribirJugador() // Función para inscribir jugadores en la lista circular
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

            if (idExiste(nuevo->id))
            {
                cout << "ID ya existente.\n";
                delete nuevo;
                pausa();
                return;
            }

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

    void listaJugadores() // Funcion para mostrar listado de jugadores inscritos
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

    void liberarMemoria() // Función para liberar memoria
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

    int resultado(int a, int b)
    {
        if (a == b)
            return 0; // empate

        if ((a == 0 && b == 2) || // piedra gana a tijera
            (a == 1 && b == 0) || // papel gana a piedra
            (a == 2 && b == 1))   // tijera gana a papel
            return 1;             // gana jugador i

        return -1; // gana jugador j
    }

    // ================= JUEGO =================
    void ejecutarJuego()
    {
        if (!primero || primero->sig == primero)
        {
            cout << "Se necesitan minimo 2 jugadores.\n";
            pausa();
            return;
        }
        NodoJugador *i = primero;

        do
        {
            NodoJugador *j = i->sig;
            while (j != primero)
            {
                limpiar();
                cout << i->nombre << " VS " << j->nombre << endl;
                cout << "Presione ENTER para jugar...";
                cin.get();

                int a = rand() % 3;
                int b = rand() % 3;

                limpiar();

                cout << i->nombre << " eligio:\n";
                mostrarJugada(a);

                cout << "\nVS\n\n";

                cout << j->nombre << " eligio:\n";
                mostrarJugada(b);

                int r = resultado(a, b);
                if (r == 1)
                {
                    cout << "\nGANA " << i->nombre << " (+3 puntos)\n";
                    i->puntos += 3;
                }
                else if (r == -1)
                {
                    cout << "\nGANA " << j->nombre << " (+3 puntos)\n";
                    j->puntos += 3;
                }
                else
                {
                    cout << "\nEMPATE (+1 punto cada uno)\n";
                    i->puntos++;
                    j->puntos++;
                }
                pausa();
                j = j->sig;
            }

            i = i->sig;
        } while (i != primero);
    }
    // ================= GANADOR =================
    void mostrarGanador()
    {
        if (!primero)
        {
            cout << "No hay jugadores.\n";
            pausa();
            return;
        }
        NodoJugador *aux = primero;
        NodoJugador *ganador = primero;

        do
        {
            if (aux->puntos > ganador->puntos)
                ganador = aux;

            aux = aux->sig;
        } while (aux != primero);

        limpiar();
        cout << "GANADOR DEL TORNEO\n";
        cout << "==================\n";
        cout << ganador->nombre
             << " con " << ganador->puntos
             << " puntos.\n";
        pausa();
    }

    // ================= AYUDA =================
    void ayuda()
    {
        limpiar();
        cout << R"(

--JUGABILIDAD--

Cada jugador tendrá un nombre, ID único (o carnet) y un puntaje que inicia en 0,
pero después de cada partida se le asignará puntaje.

Se registrarán un mínimo de 2 jugadores. Cada jugador se enfrentará a todos los
demás jugadores sin repetición. El programa asignará aleatoriamente si es
piedra, papel o tijera.

Al finalizar todos los enfrentamientos entre los jugadores se declarará al
ganador en base a quien obtuvo el mayor puntaje.


--REGLAS--

Cada jugador deberá ingresar con un nombre y un ID (o carnet) que no esté en uso.
Debe existir un mínimo de 2 jugadores para poder iniciar el juego.


--OPCIONES DEL MENU--

- Agregar Jugadores:
  Aquí se ingresa el nombre y ID (o carnet) de cada jugador.

- Ver lista de jugadores:
  Se muestran los jugadores inscritos.

- Iniciar juego:
  Se comienzan las partidas de cada jugador contra todos los demás y se asignan
  los puntajes correspondientes a cada jugador.

- Puntajes y ganador:
  Al finalizar todas las partidas se mostrará al ganador que obtuvo mayor puntaje.

- Ayuda:
  Se explica la jugabilidad del juego, las reglas y las opciones del menú principal.

- Integrantes:
  Nombre y carnet de los integrantes del equipo de diseño y creación del juego.

)";

        pausa();
    }

    // ================= INTEGRANTES =================
    void integrantes()
    {
        limpiar();
        cout << "INTEGRANTES\n";
        cout << "===========\n";
        pausa();
    }
};
#endif
