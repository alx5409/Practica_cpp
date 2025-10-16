#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <exception>

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
template <typename T>
T moda(std::vector<T> vector) {
    std::map<T, int> diccionario_T_contador;
    for (int i = 0; i < vector.size(); i++) {
        diccionario_T_contador[vector[i]] += 1;
    }
    int maximo = 0;
    T clave_maximo;
    for ( std::pair<T, int> clave_valor : diccionario_T_contador) {
        if (diccionario_T_contador[clave_valor.first] > maximo) {
            maximo = diccionario_T_contador[clave_valor.first];
            clave_maximo = clave_valor.first;
        }
    }
    return clave_maximo;
}

void main_3() {
    std::vector<int> vector = {1, 2, 3, 4, 5, 2, 3, 4, 6, 1, 2};
    int mod = moda(vector);
    std::cout << "El valor que más se repite es : " << mod << std::endl;
}

// Ejercicio 4: Escribe una clase template Pila que implemente una pila (stack) básica con métodos push, pop, top y empty.
template <typename T>
class Pila {
    std::vector<T> elementos;
public:
    // Método constructor
    Pila() = default;
    Pila(std::vector<T> pila) : elementos(pila) {}

    void pop() {
        if (elementos.empty()) {
            throw std::runtime_error("La pila está vacía.\n");
        }
        elementos.pop_back();
    }

    void push(T valor) {
        elementos.push_back(valor);
    }

    T top() const {
        if (elementos.empty()) {
            throw std::runtime_error("La pila está vacía.\n");
        }
        return elementos.back();
    }

    bool empty() const {
        return elementos.empty();
    }
};

void main_4() {
    Pila<int> pila;

    // Probar push
    pila.push(10);
    pila.push(30);

    std::cout << "Elemento superior (top): " << pila.top() << std::endl;

    // Probar pop
    pila.pop();
    std::cout << "Elemento superior tras pop: " << pila.top() << std::endl;

    // Probar empty
    pila.pop();
    std::cout << "¿La pila está vacía? " << (pila.empty() ? "Sí" : "No") << std::endl;

    // Probar excepción al hacer pop en pila vacía
    try {
        pila.pop();
    } catch (const std::exception& e) {
        std::cout << "Excepción capturada al hacer pop en pila vacía: " << e.what() << std::endl;
    }

    // Probar excepción al hacer top en pila vacía
    try {
        pila.top();
    } catch (const std::exception& e) {
        std::cout << "Excepción capturada al hacer top en pila vacía: " << e.what() << std::endl;
    }
}

// Ejercicio 5: Escribe una función template que reciba un mapa y devuelva un vector con todas sus claves.
template <typename T, typename U>
std::vector<T> claves_mapa(std::map<T, U> hash_map) {
    std::vector<T> keys_vector;
    for (std::pair<T, U> clave_valor: hash_map) {
        keys_vector.push_back(clave_valor.first);
    }
    return keys_vector;
}

void main_5() {
    std::map<std::string, int> ejemplo = {
        {"uno", 1},
        {"dos", 2},
        {"tres", 3}
    };
    std::vector<std::string> claves = claves_mapa(ejemplo);
    std::cout << "Claves del mapa: ";
    mostrar_vector(claves);
}

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
    main_5();
    return 0;
}