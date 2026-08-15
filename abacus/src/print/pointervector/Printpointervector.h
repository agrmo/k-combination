#ifndef PRINTPOINTERVECTOR_H
#define PRINTPOINTERVECTOR_H

#include <vector>

// Print a list of pointers to integers.
// Useful when constructing subsequences of integers.
void printpointervector(std::vector<int*> list);

// Same thing.
void printpointervector(std::vector<int*>* list);

#endif
