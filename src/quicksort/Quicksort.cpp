#include <iostream>
#include <stdlib.h>
#include <vector>
#include "print/vector/Printvector.h"

// Repour all numbers in the array into the left and right
// arrays.
void repour(std::vector<int> list,
	    std::vector<int>& left, std::vector<int>& right,
	    int pivot) {
  
  int lefti = 0;
  int righti = 0;

  for (int i = 0; i < list.size(); i++) {
    
    if (list[i] >= pivot) {
      
      // Put in right.
      std::cout << "pour right " << righti << " " << list[i] << "\n";
      right[righti] = list[i];
      righti += 1;
      
    } else {

      // Put in left.
      std::cout << "pour left " << lefti << " " << list[i] << "\n";
      left[lefti] = list[i];
      lefti += 1;
    }
  }
}

// Count the number of elements less than the pivot.
// This will be used for making the next left and right vectors.
int countleft(std::vector<int> list, int pivot) {

  std::cout << "countleft vector ";
  printvector(list);

  int left = 0;
  for (int i = 0; i < list.size(); i++) {
    if (list[i] < pivot) {
      left += 1;
    }
  }

  return left;
}

// Quicksort for int vectors.
std::vector<int> quicksort(std::vector<int> list) {

  std::cout << "Call ";
  printvector(list);

  if (list.size() <= 1) {
    // Do nothing
    return list;
  }

  if (list.size() == 2) {
    // Compare directly and return. If the first is larger than the
    // second, swap them.
    
    if (list[0] > list[1]) {
      list = {list[1], list[0]};
    }

    std::cout << "Case 2 ";
    printvector(list);
    return list;
  }

  // Else, size is greater than 2. Recurse.
  
  int index = rand() % list.size();
  int pivot = list[index];
  std::cout << "index " << index << " val " << pivot << "\n";

  int sizeleft = countleft(list, pivot);
  std::cout << "sizeleft " << sizeleft << "\n";
  int sizeright = list.size() - sizeleft;
  std::cout << "left " << sizeleft << " right " << sizeright << "\n";

  std::vector<int> left(sizeleft);
  std::vector<int> right(sizeright);

  repour(list, left, right, pivot);

  std::cout << "repour left ";
  printvector(left);

  std::cout << "repour right ";
  printvector(right);
  
  std::vector<int> qleft = quicksort(left);
  std::vector<int> qright = quicksort(right);

  std::vector<int> combined(list.size());
  
  for (int i = 0; i < left.size(); i++) {
    combined[i] = qleft[i];
  }

  for (int i = 0; i < right.size(); i++) {
    combined[i + sizeleft] = qright[i];
  }

  std::cout << "combine left ";
  printvector(qleft);
  std::cout << "combine right ";
  printvector(qright);
  std::cout << "combined ";
  printvector(combined);

  return combined;
}
