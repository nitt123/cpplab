#include "LinkedList.h"
#include <windows.h>
#include <limits>

OpAmp createOpAmp() {
    OpAmp temp;
    std::cin >> temp;
    return temp;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    LinkedList list;
    int choice;

    do {
        std::cout << "\n======== Меню Списку (ОП) ========\n";
        std::cout << "1. Додати на початок (push_front)\n";
        std::cout << "2. Додати в кінець (push_back)\n";
        std::cout << "3. Додати після елемента\n";
        std::cout << "4. Видалити з початку (pop_front)\n";
        std::cout << "5. Видалити з кінця (pop_back)\n";
        std::cout << "6. Видалити за значенням\n";
        std::cout << "7. Показати список\n";
        std::cout << "8. Очистити список\n";
        std::cout << "0. Вихід\n";
        std::cout << "Ваш вибір: ";

        if (!(std::cin >> choice)) {
            std::cerr << "Невірний ввід. Спробуйте ще раз." << std::endl;
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            continue;
        }

        try {
            switch (choice) {
            case 1:
                list.push_front(createOpAmp());
                std::cout << "Успішно додано на початок." << std::endl;
                break;
            case 2:
                list.push_back(createOpAmp());
                std::cout << "Успішно додано в кінець." << std::endl;
                break;
            case 3: {
                std::cout << "--> Введіть параметри елемента, ПІСЛЯ якого вставити:" << std::endl;
                OpAmp target = createOpAmp();
                std::cout << "--> Введіть новий елемент:" << std::endl;
                OpAmp newData = createOpAmp();
                list.insert_after(target, newData);
                std::cout << "Успішно вставлено." << std::endl;
                break;
            }
            case 4:
                list.pop_front();
                std::cout << "Видалено перший елемент." << std::endl;
                break;
            case 5:
                list.pop_back();
                std::cout << "Видалено останній елемент." << std::endl;
                break;
            case 6: {
                std::cout << "--> Введіть елемент для видалення:" << std::endl;
                OpAmp target = createOpAmp();
                list.remove_val(target);
                std::cout << "Елемент видалено." << std::endl;
                break;
            }
            case 7:
                std::cout << "\n--- Вміст Списку ---\n";
                list.display();
                break;
            case 8:
                list.clear();
                std::cout << "Список очищено." << std::endl;
                break;
            case 0:
                std::cout << "Вихід..." << std::endl;
                break;
            default:
                std::cout << "Невірна опція." << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка операції: " << e.what() << std::endl;
        }

    } while (choice != 0);

    return 0;
}