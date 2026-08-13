#include <iostream>
#include <vector>
#include "matrix/Matrix.h"
#include "Matrixfactory.h"
#include "print/matrix/Printmatrix.h"

int main() {
  Matrixfactory mf(3, 3);
  
  std::vector<int> one = {1,2,3};
  std::vector<int> two = {4,5,6};
  std::vector<int*> three(0);

  int a = 5;
  int b = 2;
  int c = 4;

  three.push_back(&a);
  three.push_back(&b);
  three.push_back(&c);
  
  mf.fillnextrow(&one);
  std::cout << "Filled? " << mf.filled() << "\n";
  mf.fillnextrow(&two);
  std::cout << "Filled? " << mf.filled() << "\n";
  mf.fillnextrow(&three);
  std::cout << "Filled? " << mf.filled() << "\n";

  Matrix* matrix = mf.matrix;

  printmatrix(matrix);
}
