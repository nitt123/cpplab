#include <iostream>
using namespace std;

class Operational_Amplifier
{
private:
    double Gain;
    double supply_voltage;
    int number_of_inputs;
public:
    Operational_Amplifier(double r, double p, double a) {
        Gain = r;
        supply_voltage = p;
        number_of_inputs = a;
        cout << "Parameterized constructor called\n";
    }
    Operational_Amplifier() {
        Gain = 0;
        supply_voltage = 0;
        number_of_inputs = 0;
        cout << "Default constructor called\n";
    }
    ~Operational_Amplifier() {
    cout << "Destructor called for Operational_Amplifier " << Gain << " Ohm\n";
    }
    void printinfo(){
        cout<<"Gain: "<<Gain<<"Ohm\n";
        cout<<"supply voltage: "<<supply_voltage<<"w\n";
        cout<<"number of inputs: "<<number_of_inputs<<"%\n";

    }
    void inputinfo() {
        cout << "Enter Gain (Ohm): ";
        cin >> Gain;
        cout << "Enter maximum power dissipation (W): ";
        cin >> supply_voltage;
        cout << "Enter number of inputs class (%): ";
        cin >> number_of_inputs;
    }
};


int main() {
    Operational_Amplifier r1;
    r1.inputinfo();     
    r1.printinfo();     

    cout << "\n";

    Operational_Amplifier r2(1000, 0.25, 5); 
    r2.printinfo();

    return 0;
}