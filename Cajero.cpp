#include <iostream>
//esto es una prueba de como hacer un commit
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
void retiro() {string numCuentaBusqueda;
    double montoRetiro;

    cout << "\n=== OPERAR RETIRO ===\n";
    cout << "Ingrese el numero de cuenta: ";
    cin >> numCuentaBusqueda;

    cout << "Ingrese el monto a retirar: ";
    cin >> montoRetiro;

    // Validar que el monto sea positivo (MONTO > 0)
    if (montoRetiro <= 0) {
        cout << "Error: El monto a retirar debe ser mayor a 0.\n";
        return;
    }

}

//Nombre:
//Realizar Transferencias
void transferencia() {

}

//Nombre:
//Consultar saldo de la cuenta
int consultarSaldo() {
    string numero;

    cout << "Ingrese numero de cuenta: ";
    getline(cin, numero);

    if (existeCuenta(numero) == 0) {
        cout << "Error: la cuenta no existe." << endl;
    } else {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Cuenta: " << numero << endl;
        cout << "Titular: " << obtenerNombre(numero) << endl;
        cout << "Saldo: Q " << obtenerSaldo(numero) << endl;
    }
    return 0;
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
