#include <iostream>
#include "Graph.h"
#include "comb/Comb.h"
#include "print/comb/Printcomb.h"

int main() {

  // Build an undirected Graph
  // using an adjacency list.
  
  int size = 5;
  Pairlist* p = new Pairlist();

  p -> add(0,1);
  p -> add(1,2);
  p -> add(3,2);
  p -> add(4,2);
  p -> add(4,1);
  p -> add(3,1);
  p -> add(0,3);
  
  Graph g(size, p);

  Comb* c = g.comb;
  printcomb(c);
}
