#include <iostream>
#include "Ketteprint.h"
#include "../../kette/Kette.h"

int main() {
  Kette* kopf = new Kette(2);
  kopf->naechste = new Kette(4);
  ketteprint(kopf);
}
