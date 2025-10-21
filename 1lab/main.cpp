#include <iostream>
#include "windows.h"
#include <locale>
using namespace std;

int main()
{
  SetConsoleOutputCP(CP_UTF8);
  for (int i = 0;i<10;i++) {
    cout<<i<<endl;
  }

  return 0;
}