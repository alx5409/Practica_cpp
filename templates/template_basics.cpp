#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

// Ejercicio 1: Escribe una función template que intercambie dos valores de cualquier tipo.
template <typename T>
void intercambiar_valores(T &a, T &b) {
    std::swap(a, b);
}

template <typename T, typename U>
void mostrar_valores(const T a, const U b) {
    std::cout << "El primer valor es: " << a << " y el segundo valor es " << b << std::endl;
}

void main_1() {
    int valor = 0;
    int segundo_valor = 2;
    
    mostrar_valores(valor, segundo_valor);
    intercambiar_valores(valor, segundo_valor);
    mostrar_valores(valor, segundo_valor);
}

// Ejercicio 2: Escribe una función template que devuelva el máximo de dos valores de cualquier tipo.
template <typename T>
T maximo(T a, T b) {
    if (a > b) {
        return a;
    }
    return b;
}

void main_2() {
    int valor_1 = 4;
    int valor_2 = 2;

    int maxim = maximo(valor_1, valor_2);
    std::cout << "El valor máximo es: " << maxim << std::endl;
}

// Ejercicio 3: Escribe una función template que imprima los elementos de un vector de cualquier tipo.
template <typename T>
void imprimir_elementos_vector(std::vector<T> vector) {
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

void main_3() {
    std::vector<int> int_vector = {1, 2, 3, 4, 5};
    std::vector<std::string> string_vector = {"hola", "que", "tal", "?"};
    imprimir_elementos_vector(int_vector);
    imprimir_elementos_vector(string_vector);
}

// Ejercicio 4: Escribe una clase template llamada Pareja que almacene dos valores de tipos (posiblemente) diferentes y tenga un método para mostrarlos.
template <typename T>
class Pareja {
public:
    T primero;
    T segundo;
    Pareja(T a, T b) : primero(a), segundo(b) {}
    void mostrar() const {
        std::cout << "Primer elemento : " << primero << " .Segundo elemento " << segundo << std::endl;
    }
};

void main_4() {
    int valor_1 = 1;
    int valor_2 = 2;
    std::string saludo_1 = "Hola ";
    std::string saludo_2 = "mundo.";
    Pareja pareja_enteros(valor_1, valor_2);
    Pareja pareja_strings(saludo_1, saludo_2);
    pareja_enteros.mostrar();
    pareja_strings.mostrar();
}

// Ejercicio 5: Escribe una función template que invierta los elementos de un vector de cualquier tipo.
template <typename T>
void invertir_vector(std::vector<T>& vector) {
    T temp;
    int size = vector.size();
    for (int i = 0; i < size/2; i++) {
        temp = vector[i];
        vector[i] = vector[size - 1 - i];
        vector[size - 1 - i] = temp;
    }
}

void main_5() {
    std::vector<int> vector = {1, 2, 3, 4, 5};
    imprimir_elementos_vector(vector);
    invertir_vector(vector);
    imprimir_elementos_vector(vector);
}

// Ejercicio 6: Escribe una función template que calcule la suma de los elementos de un vector de cualquier tipo numérico.
template <typename T>
T suma_total(std::vector<T> vector) {
    T suma = 0;
    for (int i = 0; i < vector.size(); i++) {
        suma += vector[i];
    }
    return suma;
}

void main_6() {
    std::vector<int> vector_enteros = {1, 2, 3, 4, 5, 6};
    int suma = suma_total(vector_enteros);
    std::cout << "La suma total del vector ";
    imprimir_elementos_vector(vector_enteros);
    std::cout << " es " << suma << std::endl;
}

// Ejercicio 7: Escribe una función template que busque un elemento en un vector y devuelva su posición o -1 si no está.
template <typename T>
int buscar_posicion_elemento_vector(std::vector<T> vector, T elemento) {
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] == elemento) {
            return i;
        }
    }
    return -1;
}

void main_7() {
    std::vector<int> vector = {4, 3, 2, 7, 6, 5};
    int valor = 7;
    int posicion = buscar_posicion_elemento_vector(vector, valor);
    std::cout << "La posicion del elemento :" << valor << " en el vector ";
    imprimir_elementos_vector(vector);
    std::cout << "Es: " << posicion;
}

// Ejercicio 8: Escribe una función template que reciba dos vectores y devuelva un nuevo vector con los elementos comunes a ambos.
template <typename T>
std::vector<T> elementos_comunes(std::vector<T> vector_1, std::vector<T> vector_2) {
    std::vector<T> vector_coincidencias;
    std::set<T> coincidencias_sin_repeticion;
    for (int i = 0; i < vector_1.size(); i++) {
        for (int j = 0; j < vector_2.size(); j++) {
            if (vector_1[i] == vector_2[j]) {
                coincidencias_sin_repeticion.insert(vector_1[i]);
                continue;
            }
        }
    }
    for (T elemento : coincidencias_sin_repeticion) {
        vector_coincidencias.push_back(elemento);
    }
    return vector_coincidencias;
}

void main_8() {
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = {3, 4, 5, 6};
    std::vector<int> coincidencias = elementos_comunes(v1, v2);
    imprimir_elementos_vector(coincidencias);
}

// Ejercicio 9: Escribe una función template que reciba un valor y un número n, y devuelva un vector con n copias de ese valor.
template <typename T>
std::vector<T> n_plicar(T valor, int n) {
    std::vector<T> vector_copias;
    for (int i = 0; i < n; i++) {
        vector_copias.push_back(valor);
    }
    return vector_copias;
}

void main_9() {
    int valor = 1;
    int dimension = 6;
    std::vector<int> vector = n_plicar(valor, dimension);
    imprimir_elementos_vector(vector);
}

// Ejercicio 10: Escribe una clase template llamada Caja que almacene un solo valor y tenga métodos para establecerlo y obtenerlo.

int main() {
    main_9();
    return 0;
}