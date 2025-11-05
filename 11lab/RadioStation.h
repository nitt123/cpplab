#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

class RadioOperator;

class RadioStation {
protected:
	struct RadioData {
		double frequency_MHz;
		double power_W;
		std::string modulationType;
	};
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

	friend class RadioOperator;
};