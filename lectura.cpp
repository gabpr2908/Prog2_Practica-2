#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

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
    fstream FILE("./archivo.bin", ios::in | ios::binary);

    FILE.seekg((sizeof(people) * 0), ios::beg);

    cout << FILE.tellg() << endl;

    FILE.read(reinterpret_cast<char *>(&p), sizeof(people));

    cout << "ID de Registro: " << p.id << endl;
    cout << "Nombre: " << p.name << endl;
    cout << "Cedula: " << p.ci << endl;
    cout << "Edad: " << p.age << endl;
    cout << "Peso: " << p.weight << endl;
    cout << "Altura: " << p.height << endl;
    cout << "Genero: " << p.gender << endl;

    FILE.close();
    return 0;
}