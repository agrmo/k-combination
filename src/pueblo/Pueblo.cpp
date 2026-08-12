#include "Pueblo.h"
#include <iostream>

Pueblo::Pueblo() {
  myweirdpointer = new std::vector<int>(0);

  myweirdpointer -> push_back(5);
  myweirdpointer -> push_back(2);
}

Pueblo::~Pueblo() {
  std::cout << "Bye!\n";
}
