#pragma once
#include "RadioStation.h"

class HandheldRadio : public RadioStation {
private:
	int batteryCapacity_mAh;

public:
	HandheldRadio(double freq, double power, const std::string& mod, int capacity);
	virtual ~HandheldRadio();

	void displayInfo() const override;

	void setBatteryCapacity(int capacity);
	int getEstimatedWorkTime() const;
};