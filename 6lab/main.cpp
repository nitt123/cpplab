#include <iostream>
#include "Operational_Amplifier.h"
#include <windows.h>
#include <locale>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "Створення об'єкта op_amp..." << std::endl;
    OperationalAmplifier op_amp(120.5, 15.0, 2);

    std::cout << "\nПочаткові дані:" << std::endl;
    op_amp.printInfo();

    std::cout << "\n--- Тестування зміни даних ---" << std::endl;

    std::cout << "Спроба встановити кількість входів = -1..." << std::endl;
    op_amp.setInputs(-1);

    std::cout << "Встановлення напруги = -15.0 В..." << std::endl;
    op_amp.setVoltage(-15.0);

    std::cout << "Спроба встановити коефіцієнт підсилення = 0..." << std::endl;
    op_amp.setGain(0);

    std::cout << "\nКінцеві дані після спроб модифікації:" << std::endl;
    op_amp.printInfo();

    return 0;
}