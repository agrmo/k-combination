#ifndef SUBABACUS_H
#define SUBABACUS_H

#include "abacus/Abacus.h"
#include <vector>

// A Subabacus is similar to an Abacus except its beads are pointers
// to the parent's beads. The size is smaller than the parent's size,
// and both are indexed at 0 at the same location. So the only
// different between the two is their size and the number of beads.

// Using inheritance is not a good idea because the underlying data
// structure is different: integers vs pointers to integers.

// Using a single class (combining Abacus and Subabacus) is not a good
// idea because it overcomplicates the parent class. We need Subabacus
// to have pointers. Abacus doesn't need pointers.

// This kind of data structure is useful for constructing recursive
// algorithms on subintervals of integers.

class Subabacus {

public:

  int size;

  // Store a pointer to the parent Abacus beads, only for the purpose
  // of saving the whole bead sequence when we have found a unique
  // combination.
  //
  // I think we can simplify the algorithm by not building a new bead
  // list but I'm not so confident it will accomplish much.
  std::vector<int>* parentbeads;

  // c.f. Abacus: beads: std::vector<int>*
  std::vector<int*>* beads;

  // Construct a Subabacus given the parent Abacus, by making pointers
  // to the parent's beads instead of making new integers. The size is
  // smaller than the parent Abacus. All beads smaller than the given
  // size will not be added to this Subabacus. We are effectively
  // truncating the Abacus at a position, and then making its beads
  // point to a parent's beads.
  Subabacus(int s, std::vector<int*>* b, std::vector<int>* pb);
  ~Subabacus();

  // Return number of beads.
  int numberofbeads();

  // Can the bth bead move right?
  // b is the index of beads, not the location of the bead.
  bool canmoveright(int b);

  // Move the bth bead to the right.
  void moveright(int b);

  // Can the terminal bead move right?
  bool terminalcanmoveright();
};

#endif
