#include "PortableRadio.h"
#include <limits>
#include <sstream>

PortableRadio::PortableRadio(const std::string& model, double frequencyMHz, bool hasDisplay)
    : RadioStation(model, frequencyMHz), hasDisplay(hasDisplay) {
}

PortableRadio::~PortableRadio() {}

void PortableRadio::printData(std::ostream& os) const {
    RadioStation::printData(os);
    os << ", Дисплей: " << (hasDisplay ? "Так" : "Ні");
}

void PortableRadio::readData(std::istream& is) {
    RadioStation::readData(is);
    int inputDisplay;

    std::cout << "Наявність Дисплея (1 - Так, 0 - Ні): ";
    if (!(is >> inputDisplay)) {
        is.clear();
        is.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        throw RadioStationException("Неприпустимий тип вводу для наявності дисплея.");
    }

    this->hasDisplay = (inputDisplay != 0);
}

void PortableRadio::writeToFile(std::ostream& os) const {
    os << getType() << "\n";
    RadioStation::writeToFile(os);
    os << (hasDisplay ? "1" : "0") << "\n";
}

void PortableRadio::readFromFile(std::istream& is) {
    RadioStation::readFromFile(is);
    std::string displayStr;
    std::getline(is, displayStr);
    hasDisplay = (displayStr == "1");
}