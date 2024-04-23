#include <iostream>
#include<conio.h>
using namespace std;
string jugador1,jugador2 ="Computer";
int turno =0;

char tablero [3][3] ;

//LA GENERACIOND DEL TABLERO
void generar_cuadro(){
int x= 0, y = 0;
for (int i = 0; i <6; i++){
     for (int j = 0; j < 3; j++){
        if (i <5 && i % 2== 1 ){
            cout <<"___";
        }else {
            if (i <5){
                cout <<" "<< tablero[x][y] <<" ";
                y++;
            }else {
                cout <<"   ";
           }
        }

        if(j <2 ){
            cout <<"|";
        } 
    }
    
    y= 0;
    if (i % 2== 0){
        x++;
    }
    
    cout <<"\n";
}
}

//POSIBLES JUGADAS
char posibles_jugadas(){
    char jugada;
    string jugadas= "123456789";
    int contar=0;

cout <<"OPCIONES A JUGAR: \n";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){   
            if (tablero [i][j] != ' '){
            }else {
           cout <<jugadas[contar]<<",- ["<<i<<","<<j<<"]";
            cout <<endl;
            }
        contar++;
       
        }
    }
if (turno % 2 == 0 ){
        //jugador 1
cout <<jugador1;
 }else {
    //jugador 2
cout <<jugador2; 
 }
cout <<", elija una jugada: ";
jugada = getch ();
return jugada;
}

//actualizar la pantalla
void actualizar(int x, int y){
    if (turno % 2 == 0 ){
        //jugador 1
tablero [x][y]='X';  
 }else {
    //jugador 2
    tablero [x][y]='O'; 
 }
 turno++;
}

int validar (char jugada){
//si ingreso un numero que no deseaba;
if(jugada >='1' && jugada <='9'){
//si estadentro de la condicion
    switch (jugada){
        case '1':
            if (tablero [0][0] == ' '){
                actualizar(0,0);
                return 1;
            }
            break;
        case '2':
            if (tablero [0][1] == ' '){
                actualizar(0,1);
                return 1;
            }
            break;
        case '3':
            if (tablero [0][2] == ' '){
                actualizar(0,2);
                return 1;
            }
            break;
        case '4':
            if (tablero [1][0] == ' '){
                actualizar(1,0);
                return 1;
            }
            break;
        case '5':
            if (tablero [1][1] == ' '){
                actualizar(1,1);
                return 1;
            }
            break;
        case '6':
            if (tablero [1][2] == ' '){
                actualizar(1,2);
                return 1;
            }
            break;
        case '7':
            if (tablero [2][0] == ' '){
                actualizar(2,0);
                return 1;
            }
            break;
        case '8':
            if (tablero [2][1]== ' '){
                actualizar(2,1);
                return 1;
            }
            break;
        case '9':
            if (tablero [2][2] == ' '){
                actualizar(2,2);
                return 1;
            }
            break;
    }
}
return 0;
}
int Ganador(){
    //validando horizontales primera columna
if (tablero [0][0] != ' ' && tablero [0][0] == tablero [0][1]  && tablero [0][0] == tablero [0][2]){
    return 1;
} //segunda columna
if (tablero [1][0] != ' ' && tablero [1][0] == tablero [1][1]  && tablero [1][0] == tablero [1][2]){
    return 1;
}//tercera columna
if (tablero [2][0] != ' ' && tablero [2][0] == tablero [2][1]  && tablero [2][0] == tablero [2][2]){
    return 1;
} //filas 1 
if (tablero [0][0] != ' ' && tablero [0][0] == tablero [1][0]  && tablero [0][0] == tablero [2][0]){
    return 1;
} //fila 2
if (tablero [0][1] != ' ' && tablero [0][1] == tablero [1][1]  && tablero [0][1] == tablero [2][1]){
    return 1;
} //fila 3
if (tablero [0][2] != ' ' && tablero [0][2] == tablero [1][2]  && tablero [0][2] == tablero [2][2]){
    return 1;
} //diagola desendiente
if (tablero [0][0] != ' ' && tablero [0][0] == tablero [1][1]  && tablero [0][0] == tablero [2][2]){
    return 1;
} //diagonal acendente
if (tablero [0][2] != ' ' && tablero [0][2] == tablero [1][1]  && tablero [0][2] == tablero [2][0]){
    return 1;
} 
return 0;
}
void verGanador(int turno_anterios){
    if (turno_anterios % 2 == 0 ){
        //jugador 1
cout <<"Ganador jugador: "<<jugador1<<endl;  
 }else {
    //jugador 2
    cout <<"Ganador jugador: "<<jugador2<<endl;
 }
}


int main (){
    int limite_de_jugadas=0,ValidaoNovalida=0,Vganador=0;
//generamos un espacio por defaul
for (int i = 0;i<3; i++){
    for (int j=0; j<3; j++){
  tablero [i][j]= ' ';
    }
}
 cout <<"\t========================\n \t Juego de Tres en Raya  \n \t========================\n \n";
   system ("pause");
    cout <<"Ingrese el nombre del jugador 1 ";
   getline(cin, jugador1);  
  cout <<"Ingrese el nombre del jugador 2 ";
   getline(cin, jugador2);  

    while (limite_de_jugadas < 9 && Vganador ==0){ 
        system("cls");
        generar_cuadro();
        ValidaoNovalida =  validar( posibles_jugadas());
        if (ValidaoNovalida == 1 ){
            Vganador=Ganador();
            limite_de_jugadas++;
        }   
    }
     system("cls");
        generar_cuadro();
    if (Vganador == 1){
        verGanador ( limite_de_jugadas-1);
    }else {
        cout <<"Es un empate";
    }

    return 0;
}