#include <iostream>
#include "Kette.h"
#include "print/kette/Ketteprint.h"

int main() {
  Kette* kopf = new Kette(2);
  kopf->naechste = new Kette(4);
  ketteprint(kopf);
}
