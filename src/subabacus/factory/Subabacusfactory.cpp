#include "abacus/Abacus.h"
#include "subabacus/Subabacus.h"
#include "Subabacusfactory.h"
#include <vector>

Subabacus* truncateterminal(Abacus* parent) {
  // First find the terminal bead.
  // We know where it is, it's always at the end of beads.
  int terminalindex = parent -> beads -> size() - 1;
  int terminal = parent -> beads -> at(terminalindex);

  // The Subabacus size is also terminal.
  // For clarity.
  int size = terminal;
    
  // Now find the beads from a within size size.  Crucially we are
  // making pointers to the parent Abacus' beads. We don't know the
  // number of beads within size size yet. Search now.
  std::vector<int*>* beads = new std::vector<int*>(0);

  for (int i = 0; i < parent -> beads -> size(); i++) {
    if (parent -> beads -> at(i) < size) {
      beads -> push_back(&(parent -> beads -> at(i)));
    }
  }

  // Done. Build the Subabacus.

  Subabacus* child = new Subabacus(size, beads, parent -> beads);

  // Note needs delete.

  return child;
}

Subabacus* truncateterminal(Subabacus* parent) {

  // Similar idea, but now we need to dereference the beads.
  
  int terminalindex = parent -> beads -> size() - 1;
  int terminal = *(parent -> beads -> at(terminalindex));

  int size = terminal;

  // Same references, same beads, but one less bead.
  std::vector<int*>* beads = new std::vector<int*>(0);

  for (int i = 0; i < parent -> beads -> size(); i++) {
    if (*(parent -> beads -> at(i)) < size) {

      // I think it's okay to use the same pointer.  So I think it's
      // okay if two Subabaci use the same pointer to one particular
      // bead. I think the call stack will allow for that because we
      // don't really care what the subbeads do in one particlar
      // iteration of the while loop at a particular bead level. The
      // bead is fully dereferenced when a Subabacus is created
      // anyway, so I don't think it would make a difference anyway.
      
      beads -> push_back(parent -> beads -> at(i));
    }
  }
  
  Subabacus* child = new Subabacus(size, beads, parent -> parentbeads);

  // Note needs delete.

  return child;
}
