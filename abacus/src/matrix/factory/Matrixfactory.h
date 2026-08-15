#ifndef MATRIXFACTORY_H
#define MATRIXFACTORY_H

#include <vector>
#include "matrix/Matrix.h"

// A Matrixfactory is a dorky class where you can fill a Matrix
// sequentially with values without worrying about last saved indices.

class Matrixfactory {
  
public:

  // Index of next row to be filled.
  int nextrow;

  // To get the matrix just grab the variable.
  Matrix* matrix;

  Matrixfactory(int m, int n);

  // Fill the next row with ints.
  void fillnextrow(std::vector<int> row);

  // Fill the next row with ints.
  void fillnextrow(std::vector<int>* row);
  
  // Fill the next row but dereference the ints first.
  void fillnextrow(std::vector<int*>* row);

  // Is the Matrix filled?
  bool filled();

  // Should verify the memory is released here.
  ~Matrixfactory();
};

#endif
