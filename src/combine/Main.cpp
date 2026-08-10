#include <iostream>
#include "print/list/Listprint.h"
#include "Combine.h"

int main() {

  int sizeleft = 3;
  int sizeright = 2;
  int left[sizeleft] = {3,4,5};
  int right[sizeright] = {1,2};

  int size = sizeleft + sizeright;
  int combined[size];
  
  combine(left, sizeleft,
	  right, sizeright,
	  combined);

  listprint(combined, size);
}
