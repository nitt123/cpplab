#include "BaseStation.h"
#include <limits>
#include <sstream>

BaseStation::BaseStation(const std::string& model, double frequencyMHz, int maxPowerWatts)
    : RadioStation(model, frequencyMHz), maxPowerWatts(maxPowerWatts) {
}

BaseStation::~BaseStation() {}

void BaseStation::checkPower(int power) const {
    if (power <= 0 || power > 10000) {
        throw RadioStationException("Неприпустиме значення потужності для Базової станції: має бути в діапазоні від 1 до 10000 Ватт.");
    }
}

void BaseStation::printData(std::ostream& os) const {
    RadioStation::printData(os);
    os << ", Макс. Потужність: " << maxPowerWatts << " Вт";
}

void BaseStation::readData(std::istream& is) {
    RadioStation::readData(is);
    int inputPower;

    std::cout << "Введіть Макс. Потужність (Ватт): ";
    if (!(is >> inputPower)) {
        is.clear();
        is.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        throw RadioStationException("Неприпустимий тип вводу для максимальної потужності.");
    }

    try {
        checkPower(inputPower);
        this->maxPowerWatts = inputPower;
    }
    catch (const RadioStationException&) {
        throw;
    }
}

void BaseStation::writeToFile(std::ostream& os) const {
    os << getType() << "\n";
    RadioStation::writeToFile(os);
    os << maxPowerWatts << "\n";
}

void BaseStation::readFromFile(std::istream& is) {
    RadioStation::readFromFile(is);
    std::string powerStr;
    std::getline(is, powerStr);
    try {
        maxPowerWatts = std::stoi(powerStr);
    }
    catch (const std::exception&) {
        throw RadioStationException("Помилка конвертації потужності при читанні з файлу.");
    }
}