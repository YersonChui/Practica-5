// Fecha creación: 22/09/2023
// Fecha modificación: 24/09/2023
// Número de ejericio: 2
// Problema planteado: La información de todos los empleados de la UCB se almacena en una variable tipo struct llamada “empleado”.
#include <iostream>
using namespace std;

struct datos
{
    char nombre[40];
    char pais[25];
};
struct atleta
{
    char deporte[30];
    struct datos pers;
    int medallas;
};

int main()
{
    int N;
    cout << "Ingrese el numero de atletas: ";cin >> N;
    cin.ignore();

    struct atleta ats[N]; // arreglo de atletas
    for (int i = 0; i < N; i++)
    {
        cout << "Ingrese el deporte del atleta " << i + 1 << ": ";
        cin.getline(ats[i].deporte, 30);
        cout << "Ingrese el nombre del atleta " << i + 1 << ": ";
        cin.getline(ats[i].pers.nombre, 40);
        cout << "Ingrese el pais del atleta " << i + 1 << ": ";
        cin.getline(ats[i].pers.pais, 25);
        cout << "Ingrese el numero de medallas del atleta " << i + 1 << ": ";
        cin >> ats[i].medallas;
        cin.ignore();
        cout << endl;
    }

    // calcular el país con mayor número de medallas
    char pais_ganador[25];
    int max_medallas = 0;
    //  atletas
    for (int i = 0; i < N; i++)
    {
        int medallas_pais = 0;

        // comparar los países
        for (int j = 0; j < N; j++)
        {
            if ((ats[i].pers.pais== ats[j].pers.pais) == 0)
            {
                medallas_pais += ats[j].medallas;
            }
        }
        if (medallas_pais > max_medallas)
        {
            max_medallas = medallas_pais;
            (pais_ganador == ats[i].pers.pais);
        }
    }
    cout << "El pais que ha ganado mas medallas es: " << pais_ganador << endl;
    cout << "El numero de medallas que ha ganado es: " << max_medallas << endl;

    return 0;
}

