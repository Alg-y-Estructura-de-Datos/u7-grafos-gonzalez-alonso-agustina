/*Ejercicio N°2
En una red social, los usuarios son representados como nodos, y las relaciones de amistad o conexión entre ellos son aristas. Este grafo es no dirigido, ya que, si dos usuarios son amigos, la relación es bidireccional. También puedes almacenar atributos adicionales, como el número de interacciones entre ellos, que podrían ser ponderaciones en las aristas.
Descripción del problema:
•	Cada usuario de la red social es un nodo en el grafo.
•	Las amistades entre usuarios son las aristas.
•	Puedes buscar si dos usuarios son amigos.
•	Puedes agregar nuevas amistades.
•	Eliminar amistades o usuarios de la red.
•	Mostrar los amigos de un usuario específico.

Operaciones:
1.	Insertar Usuario: Añadir un nodo al grafo representando a un nuevo usuario.
2.	Agregar Amistad: Añadir una arista entre dos nodos (usuarios) para representar una amistad.
3.	Eliminar Amistad: Quitar la conexión entre dos usuarios.
4.	Buscar Usuario: Ver si un usuario está en la red social.
5.	Imprimir la Red Social: Mostrar todos los usuarios y sus amigos (las conexiones en el grafo).
*/

#include <iostream>
#include "Grafos/Grafo.h"
using namespace std;


int main() {

    cout << "Ejercicio N° 2" << endl;

    Grafo<string>grafo;
    int opcion;
    string usuario, amigo;

    do {
        cout << "-----------MENU------------" << endl;
        cout << "1. Agregar usuario" << endl;
        cout << "2. Agregar amistad" << endl;
        cout << "3. Eliminar amistad" << endl;
        cout << "4. Buscar usuario" << endl;
        cout << "5. Imprimir grafo" << endl;
        cout << "6. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del usuario a agregar" << endl;
                cin >> usuario;
                grafo.agregarNodo(usuario);
                break;
            case 2:
                cout << "Ingrese el nombre del usuario y el nombre del usuario amigo" << endl;
                cin >> usuario >> amigo;
                grafo.agregarArista(usuario,amigo);
                break;
            case 3:
                cout << "Ingrese el nombre del usuario y amigo que desea eliminar" << endl;
                cin >> usuario >> amigo;
                grafo.eliminarArista(usuario,amigo);
                break;
            case 4:
                cout << "Ingrese el nombre del usuario que busca" << endl;
                cin >> usuario;
                if (grafo.buscarNodo(usuario)) {
                    cout << "La persona " << usuario << " está en la red social.\n";
                } else {
                    cout << "Persona no encontrada.\n";
                }
                break;
            case 5:
                grafo.imprimir();
                break;
            case 6:
                break;
        }

    }while (opcion !=6);
    return 0;
}
