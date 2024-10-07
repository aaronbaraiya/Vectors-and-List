#ifndef VECTOR_H
#define VECTOR_H
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;
template <typename T>
class Vector
{
  public:
      Vector (int initSize = 0)
        : theSize(initSize),
          theCapacity(initSize + SPARE_CAPACITY)
      {data = new T[theCapacity];}
      //vector added
    Vector(int initSize, int initVal)
        :theSize(initSize),
         theCapacity(initSize + SPARE_CAPACITY)
    {
          data = new T[theCapacity];
          for(int i = 0; i < theCapacity; i++)
            data[i] = initVal;
    }
    Vector(const Vector& rhs)
        : theSize(rhs.theSize),
          theCapacity(rhs.theCapacity),
          data(nullptr)
    {
      data = new T[theCapacity];
      for(int k = 0; k < theSize; ++k)
          data[k] = rhs.data[k];
    }
    Vector& operator = (const Vector& rhs)
    {
      Vector copy = rhs;
      std::swap(*this, copy);
      return *this;
    }
    Vector(Vector&& rhs)
         : theSize{rhs.size()},
           theCapacity{rhs.theCapacity},
           data{rhs.data}
    {
      rhs.data = nullptr;
      rhs.theSize = 0;
      rhs.theCapacity = 0;
    }
    Vector& operator = (Vector&& rhs)
    {
      std::swap(theSize, rhs.theSize);
      std::swap(theCapacity, rhs.theCapacity);
      std::swap(data, rhs.data);
      return *this;
    }
    ~Vector()
    {
      delete[] data;
    }
    bool empty() const
    {
      return size() == 0;
    }
    int size() const
    {
      return theSize;
    }
    int capacity() const
    {
      return theCapacity;
    }
    T& operator[] (int index)
    {//brackets issue
      assert(index >= 0 && index < theSize);
      return data[index];
    }
    const T& operator[] (int index) const
    {
      assert(index >= 0 && index < theSize);
      return data[index];
    }
    void resize(int newSize)
    {
        if(newSize > theCapacity)
           reserve(newSize * 2);
        theSize = newSize;
    }
    void reserve(int newCapacity)
    {
      if(newCapacity < theSize)
         return;
      T* newArray = new T[newCapacity];
      for(int k = 0; k < theSize; ++k)
         newArray[k] = std::move(data[k]);
      theCapacity = newCapacity;
      std::swap(data, newArray);
      delete[] newArray;
    }
    void push_back(const T& x)
    {
      if(theSize == theCapacity)
         reserve(2 * theCapacity + 1);
      data[theSize++] = x;
    }
    void pop_back()
    {
      assert(theSize >= 1);
      --theSize;
    }
    const T& back() const
    {
      assert(theSize >= 1);
      return data[theSize - 1];
    }
    void clear()
    {
      theSize = 0;
    }
    //iterators
   typedef T* iterator;
   typedef const T* const_iterator;
    iterator begin()
    {
      return &data[0];
    }
    const_iterator begin() const
    {
      return &data[0];
    }
    iterator end()
    {
      return &data[size()];
    }
    const_iterator end() const
    {
      return &data[size()];
    }
    //static const int SPARE_CAPACITY = 2;
    void erase(int index)
    {
      assert(index >= 0 && index < theSize);
      if(index == theSize - 1)
      {
        pop_back();
        return;
      }
      for(int i = index + 1; i < theSize; i++)
      {
        data[i-1] = data[i];
      }
      pop_back();
      return;
    }
    void insert(iterator itr, int value)
    {
      if(itr == end())
      {
        push_back(value);
        return;
      }
      assert(itr >= begin() && itr < end());
      push_back(back());
      iterator itr1 = end() - 2;
      iterator itr2 = end() - 1;
      while(itr1 >= itr)
      {
        *itr2 = *itr1;
        itr1--;
        itr2--;
      }
      *itr = value;
      return;
    }
    void erase(int index, int& ops)
    {
      assert(index >= 0 && index< theSize);
      if(index == theSize - 1)
      {
        pop_back();
        ops++;
        return;
      }
      for(int i = index; i < theSize; i++)
      {
        data[i] = data[i + 1];
        ops++;
      }
      pop_back();
      return;
    }
    static const int SPARE_CAPACITY = 2;
    private:
      int theSize;
      int theCapacity;
      T* data;
};
#endif
