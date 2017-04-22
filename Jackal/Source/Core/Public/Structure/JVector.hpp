//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once 

#include "Platform/JTypes.hpp"
#include "Platform/Platform.hpp"

namespace jkl {


template<typename T>
class VIterator {
public:

  VIterator();

  VIterator &Next();
  
private:

};


// Standard Vector arraylist. Used almost entirely throughout
// Jackal Game engine. Speed is improved from it's use, as well 
// as it's portability, since it does not have to rely solely on
// the standard library.
template<typename T>
class JVector {
public:
  JVector(int32 setSize);

  JVector(const JVector &vect);
  JVector(const JVector &&vect);
  // Add the data of a native array to the next.
  JVector(uint32 size, T *data);

  // Insert an object into this vector. Increments this
  // vector list by one size.
  void Insert(const T &object);

  // Operator for accessing the arraylist.
  T *operator[](const uint32 i);

  // Access the arraylist from the specified index i param.
  T *Get(const uint32 i);

  // Remove an object from the specified array.
  bool8 Remove(const uint32 i);
  void Resize(const uint32 newSize);
  void Reserve(const uint32 size);
  
  uint32 Size() const { return size; }
  uint32 TotalSize() const { return totalSize; }
  
  // Return the front of this array.
  T *Front() const { return &arr[0]; }

  // Return the back of this array.
  T *Back() const { return &arr[size - 1]; }

  // Returns the actual array.
  T *Data() const { return arr; }
  
private:
  uint32 totalSize;
  uint32 size;
  T *arr;
};
} // jkl