#include <string>
#include <vector>
#include "entry.h"

class Heap {
 
 public:
  Heap();

  void insert(Entry* ins);
  int deleteMax();
  void remove(int i);
  void print();
  void test_print();
  void pop_back();
  int get_heap_size();

 private:
  
  int get_left_child(int parent);
  int get_right_child(int parent);
  int get_parent(int child);
  //int size;
  void swap(int index1, int index2);
  std::vector<Entry*> vec;
  //Entry* ;
  
};
