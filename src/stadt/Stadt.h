#ifndef STADT_H
#define STADT_H

#include <iostream>

// Practice with member references. They are very finnicky and
// probably not useful in most situations, but they probably have some
// valid uses.

class Stadt {
  int& member;
  
public:

  Stadt(int &param) : member(param) {
    // Welcome to the function block of moral turpitude.
    std::cout << "Hi!\n";
  };
  
  ~Stadt();
};

#endif
