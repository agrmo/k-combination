#include <iostream>
#include "Combination.h"
#include "matrix/Matrix.h"
#include "print/matrix/Printmatrix.h"

void exampleone() {
  Matrix* matrix = getcombinations(5,2);
  printmatrix(matrix);
}

int main() {
  exampleone();
}
