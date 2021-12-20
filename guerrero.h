#ifndef GUERRERO_H
#define GUERRERO_H

#include <iostream>
#include <iomanip>
using namespace std;

class Guerrero {
private:
    string id;
    int salud;
    float fuerza;
    float escudo;
    string tipo;
public:
    Guerrero();
    void setId(const string &v);
    string getId();
    void setSalud(int v);
    int getSalud();
    void setFuerza(float v);
    float getFuerza();
    void setEscudo(float v);
    float getEscudo();
    void setTipo(const string &v);
    string getTipo();

    friend ostream& operator<<(ostream &out, const Guerrero &g)
    {
        out << setw(8) << g.id;
        out << setw(8) << g.salud;
        out << setw(8) << g.fuerza;
        out << setw(8) << g.escudo;
        out << setw(10) << g.tipo;
        return out;
    }
};

#endif