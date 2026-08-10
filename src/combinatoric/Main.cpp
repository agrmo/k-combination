#include <iostream>
#include "Combinatoric.h"
#include "matrix/Matrix.h"
#include "print/matrix/Printmatrix.h"

void beispieleins() {
  std::cout << "0! = " << factorial(0) << "\n";
  std::cout << "1! = " << factorial(1) << "\n";
  std::cout << "2! = " << factorial(2) << "\n";
  std::cout << "3! = " << factorial(3) << "\n";
}

void beispielzwei() {
  std::cout << "1 choose 1 = " << pchooseq(1, 1) << "\n";
  std::cout << "2 choose 1 = " << pchooseq(2, 1) << "\n";
}

void beispieldrei() {
  Matrix* m = getcombinations(1, 1);
  printmatrix(m);
}

int main() {
  beispieldrei();
}
