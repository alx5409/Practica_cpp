#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>
#include <math.h>

// Funciones auxiliares para los ejercicios.
template <typename T>
void mostrar_vector(std::vector<T> vector) {
    std::cout << "[";
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << "]\n";
}

template <typename T>
void mostrar_matriz(const std::vector<std::vector<T>> matriz) {
    int n = matriz.size();
    for (int i = 0; i < n; i++) {
        mostrar_vector(matriz[i]);
    }
}

template <typename T>
void comprobar_matriz_cuadrada(const std::vector<std::vector<T>> matriz) {
    for (const auto& fila : matriz) {
        if (fila.size() != matriz.size()) {
            throw std::invalid_argument("La matriz no es cuadrada.\n");
        }
    }
}
// Ejercicio 1: Escribe una función template que multiplique todos los elementos de un vector por un escalar.
template <typename T>
void escalar_vector(std::vector<T>& vector,const  T escalar) {
    for (int i = 0; i < vector.size(); i++) {
        vector[i] = vector[i] * escalar;
    }
}
// Ejercicio 2: Escribe una función template que calcule el producto escalar de dos vectores del mismo tamaño.
template <typename T>
T producto_escalar(std::vector<T> vector_1, std::vector<T> vector_2) {
    T resultado = 0;
    if (vector_1.size() != vector_2.size()) {
        throw std::invalid_argument("Los vectores tienen tamaños diferentes.\n");
    }
    for (int i = 0; i < vector_1.size(); i++) {
        resultado += vector_1[i] * vector_2[i];
    }
    return resultado;
}
// Ejercicio 3: Escribe una función template que transponga una matriz cuadrada representada como vector de vectores.
template <typename T>
void transponer_matriz_cuadrada(std::vector<std::vector<T>>& matriz) {
    int n = matriz.size();
    // Comprueba que la matriz es cuadrada, si no lo es tira una excepcion.
    comprobar_matriz_cuadrada(matriz);
    // La matriz es un vector de vectores fila, ahora haremos que cada fila sea una columna
    for (int fila = 0; fila < n; fila++) {
        for (int columna = fila + 1; columna < n; columna++){   // Recorre solo la matriz triangular superior
            T temp = matriz[fila][columna];
            matriz[fila][columna] = matriz[columna][fila];
            matriz[columna][fila] = temp;
            }
    }
}   
// Ejercicio 4: Escribe una función template que aplique una función (lambda o función normal) a todos los elementos de un vector.
template <typename T, typename Func>
void aplicar_funcion_a_vector(std::vector<T>& vector, Func funcion) {
    for (int i = 0; i < vector.size(); i++) {
        vector[i] = funcion(vector[i]);
    }
}

// Ejercicio 5: Escribe una clase template Matriz que permita sumar y multiplicar matrices cuadradas.
template <typename T>
class Matriz {
public:
    std::vector<std::vector<T>> entrada;
    int dim;
    Matriz(std::vector<std::vector<T>> elementos) {
        int n = elementos.size();
        comprobar_matriz_cuadrada(elementos);
        dim = n;
        entrada = elementos;
    }

    void sumar(const std::vector<std::vector<T>>& matriz) {
        int n = matriz.size();
        if (n != dim) {
            throw std::invalid_argument("La matriz no tiene la misma dimension.\n");
        }
        comprobar_matriz_cuadrada(matriz);

        for (int fila = 0; fila < dim; fila++) {
            for (int columna = 0; columna < dim; columna++) {
                entrada[fila][columna] += matriz[fila][columna];
            }
        }
    }

    void multiplicar(const std::vector<std::vector<T>>& matriz){
        int n = matriz.size();
        if (n != dim) {
            throw std::invalid_argument("La matriz no tiene la misma dimension.\n");
        }
        comprobar_matriz_cuadrada(matriz);

        std::vector<std::vector<T>> resultado(dim, std::vector<T>(dim, 0));
        for (int fila = 0; fila < dim; fila++) {
            for (int columna = 0; columna < dim; columna++) {
                for (int k = 0; k < dim; k++) {
                    resultado[fila][columna] += entrada[fila][k] * matriz[k][columna];
                }
            }
        }
        entrada = resultado;
    }
};
// Ejercicio 6: Escribe una función template que normalice un vector (divida todos sus elementos por la suma total).
template <typename T>
void normalizar_vector_suma(std::vector<T>& vector) {
   int n = vector.size();
    T norma_vector = 0;
    for (int i = 0; i < n; i++) {
        norma_vector += vector[i];
    }
    for (int i = 0; i < n; i++) {
        vector[i] = vector[i] / norma_vector;
    } 
}

template <typename T>
void normalizar_vector_l2(std::vector<T>& vector) {
    int n = vector.size();
    T norma_vector = 0;
    for (int i = 0; i < n; i++) {
        norma_vector += pow(vector[i], 2);
    }
    norma_vector = pow(norma_vector, 0.5);
    for (int i = 0; i < n; i++) {
        vector[i] = vector[i] / norma_vector;
    }
}

// Ejercicio 7: Escribe una función template que calcule la media y la varianza de un vector de números.
template <typename T>
std::pair<T, T> media_y_varianza(std::vector<T> vector) {
    T mean = 0;
    T var = 0;
    int n = vector.size();
    for (int i = 0; i < n; i++) {
        mean += vector[i];
    }
    mean /= n;
    for (int i = 0; i < n; i++) {
        var += pow((vector[i] - mean), 2);
    }
    var /= n;
    return {mean, var};
}

// Ejercicio 8: Escribe una función template que calcule la distancia euclídea entre dos vectores.
template <typename T>
float distancia_euclidea_entre_vectores(std::vector<T> vector_1, std::vector<T> vector_2) {
    float distancia = 0;
    if (vector_1.size() != vector_2.size()) {
        throw std::invalid_argument("Los vectores no tienen la misma dimension.\n");
    }
    for (int i = 0; i < vector_1.size(); i++) {
        distancia += pow(vector_1[i] - vector_2[i], 2);
    }
    distancia = pow(distancia, 0.5);
    return distancia;
}

// Ejercicio 9: Escribe una función template que aplique la función sigmoide a todos los elementos de un vector.
template <typename T>
T sigmoide(const T x) {
    return 1/(1 + std::exp(-x));
}

template <typename T>
void aplicar_sigmoide_a_vector(std::vector<T>& vector) {
    aplicar_funcion_a_vector(vector, sigmoide);
}

// Ejercicio 10: Escribe una función template que realice una regresión lineal simple (y = ax + b) dados dos vectores de datos.
template <typename T>
std::pair<T, T> linear_regression(const std::vector<T> x, const std::vector<T> y) {
    // Usando la fórmula de la solución de mínimos cuadrados:
    // a = (n * Σ(x_i * y_i) - Σx_i * Σy_i) / (n * Σ(x_i^2) - (Σx_i)^2)
    // b = (Σy_i - a * Σx_i) / n
    T suma_x = 0;
    T suma_y = 0;
    T suma_productos = 0;
    T suma_x_cuadrado = 0;
    T a;
    T b;
    if (x.size() != y.size()) {
        throw std::invalid_argument("Los vectores no tienen la misma dimension.\n");
    }
    int n = x.size();
    for (int i = 0; i < n; i++) {
        suma_x += x[i];
        suma_y += y[i];
        suma_productos += (x[i] * y[i]);
        suma_x_cuadrado += (x[i] * x[i]);
    }
    a = (n * suma_productos - suma_x * suma_y) / (n * suma_x_cuadrado - pow(suma_x, 2));
    b = (suma_y - a * suma_x) / n;
    return {a, b};
}

// Ejercicio 11: Escribe una función template que calcule la matriz de covarianza de un conjunto de vectores.
template <typename T>
T covarianza(std::vector<T> x, std::vector<T> y) {
    if (x.size() != y.size()) {
        throw std::invalid_argument("Los vectores no tienen el mismo tamaño.\n");
    }

    T media_x = 0;
    T media_y = 0;
    int n = x.size()
    T cov = 0;

    for (int i = 0; i < n; i++) {
        media_x += x[i];
        media_y += y[i];
    }
    media_x /= n;
    media_y /= n;

    for (int i = 0; i < n; i++) {
        cov += (x[i] - media_x) * (y[i] - media_y);
    }
    cov /= n;
    return cov;
}

template <typename T>
std::vector<std::vector<T>> calcular_matriz_covarianza(const std::vector<std::vector<T>>& datos) {
    // datos: m x n (m observaciones, n variables)
    int m = datos.size();
    if (m == 0) return {};
    int n = datos[0].size();

    // Comprobar que todas las filas tienen el mismo tamaño
    for (const auto& fila : datos) {
        if (fila.size() != n) {
            throw std::invalid_argument("Todas las filas deben tener el mismo tamaño.");
        }
    }

    // Extraer columnas para el calculo de la covarianza
    std::vector<std::vector<T>> columnas(n, std::vector<T>(m));
    for (int col = 0; col < n; col++) {
        for (int fila = 0; fila < m; fila++) {
            columnas[col][fila] = datos[fila][col];
        }
    }

    // Calcular matriz de covarianza (n x n): se calcula con las columnas
    std::vector<std::vector<T>> matriz(n, std::vector<T>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = covarianza(columnas[i], columnas[j]);
        }
    }
    return matriz;
}

// Ejercicio 12: Escribe una función template que encuentre el valor máximo y su posición en un vector.
template <typename T>
std::pair<T, int> maximo_en_vector(std::vector<T> vector) {
    int posicion = 0;
    T max = vector[posicion];
    for (int i = 0; i < vector.size(); i++) {
        if (max < vector[i]) {
            posicion = i;
            max = vector[posicion];
        }
    }
    return {max, posicion};
}

// Ejercicio 13: Escribe una función template que realice el producto de una matriz por un vector.
template<typename T>
std::vector<T> producto_matriz_vector(std::vector<std::vector<T>> matriz, std::vector<T> vector) {
    std::vector<T> producto;
    if (matriz[0].size() != vector.size()) {
        throw std::invalid_argument("La matriz no tiene las mismas columnas que la dimension del vector.\n");
    }
    for (int i = 0; i < matriz.size(); i++) {
        producto.push_back(producto_escalar(matriz[i], vector));
    }
    return producto;
}

// Ejercicio 14: Escribe una función template que implemente el descenso de gradiente para minimizar una función cuadrática.
template <typename T>
T funcion_cuadratica_general(T x, T a = 1, T b = 1, T c = 1) {
    return a * pow(x, 2) + b * x + c;
}

template <typename T>
T derivada_funcion_cuadratica_general(T x, T a = 1, T b = 1) {
    return 2 * a * x + b;
}

template <typename T, typename Func>
T cuadratic_gradient_descent(T tasa_aprendizaje, int numero_iteraciones = 100, T epsilon = 1e-4,
    T valor_inicial = 0) {
        // Manejamos execpciones al principio
        if (numero_iteraciones <= 0) {
            throw std::invalid_argument("El número de iteracionas máximo no puede ser menor o igual que 0.\n");
            return;
        }
        if (epsilon <= 0) {
            throw std::invalid_argument("El error máximo no puede ser menor o igual que 0.\n");
        }
        if (tasa_aprendizaje <= 0) {
            throw std::invalid_argument("La tasa de aprendizaje tiene que ser positiva.\n");
        }


        int n_iter = 0;
        T valor = valor_inicial;
        T error = abs(funcion_cuadratica_general(valor_inicial));
        while (n_iter < numero_iteraciones && error >= epsilon) {
            valor -= tasa_aprendizaje * derivada_funcion_cuadratica_general(valor);
            error = abs(funcion_cuadratica_general(valor));
            n_iter++;
        }
        return valor;
}

// Ejercicio 15: Escribe una función template que calcule la función softmax sobre un vector.
template <typename T>
std::vector<T> softmax(std::vector<T> vector) {
    std::vector<T> resultado;
    T suma = 0;
    for (int i = 0; i < vector.size(); i++) {
        suma += exp(vector[i]);
    }
    for (int i = 0; i < vector.size(); i++) {
        resultado.push_back(exp(vector[i])/suma);
    }
    return resultado;
}

// Ejercicio 16: Escribe una función template que calcule la entropía cruzada (cross-entropy) entre dos vectores de probabilidades.

template <typename T>
bool comprobar_vector_probabilidad(std::vector<T> vector) {
    T suma = 0;
    for (int i = 0; i < vector.size(); i++) {
        suma += vector[i];
    }
    if (std::abs(suma - 1) < 1e-6) {
        return  true; 
    }
    return false;
}
template <typename T>
T entropia_cruzada(std::vector<T> vector_probabilidad_1, std::vector<T> vector_probabilidad_2) {
    // Comprueba que los dos vectores que introduce suman 1
    if (!(comprobar_vector_probabilidad(vector_probabilidad_1)&&comprobar_vector_probabilidad(vector_probabilidad_2))) {
        throw std::invalid_argument("Los vectores introducidos no son de probabilidad, no suman 1.\n");
    }
    if (vector_probabilidad_1.size() != vector_probabilidad_2.size()) {
        throw std::invalid_argument("Los vectores no son de la misma dimensión.\n");
    }

    T entropia = 0;
    for (int i = 0; i < vector_probabilidad_1.size(); i++) {
        entropia -= vector_probabilidad_1[i] * log(vector_probabilidad_2[i]);
    }
    return entropia;
}
int main() {
    return 0;
}