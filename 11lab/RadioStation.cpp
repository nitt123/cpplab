#include "RadioStation.h"

RadioStation::RadioStation(double freq, double power, const std::string& mod) {
	setFrequency(freq);
	setPower(power);
	data.modulationType = mod;
}

RadioStation::~RadioStation() {}

void RadioStation::setFrequency(double freq) {
	if (freq <= 0.0 || freq > 6000.0) {
		throw std::invalid_argument("Некоректна частота. Вона повинна бути в діапазоні (0, 6000] МГц.");
	}
	data.frequency_MHz = freq;
}

void RadioStation::setPower(double power) {
	if (power <= 0.0) {
		throw std::invalid_argument("Потужність повинна бути позитивною.");
	}
	data.power_W = power;
}

double RadioStation::getFrequency() const { return data.frequency_MHz; }
double RadioStation::getPower() const { return data.power_W; }

void RadioStation::displayInfo() const {
	std::cout << "Тип: Базова Радіостанція (General)\n";
	std::cout << "Частота: " << data.frequency_MHz << " МГц, Потужність: " << data.power_W << " Вт, Модуляція: " << data.modulationType << ".\n";
}

void RadioStation::logCurrentState() {
	history.push_back(data);
}