#include <iostream>
#include "Swap.h"
#include "print/list/Listprint.h"

int main() {
  int size = 2;
  int arr[size] = {3,5};
  int* ptr = arr;
  
  swap(ptr, ptr + 1);

  listprint(ptr, size);
}
