#include <iostream>
#include "Printmatrix.h"

void exampleone() {
  int m = 3;
  int n = 3;

  int** matrix = new int*[m];

  matrix[0] = new int[n] {1, 2, 3};
  matrix[1] = new int[n] {4, 5, 6};
  matrix[2] = new int[n] {7, 8, 9};
  
  printmatrixprimitive(matrix, m, n);
}

void exampletwo() {
  int m = 4;
  int n = 3;

  int** matrix = new int*[m];
  
  matrix[0] = new int[n] {1, 2, 3};
  matrix[1] = new int[n] {4, 5, 6};
  matrix[2] = new int[n] {7, 8, 9};
  matrix[3] = new int[n] {10, 11, 12};
  
  printmatrixprimitive(matrix, m, n);
}

void examplethree() {

  int m = 4;
  int n = 3;

  // Initialize the matrix (the "outer vector").
  std::vector<std::vector<int>*> matrix(m);

  // Manually initialize each row (the "inner vectors").
  for (int i = 0; i < m; i++) {
    
    // matrix[i] is a pointer
    // new std::vector<int>(n) is a pointer
    matrix[i] = new std::vector<int>(n);
  }

  // The matrix is allocated and all zeros.
  printmatrixvector(&matrix, m, n);
}

void beispielvier() {
  Matrix* m = new Matrix(1, 1);
  printmatrix(m);
  delete m;

  m = new Matrix(3, 3);
  m -> set(1, 1, 7);
  printmatrix(m);
  delete m;
}

int main() {
  beispielvier();
}
