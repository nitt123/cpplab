#include "RadioStation.h"
#include <limits> 

RadioStation::RadioStation(const std::string& model, double frequencyMHz)
    : model(model), frequencyMHz(frequencyMHz) {
}

RadioStation::~RadioStation() {}

void RadioStation::checkFrequency(double freq) const {
    if (freq <= 0.0 || freq > 1000.0) {
        throw RadioStationException("Неприпустиме значення частоти: має бути в діапазоні від 0 до 1000 МГц.");
    }
}

void RadioStation::printData(std::ostream& os) const {
    os << "Модель: " << model << ", Частота: " << frequencyMHz << " МГц";
}

void RadioStation::readData(std::istream& is) {
    std::string inputModel;
    double inputFreq;

    std::cout << "Введіть Модель: ";
    if (!(is >> inputModel)) {
        throw RadioStationException("Не вдалося прочитати модель.");
    }

    std::cout << "Введіть Частоту (МГц, наприклад, 98.5): ";
    if (!(is >> inputFreq)) {
        is.clear();
        is.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        throw RadioStationException("Неприпустимий тип вводу для частоти.");
    }

    try {
        checkFrequency(inputFreq);
        this->model = inputModel;
        this->frequencyMHz = inputFreq;
    }
    catch (const RadioStationException&) {
        throw;
    }
}

std::istream& operator>>(std::istream& is, RadioStation& obj) {
    obj.readData(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const RadioStation& obj) {
    os << "[Радіостанція] ";
    obj.printData(os);
    return os;
}

bool RadioStation::operator>(const RadioStation& other) const {
    return this->frequencyMHz > other.frequencyMHz;
}

void RadioStation::writeToFile(std::ostream& os) const {
    os << model << "\n";
    os << frequencyMHz << "\n";
}

void RadioStation::readFromFile(std::istream& is) {
    std::string freqStr;
    std::getline(is, model);
    std::getline(is, freqStr);
    try {
        frequencyMHz = std::stod(freqStr);
    }
    catch (const std::exception&) {
        throw RadioStationException("Помилка конвертації частоти при читанні з файлу.");
    }
}