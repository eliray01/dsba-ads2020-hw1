#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
#include <utility>
#include <fstream>
#include "Multiplicator.h"

using namespace std;


int main()
{
    srand(time(0));
    ofstream Table;
    Table.open(R"(C:\Users\fahre_000\dsba-ads2020-hw1\data\output.csv)");
    Table.clear();
    Multiplicator M;
    Number num1,num2,result;
    Table << "Length" << ',' << "Grade School Multiplication" << ',' << "Divide and conquer" << ',' << "Karatsuba" << '\n';
    int k = 0;
    for(int i = 50; i <= 1000; i += 50){
        double sum = 0,sum1 = 0,sum2 = 0;
        for(int k = 0; k < 10; k++){
        num1.generate_random_number(i);
        num2.generate_random_number(i);
        clock_t start = clock();
        M.GradeSchoolMultiplication(num1,num2);
        clock_t end = clock();

        clock_t start1 = clock();
        M.DaC(num1,num2);
        clock_t end1 = clock();

        clock_t start2 = clock();
        M.Karatsuba(num1,num2);
        clock_t end2 = clock();

        sum += (double)(end - start)/CLOCKS_PER_SEC; // Grade School Multiplication
        sum1 += (double)(end1 - start1)/CLOCKS_PER_SEC; // Divide and Conquer
        sum2 += (double)(end2 - start2)/CLOCKS_PER_SEC; // Karatsuba
        }
        Table << i << ',' << (sum/10) << ',' << (sum1/10) << ',' << (sum2/10) << '\n';
    }
}