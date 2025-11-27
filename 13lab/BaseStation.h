#pragma once
#include "RadioStation.h"

class BaseStation : public RadioStation {
private:
    int maxPowerWatts;

protected:
    void printData(std::ostream& os) const override;
    void readData(std::istream& is) override;

public:
    BaseStation(const std::string& model = "БазоваНевідома", double frequencyMHz = 0.0, int maxPowerWatts = 0);
    ~BaseStation() override;

    void writeToFile(std::ostream& os) const override;
    void readFromFile(std::istream& is) override;
    int getType() const override { return 1; }

private:
    void checkPower(int power) const;
};