#include <iostream>
#include <vector>
#include "matrix/Matrix.h"
#include "Printmatrix.h"

void printmatrixprimitive(int** ptr, int m, int n) {

  for (int i = 0; i < m; i++) {
      
    for (int j = 0; j < n; j++) {
      
      if (j != 0) {
	std::cout << ", ";
      }
      
      std::cout << *(*(ptr + i) + j);
    }
    
    std::cout << std::endl;        
  }
}

void printmatrixvector(std::vector<std::vector<int>*>* matrix, int m, int n) {
  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {

      if (j != 0) {
	std::cout << ", ";
      }
      std::cout << (*(*matrix)[i])[j];
    }

    std::cout << std::endl;
  }
}

void printmatrix(Matrix* matrix) {
  
  std::vector<std::vector<int>*>* vec = matrix -> mat;
  int rows = matrix -> rows;
  int cols = matrix -> cols;
  
  std::cout << "Matrix size " << rows << ", " << cols << ":\n";
  printmatrixvector(vec, rows, cols);
}
