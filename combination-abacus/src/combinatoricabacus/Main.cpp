#include <iostream>
#include "Combinatoricabacus.h"
#include "matrix/Matrix.h"
#include "print/matrix/Printmatrix.h"

void exampleone() {
  Matrix* matrix = getcombinations(4, 3);
  printmatrix(matrix);
}

int main() {
  exampleone();
}
