#include "civilizacion.h"
#include "barco.h"

void menuBarco(Civilizacion &c)
{
    int opc;

    while(true)
    {
        cout << endl;
        cout << "1) Agregar Barco" << endl;
        cout << "2) Mostrar todos los barcos" << endl;
        cout << "3) Buscar barco" << endl;
        cout << "4) Eliminar barco" << endl;
        cout << "5) Salir" << endl;
        cout << endl;
        cin >> opc;

        if(opc == 1){
            string id = "barco";
            float combustible = 50.0;
            float velocidad = 0.0;
            float armadura = 100.0;

            Barco *b = new Barco();

            cout << "Id: ";
            cin.ignore();
            getline(cin, id);
            b->setId(id);

            cout << "Combustible (0 - 100.0): ";
            cin >> combustible;
            if(combustible <= 100){
                b->setCombustible(combustible);
            } else {
                cout << "ingrese un valor valido (0 - 100)" << endl;
                cin >> combustible;
                b->setCombustible(combustible);
            }

            b->setVelocidad(velocidad);
            b->setArmadura(armadura);

            c.agregarBarco(*b);
        }
        else if(opc == 2){
            c.mostrarBarcos();
        }
        else if(opc == 3){
            string id;
            cout << "Ingrese el Id del barco a buscar: ";
            cin.ignore();
            getline(cin, id);

            Barco *ptr = c.buscarBarco(id);

            if(ptr == nullptr){
                cout << "No encontrado" << endl;
            } 
            else{
                cout << *ptr << endl;
                Barco &barco = *ptr;
                while(true){
                int op;
                cout << endl;
                cout << "1) Agregar guerrero" << endl;
                cout << "2) Eliminar Guerreo" << endl;
                cout << "3) Mostrar ultimo guerrero" << endl;
                cout << "4) Mostrar todos los guerreros" << endl;
                cout << "5) Salir" << endl;
                cin >> op;

                if(op == 1){
                    Guerrero g;
                    string id;
                    int salud;
                    float fuerza;
                    float escudo;
                    string tipo;

                    cout << "Id: ";
                    cin.ignore();
                    getline(cin, id);
                    g.setId(id);

                    cout << "Salud (0 - 100): ";
                    cin >> salud;
                    if(salud <= 100.0){
                        g.setSalud(salud);
                    } else {
                        cout << "Ingrese un valor valido (0 - 100)" << endl;
                        cin >> salud;
                        g.setSalud(salud);
                    } 

                    cout << "Fuerza (0.0 - 60.0): ";
                    cin >> fuerza;
                    if(fuerza <= 60.0){
                        g.setFuerza(fuerza);
                    } else {
                        cout << "Ingrese un valor valido (0 - 60)" << endl;
                        cin >> fuerza;
                        g.setFuerza(fuerza);
                    }

                    cout << "Escudo (0.0 - 30.0): ";
                    cin >> escudo;
                    if(escudo <= 30.0){
                        g.setEscudo(escudo);
                    } else {
                        cout << "Ingrese un valor valido (0 - 30)" << endl;
                        cin >> escudo;
                        g.setEscudo(escudo);
                    }

                    cout << "Tipo (Elegir entre los siguientes): " << endl;
                    cout << "Luchador" << endl;
                    cout << "Lancero" << endl;
                    cout << "Arquero" << endl;
                    cout << "Mago" << endl << endl;
                    cin.ignore();
                    getline(cin, tipo);
                    if(tipo == "Luchador" || tipo == "luchador" || tipo == "Lancero" || tipo == "lancero"
                    || tipo == "Arquero" || tipo == "arquero" || tipo == "Mago" || tipo == "mago"){
                        g.setTipo(tipo);
                    } else {
                        cout << "Ingrese un tipo valido (Luchador, Lancero, Arquero, Mago)" << endl;
                        cin.ignore();
                        getline(cin, tipo);
                        g.setTipo(tipo);
                    }

                    barco.agregarGuerrero(g);
                }
                else if(op == 2){
                    barco.eliminarGuerrero();
                }
                else if(op == 3){
                    barco.tope();
                }
                else if(op == 4){
                    stack<Guerrero> copia = barco.crearCopia();
                    cout << left;
                    cout << setw(8) << "Id";
                    cout << setw(8) << "Salud";
                    cout << setw(8) << "Fuerza";
                    cout << setw(8) << "Escudo";
                    cout << setw(10) << "Tipo";
                    cout << endl;
                    while(!copia.empty()){
                        if(copia.empty()){
                            cout << "No esxistenn guerreros" << endl;
                        } else {
                            auto const &e = copia.top();
                            cout << e << endl;

                            copia.pop();
                        }
                    }
                }
                else if(op == 5){
                    break;
                }
            }
            }

        }
        else if(opc == 4){
            int op;
            cout << endl;
            cout << "1) Eliminar por Id" << endl;
            cout << "2) Eliminar donde combustible sea menor a x" << endl;
            cin >> op;

            if(op == 1){
                string id;
                cout << "Ingrese el id del barco a eliminar: ";
                cin.ignore();
                getline(cin, id);

                c.eliminarBarco(id);
            }
            else if(op == 2){
                float x;
                cout << "Ingrese la cantidad de combustible para tomar de referencia: ";
                cin >> x;

                c.eliminarCombustible(x);
            }
        }
        else if(opc == 5){
            cin.ignore();
            break;
        }
    }
}