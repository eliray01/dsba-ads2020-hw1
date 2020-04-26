#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
#include "Number.h"

using namespace std;
class Multiplicator{
public:
    Multiplicator()= default;
    ~Multiplicator()= default;

    static Number generator(int k){
        Number res;
        res.generate_random_number(k);
        return res;
    }
    static int getDigit(Number& input, int index){return input[index];}
    static std::pair <Number, Number> split(Number& input){
        Number first_part;
        Number second_part;
        if(input.size() % 2 != 0){
            input.reverse();
            input.push_back(0);
            input.reverse();
        }
        for(int i = 0; i < input.size()/2; i++){
            first_part.push_back(input[i]);
        }
        for(int i = input.size()/2; i < input.size(); i++){
            second_part.push_back(input[i]);
        }
        return std::make_pair(first_part, second_part);
    }
public:
    static Number GradeSchoolMultiplication(Number& input1, Number& input2)
    {
        Number res;
        for (int i = 0; i < input1.size() + input2.size(); i++){
            res.push_back(0);
        }
        int flag1 = 0;
        for(int i = input1.size() - 1; i >= 0; i--)
        {
            int inmind = 0;
            int flag2 = 0;
            for(int j = input2.size() -1; j >= 0; j--)
            {
                int temp = res[flag1 + flag2] + input1[i] * input2[j] + inmind;
                res[flag1 + flag2] = temp % 10;
                inmind = temp / 10;
                flag2++;
            }
            res[flag1 + input1.size()] = inmind;
            flag1++;
        }
        for(int i = res.size() - 1; i >= 0; i--){
            if(res[i] == 0)
                res.pop_back();
            else
                break;
        }
        res.reverse();
        return res;
    }
    static Number DaC (Number& input1, Number& input2){
        if (input1.size() <= 64){ return GradeSchoolMultiplication(input1,input2);}
        std::pair <Number, Number> pair_num1 = split(input1);
        std::pair <Number, Number> pair_num2 = split(input2);
        int size = 0;
        if (input1.size() % 2 != 0){
            size = input1.size() + 1;
        }
        else size = input1.size();
        Number ac = DaC(pair_num1.first,pair_num2.first);
        Number ad = DaC(pair_num1.first,pair_num2.second);
        Number bc = DaC(pair_num1.second,pair_num2.first);
        Number bd = DaC(pair_num1.second,pair_num2.second);
        Number temp = (ad + bc);
        for(int i = 0; i < size; i++)
            ac.push_back(0);
        for(int i = 0; i < size/2; i++)
            temp.push_back(0);
        return ac + temp + bd;
    }
    static Number powNum(Number input, int size1){
        for(int i = 0; i < size1; i++){
            input.push_back(0);
        }
        return input;
    }
    static Number Karatsuba(Number input1,Number input2){
        if (input1.size() <= 64){ return GradeSchoolMultiplication(input1,input2);}
        int size = 0;
        if (input1.size() % 2 != 0){
            size = input1.size() + 1;
        }
        else
            size = input1.size();
        std::pair <Number, Number> pair_num1 = split(input1);
        std::pair <Number, Number> pair_num2 = split(input2);
        Number a = Karatsuba(pair_num1.first,pair_num2.first);
        Number d = Karatsuba(pair_num1.second,pair_num2.second);
        Number e = Karatsuba(pair_num1.first + pair_num1.second, pair_num2.first + pair_num2.second) - a - d;
        return powNum(a, size/1) + powNum(e, size/2) + d;
    }
};



#ifndef UNTITLED4_MULTIPLICATOR_H
#define UNTITLED4_MULTIPLICATOR_H

#endif //UNTITLED4_MULTIPLICATOR_H
