#include "RadioStation.h"
#include "BaseStation.h"
#include "PortableRadio.h"
#include <vector>
#include <algorithm>
#include <memory> 
#include <windows.h> 
#include <sstream>
#include <limits>

const std::string FILENAME = "radio_data.txt";

void saveDataToFile(const std::vector<std::unique_ptr<RadioStation>>& stations) {
    std::ofstream ofs;
    try {
        ofs.open(FILENAME, std::ios::out | std::ios::app);
        if (!ofs.is_open()) {
            throw RadioStationException("Не вдалося відкрити файл для запису: " + FILENAME);
        }

        for (const auto& station : stations) {
            station->writeToFile(ofs);
        }

        ofs.close();
        std::cout << "\nДані успішно додано у файл " << FILENAME << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Виняток під час збереження файлу: " << e.what() << std::endl;
        if (ofs.is_open()) ofs.close();
    }
}

std::vector<std::unique_ptr<RadioStation>> loadDataFromFile() {
    std::vector<std::unique_ptr<RadioStation>> stations;
    std::ifstream ifs;
    try {
        ifs.open(FILENAME, std::ios::in);
        if (!ifs.is_open()) {
            std::cout << "\nПопередження: Файл даних " << FILENAME << " не знайдено або не вдалося відкрити. Починаємо з чистого списку." << std::endl;
            return stations;
        }

        std::string line;
        while (std::getline(ifs, line)) {
            if (line.empty()) continue;

            int type = 0;
            try {
                type = std::stoi(line);
            }
            catch (const std::exception& e) {
                std::cerr << "Помилка Вводу: " << e.what() << std::endl;
                throw RadioStationException("Помилка читання або конвертації типу об'єкта з файлу. Можливе пошкодження файлу.");
            }

            std::unique_ptr<RadioStation> station;
            if (type == 1) {
                station = std::make_unique<BaseStation>();
            }
            else if (type == 2) {
                station = std::make_unique<PortableRadio>();
            }
            else {
                throw RadioStationException("Прочитано невідомий тип об'єкта з файлу.");
            }

            station->readFromFile(ifs);
            stations.push_back(std::move(station));
        }

        ifs.close();
        std::cout << "\nДані успішно завантажено з файлу " << FILENAME << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Виняток під час завантаження файлу: " << e.what() << std::endl;
        if (ifs.is_open()) ifs.close();
    }
    return stations;
}

std::unique_ptr<RadioStation> createNewStation() {
    int choice;
    std::unique_ptr<RadioStation> newStation = nullptr;

    std::cout << "\n--- Створення нової Радіостанції ---\n";
    std::cout << "1. Базова Станція\n";
    std::cout << "2. Портативна Рація\n";
    std::cout << "Введіть вибір (1 або 2): ";
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        throw RadioStationException("Неприпустимий ввід для вибору типу станції.");
    }

    try {
        if (choice == 1) {
            newStation = std::make_unique<BaseStation>();
            std::cin >> *newStation;
        }
        else if (choice == 2) {
            newStation = std::make_unique<PortableRadio>();
            std::cin >> *newStation;
        }
        else {
            std::cout << "Невірний вибір. Створення скасовано." << std::endl;
            return nullptr;
        }
    }
    catch (const RadioStationException& e) {
        std::cerr << "Помилка Вводу: " << e.what() << std::endl;
        return nullptr;
    }
    catch (const std::exception& e) {
        std::cerr << "Загальна Помилка Вводу: " << e.what() << std::endl;
        return nullptr;
    }
    return newStation;
}

void printStations(const std::vector<std::unique_ptr<RadioStation>>& stations) {
    if (stations.empty()) {
        std::cout << "\nУ масиві немає радіостанцій." << std::endl;
        return;
    }
    std::cout << "\n--- Перелік Радіостанцій ---\n";
    for (size_t i = 0; i < stations.size(); ++i) {
        std::cout << "[" << i + 1 << "] " << *stations[i] << std::endl;
    }
}


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::vector<std::unique_ptr<RadioStation>> stations;

    std::cout << "Зверніть увагу: Перед першим збереженням файлу 'radio_data.txt' необхідно видалити його, якщо він існує, для коректного збереження поточних даних.\n";

    int choice;

    do {
        std::cout << "\n======== Головне Меню ========\n";
        std::cout << "1. Додати нову Станцію (з перевіркою винятками)\n";
        std::cout << "2. Показати всі Станції\n";
        std::cout << "3. Сортувати Станції за Частотою (за спаданням, використовуючи оператор >)\n";
        std::cout << "4. Зберегти Дані у Файл (додавання до " << FILENAME << ")\n";
        std::cout << "5. Завантажити Дані з Файлу (замінює поточний список)\n";
        std::cout << "0. Вихід\n";
        std::cout << "Введіть свій вибір: ";

        if (!(std::cin >> choice)) {
            std::cerr << "Неприпустимий ввід в меню. Вихід..." << std::endl;
            break;
        }

        switch (choice) {
        case 1: {
            try {
                std::unique_ptr<RadioStation> newStation = createNewStation();
                if (newStation) {
                    stations.push_back(std::move(newStation));
                    std::cout << "Станцію успішно додано." << std::endl;
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Операція не вдалася: " << e.what() << std::endl;
            }
            break;
        }
        case 2:
            printStations(stations);
            break;
        case 3:
            if (stations.empty()) {
                std::cout << "Немає станцій для сортування." << std::endl;
                break;
            }
            std::sort(stations.begin(), stations.end(), [](const std::unique_ptr<RadioStation>& a, const std::unique_ptr<RadioStation>& b) {
                return *a > *b;
                });
            std::cout << "\nСтанції відсортовано за частотою (за спаданням)." << std::endl;
            printStations(stations);
            break;
        case 4:
            saveDataToFile(stations);
            break;
        case 5:
            stations = loadDataFromFile();
            break;
        case 0:
            std::cout << "Вихід з програми. До побачення!" << std::endl;
            break;
        default:
            std::cout << "Невірний вибір. Спробуйте ще раз." << std::endl;
        }
    } while (choice != 0);

    return 0;
}