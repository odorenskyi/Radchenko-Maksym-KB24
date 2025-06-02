#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <bitset>
#include <cmath>
#include <windows.h>

using namespace std;

// Функція обчислення
float s_calculation(int x, int y, int z) {
    return pow(3 * sin(sqrt(12 * x + log(x - 3))), y) + (float)z / x;
}

// Перевірка чи українське речення
bool isUkrainian(const string& text) {
    return text.find("і") != string::npos || text.find("ї") != string::npos || text.find("є") != string::npos;
}

// Перевірка чи англійське речення повністю у верхньому регістрі
bool isEnglishUppercase(const string& text) {
    for (char c : text)
        if (isalpha(c) && islower(c))
            return false;
    return true;
}

// Зчитування з файлу
string ReadFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return "ERROR: Cannot open file.";

    string text, line;
    while (getline(file, line))
        text += line + "\n";
    file.close();
    return text;
}

// Запис авторських даних та обробка вхідного речення
void task_10_1(const string& inputPath, const string& outputPath) {
    ifstream in(inputPath);
    ofstream out(outputPath);

    if (!in.is_open() || !out.is_open()) return;

    // Авторські дані
    out << "Радченко Максим\nЦНТУ, Кропивницький, Україна, 2025\n";

    string line;
    getline(in, line);

    // Обробка залежно від мови
    if (isUkrainian(line)) {
        // Видалення "лінощі", "сесія", "академзаборгованість"
        vector<string> banned = {"лінощі", "сесія", "академзаборгованість"};
        for (const string& word : banned) {
            size_t pos;
            while ((pos = line.find(word)) != string::npos)
                line.erase(pos, word.length());
        }
    } else if (isEnglishUppercase(line)) {
        transform(line.begin(), line.end(), line.begin(), ::toupper);
    }

    out << line << "\n";
    in.close();
    out.close();
}

// Додавання статті 62 і дати
void task_10_2(const string& path) {
    fstream file(path, ios::app);
    if (!file.is_open()) return;

    // Додаємо текст статті 62
    file << "Відповідно до статті 62 Закону України \"Про вищу освіту\": особа має право здобувати вищу освіту на різних рівнях за рахунок державного або місцевого бюджету, а також за кошти фізичних (юридичних) осіб.\n";

    // Дата і час
    time_t now = time(0);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&now));
    file << "Дата та час допису: " << buffer << "\n";

    file.close();
}

// Додавання результатів обчислення та числа в двійковому коді
void task_10_3(const string& path, int x, int y, int z, int b) {
    fstream file(path, ios::app);
    if (!file.is_open()) return;

    float result = s_calculation(x, y, z);
    file << "s_calculation(" << x << ", " << y << ", " << z << ") = " << result << "\n";

    bitset<32> b_bin(b);
    file << "b в двійковому коді: " << b_bin << "\n";

    file.close();
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    string inputFile = "input.txt";
    string outputFile = "output.txt";

    // Виконання задач
    task_10_1(inputFile, outputFile);
    task_10_2(outputFile);
    task_10_3(outputFile, 4, 2, 8, 7); // приклад значень x=4, y=2, z=8, b=7

    cout << "Виконання завершено. Перевірте файл: " << outputFile << endl;
    return 0;
}#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <bitset>
#include <cmath>
#include <windows.h>

using namespace std;

// Функція обчислення
float s_calculation(int x, int y, int z) {
    return pow(3 * sin(sqrt(12 * x + log(x - 3))), y) + (float)z / x;
}

// Перевірка чи українське речення
bool isUkrainian(const string& text) {
    return text.find("і") != string::npos || text.find("ї") != string::npos || text.find("є") != string::npos;
}

// Перевірка чи англійське речення повністю у верхньому регістрі
bool isEnglishUppercase(const string& text) {
    for (char c : text)
        if (isalpha(c) && islower(c))
            return false;
    return true;
}

// Зчитування з файлу
string ReadFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return "ERROR: Cannot open file.";

    string text, line;
    while (getline(file, line))
        text += line + "\n";
    file.close();
    return text;
}

// Запис авторських даних та обробка вхідного речення
void task_10_1(const string& inputPath, const string& outputPath) {
    ifstream in(inputPath);
    ofstream out(outputPath);

    if (!in.is_open() || !out.is_open()) return;

    // Авторські дані
    out << "Радченко Максим\nЦНТУ, Кропивницький, Україна, 2025\n";

    string line;
    getline(in, line);

    // Обробка залежно від мови
    if (isUkrainian(line)) {
        // Видалення "лінощі", "сесія", "академзаборгованість"
        vector<string> banned = {"лінощі", "сесія", "академзаборгованість"};
        for (const string& word : banned) {
            size_t pos;
            while ((pos = line.find(word)) != string::npos)
                line.erase(pos, word.length());
        }
    } else if (isEnglishUppercase(line)) {
        transform(line.begin(), line.end(), line.begin(), ::toupper);
    }

    out << line << "\n";
    in.close();
    out.close();
}

// Додавання статті 62 і дати
void task_10_2(const string& path) {
    fstream file(path, ios::app);
    if (!file.is_open()) return;

    // Додаємо текст статті 62
    file << "Відповідно до статті 62 Закону України \"Про вищу освіту\": особа має право здобувати вищу освіту на різних рівнях за рахунок державного або місцевого бюджету, а також за кошти фізичних (юридичних) осіб.\n";

    // Дата і час
    time_t now = time(0);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&now));
    file << "Дата та час допису: " << buffer << "\n";

    file.close();
}

// Додавання результатів обчислення та числа в двійковому коді
void task_10_3(const string& path, int x, int y, int z, int b) {
    fstream file(path, ios::app);
    if (!file.is_open()) return;

    float result = s_calculation(x, y, z);
    file << "s_calculation(" << x << ", " << y << ", " << z << ") = " << result << "\n";

    bitset<32> b_bin(b);
    file << "b в двійковому коді: " << b_bin << "\n";

    file.close();
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    string inputFile = "input.txt";
    string outputFile = "output.txt";

    // Виконання задач
    task_10_1(inputFile, outputFile);
    task_10_2(outputFile);
    task_10_3(outputFile, 4, 2, 8, 7); // приклад значень x=4, y=2, z=8, b=7

    cout << "Виконання завершено. Перевірте файл: " << outputFile << endl;
    return 0;
}
