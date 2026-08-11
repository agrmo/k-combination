#include "Printabacus.h"
#include "abacus/Abacus.h"
#include "print/vector/Vectorprint.h"
#include <iostream>

void printabacus(Abacus* abacus) {

  std::cout << "Abacus: Size: " << abacus -> size << " (max bead = " << abacus -> size - 1 << ")\n";

  std::cout << "        Beads: ";
  
  vectorprint(abacus -> beads);
}
