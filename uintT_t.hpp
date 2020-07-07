#pragma once

#include "iostream"
#include <bitset>
#include <string>

template <uint64_t T>
class uintT_t{
private:
    std::bitset<T> num;

public:
    uintT_t(){
        num = 0;
    }

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

    uintT_t& operator-=(std::bitset<T> rhs){
        uint64_t temp = 0;
        std::bitset<T> x(0);
        for (uint_fast64_t i = 0; i < T; i++){
            //std::cout << first[i] << " " << second[i] << " " << temp << std::endl;
            x[i] = (num[i] - rhs[i] - temp)%2;
            if (!num[i] && rhs[i]) temp = (num[i] - rhs[i] + temp)/2;
            if (num[i] && !rhs[i]) temp /= 2;
        }
        this->num = x;
        return *this;
    }

    uintT_t& operator-=(uintT_t rhs){
        if (*this > rhs) {
            *this -= rhs.num;
            return *this;
        }
        else{
            throw "Negative uint";
        }
    }

    uintT_t& operator+=(uintT_t rhs){
        *this += rhs.num;
        return *this;
    }

    uintT_t operator+(uintT_t rhs){
        uintT_t<T> temp;
        temp+=num;
        temp+=rhs;

        return temp;
    }

    uintT_t& operator+=(uint64_t rhs){
        std::bitset<T> temp(rhs);

        *this += temp;

        return *this;
    }

//    std::string to_dec_string(){
//
//    }

    bool operator>(uintT_t rhs){
        bool check = false;

        for (uint64_t i = T - 1; i >= 0; i--){
            //std::cout << "i =" << i << " ; " << num[i] << " " << rhs.num[i] << std::endl;
            if (num[i] > rhs.num[i]){
                check = true;
                break;
            }
            else if (num[i] < rhs.num[i]){
                break;
            }
            if (i == 0) break;
        }

        return check;
    }

    bool operator<(uintT_t rhs){
        return (rhs > *this);
    }

    bool operator>=(uintT_t rhs){
        bool check = true;

        for (uint64_t i = T - 1; i >= 0; i--){
            //std::cout << "i =" << i << " ; " << num[i] << " " << rhs.num[i] << std::endl;
            if (num[i] > rhs.num[i]){
                check = true;
                break;
            }
            else if (num[i] < rhs.num[i]){
                break;
            }
            if (i == 0) break;
        }

        return check;
    }

    bool operator<=(uintT_t rhs){
        return (rhs > *this && rhs == *this);
    }

    bool operator==(uintT_t rhs){
        return num == rhs.num;
    }

    bool operator!=(uintT_t rhs){
        return num != rhs.num;
    }

    uintT_t& operator*=(uint_fast64_t x){
        std::bitset<T> temp = this->Get();
        for (uint_fast64_t i = 1; i < x; i++){
            *this += temp;
        }
        return *this;
    }

    uintT_t& operator= (const char* rhs){
        std::string buffer(rhs);
        uintT_t temp(buffer);
        *this = temp;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& lhs, uintT_t& rhs){
        lhs << rhs.Get();
        return lhs;
    }

};


