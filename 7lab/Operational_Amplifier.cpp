#include "Operational_Amplifier.h"
#include <iostream>
#include <algorithm> 

std::array<op_amp_s_t, STORAGE_SIZE> OperationalAmplifier::op_amps_storage = {};
int OperationalAmplifier::current_count = 0;
int OperationalAmplifier::next_id_counter = 1;

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

    op_amps_storage[current_count].id = next_id_counter++;
    op_amps_storage[current_count].gain = gain;
    op_amps_storage[current_count].voltage = voltage;
    op_amps_storage[current_count].number_of_inputs = inputs;
    op_amps_storage[current_count].is_used = true;

    std::cout << "����: ������ �� � ID " << op_amps_storage[current_count].id << std::endl;
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

    std::cout << "������\tID\tGain\tVoltage\tInputs" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    for (int i = 0; i < current_count; ++i) {
        std::cout << i << "\t"
            << op_amps_storage[i].id << "\t"
            << op_amps_storage[i].gain << "\t"
            << op_amps_storage[i].voltage << "\t"
            << op_amps_storage[i].number_of_inputs
            << std::endl;
    }
    std::cout << "--- ʳ���� ������� --- (�������: " << current_count << "/" << STORAGE_SIZE << ")\n" << std::endl;
}

int OperationalAmplifier::getFreeSlots() const {
    return STORAGE_SIZE - current_count;
}

bool OperationalAmplifier::insertOpAmp(int index, double gain, double voltage, int inputs) {
    if (gain <= 0) {
        std::cout << "������� (�������): ���������� �� ���� > 0." << std::endl;
        return false;
    }
    if (voltage == 0) {
        std::cout << "������� (�������): ������� �� ���� ���� 0." << std::endl;
        return false;
    }
    if (inputs <= 0) {
        std::cout << "������� (�������): ʳ������ ����� �� ���� > 0." << std::endl;
        return false;
    }

    if (current_count >= STORAGE_SIZE) {
        std::cout << "������� (�������): ������� ���������." << std::endl;
        return false;
    }

    if (index < 0 || index > current_count) {
        std::cout << "������� (�������): ����������� ������ " << index << ". ��������: [0, " << current_count << "]" << std::endl;
        return false;
    }

    for (int i = current_count; i > index; --i) {
        op_amps_storage[i] = op_amps_storage[i - 1];
    }

    op_amps_storage[index].id = next_id_counter++;
    op_amps_storage[index].gain = gain;
    op_amps_storage[index].voltage = voltage;
    op_amps_storage[index].number_of_inputs = inputs;
    op_amps_storage[index].is_used = true;

    current_count++;
    std::cout << "����: ��������� �� � ID " << op_amps_storage[index].id << " � ������ " << index << std::endl;
    return true;
}

bool OperationalAmplifier::removeOpAmp(int index) {
    if (index < 0 || index >= current_count) {
        std::cout << "������� (���������): ����������� ������ " << index << ". ��������: [0, " << current_count - 1 << "]" << std::endl;
        return false;
    }

    int removed_id = op_amps_storage[index].id;

    for (int i = index; i < current_count - 1; ++i) {
        op_amps_storage[i] = op_amps_storage[i + 1];
    }

    current_count--;

    op_amps_storage[current_count] = {};

    std::cout << "����: �������� �� � ID " << removed_id << " (������ " << index << ")" << std::endl;
    return true;
}

bool OperationalAmplifier::swapOpAmps(int index1, int index2) {
    if (index1 < 0 || index1 >= current_count || index2 < 0 || index2 >= current_count) {
        std::cout << "������� (����): ��������� �������. ��������: [0, " << current_count - 1 << "]" << std::endl;
        return false;
    }

    if (index1 == index2) {
        std::cout << "����������� (����): ������� �������, ���� �� �������." << std::endl;
        return true;
    }

    std::swap(op_amps_storage[index1], op_amps_storage[index2]);

    std::cout << "����: ������� �������� � ��������� " << index1 << " �� " << index2 << std::endl;
    return true;
}

void OperationalAmplifier::clearStorage() {
    for (int i = 0; i < current_count; ++i) {
        op_amps_storage[i] = {};
    }

    current_count = 0;
    next_id_counter = 1;
    std::cout << "����: ������� ������� �������." << std::endl;
}