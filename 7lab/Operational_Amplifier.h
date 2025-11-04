#ifndef OPERATIONAL_AMPLIFIER_H
#define OPERATIONAL_AMPLIFIER_H

#include <iostream>
#include <string>
#include <vector> 

struct op_amp_s_t {
    int id;
    double gain;
    double voltage;
    int number_of_inputs;
    bool is_used;
};

class OperationalAmplifier {
private:
    static std::vector<op_amp_s_t> op_amps_storage;
    static int next_id_counter;

public:
    OperationalAmplifier();
    ~OperationalAmplifier();

    bool addOpAmp(double gain, double voltage, int inputs);
    void printAll() const;
    int getCurrentSize() const;

    bool insertOpAmp(int index, double gain, double voltage, int inputs);
    bool removeOpAmp(int index);
    bool swapOpAmps(int index1, int index2);
    void clearStorage();
};

#endif