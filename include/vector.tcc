#pragma once
#include <print>

namespace aul {
  template <typename T> void vector<T>::erase_index(int index) {
    this->erase(this->begin() + index);
  }

  template <typename T>
  // ... yep this definetly works
  void vector<T>::erase_element(T element) {
    std::vector<T> _v_data = *this;
    this->clear();
    for (T _element : _v_data) {
      if (_element != element) {
        this->push_back(_element);
      }
    }
  }

  template <typename T>
  void vector<T>::map(std::invocable<T> auto f) {
    for (int i = 0; i < this->size(); i++) {
      this->at(i) = f(this->at(i));
    }
  }
}
