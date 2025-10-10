#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

template <typename T>
void mostrar_vector(std::vector<T> vector) {
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

// Ejercicio 1: Escribe una función template que reciba dos vectores y devuelva un vector con la unión de ambos (sin duplicados).
template <typename T>
std::vector<T> unir_vectores(std::vector<T> vector_1, std::vector<T> vector_2) {
    std::set<T> elementos_sin_duplicados;
    std::vector<T> vector_union;
    for (int i = 0; i < vector_1.size(); i++) {
        elementos_sin_duplicados.insert(vector_1[i]);
    }
    for (int i = 0; i < vector_2.size(); i++) {
        elementos_sin_duplicados.insert(vector_2[i]);
    }
    for (T elemento : elementos_sin_duplicados) {
        vector_union.push_back(elemento);
    }
    return vector_union;
}

void main_1() {
    std::vector<int> vector_1 = {1, 2, 3, 4};
    std::vector<int> vector_2 = {4, 6, 2, 9};
    std::vector<int> vector_union = unir_vectores(vector_1, vector_2);
    mostrar_vector(vector_union);
}

// Ejercicio 2: Escribe una función template que reciba un vector y un valor, y elimine todas las apariciones de ese valor del vector.
template <typename T>
void eliminar_duplicados(std::vector<T>& vector, T valor) {
    int i = 0;
    vector.erase(
        std::remove(vector.begin(), vector.end(), valor),
        vector.end()
    );
}

void main_2() {
    std::vector<int> vector = { 1, 2, 3, 2, 1, 5, 6};
    int valor = 2;
    mostrar_vector(vector);
    eliminar_duplicados(vector, valor);
    mostrar_vector(vector);
}

// Ejercicio 3: Escribe una función template que reciba un vector y devuelva el elemento más frecuente.

// Ejercicio 4: Escribe una clase template Pila que implemente una pila (stack) básica con métodos push, pop, top y empty.

// Ejercicio 5: Escribe una función template que reciba un mapa y devuelva un vector con todas sus claves.

// Ejercicio 6: Escribe una función template que reciba un mapa y devuelva un vector con todos sus valores.

// Ejercicio 7: Escribe una función template que reciba dos mapas y devuelva un nuevo mapa con la intersección de claves y sus valores correspondientes.

// Ejercicio 8: Escribe una función template que reciba un vector y devuelva un set con los elementos únicos.

// Ejercicio 9: Escribe una clase template Cola que implemente una cola (queue) básica con métodos enqueue, dequeue, front y empty.

// Ejercicio 10: Escribe una función template que reciba un vector y un predicado, y devuelva un nuevo vector con los elementos que cumplen el predicado.

// Ejercicio 11: Escribe una función template que reciba un vector y lo ordene usando un comparador pasado como parámetro.

// Ejercicio 12: Escribe una clase template ParOrdenado que almacene dos valores y tenga un método para intercambiarlos.

// Ejercicio 13: Escribe una función template que reciba un vector y devuelva el segundo valor más grande.

// Ejercicio 14: Escribe una función template que reciba un vector y devuelva true si está ordenado (ascendente o descendente).

// Ejercicio 15: Escribe una función template que reciba un vector y devuelva un mapa con la frecuencia de cada elemento.

int main() {
    main_2();
    return 0;
}