#include <iostream>

using namespace std;

// Definición de la estructura de cada nodo de la cola
struct Nodo {
    string nombre;
    int documento;
    Nodo* siguiente;
};

// Función para insertar un nuevo paciente en la cola
void insertarPaciente(Nodo*& frente, Nodo*& fin, string nombre, int documento) {
    Nodo* nuevo = new Nodo();
    nuevo->nombre = nombre;
    nuevo->documento = documento;
    nuevo->siguiente = nullptr;
    if (frente == nullptr) {
        frente = nuevo;
        fin = nuevo;
    } else {
        fin->siguiente = nuevo;
        fin = nuevo;
    }
}

// Función para mostrar todos los pacientes en orden de registro
void mostrarPacientes(Nodo* frente) {
    int contador = 1;
    while (frente != nullptr) {
        cout << contador << ". " << frente->nombre << " (" << frente->documento << ")" << endl;
        frente = frente->siguiente;
        contador++;
    }
}

int main() {
    Nodo* frente = nullptr;
    Nodo* fin = nullptr;
    int opcion = 0;
    while (opcion != 3) {
        cout << "Seleccione una opción:" << endl;
        cout << "1. Registrar un nuevo paciente" << endl;
        cout << "2. Mostrar todos los pacientes" << endl;
        cout << "3. Salir" << endl;
        cin >> opcion;
        if (opcion == 1) {
            string nombre;
            int documento;
            cout << "Ingrese el nombre del paciente: ";
            cin >> nombre;
            cout << "Ingrese el número de documento del paciente: ";
            cin >> documento;
            insertarPaciente(frente, fin, nombre, documento);
        } else if (opcion == 2) {
            mostrarPacientes(frente);
        } else if (opcion != 3) {
            cout << "Opción inválida. Intente de nuevo." << endl;
        }
    }
    return 0;
}