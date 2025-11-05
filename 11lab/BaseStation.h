#pragma once
#include "RadioStation.h"

class BaseStation : public RadioStation {
private:
	int antennaHeight_m;

public:
	BaseStation(double freq, double power, const std::string& mod, int height);
	virtual ~BaseStation();

	void displayInfo() const override;

	void setAntennaHeight(int height);
	double calculateMaxRange() const;
};