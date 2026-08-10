#include <iostream>
#include "Kette.h"

// Eine einseitige Kette.
// Auch eine Art Graphen.
// Jeder Knoten besitzt einen Zeiger zum nächsten Knoten.

Kette::Kette(int w) {
  wert = w;
  naechste = nullptr;
}

