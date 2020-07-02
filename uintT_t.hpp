#pragma once

#include "iostream"
#include <bitset>
#include <string>

template <uint64_t T>
class uintT_t{
private:
    std::bitset<T> num;

public:
    uintT_t(uint_fast64_t arg){
        std::bitset<T> temp(arg);
        this->num = temp;
    }

    uintT_t(std::string str){
        this->num = 0;
        for (const auto& i : str){
            *this *= 10;
            *this += i - '0';
        }
    }

    std::bitset<T> Get(){return num;}
    void Set(std::bitset<T> arg){num = arg;}



    uintT_t& operator+=(std::bitset<T> rhs){
        uint64_t temp = 0;
        std::bitset<T> x(0);
        for (uint_fast64_t i = 0; i < T; i++){
            //std::cout << first[i] << " " << second[i] << " " << temp << std::endl;
            x[i] = (num[i] + rhs[i] + temp)%2;
            if (num[i] && rhs[i]) temp = (num[i] + rhs[i] + temp)/2;
            if (!num[i] && !rhs[i]) temp /= 2;
        }
        this->num = x;
        return *this;
    }

    uintT_t& operator+=(uintT_t rhs){
        *this += rhs.num;
        return *this;
    }

    uintT_t& operator+=(uint64_t rhs){
        std::bitset<T> temp(rhs);

        *this += temp;

        return *this;
    }

//    std::string to_dec_string(){
//
//    }



    uintT_t& operator*=(uint_fast64_t x){
        std::bitset<T> temp = this->Get();
        for (uint_fast64_t i = 1; i < x; i++){
            *this += temp;
        }
        return *this;
    }

//    uint_1024& operator= (const char* rhs){
//        std::string buffer(rhs);
//        uint_1024 temp(0);
//        for (uint_fast64_t i = 0; i < buffer.size(); i++){
//            std::bitset<1024> x(buffer[i] - '0');
//            std::cout << buffer[i] - '0' << std::endl;
//            temp += x;
//            temp *= 10;
//        }
//        return *this;
//    }

    friend std::ostream& operator<<(std::ostream& lhs, uintT_t& rhs){
        lhs << rhs.Get();
        return lhs;
    }

};


