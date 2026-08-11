#include "Abacus.h"
#include <iostream>
#include <vector>
#include <stdexcept>

Abacus::Abacus(int s, int b) {
  size = s;
  
  beads = new std::vector<int>(b);

  for (int i = 0; i < b; i++) {
    beads -> at(i) = i;
  }
}

Abacus::~Abacus() {
  std::cout << "Deleting Abacus size " << size << "\n";
  delete beads;
}

bool Abacus::canmoveright(int b) {
  if (b >= beads -> size()) {
    throw std::runtime_error("Abacus: b not a bead index.");
  }

  // If there is any bead to the right of b, return false.
  for (int i = 0; i < beads -> size(); i++) {
    if (beads -> at(i) == (b+1)) {
      return false;
    }
  }

  return true;
}

void Abacus::moveright(int b) {
  if (!canmoveright(b)) {
    throw std::runtime_error("Abacus: cannot move right.");
  } else if (b + 1 >= size) {
    throw std::runtime_error("Abacus: bead already at end (or beyond).");
  }

  beads -> at(b) += 1;
}
