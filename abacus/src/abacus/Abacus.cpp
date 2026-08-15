#include "Abacus.h"
#include <iostream>
#include <vector>
#include <stdexcept>

// There are two constructors. One to build a whole new abacus and
// one to build a subabacus.
Abacus::Abacus(int s, int b) {
  size = s;
  
  std::vector<int> bl(b);
  std::vector<int> fbl(b);

  for (int i = 0; i < b; i++) {

    // Take the int, put it in the vector.
    bl.at(i) = i;    
    fbl.at(i) = i;
  }

  beads = bl;
  fullbeads = fbl;
}

// The second constructor. We are given the data already by a factory.
Abacus::Abacus(int s, std::vector<int> b, std::vector<int> fb) {
  size = s;
  beads = b;
  fullbeads = fb;
}

Abacus::~Abacus() {

}

bool Abacus::canmoveright(int b) {
  if (b >= beads.size()) {
    throw std::runtime_error("Abacus: b not a bead index.");
  }

  // Get the location of the bead.
  int loc = beads.at(b);
  
  // If the bead is at the end, return false.
  if (loc + 1 >= size) {
    return false;
  }

  // If the location + 1 of bead b is equal to the location of another
  // bead, return false.
  for (int i = 0; i < beads.size(); i++) {
    if (beads.at(i) == loc + 1) {
      return false;
    }
  }

  return true;
}

int Abacus::numberofbeads() {
  return beads.size();
}

void Abacus::moveright(int b) {
  if (!canmoveright(b)) {
    throw std::runtime_error("Abacus: cannot move right.");
  }

  beads.at(b) += 1;
  fullbeads.at(b) += 1;
}

bool Abacus::terminalcanmoveright() {

  int terminalindex = numberofbeads() - 1;
  
  return canmoveright(terminalindex);
}

void Abacus::moveterminalright() {

  int terminalindex = numberofbeads() - 1;

  if (!canmoveright(terminalindex)) {
    throw std::runtime_error("Abacus: cannot move right.");
  }
  
  moveright(terminalindex);
}
