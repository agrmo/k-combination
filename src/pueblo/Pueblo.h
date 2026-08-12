#ifndef PUEBLO_H
#define PUEBLO_H

#include <vector>

// For some odd reason getting the member of a class that is a pointer
// results in weird behavior. Just practice here for a second.

class Pueblo {
public:

  std::vector<int>* myweirdpointer;
  
  Pueblo();
  ~Pueblo();
};

#endif
