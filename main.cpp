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
    const uint64_t uint_size = 20;
//    RSA key1;
//    key1.Key_Generation();
//    std::cout << key1.Get_private_Key().first;
//    key1.Test();
    uintT_t<uint_size> x("12");
    uintT_t<uint_size> y;
    uintT_t<uint_size> z;

    x = "1234";
//    y = "9999999";
    std::cout << "!" << y << std::endl;
    y = "4";
    z = "2";
    //std::cout << x << std::endl << y << std::endl << "------------------------------------------" << std::endl;

    //x -= y;

    //std::cout << x << std::endl;

    //x*= 8134135361346646;

    //x/= z;

//    std::cout << "\n!!!!" << x;


//    std::cout << "\n" << x << "\n";

//    x%= z;

//    uint_T<uint_size> g(117);

    uint_fast64_t g = 55;

//    for (uint_fast64_t i = 0; i < 1000; i++) {
//
//        std::cout << std::endl << y.ToString();
//        y *= z;
//    }
    y = "1024";
    z = "10";
//    y %= z;
    y /= z;
    std::cout << y.ToString();
    //std::cout << (x <= y) << std::endl << (x >= y);

    //std::cout << (x > y) << " " << (x >= y) << " " << (x <= y) << " " << (x == y) << " " << (x != y) << " " << (x >= z) << " " << (y <= z)
    //<< " " << (x >= z) << " " << (z > z) << " " << (z < y);

    //std::bitset<10> a(7);
    //std::bitset<10> b(17);
    //std::bitset<10> c(0);


    //std::cout << x << std::endl << y << std::endl;
    //x *= 11;
    //std::cout << x;

    //c = Add(a, b);

    //std::cout << a << std::endl << b << std::endl << c;



    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
