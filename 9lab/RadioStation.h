#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

struct RadioData {
	double frequency_MHz;
	double power_W;
	std::string modulationType;
};

class RadioStation {
protected:
	RadioData data;
	std::vector<RadioData> history;

public:
	RadioStation(double freq, double power, const std::string& mod);
	virtual ~RadioStation();

	double getFrequency() const;
	double getPower() const;

	void setFrequency(double freq);
	void setPower(double power);

	virtual void displayInfo() const;

	void logCurrentState();
};