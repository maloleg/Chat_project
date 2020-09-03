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

    uintT_t(std::bitset<T> arg){
        this->num = arg;
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
        rhs.flip();
        uintT_t<T> temp(rhs);
        std::bitset<T> x(1);
        //std::cout << rhs << "!\n";
        //x = 0;

        //std::cout << x << "!\n";

        temp += x;
        //std::cout << rhs << "!\n";
        *this += rhs;
        *this += x;

//        for (uint_fast64_t i = 0; i < T; i++){
//            //std::cout << first[i] << " " << second[i] << " " << temp << std::endl;
//            x[i] = (num[i] - rhs[i] - temp)%2;
//            if (!num[i] && rhs[i]) temp = (num[i] - rhs[i] + temp)/2;
//            if (num[i] && !rhs[i]) temp /= 2;
//        }
//        this->num = x;
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
        return (rhs < *this || rhs == *this);
    }

    bool operator<=(uintT_t rhs){
        return (rhs > *this || rhs == *this);
    }

    bool operator==(uintT_t rhs){
        return num == rhs.num;
    }

    bool operator!=(uintT_t rhs){
        return num != rhs.num;
    }

    uintT_t& operator*=(uintT_t rhs){         //not terrible, not good, but not terrible
        uintT_t<T> temp(0);

        if (num.count() > rhs.num.count()){
            for (uint_fast64_t i = 0; i < T; i++){
                if (rhs.num[i]){
                    temp += num << i;
                }
            }
        }
        else{
            for (uint_fast64_t i = 0; i < T; i++){
                if (num[i]){
                    temp += rhs.num << i;
                }
            }
        }
        *this = temp;

        return *this;
    }

    uintT_t& operator*(uintT_t rhs){
        uintT_t<T> temp(num);
        temp*=rhs;

        *this = temp;

        return *this;
    }

    uintT_t& operator-(uintT_t rhs){
        uintT_t<T> temp(num);
        temp-=rhs;

        *this = temp;

        return *this;
    }

    uintT_t& operator/(uintT_t rhs){
        uintT_t<T> temp(num);
        temp/=rhs;

        *this = temp;

        return *this;
    }



    uint_fast64_t First_bit() {
        uint_fast64_t check = 0;
        if (num.count() != 0){
            for (uint_fast64_t i = T - 1; i >= 0; i--) {
                if (num[i]) {
                    check = i;
                    break;
                }
               // std::cout << i << std::endl;
            }
        return check + 1;
    }
        else{
            return 0;
        }

    }

    uintT_t& operator /= (uintT_t rhs){
        uintT_t<T> result(0);
        uintT_t<T> temp(*this);
        uintT_t<T> current(rhs);
        uint_fast64_t i;

        while (temp >= rhs){

            i = 0;
            current = rhs;
            while (current <= temp && current.First_bit() != temp.First_bit()){
                current.num <<= 1;
                i++;
            }
            std::cout << "result=      " << result << "\ntemp=    " << temp << "\ncurrent= " << current << std::endl;

            if (current <= temp){
                temp -= current;
                result.num[i] = 1;
            }
            else if (i > 0){
                current.num >>= 1;
                i--;
                temp -= current;
                result.num[i] = 1;
            }
        }
        this->num = result.num;
        return *this;
    }

    uintT_t& operator %=(uintT_t rhs){
//        return (*this / rhs);
        uintT_t temp(*this);
        temp /= rhs;
        temp *= rhs;
        *this -= temp;
//        this->num = temp.num;
        return *this;
        std::cout << *this /rhs << std::endl;
        std::cout << rhs*(*this /rhs) << std::endl;
        std::cout << *this << std::endl;
        return (*this - rhs*(*this /rhs));
    }


//    uintT_t& operator*=(uint_fast64_t x){        //slow af
//        std::bitset<T> temp = this->Get();
//        for (uint_fast64_t i = 1; i < x; i++){
//            *this += temp;
//        }
//        return *this;
//    }

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




