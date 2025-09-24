#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2};
    
    std::cout << "Elementos del vector: ";
    for (const auto& elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
