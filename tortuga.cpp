#include <iostream>
int menu();
void start(int tablero[][20],int tam);
void mostrarTablero(int tablero[][20], int tam);
void restablecerTablero(int tablero[][20], int tam);
void tabInicial(int tablero[][20], int tam);
using namespace std;
int main(int argc, const char * argv[]) {
    int opc, tam=20;
    int tablero[20][20]{{0}};
    cout << "**********Tortuga - grafica**********"<<endl;;
    
    do {
        opc = menu();

        if (opc==1)
            start(tablero, tam);
        else if (opc==2)
        { //ToDo instrucciones
        }
        else if (opc==3)
            restablecerTablero(tablero,tam);
        
        else if (opc==0)
            cout<<"Saliendo..."<<endl;
        else
            cout<<"opcion invalida"<<endl;
        mostrarTablero(tablero, tam);
        tabInicial(tablero, tam);
    } while (opc!=0);
   
    return 0;
}
int menu()
{
    int opc;
    cout<<"----Ingrese una opcion-----"<<endl;
    cout<<"1.-Iniciar"<<endl;
    cout<<"2.-Instrucciones"<<endl;
    cout<<"3.-Reiniciar"<<endl;
    cout<<"0.-Salir"<<endl;
    cout<<"Opcion: ";
    cin>>opc;
    return opc;
}
void start(int tablero[][20],int tam)
{
    int opc,pasos = 0,pluma=0,girarDerecha = 0;
    int posicionY=0,posicionX=0;
    cout<<"El juego inicia con la tortuga mirando hacia la derecha con la pluma hacia arriba"<<endl;
    cout<<"\t\t\tComandos\n";
    cout<<"1 = pluma arriba\n";
    cout<<"2 = pluma abajo\n";
    cout<<"3 = girar a la derecha\n";
    cout<<"4 = girar a la izquierda\n";
    cout<<"5 = avanzar\n";
    cout<<"6 = salir\n";
    do {
        
        cin>>opc;
        if (opc==1)
        {
            pluma=0;
            cout<<"pluma arriba"<<endl;
        }
        else if (opc==2)
        {
            pluma=1;
            cout<<"pluma abajo"<<endl;
        }
        else if(opc==3){
            girarDerecha += 1;
            if(girarDerecha==4)
                girarDerecha=0;
            cout<<girarDerecha<<"giraste a la derecha"<<endl;
        }
        else if(opc==4)
        {  girarDerecha -= 1;
        if(girarDerecha<0)
            girarDerecha=3;
        cout<<girarDerecha<<"giro a la izquierda"<<endl;
        }
        else if (opc==5) {
            cout<<"cuantos pasos quiere avanzar?"<<endl;
            cin>>pasos;
            if (girarDerecha==0)
                for (int j=posicionX, i=posicionY, k=pasos; k>0; j++,k--) {
                    if (j>=tam-1){
                        k=0;
                        tablero[i][j]=pluma;
                    }
                    tablero[i][j]=pluma;
                    posicionX=j;
                    // cout<<posicionX;
                }
            else if (girarDerecha==1)
                for (int k=pasos,i=posicionY, j=posicionX; k>0; k--,i++) {
                    if (pluma==1){
                    if (i>=tam-1){
                        k=0;
                        tablero[i][j]=pluma;
                    }
                    tablero[i][j]=pluma;
                    posicionY=i;
                    }
                    //  cout<<posicionY;
                }
            else if (girarDerecha==2)
                for (int k=posicionX, i=posicionY, j=pasos; j>0; j--,k--) {
                    if (pluma==1){
                    if (k==0){
                        j=0;
                        tablero[i][k]=pluma;
                    }
                    tablero[i][k]=pluma;
                    posicionX=k;
                    cout<<posicionX<<"x\n";
                }
                }
            else if (girarDerecha==3)
                for (int k=posicionY,j=posicionX, i=pasos; i>0; i--,k--) {
                    if (pluma==1){
                    if (k==0){
                        i=0;
                        tablero[k][j]=pluma;
                    }
                    tablero[k][j]=pluma;
                    posicionY=k;
                    // cout<<posicionY;
                }
                }
            
        }

    } while (opc!=6);
}
void mostrarTablero(int tablero[][20], int tam)
{
    for (int i=0; i<tam; i++) {
        for (int j=0; j<tam; j++){
            if (tablero[i][j]==1) {
                cout<<"*";
            }
            else
                cout<<" ";
        }
        cout<<"\n";
    }
}
void tabInicial(int tablero[][20], int tam)
{
        for (int i=0; i<tam; i++) {
          for (int j=0; j<tam; j++)
              cout<<" "<<tablero[i][j];
          cout<<"\n";
          }
}
void restablecerTablero(int tablero[][20],int tam)
{
    for (int i=0; i<tam; i++)
        for (int j=0; j<tam; j++)
            tablero[i][j]=0;
}
