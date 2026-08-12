#include <iostream>

void exampleone() {
  int a = 1;
  int& b = a;
  b += 1;
  
  std::cout << b << "\n";
  
  int c = 8;
  b = c;
  b += 1;

  std::cout << b << "\n";
}

int main() {
  exampleone();
}
