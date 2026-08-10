#include <iostream>
#include "Comb.h"

int main() {
  // Initialize the Comb.
  // The object is on the stack. Its data is not.
  Comb c;

  // Add a row.
  c.add();

  // Add a number to row 0.
  c.push_back(0, 5);

  // 5
  std::cout << c.get(0,0) << "\n";

  // And if we want to get manually...
  std::cout << (*c.comb).at(0) -> at(0) << "\n";
}
