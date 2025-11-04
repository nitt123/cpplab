#include "Operational_Amplifier.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

std::vector<op_amp_s_t> OperationalAmplifier::op_amps_storage;
int OperationalAmplifier::next_id_counter = 1;

OperationalAmplifier::OperationalAmplifier() {
    std::cout << "-> OperationalAmplifier обєкт створенно." << std::endl;
}

OperationalAmplifier::~OperationalAmplifier() {
    std::cout << "-> OperationalAmplifier обєкт зруйновано." << std::endl;
}

bool OperationalAmplifier::addOpAmp(double gain, double voltage, int inputs) {
    if (gain <= 0 || voltage == 0 || inputs <= 0) {
        return false;
    }

    op_amp_s_t new_op_amp;
    new_op_amp.id = next_id_counter++;
    new_op_amp.gain = gain;
    new_op_amp.voltage = voltage;
    new_op_amp.number_of_inputs = inputs;
    new_op_amp.is_used = true;

    op_amps_storage.push_back(new_op_amp);

    return true;
}

void OperationalAmplifier::printAll() const {
    if (op_amps_storage.empty()) {
        std::cout << "пусто." << std::endl;
        return;
    }

    std::cout << "Index\tID\tGain\tVoltage\tInputs" << std::endl;

    for (size_t i = 0; i < op_amps_storage.size(); ++i) {
        std::cout << i << "\t"
            << op_amps_storage[i].id << "\t"
            << op_amps_storage[i].gain << "\t"
            << op_amps_storage[i].voltage << "\t"
            << op_amps_storage[i].number_of_inputs
            << std::endl;
    }
}

int OperationalAmplifier::getCurrentSize() const {
    return op_amps_storage.size();
}

bool OperationalAmplifier::insertOpAmp(int index, double gain, double voltage, int inputs) {
    if (gain <= 0 || voltage == 0 || inputs <= 0) {
        return false;
    }

    if (index < 0 || index > op_amps_storage.size()) {
        return false;
    }

    op_amp_s_t new_op_amp;
    new_op_amp.id = next_id_counter++;
    new_op_amp.gain = gain;
    new_op_amp.voltage = voltage;
    new_op_amp.number_of_inputs = inputs;
    new_op_amp.is_used = true;

    op_amps_storage.insert(op_amps_storage.begin() + index, new_op_amp);

    return true;
}

bool OperationalAmplifier::removeOpAmp(int index) {
    if (index < 0 || index >= op_amps_storage.size()) {
        return false;
    }

    int removed_id = op_amps_storage.at(index).id;

    op_amps_storage.erase(op_amps_storage.begin() + index);

    return true;
}

bool OperationalAmplifier::swapOpAmps(int index1, int index2) {
    if (index1 < 0 || index1 >= op_amps_storage.size() || index2 < 0 || index2 >= op_amps_storage.size()) {
        return false;
    }

    if (index1 == index2) {
        return true;
    }

    std::swap(op_amps_storage[index1], op_amps_storage[index2]);

    return true;
}

void OperationalAmplifier::clearStorage() {
    op_amps_storage.clear();

    next_id_counter = 1;
}