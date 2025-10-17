#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <exception>
#include <stdexcept>
#include <deque>

template <typename T>
void mostrar_vector(const std::vector<T>& vector) {
    for (size_t i = 0; i < vector.size(); ++i) {
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
template <typename T, typename U>
std::vector<U> valores_hash_map(std::map<T, U> hash_map) {
    std::vector<U> values_vector;
    for (std::pair<T, U> clave_valor: hash_map) {
        values_vector.push_back(clave_valor.second);
    }
    return values_vector;
}

void main_6() {
    std::map<std::string, int> ejemplo = {
        {"uno", 1},
        {"dos", 2},
        {"tres", 3}
    };
    std::vector<int> valores = valores_hash_map(ejemplo);
    std::cout << "Valores del mapa: ";
    mostrar_vector(valores);
}

// Ejercicio 7: Escribe una función template que reciba dos mapas y devuelva un nuevo mapa con la intersección de claves y sus valores correspondientes.
template <typename T, typename U>
std::map<T, std::pair<U, U>> interseccion_por_claves_mapas(const std::map<T, U>& hash_map_1,
                                                           const std::map<T, U>& hash_map_2) {
    std::map<T, std::pair<U, U>> interseccion;
    for (const auto& [clave_1, valor_1] : hash_map_1) {
        auto it = hash_map_2.find(clave_1);
        if (it != hash_map_2.end()) {
            interseccion.emplace(clave_1, std::make_pair(valor_1, it->second));
        }
    }
    return interseccion;
                                                           }

void main_7() {
    std::map<std::string,int> m1 = {
        {"uno", 1},
        {"dos", 2},
        {"tres", 3}
    };
    std::map<std::string,int> m2 = {
        {"dos", 20},
        {"tres", 30},
        {"cuatro", 40}
    };

    std::map<std::string, std::pair<int, int>> inter = interseccion_por_claves_mapas(m1, m2);

    std::cout << "Intersección (clave : (valor_en_m1, valor_en_m2))\n";
    for (const auto& [clave, valores] : inter) {
        std::cout << clave << " : (" << valores.first << ", " << valores.second << ")\n";
    }
}

// Ejercicio 8: Escribe una función template que reciba un vector y devuelva un set con los elementos únicos.
template <typename T>
std::set<T> quitar_duplicados(const std::vector<T>& vector) {
    std::set<T> conjunto;
    for (T elemento : vector) {
        conjunto.insert(elemento);
    }
    return conjunto;
}

template <typename T>
void mostrar_conjunto(const std::set<T>& conjunto) {
    std::cout << "[ ";
    for (T elemento : conjunto) {
        std::cout << elemento << " ";
    }
    std::cout << "]\n";
}

void main_8() {
    std::vector<int> vector_enteros = {1, 2, 3 , 4, 5, 1};
    std::set<int> conjunto;
    mostrar_vector(vector_enteros);
    conjunto = quitar_duplicados(vector_enteros);
    mostrar_conjunto(conjunto);
}

// Ejercicio 9: Escribe una clase template Cola que implemente una cola (queue) básica con métodos enqueue, dequeue, front y empty.
template <typename T>
class ArrayCircular {
    std::vector<T> buffer;
    size_t head = 0;
    size_t tail = 0;
    size_t count = 0;
    size_t max_size = 0;
public:
    explicit ArrayCircular(size_t capacity)
        : buffer(capacity), head(0), tail(0), count(0), max_size(capacity) {
        if (capacity == 0) throw std::invalid_argument("La capacidad debe ser > 0");
    }

    bool empty() const noexcept { return count == 0; }

    bool enqueue(const T& valor) {
        if (count == max_size) return false;
        buffer[tail] = valor;
        tail = (tail + 1) % max_size;
        ++count;
        return true;
    }

    bool dequeue() {
        if (empty()) return false;
        head = (head + 1) % max_size;
        --count;
        return true;
    }

    T& front() {
        if (empty()) throw std::out_of_range("La cola está vacía");
        return buffer[head];
    }
    const T& front() const {
        if (empty()) throw std::out_of_range("La cola está vacía");
        return buffer[head];
    }
};

void main_9() {
    ArrayCircular<int> cola(3);

    cola.enqueue(1);
    cola.enqueue(2);
    cola.enqueue(3);
    // Esta linea debe fallar
    cola.enqueue(4);

    std::cout << "Front: " << cola.front() << std::endl;
    cola.dequeue();
    std::cout << "Front tras dequeue: " << cola.front() << std::endl;

    cola.dequeue();
    cola.dequeue();
    std::cout << "¿La cola está vacía? " << (cola.empty() ? "Sí" : "No") << std::endl;

    // Probar la vuelta al array circular
    std::cout << "Probar vuelta:" << std::endl;
    cola.enqueue(10);
    cola.enqueue(20);
    cola.enqueue(30);
    cola.dequeue();
    cola.enqueue(40);

    while (!cola.empty()) {
        std::cout << "-> " << cola.front() << std::endl;
        cola.dequeue();
    }
}

// Ejercicio 10: Escribe una función template que reciba un vector y un predicado, y devuelva un nuevo vector con los elementos que cumplen el predicado.

// Ejercicio 11: Escribe una función template que reciba un vector y lo ordene usando un comparador pasado como parámetro.

// Ejercicio 12: Escribe una clase template ParOrdenado que almacene dos valores y tenga un método para intercambiarlos.

// Ejercicio 13: Escribe una función template que reciba un vector y devuelva el segundo valor más grande.

// Ejercicio 14: Escribe una función template que reciba un vector y devuelva true si está ordenado (ascendente o descendente).

// Ejercicio 15: Escribe una función template que reciba un vector y devuelva un mapa con la frecuencia de cada elemento.

int main() {
    main_9();
    return 0;
}