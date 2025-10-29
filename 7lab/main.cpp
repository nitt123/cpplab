#include <iostream>
#include "Operational_Amplifier.h"
#include "windows.h"

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    OperationalAmplifier op_1;
	op_1.addOpAmp(120.5, 15.0, 2);
	op_1.addOpAmp(100.0, 9.0, 4);
	op_1.printAll();
	int free_slot = op_1.getFreeSlots();
	std::cout << "���� ���� " << free_slot << std::endl;
	op_1.insertOpAmp(1, 150.0, 12.0, 2);
	op_1.swapOpAmps(0, 2);
	op_1.removeOpAmp(0);
	op_1.printAll();
	op_1.clearStorage();
	op_1.printAll();

    return 0;
}