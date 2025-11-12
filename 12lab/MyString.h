#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class MyString {
private:
    std::string data;

public:
    MyString(const std::string& str = "");
    ~MyString();

    std::string getData() const;

    size_t length() const;

    bool operator>=(const MyString& other) const;

    MyString operator-(char charToRemove) const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
};

void sortStringArray(std::vector<MyString>& arr);