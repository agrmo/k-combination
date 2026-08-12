#include <iostream>
#include "Combinatoric.h"
#include "matrix/Matrix.h"
#include "print/matrix/Printmatrix.h"

void exampleone() {
  std::cout << "0! = " << factorial(0) << "\n";
  std::cout << "1! = " << factorial(1) << "\n";
  std::cout << "2! = " << factorial(2) << "\n";
  std::cout << "3! = " << factorial(3) << "\n";
}

void exampletwo() {
  std::cout << "1 choose 1 = " << pchooseq(1, 1) << "\n";
  std::cout << "2 choose 1 = " << pchooseq(2, 1) << "\n";
  std::cout << "3 choose 1 = " << pchooseq(3, 1) << "\n";
  std::cout << "3 choose 2 = " << pchooseq(3, 2) << "\n";
  std::cout << "4 choose 3 = " << pchooseq(4, 3) << "\n";
}

int main() {
  exampletwo();
}
