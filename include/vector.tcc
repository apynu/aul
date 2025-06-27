#pragma once

using namespace aul;

template <typename T>
// ... yep this definetly works
void vector<T>::erase_index(int index) {
    std::vector<T> _v_data = *this;
    this->clear();
    for (int i = 0; i < _v_data.size(); i++) {
        if (i != index) {
            this->push_back(_v_data[i]);
        }
    }
}

template <typename T>
// ... yep this definetly works
void vector<T>::erase_element(T element) {
    std::vector<T> _v_data = *this;
    this->clear();
    for (T _element : _v_data){
        if (_element != element) {
            this->push_back(_element);
        }
    }
}