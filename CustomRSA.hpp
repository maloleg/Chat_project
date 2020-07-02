//
// Created by oleg on 30.05.2020.
//
#pragma once

#include <iostream>
#include <random>
#include <math.h>
#include "uint256_t.h"

struct Key{
    uint_fast64_t first;
    uint_fast64_t second;
};



class RSA{
private:
    Key _public;
    Key _private;

    bool Is_Primal(uint_fast64_t number){
        bool check = true;
        for (uint_fast64_t i = 2; i * i < number; i++){
            if (number % i == 0){
                check = false;
                break;
                std::cout << i << " ";
            }
        }
        //std::cout << number << " " << check << std::endl;

        return check;
    }

    bool Is_Big(uint_fast64_t number){
        //std::cout << number << " " <<(number > 1048576 && number < 4294967296) << std::endl;
        return (number > 1048576 && number < 4294967296);
    }

    uint_fast64_t Big_Random_Primal(){
        uint_fast64_t temp = 0;
        std::random_device rd;
        std::mt19937 mersenne(rand());
        //std::cout << mersenne();

        while (1){
            temp = mersenne();
            //std::cout << temp << "\n";
            if (Is_Primal(temp) && Is_Big(temp)){
                //std::cout << temp << std::endl;
                break;

            }

        }
        return temp;
    }

    uint_fast64_t Euclidean_algorithm(uint_fast64_t first, uint_fast64_t second){
        while (first != second){
            if (first > second){
                first -= (second);
            }
            else{
                second -= (first);
            }
        }
        return first;
    }

    uint_fast64_t Eulers_totient_function(uint_fast64_t number){
        uint_fast64_t count = 0;

        for (uint_fast64_t i = 1; i < number; i++){
            if (Euclidean_algorithm(i, number) == 1){
                count++;
            }
        }
        return count;
    }
    uint_fast64_t Eulers_totient_function(uint_fast64_t FirstPrimal, uint_fast64_t SecondPrimal){
        return (FirstPrimal - 1) * (SecondPrimal - 1);
    }

    uint256_t Inverse(uint_fast64_t number, uint_fast64_t mod){ //Написал полную дичь, надо переписать.
        uint256_t temp = 1;

        for (uint_fast64_t i = 0; i < (Eulers_totient_function(mod) - 1); i++){
            temp *= number;
           // std::cout << temp <<std::endl;
        }
        return temp;

        //std::cout << temp << " " << Eulers_totient_function(mod) - 1 << " " << pow(number, (Eulers_totient_function(mod) - 1));
    }

public:
    void Key_Generation(){
        uint_fast64_t a = this->Big_Random_Primal();
        uint_fast64_t b = this->Big_Random_Primal();
        uint_fast64_t temp = Big_Random_Primal();

        _private.second = a * b;
        _public.second = a * b;

//        while (Euclidean_algorithm(temp, Eulers_totient_function(a, b) != 1)){
//            temp = Big_Random_Primal();
//        }

        _public.first = temp;
        //_private.first = Inverse(temp, a * b);
    }

    void Test(){
        std::cout << Eulers_totient_function(52) << std::endl;
        std::cout << pow(123, Eulers_totient_function(52) - 1) << std::endl;
        std::cout << this->Inverse(123234234343423423, 52342);
    }



    Key Get_public_Key(){
        return _public;
    };

    Key  Get_private_Key(){
        return _private;
    }
};