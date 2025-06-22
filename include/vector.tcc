#pragma once
#include <iostream>

using namespace aul;

template <typename T>
// ... yep this definetly works
void vector<T>::erase(int index) {
    std::vector<T> _v_data = *this;
    this->clear();
    for (int i = 0; i < _v_data.size(); i++) {
        if (i != index) {
            this->push_back(_v_data[i]);
        }
    }
}