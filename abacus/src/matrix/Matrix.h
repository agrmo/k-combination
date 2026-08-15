#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

// A simple implementation of a matrix as a reference to a vector of a
// list of vector pointers. It's a bit complicated to construct each
// time ad hoc so let's just make a nice class for this.

class Matrix {
  
public:
  
  // We could derive this using (*mat).length() and (*mat[0]).length()
  // but that's a bit weird. Just store m and n.
  int rows; // aka m
  int cols; // aka n
  
  std::vector<std::vector<int>*>* mat;
  
  // m: rows
  // n: cols
  // Allocates and initializes to all zeros.
  Matrix(int m, int n);

  // Should verify the memory is released here.
  ~Matrix();

  // get function
  int get(int m, int n);

  // set function
  void set(int m, int n, int v);
};

#endif
