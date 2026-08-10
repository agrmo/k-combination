#include <iostream>
#include "Twosum.h"

int main() {

  int size = 5;
  int arr[size] = {0, -1, 2, -3, 1};
  int* ptr = arr;
  int target = -2;

  std::cout << twosum(ptr, size, target);
}
