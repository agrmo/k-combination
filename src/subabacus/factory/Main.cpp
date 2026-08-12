#include "Subabacusfactory.h"
#include "abacus/Abacus.h"
#include "print/abacus/Printabacus.h"
#include "print/subabacus/Printsubabacus.h"
#include "subabacus/Subabacus.h"
#include "subabacus/factory/Subabacusfactory.h"
#include <iostream>

void exampleone() {
  Abacus* a = new Abacus(5, 3);
  printabacus(a);
  
  Subabacus* sa = truncateterminal(a);
  
  printsubabacus(sa);
  
  delete a;
  delete sa;
}

void exampletwo() {
  Abacus* a = new Abacus(5, 3);

  a -> moveright(2);
  
  printabacus(a);
  
  Subabacus* saa = truncateterminal(a);

  printsubabacus(saa);

  saa -> moveright(1);

  printsubabacus(saa);

  // Now the parent abacus should also be modified.

  printabacus(a);
  
  delete a;
  delete saa;
}

void examplethree() {

  Abacus* a = new Abacus(5, 3);

  std::cout << "Terminal can move right: " << a -> terminalcanmoveright() << "\n";
  
  a -> moveright(2);
  
  printabacus(a);
  std::cout << "Terminal can move right: " << a -> terminalcanmoveright() << "\n";
  
  Subabacus* saa = truncateterminal(a);

  printsubabacus(saa);
  std::cout << "Terminal can move right: " << saa -> terminalcanmoveright() << "\n";

  saa -> moveright(1);

  printsubabacus(saa);
  std::cout << "Terminal can move right: " << saa -> terminalcanmoveright() << "\n";

  // Now the parent abacus should also be modified.

  printabacus(a);
  
  delete a;
  delete saa;
}

int main() {
  examplethree();
}
