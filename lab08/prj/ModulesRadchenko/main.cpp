     #include <iostream>
     #include <cmath>
     #include <windows.h>
     #include <string>
     
     using namespace std;
     float s_calculation(double x, double y, double z)
     {
         double underRoot = pow(y + z, 2) - pow(x, 5);
         if (underRoot < 0) {
             cout << "Помилка: Підкореневий вираз є від'ємним." << endl;
             return NAN;
         }
         if (sin(z) == 0) {
             cout << "Помилка: Значення z не повинно бути кратним Pi." << endl;
             return NAN;
         }
         return 0.5 * pow(x, 2) - sqrt(underRoot) - log(abs(sin(z)));
     }
     string decToHexa(int n)
     {
         char hexaDeciNum[100];
         string str = "";
         int i = 0;
         while (n != 0) {
             int temp = 0;
             temp = n % 16;
             if (temp < 10) {
                 hexaDeciNum[i] = temp + 48;
                 i++;
             }
             else {
                 hexaDeciNum[i] = temp + 55;
                 i++;
             }
             n = n / 16;
         }
         for (int j = i - 1; j >= 0; j--)
             str += hexaDeciNum[j];
         return str;
     }
     string boolToString(bool b){
         return b ? "true" : "false";
     }
     string copyright(){
         SetConsoleCP(65001);
         SetConsoleOutputCP(65001);
         return "Radchenko Maksim ©";
     }
     string trueOrFalse(double a, double  b){
         return "a + 1 > |b - 2| ? " + boolToString(a + 1 > abs(b - 2));
     }
     string decimal(double x, double y, double z){
         return "x = " + to_string(x) + ", y = " + to_string(y) + ", z = " + to_string(z);
     }
     
     string hexADecimal(int x, int y, int z){
         return "x = " + decToHexa(x) + ", y = " + decToHexa(y) + ", z = " + decToHexa(z);
     }
     string s_calculation_to_string(double x, double y, double z){
         SetConsoleCP(65001);
         SetConsoleOutputCP(65001);
         double result = s_calculation(x, y, z);
         if (isnan(result)) {
             return "Помилка при обчисленні.";
         }
         return "S = " + to_string(result);
     }

