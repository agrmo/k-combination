#include "Matrix.h"
#include <iostream>
#include <vector>

Matrix::Matrix(int m, int n) {

  rows = m;
  cols = n;

  // Initialize the matrix (the "outer vector").
  mat = new std::vector<std::vector<int>*>(m);

  // Manually initialize each row (the "inner vectors").
  for (int i = 0; i < m; i++) {
    
    // mat[i] is a pointer
    // new std::vector<int>(n) is a pointer
    (*mat)[i] = new std::vector<int>(n);
  }

  // Done.

  // e.g. returns 0
  // std::cout << (*mat)[0] -> at(0) << "\n";
  
  // Note the matrix is on the heap. It will need to be freed.
}

Matrix::~Matrix() {
  // Because the matrix is on the heap we need need to free all inner
  // vectors ("rows") and the outer vector.

  for (int i = 0; i < rows; i++) {
    (*mat)[i] -> clear();
  }
  
  (*mat).clear();
}

int Matrix::get(int m, int n) {
  return mat -> at(m) -> at(n);
}

void Matrix::set(int m, int n, int v) {
  mat -> at(m) -> at(n) = v;
}
