#include "HandheldRadio.h"

HandheldRadio::HandheldRadio(double freq, double power, const std::string& mod, int capacity)
	: RadioStation(freq, power, mod) {
	setBatteryCapacity(capacity);
}

HandheldRadio::~HandheldRadio() {}

void HandheldRadio::setBatteryCapacity(int capacity) {
	if (capacity < 500) {
		throw std::invalid_argument("ªìí³ñòü áàòàðå¿ ìàº áóòè íå ìåíøå 500 ìÀã.");
	}
	batteryCapacity_mAh = capacity;
}

void HandheldRadio::displayInfo() const {
	std::cout << "Òèï: ÏÎÐÒÀÒÈÂÍÀ ÐÀÖ²ß (Ïîõ³äíèé êëàñ 2)\n";
	std::cout << "  ×àñòîòà: " << data.frequency_MHz << " ÌÃö, Ïîòóæí³ñòü: " << data.power_W << " Âò, Ìîäóëÿö³ÿ: " << data.modulationType << ".\n";
	std::cout << "  ªìí³ñòü áàòàðå¿: " << batteryCapacity_mAh << " ìÀã.\n";
}

int HandheldRadio::getEstimatedWorkTime() const {
	return static_cast<int>(batteryCapacity_mAh / (data.power_W * 100));
}