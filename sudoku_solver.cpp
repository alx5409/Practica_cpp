#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

/* Este archivo es la solución al ejercicio 2 de los ejercicios avanzado, se trata
de un solver de sudokus 3 x 3 x 3 usando backtracking.
*/

class Tablero {
    int dimension = 9;
    int casillas[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };  // Inicializa a 0 las casillas a 0
public:
    Tablero(int matriz_casillas[9][9]) {
        for (int i = 0; i < dimension; i++) {
            for( int j = 0; j < dimension; j++) {
                if (matriz_casillas[i][j] > 0 && matriz_casillas[i][j] < 10) {
                    casillas[i][j] = matriz_casillas[i][j];
                } else {
                    std::cout << "Numero fuera de rango, se guarda por defecto con 0.\n";
                }
            }
        }
    }

    void mostrar_tablero() {
        std::cout << "\n";
        for (int i = 0; i < dimension; i++) {
            // Línea horizontal entre bloques
            if (i % 3 == 0) {
                std::cout << "+===========+===========+===========+\n";
            } else {
                std::cout << "|---+---+---|---+---+---|---+---+---|\n";
            }
            for (int j = 0; j < dimension; j++) {
                if (j % 3 == 0) std::cout << "|";
                else std::cout << ":";
                std::cout << " " << casillas[i][j] << " ";
            }
            std::cout << "|\n";
        }
        std::cout << "+===========+===========+===========+\n";
    }

    bool esta_resuelto() {
        bool estado = false;
        // Comprueba que en todas las filas no hay elementos repetidos
        for (int i = 0; i < dimension; i++) {
            std::set<int> fila;
            for (int l = 0; l < dimension; l++) {
                fila.insert(casillas[i][l]);
            } 
            if (fila.size() < 9) {
                return estado;
            }
        }
        // Comprueba que en todas las columnas no hay elementos repetidos
        for (int j = 0; j < dimension; j++) {
            std::set<int> columna;
            for (int l = 0; l < dimension; l++) {
                columna.insert(casillas[l][j]);
            } 
            if (columna.size() < 9) {
                return estado;
            }
        }
        // Comprueba que en cada bloque no hay elementos repetidos
        /* vertices iniciales para cada bloque 3x3:
        [0, 0], [0, 3], [0, 6],
        [3, 0], [3, 3], [3, 6]
        [6, 0], [6, 3], [6, 6]
        */
        int vertices_iniciales[9][2] = {
            {0, 0}, {0, 3}, {0, 6},
            {3, 0}, {3, 3}, {3, 6},
            {6, 0}, {6, 3}, {6, 6}
        };   

        for (int k = 0; k < 9; k++) {
            int fila_inicio = vertices_iniciales[k][0];
            int columna_inicio = vertices_iniciales[k][1];
            std::set<int> bloque;
            for (int i = fila_inicio; i < fila_inicio + 3; i++) {
                for (int j = columna_inicio; j < columna_inicio + 3; j++) {
                    bloque.insert(casillas[i][j]);
                }
            }
            if (bloque.size() < 9) {
                return estado;
            }
        }
        estado = true;
        return estado;
    }

    std::pair<int, int> buscar_celdas_vacias() {
        for (int i = 0; i < dimension; i ++) {
            for (int j = 0; j < dimension; j++) {
                if (casillas[i][j] == 0) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};    // Si no encuentra casillas vacias
    }

    bool es_movimiento_valido(int fila, int columna, int valor) {

        // Comprobar límites
        if (fila < 0 || fila > 8 || columna < 0 || columna > 8) {
            std::cout << "La casilla que introduces no existe.\n";
            return false;
        }

        // Comprobar si la casilla ya está ocupada
        if (casillas[fila][columna] != 0) {
            std::cout << "Esa casilla ya está ocupada.\n";
            return false;
        }

        // Comprobar fila y columna
        for (int i = 0; i < dimension; i++) {
            if (casillas[fila][i] == valor) {
                std::cout << "El número ya está en la fila.\n";
                return false;
            }
            if (casillas[i][columna] == valor) {
                std::cout << "El número ya está en la columna.\n";
                return false;
            }
        }

        // Comprobar bloque 3x3
        int fila_inicio = (fila / 3) * 3;
        int columna_inicio = (columna / 3) * 3;
        for (int i = fila_inicio; i < fila_inicio + 3; i++) {
            for (int j = columna_inicio; j < columna_inicio + 3; j++) {
                if (casillas[i][j] == valor) {
                    std::cout << "El número ya está en el bloque.\n";
                    return false;
                }
            }
        }

        // Si pasa todas las comprobaciones, el movimiento es válido
        return true;
    }
    void hacer_movimiento(int fila, int columna, int valor) {
        bool movimiento_valido = es_movimiento_valido(fila, columna, valor);
        if (!movimiento_valido) {
            std::cout << "No es movimiento valido\n";
            return;
        }
        casillas[fila][columna] = valor;
    }
};

int main() {
    int solucion[9][9] = {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    };
    Tablero t = solucion;

    t.mostrar_tablero();
    return 0;
}