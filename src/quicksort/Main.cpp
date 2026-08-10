#include <iostream>
#include "Quicksort.h"
#include <ctime>
#include <stdlib.h>
#include "print/vector/Vectorprint.h"

int main() {

  srand(time(NULL));
  
  std::vector<int> list = {0, -1, 2, -3, 1};
  std::vector<int> sorted = quicksort(list);

  vectorprint(sorted);
}
