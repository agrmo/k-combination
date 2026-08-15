#include "abacus/Abacus.h"
#include "Abacusfactory.h"
#include <vector>
#include <iostream>

Abacus* truncateterminal(Abacus* parent) {

  // First find the terminal bead.
  // We know where it is, it's always at the end of beads.  
  int terminalindex = (parent -> beads).size() - 1;
  int terminal = (parent -> beads).at(terminalindex);

  // The terminal value becomes the size of the subabacus.
  int size = terminal;

  // Now find the beads from a within size size.
  std::vector<int> beads(0);

  for (int i = 0; i < (parent -> beads).size(); i++) {
    if ((parent -> beads).at(i) < size) {

      // Make a copy of each bead value.
      beads.push_back((parent -> beads).at(i));
    }
  }

  // Done. Build the subabacus.
  Abacus* child = new Abacus(size, beads, parent -> fullbeads);

  // Needs delete.
  return child;
}
