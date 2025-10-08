#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <memory>
#include <stack>
#include <queue>
#include <array>
// ===================== EJERCICIOS DE REVIEW INTERMEDIA =====================

// 1. Usa std::set para guardar números únicos introducidos por el usuario.
// 2. Implementa una función que reciba un std::vector y elimine los elementos duplicados.
std::vector<int> obtener_numeros() {
    int cantidad_numeros;
    std::vector<int> numeros;

    std::cout << "Cuántos números quieres introducir?\n";
    std::cin >> cantidad_numeros;
    std::cout << "Dame " << cantidad_numeros << " números.\n";
    for (int i = 0; i < cantidad_numeros; i++) {
        int valor;
        std::cin >> valor;
        numeros.push_back(valor);
    }
    return numeros;
}

std::set<int> eliminar_duplicados(std::vector<int>& int_vector) {
    std::set<int> vector_sin_duplicados(int_vector.begin(), int_vector.end());
    return vector_sin_duplicados;
}

void main_1() {
    std::vector<int> numeros;
    std::set<int> numeros_sin_duplicados;
    numeros = obtener_numeros();
    numeros_sin_duplicados = eliminar_duplicados(numeros);
    std::cout << "El vector sin duplicados y en orden es: [ ";
    for (auto it = numeros_sin_duplicados.begin(); it!= numeros_sin_duplicados.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << " ]";
}

// 3. Crea un programa que ordene un std::vector de strings alfabéticamente usando std::sort.
std::vector<char> guarda_vector_caracteres() {
    std::vector<char> char_vector;
    int cantidad;
    std::cout << "Cuantos caracteres quieres escribir?\n";
    std::cin >> cantidad;
    std::cout << "Dame " << cantidad << " carateres.\n";
    for (int i = 0; i < cantidad; i++) {
        char valor;
        std::cin >> valor;
        char_vector.push_back(valor);
    }
    return char_vector;
}

void ordena_alfabeticamente_vector(std::vector<char>& char_vector) {
    std::sort(char_vector.begin(), char_vector.end());
}

void main_3() {
    std::vector<char> char_vector;
    char_vector = guarda_vector_caracteres();
    ordena_alfabeticamente_vector(char_vector);
    std::cout << "El vector de caracteres ordenado es < ";
    for (int i = 0; i < char_vector.size(); i++) {
        std::cout << char_vector[i] << " ";
    }
    std::cout << " >\n";
}

// 4. Lee una cadena y cuenta cuántas veces aparece cada letra usando std::map.
std::string guardar_cadena() {
    std::string cadena;
    std::cout << "Escribe una cadena de caracteres.\n";
    std::cin >> cadena;
    return cadena;
}

std::map<char, int> dicionario_letra_contador(std::string cadena) {
    std::map<char, int> diccionario;
    for (char c: cadena) {
        diccionario[c]++;   // cada vez que encuentra la letra c una vez incrementa el valor de la clave c
    }
    return diccionario;
}

void main_4() {
    std::string cadena;
    std::set<char> letras;
    std::map<char, int> diccionario;

    cadena = guardar_cadena();
    diccionario = dicionario_letra_contador(cadena);
    for (const auto& par: diccionario) {
        std::cout << "Letra: " << par.first << ", Cantidad: " << par.second << "\n";
    }
}

// 5. Implementa una función que reciba un puntero a int y lo incremente.
void incrementar_puntero(int *pint) {
    *pint = 1 + *pint;
}

void main_5() {
    int numero = 1;
    int *pint = &numero;
    std::cout << "El valor antes de la función es :" << numero << "\n";
    incrementar_puntero(pint);
    std::cout << "El valor después de la función es :" << numero << "\n";
}

// 6. Crea un array dinámico usando new y libera la memoria con delete.
void crear_liberar() {
    int *pint = new int;
    *pint = 10;
    std::cout << "El puntero apunta a una dirección " << pint << " que guarda el valor: " << *pint << "\n";
    delete pint;
    std::cout << "Se ha liberado la memoria.\n";
}
void main_6() {
    crear_liberar();
}

// 7. Implementa una función que reciba un puntero doble (int**) y modifique una matriz.
void modificar_matriz(int **matriz, const int dimension_matriz) {
    //suma la matriz identidad
    for (int i = 0; i < dimension_matriz; i++) {
        matriz[i][i]++;
    }
}

void mostrar_matriz(int **matriz, const int dimension_matriz) {
    for (int i = 0; i < dimension_matriz; i++) {
        std::cout << "\n";
        for (int j = 0; j < dimension_matriz; j++) {
            std::cout << matriz[i][j] << " ";
        }
    }
    std::cout << "\n";
}

void main_7() {
    int dimension_matriz;
    std::cout << "De qué dimension quieres la matriz?\n";
    std::cin >> dimension_matriz;
    int **matriz = new int*[dimension_matriz];
    for (int i = 0; i < dimension_matriz; i++) {
        matriz[i] = new int[dimension_matriz];
        for (int j = 0; j < dimension_matriz; j++) {
            matriz[i][j] = std::rand() %100;
        }
    }
    std::cout << "La matriz antes de modificarse es: \n";
    mostrar_matriz(matriz, dimension_matriz);
    modificar_matriz(matriz, dimension_matriz);
    std::cout << "La matriz después de modificarse es: \n";
    mostrar_matriz(matriz, dimension_matriz);

    //liberar memoria
    for (int i = 0; i < dimension_matriz; i++) {
        delete [] matriz[i];
    }
    delete[] matriz;
}
// 8. Usa std::unique_ptr para gestionar la memoria de un objeto.
void crear_unico() {
    std::unique_ptr<int> pint = std::make_unique<int>(10);
    std::cout << *pint << std::endl;
}

void main_8() {
    crear_unico();
}

// 9. Crea una clase con un constructor que lance una excepción si recibe un valor negativo.
class Excepcion {
public:
    int valor;

    Excepcion(int value) {
        if (value < 0) {
            throw std::invalid_argument("Error al construir, el valor que has introducido es negativo.\n");
        } else {
            valor = value;
        }
    }
};

void main_9() {
    int value;
    std::cout << "Dame un número.\n";
    std::cin >> value;
    Excepcion excepcion(value);
}

// 10. Implementa una función que reciba un std::vector por referencia y lo modifique.
void modificar_vector(std::vector<int>& int_vector) {
    int_vector.push_back(1);
}

void mostrar_vector(const std::vector<int> int_vector) {
    for (int i = 0; i < int_vector.size(); i++) {
        std::cout << int_vector[i] << " ";
    }
    std::cout << std::endl;
}

void main_10() {
    std::vector<int> int_vector = {1, 2, 3};
    std::cout << "El vector antes de usar la funcion es: ";
    mostrar_vector(int_vector);
    modificar_vector(int_vector);
    std::cout << "El vector después de usar la funcion es: ";
    mostrar_vector(int_vector);
}

// 11. Crea una función que devuelva un std::pair con el mínimo y máximo de un vector.
std::pair<int, int> min_y_max(std::vector<int> int_vector) {
    int min = int_vector[0];
    int max = int_vector[0];

    for (int i = 0; i < int_vector.size(); i++) {
        if (min > int_vector[i]) {
            min = int_vector[i];
        }
        if (max < int_vector[i]) {
            max = int_vector[i];
        }
    }
    return std::pair<int, int> {min, max};
}

void main_11() {
    std::vector<int> int_vector = {1, 3, 4, 2};
    std::pair<int, int> min_max = min_y_max(int_vector);
    std::cout << "El minimo del vector es " << min_max.first << " y el maximo es " << min_max.second << std::endl;
}

// 12. Usa std::stack para invertir una cadena de texto.
void invertir_string(std::string &cadena) {
    std::stack<char> stack_cadena;
    for (int i = 0; i < cadena.size(); i++) {
        stack_cadena.push(cadena[i]);
    }
    for (int i = 0; i < cadena.size(); i++) {
        cadena[i] = stack_cadena.top();
        stack_cadena.pop();
    }
}

void main_12() {
    std::string cadena;
    std::stack<char> cadena_invertida;
    std::cout << "Introduce una cadena de texto.\n";
    std::cin >> cadena;
    std::cout << "La cadena antes de invertir la cadena es :" << cadena << std::endl;
    invertir_string(cadena);
    std::cout << "La cadena después de invertir la cadena es :" << cadena;
}
// 13. Implementa una función que reciba un std::queue y muestre sus elementos.
void mostrar_cola(std::queue<int> cola) {
    while(!cola.empty()){
        int valor_popeado = cola.front();
        std::cout << valor_popeado << " ";
        cola.pop();
    }
}

void main_13() {
    std::queue<int> cola;
    int cola_size;
    std::cout << "De qué tamaño quieres la cola\n";
    std::cin >> cola_size;
    while (cola.size() < cola_size){
        int valor;
        std::cout << "Dame un numero: \n";
        std::cin >> valor;
        cola.push(valor);
    }
    mostrar_cola(cola);
}
// 14. Crea una función que reciba un std::array y calcule la suma de sus elementos.
int suma_array(const std::array<int, 4>& int_array) {
    int suma = 0;
    for (int i = 0; i < int_array.size(); i++){
        suma += int_array[i];
    }
    return suma;
}

void main_14() {
    std::array int_array = {1, 2, 3, 4};
    int suma;
    suma = suma_array(int_array);
    std::cout << "La suma es: " << suma << std::endl;
}
// 15. Implementa una función que reciba un std::string y devuelva una versión sin espacios.
std::string quitar_espacios(std::string cadena) {
    std::string cadena_sin_espacios;
    for (char c : cadena) {
        if (c != ' ') {
            cadena_sin_espacios += c;
        }
    }
    return cadena_sin_espacios;
}

void main_15() {
    std::string cadena;
    std::string cadena_sin_espacios;
    std::cout << "Dame una cadena de caracteres.\n";
    std::getline(std::cin, cadena);
    cadena_sin_espacios = quitar_espacios(cadena);
    std::cout << " La cadena sin espacios es " << cadena_sin_espacios << std::endl;

}
// 16. Usa std::getline para leer una línea completa de texto con espacios.
void main_16() {
    std::string cadena_con_espacios;
    std::cout << "Dame una cadena de caracteres.\n";
    std::getline(std::cin,  cadena_con_espacios);
    std::cout << "La cadena que has introducido es: \n" << cadena_con_espacios;
}
// 17. Implementa una función que reciba un std::vector y lance una excepción si está vacío.
void comprobar_vector_vacio(std::vector<int> int_vector) {
    if (int_vector.empty()) {
        throw std::runtime_error("El vector esta vacío.\n");
    }
    std::cout << "El vector no esta vacio.\n";
}

void main_17() {
    std::vector<int> vector_vacio;
    std::vector<int> vector_no_vacio = {1, 2, 3};
    comprobar_vector_vacio(vector_vacio);
    comprobar_vector_vacio(vector_no_vacio);
}
// 18. Crea una clase con atributos privados y métodos públicos para acceder y modificar esos atributos.
class Publico_y_privado {
    int numero_privado;
    std::string cadena_privada;

    void imprime_cadena_y_numero_privado() {
        std::cout << "El número privado es: " << numero_privado << std::endl;
        std::cout << "La cadena privada es: " << cadena_privada << std::endl;
    }

public:
    int numero_publico;
    std::string cadena_publica;

    // Constructor de la clase, siempre es publico
    Publico_y_privado(int numero, std::string cadena) {
        numero_publico = numero;
        cadena_publica = cadena;

        numero_privado = numero_publico - 1;
        cadena_privada = quitar_espacios(cadena_publica);
    }

    void imprime_cadena_y_numero_publico() {
    std::cout << "El número publico es: " << numero_publico << std::endl;
    std::cout << "La cadena publica es: " << cadena_publica << std::endl;
    }
};

void main_18() {
    int numero = 3;
    std::string cadena = "Hola, qué tal?";
    Publico_y_privado publico_privado(numero, cadena);
    publico_privado.imprime_cadena_y_numero_publico();
}

// 19. Implementa una función que reciba un puntero constante a int y muestre su valor.
void mostrar_contenido_puntero(const int *p_int) {
    std::cout << "El valor de la variable a la que apunta el puntero es: " << *p_int << std::endl;
}

void main_19() {
    int numero = 5;
    int *p_int = &numero;
    mostrar_contenido_puntero(p_int);
}

// 20. Crea una función que reciba un std::vector de punteros y libere su memoria.
// 21. Usa std::find para buscar un elemento en un vector y mostrar su posición.
// 22. Implementa una función que reciba un std::vector y lo ordene en orden descendente.
// 23. Crea una función que reciba un std::map y muestre todas sus claves y valores.
// 24. Implementa una función que reciba un std::vector y elimine todos los elementos menores que un valor dado.
// 25. Crea una clase que gestione errores usando try-catch en sus métodos.

int main() {
    main_19();
    return 0;
}