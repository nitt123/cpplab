#include <iostream>
#include "windows.h"
#include <locale>
using namespace std;

int main()
{
  SetConsoleOutputCP(CP_UTF8);
  cout << "Hello world" << endl;

}