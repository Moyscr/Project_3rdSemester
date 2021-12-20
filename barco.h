#ifndef BARCO_H
#define BARCO_H

#include "guerrero.h"
#include <iostream>
#include <stack>
using namespace std;

class Barco{
private:
    string id;
    float combustible;
    float velocidad;
    float armadura;
    stack<Guerrero> ejercito;
public:
    Barco();
    void setId(const string &v);
    string getId();
    void setCombustible(float v);
    float getCombustible();
    void setVelocidad(float v);
    float getVelocidad();
    void setArmadura(float v);
    float getArmadura(); 

    void agregarGuerrero(const Guerrero &g);
    void eliminarGuerrero();
    void tope();
    stack<Guerrero> crearCopia();

    friend ostream& operator<<(ostream &out, const Barco &b)
    {
        out << setw(8) << b.id;
        out << setw(12) << b.combustible;
        out << setw(10) << b.velocidad;
        out << setw(10) << b.armadura;
        out << setw(10) << b.ejercito.size();
        return out;
    }
};

#endif