#include <iostream>
#include <vector>
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

// Ejercicio 3: Escribe una función template que imprima los elementos de un vector de cualquier tipo.

// Ejercicio 4: Escribe una clase template llamada Pareja que almacene dos valores de tipos (posiblemente) diferentes y tenga un método para mostrarlos.

// Ejercicio 5: Escribe una función template que invierta los elementos de un vector de cualquier tipo.

// Ejercicio 6: Escribe una función template que calcule la suma de los elementos de un vector de cualquier tipo numérico.

// Ejercicio 7: Escribe una función template que busque un elemento en un vector y devuelva su posición o -1 si no está.

// Ejercicio 8: Escribe una función template que reciba dos vectores y devuelva un nuevo vector con los elementos comunes a ambos.

// Ejercicio 9: Escribe una función template que reciba un valor y un número n, y devuelva un vector con n copias de ese valor.

// Ejercicio 10: Escribe una clase template llamada Caja que almacene un solo valor y tenga métodos para establecerlo y obtenerlo.

int main() {
    main_1();
    return 0;
}