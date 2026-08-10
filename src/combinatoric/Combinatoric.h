#ifndef COMBINATORIC_H
#define COMBINATORIC_H

#include "matrix/Matrix.h"

// Combinatorical functions.

// Factorial via brute force.
int factorial(int n);

// Factorial via Stirling.
// int factorialstirling(int n)

// Get P choose Q.
int pchooseq(int p, int q);

// Get all combinations of P choose Q for a set of integers 1...Q.
// in: p and q
// out: 2D Array of dimension pCq by q
//
// i.e. There are pCq rows, and q columns. each row is a unique
// combination. None are permutations of another, obviously.
Matrix* getcombinations(int p, int q);

#endif
