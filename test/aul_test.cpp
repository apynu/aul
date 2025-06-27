#include <vector.h>

int main() {
    aul::vector<int> _v_test = {1, 2, 3, 4, 5};

    _v_test.erase_index(2);
    _v_test.erase_element(5);

    if (_v_test.at(2) == 3 || _v_test.back() == 5)
        return 1;

    return 0;
}
