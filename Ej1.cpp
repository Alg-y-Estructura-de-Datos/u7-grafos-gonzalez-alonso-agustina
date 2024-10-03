/*Ejercicio N°1
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
    Grafo<string> redSocial;

    int opcion;
    string persona, amigo;

    do {
        cout << "\n--- Red Social ---\n";
        cout << "1. Agregar persona\n";
        cout << "2. Agregar amistad\n";
        cout << "3. Buscar persona\n";
        cout << "4. Eliminar persona\n";
        cout << "5. Mostrar red social\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre de la persona: ";
                cin >> persona;
                redSocial.agregarNodo(persona);
                break;
            case 2:
                cout << "Ingrese el nombre de la persona: ";
                cin >> persona;
                cout << "Ingrese el nombre del amigo: ";
                cin >> amigo;

                try{
                    redSocial.agregarArista(persona, amigo);
                    cout << "amistad agregada" << endl;
                }
                catch (int e){
                    cout << "rechazada" << endl;
                }

                break;
            case 3:
                cout << "Ingrese el nombre de la persona a buscar: ";
                cin >> persona;
                if (redSocial.buscarNodo(persona)) {
                    cout << "La persona " << persona << " está en la red social.\n";
                } else {
                    cout << "Persona no encontrada.\n";
                }
                break;
            case 4:
                cout << "Ingrese el nombre de la persona a eliminar: ";
                cin >> persona;
                redSocial.eliminarNodo(persona);
                break;
            case 5:
                cout << "Red social actual:\n";
                redSocial.imprimir();
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no válida.\n";
        }
    } while (opcion != 6);

    return 0;
}