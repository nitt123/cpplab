#include "BaseStation.h"
#include "HandheldRadio.h"
#include "RadioOperator.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include "windows.h"

void report(RadioStation& station) {
	std::cout << "\n============================================\n";
	station.displayInfo();
	std::cout << "============================================\n";
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::cout << "--- 1. Ñòâîðåííÿ îá'ºêò³â ---\n";
	BaseStation bs1(850.0, 50.0, "GSM", 40);
	HandheldRadio hr1(446.0, 0.5, "FM", 1500);
	RadioOperator operatorObj;

	bs1.logCurrentState();
	hr1.logCurrentState();

	try {
		std::cout << "\n--- 2. Äåìîíñòðàö³ÿ Ïîë³ìîðô³çìó òà Óñïàäêóâàííÿ ---\n";
		report(bs1);
		report(hr1);

		std::cout << "\n--- ÓÍ²ÊÀËÜÍ² ÌÅÒÎÄÈ ---\n";
		std::cout << "Áàçîâà ñòàíö³ÿ: Ìàêñèìàëüíèé ðàä³óñ ä³¿ = " << bs1.calculateMaxRange() << " êì.\n";
		std::cout << "Ðàö³ÿ: Îð³ºíòîâíèé ÷àñ ðîáîòè: " << hr1.getEstimatedWorkTime() << " ãîäèí.\n";

		std::cout << "\n\n--- 3. Äåìîíñòðàö³ÿ Äðóæíüîãî Êëàñó (RadioOperator) ---\n";

		operatorObj.showRadioData(bs1);

		operatorObj.setRadioData(bs1, 950.0, 60.0, "LTE");

		bs1.logCurrentState();
		operatorObj.analyzeHistory(bs1);

		BaseStation bs2(1800.0, 100.0, "3G", 15);
		operatorObj.inputBaseStation(bs2);
		operatorObj.showBaseStation(bs2);

		std::cout << "\n--- 4. Òåñòóâàííÿ Âàë³äàö³¿ (î÷³êóºòüñÿ âèíÿòîê) ---\n";
		bs1.setPower(0.0);

	}
	catch (const std::invalid_argument& e) {
		std::cerr << "--- ÏÎÌÈËÊÀ ÂÀË²ÄÀÖ²¯ ---: " << e.what() << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << "--- ÇÀÃÀËÜÍÀ ÏÎÌÈËÊÀ ---: " << e.what() << "\n";
	}

	return 0;
}