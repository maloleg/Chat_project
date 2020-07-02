#include <iostream>
#include "CustomRSA.hpp"
#include "uintT_t.hpp"

template <uint_fast64_t T>
std::bitset<T> Add(std::bitset<T> first, std::bitset<T> second){
    uint64_t temp = 0;
    std::bitset<T> x(0);
    for (uint_fast64_t i = 0; i < T; i++){
        //std::cout << first[i] << " " << second[i] << " " << temp << std::endl;
        x[i] = (first[i] + second[i] + temp)%2;
        if (first[i] && second[i]) temp = (first[i] + second[i] + temp)/2;
        if (!first[i] && !second[i]) temp /= 2;
    }
    return x;
}

int main() {
//    RSA key1;
//    key1.Key_Generation();
//    std::cout << key1.Get_private_Key().first;
//    key1.Test();
    uintT_t<200> x("12");
    uintT_t<200> y(524542489288468442);

    //std::bitset<10> a(7);
    //std::bitset<10> b(17);
    //std::bitset<10> c(0);


    std::cout << x << std::endl << y << std::endl;
    x *= 11;
    std::cout << x;

    //c = Add(a, b);

    //std::cout << a << std::endl << b << std::endl << c;



    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
