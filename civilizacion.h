#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include "aldeano.h"
#include "barco.h"

using namespace std;

class Civilizacion {
private:
    string nombre;
    float ubicacion_x;
    float ubicacion_y;
    int puntuacion;
    list<Aldeano> aldeanos;
    list<Barco*> puerto;
public:
    Civilizacion();
    Civilizacion(const string &nombre, float ubicacion_x, float ubicacion_y, int puntuacion)
    : nombre(nombre), ubicacion_x(ubicacion_x), ubicacion_y(ubicacion_y), puntuacion(puntuacion){}
    void setNombre(const string &v);
    string getNombre();
    void setUbicacionX(float v);
    float getUbicacionX();
    void setUbicacionY(float v);
    float getUbicacionY();
    void setPuntuacion(int v);
    int getPuntuacion();

    void agregarInicio(const Aldeano &a);
    void agregarFinal(const Aldeano &a);
    void mostrarAldeanos();

    void eliminarNombre(const string &nombre);
    void eliminarEdad();
    void eliminarSalud(size_t salud);

    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();

    void respaldar();
    void recuperar();

    void agregarBarco(Barco &b);
    void mostrarBarcos();
    Barco* buscarBarco(const string &id);
    void eliminarBarco(const string &id);
    void eliminarCombustible(float combustible);

    Aldeano* buscarAldeano(const string &nombre);

    friend ostream& operator<<(ostream &out, const Civilizacion &c)
    {
        out << setw(15) << c.nombre;
        out << setw(15) << c.ubicacion_x;
        out << setw(15) << c.ubicacion_y;
        out << setw(10) << c.puntuacion;
        return out;
    }

    friend istream& operator>>(istream &in, Civilizacion &c)
    {
        cout << endl;
        cout << "Nombre: ";
        fflush(stdin);
        getline(cin, c.nombre);

        cout << "Ubicacion en X: ";
        cin >> c.ubicacion_x;

        cout << "Ubicacion en Y: ";
        cin >> c.ubicacion_y;

        cout <<"Puntuacion: ";
        cin >> c.puntuacion;
        cout << endl;

        return in;
    }

    bool operator==(const Civilizacion& c)
    {
        return nombre == c.nombre;
    }

    bool operator==(const Civilizacion& c) const
    {
        return nombre == c.nombre;
    }

    bool operator<(const Civilizacion& c)
    {
        return nombre < c.nombre;
    }

    bool operator<(const Civilizacion& c) const
    {
        return nombre < c.nombre;
    }
};

#endif