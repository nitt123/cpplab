#include <iostream>
using namespace std;

class resistor
{
public:
    double resistance;
    double maximum_power_dissipation;
    double accuracy;
    void printinfo(){
        cout<<"resistance: "<<resistance<<"om\n";
        cout<<"maximum_power_dissipation: "<<maximum_power_dissipation<<"w\n";
        cout<<"accuracy: "<<accuracy<<"%\n";

    }
};


int main() {
  resistor r1; 
  r1.accuracy=10;
  r1.resistance=1000;
  r1.maximum_power_dissipation=10;
  r1.printinfo();
  return 0;
}