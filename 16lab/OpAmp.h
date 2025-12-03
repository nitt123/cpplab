#pragma once
#include <iostream>
#include <string>

class OpAmp {
private:
    double gain;
    double voltage;
    int inputs;

public:
    OpAmp(double gain = 1.0, double voltage = 0.0, int inputs = 2);
    ~OpAmp();

    friend std::ostream& operator<<(std::ostream& os, const OpAmp& obj);

    double getGain() const { return gain; }
    void setGain(double g) { gain = g; }
};