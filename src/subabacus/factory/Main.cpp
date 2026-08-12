#include "Subabacusfactory.h"
#include "abacus/Abacus.h"
#include "print/abacus/Printabacus.h"
#include "print/subabacus/Printsubabacus.h"
#include "subabacus/Subabacus.h"
#include "subabacus/factory/Subabacusfactory.h"
#include <iostream>

void exampleone() {
  Abacus* a = new Abacus(5, 3);
  printabacus(a);
  
  Subabacus* sa = truncateterminal(a);
  
  printsubabacus(sa);
  
  delete a;
  delete sa;
}

int main() {
  exampleone();
}
