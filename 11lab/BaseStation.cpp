#include "BaseStation.h"
#include <cmath>

BaseStation::BaseStation(double freq, double power, const std::string& mod, int height)
	: RadioStation(freq, power, mod) {
	setAntennaHeight(height);
}

BaseStation::~BaseStation() {}

void BaseStation::setAntennaHeight(int height) {
	if (height < 10) {
		throw std::invalid_argument("Висота антени базової станції має бути не менше 10м.");
	}
	antennaHeight_m = height;
}

void BaseStation::displayInfo() const {
	std::cout << "Тип: БАЗОВА СТАНЦІЯ (Похідний клас 1)\n";
	std::cout << "  Частота: " << data.frequency_MHz << " МГц, Потужність: " << data.power_W << " Вт, Модуляція: " << data.modulationType << ".\n";
	std::cout << "  Висота антени: " << antennaHeight_m << " м.\n";
}

double BaseStation::calculateMaxRange() const {
	return 3.5 * std::sqrt(antennaHeight_m);
}