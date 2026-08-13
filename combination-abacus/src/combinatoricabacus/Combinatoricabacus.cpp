#include <stdexcept>
#include <vector>
#include "matrix/Matrix.h"
#include "combinatoric/Combinatoric.h"
#include "Combinatoricabacus.h"
#include "abacus/Abacus.h"
#include "print/matrix/Printmatrix.h"
#include "matrix/factory/Matrixfactory.h"
#include "subabacus/factory/Subabacusfactory.h"
#include <iostream>

// The next two functions call eachother mutually.
// In order to do that, we need a forward declaration.
void subabacusgetcombinations(Subabacus* subabacus,
			      Matrixfactory* mf);

// Interestingly we need to repeat this step in the recursive
// algorithm twice. No way around it I suppose. We'll just make a
// function to factor the code a little.
void subabacuscheckrecursion(Subabacus* subabacus,
			     Matrixfactory* mf) {

  std::cout << "check recursion\n";

  if (subabacus -> numberofbeads() > 1) {
    Subabacus* subabacuschild = truncateterminal(subabacus);

    // Now we recurse but this time with one less bead.
    subabacusgetcombinations(subabacuschild, mf);
  }
}

void subabacusgetcombinations(Subabacus* subabacus,
			      Matrixfactory* mf) {

  // The logic is completely identical to the parent Abacus.
  // Just the underlying data structure is a little different.

  while (subabacus -> terminalcanmoveright()) {

    std::cout << "while child " << subabacus -> size << "\n";

    // This may recurse.
    subabacuscheckrecursion(subabacus, mf);

    // Move right and save.
    subabacus -> moveterminalright();
    mf -> fillnextrow(subabacus -> parentbeads);

    // This may recurse.
    subabacuscheckrecursion(subabacus, mf);
  }
}

// Check if the Abacus needs to make a Subabacus and recurse into the
// smaller Abacus. In this case we don't need a forward
// declaration. The two Subabaci functions on the other hand are
// circular and require a forward declaration.
void abacuscheckrecursion(Abacus* abacus, Matrixfactory* mf) {
  if (abacus -> numberofbeads() > 1) {

    // Make a new Abacus truncated at the terminal bead.  The
    // unoccupied locations before the terminal bead are still
    // included.
    Subabacus* sa = truncateterminal(abacus);

    // Call a recursive algorithm. This function will count the
    // combinations of the smaller abacus and add the combinations
    // to the matrix, while also appending the parent abacus' beads.
    subabacusgetcombinations(sa, mf);
  }
}

// Complexity analysis: O(p!) where p is the size of the set.
// In other notation O(n!)
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
  Matrixfactory mf(pcq, q);

  // Build the parent abacus.
  Abacus parent(p, q);

  // The beads are initialized on the left.

  // Save initial combination.

  mf.fillnextrow(parent.beads);

  // Start the recursive loop.

  while (parent.terminalcanmoveright()) {

    std::cout << "while parent " << parent.size << "\n";

    abacuscheckrecursion(&parent, &mf);

    // After the possible recursion (there could be no recursion)
    // move and then save the resulting combination.
    parent.moveterminalright();
    mf.fillnextrow(parent.beads);

    // Run the check statement exactly again.
    abacuscheckrecursion(&parent, &mf);
  }
  
  return mf.matrix;
}
