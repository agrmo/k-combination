#include "Abacusfactory.h"
#include "abacus/Abacus.h"
#include "print/abacus/Printabacus.h"
#include <iostream>

void exampleone() {
  Abacus* a = new Abacus(5, 3);
  printabacus(a);
  
  Abacus* sa = truncateterminal(a);
  
  printabacus(sa);  
}

void exampletwo() {
  Abacus* a = new Abacus(5, 3);

  a -> moveright(2);
  
  printabacus(a);
  
  Abacus* saa = truncateterminal(a);

  printabacus(saa);

  saa -> moveright(1);

  printabacus(saa);

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
  
  Abacus* saa = truncateterminal(a);

  printabacus(saa);
  std::cout << "Terminal can move right: " << saa -> terminalcanmoveright() << "\n";

  saa -> moveright(1);

  printabacus(saa);
  std::cout << "Terminal can move right: " << saa -> terminalcanmoveright() << "\n";

  // Now the parent abacus should also be modified.

  printabacus(a);
  std::cout << "Terminal can move right: " << a -> terminalcanmoveright() << "\n";
  
  delete a;
  delete saa;
}

int main() {
  exampletwo();
}
