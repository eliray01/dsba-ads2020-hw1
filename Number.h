#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;
class Number {
private:
    vector<int> container;
public:
    Number(vector<int> input) :container(input) {};
    Number() = default;
    ~Number() = default;
    Number(const Number& rhv) : container(rhv.container){
        for(int i = 0; i < this->size(); ++i)
            this->container[i] = rhv.container[i];
    }   // copy constructor
    Number operator +(const Number& input)
    {
        vector <int> res;
        Number result;
        int reminder = 0;
        int temp = 0;
        if (input.size() == this->size()){
            for(int i = input.size()-1; i >= 0; i--){
                temp = (input.container[i] + this->container[i]) + reminder;
                reminder = (temp / 10);
                res.push_back(temp % 10);
            }
            if(reminder > 0){
                res.push_back(1);
            }
            std::reverse(res.begin(),res.end());
            result.container = res;
        }
        else if (input.container.size() < this->container.size()){
            Number with_zero = input;
            with_zero.reverse();
            for(int i = 0; i < this->container.size() - input.container.size(); i++){
                with_zero.container.push_back(0);
            }
            with_zero.reverse();
            for(int i = this->size()-1; i >= 0; i--){
                temp = (with_zero.container[i] + this->container[i]) + reminder;
                reminder = (temp / 10);
                res.push_back(temp % 10);
            }
            if(reminder > 0){
                res.push_back(1);
            }
            std::reverse(res.begin(),res.end());
            result.container = res;
        }
        else if(this->size() < input.size()){
            Number with_zero;
            with_zero.container = this->container;
            with_zero.reverse();
            for(int i = 0; i < input.size()-this->size(); i++)
                with_zero.push_back(0);
            with_zero.reverse();

            for(int i = input.size()-1; i >= 0; i--){
                temp = (input.container[i] + with_zero[i]) + reminder;
                reminder = (temp / 10);
                res.push_back(temp % 10);
            }
            if(reminder > 0){
                res.push_back(1);
            }
            std::reverse(res.begin(),res.end());
            result.container = res;
        }
        return result;
    }          // plus
    Number& operator -(const Number& input) {
        Number temp = input.container;
        if (this->size() > input.size()) {
            temp.reverse();
            for (int i = 0; i < (this->size() - temp.size()); i++)
                temp.push_back(0);
            temp.reverse();
        }

        int flag = 0;
        for (int i = this->size() - 1; i >= 0; i--) {
            if (this->container[i] - flag - temp[i] < 0) {
                this->container[i] = this->container[i] + 10 - temp[i] - flag;
                flag = 1;

            }
            else {
                this->container[i] = this->container[i] - temp[i] - flag;
                flag = 0;
            }
        }

        this->reverse();
        for (int i = this->container.size() - 1; i >= 0; i--) {
            if (this->container[i] == 0)
                this->pop_back();
            else
                break;
        }
        this->reverse();
        temp.clear();
        return *this;
    }         // minus
    int& operator [](int index){ return container[index];}
    Number& operator = (Number rhv){
        container.clear();
        for(int i = 0; i < rhv.size(); i++){
            container.push_back(rhv[i]);
        }
    }
    friend std::ostream& operator<< (std::ostream& out, Number& input);

public:
    void push_back(int value){ container.push_back(value);};
    void generate_random_number(int size) {
        vector<int> out;
        for (int i = 0; i < size; i++) {
            int a = std::rand() % 10;
            out.push_back(a);
        }
        if(out[0] == 0){
            out[0] = 1 + rand() % 9;
        }
        container = out;
    }
    int size() const { return container.size();}
    void pop_back() {container.pop_back();}
    void reverse() { std::reverse(container.begin(), container.end());}
    void clear() {container.clear();}
    void push_front(int value){
        std::reverse(container.begin(),container.end());
        container.push_back(value);
        std::reverse(container.begin(),container.end());
    }
};
std::ostream& operator<< (std::ostream& out, Number& input)
{
    for (int i = 0; i < input.size(); i++) {
        out << input[i];
    }
    return out;
}

#ifndef UNTITLED4_NUMBER_H
#define UNTITLED4_NUMBER_H

#endif //UNTITLED4_NUMBER_H
