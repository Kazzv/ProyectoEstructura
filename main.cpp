#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <limits> // Requerido para std::numeric_limits

// Función para mostrar el menu principal
void mostrarMenuPrincipal() {
    std::cout << "\n--- MENU PRINCIPAL ---" << std::endl;
    std::cout << "1. Trabajar con VECTOR" << std::endl;
    std::cout << "2. Trabajar con PRIORITY_QUEUE" << std::endl;
    std::cout << "3. Trabajar con DEQUE" << std::endl;
    std::cout << "4. Trabajar con SET" << std::endl;
    std::cout << "5. Trabajar con MAP" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Seleccione una opcion: ";
}

// Función para mostrar el menu para std::map operations
void mostrarMenuMap() {
    std::cout << "\n--- TRABAJAR CON MAP ---" << std::endl;
    std::cout << "1. Agregar elemento (clave-valor)" << std::endl;
    std::cout << "2. Eliminar elemento por clave" << std::endl;
    std::cout << "3. Mostrar elementos" << std::endl;
    std::cout << "0. Volver al menu principal" << std::endl;
    std::cout << "Seleccione una opcion: ";
}

// Función para manejar std::map operations
void trabajarConMap() {
    std::map<std::string, int> miMapa; // Por ejemplo usando string como clave e int como valor
    int opcionMap;
    std::string clave;
    int valor;

    do {
        mostrarMenuMap();
        // Validar la entrada de numeros enteros
        while (!(std::cin >> opcionMap)) {
            std::cout << "Entrada invalida. Por favor, ingrese un numero: ";
            std::cin.clear(); // Borrar indicadores de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar la entrada invalida
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consumir el carácter de nueva línea despues de la entrada

        switch (opcionMap) {
            case 1: // Agregar elemento
                std::cout << "Ingrese la clave (string): ";
                std::getline(std::cin, clave);
                std::cout << "Ingrese el valor (entero): ";
                while (!(std::cin >> valor)) {
                    std::cout << "Entrada invalida. Por favor, ingrese un numero entero para el valor: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consumir nueva línea
                miMapa[clave] = valor; // Añadir o actualizar el elemento
                std::cout << "Elemento agregado." << std::endl;
                break;
            case 2: // Eliminar elemento
                if (miMapa.empty()) {
                    std::cout << "El map esta vacio. No hay elementos para eliminar." << std::endl;
                    break;
                }
                std::cout << "Ingrese la clave del elemento a eliminar: ";
                std::getline(std::cin, clave);
                if (miMapa.erase(clave)) { // Erase devuelve el numero de elementos eliminados (0 o 1 para un map)
                    std::cout << "Elemento eliminado." << std::endl;
                } else {
                    std::cout << "Clave no encontrada." << std::endl;
                }
                break;
            case 3: // Mostrar elementos
                if (miMapa.empty()) {
                    std::cout << "El map esta vacio." << std::endl;
                } else {
                    std::cout << "Elementos en el map:" << std::endl;
                    for (const auto& par : miMapa) {
                        std::cout << "Clave: " << par.first << ", Valor: " << par.second << std::endl;
                    }
                }
                break;
            case 0: // Volver al menu principal
                std::cout << "Volviendo al menu principal..." << std::endl;
                break;
            default:
                std::cout << "opcion no valida. Intente de nuevo." << std::endl;
                break;
        }
    } while (opcionMap != 0);
}

// --- Funciones placeholders para otros componentes STL ---
void trabajarConVector() {
    std::cout << "Funcionalidad de VECTOR aun no implementada." << std::endl;
    // Aquí iría el submenu y lógica para std::vector
}

void trabajarConPriorityQueue() {
    std::cout << "Funcionalidad de PRIORITY_QUEUE aun no implementada." << std::endl;
    // Aquí iría el submenu y lógica para std::priority_queue
}

void trabajarConDeque() {
    std::cout << "Funcionalidad de DEQUE aun no implementada." << std::endl;
    // Aquí iría el submenu y lógica para std::deque
}

void trabajarConSet() {
    std::cout << "Funcionalidad de SET aun no implementada." << std::endl;
    // Aquí iría el submenu y lógica para std::set
}
// --- Final de las funciones placeholders ---

int main() {
    int opcionPrincipal;

    do {
        mostrarMenuPrincipal();
        // Validar la entrada de numeros enteros
        while (!(std::cin >> opcionPrincipal)) {
            std::cout << "Entrada invalida. Por favor, ingrese un numero: ";
            std::cin.clear(); // Borrar indicadores de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar la entrada invalida
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consumir el carácter de nueva línea despues de la entrada

        switch (opcionPrincipal) {
            case 1:
                trabajarConVector();
                break;
            case 2:
                trabajarConPriorityQueue();
                break;
            case 3:
                trabajarConDeque();
                break;
            case 4:
                trabajarConSet();
                break;
            case 5:
                trabajarConMap();
                break;
            case 0:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "opcion no valida. Intente de nuevo." << std::endl;
                break;
        }
    } while (opcionPrincipal != 0);

    return 0;
}