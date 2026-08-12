#include <stdexcept>
#include "matrix/Matrix.h"
#include "combinatoric/Combinatoric.h"
#include "Combinationabacus.h"
#include "abacus/Abacus.h"

// Populate the next found combination with the
// beads: the parent abacus beads. Always length q.
void populatenextrow(Matrix* matrix,
		     std::vector<int>* beads,
		     int nextrow) {

  // We will need to copy each integer over.
  // matrix -> cols equals beads -> length()
  // We have no idea what nextrow is, except that it's less than pCq.
  for (int i = 0; i < matrix -> cols; i++) {
    matrix -> set(nextrow, i, beads -> at(i));
  }
}

// Complexity analysis: O(p!) where p is the size of the set.
// aka O(n!)
//
// More accurately would be
// O(q*(p choose q)) = O((q*p!)/(q!(p-q)!)))
// but O(p!) is close enough.
//
// Given an Abacus and a Subabacus implementation we have all the
// tools we need to build a recursive algorithm that find combinations
// of numbers in a clean way.

Matrix* getcombinations(int p, int q) {

  // The output data structure is a matrix, and each row is a unique
  // combination of the possible numbers [0 ... p] with length q.
  int pcq = pchooseq(p, q);  
  Matrix* matrix = new Matrix(pcq, q);

  // The matrix initially has all zero values.
  // We will replace each row as we find new combinations.
  // We will need a variable to keep track of which row we are on.
  // Next row to populate.
  int nextrow = 0;

  // Build the parent abacus.
  Abacus parent(p, q);

  // The beads are initialized on the left.

  // Start the recursive algorithm.

  return matrix;
}
