#include <iostream>
#include "CustomRSA.hpp"

int main() {
    RSA key1;
    key1.Key_Generation();
    std::cout << key1.GetKey();

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
