#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctype.h>

// ===================== EJERCICIOS DE REVIEW BÁSICA =====================

// 1. Imprime "Hola Mundo" en pantalla.
void hola_mundo() {
    std::cout << "Hola mundo.\n";
}

void main_1() {
    hola_mundo();
}

// 2. Pide un número al usuario y muestra si es positivo, negativo o cero.
void entrada_basica() {
    float numero;
    std::cout << "Dame un número.\n";
    std::cin >> numero;
    std::cout << "El número que has puesto es: " << numero << std::endl;
    if (numero < 0) std::cout << "Es un número negativo.\n";
    else if (numero > 0) std::cout << "Es un número positivo.\n";
    else if(numero == 0) std::cout<< "Es cero.\n";
    else std::cout << "No es un número.\n";
}

void main_2() {
    entrada_basica();
}

// 3. Pide dos números y muestra el mayor.
void mostrar_mayor(int numero_1, int numero_2) {
    std::cout << "El número mayor es: ";
    if (numero_1 > numero_2) {
        std::cout << numero_1 << std::endl;
    } else {
        std::cout << numero_2 << std::endl;
    }
}

void main_3() {
    int numero_1, numero_2;
    std::cout << "Dame dos números.\n";
    std::cin >> numero_1;
    std::cin >> numero_2;
    mostrar_mayor(numero_1, numero_2);
}

// 4. Calcula la suma de los números del 1 al 100 usando un bucle.
int suma_hasta_numero(int numero) {
    int suma = 0;
    for (int i = 0; i <= numero; i++) {
        suma += i;
    }
    return suma;
}

void main_4() {
    int numero;
    std::cout << "Dame un número hasta el que quieres sumar.\n";
    std::cin >> numero;
    std::cout << "La suma hasta ese número es :" << suma_hasta_numero(numero)<< std::endl;
}
// 5. Pide un número y muestra su tabla de multiplicar del 1 al 10.
void tabla_multiplicar(int numero) {
    std::cout << "La tabla de multiplicar es: \n";
    for (int i = 1; i < 11; i++) {
        std::cout << i * numero << std::endl;
    }
}

void main_5() {
    int numero;
    std::cout << "Dame un úmero para mostrarte su tabla de multiplicar.\n";
    std::cin >> numero;
    tabla_multiplicar(numero);
}
// 6. Lee 5 números en un array y muestra su suma.
void mostrar_suma(int int_array[], int array_size) {
    int suma = 0;
    for (int i = 0; i < array_size; i++) {
        suma += int_array[i];
    }
    std::cout << "La suma de los elementos del array es " << suma << std::endl;
}

void main_6() {
    int int_array[5];
    std::cout << "Dame un array de 5 números enteros.\n";
    for (int i = 0; i < 5; i++) {
        std::cin >> int_array[i];
    }
    mostrar_suma(int_array, 5);
}
// 7. Lee 5 números en un vector y muestra el mayor.
void mostrar_mayor_vector(std::vector<int> int_vector) {
    int mayor = int_vector[1];
    for (int i = 0; i < int_vector.size(); i++) {
        if (int_vector[i] > mayor) {
            mayor = int_vector[i];
        }
    }
    std::cout << "El mayor número del vector es " << mayor << std::endl;
}

void main_7() {
    std::vector<int> int_vector;
    int vector_size = 5;  // tamaño del vector
    std::cout << "Dame un vector de 5 números enteros.\n";
    for (int i = 0; i < vector_size; i++) {
        int valor;
        std::cin >> valor; 
        int_vector.push_back(valor);
    }
    mostrar_mayor_vector(int_vector);
};
// 8. Invierte un array de 5 elementos.
void intercambiar_dos_numeros(int *numero_1, int *numero_2) {
    int temp = *numero_1;
    *numero_1 = *numero_2;
    *numero_2 = temp;
}
void invertir_array(int int_array[], int array_size) {
    for (int i = 0; i < array_size / 2; i++) {
        intercambiar_dos_numeros(&int_array[i], &int_array[array_size - i - 1]);
    }
}

void mostrar_int_array(int int_array[], int array_size) {
    std::cout << "[ ";
    for (int i = 0; i < array_size; i++) {
        std::cout << int_array[i] << " ";
    }
    std::cout << "]\n"; 
}

void main_8() {
    int int_array[5];
    std::cout << "Dame un array de 5 números enteros.\n";
    for (int i = 0; i < 5; i++) {
        std::cin >> int_array[i];
    }
    mostrar_int_array(int_array, 5);
    invertir_array(int_array, 5);
    mostrar_int_array(int_array, 5);
    
}
// 9. Comprueba si un número es primo.
void test_primalidad(int numero) {
    for (int i = 2; i < numero / 2; i++) {
        if ((numero % i) == 0) {
            std::cout << "El número es divisible por " << i << "\n"; 
            return;
        }
    }
    std::cout << "Es un número primo.\n";
}

int main_9() {
    int numero;
    std::cout << "Dame un número.\n";
    std::cin >> numero;
    test_primalidad(numero);
} 

// 10. Calcula el factorial de un número.
int factorial_recursivo(int numero) {
    if (numero <= 1) return numero;
    else return numero * factorial_recursivo(numero-1);
}

int factorial_dinamico(int numero) {
    int factorial = 1;
    for (int i = 1; i <= numero; i++) {
        factorial *= i;
    }
    return factorial;
}

void comparar_factoriales(int numero) {
    using namespace std::chrono;
    const int repeticiones = 100000; // Aumenta este valor si sigue saliendo 0

    // Medir tiempo recursivo
    auto start_rec = high_resolution_clock::now();
    int resultado_rec = 0;
    for (int i = 0; i < repeticiones; ++i)
        resultado_rec = factorial_recursivo(numero);
    auto end_rec = high_resolution_clock::now();
    auto duracion_rec = duration_cast<nanoseconds>(end_rec - start_rec).count();

    // Medir tiempo dinámico
    auto start_dyn = high_resolution_clock::now();
    int resultado_dyn = 0;
    for (int i = 0; i < repeticiones; ++i)
        resultado_dyn = factorial_dinamico(numero);
    auto end_dyn = high_resolution_clock::now();
    auto duracion_dyn = duration_cast<nanoseconds>(end_dyn - start_dyn).count();

    std::cout << "Recursivo: " << resultado_rec << " | Tiempo promedio: " << (duracion_rec / repeticiones) << " ns\n";
    std::cout << "Dinámico:  " << resultado_dyn << " | Tiempo promedio: " << (duracion_dyn / repeticiones) << " ns\n";
};

void main_10() {
    int numero;
    std::cout << "Dame un número: \n";
    std::cin >> numero;
    comparar_factoriales(numero);
}
// 11. Cuenta cuántas vocales hay en una cadena introducida por el usuario.
void introduce_cadena(std::string *cadena) {
    std::cout << "Introduce una cadena de caracteres.\n";
    std::cin >> *cadena;
};

void cuenta_vocales(std::string cadena) {
    std::string vocales = "aeiouAEIOU"; // parecido a un conjunto en python
    int contador = 0;
    for (char c: cadena) {
        if (vocales.find(c) != std::string::npos) { // si halla coindidencias suma el contador
            contador++;
        }
    }
    std::cout << "Hay " << contador << " vocales en la cadena.\n";
}

void main_11() {
    std::string cadena;
    introduce_cadena(&cadena);
    cuenta_vocales(cadena);
}
// 12. Crea una función que reciba dos números y devuelva el menor.
int menor_numero(int numero_1, int numero_2) {
    if (numero_1 < numero_2) return numero_1;
    else return numero_2;
}

void main_12() {
    int numero_1, numero_2;
    std::cout << "Dame dos números.\n";
    std::cin >> numero_1 >> numero_2;
    std::cout << "El número menor es " << menor_numero(numero_1, numero_2) << "\n";
}
// 13. Crea una estructura Persona con nombre y edad, y muestra sus datos.
struct Persona {
    std::string nombre;
    int edad;
};

void main_13() {
    Persona persona = {"Alex", 26};
    std::cout << "La persona se llama " << persona.nombre << " y tiene " << persona.edad << " años.\n";
}
// 14. Crea una clase Rectangulo con métodos para calcular área y perímetro.
class Rectangulo {
    float base;
    float altura;

public:
    Rectangulo(int b,int h) {
        base = b;
        altura = h;
    }

    float area() {
        return base * altura;
    }

    float perimetro() {
        return 2 * base + 2 * altura;
    }
};

void main_14() {
    Rectangulo rectangulo = {3, 5};
    std::cout << "El área del rectángulo es " << rectangulo.area() << " y el perímetro es " << rectangulo.perimetro() << "\n";
}
// 15. Implementa una función que intercambie dos variables usando referencias.
//definida como función intercambiar_dos_numeros

int main_15() {
    int numero_1 = 1, numero_2 = 2;
    std::cout << "El numero_1 tiene valor " << numero_1 << " y el numero_2 " << numero_2 << "\n";
    intercambiar_dos_numeros(&numero_1, &numero_2);
    std::cout << "El numero_1 tiene valor " << numero_1 << " y el numero_2 " << numero_2 << "\n";
}
// 16. Crea un array bidimensional 3x3 y muestra su diagonal principal.
void mostrar_diagonal(int matriz[3][3]) {
    for (int i = 0; i < 3; i++) {
        std::cout << matriz[i][i] << " ";
    }
}

void main_16() {
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    mostrar_diagonal(matriz);
}
// 17. Lee una cadena y muestra si es un palíndromo.
void palidromo_test(std::string cadena) {
    for (int i = 0; i < cadena.size() / 2; i++) {
        if (cadena[i] != cadena[cadena.size() - i - 1]) {
            std::cout << "No es un palíndromo.\n";
            return;
        }
    }
    std::cout << "Es un palíndromo.\n";
}

int main_17() {
    std::string cadena;
    std::cout << "Introduce una cadena para ver si es un palíndromo.\n";
    std::cin >> cadena;
    palidromo_test(cadena);
}
// 18. Usa un puntero para modificar el valor de una variable desde una función.
void sumar_unidad(int *numero) {
    *numero = *numero + 1;
}

int main_18() {
    int numero = 0;
    std::cout << "El número vale " << numero <<"\n";
    sumar_unidad(&numero);
    std::cout << "El número vale " << numero <<"\n";
}
// 19. Crea una función que reciba un vector y devuelva su media.
float media(std::vector<float> vector_float) {
    float suma = 0;
    for (int i = 0; i < vector_float.size(); i++) {
        suma += vector_float[i];
    }
    return suma / vector_float.size();
}

void main_19() {
    std::vector<float> vector_float;
    int size;

    std::cout << "De qué tamaño quieres el vector?\n";
    std::cin >> size;
    std::cout << "Dame el vector de tamaño " << size << "\n";
    for (int i = 0; i < size; i ++) {
        float valor;
        std::cin >> valor;
        vector_float.push_back(valor);
    }
    std::cout << "La media del vector es " << media(vector_float) << std::endl;
}
// 20. Maneja una excepción al intentar dividir por cero.
float division(float numerador, float denominador) {
    if (denominador == 0) {
        throw std::runtime_error("Error: Division por 0 no permitida.");
    }
    return numerador / denominador;
}

void main_20() {
    float numerador = 1, denominador = 0;
    float cociente;
    cociente = division(numerador, denominador);
}
// 21. Crea una función que reciba un array y devuelva el número de elementos pares.
int contar_pares_en_array(int array[], int array_size){
    int contador = 0;
    for (int i = 0; i < array_size; i++) {
        if ((array[i] % 2) == 0) {
            contador += 1;
        }
    }
    return contador;
}

void main_21() {
    int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int array_size = sizeof(array) / sizeof(array[0]); // sizeof devuelve el tamaño en bytes
    std::cout << "El array tiene " << contar_pares_en_array(array, array_size) << " elementos pares.\n";
}
// 22. Implementa una función recursiva para calcular la suma de los primeros N números naturales.
int suma_recursiva(int n) {
    if (n <= 0) {
        return 0;
    } else {
        return n + suma_recursiva(n - 1);
    }
}

void main_22() {
    int n = 100;
    int suma;
    suma = suma_recursiva(n);
    std::cout << "La suma de los "<< n << " primeros números es: " << suma << "\n";
}
// 23. Crea una clase CuentaBancaria con métodos para depositar y retirar dinero.
class CuentaBancaria {
public:
    int id_cuenta;
    std::string nombre_titular;
    float saldo;
    std::string tipo_cuenta;
    void depositar(float cantidad) {
        saldo += cantidad;
    } 

    void retirar(float cantidad) {
        saldo -= cantidad;
    }

    void mostrar_saldo() {
        std::cout << "Hay " << saldo << " en la cuenta.\n";
    }
};

void main_23() {
    CuentaBancaria cuenta;
    cuenta.saldo = 1000;
    cuenta.mostrar_saldo();
    cuenta.depositar(10);
    cuenta.mostrar_saldo();
    cuenta.retirar(10);
    cuenta.mostrar_saldo();
}
// 24. Lee 10 números y muestra cuántos son mayores que la media.
float media_float_array(float float_array[], int array_size) {
    float suma = 0;
    for (int i = 0; i < array_size; i++) {
        suma += float_array[i];
    }
    return suma / array_size;
}

void mostrar_mayores_que_media(float float_array[], int array_size) {
    float media;
    media = media_float_array(float_array, array_size);
    for (int i = 0; i < array_size; i++) {
        if (float_array[i] > media) {
            std::cout << float_array[i] << " ";
        }
    }
}

void main_24() {
    float float_array[10];
    int array_size = sizeof(float_array) / sizeof(float_array[0]);
    std::cout << "Dame 10 valores para el array.\n";
    for (int i = 0; i < array_size; i++) {
        std::cin >> float_array[i];
    }
    mostrar_mayores_que_media(float_array, array_size);
}
// 25. Implementa una función que reciba una cadena y la convierta a mayúsculas.
void cadena_a_mayusculas(std::string *cadena) {
    for (char &c: *cadena) {
        c = std::toupper(c);
    }
}

int main_25() {
    std::string cadena;
    std::string cadena_mayuscula;
    std::cout << "Dame una cadena.\n";
    std::cin >> cadena;
    cadena_a_mayusculas(&cadena);
    std::cout << "La cadena a mayúsculas es: " << cadena << "\n";
}
// ===================== MAIN DE PRUEBA =====================

int main() {
    main_25();
    return 0;
}