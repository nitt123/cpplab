#include "Operational_Amplifier.h"
#include <iostream>

std::array<op_amp_s_t, STORAGE_SIZE> OperationalAmplifier::op_amps_storage = {};
int OperationalAmplifier::current_count = 0;

OperationalAmplifier::OperationalAmplifier() {
    std::cout << "-> �������� ��'��� OperationalAmplifier." << std::endl;
}

OperationalAmplifier::~OperationalAmplifier() {
    std::cout << "-> ������� ��'��� OperationalAmplifier." << std::endl;
}

bool OperationalAmplifier::addOpAmp(double gain, double voltage, int inputs) {
    if (gain <= 0) {
        std::cout << "�������: ���������� �� ���� > 0. ����� ��������." << std::endl;
        return false;
    }
    if (voltage == 0) {
        std::cout << "�������: ������� �� ���� ���� 0. ����� ��������." << std::endl;
        return false;
    }
    if (inputs <= 0) {
        std::cout << "�������: ʳ������ ����� �� ���� > 0. ����� ��������." << std::endl;
        return false;
    }

    if (current_count >= STORAGE_SIZE) {
        std::cout << "�������: ������� ���������. ����� ��������." << std::endl;
        return false;
    }

    op_amps_storage[current_count].id = current_count + 1;
    op_amps_storage[current_count].gain = gain;
    op_amps_storage[current_count].voltage = voltage;
    op_amps_storage[current_count].number_of_inputs = inputs;
    op_amps_storage[current_count].is_used = true;

    std::cout << "����: ������ �� � ID " << current_count + 1 << std::endl;
    current_count++;
    return true;
}

void OperationalAmplifier::printAll() const {
    std::cout << "\n--- ���� ������� �� ---" << std::endl;
    if (current_count == 0) {
        std::cout << "������� ������." << std::endl;
        std::cout << "--------------------------\n" << std::endl;
        return;
    }

    std::cout << "ID\tGain\tVoltage\tInputs" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    for (int i = 0; i < current_count; ++i) {
        std::cout << op_amps_storage[i].id << "\t"
            << op_amps_storage[i].gain << "\t"
            << op_amps_storage[i].voltage << "\t"
            << op_amps_storage[i].number_of_inputs
            << std::endl;
    }
    std::cout << "--- ʳ���� ������� ---\n" << std::endl;
}

int OperationalAmplifier::getFreeSlots() const {
    return STORAGE_SIZE - current_count;
}