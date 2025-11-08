#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>
#include <math.h>

/**
 * Muestra los elementos de un vector por consola.
 * @param vector Vector a mostrar.
 */
template <typename T>
void mostrar_vector(std::vector<T> vector) {
    std::cout << "[";
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << "]\n";
}

/**
 * Muestra una matriz (vector de vectores) por consola.
 * @param matriz Matriz a mostrar.
 */
template <typename T>
void mostrar_matriz(const std::vector<std::vector<T>> matriz) {
    int n = matriz.size();
    for (int i = 0; i < n; i++) {
        mostrar_vector(matriz[i]);
    }
}

/**
 * Comprueba si una matriz es cuadrada.
 * Lanza std::invalid_argument si alguna fila no tiene el mismo tamaño que el número de filas.
 * @param matriz Matriz a comprobar.
 */
template <typename T>
void comprobar_matriz_cuadrada(const std::vector<std::vector<T>> matriz) {
    for (const auto& fila : matriz) {
        if (fila.size() != matriz.size()) {
            throw std::invalid_argument("La matriz no es cuadrada.\n");
        }
    }
}

/**
 * Multiplica todos los elementos de un vector por un escalar.
 * @param vector Vector a modificar.
 * @param escalar Valor por el que multiplicar cada elemento.
 */
template <typename T>
void escalar_vector(std::vector<T>& vector,const  T escalar) {
    for (int i = 0; i < vector.size(); i++) {
        vector[i] = vector[i] * escalar;
    }
}

/**
 * Calcula el producto escalar de dos vectores del mismo tamaño.
 * @param vector_1 Primer vector.
 * @param vector_2 Segundo vector.
 * @return Producto escalar.
 */
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

/**
 * Transpone una matriz cuadrada (intercambia filas y columnas).
 * @param matriz Matriz cuadrada a transponer.
 */
template <typename T>
void transponer_matriz_cuadrada(std::vector<std::vector<T>>& matriz) {
    int n = matriz.size();
    comprobar_matriz_cuadrada(matriz);
    for (int fila = 0; fila < n; fila++) {
        for (int columna = fila + 1; columna < n; columna++){
            T temp = matriz[fila][columna];
            matriz[fila][columna] = matriz[columna][fila];
            matriz[columna][fila] = temp;
        }
    }
}

/**
 * Aplica una función a todos los elementos de un vector.
 * @param vector Vector a modificar.
 * @param funcion Función a aplicar.
 */
template <typename T, typename Func>
void aplicar_funcion_a_vector(std::vector<T>& vector, Func funcion) {
    for (int i = 0; i < vector.size(); i++) {
        vector[i] = funcion(vector[i]);
    }
}

/**
 * Clase Matriz para sumar y multiplicar matrices cuadradas.
 */
template <typename T>
class Matriz {
public:
    std::vector<std::vector<T>> entrada;
    int dim;
    /**
     * Constructor que recibe una matriz cuadrada.
     * @param elementos Matriz cuadrada.
     */
    Matriz(std::vector<std::vector<T>> elementos) {
        int n = elementos.size();
        comprobar_matriz_cuadrada(elementos);
        dim = n;
        entrada = elementos;
    }

    /**
     * Suma otra matriz cuadrada de la misma dimensión.
     * @param matriz Matriz a sumar.
     */
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

    /**
     * Multiplica por otra matriz cuadrada de la misma dimensión.
     * @param matriz Matriz a multiplicar.
     */
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

/**
 * Normaliza un vector dividiendo cada elemento por la suma total.
 * @param vector Vector a normalizar.
 */
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

/**
 * Normaliza un vector usando la norma L2 (raíz cuadrada de la suma de cuadrados).
 * @param vector Vector a normalizar.
 */
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

/**
 * Calcula la media y la varianza de un vector.
 * @param vector Vector de números.
 * @return Par (media, varianza).
 */
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

/**
 * Calcula la distancia euclídea entre dos vectores.
 * @param vector_1 Primer vector.
 * @param vector_2 Segundo vector.
 * @return Distancia euclídea.
 */
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

/**
 * Aplica la función sigmoide a un valor.
 * @param x Valor de entrada.
 * @return Resultado de la sigmoide.
 */
template <typename T>
T sigmoide(const T x) {
    return 1/(1 + std::exp(-x));
}

/**
 * Aplica la función sigmoide a todos los elementos de un vector.
 * @param vector Vector a modificar.
 */
template <typename T>
void aplicar_sigmoide_a_vector(std::vector<T>& vector) {
    aplicar_funcion_a_vector(vector, sigmoide);
}

/**
 * Realiza una regresión lineal simple (y = ax + b) dados dos vectores de datos.
 * @param x Vector de valores independientes.
 * @param y Vector de valores dependientes.
 * @return Par (a, b) de coeficientes.
 */
template <typename T>
std::pair<T, T> linear_regression(const std::vector<T> x, const std::vector<T> y) {
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

/**
 * Calcula la covarianza entre dos vectores.
 * @param x Primer vector.
 * @param y Segundo vector.
 * @return Covarianza.
 */
template <typename T>
T covarianza(std::vector<T> x, std::vector<T> y) {
    if (x.size() != y.size()) {
        throw std::invalid_argument("Los vectores no tienen el mismo tamaño.\n");
    }

    T media_x = 0;
    T media_y = 0;
    int n = x.size();
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

/**
 * Calcula la matriz de covarianza de un conjunto de vectores.
 * @param datos Matriz de datos (muestras x variables).
 * @return Matriz de covarianza.
 */
template <typename T>
std::vector<std::vector<T>> calcular_matriz_covarianza(const std::vector<std::vector<T>>& datos) {
    int m = datos.size();
    if (m == 0) return {};
    int n = datos[0].size();

    for (const auto& fila : datos) {
        if (fila.size() != n) {
            throw std::invalid_argument("Todas las filas deben tener el mismo tamaño.");
        }
    }

    std::vector<std::vector<T>> columnas(n, std::vector<T>(m));
    for (int col = 0; col < n; col++) {
        for (int fila = 0; fila < m; fila++) {
            columnas[col][fila] = datos[fila][col];
        }
    }

    std::vector<std::vector<T>> matriz(n, std::vector<T>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = covarianza(columnas[i], columnas[j]);
        }
    }
    return matriz;
}

/**
 * Encuentra el valor máximo y su posición en un vector.
 * @param vector Vector de entrada.
 * @return Par (valor máximo, posición).
 */
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

/**
 * Realiza el producto de una matriz por un vector.
 * @param matriz Matriz de entrada.
 * @param vector Vector de entrada.
 * @return Vector resultado del producto.
 */
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

/**
 * Evalúa una función cuadrática general.
 * @param x Valor de entrada.
 * @param a Coeficiente cuadrático.
 * @param b Coeficiente lineal.
 * @param c Término independiente.
 * @return Resultado de la función cuadrática.
 */
template <typename T>
T funcion_cuadratica_general(T x, T a = 1, T b = 1, T c = 1) {
    return a * pow(x, 2) + b * x + c;
}

/**
 * Calcula la derivada de una función cuadrática general.
 * @param x Valor de entrada.
 * @param a Coeficiente cuadrático.
 * @param b Coeficiente lineal.
 * @return Derivada en x.
 */
template <typename T>
T derivada_funcion_cuadratica_general(T x, T a = 1, T b = 1) {
    return 2 * a * x + b;
}

/**
 * Implementa el descenso de gradiente para minimizar una función cuadrática.
 * @param tasa_aprendizaje Tasa de aprendizaje.
 * @param numero_iteraciones Número máximo de iteraciones.
 * @param epsilon Umbral de error para detener el algoritmo.
 * @param valor_inicial Valor inicial de la variable.
 * @return Valor donde se alcanza el mínimo local.
 */
template <typename T, typename Func>
T cuadratic_gradient_descent(T tasa_aprendizaje, int numero_iteraciones = 100, T epsilon = 1e-4,
    T valor_inicial = 0) {
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

/**
 * Calcula la función softmax sobre un vector.
 * @param vector Vector de entrada.
 * @return Vector con probabilidades softmax.
 */
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

/**
 * Comprueba si un vector es de probabilidad (suma aproximadamente 1).
 * @param vector Vector de entrada.
 * @return true si suma 1, false si no.
 */
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

/**
 * Calcula la entropía cruzada (cross-entropy) entre dos vectores de probabilidades.
 * @param vector_probabilidad_1 Vector de probabilidades reales.
 * @param vector_probabilidad_2 Vector de probabilidades predichas.
 * @return Valor de la entropía cruzada.
 */
template <typename T>
T entropia_cruzada(std::vector<T> vector_probabilidad_1, std::vector<T> vector_probabilidad_2) {
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