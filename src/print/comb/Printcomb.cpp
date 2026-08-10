#include <iostream>
#include "comb/Comb.h"

void printcomb(Comb* c) {

  std::cout << "[";

  for (int i = 0; i < c -> size(); i++) {    

    std::cout << "[";

    for (int j = 0; j < c -> size(i); j++) {
      if (j != 0) {
	std::cout << ", ";
      }

      std::cout << c -> get(i, j);
    }

    std::cout << "]";

    if (i != c -> size() - 1) {
      std::cout << ",\n";
    }
  }

  std::cout << "]" << std::endl;
}
