#include <iostream>
#include "Pueblo.h"
#include <vector>

void doweirdthing(std::vector<int>* mwp) {

  for (int i = 0; i < mwp -> size(); i++) {
    std::cout << "Fine.\n";
  }
}

int main() {
  Pueblo a;

  doweirdthing(a.myweirdpointer);
}
