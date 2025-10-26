#include <iostream>
#include "Operational_Amplifier.h"
#include "windows.h"

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    OperationalAmplifier op_amp_manager_1;

    op_amp_manager_1.printAll();

    op_amp_manager_1.addOpAmp(120.5, 15.0, 2);
    op_amp_manager_1.addOpAmp(100.0, 9.0, 4);

    std::cout << "\nΒ³λόνθυ μ³ρφό: "
        << op_amp_manager_1.getFreeSlots() << std::endl;

    op_amp_manager_1.printAll();

    op_amp_manager_1.addOpAmp(0, 12.0, 2);
    op_amp_manager_1.addOpAmp(150.0, 0, 2);
    op_amp_manager_1.addOpAmp(200.0, -5.0, -1);

    op_amp_manager_1.printAll();

    {
        OperationalAmplifier op_amp_manager_2;
        op_amp_manager_2.addOpAmp(75.0, 5.0, 8);
        op_amp_manager_2.printAll();
    }

    op_amp_manager_1.printAll();

    op_amp_manager_1.addOpAmp(10.0, 3.3, 1);
    op_amp_manager_1.addOpAmp(50.0, 12.0, 2);
    op_amp_manager_1.addOpAmp(1.0, 1.0, 1);

    op_amp_manager_1.printAll();

    return 0;
}