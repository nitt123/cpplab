#ifndef OPERATIONAL_AMPLIFIER_H
#define OPERATIONAL_AMPLIFIER_H

class OperationalAmplifier {
private:
    double gain_coefficient;
    double supply_voltage;
    int number_of_inputs;

public:
    OperationalAmplifier(double gain, double voltage, int inputs);
    ~OperationalAmplifier();

    void setGain(double gain);
    void setVoltage(double voltage);
    void setInputs(int inputs);

    double getGain() const;
    double getVoltage() const;
    int getInputs() const;

    void printInfo() const;
};

#endif