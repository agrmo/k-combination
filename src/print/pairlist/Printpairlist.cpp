#include <iostream>
#include "pairlist/Pairlist.h"

void printpairlist(Pairlist* p) {

  std::cout << "[";

  for (int i = 0; i < p -> size(); i++) {
    if (i != 0) {
      std::cout << ", ";
    }

    std::cout << "[";

    int* pair = p -> get(i);
    std::cout << *pair << ", " << *(pair + 1);

    std::cout << "]";
  }

  std::cout << "]" << std::endl;
}
