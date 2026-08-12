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

int Abacus::numberofbeads() {
  return beads -> size();
}

void Abacus::moveright(int b) {
  if (!canmoveright(b)) {
    throw std::runtime_error("Abacus: cannot move right.");
  }

  beads -> at(b) += 1;
}

