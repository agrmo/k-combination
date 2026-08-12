#include <stdexcept>
#include "matrix/Matrix.h"
#include "combinatoric/Combinatoric.h"
#include "Combinationabacus.h"

// Complexity analysis: O(p!) where p is the size of the set.
// aka O(n!)
//
// More accurately would be
// O(q*(p choose q)) = O((q*p!)/(q!(p-q)!)))
// but O(p!) is close enough.
Matrix* getcombinations(int p, int q) {
  int pcq = pchooseq(p, q);
  
  Matrix* matrix = new Matrix(pcq, q);

  

  return matrix;
}
