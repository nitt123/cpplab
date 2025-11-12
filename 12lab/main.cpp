#include "MyString.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <windows.h>
void printArray(const std::string& title, const std::vector<MyString>& arr) {
    std::cout << "\n--- " << title << " ---\n";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << "[" << i << "] " << arr[i] << " (Length: " << arr[i].length() << ")\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);



    std::vector<MyString> myStrings = {
        MyString("Банан"),
        MyString("Яблуко"),
        MyString("Вишня"),
        MyString("Авокадо"),
        MyString("Ананас"),
    };
	printArray("Початковий Масив", myStrings);
    std::cout << "Тестуємо оператор >= \n";
    MyString strA("Вишня");
    MyString strB("Банан");
    MyString strC("Ананас");

    std::cout << strA << " >= " << strB << ": " << (strA >= strB ? "True" : "False") << "\n";
    std::cout << strB << " >= " << strA << ": " << (strB >= strA ? "True" : "False") << "\n";
    std::cout << strA << " >= " << strC << ": " << (strA >= strC ? "True" : "False") << "\n";
    sortStringArray(myStrings);
    printArray("Відсортований Масив", myStrings);
    char charToRemove = 'а';
    std::vector<MyString> modifiedStrings;
    for (const auto& str : myStrings) {
        modifiedStrings.push_back(str - charToRemove);
    }
    printArray(std::string("Масив після видалення символу ") + charToRemove , modifiedStrings);

	return 0;
}