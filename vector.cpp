/* vector.cpp 
 *
 * Author: Richard Townsend   
 * Last Updated: 11/5/24
 *
 * Purpose: Implement a Vector class similar to (but more limited than) the
 * standard C++ vector. A vector is basically an array that can dynamically grow
 * (or shrink) to hold more (or remove) elements as needed. The user of a vector
 * should not have to worry about how the elements are actually stored under the
 * hood (this will motivate which fields/methods should be private).
 *
 * 
 * Rules about a vectors fields that must be true at the start and end of any
 * of our vector's methods:
 *  1. 0 <= size <= capacity
 *  2. capacity >= 0
 *  3. If the vector is not empty, buffer[0] stores the first element
 *  4. If the vector is not empty, buffer[size - 1] is the last element
 *
 */

#include "vector.h"

Vector::Vector() {
  capacity = 0;
  vSize = 0;
  buffer = nullptr;
 }

/* Return the number of elements in the vector. */
int Vector::size() {
  return vSize;
}




/* Returns the value at the given index in our vector. 
 *
 * ERRORS: Calling this function with an index outside the vector's range causes
 * the program to terminate with an error.
 */
Data Vector::at(int index) {
  if (index < 0 || index >= vSize) {
    cerr << "ERROR: a vector of size " << vSize;
    cerr << " was accessed at index " << index << endl;
    exit(EXIT_FAILURE);
  }
  return buffer[index];
}





/* Add the given element to the back of the vector. If there isn't enough space
 * for this additional element, make the vector twice as large (this makes the
 * push_back() function have O(1) amortized complexity). 
 */
void Vector::push_back(Data value) {
  if (vSize == capacity) {
    capacity = capacity * 2; 
    void reserve_more(); 
  }
  buffer[vSize] = value;
  vSize++;
}




/* "Remove" the last element of the vector by decrementing the size.
 *
 * ERRORS: Calling this function on an empty vector causes undefined behavior.
 */ 
void Vector::pop_back() {
  vSize--; 
}






/* Insert a new value before the element at the given index, shifting all
 * elements at that index and above to the right by 1. 
 *
 * ERRORS: Calling this function with an index outside the bounds (0, size)
 * causes the program to terminate with an error. We allow an insertion at index
 * size because that's equivalent to a call to push_back().
 */
void Vector::insert(int index, Data value) {
  if (index < 0 || index > vSize) {
    cerr << "ERROR: trying to insert an element out of bounds" << endl;
    exit(EXIT_FAILURE);
  }
  if (vSize == capacity) {
    //TODO: Make more space in the vector if needed to hold this new element
  }
  //TODO: Insert element and shift all following elements to the right
  
  //Update our size
  vSize++;
}







/* Erase the value at the given index, shifting all
 * elements above that index to the left by 1. 
 *
 * ERRORS: Calling this function with an index outside the bounds (0, size)
 * causes the program to terminate with an error. 
 */
void Vector::erase(int index) {
  if (index < 0 || index >= vSize) {
    cerr << "ERROR: trying to erase an element out of bounds" << endl;
    exit(EXIT_FAILURE);
  }
  //TODO: Shift all elements above the given index to the left
  
  //Update our size
  vSize--;
}

