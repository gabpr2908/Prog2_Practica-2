#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int x, i = 1;

struct people
{
    int id;
    char name[100];
    int ci;
    int age;
    float weight;
    float height;
    char gender[1];
};

int main()
{
    people p;

    cout << "Cuantas personas va a registrar?" << endl;
    cin >> x;

    fstream FILE("./archivo.bin", ios::out | ios::binary);

    while (x > 0)
    {
        cout << "Ingrese los siguientes datos para el Registro #" << i << ":" << endl;
        cout << "ID de Registro: ";
        cin >> p.id;
        cout << "Nombre: ";
        cin >> p.name;
        cout << "Cedula: ";
        cin >> p.ci;
        cout << "Edad: ";
        cin >> p.age;
        cout << "Peso: ";
        cin >> p.weight;
        cout << "Altura: ";
        cin >> p.height;
        cout << "Genero (M o F): ";
        cin >> p.gender;

        FILE.write(reinterpret_cast<char *>(&p), sizeof(people));

        i++;
        x--;
    }

    FILE.close();
    return 0;
}