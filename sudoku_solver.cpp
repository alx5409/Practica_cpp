#include <iostream>
#include <vector>

// clase que define una estructura binaria, solo admite 1 y 0
class Binaria {
    int bin;
public:
    Binaria(int numero) {
        if (numero == 0 || numero == 1) {
        bin = numero;
        } else {
            throw std::invalid_argument("El número de ser 0 o 1");
        }
    }
    int valor() const { return bin; }
};

// clase que define un bloque binario para los bloques del sudoku
class Bloque_binario {
    Binaria *bloque_array;
public:
    Bloque_binario(Binaria *int_array) {
        bloque_array = int_array;
    }
    void muestra_bloque() {
        for (int i = 0; i < 4; i++) {
            printf("%d ", bloque_array[i]);
            if (((i + 1) % 2) == 0) {
                printf("\n");
            }
        }
    }
};

class Tablero {
    int dimension;
    std::vector<Bloque_binario> bloques;
public:
    Tablero(int dim) : dimension(dim), bloques(dim * dim) {
        
    }

    void print_sudoku() {
    }
};

void tablero_2_2_2(Tablero) {
    /*
    1 1 | 1 1 | 1 1
    1 1 | 1 1 | 1 1
    ---------------
    1 1 | 1 1 | 1 1
    1 1 | 1 1 | 1 1
    ---------------
    1 1 | 1 1 | 1 1
    1 1 | 1 1 | 1 1
    ---------------
    */
}

int main() {
    Binaria array[4] = {Binaria(1), Binaria(1), Binaria(1), Binaria(1)};
    Bloque_binario bloquecito(array);
    bloquecito.muestra_bloque();
    return 0;
}