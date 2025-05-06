#include <iostream>
#include "../ModulesRadchenko.h"
using namespace std;

int main() {
    int x = 0, y = 0, z = 0;
    int salary = 0, work_exp = 0;
    int size_head = 0, number = 0;
    char action;

    do {
        cout << "Enter action (e, r, f, t):\n==> ";
        cin >> action;

        if (action == 'e') {
            cout << "Enter x:\n==> ";
            cin >> x;
            cout << "Enter y:\n==> ";
            cin >> y;
            cout << "Enter z:\n==> ";
            cin >> z;

            cout << s_calculation_to_string(x, y, z) << endl;

        } else if (action == 'r') {
            cout << "Enter your salary:\n==> ";
            cin >> salary;
            cout << "Enter your work experience:\n==> ";
            cin >> work_exp;

            cout << head_task_9_1(salary, work_exp) << endl;

        } else if (action == 'f') {
            cout << "Enter your head circumference in centimeters:\n==> ";
            cin >> size_head;

            cout << "Helmet size - " << task_9_2(size_head) << endl;

        } else if (action == 't') {
            cout << "Enter number:\n==> ";
            cin >> number;

            cout << task_9_3(number) << endl;

        } else if (action != 'g' && action != 'G' && action != 'o') {
            cout << '\a'; // звуковий сигнал
        }

    } while (action != 'g' && action != 'G' && action != 'o');

    return 0;
}

