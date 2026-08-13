#ifndef SUBABACUSFACTORY_H
#define SUBABACUSFACTORY_H

#include "abacus/Abacus.h"
#include "subabacus/Subabacus.h"

// Given an Abacus, make a Subabacus by truncating the terminal bead.
//
// e.g.
// Given
//
//   x x   x
// 0 1 2 3 4 5 6
//
// Make the Subabacus
//
//   x x
// 0 1 2 3
//
// A couple necessary things for algorithmic purposes:
// - The size is the location of the terminal bead - 1.
// - The beads below the terminal bead stay the same.
Subabacus* truncateterminal(Abacus* a);

// Same thing as truncateterminal(Abacus* a) except now for a
// Subabacus.
//
// Note
// - The beads do not become pointer pointers (int**). They
//   will be just int*.
Subabacus* truncateterminal(Subabacus* parent);

#endif
