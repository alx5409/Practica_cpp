/*
Este archivo es la solución general al ejercicio 2 de la review avanzada, es un solver para un sudoku genérico construido con bloques de dimensión n, en el caso 
del sudoku clasico este n sería 3.
*/
#include <iostream>
#include <vector>
#include <utility>
#include <chrono>

class Sudoku {
    int block_size;            // n
    int dim;                   // n * n
    std::vector<std::vector<int>> grid;

public:
    // Construye tablero a partir del tamaño de bloque (n) y una matriz inicial.
    // La matriz debe tener tamaño n*n x n*n y usar 0 para celdas vacías.
    Sudoku(int n, const std::vector<std::vector<int>>& inicial)
        : block_size(n), dim(n * n), grid(inicial)
    {
        // Si la matriz no tiene el tamaño correcto, inicializa vacía.
        if ((int)grid.size() != dim) {
            grid.assign(dim, std::vector<int>(dim, 0));
        } else {
            for (auto &row : grid) {
                if ((int)row.size() != dim) {
                    row.assign(dim, 0);
                }
            }
        }
    }

    // Mostrar tablero en consola
    void mostrar() const {
        const int B = block_size;
        const int N = dim;
        for (int i = 0; i < N; ++i) {
            if (i % B == 0) {
                std::cout << "+";
                for (int bi = 0; bi < B; ++bi) {
                    for (int k = 0; k < 2*B+1; ++k) std::cout << "-";
                    std::cout << "+";
                }
                std::cout << "\n";
            }
            for (int j = 0; j < N; ++j) {
                if (j % B == 0) std::cout << "| ";
                int v = grid[i][j];
                if (v == 0) std::cout << ". ";
                else std::cout << v << ' ';
            }
            std::cout << "|\n";
        }
        std::cout << "+";
        for (int bi = 0; bi < block_size; ++bi) {
            for (int k = 0; k < 2*block_size+1; ++k) std::cout << "-";
            std::cout << "+";
        }
        std::cout << "\n";
    }

    // Busca la siguiente celda vacía; devuelve {-1,-1} si no hay.
    std::pair<int,int> siguiente_vacia() const {
        for (int i = 0; i < dim; ++i)
            for (int j = 0; j < dim; ++j)
                if (grid[i][j] == 0) return {i, j};
        return {-1, -1};
    }

    // Comprueba si colocar valor en (fila,col) es válido (fila, columna y bloque).
    bool valido(int fila, int col, int valor) const {
        if (valor <= 0 || valor > dim) return false;
        // fila
        for (int j = 0; j < dim; ++j)
            if (grid[fila][j] == valor) return false;
        // columna
        for (int i = 0; i < dim; ++i)
            if (grid[i][col] == valor) return false;
        // bloque
        int bi = (fila / block_size) * block_size;
        int bj = (col  / block_size) * block_size;
        for (int i = bi; i < bi + block_size; ++i)
            for (int j = bj; j < bj + block_size; ++j)
                if (grid[i][j] == valor) return false;
        return true;
    }

    // Resolver por backtracking. Devuelve true si encuentra solución.
    bool resolver() {
        auto [fila, col] = siguiente_vacia();
        if (fila == -1) return true; // sin vacías -> resuelto

        for (int val = 1; val <= dim; ++val) {
            if (valido(fila, col, val)) {
                grid[fila][col] = val;
                if (resolver()) return true;
                grid[fila][col] = 0; // backtrack
            }
        }
        return false;
    }

    // Obtener tablero resultante (útil para tests)
    const std::vector<std::vector<int>>& obtener_grid() const { return grid; }
};

// Estas funciones son para crear los ejemplos de los sudokus para resolver
std::vector<std::vector<int>> ejemplo_n1() {
    return { {0} };
}

std::vector<std::vector<int>> ejemplo_n2() {
    return {
        {1,0,3,4},
        {0,4,1,0},
        {2,0,4,3},
        {4,3,0,1}
    };
}

std::vector<std::vector<int>> ejemplo_n3() {
    return {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,3, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };
}

// Ejecuta el solver sobre un puzzle, mide tiempo y muestra resultados.
void resolver_y_mostrar(int n, const std::vector<std::vector<int>>& puzzle, const std::string& nombre) {
    Sudoku s(n, puzzle);
    std::cout << "\n--- " << nombre << " (n=" << n << ", dim=" << n*n << "x" << n*n << ") ---\n";
    std::cout << "Inicial:\n";
    s.mostrar();

    auto inicio = std::chrono::high_resolution_clock::now();
    bool ok = s.resolver();
    auto fin = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

    if (ok) {
        std::cout << "\nSolución encontrada (" << ms << " ms):\n";
        s.mostrar();
    } else {
        std::cout << "\nNo se encontró solución (" << ms << " ms)\n";
    }
}

// Ejecuta varios ejemplos
void ejecutar_ejemplos() {
    resolver_y_mostrar(1, ejemplo_n1(), "Ejemplo n=1");
    resolver_y_mostrar(2, ejemplo_n2(), "Ejemplo n=2");
    resolver_y_mostrar(3, ejemplo_n3(), "Ejemplo n=3");
}

int main() {
    ejecutar_ejemplos();
    return 0;
}