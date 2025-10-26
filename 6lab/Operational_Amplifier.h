#ifndef OPERATIONAL_AMPLIFIER_H
#define OPERATIONAL_AMPLIFIER_H

#include <iostream>
#include <string>
#include <array>

const int STORAGE_SIZE = 5; // <--- «м≥нив назву константи

struct op_amp_s_t {
    int id;
    double gain;
    double voltage;
    int number_of_inputs;
    bool is_used;
};

class OperationalAmplifier {
private:
    static std::array<op_amp_s_t, STORAGE_SIZE> op_amps_storage;
    static int current_count;

public:
    OperationalAmplifier();
    ~OperationalAmplifier();

    bool addOpAmp(double gain, double voltage, int inputs);
    void printAll() const;
    int getFreeSlots() const;
};

#endif