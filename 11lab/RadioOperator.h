#pragma once
#include "RadioStation.h"
#include "BaseStation.h"
#include "HandheldRadio.h"
#include <vector>

class RadioOperator {
public:
	RadioOperator();
	~RadioOperator();

	void showRadioData(const RadioStation& station) const;

	void setRadioData(RadioStation& station, double freq, double power, const std::string& mod);

	void analyzeHistory(const RadioStation& station) const;

	void inputBaseStation(BaseStation& bs);
	void showBaseStation(const BaseStation& bs) const;
};