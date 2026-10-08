#include <iostream>

using namespace std;

//Nombre:
//Crear una cuenta monetaria
void crearCuenta() {

}

//Nombre:
//Operar deposito
void deposito() {

}

//Nombre:
//Operar retiro
void retiro() {

}

//Nombre:
//Realizar Transferencias
void transferencia() {

}

//Nombre:
//Consultar saldo de la cuenta
void consultarSaldo() {

}


int main() {
    //Menu principal
    int opcion; //se puede cambiar si no es viable
    do {
        //Menu de opciones
        cout << "\nSISTEMA DE CUENTAS MONETARIAS\n";
        cout << "1. Crear cuenta monetaria\n";
        cout << "2. Operar deposito\n";
        cout << "3. Operar retiro\n";
        cout << "4. Realizar transferencia\n";
        cout << "5. Consultar saldo de cuenta\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:crearCuenta();break;
            case 2:deposito();break;
            case 3:retiro();break;
            case 4:transferencia();break;
            case 5:consultarSaldo();break;
            case 6:cout << "Salida programa";break;
            default:cout << "Opcion no valida.\n";
        }
    }while (opcion != 6);

    return 0;
}
