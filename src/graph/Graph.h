#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "pairlist/Pairlist.h"
#include "comb/Comb.h"

// A undirected graph.

class Graph {
  
public:

  // The underlying data structure is an adjacency list.
  Comb* comb;

  // Constructor:
  // - pairs: List of pairs of ints. Each pair is an edge.
  //
  // We will derive the necessary size of the pairlist data structure
  // ad hoc.
  Graph(int size, Pairlist* p);
};

#endif
