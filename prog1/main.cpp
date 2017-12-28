

#include <iostream>
#include <fstream>
#include "hashtable.h"
#include "heap.h"
using namespace std;

int main() {
  Heap heep;  

  HashTable h;
  heep.insert(h.insert(4));
  heep.insert(h.insert(7));
  heep.insert(h.insert(4));
  heep.insert(h.insert(101));
  heep.insert(h.insert(32));
  heep.insert(h.insert(42));
  heep.insert(h.insert(58));
  heep.insert(h.insert(324));
  heep.insert(h.insert(321));
  heep.insert(h.insert(44));
  heep.insert(h.insert(141));

  h.test_print();
  heep.test_print();

  h.lookup(4);
  h.lookup(41);
  h.lookup(141);
  h.lookup(5);
  h.lookup(7);
  h.remove(2);
  h.remove(4);
  h.lookup(4);
  h.lookup(101);


  Entry* a = new Entry(47);
  Entry* b = new Entry(19);
  Entry* c = new Entry(58);
  Entry* d = new Entry(52);
  Entry* e = new Entry(41);
  Entry* f = new Entry(30);
  Entry* g = new Entry(60);
  Entry* hi = new Entry(12);
  Entry* i = new Entry(50);
  Entry* j = new Entry(23);
  Entry* k = new Entry(18);
  heep.insert(a);
  heep.insert(b);
  heep.insert(c);
  heep.insert(d);
  heep.insert(e);
  heep.insert(f);
  heep.insert(g);
  heep.insert(hi);
  heep.insert(i);
  heep.insert(j);
  heep.insert(k);
  heep.deleteMax();
  heep.test_print();
  heep.print();
  std:: cout << std:: endl;
  heep.deleteMax();
  heep.print();

  std::cout << std:: endl;

  Heap mine;
  Entry* l = new Entry(58);
  mine.insert(l);
  mine.print();
  mine.deleteMax();
  mine.print();

  std::cout << std::endl;
  
  Heap size_2;
  Entry* m = new Entry(51);
  Entry* n = new Entry(58);
  size_2.insert(m);
  size_2.insert(n);
  size_2.print();
  size_2.deleteMax();
  size_2.print();

  size_2.remove(0);
  size_2.print();
  std::cout << std::endl;
 
  Heap size_3;
  Entry* o = new Entry(51);
  Entry* p = new Entry(56);
  Entry* q = new Entry(58);
  size_3.insert(o);
  size_3.insert(p);
  size_3.insert(q);
  size_3.print();
  size_3.deleteMax();
  size_3.print();
  
  size_3.remove(1);
  size_3.print();

  std::cout << std::endl;

  Heap size_4;
  Entry* r = new Entry(49);
  size_4.insert(q);
  size_4.insert(r);
  size_4.insert(o);
  size_4.insert(p);
  size_4.print();
  size_4.deleteMax();
  size_4.print();

  size_4.remove(1);
  
  size_4.print();
  

  Heap sl;
  sl.insert(f);
  sl.insert(d);
  sl.insert(g);
  sl.insert(p);
  sl.insert(a);
  sl.insert(j);
  
  sl.remove(2);
  
  sl.print();
  return 0;
}
