#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

class RadioStationException : public std::exception {
private:
    std::string message;
public:
    RadioStationException(const std::string& msg) : message("Помилка Радіостанції: " + msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class RadioStation {
private:
    std::string model;
    double frequencyMHz;

protected:
    virtual void printData(std::ostream& os) const;
    virtual void readData(std::istream& is);

public:
    RadioStation(const std::string& model = "Невідома", double frequencyMHz = 0.0);
    virtual ~RadioStation();

    std::string getModel() const { return model; }
    double getFrequency() const { return frequencyMHz; }

    friend std::istream& operator>>(std::istream& is, RadioStation& obj);
    friend std::ostream& operator<<(std::ostream& os, const RadioStation& obj);

    bool operator>(const RadioStation& other) const;

    virtual void writeToFile(std::ostream& os) const;
    virtual void readFromFile(std::istream& is);
    virtual int getType() const = 0;

protected:
    void checkFrequency(double freq) const;
};