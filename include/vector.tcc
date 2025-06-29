#pragma once

using namespace aul;

template <typename T> void vector<T>::erase(int index) {
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
