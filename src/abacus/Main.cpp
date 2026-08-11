#include <iostream>
#include "Abacus.h"
#include "print/abacus/Printabacus.h"

int main() {
  Abacus* a = new Abacus(5);
  printabacus(a);
  delete a;
}
