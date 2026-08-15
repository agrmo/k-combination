#ifndef COMBINATION_H
#define COMBINATION_H

#include "matrix/Matrix.h"
// Get all combinations of P choose Q for a set of integers 1...Q.
// in: p and q
// out: 2D Array of dimension pCq by q
//
// i.e. There are pCq rows, and q columns. each row is a unique
// combination. None are permutations of another, obviously.
//
// Implementation description is in Combinationabacus.cpp.
//
Matrix* getcombinations(int p, int q);

#endif
