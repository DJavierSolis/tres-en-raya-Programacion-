#include <iostream>
#include <conio.h>
using namespace std;

string jugador1, jugador2 = "Computer";
int turno = 0;
char tablero[3][3] = {{'1', '2', '3'},
                      {'4', '5', '6'},
                      {'7', '8', '9'}};

// FUNCION PARA GENERAR EL TABLERO
void generar_tablero(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << tablero[i][j];
            if (j < 2){
                cout << "|";
            }
        }
        if (i < 2){
            cout << "\n-----\n";
        }
    }
}

// POSIBLES JUGADAS
char posibles_jugadas(){
    char jugada;
    cout << "\n\nOPCIONES A JUGAR: ";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O'){
                cout << tablero[i][j] << " ";
            }
        }
    }
    if (turno % 2 == 0){
        //jugador 1
        cout << "\n\n" << jugador1;
    }else{
        //jugador 2
        cout << "\n\n" << jugador2;
    }
    cout << ", elija una jugada: ";
    jugada = getch();
    return jugada;
}

// ACTUALIZAR LA PANTALLA
void actualizar(char jugada){
    char simbolo;
    if (turno % 2 == 0){
        //jugador 1
        simbolo = 'X';
    }else{
        //jugador 2
        simbolo = 'O';
    }
    // Actualizar el tablero con la jugada
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tablero[i][j] == jugada){
                tablero[i][j] = simbolo;
            }
        }
    }
    turno++;
}

// VALIDAR JUGADA
int validar(char jugada){
    // Verificar si la jugada es válida
    if (jugada >= '1' && jugada <= '9'){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (tablero[i][j] == jugada){
                    return 1;
                }
            }
        }
    }
    return 0;
}

// COMPROBAR GANADOR
int Ganador(){
    // Comprobar filas y columnas
    for (int i = 0; i < 3; i++){
        if ((tablero[i][0] == tablero[i][1] && tablero[i][0] == tablero[i][2]) || (tablero[0][i] == tablero[1][i] && tablero[0][i] == tablero[2][i])){
            return 1;
        }
    }
    // Comprobar diagonales
    if ((tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]) || (tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])){
        return 1;
    }

    return 0;
}

// MOSTRAR GANADOR
void verGanador(){
    if ((turno - 1) % 2 == 0){
        //jugador 1
        cout << "\n\nGanador jugador: " << jugador1 << endl;
    }else{
        //jugador 2
        cout << "\n\nGanador jugador: " << jugador2 << endl;
    }
}

int main(){
    int limite_de_jugadas = 0, ValidaoNovalida = 0, Vganador = 0;

    cout << "\t========================\n \t Juego de Tres en Raya  \n \t========================\n \n";
    system("pause");
    cout << "Ingrese el nombre del jugador 1: ";
    getline(cin, jugador1);
    cout << "Ingrese el nombre del jugador 2: ";
    getline(cin, jugador2);

    while (limite_de_jugadas < 9 && Vganador == 0){
        system("cls");
        generar_tablero();
        char jugada = posibles_jugadas();
        ValidaoNovalida = validar(jugada);
        if (ValidaoNovalida == 1){
            actualizar(jugada);
            Vganador = Ganador();
            limite_de_jugadas++;
        }
    }
    system("cls");
    generar_tablero();
    if (Vganador == 1){
        verGanador();
    }else{
        cout << "\n\nEs un empate";
    }

    return 0;
}
