#include <iostream>
using namespace std;

class Operational_Amplifier
{
private:
    double Gain;
    double supply_voltage;
    int number_of_inputs;
public:
    Operational_Amplifier(double r, double p, int a) {
        Gain = r;
        supply_voltage = p;
        number_of_inputs = a;
        cout << "Parameterized constructor\n";
    }
    Operational_Amplifier() {
        Gain = 0;
        supply_voltage = 0;
        number_of_inputs = 0;
        cout << "Звичайний конструктор\n";
    }
    ~Operational_Amplifier() {
    cout << "дуструктор" << Gain << "\n";
    }
    void printinfo(){
        cout<<"Коефіцієнт підсилення: "<<Gain<<"\n";
        cout<<"Напруга живлення: "<<supply_voltage<<"v\n";
        cout<<"Кількість входів: "<<number_of_inputs<<"\n";

    }
    void inputinfo() {
        cout << "Введи коефіцієнт підсилення: ";
        cin >> Gain;

        cout << "Введи напругу живлення(v): ";
        cin >> supply_voltage;
        cout << "Введи кількість входів: ";
        cin >> number_of_inputs;
    }
};


int main() {
    setlocale (LC_CTYPE, "ukr");
    Operational_Amplifier r1;
    r1.inputinfo();     
    r1.printinfo();     

    cout << "\n";

    Operational_Amplifier r2(1000, 0.25, 5); 
    r2.printinfo();

    return 0;
}