#include "Combinatoric.h"
#include <stdexcept>
#include "matrix/Matrix.h"

int factorial(int n) {

  if (n < 0) {
    throw std::runtime_error("Factorial below 0.");
  }
  
  int f = 1;

  for (int i = 2; i < n + 1; i++) {
    f *= i;
  }

  return f;
}

// Check if the combinatoric pCq is valid.
void checkpcq(int p, int q) {
  if (p - q < 0) {
    throw std::runtime_error("pchooseq: p - q < 0.");
  } else if (q == 0) {
    throw std::runtime_error("pchooseq: q = 0.");
  } else if (p == 0) {
    throw std::runtime_error("pchooseq: p = 0.");
  }
}

int pchooseq(int p, int q) {
  
  checkpcq(p, q);
  
  return (factorial(p) / (factorial(q) * factorial(p-q)));
}

