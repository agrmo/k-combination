#ifndef PRINTMATRIX_H
#define PRINTMATRIX_H

#include <vector>
#include "matrix/Matrix.h"

// Various ways to construct and print matrices in C++.

// Print a primitive m-by-n matrix.
// - m: num of rows
// - n: num of cols
// - ptr: pointer to first element
void printmatrixprimitive(int** ptr, int m, int n);

// Print a matrix made of vectors.
// - matrix: Vector reference to a list of vector references.
// - m: num of rows
// - n: num of cols
//
// We want the entire parameter to be a pointer. That way, the parent
// function passes its vector by pointer, not by copy. That way,
// modifications to this matrix will be available to the parent.
//
// Technically the matrix can be jagged. We will try to use this
// function only for actual matrices that strictly are m x n. No
// sanity checking is done in function.
void printmatrixvector(std::vector<std::vector<int>*>* matrix, int m, int n);

// Print the matrix from "matrix/Matrix.h".
void printmatrix(Matrix* matrix);

#endif
