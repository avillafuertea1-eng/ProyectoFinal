#include <iostream>
#include <fstream>   // Para utilizar archivos
#include <string>    // Para utilizar cadenas
#include <sstream>   // Para usar stringstream, convierte cadena en un flujo de caracteres

using namespace std;

void diseño() {
    cout << "----------------------------------------------------\n";
}

// Comprueba que la cuenta exista: devuelve 1 si existe, 0 si no existe
int existeCuenta(int numero) {
    ifstream archivo("cuentas/CTASMONETARIAS.txt");
    string linea, num;
    int existe = 0;
    string numero_str = std::to_string(numero);

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        getline(ss, num, '|');
        if (num == numero_str) {
            existe = 1;
        }
    }
    archivo.close();
    return existe;
}

// Devuelve el saldo actual de una cuenta
float obtenerSaldo(int numero) {
    ifstream archivo("cuentas/CTASMONETARIAS.txt");
    string linea, num, nom, tel, cor, saldo_str;
    float saldo = 0;
    string numero_str = std::to_string(numero);

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        getline(ss, num, '|');
        getline(ss, nom, '|');
        getline(ss, tel, '|');
        getline(ss, cor, '|');
        getline(ss, saldo_str, '|');
        if (num == numero_str) {
            stringstream conv(saldo_str);
            conv >> saldo;
        }
    }
    archivo.close();
    return saldo;
}

// Devuelve el nombre de la persona de la cuenta
string obtenerNombre(int numero) {
    ifstream archivo("cuentas/CTASMONETARIAS.txt");
    string linea, num, nom, nombre = "", numero_str = std::to_string(numero);

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        getline(ss, num, '|');
        getline(ss, nom, '|');
        if (num == numero_str) {
            nombre = nom;
        }
    }
    archivo.close();
    return nombre;
}

// Suma 'monto' al saldo de la cuenta para restar se envia negativo

int actualizarSaldo(int numero, float monto) {
    ifstream archivo("cuentas/CTASMONETARIAS.txt");
    string linea, num, nom, tel, cor, saldo_str, contenido = "";
    string numero_str = std::to_string(numero);
    float saldo;

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        getline(ss, num, '|');
        getline(ss, nom, '|');
        getline(ss, tel, '|');
        getline(ss, cor, '|');
        getline(ss, saldo_str, '|');

        if (num == numero_str) {
            stringstream conv(saldo_str);
            conv >> saldo;
            saldo = saldo + monto;

            stringstream sal;
            sal.setf(ios::fixed);
            sal.precision(2);
            sal << saldo;
            saldo_str = sal.str();
        }
        contenido = contenido + num + "|" + nom + "|" + tel + "|" + cor + "|" + saldo_str + "\n";
    }
    archivo.close();

    ofstream salida("cuentas/CTASMONETARIAS.txt");   // Reemplaza el contenido
    salida << contenido;
    salida.close();
    return 0;
}

// Montos: solo valores positivos se permiten decimales
float leerMonto(string mensaje) {
    string texto;
    float monto = 0;

    while (monto <= 0) {
        monto = 0;
        cout << mensaje;
        getline(cin, texto);
        stringstream ss(texto);
        ss >> monto;
        if (monto <= 0) {
            cout << "Error: ingrese un monto numerico mayor que 0." << endl;
        }
    }
    return monto;
}

// CREAR CUENTA MONETARIA
int crearCuenta() {
    ofstream archivo;
    int numero, telefono;
    string nombre, correo;

    diseño();
    cout << "CREACION DE CUENTA\n";
    cout << "Ingrese numero de cuenta: ";
    cin >> numero;
    cin.ignore();
    //getline(cin, numero);

    if (existeCuenta(numero) == 1) {
        cout << "Error: la cuenta ya existe." << endl;
    } else {
        cout << "Ingrese nombre del cuenta habiente: ";
        getline(cin, nombre);
        cout << "Ingrese telefono: ";
        cin >> telefono;
        cin.ignore();
        //getline(cin, telefono);
        cout << "Ingrese correo electronico: ";
        getline(cin, correo);

        // Abrir archivo en modo append (ios::app)
        archivo.open("cuentas/CTASMONETARIAS.txt", ios::app);

        if (!archivo) {
            cin.ignore();
            cout << "No se pudo abrir el archivo." << endl;
        } else {
            archivo << numero << "|" << nombre << "|" << telefono << "|" << correo << "|" << "0" << endl;
            archivo.close();
            cout << "Cuenta creada correctamente." << endl;
        }
    }
    diseño();
    return 0;
}

//OPERAR DEPOSITO
int operarDeposito() {
    int numero;
    float monto;

    diseño();
    cout << "Ingrese numero de cuenta: ";
    cin >> numero;
    cin.ignore();
    //getline(cin, numero);

    if (existeCuenta(numero) == 0) {
        cout << "Error: la cuenta no existe." << endl;
    } else {
        monto = leerMonto("Ingrese monto del deposito: ");
        actualizarSaldo(numero, monto);
        cout << "Deposito realizado correctamente." << endl;
    }
    diseño();
    return 0;
}

// OPERAR RETIRO
int operarRetiro() {
    int numero;
    float monto;

    diseño();
    cout << "Ingrese numero de cuenta: ";
    cin >> numero;
    cin.ignore();
    //getline(cin, numero);

    if (existeCuenta(numero) == 0) {
        cout << "Error: la cuenta no existe." << endl;
    } else {
        monto = leerMonto("Ingrese monto del retiro: ");
        if (monto > obtenerSaldo(numero)) {
            cout << "Error: saldo insuficiente. No se realizo el retiro." << endl;
        } else {
            actualizarSaldo(numero, -monto);
            cout << "Retiro realizado correctamente." << endl;
        }
    }
    diseño();
    return 0;
}

// REALIZAR TRANSFERENCIA
int realizarTransferencia() {
    int origen, destino;
    float monto;

    diseño();
    cout << "Ingrese numero de cuenta origen: ";
    cin >> origen;
    cin.ignore();
    //getline(cin, origen);
    cout << "Ingrese numero de cuenta destino: ";
    cin >> destino;
    cin.ignore();
    //getline(cin, destino);

    if (existeCuenta(origen) == 0 || existeCuenta(destino) == 0) {
        cout << "Error: alguna de las cuentas no existe." << endl;
    } else if (origen == destino) {
        cout << "Error: las cuentas origen y destino deben ser distintas." << endl;
    } else {
        monto = leerMonto("Ingrese monto de la transferencia: ");
        if (monto > obtenerSaldo(origen)) {
            cout << "Error: saldo insuficiente en la cuenta origen." << endl;
        } else {
            actualizarSaldo(origen, -monto);
            actualizarSaldo(destino, monto);
            cout << "Transferencia realizada correctamente." << endl;
        }
    }
    diseño();
    return 0;
}

// CONSULTAR SALDO DE CUENTA
int consultarSaldo() {
    int numero;

    diseño();
    cout << "Ingrese numero de cuenta: ";
    cin >> numero;
    cin.ignore();
    //getline(cin, numero);

    if (existeCuenta(numero) == 0) {
        cout << "Error: la cuenta no existe." << endl;
    } else {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Cuenta: " << numero << endl;
        cout << "Titular: " << obtenerNombre(numero) << endl;
        cout << "Saldo: Q " << obtenerSaldo(numero) << endl;
    }
    diseño();
    return 0;
}

// MENU PRINCIPAL
int main() {
    int opcion = 0;
    ofstream archivo;

    // Si el archivo no existe, se crea desde el inicio (modo append)
    archivo.open("cuentas/CTASMONETARIAS.txt", ios::app);
    archivo.close();

    while (opcion != 6) {
        cout << endl;
        diseño();
        cout << "===== CUENTAS MONETARIAS =====" << endl;
        cout << "1. Crear cuenta monetaria" << endl;
        cout << "2. Operar deposito" << endl;
        cout << "3. Operar retiro" << endl;
        cout << "4. Realizar transferencia" << endl;
        cout << "5. Consultar saldo de cuenta" << endl;
        cout << "6. Salir" << endl;
        diseño();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();   // elimina del buffer el enter de la opcion
        cout << endl;


        switch (opcion) {
            case 1: crearCuenta(); break;
            case 2: operarDeposito(); break;
            case 3: operarRetiro(); break;
            case 4: realizarTransferencia(); break;
            case 5: consultarSaldo(); break;
            case 6: diseño(); cout << "Esperamos su regreso\n"; diseño(); break;
            default: cout << "Opcion no valida"; break;
        }
    }

    return 0;
}
