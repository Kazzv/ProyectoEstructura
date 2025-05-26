#include <iostream>   
#include <deque>      
#include <set>        
using namespace std;

void menuDeque(deque<int>& dq) {
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


void menuSet(set<int>& s) {
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

/**
 * Función principal: muestra el menú principal y llama a los submenús.
 */
int main() {
    deque<int> miDeque;  
    set<int> miSet;      
    int opcion;

    do {
        cout << "\n===== MENÚ PRINCIPAL =====\n";
        cout << "1. Trabajar con DEQUE\n";
        cout << "2. Trabajar con SET\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuDeque(miDeque);
                break;
            case 2:
                menuSet(miSet);
                break;
            case 3:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 3);

    return 0;
}

