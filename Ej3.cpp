/*Ejercicio N°3
En una ciudad, se está implementando un sistema de gestión de rutas de transporte entre distintas estaciones.
 Cada estación se representa como un nodo, y las rutas directas entre estaciones se representan como aristas.
 Tu tarea es diseñar este sistema de rutas utilizando grafos, donde los ciudadanos puedan interactuar con el
 sistema para realizar varias operaciones.

1.	Agregar estaciones:
o	El sistema debe permitir agregar nuevas estaciones al mapa. Cada estación tiene un nombre único.
2.	Conexión de rutas entre estaciones:
o	Las estaciones pueden estar conectadas mediante rutas directas. El sistema debe permitir agregar una conexión entre dos estaciones,
 indicando que existe una ruta entre ellas.
3.	Eliminar estaciones:
o	Si una estación deja de funcionar, debe ser posible eliminarla del sistema. Al eliminar una estación,
 también deben eliminarse todas las rutas que conectan a dicha estación.
4.	Eliminar rutas:
o	En caso de que una ruta deje de ser operativa entre dos estaciones, el sistema debe poder eliminar esa conexión sin afectar al resto de las estaciones.
5.	Consulta de conectividad:
o	Los ciudadanos podrán consultar si existe una ruta directa entre dos estaciones específicas. El sistema debe devolver si esas estaciones están conectadas por una ruta.
6.	Verificar si una estación existe:
o	El sistema debe proporcionar una función para verificar si una estación específica existe en el mapa.
7.	Visualización de estaciones conectadas:
o	Los usuarios del sistema podrán consultar qué otras estaciones están directamente conectadas a una estación en particular.
8.	Imprimir el mapa completo:
o	Finalmente, el sistema debe poder imprimir un listado de todas las estaciones y sus conexiones directas, mostrando el estado actual de todas las rutas en la ciudad.
*/

#include <iostream>
#include "Grafos/Grafo.h"
using namespace std;

int main() {

    cout << "Ejercicio N° 3" << endl;
    Grafo<string>grafo;
    int opcion;
    string estacion1, estacion2;

    do {
        cout << "-----------MENU------------" << endl;
        cout << "1. Agregar estaciones" << endl;
        cout << "2. Agregar conexion de rutas entre estaciones" << endl;
        cout << "3. Eliminar estacion" << endl;
        cout << "4. Eliminar ruta" << endl;
        cout << "5. Consulta de conectividad" << endl;
        cout << "6. Verificar ruta" << endl;
        cout << "7. Imprimir mapa" << endl;
        cout << "8. Salir" << endl;
        cin >> opcion;

        cin.clear();
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Ingrese nombre de la estacion a agregar" << endl;
                getline(cin,estacion1 );
                grafo.agregarNodo(estacion1);
                break;
            case 2:
                cout << "Ingrese esatcion 1" << endl;
                getline(cin,estacion1 );
                cout << "ingrese la estacion 2" << endl;
                getline(cin,estacion2 );
                grafo.agregarArista(estacion1, estacion2);
                break;
            case 3:
                cout << "Ingrese el nombre de la estacion a eliminar" << endl;
                getline(cin,estacion1 );
                grafo.eliminarNodo(estacion1);
                break;
            case 4:
                cout << "Ingrese la ruta a eliminar  (origen, destino)" << endl;
                getline(cin,estacion1 );
                getline(cin,estacion2 );
                grafo.eliminarArista(estacion1,estacion2);
                break;
            case 5:
                cout << "Ingrese la estacion de origen: ";
                getline(cin, estacion1);
                cout << "Ingrese la estacion de destino: ";
                getline(cin, estacion2);
                if (grafo.estanConectados(estacion1, estacion2)) {
                    cout << "Las estaciones estan conectadas.\n";
                } else {
                    cout << "Las estaciones NO estan conectadas.\n";
                }
                break;
            case 6:
                cout << "Ingrese el nombre de la ruta a verificar" << endl;
                getline(cin,estacion1 );

                if (grafo.buscarNodo(estacion1)){
                    cout << "la estacion " << estacion1 << " si existe" << endl;
                }
                else {
                    cout << "la estacion " << estacion1 << " no existe" << endl;
                }
                break;
            case 7:
                grafo.imprimir();
                break;
            case 8:
                break;
        }

    }while (opcion!=8);



    return 0;
}
