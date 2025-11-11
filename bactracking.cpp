// ===================== EJERCICIOS DE BACKTRACKING =====================
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <random>
#include <string>
#include <algorithm>

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
    for (int i = 0; i <= conjunto.size(); i++) {
        subconjuntos(conjunto, i);
    }
}
void main_3() {
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
        casillas = std::vector<std::vector<int>>(dim, std::vector<int>(dim, 0));    // inicializa todas las casillas a 0
    }
    bool es_valido(int fila, int columna) {
        /*
        Comprueba si es valido poner la dama en esa posicion: que no haya dama en la misma columna,
        ni en las diagonales.
        */
       // Comprueba que los números están dentro del tablero
       if (fila < 0 || fila >= dimension || columna < 0 || columna >= dimension){
        return false;
       }
       // Comprueba que la fila está libre
        for (int i = 0; i < dimension; i++) {
            if (casillas[fila][i] == 1) {
                return false;
            }
        }
        // Comprueba que la columna está libre
        for (int i = 0; i < dimension; i++) {
            if (casillas[i][columna] == 1) {
                return false;
            }
        }
        // Comprueba la diagonal principal ↖ (arriba a la izquierda)
        for (int i = fila - 1, j = columna - 1; i >= 0 && j >= 0; i--, j--) {
            if (casillas[i][j] == 1) {
                return false;
            }
        }
        // Comprueba la diagonal secundaria ↗ (arriba a la derecha)
        for (int i = fila - 1, j = columna + 1; i >= 0 && j < dimension; i--, j++) {
            if (casillas[i][j] == 1) {
                return false;
            }
        }
        // Comprueba la diagonal principal ↘ (abajo a la derecha)
        for (int i = fila + 1, j = columna + 1; i < dimension && j < dimension; i++, j++) {
            if (casillas[i][j] == 1) {
                return false;
            }
        }
        // Comprueba la diagonal secundaria ↙ (abajo a la izquierda)
        for (int i = fila + 1, j = columna - 1; i < dimension && j >= 0; i++, j--) {
            if (casillas[i][j] == 1) {
                return false;
            }
        }
        return true;
    }

    void colocar_reina(int fila, int columna) {
        if (!(es_valido(fila, columna))){
            printf("Movimiento no valido.\n");
            return;
        }
        casillas[fila][columna] = 1;
    }

    int contar_puntuacion_tablero() {
        int suma = 0;
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                if (casillas[i][j] == 1) {
                    suma++;
                    continue;
                }
            }
        }
        return suma;
    }

    void revolver_N_damas() {
        int puntuacion;
        for(int fila = 0; fila < dimension; fila++) {
            for(int columna = 0; columna < dimension; columna++) {
                if (!(es_valido(fila, columna))) {
                    continue;
                }
                colocar_reina(fila, columna);
            }
        }
    }

    void mostrar_tablero() {
        int puntuacion;
        for (int fila = 0; fila < dimension; fila ++) {
            for (int columna = 0; columna < dimension; columna++) {
                std::cout << casillas[fila][columna] << " ";
            }
            std::cout << std::endl;
        }
        puntuacion = contar_puntuacion_tablero();
        std::cout << "\n\nLa puntuacion es : " << puntuacion << std::endl;
    }
};

void main_4() {
    int dimension = 8;
    Tablero tablero(dimension);
    tablero.revolver_N_damas();
    tablero.mostrar_tablero();
}

// 5. Sumas objetivo (Subset Sum)
//    Dado un conjunto de números y un objetivo, encuentra todos los subconjuntos cuya suma sea igual al objetivo.
void hallar_subconjunto_suma(std::set<int> subconjunto, int suma) {
}

void mostrar_contenido_vector(std::vector<int> int_vector) {
    std::cout << "[ ";
    for (int i = 0; i < int_vector.size(); i++) {
        std::cout << int_vector[i] << " ";
    }
    std::cout << "]\n";
}
void mostrar_todos_subconjuntos_por_suma(std::set<int> conjunto, int suma) {
    // std::map<int, std::vector<int>> diccionario_sumas;
    std::vector<int> posibles_elementos;
    for (int elementos : conjunto) {
        posibles_elementos.push_back(elementos);
    }
    mostrar_contenido_vector(posibles_elementos);
}

void main_5() {
    std::set<int> conjunto_enteros = {4, 3, 6, 2, 1};
    int suma_objetivo = 10;
    mostrar_todos_subconjuntos_por_suma(conjunto_enteros, suma_objetivo);
}
// 6. Labyrinth/maze solver
//    Dado un laberinto representado como una matriz, encuentra un camino desde la entrada hasta la salida.
std::vector<std::vector<bool>> hacer_laberinto(int filas = 10, int columnas = 10) {
    std::vector<std::vector<bool>> laberinto(filas, std::vector<bool>(columnas, false));     // Inicializa la matriz booleana a todo falso

    // Camino predefinido: escalera diagonal (abajo, derecha, abajo, derecha...)
    int x = 0, y = 0;
    laberinto[x][y] = true;
    while (x < filas - 1 && y < columnas - 1) {
        x++; laberinto[x][y] = true; // abajo
        y++; laberinto[x][y] = true; // derecha
    }
    // Si quedan filas o columnas, termina el camino hasta el borde
    while (x < filas - 1) { x++; laberinto[x][y] = true; }
    while (y < columnas - 1) { y++; laberinto[x][y] = true; }
    
    // Rellena el resto aleatoriamente (sin bloquear el camino definido)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(0.6); // probabilidad de ser camino

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (!laberinto[i][j]) { // No sobrescribir el camino
                laberinto[i][j] = d(gen);
            }
        }
    }
    return laberinto;
}

void mostrar_laberinto(const std::vector<std::vector<bool>> &laberinto) {
    int filas = laberinto.size();
    int columnas = laberinto[0].size();

    // Imprime borde superior
    std::cout << "╔";
    for (int j = 0; j < columnas; ++j) std::cout << "══";
    std::cout << "╗\n";

    // Imprime filas con bordes laterales
    for (int i = 0; i < filas; ++i) {
        std::cout << "║";
        for (int j = 0; j < columnas; ++j) {
            std::cout << (laberinto[i][j] ? "  " : "██");
        }
        std::cout << "║\n";
    }

    // Imprime borde inferior
    std::cout << "╚";
    for (int j = 0; j < columnas; ++j) std::cout << "══";
    std::cout << "╝\n";
}

void mostrar_camino(const std::vector<std::vector<bool>> &laberinto, const std::vector<std::vector<bool>> &camino) {
    int filas = laberinto.size();
    int columnas = laberinto[0].size();

    std::cout << "╔";
    for (int j = 0; j < columnas; ++j) std::cout << "══";
    std::cout << "╗\n";

    for (int i = 0; i < filas; ++i) {
        std::cout << "║";
        for (int j = 0; j < columnas; ++j) {
            if (camino[i][j])
                std::cout << " *";
            else
                std::cout << (laberinto[i][j] ? "  " : "██");
        }
        std::cout << "║\n";
    }

    std::cout << "╚";
    for (int j = 0; j < columnas; ++j) std::cout << "══";
    std::cout << "╝\n";
}

bool mover_en_laberinto(int fila, int columna, const std::vector<std::vector<bool>> &laberinto, std::vector<std::vector<bool>> &camino) {
    int filas = laberinto.size();
    int columnas = laberinto[0].size();

    // Fuera de límites, pared o ya visitado
    if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas ||
        !laberinto[fila][columna] || camino[fila][columna]) {
        return false;
    }

    // Marca la casilla como parte del camino
    camino[fila][columna] = true;

    // Si es la meta, termina
    if (fila == filas - 1 && columna == columnas - 1) {
        return true;
    }

    // Prioridad: derecha, abajo, izquierda, arriba
    if (mover_en_laberinto(fila, columna + 1, laberinto, camino)) return true; // derecha
    if (mover_en_laberinto(fila + 1, columna, laberinto, camino)) return true; // abajo
    if (mover_en_laberinto(fila, columna - 1, laberinto, camino)) return true; // izquierda
    if (mover_en_laberinto(fila - 1, columna, laberinto, camino)) return true; // arriba

    // Si no hay camino, desmarca y retrocede
    camino[fila][columna] = false;
    return false;
}

void main_6() {
    const int dim = 30;
    std::vector<std::vector<bool>> laberinto = hacer_laberinto(dim, dim);
    std::vector<std::vector<bool>> camino(dim, std::vector<bool>(dim, false));
    bool exito = false;

    std::cout << "Laberinto generado:\n";
    mostrar_laberinto(laberinto);
    exito = mover_en_laberinto(0, 0, laberinto, camino);
    if (exito) {
        std::cout << "Camino desde la entrada hasta la salida:\n";
        mostrar_camino(laberinto, camino);
    } else {
        std::cout << "No se encontró ningún camino.\n";
    }
}

// 7. Palabras en un tablero (Word Search)
//    Dado un tablero de letras y una lista de palabras, encuentra si se puede formar una palabra moviéndose horizontal, vertical o diagonalmente.
void mostrar_tablero_g(size_t filas, size_t columnas, const std::vector<std::vector<char>> &casillas) {
    std::cout << "\n\n";
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            std::cout << casillas[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

size_t maxima_longitud_en_vector(const std::vector<std::string> &vec) {
    size_t max_length = 0;
    for (const auto &str : vec) {
        if (str.length() > max_length) {
            max_length = str.length();
        }
    }
    return max_length;
}

class TableroLetras
{
public:
    size_t filas;
    size_t columnas;
    std::vector<std::vector<char>> casillas;

    // Constructor
    TableroLetras(size_t f, size_t c) : filas(f), columnas(c) {
        casillas = std::vector<std::vector<char>>(filas, std::vector<char>(columnas, ' '));
        // Rellenar el tablero con letras aleatorias
        std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, alfabeto.size() - 1);

        for (size_t i = 0; i < filas; i++) {
            for (size_t j = 0; j < columnas; j++) {
                casillas[i][j] = alfabeto[dis(gen)];
            }
        }
    }

    void mostrar_tablero() {
        mostrar_tablero_g(filas, columnas, casillas);
    }
    
    std::vector<std::pair<size_t, size_t>> buscar_letra_en_tablero(char letra) {
        std::vector<std::pair<size_t, size_t>> posiciones = {};
        for (size_t i = 0; i < filas; i++) {
            for (size_t j = 0; j < columnas; j++) {
                if (casillas[i][j] == letra) {
                    posiciones.push_back({i, j});
                }
            }
        }
        return posiciones;
    }

    bool letras_de_palabra_esta_en_tablero(std::string palabra) {
        // Copia todas las letras del tablero en un vector
        std::vector<std::pair<size_t, size_t>> posiciones;
        for (size_t i = 0; i < palabra.length(); i++) {
            posiciones = buscar_letra_en_tablero(palabra[i]);
            if (posiciones.empty()) {
                return false;
            }
        }
        return true;
    }


    bool es_movimiento_horizontal_valido(const std::pair<size_t, size_t> actual, const std::pair<size_t, size_t> siguiente) {
        size_t fila_diff = siguiente.first - actual.first;
        size_t col_diff = siguiente.second - actual.second;
        return (fila_diff == 0 && (col_diff == 1 || col_diff == -1));
    }

    bool comprobar_palabra_horizontal(const std::pair<size_t, size_t> inicio, std::string palabra) {
        size_t fila = inicio.first;
        size_t columna = inicio.second;
        // Comprobar hacia la derecha
        if (columna + palabra.length() <= columnas) {
            bool coincide = true;
            for (size_t k = 0; k < palabra.length(); k++) {
                if (casillas[fila][columna + k] != palabra[k]) {
                    coincide = false;
                    break;
                }
            }
            if (coincide) return true;
        }
        // Comprobar hacia la izquierda
        if (columna >= palabra.length() - 1) {
            bool coincide = true;
            for (size_t k = 0; k < palabra.length(); k++) {
                if (casillas[fila][columna - k] != palabra[k]) {
                    coincide = false;
                    break;
                }
            }
            if (coincide) return true;
        }
        return false;
    }

    bool comprobar_palabra_vertical(const std::pair<size_t, size_t> inicio, std::string palabra) {
        size_t fila = inicio.first;
        size_t columna = inicio.second;
        // Comprobar hacia abajo
        if (fila + palabra.length() <= filas) {
            bool coincide = true;
            for (size_t k = 0; k < palabra.length(); k++) {
                if (casillas[fila + k][columna] != palabra[k]) {
                    coincide = false;
                    break;
                }
            }
            if (coincide) return true;
        }
        // Comprobar hacia arriba
        if (fila >= palabra.length() - 1) {
            bool coincide = true;
            for (size_t k = 0; k < palabra.length(); k++) {
                if (casillas[fila - k][columna] != palabra[k]) {
                    coincide = false;
                    break;
                }
            }
            if (coincide) return true;
        }
        return false;
    }

    bool comprobar_palabra_diagonal(const std::pair<size_t, size_t> inicio, std::string palabra) {
        size_t fila = inicio.first;
        size_t columna = inicio.second;
        // Comprobar diagonal (abajo derecha)
        if (fila + palabra.length() <= filas && columna + palabra.length() <= columnas) {
            bool coincide = true;
            for (size_t k = 0; k < palabra.length(); k++) {
                if (casillas[fila + k][columna + k] != palabra[k]) {
                    coincide = false;
                    break;
                }
            }
            if (coincide) return true;
        }
        // Comprobar diagonal (abajo izquierda)
        if (fila + palabra.length() <= filas && columna >= palabra.length() - 1) {
            bool coincide = true;
            for (size_t k = 0; k < palabra.length(); k++) {
                if (casillas[fila + k][columna - k] != palabra[k]) {
                    coincide = false;
                    break;
                }
            }
            if (coincide) return true;
        }
        // Comprobar diagonal (arriba derecha)
        if (fila >= palabra.length() - 1 && columna + palabra.length() <= columnas) {
            bool coincide = true;
            for (size_t k = 0; k < palabra.length(); k++) {
                if (casillas[fila - k][columna + k] != palabra[k]) {
                    coincide = false;
                    break;
                }
            }
            if (coincide) return true;
        }
        // Comprobar diagonal (arriba izquierda)
        if (fila >= palabra.length() - 1 && columna >= palabra.length() - 1) {
            bool coincide = true;
            for (size_t k = 0; k < palabra.length(); k++) {
                if (casillas[fila - k][columna - k] != palabra[k]) {
                    coincide = false;
                    break;
                }
            }
            if (coincide) return true;
        }
        return false;
    }

    bool es_movimiento_vertical_valido(const std::pair<size_t, size_t> actual, const std::pair<size_t, size_t> siguiente) {
        size_t fila_diff = siguiente.first - actual.first;
        size_t col_diff = siguiente.second - actual.second;
        return (col_diff == 0 && (fila_diff == 1 || fila_diff == -1));
    }

    bool es_movimiento_diagonal_valido(const std::pair<size_t, size_t> actual, const std::pair<size_t, size_t> siguiente) {
        size_t fila_diff = siguiente.first - actual.first;
        size_t col_diff = siguiente.second - actual.second;
        return (std::abs(static_cast<int>(fila_diff)) == 1 && std::abs(static_cast<int>(col_diff)) == 1);
    }

    bool palabra_con_posicion_inicial_esta_en_tablero(const std::pair<size_t, size_t> inicio, std::string palabra) {
        return comprobar_palabra_horizontal(inicio, palabra) ||
               comprobar_palabra_vertical(inicio, palabra) ||
               comprobar_palabra_diagonal(inicio, palabra);
    }

    

    void mostrar_palabra_en_tablero(std::string palabra, const  std::pair<size_t, size_t> inicio) {
        // Marcar la palabra en el tablero y sustituir el resto de las letras por *
        std::vector<std::vector<char>> casilla_con_palabras(filas, std::vector<char>(columnas, '.'));
        if (comprobar_palabra_horizontal(inicio, palabra)) {
            for (size_t k = 0; k < palabra.length(); k++) {
            size_t fila = inicio.first;
            size_t columna = inicio.second;
            // Hacia la derecha
            if (columna + palabra.length() <= columnas && casillas[fila][columna + k] == palabra[k]) {
                casilla_con_palabras[fila][columna + k] = palabra[k];
            }
            // Hacia la izquierda
            if (columna >= palabra.length() - 1 && casillas[fila][columna - k] == palabra[k]) {
                casilla_con_palabras[fila][columna - k] = palabra[k];
            }
            }
        }

        if (comprobar_palabra_vertical(inicio, palabra)) {
            for (size_t k = 0; k < palabra.length(); k++) {
                size_t fila = inicio.first;
                size_t columna = inicio.second;
                // Hacia abajo
                if (fila + palabra.length() <= filas && casilla_con_palabras[fila + k][columna] == palabra[k]) {
                    casilla_con_palabras[fila + k][columna] = palabra[k];
                }
                // Hacia arriba
                if (fila >= palabra.length() - 1 && casilla_con_palabras[fila - k][columna] == palabra[k]) {
                    casilla_con_palabras[fila - k][columna] = palabra[k];
                }
            }
        }

        if (comprobar_palabra_diagonal(inicio, palabra)) {
            for (size_t k = 0; k < palabra.length(); k++) {
                size_t fila = inicio.first;
                size_t columna = inicio.second;
                // Diagonal (abajo derecha)
                if (fila + palabra.length() <= filas && columna + palabra.length() <= columnas &&
                    casilla_con_palabras[fila + k][columna + k] == palabra[k]) {
                    casilla_con_palabras[fila + k][columna + k] = palabra[k];
                }
                // Diagonal (abajo izquierda)
                if (fila + palabra.length() <= filas && columna >= palabra.length() - 1 &&
                    casilla_con_palabras[fila + k][columna - k] == palabra[k]) {
                    casilla_con_palabras[fila + k][columna - k] = palabra[k];
                }
                // Diagonal (arriba derecha)
                if (fila >= palabra.length() - 1 && columna + palabra.length() <= columnas &&
                    casilla_con_palabras[fila - k][columna + k] == palabra[k]) {
                    casilla_con_palabras[fila - k][columna + k] = palabra[k];
                }
                // Diagonal (arriba izquierda)
                if (fila >= palabra.length() - 1 && columna >= palabra.length() - 1 &&
                    casilla_con_palabras[fila - k][columna - k] == palabra[k]) {
                    casilla_con_palabras[fila - k][columna - k] = palabra[k];
                }
            }
        }
        mostrar_tablero_g(filas, columnas, casilla_con_palabras);
    }
        

    bool palabra_esta_en_tablero(std::string palabra) {
        // Primera comprobación rápida: si alguna letra no está en el tablero, devuelve false
        if (!letras_de_palabra_esta_en_tablero(palabra)) {
            return false;
        }
        std::vector<std::pair<size_t, size_t>> posiciones_iniciales = buscar_letra_en_tablero(palabra[0]);
        for (const auto &posicion_inicial : posiciones_iniciales) {
            if (palabra_con_posicion_inicial_esta_en_tablero(posicion_inicial, palabra)) {
                mostrar_palabra_en_tablero(palabra, posicion_inicial);
                return true;
            }
        }
        return false;
    }
};

void main_7() {
    std::vector<std::string> lista_palabras = {"a", "es", "cpp", "hola", "mundo", "backtracking"};
    size_t dim = 1 * maxima_longitud_en_vector(lista_palabras);
    TableroLetras tablero = TableroLetras(dim, dim);
    tablero.mostrar_tablero();
    for (size_t i = 0; i < lista_palabras.size(); i++) {
        if(tablero.palabra_esta_en_tablero(lista_palabras[i])) {
            std::cout << "La palabra \"" << lista_palabras[i] << "\" SI está en el tablero.\n";
            continue;
        }
        std::cout << "La palabra \"" << lista_palabras[i] << "\" NO está en el tablero.\n";
    }
}

// 8. Partición de un conjunto en k subconjuntos con suma igual
bool suman_igual(const std::vector<int> &conjunto1, const std::vector<int> &conjunto2, int k) {
    int suma1 = 0;
    int suma2 = 0;
    for (int num : conjunto1) {
        suma1 += num;
    }
    for (int num : conjunto2) {
        suma2 += num;
    }
    return suma1 == suma2;
}

std::vector<std::vector<int>> subconjuntos_long_k(const std::vector<int> &numeros, int k) {

    return {};
}

std::vector<std::vector<int>> particionar_en_k_subconjuntos_con_suma_igual(const std::vector<int> &numeros, int k) {
    return {};
}

bool existe_particion_k_subconjuntos(const std::vector<int> &numeros, int k) {
    return false;
}

void main_8() {
    std::vector<int> numeros = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    if (existe_particion_k_subconjuntos(numeros, k)) {
        std::cout << "Es posible particionar el conjunto en " << k << " subconjuntos con la misma suma.\n";
    } else {
        std::cout << "No es posible particionar el conjunto en " << k << " subconjuntos con la misma suma.\n";
    }
}

//    Dado un conjunto de números, determina si se puede dividir en k subconjuntos con la misma suma.

// 9. Colorear un grafo (Graph Coloring)
//    Dado un grafo y un número de colores, asigna un color a cada nodo de modo que no haya dos nodos adyacentes con el mismo color.

// 10. Resolver el problema del viajante (Traveling Salesman Problem, TSP) por fuerza bruta
//     Dada una lista de ciudades y las distancias entre ellas, encuentra el camino más corto que visita cada ciudad exactamente una vez y regresa al punto de inicio.

// 11. Generar todas las secuencias binarias de longitud n
//     Dado un número n, genera todas las secuencias posibles de 0s y 1s de longitud n.

// 12. Generar todas las particiones de un número
//     Dado un número n, genera todas las formas posibles de escribir n como suma de números positivos.

// 13. Generar todas las combinaciones de paréntesis válidos
//     Dado n pares de paréntesis, genera todas las combinaciones válidas.

// 14. Generar todas las permutaciones únicas de un vector con elementos repetidos
//     Dado un vector con elementos repetidos, genera todas las permutaciones únicas (sin duplicados).

// 15. Generar todas las formas de colocar k caballos en un tablero NxN sin que se ataquen
//     Dado un tablero NxN y k caballos, genera todas las formas de colocarlos sin que se ataquen entre sí.

// 16. Encontrar todas las formas de sumar monedas para un valor dado
//     Dadas monedas de ciertos valores y un objetivo, encuentra todas las combinaciones de monedas que suman ese objetivo.

// 17. Resolver el problema de las palabras cruzadas (Crossword Puzzle)
//     Dado un tablero y una lista de palabras, encuentra todas las formas de colocar las palabras en el tablero respetando las reglas.

// 18. Encontrar todas las formas de dividir un string en palabras válidas (Word Break)
//     Dada una cadena y un diccionario, encuentra todas las formas de segmentar la cadena en palabras del diccionario.

// 19. Resolver el problema de los números mágicos (Magic Square)
//     Genera todos los cuadrados mágicos de tamaño NxN (todas las filas, columnas y diagonales suman lo mismo).

// 20. Encontrar todas las formas de cubrir un tablero con fichas de dominó
//     Dado un tablero rectangular, encuentra todas las formas de cubrirlo completamente con fichas de dominó (2x1) sin solapamientos ni huecos.

int main() {
    main_7();
    return 0;
}