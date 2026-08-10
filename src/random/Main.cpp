#include <iostream>
#include <stdlib.h>
#include <ctime>

// in: none
// out: 0 or 1
int coin() {
  srand(time(NULL));
  int coin = rand() % 2; // entweder 0 oder 1
  // If number is 0: Heads
  // If it is not 0: Tails

  return coin;
}

// in: int
// out: 0 or 1 or ... or n-1
int randn(int n) {
  srand(time(NULL));

  return rand() % n;
}

int main() {
  std::cout << randn(5);
}
