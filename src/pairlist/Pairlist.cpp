#include "Pairlist.h"
#include <iostream>

Pairlist::Pairlist() {
  pairlist = new std::vector<int*>(0);
  
  // On the heap.
}

Pairlist::~Pairlist() {

  for (int i = 0; i < pairlist -> size(); i++) {
    delete pairlist -> at(i);
  }

  pairlist -> clear();

  delete pairlist;
}

int Pairlist::size() {
  return pairlist -> size();
}

void Pairlist::add(int a, int b) {
  
  // Put this on the heap immediately.
  int* pair = new int[] {a, b};
  
  pairlist -> push_back(pair);
}

int* Pairlist::get(int i) {
  
  return pairlist -> at(i);
}

int Pairlist::getmax() {
  // The Pairlist should have at least one pair in it.

  if (pairlist -> size() == 0) {
    throw "getmax called on empty Pairlist";
  }

  int max = *(pairlist -> at(0));
    
  for (int i = 0; i < pairlist -> size(); i++) {
    int* pair = pairlist -> at(i);

    if (*pair > max) {
      max = *pair;
    }

    // Just pretend we are still iterating. I don't like complicated
    // boolean expressions.
    
    if (*(pair + 1) > max) {
      max = *(pair + 1);
    }
  }

  return max;
}
