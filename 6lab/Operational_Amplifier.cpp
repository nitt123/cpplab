#include "Operational_Amplifier.h"
#include <iostream>

OperationalAmplifier::OperationalAmplifier(double gain, double voltage, int inputs) {
    gain_coefficient = 0;
    supply_voltage = 0;
    number_of_inputs = 0;

    setGain(gain);
    setVoltage(voltage);
    setInputs(inputs);

    std::cout << "=> Об'єкт OperationalAmplifier створено." << std::endl;
}

OperationalAmplifier::~OperationalAmplifier() {
    std::cout << "=> Об'єкт OperationalAmplifier знищено." << std::endl;
}

void OperationalAmplifier::setGain(double gain) {
    if (gain > 0) {
        gain_coefficient = gain;
    } else {
        std::cout << "[ПОПЕРЕДЖЕННЯ] Коефіцієнт підсилення має бути додатнім. Значення не змінено." << std::endl;
    }
}

void OperationalAmplifier::setVoltage(double voltage) {
    if (voltage != 0) {
        supply_voltage = voltage;
    } else {
        std::cout << "[ПОПЕРЕДЖЕННЯ] Напруга живлення не може дорівнювати 0. Значення не змінено." << std::endl;
    }
}

void OperationalAmplifier::setInputs(int inputs) {
    if (inputs > 0) {
        number_of_inputs = inputs;
    } else {
        std::cout << "[ПОПЕРЕДЖЕННЯ] Кількість входів має бути більшою за 0. Значення не змінено." << std::endl;
    }
}

double OperationalAmplifier::getGain() const {
    return gain_coefficient;
}

double OperationalAmplifier::getVoltage() const {
    return supply_voltage;
}

int OperationalAmplifier::getInputs() const {
    return number_of_inputs;
}

void OperationalAmplifier::printInfo() const {
    std::cout << "\n--- Характеристики підсилювача ---" << std::endl;
    std::cout << "Коефіцієнт підсилення: " << gain_coefficient << std::endl;
    std::cout << "Напруга живлення: " << supply_voltage << " В" << std::endl;
    std::cout << "Кількість входів: " << number_of_inputs << std::endl;
    std::cout << "------------------------------------" << std::endl;
}