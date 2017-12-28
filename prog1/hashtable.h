#include <string>
#include "entry.h"

class HashTable {

 public:
  HashTable();

  Entry* insert(int key);
  bool lookup(int i);
  int remove(int i);

 private:
  int hash(unsigned int key);
  Entry** table;
  Entry* max;
  int* heap_loc;
};
