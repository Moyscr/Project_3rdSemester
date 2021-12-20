#include "videogame.h"
#include <fstream>
#include <algorithm>

Videogame::Videogame()
{

}

void Videogame::setUsuario(const string &v)
{
    nombre_usuario = v;
}

string Videogame::getUsuario()
{
    return nombre_usuario;
}

void Videogame::agregarCivilizacion(const Civilizacion &c)
{
    civilizaciones.push_back(c);
}

void Videogame::mostrar()
{
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(15) << "Ubicacion_X";
    cout << setw(15) << "Ubicacion_Y";
    cout << setw(10) << "Puntuacion";
    cout << endl;
    for (size_t i = 0; i < civilizaciones.size(); i++)
    {
        Civilizacion &c = civilizaciones[i];
        cout << c << endl;
    }
}

void Videogame::insertar(const Civilizacion &c, size_t pos)
{
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

void Videogame::inicializar(const Civilizacion &c, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, c);
}

Civilizacion Videogame::front()
{
    return civilizaciones.front();
}

Civilizacion Videogame::back()
{
    return civilizaciones.back();
}

void Videogame::ordenarNombre()
{
    sort(civilizaciones.begin(), civilizaciones.end());
}

void Videogame::ordenarX()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getUbicacionX() < c2.getUbicacionX();});
}

void Videogame::ordenarY()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getUbicacionY() < c2.getUbicacionY();});
}

void Videogame::ordenarPuntuacion()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() > c2.getPuntuacion();});
}

void Videogame::eliminar(const string &nombre)
{
    auto it = find_if(civilizaciones.begin(), civilizaciones.end(),
    [&nombre](Civilizacion& c1){return c1.getNombre() == nombre;});

    civilizaciones.erase(it);
}

Civilizacion* Videogame::buscar(const string &nombre)
{
   auto it = find_if(civilizaciones.begin(), civilizaciones.end(),
    [&nombre](Civilizacion& c1){return c1.getNombre() == nombre;});

   if(it == civilizaciones.end()){
       return nullptr;
   }
   else{
       return &(*it);
   }
}

size_t Videogame::total()
{
    return civilizaciones.size();
}

size_t Videogame::get_pos(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it != civilizaciones.end()){
        auto index = distance(civilizaciones.begin(), it);
        return index;
    }
}

void Videogame::respaldar()
{
    ofstream archivo("civilizaciones.txt");
    
    for (auto it = civilizaciones.begin(); it != civilizaciones.end(); ++it) {
        Civilizacion &civilizacion = *it; 
        archivo << civilizacion.getNombre() << endl;
        archivo << civilizacion.getUbicacionX() << endl;
        archivo << civilizacion.getUbicacionY() << endl;
        archivo << civilizacion.getPuntuacion() << endl;
        civilizacion.respaldar();
    }
    archivo.close();
}

void Videogame::recuperar()
{
    ifstream archivo("civilizaciones.txt");
    if(archivo.is_open()){
    string temp;
    float ubicacion_x;
    float ubicacion_y;
    int puntuacion;

    while(true){
        Civilizacion civilizacion;
        getline(archivo, temp);
        if(archivo.eof()){
            break;
        }
        civilizacion.setNombre(temp);

        getline(archivo, temp);
        ubicacion_x = stof(temp);
        civilizacion.setUbicacionX(ubicacion_x);

        getline(archivo, temp);
        ubicacion_y = stof(temp);
        civilizacion.setUbicacionY(ubicacion_y);

        getline(archivo, temp);
        puntuacion = stoi(temp);
        civilizacion.setPuntuacion(puntuacion);

        civilizacion.recuperar();

        agregarCivilizacion(civilizacion);
    }
}
archivo.close();
}