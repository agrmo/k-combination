#include "Printsubabacus.h"
#include "subabacus/Subabacus.h"
#include "print/pointervector/Pointervectorprint.h"
#include <iostream>

void printsubabacus(Subabacus* sa) {

  int size = sa -> size;
  std::cout << "Subabacus: Size: " << size << " (max bead = " << size - 1 << ")\n";

  std::cout << "        Beads: ";
  pointervectorprint(sa -> beads);

  std::cout << "        Can move right: [";

  for (int i = 0; i < sa -> beads -> size(); i++) {
    if (i != 0) {
      std::cout << ", ";
    }
    
    if (sa -> canmoveright(i)) {
      std::cout << "yes";
    } else {
      std::cout << "no";
    }
  }

  std::cout << "]\n";
}
