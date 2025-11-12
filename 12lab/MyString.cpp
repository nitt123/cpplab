#include "MyString.h"
#include <algorithm>

MyString::MyString(const std::string& str) : data(str) {}

MyString::~MyString() {}

std::string MyString::getData() const {
    return data;
}

size_t MyString::length() const {
    return data.length();
}

bool MyString::operator>=(const MyString& other) const {
    return this->data >= other.data;
}

MyString MyString::operator-(char charToRemove) const {
    std::string newStr = this->data;

    newStr.erase(std::remove(newStr.begin(), newStr.end(), charToRemove), newStr.end());

    return MyString(newStr);
}

std::ostream& operator<<(std::ostream& os, const MyString& obj) {
    os << "\"" << obj.data << "\"";
    return os;
}

void sortStringArray(std::vector<MyString>& arr) {
    std::sort(arr.begin(), arr.end(), [](const MyString& a, const MyString& b) {
        return !(a >= b);
        });
}