#include "operational_amplifier.h"

int main() {
    Operational_Amplifier opa;

    opa.inputData();
    opa.printData();
    opa.setAmplifier(0, 100.5, 12, 2);  
    opa.setAmplifier(1, -5, 9, 1);       
    opa.setAmplifier(2, 50, 0, 3);     
    opa.setAmplifier(5, 10, 5, 2);    

    opa.printData(); 
    return 0;
}
