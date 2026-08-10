#ifndef COMB_H
#define COMB_H

#include <vector>

// A "comb" is a jagged 2D matrix. Useful for constructing a
// graph adjacency list, for example.

// In code we will implement this as a 2D array of vectors, which is
// identical to the way you would build a matrix, except now you must
// check the size of the outer vector and inner vectors each
// time. Such is life.

// If it's just a single variable, why make a class? I hate C++
// syntax. Me like words.

class Comb {
  
public:

  // In Matrix.h we make the underlying variable private but here it's
  // wiser to make the underlying variable accessible. I need to use
  // push_back and pop_back and would rather not reimplement them.
  std::vector<std::vector<int>*>* comb;

  // Constructor. Let's just make it a 1x1 matrix to begin with.
  Comb();

  // get function
  int get(int m, int n);

  // set function
  int set(int m, int n, int val);

  // add the value v to the nth row
  void push_back(int n, int v);

  // add an extra row to the comb with length 1 and initialize to 0
  void add();

  // add n rows to the comb
  void add(int n);

  // get size of the outer vector
  // equal to the max number of columns
  int size();

  // get width of the nth row
  int size(int n);

  // Should verify the memory is released here.
  ~Comb();
};

#endif
