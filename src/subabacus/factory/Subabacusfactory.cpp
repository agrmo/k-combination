#include "abacus/Abacus.h"
#include "subabacus/Subabacus.h"
#include "Subabacusfactory.h"
#include <vector>

Subabacus* truncateterminal(Abacus* a) {
  // First find the terminal bead.
  // We know where it is, it's always at the end of beads.
  int terminalindex = a -> beads -> size() - 1;
  int terminal = a -> beads -> at(terminalindex);

  // The Subabacus size is also terminal.
  // For clarity.
  int size = terminal;
    
  // Now find the beads from a within size size.  Crucially we are
  // making pointers to the parent Abacus' beads. We don't know the
  // number of beads within size size yet. Search now.
  std::vector<int*>* beads = new std::vector<int*>(0);

  for (int i = 0; i < a -> beads -> size(); i++) {
    if (a -> beads -> at(i) < size) {
      beads -> push_back(&(a -> beads -> at(i)));
    }
  }

  // Done. Build the Subabacus.

  Subabacus* sa = new Subabacus(size, beads);

  // Note needs delete.

  return sa;
}

// Subabacus* truncateterminal(Subabacus* saa) {
  
//   // Done. Build the Subabacus.

//   Subabacus* sab = new Subabacus(size, beads);

//   // Note needs delete.
// }
