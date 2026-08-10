#include <iostream>
#include <vector>
#include "print/vector/Vectorprint.h"
#include "Vector.h"

// What happens if we are passed a vector directly and try to modify it
void tryeditdirect(std::vector<int> v) {
  std::cout << "this array has addr " << &v << "\n";
  v[0] = -1;
  v[1] = -5;
}

// What happens if we are passed a vector reference and try to modify it
void tryeditreference(std::vector<int>& v) {
  std::cout << "this array has addr " << &v << "\n";
  v[0] = -1;
  v[1] = -3;
}

// What happens if we are passed a vector pointer and try to modify it
void tryeditpointer(std::vector<int>* v) {
  std::cout << "this array has addr " << v << "\n";
  v->at(0) = -1;
  v->at(1) = -3;
}

// Try to pass a vector into another function, edit it, and print it.
void trypassdirect() {
  std::vector<int> va = {2,3};
  std::cout << "this array has addr " << &va << "\n";
  vectorprint(va); // 2 3
  tryeditdirect(va);
  vectorprint(va); // still 2 3
}

// Try to pass a vector reference into another function, edit it, and print it.
void trypassreference() {
  std::vector<int> va = {2,3};
  std::cout << "this array has addr " << &va << "\n";
  vectorprint(va); // 2 3
  tryeditreference(va);
  vectorprint(va); // -1 -3
}

// Try to pass a vector pointer into another function, edit it, and print it.
void trypasspointer() {
  std::vector<int> va = {2,3};
  std::cout << "this array has addr " << &va << "\n";
  vectorprint(va); // 2 3
  tryeditpointer(&va);
  vectorprint(va); // -1 -3
}

// Initialize a vector then add values later.
void tryaddlater() {
  std::vector<int> zahlen(3);
  vectorprint(zahlen);
  zahlen = {3,4,5};
  vectorprint(zahlen);
}

// Messing around with vectors.
int main() {
  tryaddlater();
}
