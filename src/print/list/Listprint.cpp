#include <iostream>
#include "Listprint.h"

void listprint(int* ptr, int size) {

  std::cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      std::cout << ", ";
    }
    
    std::cout << *(ptr + i);
  }

  std::cout << "]" << std::endl;
}
