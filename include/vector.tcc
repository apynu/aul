#pragma once

using namespace aul;

template <typename T>
void vector<T>::erase(int index) {
    this->erase(this->begin() + index);
}
