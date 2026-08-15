#include <iostream>
#include <vector>
#include "Printpointervector.h"

void printpointervector(std::vector<int*> list) {
  std::cout << "[";
  
  for (int i = 0; i < list.size(); i++) {
    if (i != 0) {
      std::cout << ", ";
    }
    
    std::cout << *(list[i]);
  }

  std::cout << "]" << std::endl;
}

void printpointervector(std::vector<int*>* listptr) {
  std::vector<int*> list = *listptr;

  printpointervector(list);
}
