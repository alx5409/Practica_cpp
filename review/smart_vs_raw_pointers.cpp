#include <iostream>
#include <memory>
#include <vector>

// ===================== EJERCICIOS DE PUNTEROS INTELIGENTES VS PUNTEROS NORMALES =====================

// 1. Reserva memoria para un entero usando un puntero normal y libera la memoria manualmente.
void main_1() {
    int *pint = new int;
    *pint = 10;
    std::cout << *pint << std::endl;
    delete pint;
}

// 2. Reserva memoria para un entero usando std::unique_ptr y muestra su valor.
void main_2() {
    int numero = 10;
    std::unique_ptr<int> pint = std::make_unique<int>(numero);
    std::cout << *pint << std::endl;
}

// 3. Crea un array dinámico de 5 enteros con punteros normales y libera la memoria correctamente.
void main_3() {
    int *pint_array = new int[5];
    for (int i = 0; i < 5; i++) {
        pint_array[i] = i;
        std::cout << pint_array[i] << std::endl;
    }
    delete[] pint_array;
}

// 4. Crea un array dinámico de 5 enteros usando std::unique_ptr.
void main_4() {
    std::unique_ptr<int[]> pint_array = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; i++) {
        pint_array[i] = i;
        std::cout << pint_array[i] << std::endl;
    }
}

// 5. Crea una clase Persona y reserva memoria para un objeto usando un puntero normal, luego libera la memoria.
class Persona {
public:
    std::string nombre;
    int edad;
    Persona(std::string nom = "Nadie", int ed = 10) {
        nombre = nom;
        edad = ed;
    }

    void saludar() {
        std::cout << "Hola, soy " << nombre << " y tengo " << edad << " años\n";
    }
};

void main_5() {
    Persona *ppersona = new Persona;
    std::cout << "Introduce el nombre y la edad.\n";
    std::cin >> ppersona->nombre >> ppersona->edad;
    ppersona->saludar();
    delete ppersona;
}

// 6. Reserva memoria para un objeto Persona usando std::shared_ptr y muestra sus atributos.
void main_6() {
    std::shared_ptr<Persona> ppersona = std::make_shared<Persona>("Alex", 26);
    ppersona->saludar();
}
// 7. Crea una función que reciba un std::unique_ptr<int> y modifique el valor apuntado.
void resta_uno(std::unique_ptr<int>& pnumero) {
    *pnumero = *pnumero - 1;
}

void main_7() {
    int numero = 1;
    std::unique_ptr<int> pnumero = std::make_unique<int>(numero);
    std::cout << "Valor del numero antes de llamar a la función: " << *pnumero << std::endl;
    resta_uno(pnumero);
    std::cout << "Valor del numero despues de llamar a la función: " << *pnumero << std::endl;
}

// 8. Crea una función que reciba un puntero normal a int y modifique el valor apuntado.
void resta_uno_normal(int *pnumero) {
    *pnumero = *pnumero - 1;
}

void main_8() {
    int numero = 1;
    int *pnumero = new int(numero);
    std::cout << "Valor del numero antes de llamar a la función: " << *pnumero << std::endl;
    resta_uno_normal(pnumero);
    std::cout << "Valor del numero despues de llamar a la función: " << *pnumero << std::endl;
}

// 9. Crea un vector de punteros normales a objetos Persona y libera la memoria de todos los objetos.
void main_9() {
    std::vector<Persona*> ppersona_vector;
    ppersona_vector.push_back(new Persona("Alex", 26));
    for (Persona* p: ppersona_vector) {
        delete p;
    }
    std::cout << "Se ha liberado la memoria.\n";
}
// 10. Crea un vector de std::shared_ptr<Persona> y muestra los nombres de todas las personas.
void main_10() {
    std::vector<std::shared_ptr<Persona>> ppersona_vector;
    ppersona_vector.push_back(std::make_shared<Persona>("Alex", 26));
    ppersona_vector.push_back(std::make_shared<Persona>("Ana", 27));
    for (const auto&p : ppersona_vector) {
        p->saludar();
    }
}

// 11. Implementa una función que transfiera la propiedad de un std::unique_ptr entre dos variables.
void trasferir_propiedad(int variable_1, int variable_2, std::unique_ptr<int> pint) {
    
}

void main_10() {
    int numero = 1;
    std::unique_ptr<int> pint = std::make_unique<int>(numero);
}
// 12. Implementa una función que intente copiar un std::unique_ptr y explica el error que ocurre.
// 13. Crea una función que reciba un std::shared_ptr y muestre el contador de referencias.
// 14. Crea una función que reciba un puntero normal y explique los riesgos de acceso a memoria liberada.
// 15. Crea una clase con un método que devuelva un std::unique_ptr a un objeto creado dentro de la clase.
// 16. Crea una función que reciba un std::weak_ptr y verifique si el objeto aún existe.
// 17. Crea una función que reciba un std::shared_ptr y lo comparta entre varias variables.
// 18. Crea una función que reciba un std::unique_ptr y lo pase a otra función usando std::move.
// 19. Crea una función que reciba un puntero normal y lo pase a otra función.
// 20. Compara el uso de memoria y seguridad entre punteros normales y punteros inteligentes en un ejemplo simple.

int main() {
    main_10();
    return 0;
}