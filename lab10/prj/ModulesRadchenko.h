#ifndef MODULESRADCHENKO_H_INCLUDED
#define MODULESRADCHENKO_H_INCLUDED

#include <iostream>
#include <cmath>
#include <bitset>
#include <windows.h>

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>

using namespace std;

// --- Функції обробки чисел ---
float s_calculation(int x, int y, int z);

string s_calculation_to_string(int x, int y, int z);

string to_binary(int b);

// --- Функції для задач 10.1–10.3 ---
int task_10_1(string path_output, string path_input);

int task_10_2(string path_output);

int task_10_3(int x, int y, int z, int b, string path_output);

// --- Допоміжні функції ---
string detect_language(const string& sentence);

bool contains_taboo_words(const string& sentence);

string current_datetime();

string read_file(const string& path);

void append_to_file(const string& path, const string& content);

#endif // MODULESRADCHENKO_H_INCLUDED
