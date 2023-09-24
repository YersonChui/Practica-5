// Fecha creaci�n: 22/09/2023
// Fecha modificaci�n: 24/09/2023
// N�mero de ejericio: 3
// Problema planteado: Estacionamiento
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Vehiculo {
    string tipo;
    string marca;
    string modelo;
    string color;
    int piso;
};
// funci�n para tipo de veh�culo aleatorio
string generar_tipo() {
    string tipos[5] = {"vagoneta", "camioneta", "autom�vil", "minivan", "motocicleta"};
    return tipos[rand() % 5];
}
// funci�n para marca de veh�culo
string generar_marca() {
    string marcas[10] = {"Toyota", "Ford", "Nissan", "Chevrolet", "Hyundai", "Honda", "Kia", "Mazda", "Suzuki", "Renault"};
    return marcas[rand() % 10];
}
// funci�n para un modelo de veh�culo
string generar_modelo() {
    string modelos[10] = {"Corolla", "Ranger", "Sentra", "Spark", "Accent", "Civic", "Sportage", "CX-5", "Swift", "Duster"};
    return modelos[rand() % 10];
}
// funci�n para un color de veh�culo
string generar_color() {
    string colores[10] = {"rojo", "azul", "verde", "negro", "blanco", "gris", "amarillo", "naranja", "morado", "rosado"};
    return colores[rand() % 10];
}
// funci�n para contar cu�ntos veh�culos hay de cada tipo
void contar_tipos(Vehiculo vehiculos[], int n) {
    string tipos[5] = {"vagoneta", "camioneta", "autom�vil", "minivan", "motocicleta"};
    int contadores[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (vehiculos[i].tipo == tipos[j]) {
                contadores[j]++;
                break;
            }
        }
    }
cout << "\nLa cantidad de veh�culos por tipo es:\n";
    for (int j = 0; j < 5; j++) {
        cout << tipos[j] << ": " << contadores[j] << endl;
    }
}
// funci�n que asigna un piso al veh�culo seg�n la disponibilidad
int asignar_piso(int capacidad[4]) {
    int maximo[4] = {50, 40, 30, 45};//capcidad de cada piso
    for (int i = 0; i < 4; i++) {//ve la cap de cada piso
        if (capacidad[i] < maximo[i]) {//asigna
            capacidad[i]++;
            return i + 1;
        }
    }
    return -1;
}

// funci�n para hacer un reporte por colores de autos, modelo y marca
void reporte_colores(Vehiculo vehiculos[], int n) {
    string colores[10] = {"rojo", "azul", "verde", "negro", "blanco", "gris", "amarillo", "naranja", "morado", "rosado"};
    for (int i = 0; i < 10; i++) {
        cout << "\nColor: " << colores[i] << endl;
        for (int j = 0; j < n; j++) {
            if (vehiculos[j].color == colores[i]) {
                cout << "\nMarca: " << vehiculos[j].marca << endl;
                cout << "Modelo: " << vehiculos[j].modelo << endl;
            }
        }
    }
}

//funci�n para mostrar los datos de un veh�culo
void mostrar_vehiculo(Vehiculo v) {
    cout << "Tipo: " << v.tipo << endl;
    cout << "Marca: " << v.marca << endl;
    cout << "Modelo: " << v.modelo << endl;
    cout << "Color: " << v.color << endl;
    cout << "Piso: " << v.piso << endl;
}
// Definir una funci�n para mostrar los datos de todos los veh�culos ingresados
void mostrar_vehiculos(Vehiculo vehiculos[], int n) {
    cout << "\nLos vehiculos ingresados son:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nVehiculo #" << i + 1 << endl;
        mostrar_vehiculo(vehiculos[i]);
    }
}
//  funci�n para mostrar la cantidad de veh�culos estacionados en cada piso
void mostrar_pisos(int capacidad[4]) {
    cout << "\nLa cantidad de vehiculos estacionados en cada piso es:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Piso " << i + 1 << ": " << capacidad[i] << endl;
    }
}

// funci�n para simular la entrada de veh�culos
void simular_entrada(Vehiculo vehiculos[], int &n, int capacidad[4]) {
    int cantidad;
    cout << "\nIngrese la cantidad de vehiculos a ingresar: ";cin >> cantidad;
    if (cantidad == 0) {
        cout << "\nSimulacion terminada.\n";
        return;
    }
    // Si la cantidad es mayor que el espacio disponible, mostrar un mensaje de error y volver a pedir la cantidad
    int espacio = 165 - n;
    if (cantidad > espacio) {
        cout << "\nNo hay suficiente espacio para ingresar esa cantidad de vehiculos.\n";
        cout << "El espacio disponible es de " << espacio << " vehiculos.\n";
        simular_entrada(vehiculos, n, capacidad);
        return;
    }
    // Generar los datos de los veh�culos a ingresar y asignarles un piso
    for (int i = 0; i < cantidad; i++) {
        Vehiculo v;
        v.tipo = generar_tipo();
        v.marca = generar_marca();
        v.modelo = generar_modelo();
        v.color = generar_color();
        v.piso = asignar_piso(capacidad);
        // Si el piso asignado es -1, significa que no hay espacio y mostrar un mensaje de error
        if (v.piso == -1) {
            cout << "\nNo hay espacio para el vehiculo #" << i + 1 << endl;
            break;
        }
        vehiculos[n] = v;
        n++;
    }
    mostrar_vehiculos(vehiculos, n);
    mostrar_pisos(capacidad);
    simular_entrada(vehiculos, n, capacidad);
}
int main() {
    srand((NULL));//random
    Vehiculo vehiculos[165];
    int n = 0;//cuenta los autos
    int capacidad[4] = {0, 0, 0, 0};
    simular_entrada(vehiculos, n, capacidad);
    contar_tipos(vehiculos, n);
    reporte_colores(vehiculos, n);
    if (n == 165) {
        cout << "\nEl estacionamiento se ha llenado.\n";
    } else {
        cout << "\nEl estacionamiento a�n tiene espacio.\n";
        cout << "El espacio libre es de " << 165 - n << " veh�culos.\n";
    }
    return 0;
}

