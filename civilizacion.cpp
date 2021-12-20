#include "civilizacion.h"
#include "videogame.h"
#include <fstream>
#include <algorithm>

Civilizacion::Civilizacion()
{

}

void Civilizacion::setNombre(const string &v)
{
    nombre = v;
}

string Civilizacion::getNombre()
{
    return nombre;
}

void Civilizacion::setUbicacionX(float v)
{
    ubicacion_x = v;
}

float Civilizacion::getUbicacionX()
{
    return ubicacion_x;
}

void Civilizacion::setUbicacionY(float v)
{
    ubicacion_y = v;
}

float Civilizacion::getUbicacionY()
{
    return ubicacion_y;
}

void Civilizacion::setPuntuacion(int v)
{
    puntuacion = v;
}

int Civilizacion::getPuntuacion()
{
    return puntuacion;
}

void Civilizacion::agregarInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
    puntuacion += 100;
}

void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
    puntuacion += 100;
}

void Civilizacion::mostrarAldeanos()
{
    cout << left;
    cout << setw(12) << "Nombre";
    cout << setw(5) << "Edad";
    cout << setw(10) << "Genero";
    cout << setw(8) << "Salud";
    cout << endl;
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout << *it << endl;
    }
}

void Civilizacion::eliminarNombre(const string &nombre)
{
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;
        if(nombre == a.getNombre()){
            aldeanos.erase(it);
            break;
        }
    }
}

bool comparador(const Aldeano &a)
{
    return a.getEdad() >= 60;
}

void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if(comparador);
}

void Civilizacion::eliminarSalud(size_t salud)
{
    aldeanos.remove_if([salud](const Aldeano &a){return a.getSalud() < salud;});
}

void Civilizacion::ordenarNombre()
{
    aldeanos.sort();
}

void Civilizacion::ordenarEdad()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getEdad() > a2.getEdad();});
}

void Civilizacion::ordenarSalud()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

void Civilizacion::respaldar()
{
    ofstream archivo(getNombre() + ".txt", ios::out);
    
    for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it) {
        Aldeano &aldeano = *it; 
        archivo << aldeano.getNombre() << endl;
        archivo << aldeano.getEdad()   << endl;
        archivo << aldeano.getGenero() << endl;
        archivo << aldeano.getSalud()  << endl;
        cout << endl;
    }
    archivo.close();
}

void Civilizacion::recuperar()
{
    ifstream archivo(getNombre() + ".txt");

    if(archivo.is_open()){
        string temp;
        int edad;
        int salud;
        Aldeano aldeano;

        while(true){
            getline(archivo, temp);
            if(archivo.eof()){
                break;
            }
            aldeano.setNombre(temp);

            getline(archivo, temp);
            edad = stoi(temp);
            aldeano.setEdad(edad);

            getline(archivo, temp);
            aldeano.setGenero(temp);

            getline(archivo, temp);
            salud = stoi(temp);
            aldeano.setSalud(salud);

            agregarFinal(aldeano);
        }
    }
    archivo.close();
}

Aldeano* Civilizacion::buscarAldeano(const string &nombre)
{
   auto it = find_if(aldeanos.begin(), aldeanos.end(),
    [&nombre](Aldeano& a1){return a1.getNombre() == nombre;});

   if(it == aldeanos.end()){
       return nullptr;
   }
   else{
       return &(*it);
   }
}

void Civilizacion::agregarBarco(Barco &b)
{
    puerto.push_back(&b);
}

void Civilizacion::mostrarBarcos()
{
    cout << left;
    cout << setw(8) << "Id";
    cout << setw(12) << "Combustible";
    cout << setw(10) << "Velocidad";
    cout << setw(10) << "Armadura";
    cout << setw(10) << "Guerreros";
    cout << endl;
    for(auto it = puerto.begin(); it != puerto.end(); it++){
        auto &e = *it;
        cout << *e << endl;
    }
}

Barco* Civilizacion::buscarBarco(const string &id)
{ 
   auto it = find_if(this->puerto.begin(), this->puerto.end(),
    [&id](Barco *b1){return b1->getId() == id;});

   if(it == puerto.end()){
       return nullptr;
   }
   else{
       return *it;
   }
}

void Civilizacion::eliminarBarco(const string &id)
{
     puerto.remove_if([&id](Barco *b1){
         if(b1->getId() == id){
             delete(b1);
             return true;
         } else {
             return false;
         }
     });
}

void Civilizacion::eliminarCombustible(float combustible)
{
    puerto.remove_if([combustible](Barco *b1){
         if(b1->getCombustible() < combustible){
             delete(b1);
             return true;
         } else {
             return false;
         }
     });
}
