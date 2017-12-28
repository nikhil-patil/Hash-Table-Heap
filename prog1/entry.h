#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry {
	
	public: 

		Entry(int k);
		int get_key();
		Entry* get_next();
		void set_next(Entry* e);
		void set_heap_loc(int i);
		int get_heap_loc();

	private:

		unsigned int key;
		Entry* next;
		int heap_loc;

};

#endif
