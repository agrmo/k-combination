#include "Graph.h"
#include <vector>
#include "pairlist/Pairlist.h"
#include "comb/Comb.h"

Graph::Graph(int size, Pairlist* p) {

  // The name of each node starts at 0 and corresponds to its
  // adjacency list in the Comb.

  comb = new Comb();
  
  // We need to initialize the Comb to the cardinality of the Graph so
  // just do that now. max is an index, max+1 is a size.
  int max = p -> getmax();

  // Add max+1 new adjacency lists for each node.
  comb -> add(max + 1);

  // Now iterate over each pair and add their edges.

  for (int i = 0; i < p -> size(); i++) {

    // Pair is an undirected edge.
    // *pair is from
    // *(pair + 1) is to

    int* pair = p -> get(i);
    comb -> push_back(*pair, *(pair + 1));
  }

  // Done. The adjacency list is populated.
}
