#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <limits> // Requerido para std::numeric_limits
#include <algorithm> // Requerido para std::sort

using namespace std;

// Función para mostrar el menu principal
void mostrarMenuPrincipal() {
    cout << "\n--- MENU PRINCIPAL ---" << endl;
    cout << "1. Trabajar con VECTOR" << endl;
    cout << "2. Trabajar con PRIORITY_QUEUE" << endl;
    cout << "3. Trabajar con DEQUE" << endl;
    cout << "4. Trabajar con SET" << endl;
    cout << "5. Trabajar con MAP" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

// Función para mostrar el menu para std::map operations
void mostrarMenuMap() {
    cout << "\n--- TRABAJAR CON MAP ---" << endl;
    cout << "1. Agregar elemento (clave-valor)" << endl;
    cout << "2. Eliminar elemento por clave" << endl;
    cout << "3. Mostrar elementos" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "Seleccione una opcion: ";
}

// Función para manejar std::map operations
void trabajarConMap() {
    map<string, int> miMapa; // Por ejemplo usando string como clave e int como valor
    int opcionMap;
    string clave;
    int valor;

    do {
        mostrarMenuMap();
        // Validar la entrada de numeros enteros
        while (!(cin >> opcionMap)) {
            cout << "Entrada invalida. Por favor, ingrese un numero: ";
            cin.clear(); // Borrar indicadores de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada invalida
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consumir el caracter de nueva linea despues de la entrada

        switch (opcionMap) {
            case 1: // Agregar elemento
                cout << "Ingrese la clave (string): ";
                getline(cin, clave);
                cout << "Ingrese el valor (entero): ";
                while (!(cin >> valor)) {
                    cout << "Entrada invalida. Por favor, ingrese un numero entero para el valor: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consumir nueva linea
                miMapa[clave] = valor; // Añadir o actualizar el elemento
                cout << "Elemento agregado." << endl;
                break;
            case 2: // Eliminar elemento
                if (miMapa.empty()) {
                    cout << "El map esta vacio. No hay elementos para eliminar." << endl;
                } else {
                    cout << "Ingrese la clave del elemento a eliminar: ";
                    getline(cin, clave);
                    if (miMapa.erase(clave)) { // Erase devuelve el numero de elementos eliminados
                        cout << "Elemento eliminado." << endl;
                    } else {
                        cout << "Clave no encontrada." << endl;
                    }
                }
                break;
            case 3: // Mostrar elementos
                if (miMapa.empty()) {
                    cout << "El map esta vacio." << endl;
                } else {
                    cout << "Elementos en el map:" << endl;
                    for (const auto& par : miMapa) {
                        cout << "Clave: " << par.first << ", Valor: " << par.second << endl;
                    }
                }
                break;
            case 0: // Volver al menu principal
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcionMap != 0);
}

void trabajarConVector(vector<int>& v) {
    int opcion;
    do {
        cout << "\n--- SUBMENÚ VECTOR ---\n";
        cout << "1. Agregar número\n";
        cout << "2. Eliminar número (por posición)\n";
        cout << "3. Modificar número (por posición)\n";
        cout << "4. Mostrar contenido\n";
        cout << "5. Ordenar vector\n";
        cout << "6. Regresar al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int num;
                cout << "Ingrese el número a agregar: ";
                cin >> num;
                v.push_back(num);
                cout << "Número agregado.\n";
                break;
            }
            case 2: {
                int pos;
                cout << "Ingrese la posición a eliminar (0 a " << v.size()-1 << "): ";
                cin >> pos;
                if (pos >= 0 && pos < static_cast<int>(v.size())) {
                    v.erase(v.begin() + pos);
                    cout << "Elemento eliminado.\n";
                } else {
                    cout << "Posición inválida.\n";
                }
                break;
            }
            case 3: {
                int pos, nuevo;
                cout << "Ingrese la posición a modificar (0 a " << v.size()-1 << "): ";
                cin >> pos;
                if (pos >= 0 && pos < static_cast<int>(v.size())) {
                    cout << "Ingrese el nuevo valor: ";
                    cin >> nuevo;
                    v[pos] = nuevo;
                    cout << "Valor modificado.\n";
                } else {
                    cout << "Posición inválida.\n";
                }
                break;
            }
            case 4: {
                cout << "Contenido del vector: ";
                for (int x : v) cout << x << " ";
                cout << "\n";
                break;
            }
            case 5: {
                sort(v.begin(), v.end());
                cout << "Vector ordenado.\n";
                break;
            }
            case 6:
                cout << "Regresando al menú principal...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 6);
}

void trabajarConPriorityQueue(priority_queue<int>& pq) {
    int opcion;
    do {
        cout << "\n--- SUBMENÚ PRIORITY_QUEUE ---\n";
        cout << "1. Agregar número\n";
        cout << "2. Mostrar número con mayor prioridad\n";
        cout << "3. Eliminar número con mayor prioridad\n";
        cout << "4. Mostrar tamaño de la cola\n";
        cout << "5. Vaciar la cola\n";
        cout << "6. Regresar al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int num;
                cout << "Ingrese el número a agregar: ";
                cin >> num;
                pq.push(num);
                cout << "Número agregado.\n";
                break;
            }
            case 2:
                if (!pq.empty()) {
                    cout << "Mayor prioridad: " << pq.top() << "\n";
                } else {
                    cout << "La cola está vacía.\n";
                }
                break;
            case 3:
                if (!pq.empty()) {
                    pq.pop();
                    cout << "Elemento con mayor prioridad eliminado.\n";
                } else {
                    cout << "La cola está vacía.\n";
                }
                break;
            case 4:
                cout << "Tamaño de la cola: " << pq.size() << "\n";
                break;
            case 5:
                while (!pq.empty()) pq.pop();
                cout << "Cola vaciada.\n";
                break;
            case 6:
                cout << "Regresando al menú principal...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 6);
}

void trabajarConDeque(deque<int>& dq) {
    int opcion;
    do {
        cout << "\n--- SUBMENÚ DEQUE ---\n";
        cout << "1. Agregar elemento al inicio\n";
        cout << "2. Agregar elemento al final\n";
        cout << "3. Eliminar elemento del inicio\n";
        cout << "4. Eliminar elemento del final\n";
        cout << "5. Mostrar contenido\n";
        cout << "6. Regresar al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int val;
                cout << "Ingrese el elemento a agregar al inicio: ";
                cin >> val;
                dq.push_front(val);  // Inserta al frente
                cout << "Elemento agregado al inicio.\n";
                break;
            }
            case 2: {
                int val;
                cout << "Ingrese el elemento a agregar al final: ";
                cin >> val;
                dq.push_back(val);   // Inserta al final
                cout << "Elemento agregado al final.\n";
                break;
            }
            case 3:
                if (!dq.empty()) {
                    dq.pop_front();   // Elimina el primer elemento
                    cout << "Elemento eliminado del inicio.\n";
                } else {
                    cout << "El deque está vacío.\n";
                }
                break;
            case 4:
                if (!dq.empty()) {
                    dq.pop_back();    // Elimina el último elemento
                    cout << "Elemento eliminado del final.\n";
                } else {
                    cout << "El deque está vacío.\n";
                }
                break;
            case 5:
                if (dq.empty()) {
                    cout << "El deque está vacío.\n";
                } else {
                    cout << "Contenido del deque: ";
                    for (int x : dq) cout << x << " ";  // Recorre e imprime
                    cout << "\n";
                }
                break;
            case 6:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 6);
}

void trabajarConSet(set<int>& s) {
    int opcion;
    do {
        cout << "\n--- SUBMENÚ SET ---\n";
        cout << "1. Agregar elemento\n";
        cout << "2. Eliminar elemento\n";
        cout << "3. Mostrar contenido\n";
        cout << "4. Buscar elemento\n";
        cout << "5. Regresar al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int val;
                cout << "Ingrese el elemento a agregar: ";
                cin >> val;
                auto res = s.insert(val);  // Inserta y retorna 
                cout << (res.second ? "Elemento agregado.\n" : "El elemento ya existe.\n");
                break;
            }
            case 2: {
                int val;
                cout << "Ingrese el elemento a eliminar: ";
                cin >> val;
                size_t cnt = s.erase(val);  // Elimina valor si existe
                cout << (cnt ? "Elemento eliminado.\n" : "El elemento no se encontró.\n");
                break;
            }
            case 3:
                if (s.empty()) {
                    cout << "El set está vacío.\n";
                } else {
                    cout << "Contenido del set: ";
                    for (int x : s) cout << x << " ";  // Imprime todos los valores en orden
                    cout << "\n";
                }
                break;
            case 4: {
                int val;
                cout << "Ingrese el elemento a buscar: ";
                cin >> val;
                bool found = (s.find(val) != s.end());
                cout << (found ? "Elemento encontrado.\n" : "Elemento no encontrado.\n");
                break;
            }
            case 5:
                cout << "Regresando al menú principal...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 5);
}

int main() {
    int opcionPrincipal;
    vector<int> v;
    priority_queue<int> pq;
    deque<int> dq;
    set<int> s;

    do {
        mostrarMenuPrincipal();
        // Validar la entrada de numeros enteros
        while (!(cin >> opcionPrincipal)) {
            cout << "Entrada invalida. Por favor, ingrese un numero: ";
            cin.clear(); // Borrar indicadores de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada invalida
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consumir el caracter de nueva linea despues de la entrada

        switch (opcionPrincipal) {
            case 1:
                trabajarConVector(v);
                break;
            case 2:
                trabajarConPriorityQueue(pq);
                break;
            case 3:
                trabajarConDeque(dq);
                break;
            case 4:
                trabajarConSet(s);
                break;
            case 5:
                trabajarConMap();
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcionPrincipal != 0);

    return 0;
}
