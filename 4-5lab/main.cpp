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
        setGain(0);
        setSupplyVoltage(0);
        setNumberOfInputs(0);
        cout << "Звичайний конструктор\n";
    }
    ~Operational_Amplifier() {
        delete Gain;
        delete supply_voltage;
        delete number_of_inputs;
        cout << "Деструктор: пам'ять звільнено\n";
    }
    void printinfo(){
        cout<<"Коефіцієнт підсилення: "<<*Gain<<"\n";
        cout<<"Напруга живлення: "<<*supply_voltage<<"v\n";
        cout<<"Кількість входів: "<<*number_of_inputs<<"\n";

    }
    void inputinfo() {
        double g;
        cout << "Введи коефіцієнт підсилення: ";
        cin >> g;
        setGain(g);

        double s;
        cout << "Введи напругу живлення(v): ";
        cin >> s;
        setSupplyVoltage(s);
        int n;
        cout << "Введи кількість входів: ";
        cin >> n;
        setNumberOfInputs(n);
    }
};


int main() {
    setlocale (LC_CTYPE, "ukr");
    Operational_Amplifier r1;
    r1.inputinfo();     
    r1.printinfo();     

    cout << "\n";

    Operational_Amplifier r2(1, 0.25, 5); 
    r2.printinfo();

    return 0;
}