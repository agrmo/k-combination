#include "Matrixfactory.h"
#include "matrix/Matrix.h"
#include <iostream>
#include <vector>
#include "print/vector/Printvector.h"
#include "print/pointervector/Printpointervector.h"
#include "print/matrix/Printmatrix.h"

Matrixfactory::Matrixfactory(int m, int n) {

  // Make a new Matrix and start the nextrow count at 0.

  std::cout << "Making new Matrix size " << m << ", " << n << "\n";
    
  matrix = new Matrix(m, n);
  nextrow = 0;
}

Matrixfactory::~Matrixfactory() {

  // hmmmm let's not delete the pointer?
  // the parent might use it unfortunately
  // should really use smart pointers...
  
}

void Matrixfactory::fillnextrow(std::vector<int>* row) {

  // We could use some assertions here.

  std::cout << "Saving row at " << nextrow << ": ";
  printvector(row);

  // Here we copy each integer over.
  for (int i = 0; i < row -> size(); i++) {
    matrix -> set(nextrow, i, row -> at(i));
  }

  std::cout << "Matrix is now \n";
  printmatrix(matrix);

  nextrow++;

  std::cout << "nextrow is " << nextrow << "\n";
}

void Matrixfactory::fillnextrow(std::vector<int*>* row) {

  // Same idea, just dereference each integer first.

  std::cout << "Saving row at " << nextrow << ": ";
  printpointervector(row);
  
  for (int i = 0; i < row -> size(); i++) {
    matrix -> set(nextrow, i, *(row -> at(i)));
  }

  std::cout << "Matrix is now \n";
  printmatrix(matrix);

  nextrow++;

  std::cout << "nextrow is now " << nextrow << "\n";
}

bool Matrixfactory::filled() {
  
  // nextrow is an index
  
  return nextrow >= matrix -> rows;
}
