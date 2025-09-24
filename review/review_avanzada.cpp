#include <iostream>
#include <vector>
#include <math.h>
// ===================== EJERCICIO 1 =====================
// Calculadora de polinomios
// Implementa una clase Polinomio que permita sumar, restar y multiplicar polinomios de cualquier grado.
// Incluye métodos para evaluar el polinomio en un punto y derivarlo.

class Polinomio {
    int grado;
    std::vector<double> coef;

public:
    // Constructor por defecto
    Polinomio() : grado(0) {}

    // Constructor con grado y coeficientes
    Polinomio(int g, const std::vector<double>& c) : grado(g), coef(c) {}

    // Método para sumar polinomios
    Polinomio sumar_polinomio(const Polinomio& otro) const {
        int max_grado = std::max(grado, otro.grado);
        std::vector<double> resultado_coef(max_grado + 1, 0.0);

        for (int i = 0; i <= max_grado; ++i) {
            double coef1 = (i <= grado) ? coef[i] : 0.0;
            double coef2 = (i <= otro.grado) ? otro.coef[i] : 0.0;
            resultado_coef[i] = coef1 + coef2;
        }
        return Polinomio(max_grado, resultado_coef);
    }

    Polinomio restar_polinomio(const Polinomio& otro) const {
        int max_grado = std::max(grado, otro.grado);
        std::vector<double> resultado_coef(max_grado + 1, 0.0);

        for (int i = 0; i <= max_grado; ++i) {
            double coef1 = (i <= grado) ? coef[i] : 0.0;
            double coef2 = (i <= otro.grado) ? otro.coef[i] : 0.0;
            resultado_coef[i] = coef1 - coef2;
        }
        return Polinomio(max_grado, resultado_coef);
    }

    Polinomio multiplicar_polinomios( const Polinomio &p_2) {
        int grado_multiplicacion = grado + p_2.grado;
        std::vector<double> coef_multiplicacion;
        for (int i = 0; i < grado; i++) {
            for (int j = 0; j < p_2.grado; j++) {
                coef_multiplicacion[i + j] += coef[i] * p_2.coef[j]; 
            }
        }
        return Polinomio(grado_multiplicacion, coef_multiplicacion);
    }

    double evaluar_polinomio(double x) const {
        double sum = 0.0;
        for (int i = 0; i <= grado; i++) {
            sum += coef[i] * pow(x, i);
        }
        return sum;
    }
    //f(x) = c_i * x^i --> f'(x) = i * c_i * x^(i-1);
    void derivar_polinomio() {
        if (grado == 0) {
            coef = {0.0}; // derivada de una constante
            return;
        }
        for(int i = 0; i < grado; i++) {
            coef[i] = (i + 1)* coef[i + 1];
        }
        coef.pop_back();    // elimina el último coeficiente
        grado--;
    }
};

void main_ej1() {
    Polinomio p_1 = {2, {2.2, 3.3}};
    Polinomio p_2 = {3, {1.1, 3.3, 2.2}};

    std::cout << "El polinomio p_1 evaluado en 0 es " << p_1.evaluar_polinomio(0) << std::endl;
}

// ===================== EJERCICIO 2 =====================
// Sudoku Solver
// Implementa un solucionador de Sudoku usando backtracking para resolver cualquier tablero válido.

// int main_ej2() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 3 =====================
// Grafo dirigido con búsqueda BFS y DFS
// Implementa una clase Grafo con métodos para agregar nodos/aristas y realizar búsquedas BFS y DFS.

// int main_ej3() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 4 =====================
// Sistema de gestión de estudiantes
// Crea un sistema que permita registrar estudiantes, asignarles calificaciones y calcular el promedio general y por materia.
// Usa clases, herencia y manejo de archivos para persistencia.

// int main_ej4() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 5 =====================
// Juego de la vida de Conway
// Implementa el autómata celular "Juego de la vida" en una matriz NxN, mostrando la evolución en consola.

// int main_ej5() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 6 =====================
// Árbol binario de búsqueda (BST)
// Implementa un BST con inserción, búsqueda, recorrido inorden y eliminación de nodos.

// int main_ej6() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 7 =====================
// Algoritmo de Dijkstra
// Implementa el algoritmo de Dijkstra para encontrar el camino más corto en un grafo ponderado.

// int main_ej7() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 8 =====================
// Simulación de colas de banco
// Simula la atención de clientes en un banco usando colas y mide el tiempo promedio de espera.

// int main_ej8() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 9 =====================
// Compresor de texto simple (Run-Length Encoding)
// Implementa un compresor/descompresor de texto usando el algoritmo RLE.

// int main_ej9() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 10 =====================
// Analizador de expresiones matemáticas
// Implementa un parser que evalúe expresiones matemáticas con +, -, *, / y paréntesis usando pilas.

// int main_ej10() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 11 =====================
// Sistema de inventario con archivos binarios
// Crea un sistema de inventario que almacene productos en archivos binarios y permita búsquedas eficientes.

// int main_ej11() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 12 =====================
// Multithreading: suma de matrices grandes
// Divide la suma de dos matrices grandes entre varios hilos y mide el tiempo de ejecución.

// int main_ej12() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 13 =====================
// Serialización y deserialización de objetos
// Implementa funciones para guardar y cargar objetos complejos (con punteros y arreglos dinámicos) en archivos.

// int main_ej13() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 14 =====================
// Algoritmo de ordenamiento personalizado
// Implementa un algoritmo de ordenamiento (por ejemplo, quicksort) que acepte un comparador personalizado.

// int main_ej14() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 15 =====================
// Sistema de reservas de vuelos
// Crea un sistema que permita reservar, cancelar y consultar vuelos, usando listas enlazadas y archivos.

// int main_ej15() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 16 =====================
// Expresiones regulares básicas
// Implementa una función que valide correos electrónicos usando expresiones regulares (sin librerías externas).

// int main_ej16() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 17 =====================
// Simulación de memoria (malloc/free)
// Simula un sistema de gestión de memoria simple con malloc y free personalizados.

// int main_ej17() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 18 =====================
// Árbol AVL (auto-balanceado)
// Implementa un árbol AVL con inserción y recorrido inorden.

// int main_ej18() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 19 =====================
// Sistema de chat básico por consola
// Simula un chat entre varios usuarios usando hilos y colas de mensajes.

// int main_ej19() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 20 =====================
// Algoritmo de búsqueda A*
// Implementa el algoritmo A* para encontrar el camino más corto en una cuadrícula con obstáculos.

// int main_ej20() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 21 =====================
// Serialización JSON manual
// Serializa y deserializa objetos a un formato JSON simple sin librerías externas.

// int main_ej21() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 22 =====================
// Sistema de logs multihilo
// Implementa un sistema de logs seguro para múltiples hilos, escribiendo en un archivo de texto.

// int main_ej22() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 23 =====================
// Compilador de mini-lenguaje
// Implementa un intérprete para un mini-lenguaje con variables, sumas y bucles for.

// int main_ej23() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 24 =====================
// Algoritmo de cifrado César y descifrado
// Implementa funciones para cifrar y descifrar textos usando el cifrado César.

// int main_ej24() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 25 =====================
// Sistema de plugins con punteros a funciones
// Permite cargar y ejecutar funciones (plugins) en tiempo de ejecución usando punteros a funciones.

// int main_ej25() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 26 =====================
// Grafo no dirigido: detección de ciclos
// Implementa un algoritmo para detectar ciclos en un grafo no dirigido.

// int main_ej26() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 27 =====================
// Simulación de mercado de valores
// Simula la compra/venta de acciones con fluctuaciones aleatorias y reportes de ganancias/pérdidas.

// int main_ej27() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 28 =====================
// Algoritmo de Kruskal para árbol de expansión mínima
// Implementa el algoritmo de Kruskal para encontrar el árbol de expansión mínima en un grafo.

// int main_ej28() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 29 =====================
// Sistema de colisiones físicas 2D
// Simula colisiones elásticas entre partículas en 2D usando clases y vectores.

// int main_ej29() {
//     // Tu código aquí
// }

// ===================== EJERCICIO 30 =====================
// Máquina de estados finitos
// Implementa una máquina de estados finitos para validar cadenas binarias que terminen en "01".

// int main_ej30() {
//     // Tu código aquí
// }

// ===================== MAIN GENERAL =====================
// Puedes llamar a cualquier main_ejX desde aquí para probar cada ejercicio

int main() {
    main_ej1();
    return 0;
}