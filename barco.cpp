#include "barco.h"

Barco::Barco()
{

}

void Barco::setId(const string &v)
{
    id = v;
}

string Barco::getId()
{
    return id;
}

void Barco::setCombustible(float v)
{
    combustible = v;
}

float Barco::getCombustible()
{
    return combustible;
}

void Barco::setVelocidad(float v)
{
    velocidad = v;
}

float Barco::getVelocidad()
{
    return velocidad;
}

void Barco::setArmadura(float v)
{
    armadura = v;
}

float Barco::getArmadura()
{
    return armadura;
}

void Barco::agregarGuerrero(const Guerrero &g)
{
    ejercito.push(g);
}

void Barco::eliminarGuerrero()
{
    ejercito.pop();
}

void Barco::tope()
{   if(ejercito.empty()){
        cout << "no existen guerreros" << endl;
    }
    else {
        cout << left;
        cout << setw(8) << "Id";
        cout << setw(8) << "Salud";
        cout << setw(8) << "Fuerza";
        cout << setw(8) << "Escudo";
        cout << setw(10) << "Tipo";
        cout << endl;
        cout << ejercito.top() << endl;
    }
}

stack<Guerrero> Barco::crearCopia()
{
    stack<Guerrero> copia(ejercito);
    return copia;
}

