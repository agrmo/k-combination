#include <iostream>

// Loop over a list using a pointer
void loop() {
  int size = 4;
  int arr[size] = {6,7,8,9};
  int* ptr = arr;
  
  for (int i = 0; i < size; i++) {
    std::cout << "Element: " << *(ptr + i) << std::endl;
  }
}
