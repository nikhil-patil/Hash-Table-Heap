#include "heap.h"
#include "entry.h"
#include <iostream>
#include <vector>

Heap::Heap()
{
}

void Heap::insert(Entry* ins) {
  Entry* p = ins;
  vec.push_back(p);
  int index = vec.size() - 1;
  vec[index] -> set_heap_loc(index);
  int p_index = get_parent(index);
  vec[p_index] -> set_heap_loc(p_index);
  while(p_index >= 0 && vec[index] -> get_key() > vec[p_index] -> get_key())
    {
      swap(index, p_index);
      index = p_index;
      p_index = get_parent(p_index);
    }
}

int Heap::get_left_child(int parent) {
  return 2 * parent + 1;
}

int Heap::get_right_child(int parent) {
  return 2 * parent + 2;
}

int Heap::get_parent(int child) {
  return (child-1)/2;
}

void Heap::swap(int index1, int index2) {
  Entry* a = vec[index1];
  vec[index1] = vec[index2];
  vec[index2] = a;
  vec[index1] -> set_heap_loc(index1);
  vec[index2] -> set_heap_loc(index2);
}

void Heap::pop_back() {
  vec.pop_back();
}

int Heap::deleteMax() {
  int max = vec[0] -> get_key();
  std::cout << max;
  if(vec.size() == 1)
    return max;
  if(vec.size() == 2)
    {
      swap(0, 1);
      return max;
    }
  swap(0, vec.size() - 1);
  int index = 0;
  int lchild = 1;
  if(vec.size() == 3)
    {
      if(vec[lchild]->get_key() > vec[index] -> get_key())
	swap(lchild, index); 
      return max;
    }
  int rchild = 2;

  while(vec[lchild] -> get_key() > vec[index] -> get_key() || vec[rchild] -> get_key() > vec[index] -> get_key())
    {
      if(vec[lchild] -> get_key() > vec[rchild] -> get_key())
	{	
	  swap(index, lchild);
	  index = lchild;
	  lchild = get_left_child(index);
	  rchild = get_right_child(index);
	  if(lchild > vec.size() - 2)
	    return max;
	  else if(rchild > vec.size() - 2)
	    {
	      if(vec[lchild] -> get_key() > vec[index] -> get_key())
		swap(index, lchild);
	      return max;
	    }
	}
      else
	{
	  swap(index, rchild);
	  index = rchild;
	  lchild = get_left_child(index);
	  rchild = get_right_child(index);
	  if(lchild > vec.size() - 2)
	    return max;
	  else if(rchild > vec.size() - 2)
	    {
	      if(vec[lchild] -> get_key() > vec[index] -> get_key())
		swap(index, lchild);
	      return max;
	    }
	}
    }
  return max;
}

void Heap::remove(int i) {
  if(i == vec.size()-1)
    {    
      vec.pop_back();
      return;
    }
  swap(i, vec.size() - 1);
  vec.pop_back();
  int index = i;
  int lchild = get_left_child(i);
  int rchild = get_right_child(i);
  int p_index = get_parent(i);
  if(p_index >=0 && vec[index] -> get_key() > vec[p_index] -> get_key())
    {
      while(p_index >= 0 && vec[index] -> get_key() > vec[p_index] -> get_key())
        {
          swap(index, p_index);
          index = p_index;
          p_index = get_parent(p_index);
        }
      return;
    }
  if(lchild > vec.size() - 1)
    return;
  else if(rchild > vec.size() - 2)
    {
      if(vec[lchild] -> get_key() > vec[index] -> get_key())
	swap(index, lchild);
      return;
    }
  while(vec[lchild] -> get_key() > vec[index] -> get_key() || vec[rchild] -> get_key() > vec[index] -> get_key())
    {
      if(vec[lchild] -> get_key() > vec[rchild] -> get_key())
        {
          swap(index, lchild);
          index = lchild;
          lchild = get_left_child(index);
          rchild = get_right_child(index);
          if(lchild > vec.size() - 1)
            return;
          else if(rchild > vec.size() - 1)
            {
              if(vec[lchild] -> get_key() > vec[index] -> get_key())
                swap(index, lchild);
              return;
            }
        }
      else
        {
          swap(index, rchild);
          index = rchild;
          lchild = get_left_child(index);
          rchild = get_right_child(index);
          if(lchild > vec.size() - 1)
            return;
          else if(rchild > vec.size() - 1)
            {
              if(vec[lchild] -> get_key() > vec[index] -> get_key())
                swap(index, lchild);
              return;
            }
        }
    }
	 /*if(rchild > vec.size() - 1)
    {
      if(lchild < vec.size())
	{
	  if(vec[lchild] -> get_key() > vec[index] -> get_key())
	    swap(lchild, index);
	}
      return;
    }*/
  /*while(vec[index] -> get_key() < vec[lchild] -> get_key() || (rchild < vec.size() && vec[index] -> get_key() < vec[rchild] -> get_key()))
    {
      if(vec[rchild] -> get_key() < vec[lchild] -> get_key())
        {
          swap(index, lchild);
          index = lchild;
          lchild = get_left_child(index);
          rchild = get_right_child(index);
          if(lchild > vec.size() - 1)
            break;
        }
      else if(rchild < vec.size() && vec[lchild] -> get_key() < vec[rchild] -> get_key())
        {
          swap(index, rchild);
          index = rchild;
          lchild = get_left_child(index);
          rchild = get_right_child(index);
          if(lchild > vec.size() - 1)
            break;
        }
	}*/
}

void Heap::test_print() {
  for(int i = 0; i < vec.size(); i++)
    std::cout << vec[i] -> get_key() << std::endl;
}

int Heap::get_heap_size() {
  return vec.size();
}

void Heap::print() {
  if(vec.size() == 0)
    {
      std::cout << std::endl;
      return;
    }
  while(vec.size() > 0)
    {    
      deleteMax();
      pop_back();
      std::cout << " ";
      }
}

