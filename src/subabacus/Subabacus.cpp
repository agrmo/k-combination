#include "Subabacus.h"
#include "abacus/Abacus.h"
#include <iostream>
#include <stdexcept>
#include <vector>

// Only the factory builds Subabaci so we just need a simple
// constructor for now.
Subabacus::Subabacus(int s, std::vector<int*>* b) {

  if (b -> size() > s) {
    throw std::runtime_error("Given more beads than size of Subabacus.");
  }
  
  size = s;
  beads = b;
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
  int loc = *(beads -> at(b));

  // If the bead is at the end, return false.
  if (loc + 1 >= size) {
    return false;
  }

  // If the location + 1 of bead b is equal to the location of another
  // bead, return false.
  for (int i = 0; i < beads -> size(); i++) {
    if (*(beads -> at(i)) == loc + 1) {
      return false;
    }
  }

  return true;
}

void Subabacus::moveright(int b) {
  if (!canmoveright(b)) {
    throw std::runtime_error("Subabacus: cannot move right.");
  }

  std::cout << "Move bead " << b << " value " << *(beads -> at(b)) << " right.";

  *(beads -> at(b)) += 1;
}
