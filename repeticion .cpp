#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
char simbolo_jugador1, simbolo_jugador2;
string jugador1, jugador2 = "Computadora";
int turno ;
char tablero[3][3] = {{'1', '2', '3'},
                      {'4', '5', '6'},
                      {'7', '8', '9'}};

// FUNCION PARA GENERAR EL TABLERO
int generar_tablero(){
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
        simbolo = simbolo_jugador1;
    }else{
        //jugador 2
        simbolo = simbolo_jugador2;
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
// JUGADA DE LA COMPUTADORA
int jugada_computadora() {
    srand(time(0));
    char jugada;
    do {
        jugada = '1' + rand() % 9; // jugada aleatoria
    } while (!validar(jugada)); // verificar si la jugada es valida
    return jugada;
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
// Elejir simbolo para el jugador
void elegir_simbolo() {
    cout << "\nJugador 1, elija el simbolo con el que desea jugar\n";
    cout << "1. 0\n";
    cout << "2. X\n";
    cout << "\nIngrese su opcion: ";
    int opcion;
    cin >> opcion;
    if (opcion == 1) {
        simbolo_jugador1 = '0';
        simbolo_jugador2 = 'X';
    } else if (opcion == 2) {
        simbolo_jugador1 = 'X';
        simbolo_jugador2 = '0';
    } else {
        cout << "La opcion ingresada no es valida\n";
    }
}
int main(){
 srand(time (NULL));
turno =0 +rand ()%(3);
char neuvo_tablero[3][3] = {{'1', '2', '3'},
                      {'4', '5', '6'},
                      {'7', '8', '9'}};

    int limite_de_jugadas = 0, ValidaoNovalida = 0, Vganador = 0;
    int opcion, Vrepetir;
    cout << "\t========================\n \t Juego de Tres en Raya  \n \t========================\n \n";
    system("pause");
    cout << "Modo de juego\n1.Jugador vs jugador\n2.Jugador vs computadora\nIngrese una opcion: ";
    cin >> opcion;
    if (opcion == 1) {
        cout << "Ingrese el nombre del jugador 1: ";
        cin >> jugador1;
        cout << "Ingrese el nombre del jugador 2: ";
        cin >> jugador2;
        elegir_simbolo();
    } else if (opcion == 2) {
        cout << "Ingrese el nombre del jugador 1: ";
        cin >> jugador1;
        elegir_simbolo();
    } else {
        cout << "Opcion invalida." << endl;
        return 0;
    }
 do{
    while (limite_de_jugadas < 9 && Vganador == 0){
        system("cls");
        generar_tablero();
        char jugada;
        if (turno % 2 == 0 || opcion == 1) {
            jugada = posibles_jugadas();
        } else {
            jugada = jugada_computadora();
        }
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
getch();
system ("cls");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            tablero [i][j] = neuvo_tablero [i][j];
        }
    }
limite_de_jugadas = 0, ValidaoNovalida = 0, Vganador = 0;
turno--;
    cout<<"1 | Volver a jugar\n0 | Salir \n ";
    cin >> Vrepetir;
 } while(Vrepetir  == 1);
 
    return 0;
}