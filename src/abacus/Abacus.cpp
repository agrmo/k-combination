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
  for (int i = 0; i < size; i++) {
    if (beads -> at(i) == (b+1)) {
      return false;
    }
  }

  return true;
}

void Abacus::moveright(int b, int amount) {
  if (!canmoveright(b)) {
    throw std::runtime_error("Abacus: cannot move right.");
  } else if (b + amount >= size) {
    throw std::runtime_error("Abacus: bead already at end (or beyond).");
  }

  beads -> at(b) += amount;
}
