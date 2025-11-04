#include <iostream>
#include <stdexcept>
#include "windows.h" 


class OpAmp {
private:
    double gain;
    double supplyVoltage;
    int numberOfInputs;

public:
    OpAmp() : gain(100000.0), supplyVoltage(12.0), numberOfInputs(2) {}

    OpAmp(double g, double v, int inputs) {
        setGain(g);
        setSupplyVoltage(v);
        setNumberOfInputs(inputs);
    }

    ~OpAmp() {}

    void displayInfo() const {
        std::cout << "Коефіцієнт підсилення: " << gain << "; Напруга живлення: " << supplyVoltage << " В; Кількість входів: " << numberOfInputs << ".\n";
    }

    void setGain(double newGain) {
        if (newGain <= 1.0) {
            throw std::invalid_argument("Error: Коефіцієнт підсилення має бути значно > 1.");
        }
        gain = newGain;
    }

    void setSupplyVoltage(double newVoltage) {
        if (newVoltage <= 0.0) {
            throw std::invalid_argument("Error: Напруга живлення має бути позитивною.");
        }
        supplyVoltage = newVoltage;
    }

    void setNumberOfInputs(int newInputs) {
        if (newInputs < 1 || newInputs > 4) {
            throw std::invalid_argument("Error: Кількість входів має бути 1, 2, 3 або 4.");
        }
        numberOfInputs = newInputs;
    }
};

void changeSupplyVoltage(OpAmp& amp, double newVoltage) {
    std::cout << "\n>>> Виклик функції changeSupplyVoltage (посилання)\n";
    try {
        amp.setSupplyVoltage(newVoltage);
        std::cout << ">>> Напруга живлення успішно змінена на " << newVoltage << " В.\n";
    }
    catch (const std::invalid_argument& e) {
        std::cerr << ">>> Помилка при зміні напруги: " << e.what() << "\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    OpAmp defaultAmp;
    std::cout << "1. Початкові дані (Default):\n";
    defaultAmp.displayInfo();

    std::cout << "------------------------------------------\n";

    OpAmp precisionAmp(50000.0, 15.0, 2);

    std::cout << "2. Початкові дані (precisionAmp):\n";
    precisionAmp.displayInfo();

    try {
        precisionAmp.setGain(200000.0);
        precisionAmp.setNumberOfInputs(4);
        std::cout << "Коефіцієнт підсилення та кількість входів змінені.\n";
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Помилка валідації в main: " << e.what() << "\n";
    }

    std::cout << "\n3. Дані після прямої зміни:\n";
    precisionAmp.displayInfo();

    changeSupplyVoltage(precisionAmp, 5.0);

    changeSupplyVoltage(precisionAmp, -3.0);

    std::cout << "\n4. Кінцеві дані precisionAmp (після референсів):\n";
    precisionAmp.displayInfo();

    std::cout << "------------------------------------------\n";

    return 0;
}