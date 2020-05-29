//
// Created by oleg on 30.05.2020.
//
#pragma once

#include <iostream>
#include <random>



class RSA{
private:
    uint_fast64_t key;

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
public:
    void Key_Generation(){
        key = this->Big_Random_Primal() * this->Big_Random_Primal();
    }
    //Только одну часть сделал.



    uint_fast64_t GetKey(){
        return key;
    };
};