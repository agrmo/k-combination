#include "Combination.h"
#include "abacus/Abacus.h"
#include "abacus/factory/Abacusfactory.h"
#include "combinatoric/Combinatoric.h"
#include "matrix/Matrix.h"
#include "matrix/factory/Matrixfactory.h"
#include "print/matrix/Printmatrix.h"
#include "print/pointervector/Printpointervector.h"
#include "print/vector/Printvector.h"
#include <iostream>
#include <vector>

// The next two functions call eachother mutually.
// - checkrecursion(Abacus*, Matrixfactory*)
// - getcombinations(Abacus*, Matrixfactory*)
// In order to do that, we need to forward declare one of them.
void getcombinations(Abacus* abacus, Matrixfactory* mf);

// Check if the Abacus needs to make a Abacus and recurse into the
// smaller Abacus. In this case we don't need a forward
// declaration. The two Subabaci functions on the other hand are
// circular and require a forward declaration.

// Interestingly we need to repeat this step in the recursive
// algorithm twice. No way around it I suppose. We'll just make a
// function to factor the code a little.
void checkrecursion(Abacus* abacus, Matrixfactory* mf) {

  if (abacus -> numberofbeads() > 1) {

    // Make a new Abacus truncated at the terminal bead.  The
    // unoccupied locations before the terminal bead are still
    // included.
    Abacus* abacuschild = truncateterminal(abacus);

    // Call a recursive algorithm. This function will count the
    // combinations of the smaller abacus and add the combinations
    // to the matrix, while also appending the parent abacus' beads.
    getcombinations(abacuschild, mf);
  }
}

void getcombinations(Abacus* abacus, Matrixfactory* mf) {

  bool didmove = false;

  while (abacus -> terminalcanmoveright()) {

    // Check if recurse on subabacus.
    if (!didmove) {
      std::cout << "Did not move: \n";
      checkrecursion(abacus, mf);
    } else {
      std::cout << "Skipping recursion on: ";
      printvector(abacus -> fullbeads);
    }
    
    // Move right and save.
    abacus -> moveterminalright();
    didmove = true;
    std::cout << "Move to: ";
    printvector(abacus -> fullbeads);
    mf -> fillnextrow(abacus -> fullbeads);    

    // Check if recurse on subabacus.
    checkrecursion(abacus, mf);    
  }
}

// Complexity analysis: O(p!) where p is the size of the set.
// In other notation O(n!)
//
// More accurately would be
// O(q*(p choose q)) = O((q*p!)/(q!(p-q)!)))
// but O(p!) is close enough.
//
// Given an Abacus and a Abacus implementation we have all the
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

  mf.fillnextrow(parent.fullbeads);

  // Start the recursive loop.

  getcombinations(&parent, &mf);

  return mf.matrix;
}
