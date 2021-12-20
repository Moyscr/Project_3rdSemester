#include "civilizacion.h"

Aldeano capturar()
{
    Aldeano a;
    string nombre;
    int edad;
    string genero;
    int salud;

    cout << endl;
    cout << "Nombre: ";
    fflush(stdin);
    getline(cin, nombre);
    a.setNombre(nombre);

    cout << "Edad: ";
    cin >> edad;
    a.setEdad(edad);

    cout << "Genero: ";
    fflush(stdin);
    getline(cin, genero);
    a.setGenero(genero);

    cout << "Salud: ";
    cin >> salud;
    a.setSalud(salud);
    cout << endl;

    return a;
}

void menuAldeano(Civilizacion &c)
{
    int op;

    while(true)
    {
        cout << endl;
        cout << "1) Agregar aldeano" << endl;
        cout << "2) Eliminar aldeano" << endl;                
        cout << "3) Calsificar aldeano" << endl;
        cout << "4) Buscar aldeano" << endl;
        cout << "5) Modificar aldeano" << endl;
        cout << "6) Mostrar Aldeanos" << endl;
        cout << "7) Salir" << endl;
        cout << endl;
        cin >> op;

        if(op == 1){
            cout << endl;
            cout << "1) Agregar aldeano al inicio" << endl;
            cout << "2) Agregar aldeano al final" << endl;
            cin >> op;

            if(op == 1){
                c.agregarInicio(capturar());
            }
            else if(op == 2){
                c.agregarFinal(capturar());
            }
        }
        else if(op == 2){
            cout << endl;
            cout << "1) Eliminar por nombre" << endl;
            cout << "2) Eliminar donde su salud sea menor a x" << endl;
            cout << "3) Eliminar donde edad sea mayor a 60" << endl;
            cin >> op;

            if(op == 1){
                string nombre;
                cout << "Ingrese el nombre del aldeano a eliminar: ";
                cin.ignore();
                getline(cin, nombre);

                c.eliminarNombre(nombre);
            }
            else if(op == 2){
                size_t x;
                cout << "Ingrese la salud a tomar como referencia para eliminar: ";
                cin >> x;

                c.eliminarSalud(x);
            }
            else if(op == 3){
                c.eliminarEdad();
            }
        }
        else if(op == 3){
            cout << endl;
            cout << "1) Ordenar por nombre" << endl;
            cout << "2) Ordenar por edad" << endl;
            cout << "3) Ordenar por salud" << endl;
            cin >> op;

            if(op == 1){
                c.ordenarNombre();
            }
            if(op == 2){
                c.ordenarEdad();
            }
            if(op == 3){
                c.ordenarSalud();
            }
        }
        else if(op == 4){
            string nombre;
            cout << "ingrese el nombre del aldeano a buscar: ";
            cin.ignore();
            getline(cin, nombre);

            Aldeano *ptr = c.buscarAldeano(nombre);

            if(ptr == nullptr){
                cout << "no encontrado" << endl;
            }
            else{
                cout << *ptr << endl;
            }
        }
        else if(op == 5){
            int op;
            string nombre;
            cout << "Ingrese el nombre del aldeano a modificar: ";
            cin.ignore();
            getline(cin, nombre);

            Aldeano *ptr = c.buscarAldeano(nombre);
            Aldeano a1 = *ptr;

            if(ptr == nullptr){
                cout << "no encontrado" << endl;
            }
            else{
                cout << left;
                cout << setw(12) << "Nombre";
                cout << setw(5) << "Edad";
                cout << setw(10) << "Genero";
                cout << setw(8) << "Salud";
                cout << endl;
                cout << *ptr << endl;
                cout << endl << "Que atributo quisiera modificar?" << endl;
                cout << "1. Nombre" << endl;
                cout << "2. Edad" << endl;
                cout << "3. Genero" << endl;
                cout << "4. Salud" << endl;
                cin >> op;

                if(op == 1){
                    string new_nombre;
                    cout << "Ingrese el nuevo nombre: ";
                    cin.ignore();
                    getline(cin, new_nombre);
                    a1.setNombre(new_nombre);
                    *ptr = a1;
                }
                else if(op == 2){
                    int new_edad;
                    cout << "Ingrese la nueva edad: ";
                    cin.ignore();
                    cin >> new_edad;
                    a1.setEdad(new_edad);
                    *ptr = a1;
                }
                else if(op == 3){
                    string new_genero;
                    cout << "Ingrese el nuevo genero ";
                    cin.ignore();
                    getline(cin, new_genero);
                    a1.setGenero(new_genero);
                    *ptr = a1;
                }
                else if(op == 4){
                    int new_salud;
                    cout << "Ingrese la nueva salud ";
                    cin.ignore();
                    cin >> new_salud;
                    a1.setSalud(new_salud);
                    *ptr = a1;
                }
            }
        }
        else if(op == 6){
            c.mostrarAldeanos();
        }
        else if(op == 7){
            cin.ignore();
            break;
        }
    }
}