#include <iostream>
#include "civilizacion.h"
#include "videogame.h"
#include "menualdeanos.h"
#include "menubarcos.h"

using namespace std;

int main(){
    Videogame vg;
    Civilizacion cv;
    string opc;

    while(true)
    {
        cout << endl;
        cout << "a) Definir nombre de usuario" << endl;
        cout << "b) Agregar civilizacion" << endl;
        cout << "c) Insertar civilizacion" << endl;
        cout << "d) Crear civilizaciones" << endl; 
        cout << "e) Mostrar primera civilizacion" << endl;
        cout << "f) Mostrar ultima civilizacion" << endl;
        cout << "g) Ordenar" << endl;
        cout << "h) Eliminar civilizacion" << endl;
        cout << "i) Buscar" << endl;
        cout << "j) Modificar" << endl;
        cout << "k) Respaldar" << endl;
        cout << "l) Recuperar" << endl;
        cout << "m) Resumen" << endl;
        cout << "n) Salir" << endl;
        getline(cin, opc);

        if(opc == "a" || opc == "A") {
            string usuario;
            cout << "Ingrese el nuevo nombre de usuario: ";
            cin >> usuario;
            cin.ignore();
            vg.setUsuario(usuario);
            cout << "Nuevo usuario: " << vg.getUsuario() << endl;
        }
        else if(opc == "b" || opc == "B") {
            Civilizacion c;
            cin >> c;
            vg.agregarCivilizacion(c);
            cin.ignore(); 
        }
        else if(opc == "c" || opc == "C") {
            Civilizacion c;
            cin >> c;

            size_t pos;
            cout << "posicion: ";
            cin >> pos; cin.ignore();

            if(pos >= vg.total())
            {
                cout << "posicion no valida" << endl;
            }
            else{
                vg.insertar(c, pos);
            }
        }
        else if(opc == "d" || opc == "D"){
            Civilizacion c;
            cin >> c;

            size_t n;
            cout << "n: ";
            cin >> n; cin.ignore();
            
            vg.inicializar(c, n);
        }
        else if(opc == "e" || opc == "E") {
            if(vg.total() > 0){
                Civilizacion c = vg.front();
                cout << left;
                cout << setw(15) << "Nombre";
                cout << setw(15) << "Ubicacion_X";
                cout << setw(15) << "Ubicacion_Y";
                cout << setw(10) << "Puntuacion";
                cout << endl;
                cout << c << endl;
            }
            else{
                cout << "No hay civilizaciones" << endl;
            }
        }
        else if(opc == "f" || opc == "F") {
            if(vg.total() > 0){
                Civilizacion c = vg.back();
                cout << left;
                cout << setw(15) << "Nombre";
                cout << setw(15) << "Ubicacion_X";
                cout << setw(15) << "Ubicacion_Y";
                cout << setw(10) << "Puntuacion";
                cout << endl;
                cout << c << endl;
            }
            else{
                cout << "No hay civilizaciones" << endl;
            }
        }
        else if(opc == "g" || opc == "G") {
            int op;
            cout << "Conforme a que atributo le gustaria ordenar?" << endl;
            cout << "1. Nombre" << endl;
            cout << "2. Ubicacion en X" << endl;
            cout << "3. Ubicacion en Y" << endl;
            cout << "4. Puntuacion" << endl;
            cin >> op;
            cin.ignore();

            if(op == 1){
                vg.ordenarNombre();
            }
            else if(op == 2){
                vg.ordenarX();
            }
            else if(op == 3){
                vg.ordenarY();
            }
            else if(op == 4){
                vg.ordenarPuntuacion();
            }
        }
        else if(opc == "h" || opc == "H") {
            string nombre;
            cout << "Ingrese el nombre de la civilizacion que le gustaria eliminar: ";
            getline(cin, nombre);
            
            vg.eliminar(nombre);

        }
        else if(opc == "i" || opc == "I") {
            int op;
            string nombre;
            cout << "ingrese el nombre de la civilizacione a buscar: ";
            getline(cin, nombre);

            Civilizacion *ptr = vg.buscar(nombre);

            if(ptr == nullptr){
                cout << "no encontrado" << endl;
            }
            else{
                cout << *ptr << endl;
            }

            Civilizacion &civilizacion = *ptr;
            cout << "Ingrese al apartado al que le gustaria acceder" << endl;
            cout << "1) Administrar aldeanos" << endl;
            cout << "2) Administrar barcos y guerreros" << endl;
            cin >> op;

            if(op == 1){
                menuAldeano(civilizacion);
            }
            else if(op == 2){
                menuBarco(civilizacion);
            }
        }
        else if(opc == "j" || opc == "J") {
            string nombre;
            int op;
            cout << "Ingrese el nombre de la civilizacion a modificar: ";
            getline(cin, nombre);

            Civilizacion *ptr = vg.buscar(nombre);
            Civilizacion c1 = *ptr;
            int pos = vg.get_pos(*ptr);

            if(ptr == nullptr){
                cout << "no encontrado" << endl;
            }
            else{
                cout << left;
                cout << setw(15) << "Nombre";
                cout << setw(15) << "Ubicacion_X";
                cout << setw(15) << "Ubicacion_Y";
                cout << setw(10) << "Puntuacion";
                cout << endl;
                cout << *ptr << endl;
                cout << endl << "Que atributo quisiera modificar?" << endl;
                cout << "1. Nombre" << endl;
                cout << "2. Ubicacion en X" << endl;
                cout << "3. Ubicacion en Y" << endl;
                cout << "4. Puntuacion" << endl;
                cin >> op;

                if(op == 1){
                    string new_nombre;
                    vg.eliminar(nombre);
                    cout << "Ingrese el nuevo nombre ";
                    cin.ignore();
                    getline(cin, new_nombre);
                    c1.setNombre(new_nombre);
                    vg.insertar(c1, pos);
                }
                else if(op == 2){
                    float new_ubicacionX;
                    vg.eliminar(nombre);
                    cout << "Ingrese la nueva ubicacion ";
                    cin.ignore();
                    cin >> new_ubicacionX;
                    cin.ignore();
                    c1.setUbicacionX(new_ubicacionX);
                    vg.insertar(c1, pos);
                }
                else if(op == 3){
                    float new_ubicacionY;
                    vg.eliminar(nombre);
                    cout << "Ingrese la nueva ubicacion ";
                    cin.ignore();
                    cin >> new_ubicacionY;
                    cin.ignore();
                    c1.setUbicacionY(new_ubicacionY);
                    vg.insertar(c1, pos);
                }
                else if(op == 4){
                    int new_puntuacion;
                    vg.eliminar(nombre);
                    cout << "Ingrese la nueva puntuacion ";
                    cin.ignore();
                    cin >> new_puntuacion;
                    cin.ignore();
                    c1.setPuntuacion(new_puntuacion);
                    vg.insertar(c1, pos);
                }
            }
        }
        else if(opc == "k" || opc == "K") {
            vg.respaldar();
        }
        else if(opc == "l" || opc == "L") {
            vg.recuperar();
        }
        else if(opc == "m" || opc == "M") {
            vg.mostrar();
        }
        else if(opc == "n" || opc == "N") {
            return 0;
        }

    }

    return 0;
}
