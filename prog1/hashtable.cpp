//Hash table 
//Nikhil Patil

#include "hashtable.h"
#include "entry.h"
#include <iostream>

HashTable::HashTable()
{
  table = new Entry*[97];
  for(int i = 0; i < 97; i++)
  	table[i] = NULL;
}

Entry* HashTable::insert(int key) {
	Entry* p = new Entry(key);
	int index = hash(key);

	if(table[index] == NULL)
	{
	  table[index] = p;
	  return p;
	}
	Entry* add = table[index];
	while(add != NULL)
	  {
	    if(add -> get_key() == key)
	      {
		std::cout << "error: item already exists" << std::endl;
		p = NULL;
		return p;
	      }
	    else if(add -> get_next() != NULL)
	      add = add -> get_next();
	    else
	      break;
	  }
	add -> set_next(p);
	return p;
}

bool HashTable::lookup(int key) {
	int index = hash(key);
	if(table[index] != NULL && table[index] -> get_key() == key)
	{
	  std::cout << "found " << key << std::endl;
	  return true;
	}

	Entry* look = table[index];
	while(look != NULL)
	{
		if(look -> get_key() == key)
		{
		  std::cout << "found " << key << std::endl;
		  return true;
		}
		else
		  look = look -> get_next();
	}

	std::cout << key << " not found" << std::endl;
	return false;

}

int HashTable::remove(int i) {
  int index = hash(i);
  Entry* bef = NULL;
  Entry* del = table[index];

  while(del != NULL && del -> get_key() != i)
    {    
      bef = del;
      del = del -> get_next();
    }

  if(del == NULL)
    {
      std::cout << "error: item not present" << std::endl;
      return -1;
    }
  else if(del -> get_key() == i && bef == NULL)
    {
      table[index] = del -> get_next();
      int a = del -> get_heap_loc();
      delete del;
      return a;
    }
  else 
    {
      bef -> set_next(del -> get_next());
      int b = del -> get_heap_loc();
      delete del;
      return b;
    }
}

int HashTable::hash(unsigned int key) {
  int result = key % 97;
  if(result < 0)
    result += 97;
  return result;
}
