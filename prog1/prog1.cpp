#include <iostream>
#include "entry.h"
#include "hashtable.h"
#include "heap.h"

int main() {
  HashTable hash;
  Heap heap;
  
  int size;
  int instruct;
  int arg;
  std::string func;
  std::string insert = "insert";
  std::string deleteMax = "deleteMax";
  std::string remove = "delete";
  std::string lookup = "lookup";
  std::string print = "print";

  std::cin >> func;
  std::cin >> instruct;
  
  int i = 0;
      while(std::cin >> func && i < instruct)
	{
	  if(func == insert)
	    {
	      std::cin >> arg;
	      Entry* a = hash.insert(arg);
	      if(a != NULL)
		heap.insert(a);
	    }
	  else if(func == lookup)
	    {
	      std::cin >> arg;
	      hash.lookup(arg);
	    }
	  else if(func == deleteMax)
	    {
	      if(heap.get_heap_size() == 0)
		std::cout << "error" << std::endl;
	      else
		{
		  int max = heap.deleteMax();
		  hash.remove(max);
		  heap.pop_back();
		  std::cout << std::endl;
		}
	    }
	  else if(func == remove)
	    {
	      std::cin >> arg;
	      int b = hash.remove(arg);
	      if(b != -1)
		{
		  heap.remove(b);
		}
	    }
	  else if(func == print)
	    heap.print();
	  i++;

	}
      

  std::cout << std::endl;
  return 0;
}

