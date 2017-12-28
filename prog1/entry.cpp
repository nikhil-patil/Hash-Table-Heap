#include "entry.h"
#include <iostream>
using namespace std;

Entry::Entry(int k) {
	key = k;
	next = NULL;
}

int Entry::get_key() {
	return key;
}

Entry* Entry::get_next() {
	return next;
}

int Entry::get_heap_loc() {
  return heap_loc;
}

void Entry::set_next(Entry* e) {
	next = e;
}

void Entry::set_heap_loc(int i) {  
  heap_loc = i;
}
