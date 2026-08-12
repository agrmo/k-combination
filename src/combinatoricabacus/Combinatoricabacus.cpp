#include <stdexcept>
#include "matrix/Matrix.h"
#include "combinatoric/Combinatoric.h"
#include "Combinatoricabacus.h"
#include "abacus/Abacus.h"
#include "print/matrix/Printmatrix.h"
#include "matrix/factory/Matrixfactory.h"
#include "subabacus/factory/Subabacusfactory.h"
#include <iostream>

// Populate the next found combination with the beads: the parent
// abacus beads. Always length q.
void savecombination(Matrixfactory* mf,
		     std::vector<int>* beads) {

  mf -> fillnextrow(beads);
}

// Same thing, now just for int references.
void savecombination(Matrixfactory* mf,
		     std::vector<int*>* beads) {

  mf -> fillnextrow(beads);
}


void subabacusgetcombinations(Subabacus* subabacusparent,
			      Matrixfactory* mf) {

  // The logic is completely identical to the parent Abacus.
  // Just the underlying data structure is a little different.

  while (subabacusparent -> terminalcanmoveright()) {

    if (subabacusparent -> numberofbeads() > 1) {
      Subabacus* subabacuschild = truncateterminal(subabacusparent);

      subabacusgetcombinations(subabacuschild, mf);
    }

    // Move right and save.
    subabacusparent -> moveterminalright();
    savecombination(mf, subabacusparent -> parentbeads);
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

  // Start the algorithm.

  // The output data structure is a matrix, and each row is a unique
  // combination of the possible numbers [0 ... p] with length q.
  int pcq = pchooseq(p, q);  

  // The matrix initially has all zero values.
  // We will replace each row as we find new combinations.
  // We will need a variable to keep track of which row we are on.
  // Next row to populate.
  Matrixfactory mf(pcq, q);

  // Build the parent abacus.
  Abacus parent(p, q);

  // The beads are initialized on the left.

  // Save initial combination.

  // savecombination(mf, parent.beads);

  // Start the recursive loop.

  // while (parent.terminalcanmoveright()) {
  //   if (parent.numberofbeads() > 1) {

  //     Subabacus* sa = truncateterminal(&parent);

  //     // Call a recursive algorithm. This function will count the
  //     // combinations of the smaller abacus and add the combinations
  //     // to the matrix, while also appending the parent's beads.
  //     subabacusgetcombinations(sa, matrix);
  //   }
  // }
  
  return mf.matrix;
}
