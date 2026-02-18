#include "funciones.h"

int main()
{
    srand(time(NULL));

    GamePPT juego;

    int opcion;

    do
    {
        juego.limpiar();
        juego.titulo();

        cout << "\n===== MENU =====\n";
        cout << "1. Agregar jugadores\n";
        cout << "2. Ver lista jugadores\n";
        cout << "3. Iniciar juego\n";
        cout << "4. Ver ganador\n";
        cout << "5. Ayuda\n";
        cout << "6. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            juego.inscribirJugador();
            break;

        case 2:
            juego.listaJugadores();
            break;

        case 3:
            juego.ejecutarJuego();
            break;

        case 4:
            juego.mostrarGanador();
            break;

        case 5:
            juego.ayuda();
            break;

        case 6:
            cout << "Saliendo...\n";
            juego.liberarMemoria();
            break;


        default:
            cout << "Opcion invalida\n";
            juego.pausa();
        }

    } while (opcion != 6);

    return 0;
}
