#include <iostream>
#include <windows.h>
#include "OpAmp.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int g1 = 120;
    int v1 = 15;
    OpAmp<int> amp1(g1, v1, 2);
    amp1.showInfo();

    OpAmp<double> amp2(300.75, 12.5, 4);
    amp2.showInfo();

    float g3 = 50.2f;
    float v3 = 5.1f;
    OpAmp<float*> amp3(&g3, &v3, 1);
    amp3.showInfo();

    system("pause");
    return 0;
}