#pragma once

#include <vector>
#include <concepts>

namespace aul {
template <typename T> class vector : public std::vector<T> {
public:
  using std::vector<T>::vector;
  using std::vector<T>::operator=;

  // erase an element at some index
  void erase_index(int index);

  // erase all elements in the vector
  // WARN: this erase method is very unperformant
  void erase_element(T element);

  // Applies the lambda function f to each element of the vector, modifying the elements in-place
  void map(std::invocable<T> auto f);
};
} // namespace aul

#include "vector.tcc"
