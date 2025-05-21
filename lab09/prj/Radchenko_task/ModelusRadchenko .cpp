#include "ModulesRadchenko.h"
#include <cmath>
#include <vector>
#include <bitset>
#include <string>

// Реалізація функції з лабораторної №8 (приклад)
double s_calculation(double x, double y, double z) {
    return pow(x, 2) + sqrt(y) + log(z); // Можна змінити під свій варіант
}

// Задача 9.1: Обчислення зміни чисельності населення області
int calculatePopulationChange(int initialPopulation, int born, int died, int arrived, int left) {
    return initialPopulation + born - died + arrived - left;
}

// Задача 9.2: Визначення мінімального бала Бофорта за добу
int getBeaufortScale(double speed) {
    if (speed < 0.3) return 0;
    else if (speed < 1.6) return 1;
    else if (speed < 3.4) return 2;
    else if (speed < 5.5) return 3;
    else if (speed < 8.0) return 4;
    else if (speed < 10.8) return 5;
    else if (speed < 13.9) return 6;
    else if (speed < 17.2) return 7;
    else if (speed < 20.8) return 8;
    else if (speed < 24.5) return 9;
    else if (speed < 28.5) return 10;
    else if (speed < 32.7) return 11;
    else return 12;
}

int minBeaufortScale(const std::vector<double>& speeds) {
    int minScale = 12;
    for (double speed : speeds) {
        int scale = getBeaufortScale(speed);
        if (scale < minScale) minScale = scale;
    }
    return minScale;
}

// Задача 9.3: Обробка біта D7
int countZeroBitsOrBinaryZeros(unsigned int N) {
    // Перевірка біт D7 (тобто 7-й біт зліва, індексація з 0)
    bool D7 = (N >> 7) & 1;
    int count = 0;

    if (D7 == 0) {
        // Рахуємо кількість двійкових нулів
        for (int i = 0; i < 32; ++i) {
            if (((N >> i) & 1) == 0) ++count;
        }
    } else {
        // Рахуємо кількість двійкових одиниць
        for (int i = 0; i < 32; ++i) {
            if ((N >> i) & 1) ++count;
        }
    }
    return count;
}
