
#include <iostream>
#include <vector>
#include <stdexcept>
#include "abacus/Abacus.h"

Subabacus::Subabacus(int s, Abacus* a) {
  
  // I don't think we need to store the pointer.
  size = s;

  // We don't know how many beads are in the parent Abacus yet. Parse
  // that now. We will store at most s beads.
  beads = new std::vector<int*>(0);

  // For each bead in the parent, if its index is below s, then it
  // will also be in this Subabacus. Store it.
  for (int i = 0; i < a -> beads -> size(); i++) {

    if (a -> beads -> at(i) < s) {
      
      // wowzers
      beads -> push_back(a -> beads -> at(i));
    }
  }
}

Subabacus::~Subabacus() {
  std::cout << "Deleting Subabacus size " << size << "\n";
  delete beads;
}

bool Subabacus::canmoveright(int b) {
  if (b >= beads -> size()) {
    throw std::runtime_error("Subabacus: b not a bead index.");
  }

  // Get the location of the bead.
  int loc = beads -> at(b);

  // If the bead is at the end, return false.
  if (loc + 1 >= size) {
    return false;
  }

  // If the location + 1 of bead b is equal to the location of another
  // bead, return false.
  for (int i = 0; i < beads -> size(); i++) {
    if (beads -> at(i) == loc + 1) {
      return false;
    }
  }

  return true;
}

void Subabacus::moveright(int b) {
  if (!canmoveright(b)) {
    throw std::runtime_error("Subabacus: cannot move right.");
  }

  beads -> at(b) += 1;
}
