#include "Matrixfactory.h"
#include "matrix/Matrix.h"
#include <iostream>
#include <vector>
#include "print/vector/Printvector.h"
#include "print/pointervector/Printpointervector.h"
#include "print/matrix/Printmatrix.h"
#include <stdexcept>

Matrixfactory::Matrixfactory(int m, int n) {

  // Make a new Matrix and start the nextrow count at 0.
    
  matrix = new Matrix(m, n);
  nextrow = 0;
}

Matrixfactory::~Matrixfactory() {
}

bool Matrixfactory::filled() {
  
  // nextrow is an index  
  return nextrow >= matrix -> rows;
}

void Matrixfactory::fillnextrow(std::vector<int> row) {

  std::cout << "Saving: ";
  printvector(row);

  // Here we copy each integer over.
  for (int i = 0; i < row.size(); i++) {
    matrix -> set(nextrow, i, row.at(i));
  }

  nextrow++;
}

void Matrixfactory::fillnextrow(std::vector<int>* row) {

  std::cout << "Saving: ";
  printvector(row);

  // Here we copy each integer over.
  for (int i = 0; i < row -> size(); i++) {
    matrix -> set(nextrow, i, row -> at(i));
  }

  nextrow++;
}

void Matrixfactory::fillnextrow(std::vector<int*>* row) {

  std::cout << "Saving row at " << nextrow << ": ";
  printpointervector(row);
  
  for (int i = 0; i < row -> size(); i++) {
    matrix -> set(nextrow, i, *(row -> at(i)));
  }

  nextrow++;
}
