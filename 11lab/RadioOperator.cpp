#include "RadioOperator.h"
#include <iostream>
#include <limits>

RadioOperator::RadioOperator() {
	std::cout << "Радіооператор створений.\n";
}

RadioOperator::~RadioOperator() {
	std::cout << "Радіооператор знищений.\n";
}

void RadioOperator::showRadioData(const RadioStation& station) const {
	std::cout << "\n--- Інформація, отримана через Дружній Клас ---\n";
	std::cout << "  Частота (private): " << station.data.frequency_MHz << " МГц\n";
	std::cout << "  Потужність (private): " << station.data.power_W << " Вт\n";
	std::cout << "  Модуляція (private): " << station.data.modulationType << "\n";
}

void RadioOperator::setRadioData(RadioStation& station, double freq, double power, const std::string& mod) {
	std::cout << "\n--- Встановлення значень через Дружній Клас ---\n";
	station.data.frequency_MHz = freq;
	station.data.power_W = power;
	station.data.modulationType = mod;
	std::cout << "  Нові дані встановлено!\n";
}

void RadioOperator::analyzeHistory(const RadioStation& station) const {
	std::cout << "\n--- Аналіз історії станів (private history) ---\n";
	if (station.history.empty()) {
		std::cout << "  Історія порожня.\n";
		return;
	}
	std::cout << "  Кількість записів в історії: " << station.history.size() << "\n";

	double minPower = std::numeric_limits<double>::max();
	for (const auto& item : station.history) {
		if (item.power_W < minPower) {
			minPower = item.power_W;
		}
	}
	std::cout << "  Мінімальна потужність в історії: " << minPower << " Вт.\n";
}

void RadioOperator::inputBaseStation(BaseStation& bs) {
	int height;
	std::cout << "\n--- Введення даних для Базової Станції (через Оператора) ---\n";
	std::cout << "Введіть висоту антени (м): ";
	if (!(std::cin >> height)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Некоректне введення. Встановлено висоту за замовчуванням (10 м).\n";
		height = 10;
	}
	bs.setAntennaHeight(height);
}

void RadioOperator::showBaseStation(const BaseStation& bs) const {
	std::cout << "\n--- Виведення даних Базової Станції (через Оператора) ---\n";
	bs.displayInfo();
	std::cout << "  Розрахунок макс. радіусу: " << bs.calculateMaxRange() << " км.\n";
}