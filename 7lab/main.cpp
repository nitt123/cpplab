#include <iostream>
using namespace std;

class Operational_Amplifier
{
public:
    double Gain;
    double supply_voltage;
    double number_of_inputs;
    void printinfo(){
        cout<<"Gain: "<<Gain<<"\n";
        cout<<"supply_voltage: "<<supply_voltage<<"в\n";
        cout<<"number_of_inputs: "<<number_of_inputs<<"\n";

    }
};


int main() {
  Operational_Amplifier r1; 
  r1.number_of_inputs=10;
  r1.Gain=1000;
  r1.supply_voltage=10;
  r1.printinfo();
  return 0;
}