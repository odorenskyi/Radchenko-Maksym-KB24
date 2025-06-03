#ifndef MODULESRADCHENKO_H_INCLUDED
#define MODULESRADCHENKO_H_INCLUDED

#include <iostream>
#include <cmath>
#include <string>
#include <bitset>
#include <windows.h>

using namespace std;

// Функція для обчислення якогось значення (наприклад, середнє арифметичне)
float s_calculation(int x, int y, int z) {
    return (x + y + z) / 3.0f;
}

// Функція, яка повертає обчислення у вигляді рядка
string s_calculation_to_string(int x, int y, int z) {
    float result = s_calculation(x, y, z);
    return "Result: " + to_string(result);
}

// Функція для представлення числа у двійковому коді (для числа b)
string to_binary(int b) {
    return bitset<32>(b).to_string();
}

#endif // MODULESRADCHENKO_H_INCLUDED
