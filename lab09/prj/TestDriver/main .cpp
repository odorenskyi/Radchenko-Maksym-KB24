#include <iostream>
#include "Modules.h"

using namespace std;

int main() {
    // Задача 9.1
    int population = calculatePopulationChange(1000000, 5000, 6000, 3000, 2000);
    cout << "Нове населення: " << population << endl;

    // Задача 9.2
    float windSpeeds[24] = {1.0f, 2.5f, 3.5f, 4.5f, 5.5f, 2.0f, 3.0f, 2.2f,
                            1.8f, 0.5f, 6.5f, 7.0f, 4.0f, 2.7f, 2.1f, 3.6f,
                            4.8f, 1.0f, 1.5f, 0.8f, 1.1f, 5.5f, 6.0f, 7.0f};
    int beaufort = minBeaufortScale(windSpeeds, 24);
    cout << "Мінімальна швидкість в балах Бофорта: " << beaufort << endl;

    // Задача 9.3
    unsigned int N = 255;
    int count = countBinaryZerosOrOnes(N);
    cout << "Кількість (нулів або одиниць) в числі " << N << ": " << count << endl;

    return 0;
}
