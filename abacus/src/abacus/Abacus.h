#ifndef ABACUS_H
#define ABACUS_H

#include <vector>

// A dorky theft of a word, an "Abacus" here is a list of numbers, and
// a list of pointers to some of the numbers ("beads"). The beads
// (pointers) cannot "pass over" eachother in the same way that beads
// in an abacus cannot pass over eachother.

// Most importantly we will need a function, "canmoveright," which
// tells us if a particular bead has a free space to the right.

// We will restrict the implementation to a list of number 0..n and
// the beads are the number.

// e.g. Abacus of with 6 available positions and 3 beads.
//
// Bead          x   x x
//
// Locations 0 1 2 3 4 5
//
// Data implementation: locations: Array of ints [0, 1, 2, 3, 4, 5, 6]
//                      beads: Array of size 3 = [2, 4, 5]
//
// Thus we don't need the locations variable at all.
//
// Data implementation: size: 5
//                      beads: Array of size 3 = [2, 4, 5]
//
// The 0th bead is beads[0] and points to location 2.
// The 1st bead is beads[1] and points to location 4.
// The 2nd bead is beads[2] and points to location 5.
//
// Moving a bead is a simple function which checks if a bead can move
// in that direction and then does so.
//
// Everything is 0 indexed here.
//
// Furthermore we want this implementation to be fragmentable. That
// is, an abacus contains, in theory, smaller abaci within it. We will
// implement this by using a Abacus class. This Abacus can create a
// Abacus, whose beads are pointers to integers, instead of full
// integers, that point to the parent Abacus.
//
// This kind of data structure is useful for constructing recursive
// algorithms on subintervals of integers.


class Abacus {

public:

  int size;

  // This Abacus may be the subset of a larger Abacus.

  // The set of beads of this Abacus.
  std::vector<int> beads;

  // The full set of beads of the full Abacus.
  std::vector<int> fullbeads;

  // Make an Abacus with s positions and b number of beads. Put all
  // the beads on the left first. This will be a top level or parent
  // Abacus so to speak.
  Abacus(int s, int b);

  // We will also have a constructor for a subabacus from the factory.
  // Construct a subabacus given the parent abacus, by making pointers
  // to the parent's beads. The size is then smaller than the parent
  // abacus. All beads smaller than the given size will not be added
  // to this abacus. We are effectively truncating the abacus at a
  // position, and then making its beads point to the parent's beads.
  Abacus(int s, std::vector<int> b, std::vector<int> fullbeads);

  // Note the destructor is nontrivial.
  ~Abacus();

  // Return number of beads.
  int numberofbeads();

  // Can the bth bead move right?
  // b is the index of beads, not the location of the bead.
  bool canmoveright(int b);

  // Move the bth bead to the right.
  void moveright(int b);

  // Can the terminal bead move right?
  bool terminalcanmoveright();

  // Move the terminal bead right.
  // Throw an exception if cannot move right.
  void moveterminalright();
};

#endif
