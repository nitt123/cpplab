#include "BaseStation.h"
#include "HandheldRadio.h"
#include <vector>

void report(RadioStation& station) {
	std::cout << "\n============================================\n";
	station.displayInfo();
	std::cout << "============================================\n";
}

int main() {
	BaseStation bs1(850.0, 50.0, "GSM", 40);
	HandheldRadio hr1(446.0, 0.5, "FM", 1500);

	try {
		bs1.setFrequency(900.0);
		hr1.setPower(2.0);
		bs1.logCurrentState();

		std::cout << "\n--- ПЕРЕВІРКА ВАЛІДНОСТІ ---\n";
		bs1.setAntennaHeight(5);

	}
	catch (const std::invalid_argument& e) {
		std::cerr << "--- ПОМИЛКА ВАЛІДАЦІЇ ---: " << e.what() << "\n";
	}

	std::cout << "\n--- ДЕМОНСТРАЦІЯ ПОЛІМОРФІЗМУ ---\n";

	report(bs1);
	report(hr1);

	std::cout << "--- УНІКАЛЬНІ МЕТОДИ ---\n";
	std::cout << "Базова станція: Максимальний радіус дії = " << bs1.calculateMaxRange() << " км.\n";
	std::cout << "Рація: Орієнтовний час роботи: " << hr1.getEstimatedWorkTime() << " годин (при 2.0 Вт).\n";

	return 0;
}