#include <iostream>
#include <fstream>   // Para utilizar archivos
#include <string>    // Para utilizar cadenas
#include <sstream>   // Para usar stringstream, convierte cadena en un flujo de caracteres

using namespace std;

//Cuando trabajen en su parte coloquen su nombre y apellido en donde dice "Nombre:", asi sabemos quien trabajo en su parte

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

//Nombre: Fernando Mencos
//Realizar Transferencias
void transferencia() {
    string cuentaOrigen, cuentaDestino;
    double monto = 0.0;

    cout << "\n--- REALIZAR TRANSFERENCIA ---\n";
    cout << "Ingrese el numero de cuenta origen: ";
    cin >> cuentaOrigen;

    cout << "Ingrese el numero de cuenta destino: ";
    cin >> cuentaDestino;

    // Validar que las cuentas origen y destino sean distintas
    if (cuentaOrigen == cuentaDestino) {
        cout << "Error: La cuenta origen y la cuenta destino deben ser distintas.\n";
        return;
    }
    cout << "Ingrese el monto a transferir: ";
    cin >> monto;

    // Validar que el monto sea mayor a 0
    if (monto <= 0) {
        cout << "Error: El monto a transferir debe ser mayor a 0.\n";
        return;
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
