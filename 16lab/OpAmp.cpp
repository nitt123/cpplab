#include "OpAmp.h"

OpAmp::OpAmp(double gain, double voltage, int inputs)
    : gain(gain), voltage(voltage), inputs(inputs) {
    std::cout << "  [Конструктор ОП] Створено: " << gain << "x, " << voltage << "В" << std::endl;
}

OpAmp::~OpAmp() {
    std::cout << "  [Деструктор ОП] Знищено: " << gain << "x" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const OpAmp& obj) {
    os << "ОП (Gain: " << obj.gain << ", " << obj.voltage << "V, Inputs: " << obj.inputs << ")";
    return os;
}