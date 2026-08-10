#include <iostream>
#include "kette/Kette.h"

void ketteprint(Kette* knoten) {
  Kette* k = knoten;

  while (k != nullptr) {
    std::cout << k->wert;
    
    if (k->naechste != nullptr) {
      std::cout << " -> ";
    }


    k = k -> naechste;
  }
  std::cout << std::endl;
}
