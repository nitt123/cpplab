#include "Operational_Amplifier.h"

Operational_Amplifier::Operational_Amplifier() {
    std::cout << "Об'єкт Operational_Amplifier створено\n";
}

Operational_Amplifier::~Operational_Amplifier() {
    std::cout << "Об'єкт Operational_Amplifier знищено\n";
}

void Operational_Amplifier::inputData() {
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Введіть коефіцієнт підсилення (Gain): ";
        std::cin >> amplifiers[i].Gain;

        std::cout << "Введіть напругу живлення (supply_voltage): ";
        std::cin >> amplifiers[i].supply_voltage;

        std::cout << "Введіть кількість входів (number_of_inputs): ";
        std::cin >> amplifiers[i].number_of_inputs;
    }
}

void Operational_Amplifier::printData() {
    std::cout << "\nСписок підсилювачів:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Amplifier " << i+1 << ":\n";
        std::cout << "  Gain: " << amplifiers[i].Gain << "\n";
        std::cout << "  Supply voltage: " << amplifiers[i].supply_voltage << " В\n";
        std::cout << "  Number of inputs: " << amplifiers[i].number_of_inputs << "\n\n";
    }
}

void Operational_Amplifier::setAmplifier(int index, double gain, double supply, int inputs) {
    if (index < 0 || index >= SIZE) {
        std::cout << "Помилка: неправильний індекс!\n";
        return;
    }
    if (gain <= 0) {
        std::cout << "Помилка: Gain має бути > 0!\n";
        return;
    }
    if (supply <= 0) {
        std::cout << "Помилка: напруга живлення має бути > 0!\n";
        return;
    }
    if (inputs < 1) {
        std::cout << "Помилка: кількість входів має бути >= 1!\n";
        return;
    }

    amplifiers[index].Gain = gain;
    amplifiers[index].supply_voltage = supply;
    amplifiers[index].number_of_inputs = inputs;
}