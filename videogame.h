#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>

class Videogame{
    string nombre_usuario;
    vector<Civilizacion> civilizaciones;
public:
    Videogame();
    void agregarCivilizacion(const Civilizacion &c);
    void mostrar();
    void insertar(const Civilizacion &c, size_t pos);
    void inicializar(const Civilizacion &c, size_t n);
    Civilizacion front();
    Civilizacion back();
    void ordenarNombre();
    void ordenarX();
    void ordenarY();
    void ordenarPuntuacion();
    void eliminar(const string &nombre);
    Civilizacion* buscar(const string &nombre);
    size_t total();
    size_t get_pos(const Civilizacion &c);

    void respaldar();
    void recuperar();

    void setUsuario(const string &v);
    string getUsuario();

    friend istream& operator>>(istream &in, Videogame &v)
    {
        cout << "Usuario: ";
        fflush(stdin);
        getline(cin, v.nombre_usuario);

        return in;
    } 
};

#endif