#include "guerrero.h"

Guerrero::Guerrero()
{

}

void Guerrero::setId(const string &v)
{
    id = v;
}

string Guerrero::getId()
{
    return id;
}

void Guerrero::setSalud(int v)
{
    salud = v;
}

int Guerrero::getSalud()
{
    return salud;
}

void Guerrero::setFuerza(float v)
{
    fuerza = v;
}

float Guerrero::getFuerza()
{
    return fuerza;
}

void Guerrero::setEscudo(float v)
{
    escudo = v;
}

float Guerrero::getEscudo()
{
    return escudo;
}

void Guerrero::setTipo(const string &v)
{
    tipo = v;
}

string Guerrero::getTipo()
{
    return tipo;
}