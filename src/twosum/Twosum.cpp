#include <iostream>

bool twosum(int* start, int size, int target) {
  // Gegeben eine Liste von Zahlen und eine Zielzahl, finde ob die
  // Summe von zwei Zahlen ist gleich wie die Zielzahl.

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {

      if (*(start + i) + *(start + j) == target) {
	return true;
      }
    }
  }

  return false;
}
