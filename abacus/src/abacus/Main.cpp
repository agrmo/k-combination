#include <iostream>
#include "Abacus.h"
#include "print/abacus/Printabacus.h"

void exampleone() {
  Abacus* a = new Abacus(5, 3);
  printabacus(a);
  delete a;
}

void exampletwo() {
  Abacus* a = new Abacus(5, 3);

  std::cout << a -> canmoveright(0) << "\n"; // no
  std::cout << a -> canmoveright(1) << "\n"; // no
  std::cout << a -> canmoveright(2) << "\n"; // yes
  
  printabacus(a);
  delete a;
}

void examplethree() {
  Abacus* a = new Abacus(5, 3);

  a -> moveright(2);

  printabacus(a);
  
  a -> moveright(2);

  printabacus(a);
  
  a -> moveright(1);

  printabacus(a);

  a -> moveright(1);
  
  printabacus(a);

  delete a;
}


int main() {
  examplethree();
}
