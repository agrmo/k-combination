#include <iostream>
#include "Abacus.h"
#include "print/abacus/Printabacus.h"

void exampleone() {
  Abacus* a = new Abacus(5, 3);
  printabacus(a);
  delete a;
}

void exampletwo() {
  Abacus* a = new Abacus(5, 3);
  printabacus(a);
  delete a;
}

int main() {
  exampleone();
}
