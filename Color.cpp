#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include<stdio.h>
using namespace std;
void kitty();
char simbolo_jugador1, simbolo_jugador2;
string jugador1, jugador2 = "Computadora";
int turno ;
char tablero[3][3] = {{'1', '2', '3'},
                      {'4', '5', '6'},
                      {'7', '8', '9'}};

void gotoxy(int x, int y) { //cordenadas
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
// FUNCION PARA GENERAR EL TABLERO
void generar_tablero() {
    system("cls");
    gotoxy(65, 7);
    cout << "========================\n";
    gotoxy(65, 8);
    cout << " Juego de Tres en Raya  \n";
    gotoxy(65, 9);
    cout << "========================\n\n";

    for (int i = 0; i < 3; i++) {
        gotoxy(75, 10 + i*2); 
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j];
            if (j < 2) {
                cout << "|";
            }
        }
        if (i < 2) {
            gotoxy(75, 11 + i*2); 
            cout << "-----";
        }
    }
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
// POSIBLES JUGADAS
char posibles_jugadas(){
    char jugada;
    bool jugada_valida;
    do {
        gotoxy(60, 17);
        cout << "OPCIONES A JUGAR: ";
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (tablero[i][j] != 'X' && tablero[i][j] != 'O'){
                    cout << tablero[i][j] << " ";
                }
            }
        }
        cout << "\n";
        if (turno % 2 == 0){
            //jugador 1
            gotoxy(65, 19);
            cout << jugador1;
        } else {
            //jugador 2
            gotoxy(65, 19);
            cout << jugador2;
        }
     
        gotoxy(65, 20);
        cout << "Elija una jugada: ";
        kitty();
        gotoxy(83, 20);
        jugada = getch();
      
        jugada_valida = validar(jugada);
        cout<<endl;
        if (!jugada_valida) {
            gotoxy(30, 22);
            cout << "La posicion seleccionada ya esta ocupada. Puede ingresar una de las que este disponible!";
        }
           system("COLOR FC");
    } while (!jugada_valida);
    
    return jugada;
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
        gotoxy(65, 18);
        cout << "Ganador jugador: " << jugador1 << endl;
    }else{
        //jugador 2
        gotoxy(65, 18);
        cout << "Ganador jugador: " << jugador2 << endl;
    }
}
// Elejir simbolo para el jugador
void elegir_simbolo() {
    int opcion;
    do {
        gotoxy(50, 14);
        cout << "Jugador 1, elija el simbolo con el que desea jugar";
        gotoxy(75, 15);
        cout << "1. O";
        gotoxy(75, 16);
        cout << "2. X";
        gotoxy(65, 17);
        cout << "Ingrese su opcion: ";
        kitty();
         gotoxy(84, 17);
        cin >> opcion;
           system("COLOR FC");
        if (opcion == 1) {
            simbolo_jugador1 = 'O';
            simbolo_jugador2 = 'X';
        } else if (opcion == 2) {
            simbolo_jugador1 = 'X';
            simbolo_jugador2 = 'O';
        } else {
            gotoxy(65, 19);
            cout << "La opcion ingresada no es valida\n";
        }
    }while (opcion > 2);
}

int main() {
    system("COLOR FC");
    srand(time(NULL));
    turno = 0 + rand() % 3;
    char neuvo_tablero[3][3] = {{'1', '2', '3'},
                                 {'4', '5', '6'},
                                 {'7', '8', '9'}};

    int limite_de_jugadas = 0, ValidaoNovalida = 0, Vganador = 0, opcion, Vrepetir;
    gotoxy(60, 1);
    cout << "\t========================\n";
    gotoxy(60, 2);
    cout << "\t Juego de Tres en Raya  \n";
    gotoxy(60, 3);
    cout << "\t========================\n\n";
    system("pause");
    gotoxy(70, 5);
    cout << "[Modo de juego]";
    gotoxy(65, 7);
    cout << "1.Jugador vs jugador";
    gotoxy(65, 8);
    cout << "2.Jugador vs computadora";
    gotoxy(65, 9);
    cout << "Ingrese una opcion: ";
    kitty();
     gotoxy(85, 9);
    cin >> opcion;
     system("COLOR FC");

    cin.ignore();
    if (opcion == 1) {
        gotoxy(60, 11);
        cout << "Ingrese el nombre del jugador 1: ";
        kitty();
         gotoxy(93, 11);
        getline(cin, jugador1);
           system("COLOR FC");
        gotoxy(60, 12);
        
        cout << "Ingrese el nombre del jugador 2: ";
        kitty();
         gotoxy(93, 12);
        getline(cin, jugador2);
        system("COLOR FC");
        elegir_simbolo();
    } else if (opcion == 2) {
        gotoxy(60, 11);
        cout << "Ingrese el nombre del jugador 1: ";
         kitty();
         gotoxy(93, 11);
        getline(cin, jugador1);
           system("COLOR FC");
        elegir_simbolo();
    } else {
        gotoxy(60, 12);
        cout << "Opcion invalida. Intente de nuevo." << endl;
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
        gotoxy(70, 20);
        cout << "Es un empate";
    }
    kitty();
getch();
system ("cls");
    system("COLOR FC");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            tablero [i][j] = neuvo_tablero [i][j];
        }
    }
limite_de_jugadas = 0, ValidaoNovalida = 0, Vganador = 0;
turno--;
    gotoxy(65, 6);
    cout<<"1 | Volver a jugar";
    gotoxy(65, 7);
    cout<<"0 | Salir ";
    gotoxy(65, 8);
    cout<<"Ingrese su opcion: ";
     kitty();
     gotoxy(84, 8);
    cin >> Vrepetir;
    system("COLOR FC");
 } while(Vrepetir  == 1);
 
    return 0;
}
void kitty(){

       HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  system("COLOR FC");
 //1
  gotoxy(114, 12);
    SetConsoleTextAttribute(hConsole,1);
cout <<"    ";

 gotoxy(134, 12);
SetConsoleTextAttribute(hConsole,1);
cout <<"    "<<endl;
 
//2
  gotoxy(112,13);
  SetConsoleTextAttribute(hConsole,1);
cout <<"  ";
  gotoxy(118, 13);
  SetConsoleTextAttribute(hConsole,1);
cout <<"              ";
   gotoxy(132, 13);
  SetConsoleTextAttribute(hConsole,64);
cout <<"    ";
gotoxy(138, 13);
SetConsoleTextAttribute(hConsole,1);
cout <<"  "<<endl;


//3
 gotoxy(112, 14);
 SetConsoleTextAttribute(hConsole,1);
cout <<"  ";
 gotoxy(132, 14);
 SetConsoleTextAttribute(hConsole,64);
cout <<"        "<<endl;

//4
 gotoxy(112, 15);
SetConsoleTextAttribute(hConsole,1);
cout <<"  ";
gotoxy(136, 15);
SetConsoleTextAttribute(hConsole,64);
cout <<"    "<<endl;
 
//5
 gotoxy(112, 16);
SetConsoleTextAttribute(hConsole,1);
cout <<"    ";
gotoxy(136, 16);
SetConsoleTextAttribute(hConsole,1);
cout <<"    "<<endl;

//6
 gotoxy(112, 17);
SetConsoleTextAttribute(hConsole,1);
cout <<"  ";
 gotoxy(118, 17);
SetConsoleTextAttribute(hConsole,1);
cout <<"  ";
 gotoxy(130, 17);
SetConsoleTextAttribute(hConsole,1);
cout <<"  ";
 gotoxy(138, 17);
SetConsoleTextAttribute(hConsole,1);
cout <<"  "<<endl;

//7
 gotoxy(112, 18);
SetConsoleTextAttribute(hConsole,1);
cout <<"    ";
 gotoxy(118, 18);
SetConsoleTextAttribute(hConsole,1);
cout <<"  ";
 gotoxy(124, 18);
SetConsoleTextAttribute(hConsole,224);
cout <<"  ";
 gotoxy(130, 18);
SetConsoleTextAttribute(hConsole,1);
cout <<"  ";
 gotoxy(136, 18);
SetConsoleTextAttribute(hConsole,1);
cout <<"    "<<endl;

//8

gotoxy(114, 19);
SetConsoleTextAttribute(hConsole,1);
cout <<"  ";
gotoxy(136, 19);
SetConsoleTextAttribute(hConsole,1);
cout <<"  ";
//9

gotoxy(116, 20);
SetConsoleTextAttribute(hConsole,1);
cout <<"                    "<<endl;
  SetConsoleTextAttribute(hConsole,1);  
}
