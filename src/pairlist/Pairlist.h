#ifndef PAIRLIST_H
#define PAIRLIST_H

#include <vector>

// A list of pairs. I like making classes for everything.

class Pairlist {

  // We will implement this as a vector to a pointer to a pair of
  // ints. The vector needs to be a vector because we will add and
  // remove pairs ad hoc. The pairs can be a pointer to a primitive
  // array because their size will not change and we can deallocate
  // easily.
  std::vector<int*>* pairlist;
  
public:
  
  Pairlist();
  ~Pairlist();

  // Add the pair [a,b] to this list of pairs.
  void add(int a, int b);

  // Get the pair at index i.
  int* get(int i);

  // Get size.
  int size();

  // Get the largest number in this Pairlist.
  int getmax();
};

#endif
