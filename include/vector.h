#pragma once

#include <vector>

namespace aul {
template <typename T> class vector : public std::vector<T> {
public:
  using std::vector<T>::vector;
  using std::vector<T>::operator=;

  // erase an element at some index
  void erase(int index);

  // erase all elements in the vector
  // WARN: this erase method is very unperformant
  void erase_element(T element);
};
} // namespace aul

#include "vector.tcc"
