#ifndef ABACUSFACTORY_H
#define ABACUSFACTORY_H

#include "abacus/Abacus.h"

// Given an abacus, make a subabacus by truncating the terminal bead.
//
// E.g. given
//
//   x x   x
// 0 1 2 3 4 5 6
//
// Make the subabacus
//
//   x x
// 0 1 2 3
//
// A couple necessary things for algorithmic purposes:
// - The subabacus starts at the same location. In other words the
//   truncation only happens on the right side.
// - The subabacus size is the location of the terminal bead - 1.
// - The locations below the terminal bead remain, even if unoccupied.
Abacus* truncateterminal(Abacus* a);

#endif
