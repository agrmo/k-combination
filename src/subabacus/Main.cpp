#include <iostream>

#include "abacus/Abacus.h"
#include "Factory.h"
#include "Subabacus.h"

void exampleone() {
  Abacus* a = new Abacus(5, 3);
  printabacus(a);
  
  Subabacus* sa = truncateterminal(a);
  printsubabacus(sa);
  
  delete a;
}

int main() {
  exampleone();
}
