#include "OpAmp.h"
#include <limits>

OpAmp::OpAmp(double gain, double voltage, int inputs)
    : gain(gain), voltage(voltage), inputs(inputs) {
}

OpAmp::~OpAmp() {}

bool OpAmp::operator==(const OpAmp& other) const {
    return gain == other.gain && voltage == other.voltage && inputs == other.inputs;
}

bool OpAmp::operator!=(const OpAmp& other) const {
    return !(*this == other);
}

std::istream& operator>>(std::istream& is, OpAmp& obj) {
    double inGain, inVoltage;
    int inInputs;

    std::cout << "Введіть коефіцієнт підсилення: ";
    if (!(is >> inGain)) {
        is.clear();
        is.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        throw OpAmpException("Невірний тип даних для коефіцієнта.");
    }

    std::cout << "Введіть напругу живлення (В): ";
    if (!(is >> inVoltage)) {
        is.clear();
        is.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        throw OpAmpException("Невірний тип даних для напруги.");
    }

    std::cout << "Введіть кількість входів: ";
    if (!(is >> inInputs)) {
        is.clear();
        is.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        throw OpAmpException("Невірний тип даних для кількості входів.");
    }

    if (inInputs < 1) throw OpAmpException("Кількість входів має бути більше 0.");

    obj.gain = inGain;
    obj.voltage = inVoltage;
    obj.inputs = inInputs;

    return is;
}

std::ostream& operator<<(std::ostream& os, const OpAmp& obj) {
    os << "[ОП] Коеф: " << obj.gain
        << ", Напруга: " << obj.voltage
        << "В, Входів: " << obj.inputs;
    return os;
}