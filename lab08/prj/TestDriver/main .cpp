#include <ModulesRachenko.h>

int main()
{
    int x [7]= {1, 2, 0.5 , -1, 3, 10, -2, 4, -3, 2.5};
    int y [7] = {10, 8, 4, 5, 14, 20, 1, 3, 12, 2};
    int z [7] = {3, 15, 7, 6, 21, 30, 1 , 2, 18, 7};

    float result [7] = {-1.10865, -21.5646, -6542.09, -13.5899, -1152.16, -22062300, 0.22651, -69.2445, -465.462};

    for(int i = 0; i < 7; i ++){
        if(round(s_calculation(x[i], y[i], z[i]) * 100) / 100 == result[i] ){
            cout << "Test is passed" << endl;
        }
        else{
            cout << "Test failed" << endl;
        }
    }

    return 0;
}
