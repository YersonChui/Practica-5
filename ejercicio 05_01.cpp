// Fecha creación: 22/09/2023
// Fecha modificación: 22/09/2023
// Número de ejericio: 1
// Problema planteado: La información de todos los empleados de la UCB se almacena en una variable tipo struct llamada “empleado”.
// La información con que se cuenta es: nombre, ci, departamento y salario. Realizar un programa en C++ que lea un array de estructura de los datos de N empleados e imprima los siguiente:
#include <iostream>
#include <string>
using namespace std;

struct empleado {
  string nombre;
  int ci;
  string departamento;
  float salario;
};
// función para leer los datos de un empleado
void leer_empleado(empleado &e) {
  cout << "Ingrese el nombre del empleado: ";
  getline(cin, e.nombre);
  cout << "Ingrese el ci del empleado: ";cin >> e.ci;
  cin.ignore(); // Limpiar el buffer de entrada
  cout << "Ingrese el departamento del empleado: ";
  getline(cin, e.departamento);
  cout << "Ingrese el salario del empleado: ";cin >> e.salario;
  cin.ignore();
}
// función para mostrar los datos 
void mostrar_empleado(empleado e) {
  cout << "Nombre: " << e.nombre << endl;
  cout << "CI: " << e.ci << endl;
  cout << "Departamento: " << e.departamento << endl;
  cout << "Salario: " << e.salario << endl;
}
// función para calcular el promedio salarial
float promedio_salarial(empleado empleados[], int n) {
  float suma = 0;
  for (int i = 0; i < n; i++) {
    suma += empleados[i].salario;
  }
  return suma / n;
}
// para calcular el promedio salarial por departamento por un array de empleados
float promedio_por_departamento(empleado empleados[], int n, string departamento) {
  float suma = 0;
  int contador = 0;
  for (int i = 0; i < n; i++) {
    if (empleados[i].departamento == departamento) {
      suma += empleados[i].salario;
      contador++;
    }
  }
  if (contador > 0) {
    return suma / contador;
  }
  else {
    return -1;
  }
}
//  Encuentra el departamento con mayor salario en promedio
string departamento_con_mayor_salario(empleado empleados[], int n) {
  string mayor_departamento = "";
  float mayor_promedio = -1;
  for (int i = 0; i < n; i++) {
    string departamento = empleados[i].departamento;
    float promedio = promedio_por_departamento(empleados, n, departamento);
    if (promedio > mayor_promedio) {
      mayor_promedio = promedio;
      mayor_departamento = departamento;
    }
  }
  return mayor_departamento;
}
// función para encontrar el departamento con menor salario en promedio 
string departamento_con_menor_salario(empleado empleados[], int n) {
  string menor_departamento = "";
  float menor_promedio = -1;
  for (int i = 0; i < n; i++) {
    string departamento = empleados[i].departamento;
    float promedio = promedio_por_departamento(empleados, n, departamento);
    if (promedio < menor_promedio || menor_promedio == -1) {
      menor_promedio = promedio;
      menor_departamento = departamento;
    }
  }
  return menor_departamento;
}
//función para encontrar el empleado con mayor salario
empleado empleado_con_mayor_salario(empleado empleados[], int n) {
  empleado mayor_empleado = empleados[0];
  for (int i = 1; i < n; i++) {
    if (empleados[i].salario > mayor_empleado.salario) {
      mayor_empleado = empleados[i];
    }
  }
  return mayor_empleado;
}
// función para encontrar el empleado con menor salari
empleado empleado_con_menor_salario(empleado empleados[], int n) {
   empleado menor_empleado = empleados[0];
   for (int i =1; i < n; i++) {
     if (empleados[i].salario < menor_empleado.salario) {
       menor_empleado = empleados[i];
     }
   }
   return menor_empleado;
}
int main() {
   int n;
   cout << "Ingrese el numero de empleados: ";cin >> n;
   cin.ignore();
   empleado empleados[n];
   for (int i = 0; i < n; i++) {
     cout << "Datos del empleado " << i + 1 << endl;
     leer_empleado(empleados[i]);
     cout << endl;
   }
   cout << "Los datos de los empleados son:" << endl;
   for (int i = 0; i < n; i++) {
     cout << "Empleado " << i + 1 << endl;
     mostrar_empleado(empleados[i]);
     cout << endl;
   }
   cout << "El empleado con mayor salario es:" << endl;
   mostrar_empleado(empleado_con_mayor_salario(empleados, n));
   cout << endl;
   cout << "El empleado con menor salario es:" << endl;
   mostrar_empleado(empleado_con_menor_salario(empleados, n));
   cout << endl;
   cout << "El promedio salarial es: " << promedio_salarial(empleados, n) << endl;
   cout << endl;
   cout << "El promedio por departamento es:" << endl;
   for (int i = 0; i < n; i++) {
     string departamento = empleados[i].departamento;
     float promedio = promedio_por_departamento(empleados, n, departamento);
     if (promedio != -1) {
       cout << departamento << ": " << promedio << endl;
       for (int j = 0; j < n; j++) {
         if (empleados[j].departamento == departamento) {
           empleados[j].salario = -1;
         }
       }
     }
   }
   cout << endl;
   cout << "El departamento con mayor salario en promedio es: "
        << departamento_con_mayor_salario(empleados, n) << endl;
   cout << endl;
   cout << "El departamento con menor salario en promedio es: "
        << departamento_con_menor_salario(empleados, n) << endl;
  return 0;
}

