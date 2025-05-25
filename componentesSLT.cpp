#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void menuVector(vector<int>& v) {
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
                if (pos >= 0 && pos < v.size()) {
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
                if (pos >= 0 && pos < v.size()) {
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

void menuPriorityQueue(priority_queue<int>& pq) {
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

int main() {
    vector<int> miVector;
    priority_queue<int> miQueue;
    int opcion;

    do {
        cout << "\n===== MENÚ PRINCIPAL =====\n";
        cout << "1. Trabajar con VECTOR\n";
        cout << "2. Trabajar con PRIORITY_QUEUE\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuVector(miVector);
                break;
            case 2:
                menuPriorityQueue(miQueue);
                break;
            case 3:
                cout << "Saliendo del programa. ¡Hasta luego!\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }

    } while (opcion != 3);

    return 0;
}
