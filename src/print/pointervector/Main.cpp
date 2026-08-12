#include "Pointervectorprint.h"
#include <vector>

int main() {
  std::vector<int> list = {6,7,8,9};

  std::vector<int*>* plist = new std::vector<int*>(0);

  for (int i = 0; i < list.size(); i++) {

    // Push back a pointer to the int, not a copy of it.
    plist -> push_back(&list[i]);
  }

  pointervectorprint(plist); // [6, 7, 8, 9]

  // Now try modifying the "parent" vector.

  list[1] = 15;

  pointervectorprint(plist); // [6, 15, 8, 9]
}
