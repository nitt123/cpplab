#pragma once
#include "RadioStation.h"

class PortableRadio : public RadioStation {
private:
    bool hasDisplay;

protected:
    void printData(std::ostream& os) const override;
    void readData(std::istream& is) override;

public:
    PortableRadio(const std::string& model = "ПортативнаНевідома", double frequencyMHz = 0.0, bool hasDisplay = false);
    ~PortableRadio() override;

    void writeToFile(std::ostream& os) const override;
    void readFromFile(std::istream& is) override;
    int getType() const override { return 2; }
};