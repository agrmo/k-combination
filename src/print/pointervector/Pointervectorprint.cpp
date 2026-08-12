#include <iostream>
#include <vector>
#include "Pointervectorprint.h"

void pointervectorprint(std::vector<int*>* listptr) {
  std::vector<int*> list = *listptr;

  std::cout << "[";
  
  for (int i = 0; i < list.size(); i++) {
    if (i != 0) {
      std::cout << ", ";
    }
    
    std::cout << *(list[i]);
  }

  std::cout << "]" << std::endl;
}
