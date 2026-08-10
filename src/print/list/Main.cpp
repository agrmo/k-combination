#include <iostream>
#include "Listprint.h"

int main() {

  int size = 4;
  int arr[size] = {6,7,8,9};
  int* ptr = arr;

  listprint(arr, size);
}
