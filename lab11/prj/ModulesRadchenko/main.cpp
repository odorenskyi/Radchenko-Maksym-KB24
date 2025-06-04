#include <iostream>
#include <locale>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "ModulesRadchenko.h"

using namespace std;

struct MediaEntry {
    string name;
    string type;
    string certificate;
    string registration_date;
    string founders;
    string registering_authority;
};

vector<MediaEntry> registry;


// Запис інформації до реєстру
void add_entry() {

    MediaEntry entry;
    cin.ignore();
    cout << "Назва видання: ";
    getline(cin, entry.name);

    cout << "Вид видання: ";
    getline(cin, entry.type);

    cout << "Серія та номер свідоцтва: ";
    getline(cin, entry.certificate);

    cout << "Дата реєстрації: ";
    getline(cin, entry.registration_date);

    cout << "Відомості про засновників: ";
    getline(cin, entry.founders);

    cout << "Орган, який здійснив реєстрацію: ";
    getline(cin, entry.registering_authority);

    registry.push_back(entry);

    cout << "Запис додано успішно." << endl;
}

// Додавання інформації до реєстру
void load_registry(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Помилка при відкритті файлу: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        MediaEntry entry;

        getline(ss, entry.name, ',');
        getline(ss, entry.type, ',');
        getline(ss, entry.certificate, ',');
        getline(ss, entry.registration_date, ',');
        getline(ss, entry.founders, ',');
        getline(ss, entry.registering_authority, ',');

        if (!entry.name.empty() && !entry.type.empty()) {
            registry.push_back(entry);
        } else {
            cerr << "Невірний запис знайдено у файлі: " << line << endl;
        }
    }

    file.close();
    if (file.bad()) {
        cerr << "Помилка під час читання файлу: " << filename << endl;
    }
}

// Вилучення інформації з реєстру
void remove_entry() {

    string search_term;
    cin.ignore();
    cout << "Введіть назву видання або серію та номер свідоцтва для вилучення: ";
    getline(cin, search_term);

    auto it = remove_if(registry.begin(), registry.end(), [&](const MediaEntry& entry) {
        return entry.name == search_term || entry.certificate == search_term;
    });

    if (it != registry.end()) {
        registry.erase(it, registry.end());
        cout << "Запис вилучено успішно." << endl;
    } else {
        cout << "Запис не знайдено." << endl;
    }
}


