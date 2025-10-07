#include <iostream>
using namespace std;

class Operational_Amplifier
{
private:
    double* Gain = nullptr;
    double* supply_voltage = nullptr;
    int* number_of_inputs = nullptr;

public:
    void setGain(double g) {
        if (g < 0) {
            cout << "Помилка: коефіцієнт підсилення не може бути від'ємним!\n";
        } else {
            delete Gain; 
            Gain = new double(g);
        }
    }

    void setSupplyVoltage(double v) {
        if (v <= 0) {
            cout << "Помилка: напруга живлення повинна бути більшою за 0!\n";
        } else {
            delete supply_voltage;
            supply_voltage = new double(v);
        }
    }

    void setNumberOfInputs(int n) {
        if (n <= 0) {
            cout << "Помилка: кількість входів повинна бути більшою за 0!\n";
        } else {
            delete number_of_inputs;
            number_of_inputs = new int(n);
        }
    }

    Operational_Amplifier(double g, double v, int n) {
        setGain(g);
        setSupplyVoltage(v);
        setNumberOfInputs(n);
        cout << "Параметризований конструктор\n";
    }

    Operational_Amplifier() {
        setGain(1);
        setSupplyVoltage(1);
        setNumberOfInputs(1);
        cout << "Звичайний конструктор\n";
    }

    ~Operational_Amplifier() {
        delete Gain;
        delete supply_voltage;
        delete number_of_inputs;
        cout << "Деструктор: пам'ять звільнено\n";
    }

    void printinfo() {
        cout << "Коефіцієнт підсилення: " << *Gain << "\n";
        cout << "Напруга живлення: " << *supply_voltage << " В\n";
        cout << "Кількість входів: " << *number_of_inputs << "\n";
    }

    void inputinfo() {
        double g;
        cout << "Введи коефіцієнт підсилення: ";
        cin >> g;
        setGain(g);

        double s;
        cout << "Введи напругу живлення (В): ";
        cin >> s;
        setSupplyVoltage(s);

        int n;
        cout << "Введи кількість входів: ";
        cin >> n;
        setNumberOfInputs(n);
    }
    void checkCriteria(double minGain, double minVoltage, int minInputs) {
        if (*Gain >= minGain && *supply_voltage >= minVoltage && *number_of_inputs >= minInputs) {
            cout << "\n=== Знайдено підсилювач, що відповідає критеріям ===\n";
            printinfo();
        } else {
            cout << "\nПідсилювач не відповідає критеріям:\n";
            if (*Gain < minGain) cout << "- Коефіцієнт підсилення менший за " << minGain << "\n";
            if (*supply_voltage < minVoltage) cout << "- Напруга живлення менша за " << minVoltage << " В\n";
            if (*number_of_inputs < minInputs) cout << "- Кількість входів менша за " << minInputs << "\n";
        }
    }
    void copy(const Operational_Amplifier& other){
        setGain(*other.Gain);
        setSupplyVoltage(*other.supply_voltage);
        setNumberOfInputs(*other.number_of_inputs);
        cout << "\nДані було успішно скопійованно у інший клас:\n";
        printinfo();
    }
};

int main() {
    setlocale(LC_ALL, "ukr");

    Operational_Amplifier r1;
    r1.inputinfo();     

    cout << "\n=== Перевірка r1 за критеріями (мін. Gain=1, V=5В, inputs=2) ===\n";
    r1.checkCriteria(5, 7, 9);

    cout << "\n";

    Operational_Amplifier r2(10, 12, 5); 
    cout << "\n=== Перевірка r2 за критеріями (мін. Gain=1, V=5В, inputs=2) ===\n";
    r2.checkCriteria(1, 5, 2);
    Operational_Amplifier r3;
    r3.copy(r2);

    return 0;
}