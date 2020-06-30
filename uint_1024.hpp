#pragma once

#include "iostream"
#include <bitset>

class uint_1024{
private:
    std::bitset<1024> num;

public:
    uint_1024(uint_fast64_t arg){
        std::bitset<1024> temp(arg);
        num = temp;
    }

    std::bitset<1024> Get(){return num;}
    void Set(std::bitset<1024> arg){num = arg;}

    uint_1024& operator+=(std::bitset<1024> rhs){
        uint64_t temp = 0;
        for (uint_fast64_t i = 1023; i >= 0; i--){
            if (rhs[i] == 1 && this->num[i] == 0){
                this->num[i] = 1;
            }

            if (rhs[i] == 0 && this->num[i] == 1){
                this->num[i] = 1;
            }

            if (rhs[i] == 1 && this->num[i] == 1){
                this->num[i] = 1;
                temp += 1;
            }

            if (rhs[i] == 0 && this->num[i] == 0){
                if (temp > 0){
                    this->num[i] = 1;
                    temp -= 1;
                }
            }
        }
        return *this;
    }

    uint_1024& operator+=(uint_1024 rhs){
        uint64_t temp = 0;
        for (uint_fast64_t i = 1023; i >= 0; i--){
            if (rhs.num[i] == 1 && this->num[i] == 0){
                this->num[i] = 1;
            }

            if (rhs.num[i] == 0 && this->num[i] == 1){
                this->num[i] = 1;
            }

            if (rhs.num[i] == 1 && this->num[i] == 1){
                this->num[i] = 1;
                temp += 1;
            }

            if (rhs.num[i] == 0 && this->num[i] == 0){
                if (temp > 0){
                    this->num[i] = 1;
                    temp -= 1;
                }
            }
        }
        return *this;
    }

    uint_1024& operator*=(uint_fast64_t x){
        std::bitset<1024> temp = this->Get();
        for (uint_fast64_t i = 0; i < x; i++){
            *this += temp;
        }
        return *this;
    }

    uint_1024& operator= (const char* rhs){
        std::string buffer(rhs);
        uint_1024 temp(0);
        for (uint_fast64_t i = 0; i < buffer.size(); i++){
            std::bitset<1024> x(buffer[i] - '0');
            std::cout << buffer[i] - '0' << std::endl;
            temp += x;
            temp *= 10;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& lhs, uint_1024& rhs);

};

std::ostream& operator<< (std::ostream& lhs, uint_1024& rhs){
    lhs << rhs.Get();
    return lhs;
}



