#pragma once
#include <iostream>
using namespace std;

template <typename T>
class OpAmp {
private:
    T gain;
    T voltage;
    int inputs;

public:
    OpAmp(T g, T v, int i) : gain(g), voltage(v), inputs(i) {}

    void showInfo() {
        cout << "--- Загальний шаблон ---" << endl;
        cout << "Коефіцієнт підсилення: " << gain << endl;
        cout << "Напруга живлення: " << voltage << " В" << endl;
        cout << "Кількість входів: " << inputs << endl << endl;
    }
};

template <>
class OpAmp<double> {
private:
    double gain;
    double voltage;
    int inputs;

public:
    OpAmp(double g, double v, int i) : gain(g), voltage(v), inputs(i) {}

    void showInfo() {
        cout << "--- Повна спеціалізація (double) ---" << endl;
        cout << "Коефіцієнт підсилення: " << gain << endl;
        cout << "Напруга живлення: " << voltage << " В" << endl;
        cout << "Кількість входів: " << inputs << endl << endl;
    }
};

template <typename T>
class OpAmp<T*> {
private:
    T* gain;
    T* voltage;
    int inputs;

public:
    OpAmp(T* g, T* v, int i) : gain(g), voltage(v), inputs(i) {}

    void showInfo() {
        cout << "--- Часткова спеціалізація (Вказівник) ---" << endl;
        if (gain && voltage) {
            cout << "Коефіцієнт підсилення: " << *gain << endl;
            cout << "Напруга живлення: " << *voltage << " В" << endl;
        }
        else {
            cout << "Помилка: дані відсутні" << endl;
        }
        cout << "Кількість входів: " << inputs << endl << endl;
    }
};