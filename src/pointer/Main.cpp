#include <iostream>
using namespace std;

void exampleone() {
  string essen = "Brot";
  cout << essen << endl; // "Brot"
  cout << &essen << endl; // 0x
}

void exampletwo() {
  string essen = "Brot";
  string* zeiger = &essen;
  cout << zeiger << endl; // 0x  
}

void examplethree() {
  int a = 1;
  int& b = a;
  b += 1;
  cout << a << "\n";
  cout << b << "\n";
}

int main() {
  examplethree();
}
