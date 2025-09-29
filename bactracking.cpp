// ===================== EJERCICIOS DE BACKTRACKING =====================
#include <iostream>
#include <set>
#include <vector>

// 1. Generar todas las combinaciones de un conjunto
//    Dado un conjunto de números, genera todas las combinaciones posibles de tamaño k.
void combinaciones_recursivas(std::vector<int> &elementos, std::vector<int> &actual, int size, int index) {
    // Muestra todos los subconjuntos de un tamaño fijo
    if (actual.size() == size) {
        for (int x : actual) {
            std::cout << x << " ";
        }
        std::cout << "\n";
        return;
    }
    // No quedan elementos
    if (index == elementos.size()) {
        return;
    }
    // Incluir elemento actual
    actual.push_back(elementos[index]);
    combinaciones_recursivas(elementos, actual, size, index + 1);

    // No incluir el elemento actual
    actual.pop_back();
    combinaciones_recursivas(elementos, actual, size, index + 1);
}

void subconjuntos(std::set<int> conjunto, int k) {
    std::vector<int> elementos(conjunto.begin(), conjunto.end());
    std::vector <int> actual;
    combinaciones_recursivas(elementos, actual, k, 0);
}

void main_1() {
    std::set<int> conjunto = {1, 2, 3, 4, 5, 6};
    subconjuntos(conjunto, 3);
}

// 2. Permutaciones de una cadena
//    Dada una cadena, genera todas las permutaciones posibles de sus caracteres.
void permutaciones_rec(std::string elementos, int inicio) {
    if (inicio == elementos.size()) {
        std::cout << elementos << "\n";
        return;
    }
    for(int i = inicio; i < elementos.size(); i++) {
        std::swap(elementos[inicio], elementos[i]);
        permutaciones_rec(elementos, inicio + 1);
        std::swap(elementos[inicio], elementos[i]); // backtracking
    }
}

void permutaciones_cadena(std::string cadena) {
    int inicio = 0;
    permutaciones_rec(cadena, inicio);
}

void main_2() {
    std::string cadena;
    std::cout << "Dame una cadena de caracteres.\n";
    std::cin >> cadena;
    std::cout << "\n\n";
    permutaciones_cadena(cadena);
}

// 3. Subconjuntos de un conjunto
//    Dado un conjunto de números, genera todos los subconjuntos posibles (el conjunto potencia).
void mostrar_subconjuntos(std::set<int> conjunto) {
    for (int i = 0; i < conjunto.size(); i++) {
        subconjuntos(conjunto, i);
    }
}
int main_3() {
    std::set<int> conjunto = {1, 2, 3, 4};
    mostrar_subconjuntos(conjunto);
}

// 4. N-Queens (N-Reinas)
//    Coloca N reinas en un tablero NxN de ajedrez de forma que no se ataquen entre sí.
class Tablero{
public:
    int dimension;
    std::vector<std::vector<int>> casillas;
    Tablero(int dim) {
        dimension = dim;
        for (int i = 0; i < dimension; i++) {
            for( int j = 0; j < dimension; j++) {
                casillas[i][j] = 0;
            }
        }
    }
};

void main_4() {
    Tablero tablero(8);
    
}

// 5. Sumas objetivo (Subset Sum)
//    Dado un conjunto de números y un objetivo, encuentra todos los subconjuntos cuya suma sea igual al objetivo.

// 6. Labyrinth/maze solver
//    Dado un laberinto representado como una matriz, encuentra un camino desde la entrada hasta la salida.

// 7. Palabras en un tablero (Word Search)
//    Dado un tablero de letras y una lista de palabras, encuentra si se puede formar una palabra moviéndose horizontal, vertical o diagonalmente.

// 8. Partición de un conjunto en k subconjuntos con suma igual
//    Dado un conjunto de números, determina si se puede dividir en k subconjuntos con la misma suma.

// 9. Colorear un grafo (Graph Coloring)
//    Dado un grafo y un número de colores, asigna un color a cada nodo de modo que no haya dos nodos adyacentes con el mismo color.

// 10. Resolver el problema del viajante (Traveling Salesman Problem, TSP) por fuerza bruta
//     Dada una lista de ciudades y las distancias entre ellas, encuentra el camino más corto que visita cada ciudad exactamente una vez y regresa al punto de inicio.

int main() {
    main_3();
    return 0;
}