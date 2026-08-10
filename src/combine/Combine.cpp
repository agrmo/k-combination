#include "Combine.h"

// A very manual way of combining two arrays into one. The problem is
// that we cannot allocate a new array within the function, such as
// int combined[sizeleft + sizeright] because such an array will be
// deallocated after returning.
void combine(int* left, int sizeleft,
	     int* right, int sizeright,
	     int* combined) {
  
  int* cptr = combined;

  for (int i = 0; i < sizeleft; i++) {
    *(cptr + i) = *(left + i);
  }

  for (int i = 0; i < sizeright; i++) {
    *(cptr + sizeleft + i) = *(right + i);
  }
}
