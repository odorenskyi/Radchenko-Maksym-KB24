#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функція для виводу імені розробника
void printDeveloper() {
    cout << "Rachencko Maksim ©" << endl;
}

// Функція для обчислення логічного виразу (1 або 0)
int logicalExpression(char a, char b) {
    return (a + 1 <= b) ? 1 : 0;
}

// Функція для обчислення S
double s_calculation(double x, double y, double z) {
    if (sin(z) == 0) {
        cerr << "Помилка: sin(z) = 0, логарифм не визначений!" << endl;
        return NAN;
    }
    return (0.5 * x * x) - sqrt(abs(pow(y + z, 2) - pow(x, 5))) - log(abs(sin(z)));
}

// Функція для виводу чисел у двох системах числення
void printNumbers(double x, double y, double z) {
    cout << "Числа у десятковій системі: x = " << x << ", y = " << y << ", z = " << z << endl;
    cout << hex << uppercase;
    cout << "Числа у шістнадцятковій системі: x = " << static_cast<int>(x) 
         << ", y = " << static_cast<int>(y) 
         << ", z = " << static_cast<int>(z) << dec << endl;
}

int main() {
    double x, y, z;
    char a, b;

    // Введення даних
    cout << "Введіть x, y, z: ";
    cin >> x >> y >> z;
    cout << "Введіть два символи a і b: ";
    cin >> a >> b;

    // Вивід результатів
    printDeveloper();
    cout << "Результат логічного виразу: " << logicalExpression(a, b) << endl;
    printNumbers(x, y, z);
    cout << "Значення S: " << s_calculation(x, y, z) << endl;

    return 0;
}

