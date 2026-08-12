#include <iostream>
#include "Pairlist.h"
#include "print/pairlist/Printpairlist.h"

void exampleone() {
  Pairlist a;

  a.add(3,4);

  int* p = a.get(0);

  std::cout << *p << "\n";
  std::cout << *(p+1) << "\n";

  a.add(5,6);

  p = a.get(1);

  std::cout << *p << "\n";
  std::cout << *(p+1) << "\n";
}

void exampletwo() {
  Pairlist a;

  a.add(1,2);
  a.add(3,4);

  printpairlist(&a);
}

void examplethree() {
  Pairlist a;

  a.add(1,2);
  a.add(3,4);

  int max = a.getmax();

  std::cout << max << "\n";
}

int main() {
  examplethree();
}
