/* vector.h 
 *
 * Richard Townsend   8/11/20
 *
 * Define the Vector class type 
 *
 */
//These two lines (plus the last line of the file) prevent various compiler
//errors that arise in multi-file programs.
#ifndef VECTOR_H 
#define VECTOR_H

#include <iostream>
#include <string>
#include "card.h"

using namespace std;

typedef Card * Data;

class Vector {
public:
Vector();
  int size();
  Data at(int index);
  void push_back(Data value);
  void pop_back();
  void insert(int index, Data value);
  void erase(int index);
private:
void reserve_more(); 
  int capacity; 
  int vSize;    //We can't use the same name as the size() method above!
  Data *buffer; 
};

#endif
