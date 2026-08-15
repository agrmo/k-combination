#include "Printabacus.h"
#include "abacus/Abacus.h"
#include "print/pointervector/Printpointervector.h"
#include "print/vector/Printvector.h"
#include <iostream>

void printabacus(Abacus* abacus) {

  int size = abacus -> size;
  std::cout << "Abacus: Size: " << size << " (max bead = " << size - 1 << ")\n";

  std::cout << "        Beads: ";
  printvector(abacus -> beads);

  std::cout << "        Fullbeads: ";
  printvector(abacus -> fullbeads);

  std::cout << "        Can move right: [";

  for (int i = 0; i < (abacus -> beads).size(); i++) {
    if (i != 0) {
      std::cout << ", ";
    }
    
    if (abacus -> canmoveright(i)) {
      std::cout << "yes";
    } else {
      std::cout << "no";
    }
  }

  std::cout << "]\n";
}
