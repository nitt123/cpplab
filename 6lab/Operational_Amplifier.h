#ifndef OPERATIONAL_AMPLIFIER_H
#define OPERATIONAL_AMPLIFIER_H

#include <iostream>
#include <array>
#include <string>

struct amplifier_s_t {
    double Gain;
    double supply_voltage;
    int number_of_inputs;
};

class Operational_Amplifier {
private:
    static const int SIZE = 3; 
    std::array<amplifier_s_t, SIZE> amplifiers;

public:
    Operational_Amplifier();  
    ~Operational_Amplifier();

    void inputData();  
    void printData();  
    void setAmplifier(int index, double gain, double supply, int inputs);
};

#endif
