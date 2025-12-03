#pragma once
#include <iostream>
#include <string>
#include <exception>

class OpAmpException : public std::exception {
private:
    std::string message;
public:
    OpAmpException(const std::string& msg) : message("Помилка ОП: " + msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class OpAmp {
private:
    double gain;
    double voltage;
    int inputs;

public:
    OpAmp(double gain = 1.0, double voltage = 0.0, int inputs = 2);
    ~OpAmp();

    friend std::istream& operator>>(std::istream& is, OpAmp& obj);
    friend std::ostream& operator<<(std::ostream& os, const OpAmp& obj);
    bool operator==(const OpAmp& other) const;
    bool operator!=(const OpAmp& other) const;

    double getGain() const { return gain; }
    double getVoltage() const { return voltage; }
    int getInputs() const { return inputs; }
};
